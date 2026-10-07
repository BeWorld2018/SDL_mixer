#include <exec/types.h>

#include <proto/exec.h>

#include <SDL3/SDL_version.h>

#include "MIX_library.h"
#include "MIX_startup.h"

/*********************************************************************/

/* The SDL calls go through libb32/libSDL3-nc.a (-mresident32 glue, no
   constructor): SDL3Base is per opener, opened in MOS_Startup(). */
struct Library *SDL3Base = NULL;

/* our own library base */
struct Library *SDL3MixerBase = NULL;

#if defined(USE_SHAREDLIB_VORBIS) || defined(USE_SHAREDLIB_OGG)
/* vorbisfile.library, optional: Ogg Vorbis (decoder_vorbis.c) and the libogg
   calls of Opus and Ogg FLAC (libabox glue) fail without it. Per opener,
   like the other bases. */
struct Library *VorbisFileBase = NULL;
#endif

int  ThisRequiresConstructorHandling = 0;

/* libnix malloc()/free() (used by the codec libraries) allocate from this
   pool: created by the libnix constructor and deleted by its destructor,
   both run below from the .ctdt list. */
APTR libnix_mempool;

extern void MIX_MOS_QuitAll(void);

/* The libSDL3-nc glue references TGLGetProcAddress and __tglContext (for
   SDL_GL_GetProcAddress); the mixer never uses OpenGL. Defined here, libGL.a
   isn't linked, nor its constructor that would open tinygl.library for
   every opener (and make the open fail without it). */
void *__tglContext = NULL;
void *TGLGetProcAddress() { return NULL; }

/* libstdc++ (fluidsynth is C++): its eh_globals.o would create an exec TLS
   key with a destructor, called at program exit with the program's r13,
   before the library is closed. One exception state per opener instead. */
static struct
{
    void        *caughtExceptions;
    unsigned int uncaughtExceptions;
} mos_eh_globals;

void *__cxa_get_globals(void) { return &mos_eh_globals; }
void *__cxa_get_globals_fast(void) { return &mos_eh_globals; }

/* libxmp opens xfdmaster.library in a .ctors constructor and closes it in a
   .dtors destructor, but its (non-resident) code uses the library's template
   data, shared by all openers: the first opener to close would take it away
   from the others. Opened once in LIB_Init instead (MIX_library.c), these two
   are skipped. Weak: absent when libxmp isn't linked. */
extern void INIT_8_open_xfd(void) __attribute__((weak));
extern void EXIT_8_close_xfd(void) __attribute__((weak));

/* libnix code (fluidsynth, libgcc thread support) may call exit(): never
   leave from the middle of the opener's task. */
__attribute__((noreturn)) void exit(int rc);
__attribute__((noreturn)) void exit(int rc)
{
    (void)rc;
    for (;;) Wait(0);
}

/* This function must preserve all registers except r13 */
asm
("\n"
"	.section \".text\"\n"
"	.align 2\n"
"	.type __restore_r13, @function\n"
"__restore_r13:\n"
"	lwz 13, 36(3)\n"
"	blr\n"
"__end__restore_r13:\n"
"	.size __restore_r13, __end__restore_r13 - __restore_r13\n"
);

/**********************************************************************
	Startup/Cleanup

	Per opener, with the opener's r13 (data copy). The .ctdt list (libnix
	malloc/stdio...) is sorted once in LIB_Init; then .ctors (C++ static
	constructors, attribute((constructor))). Constructors run here,
	destructors in MOS_Cleanup, also after a partial start.
**********************************************************************/

int SAVEDS MOS_Startup(struct MIX_Library *LibBase)
{
    struct CTDT *ctdt      = LibBase->ctdtlist;
    struct CTDT *last_ctdt = LibBase->last_ctdt;

    SDL3MixerBase = &LibBase->Library;

    /* Same task as the program: sdl3.library returns the program's own
       child base, so both share one SDL state. sdl3.library version =
       SDL version (REVISION = minor * 100 + micro): any micro
       release of the SDL we were built against has our functions. */
    if ((SDL3Base = OpenLibrary("sdl3.library", SDL_MAJOR_VERSION)) == NULL)
        return 0;

    if (!LIB_MINVER(SDL3Base, SDL_MAJOR_VERSION, SDL_MINOR_VERSION * 100))
        return 0;

#if defined(USE_SHAREDLIB_VORBIS) || defined(USE_SHAREDLIB_OGG)
    VorbisFileBase = OpenLibrary("vorbisfile.library", 0);
#endif

    /* From here, MOS_Cleanup runs the .ctdt destructors (libnix ones check
       what was set up) */
    LibBase->CtdtStarted = 1;

    while (ctdt < last_ctdt)
    {
        if (ctdt->priority >= 0 && ctdt->fp != (int (*)(void)) -1)
        {
            if (ctdt->fp() != 0)
                return 0;
        }
        ctdt++;
    }

    // C++ / attribute((constructor)) list, last first like gcc
    {
        void (**fn)(void) = (void (**)(void))LibBase->last_ctor;

        while (--fn >= (void (**)(void))LibBase->ctors)
        {
            if (*fn != NULL && *fn != (void (*)(void)) -1 && *fn != INIT_8_open_xfd)
                (*fn)();
        }
    }

    LibBase->CtorsDone = 1;

    return 1;
}

VOID SAVEDS MOS_Cleanup(struct MIX_Library *LibBase)
{
    struct CTDT *ctdt      = LibBase->ctdtlist;
    struct CTDT *last_ctdt = LibBase->last_ctdt;

    if (LibBase->CtorsDone)
    {
        /* Mixers, tracks and audio the application left: the audio
           callbacks must be gone before the code and data they use. */
        MIX_MOS_QuitAll();

        {
            void (**fn)(void) = (void (**)(void))LibBase->dtors;

            for (; fn < (void (**)(void))LibBase->last_dtor; fn++)
            {
                if (*fn != NULL && *fn != (void (*)(void)) -1 && *fn != EXIT_8_close_xfd)
                    (*fn)();
            }
        }
    }

    if (LibBase->CtdtStarted)
    {
        while (ctdt < last_ctdt)
        {
            if (ctdt->priority < 0 && ctdt->fp != (int (*)(void)) -1)
                ctdt->fp();
            ctdt++;
        }
    }

#if defined(USE_SHAREDLIB_VORBIS) || defined(USE_SHAREDLIB_OGG)
    CloseLibrary(VorbisFileBase);
    VorbisFileBase = NULL;
#endif

    CloseLibrary(SDL3Base);
    SDL3Base = NULL;
}

void __chkabort(void) { }
void abort(void) { for (;;) Wait(0); }
