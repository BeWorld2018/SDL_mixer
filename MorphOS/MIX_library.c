/*
  SDL_mixer:  An audio mixer library based on the SDL library
  Copyright (C) 1997-2026 Sam Lantinga <slouken@libsdl.org>

  This software is provided 'as-is', without any express or implied
  warranty.  In no event will the authors be held liable for any damages
  arising from the use of this software.

  Permission is granted to anyone to use this software for any purpose,
  including commercial applications, and to alter it and redistribute it
  freely, subject to the following restrictions:

  1. The origin of this software must not be misrepresented; you must not
     claim that you wrote the original software. If you use this software
     in a product, an acknowledgment in the product documentation would be
     appreciated but is not required.
  2. Altered source versions must be plainly marked as such, and must not be
     misrepresented as being the original software.
  3. This notice may not be removed or altered from any source distribution.
*/

#include <stddef.h>
#include <stdlib.h>

#include <exec/execbase.h>
#include <exec/libraries.h>
#include <exec/lists.h>
#include <exec/nodes.h>
#include <exec/resident.h>
#include <exec/system.h>

#include <proto/exec.h>
#include <emul/emulregs.h>

#include "MIX_mosversion.h"
#include "MIX_library.h"
#include "MIX_startup.h"

STATIC CONST TEXT __TEXTSEGMENT__ verstring[] = VERSTAG;
STATIC CONST TEXT libname[] = "sdl3_mixer.library";

struct MIX_Library *GlobalBase = NULL;

struct ExecBase   *SysBase = NULL;
struct DosLibrary *DOSBase = NULL;

/* libxmp (xfd_link.o), weak: absent when libxmp isn't linked */
extern struct Library *xfdMasterBase __attribute__((weak));

/**********************************************************************/

STATIC ULONG LIB_Reserved(void)
{
    return 0;
}

/* Jump table entry of the SDL3_mixer functions not built for MorphOS */
ULONG LIB_Unsupported(void)
{
    return 0;
}

/**********************************************************************
    .ctdt sort - order constructors/destructors by priority
**********************************************************************/

STATIC int comp_ctdt(struct CTDT *a, struct CTDT *b)
{
    if (a->priority == b->priority)
        return 0;
    if ((unsigned long)a->priority < (unsigned long)b->priority)
        return -1;
    return 1;
}

STATIC VOID sort_ctdt(struct MIX_Library *LibBase)
{
    extern struct CTDT __ctdtlist;
    struct CTDT *ctdtlist = &__ctdtlist;

    struct HunkSegment *seg = (struct HunkSegment *)(((unsigned int)ctdtlist) - sizeof(struct HunkSegment));
    struct CTDT *_last_ctdt = (struct CTDT *)(((unsigned int)seg) + seg->Size);

    qsort((struct CTDT *)ctdtlist, _last_ctdt - ctdtlist, sizeof(*ctdtlist),
          (int (*)(const void *, const void *))comp_ctdt);

    LibBase->ctdtlist  = ctdtlist;
    LibBase->last_ctdt = _last_ctdt;
}

/**********************************************************************
    .ctors / .dtors - C++ static constructors (libstdc++, fluidsynth),
    attribute((constructor)) (libxmp xfdmaster.library). Not in the
    .ctdt list: MOS_Startup/MOS_Cleanup run them per opener. Each list
    is between our markers: -1 here (MIX_library.o is linked first) and
    MIX_ctorsend.o (linked last).
**********************************************************************/

STATIC VOID find_ctors(struct MIX_Library *LibBase)
{
    extern APTR __mos_ctors, __mos_dtors, __mos_ctors_end, __mos_dtors_end;

    LibBase->ctors     = &__mos_ctors;
    LibBase->last_ctor = &__mos_ctors_end;
    LibBase->dtors     = &__mos_dtors;
    LibBase->last_dtor = &__mos_dtors_end;
}

/**********************************************************************
    init_libs - open the libraries needed for the whole library lifetime
**********************************************************************/

static int init_libs(struct MIX_Library *base, struct ExecBase *SysBase)
{
    if ((DOSBase = base->MyDOSBase = (APTR)OpenLibrary("dos.library", 36)) != NULL)
    {
        sort_ctdt(base);
        find_ctors(base);

        /* libxmp: once for all openers, see MIX_startup.c */
        if (&xfdMasterBase)
            xfdMasterBase = OpenLibrary("xfdmaster.library", 38);

        return 1;
    }

    return 0;
}

/**********************************************************************
    -mresident32 data relocation machinery (toolchain contract)
**********************************************************************/

#define R13_OFFSET 0x8000

extern int __datadata_relocs(void);

STATIC __inline int __dbsize(void)
{
    extern APTR __sdata_size, __sbss_size;
    STATIC CONST ULONG size[] = { (ULONG)&__sdata_size, (ULONG)&__sbss_size };
    return size[0] + size[1];
}

/**********************************************************************
    LIB_Init - resident auto-init entry (called once at library load)
**********************************************************************/

struct Library *LIB_Init(struct MIX_Library *LibBase, BPTR SegList, struct ExecBase *sysBase)
{
    register char *r13;

    GlobalBase = LibBase;
    SysBase    = sysBase;

    LibBase->Library.lib_Node.ln_Pri = -5;

    asm volatile ("lis %0,__r13_init@ha; addi %0,%0,__r13_init@l" : "=r" (r13));

    LibBase->SegList   = SegList;
    LibBase->DataSeg   = r13 - R13_OFFSET;
    LibBase->DataSize  = __dbsize();
    LibBase->Parent    = NULL;
    LibBase->MySysBase = sysBase;

    NEWLIST(&LibBase->TaskContext.TaskList);
    InitSemaphore(&LibBase->Semaphore);

    if (init_libs(LibBase, sysBase) == 0)
    {
        FreeMem((APTR)((ULONG)(LibBase) - (ULONG)(LibBase->Library.lib_NegSize)),
                LibBase->Library.lib_NegSize + LibBase->Library.lib_PosSize);
        LibBase = NULL;
    }

    return (struct Library *)LibBase;
}

/**********************************************************************
    DeleteLib - final tear-down at expunge
**********************************************************************/

static BPTR DeleteLib(struct MIX_Library *LibBase, struct ExecBase *SysBase)
{
    BPTR SegList = 0;

    if (LibBase->Library.lib_OpenCnt == 0)
    {
        CloseLibrary((struct Library *)LibBase->MyDOSBase);

        if (&xfdMasterBase && xfdMasterBase)
        {
            CloseLibrary(xfdMasterBase);
            xfdMasterBase = NULL;
        }

        SegList = LibBase->SegList;

        REMOVE(&LibBase->Library.lib_Node);
        FreeMem((APTR)((ULONG)(LibBase) - (ULONG)(LibBase->Library.lib_NegSize)),
                LibBase->Library.lib_NegSize + LibBase->Library.lib_PosSize);
    }

    return SegList;
}

/**********************************************************************
    UserLibClose - close anything opened lazily in LIB_Open (nothing yet)
**********************************************************************/

static void UserLibClose(struct MIX_Library *LibBase, struct ExecBase *SysBase)
{
    (void)LibBase;
    (void)SysBase;
}

/**********************************************************************
    LIB_Expunge
**********************************************************************/

BPTR LIB_Expunge(void)
{
    struct MIX_Library *LibBase = (struct MIX_Library *)REG_A6;
    LibBase->Library.lib_Flags |= LIBF_DELEXP;
    return DeleteLib(LibBase, LibBase->MySysBase);
}

/**********************************************************************
    LIB_Close
**********************************************************************/

BPTR LIB_Close(void)
{
    struct MIX_Library *LibBase = (struct MIX_Library *)REG_A6;
    struct ExecBase *SysBase = LibBase->MySysBase;
    BPTR SegList = 0;

    if (LibBase->Parent)
    {
        struct MIX_Library *ChildBase = LibBase;

        if ((--ChildBase->Library.lib_OpenCnt) > 0)
            return 0;

        LibBase = ChildBase->Parent;

        REMOVE(&ChildBase->TaskContext.TaskNode.Node);

        MOS_Cleanup(ChildBase);
        FreeVecTaskPooled((APTR)((ULONG)(ChildBase) - (ULONG)(ChildBase->Library.lib_NegSize)));
    }

    ObtainSemaphore(&LibBase->Semaphore);

    LibBase->Library.lib_OpenCnt--;

    if (LibBase->Library.lib_OpenCnt == 0)
    {
        LibBase->Alloc = 0;
        UserLibClose(LibBase, SysBase);
    }

    ReleaseSemaphore(&LibBase->Semaphore);

    if (LibBase->Library.lib_Flags & LIBF_DELEXP)
        SegList = DeleteLib(LibBase, SysBase);

    return SegList;
}

/**********************************************************************
    LIB_Open
**********************************************************************/

struct Library *LIB_Open(void)
{
    struct MIX_Library *LibBase = (struct MIX_Library *)REG_A6;
    struct MIX_Library *newbase, *childbase;
    struct ExecBase *SysBase = LibBase->MySysBase;
    struct Task *MyTask = SysBase->ThisTask;
    struct TaskNode *ChildNode;
    ULONG MyBaseSize;

    /* has this task already opened a child? */
    ForeachNode(&LibBase->TaskContext.TaskList, ChildNode)
    {
        if (ChildNode->Task == MyTask)
        {
            childbase = (APTR)(((ULONG)ChildNode) - offsetof(struct MIX_Library, TaskContext.TaskNode.Node));
            childbase->Library.lib_Flags &= ~LIBF_DELEXP;
            childbase->Library.lib_OpenCnt++;
            return &childbase->Library;
        }
    }

    childbase  = NULL;
    MyBaseSize = LibBase->Library.lib_NegSize + LibBase->Library.lib_PosSize;
    LibBase->Library.lib_Flags &= ~LIBF_DELEXP;
    LibBase->Library.lib_OpenCnt++;

    ObtainSemaphore(&LibBase->Semaphore);

    LibBase->Alloc = 1;

    if ((newbase = AllocVecTaskPooled(MyBaseSize + LibBase->DataSize + 15)) != NULL)
    {
        CopyMem((APTR)((ULONG)LibBase - (ULONG)LibBase->Library.lib_NegSize), newbase, MyBaseSize);

        childbase = (APTR)((ULONG)newbase + (ULONG)LibBase->Library.lib_NegSize);

        if (LibBase->DataSize)
        {
            char *orig   = LibBase->DataSeg;
            LONG *relocs = (LONG *)__datadata_relocs;
            int mem = ((int)newbase + MyBaseSize + 15) & (unsigned int)~15;

            CopyMem(orig, (char *)mem, LibBase->DataSize);

            if (relocs[0] > 0)
            {
                int i, num_relocs = relocs[0];
                for (i = 0, relocs++; i < num_relocs; ++i, ++relocs)
                    *(long *)(mem + *relocs) -= (int)orig - mem;
            }

            childbase->DataSeg = (char *)mem + R13_OFFSET;

            if (MOS_Startup(childbase) == 0)
            {
                MOS_Cleanup(childbase);
                FreeVecTaskPooled(newbase);
                childbase = 0;
                goto error;
            }
        }

        childbase->Parent = LibBase;
        childbase->Library.lib_OpenCnt = 1;

        childbase->TaskContext.TaskNode.Task = MyTask;
        ADDTAIL(&LibBase->TaskContext.TaskList, &childbase->TaskContext.TaskNode.Node);
    }
    else
    {
error:
        LibBase->Library.lib_OpenCnt--;

        if (LibBase->Library.lib_OpenCnt == 0)
        {
            LibBase->Alloc = 0;
            UserLibClose(LibBase, SysBase);
        }
    }

    ReleaseSemaphore(&LibBase->Semaphore);

    return (struct Library *)childbase;
}

/**********************************************************************
    Library jump table + resident tag
**********************************************************************/

/* forward declarations of every LIB_xxx trampoline (neither macro defined) */
#include "MIX_stubs.h"

static const APTR FuncTable[] =
{
    (APTR)FUNCARRAY_BEGIN,

    (APTR)FUNCARRAY_32BIT_NATIVE,
    (APTR)LIB_Open,
    (APTR)LIB_Close,
    (APTR)LIB_Expunge,
    (APTR)LIB_Reserved,
    (APTR)-1,

    (APTR)FUNCARRAY_32BIT_SYSTEMV,

    /* spare private slots (private_reserved1..4 in the fd) */
    (APTR)LIB_Reserved,
    (APTR)LIB_Reserved,
    (APTR)LIB_Reserved,
    (APTR)LIB_Reserved,

    #define GENERATE_POINTERS
    #include "MIX_stubs.h"
    #undef GENERATE_POINTERS

    (APTR)-1,
    (APTR)FUNCARRAY_END
};

static const size_t InitTable[] =
{
    sizeof(struct MIX_Library),
    (size_t)FuncTable,
    0,
    (size_t)LIB_Init
};

const struct Resident __TEXTSEGMENT__ RomTag =
{
    RTC_MATCHWORD,
    (struct Resident *)&RomTag,
    (struct Resident *)&RomTag + 1,
    RTF_AUTOINIT | RTF_PPC | RTF_EXTENDED,
    VERSION,
    NT_LIBRARY,
    0,
    (char *)libname,
    (char *)&verstring[7],
    (APTR)&InitTable[0],
    REVISION,
    NULL
};

CONST ULONG __abox__ = 1;

__asm("\n"
      ".pushsection \".ctdt\",\"a\",@progbits\n"
      "__ctdtlist:\n"
      ".long -1,-1\n"
      ".popsection\n");

/* First entries of .ctors/.dtors (MIX_library.o is linked first), see find_ctors() */
__asm("\n"
      ".pushsection \".ctors\",\"aw\",@progbits\n"
      "__mos_ctors:\n"
      ".long -1\n"
      ".popsection\n"
      ".pushsection \".dtors\",\"aw\",@progbits\n"
      "__mos_dtors:\n"
      ".long -1\n"
      ".popsection\n");
