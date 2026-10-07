/*
 * sdl3_mixer.library version = SDL_mixer version: VERSION = major,
 * REVISION = minor * 100 + micro (SDL_mixer 3.3.0 -> 3.300).
 *
 * MIX_LIB_MAJOR/MINOR/MICRO/REVISION come from include/SDL3_mixer/SDL_mixer.h,
 * passed by Makefile.mos and devenv/makefile.
 */
#if !defined(MIX_LIB_MAJOR) || !defined(MIX_LIB_MINOR) || !defined(MIX_LIB_MICRO) || !defined(MIX_LIB_REVISION)
#error "MIX_LIB_MAJOR/MINOR/MICRO/REVISION not defined (see Makefile.mos)"
#endif

#define	str(s) #s
#define	xstr(s) str(s)
#define	VERSION	MIX_LIB_MAJOR
#define	REVISION	MIX_LIB_REVISION
#define	VERSTAG	"\0$VER: sdl3_mixer.library " xstr(VERSION) "." xstr(REVISION) " (" __AMIGADATE__ ") SDL_mixer " xstr(MIX_LIB_MAJOR) "." xstr(MIX_LIB_MINOR) "." xstr(MIX_LIB_MICRO) " (c) Bruno Peloille"
