/*
 * -lSDL3_mixer glue: opens sdl3_mixer.library for the program (constructor,
 * after the -lSDL3 one which opens sdl3.library).
 *
 * Built three times (see makefile): normal, -mresident32 and
 * -mresident32 -D__NO_SDL_CONSTRUCTORS.
 */

#include <constructor.h>

#include <proto/exec.h>

#include "../MIX_mosversion.h"

#if defined(__NO_SDL_CONSTRUCTORS)
extern struct Library *SDL3MixerBase;
#else
int _INIT_4_SDL3MixerBase(void) __attribute__((alias("__CSTP_init_SDL3MixerBase")));
void _EXIT_4_SDL3MixerBase(void) __attribute__((alias("__DSTP_cleanup_SDL3MixerBase")));

/* From the -lSDL3 glue */
extern void __SDL3_OpenLibError(ULONG version, const char *name, ULONG revision);

struct Library *SDL3MixerBase;

static CONSTRUCTOR_P(init_SDL3MixerBase, 103)
{
	static const char libname[] = "sdl3_mixer.library";
	struct Library *base = OpenLibrary((STRPTR)libname, VERSION);

	/* REVISION = SDL_mixer minor * 100 + micro: an older 3.x would
	   lack the vectors this program was linked against. */
	if (base && !LIB_MINVER(base, VERSION, REVISION))
	{
		CloseLibrary(base);
		base = NULL;
	}

	SDL3MixerBase = base;

	if (base == NULL)
	{
		__SDL3_OpenLibError(VERSION, libname, REVISION);
	}

	return (base == NULL);
}

static DESTRUCTOR_P(cleanup_SDL3MixerBase, 103)
{
	CloseLibrary(SDL3MixerBase);
	SDL3MixerBase = NULL;
}
#endif
