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

#ifndef MIX_MORPHOS_LIBRARY_H
#define MIX_MORPHOS_LIBRARY_H

#ifndef DOS_DOS_H
#include <dos/dos.h>
#endif
#ifndef EXEC_LIBRARIES_H
#include <exec/libraries.h>
#endif
#ifndef EXEC_SEMAPHORES_H
#include <exec/semaphores.h>
#endif

#define SAVEDS __saveds

#if defined(__PPC__)
#define __TEXTSEGMENT__ __attribute__((section(".text")))
#else
#define __TEXTSEGMENT__
#endif

/* One entry of the .ctdt (constructor/destructor) section. */
struct CTDT
{
    int  (*fp)(void);
    long   priority;
};

struct HunkSegment
{
    unsigned int        Size;
    struct HunkSegment *Next;
};

struct TaskNode
{
    struct MinNode Node;
    struct Task   *Task;
};

struct MIX_Library
{
    struct Library Library;         /* offset 0                       */
    UWORD          Alloc;           /* offset 34                      */
    APTR           DataSeg;         /* offset 36 - DON'T CHANGE       */

    ULONG                DataSize;
    struct MIX_Library  *Parent;
    BPTR                 SegList;
    struct ExecBase     *MySysBase;
    struct DosLibrary   *MyDOSBase;

    union
    {
        struct MinList  TaskList;
        struct TaskNode TaskNode;
    } TaskContext;

    struct SignalSemaphore Semaphore;
    APTR                   ctdtlist;
    APTR                   last_ctdt;
    APTR                   ctors;      /* .ctors, from our -1 marker */
    APTR                   last_ctor;
    APTR                   dtors;      /* .dtors */
    APTR                   last_dtor;
    UWORD                  CtorsDone;  /* child base: constructors ran */
    UWORD                  CtdtStarted; /* child base: .ctdt constructors started */
};

#endif /* MIX_MORPHOS_LIBRARY_H */
