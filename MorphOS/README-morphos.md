# sdl3_mixer.library for MorphOS

Resident shared library built on `sdl3.library`, same layout as
`sdl3_image.library` / `sdl3_ttf.library`. Everything is driven from
`../Makefile.mos` (see its header for the targets and decoder switches).

Library version = SDL_mixer version: VERSION = major, REVISION =
minor * 100 + micro (SDL_mixer 3.3.0 -> 3.300), computed by the makefiles
from `include/SDL3_mixer/SDL_mixer.h`.

## Build

```
make -f Makefile.mos          # sdl3_mixer.library + glue libs + LVO check
make -f Makefile.mos tests    # testmixer, testaudiodecoder, testspatialization
make -f Makefile.mos sdk      # headers, fd/clib/proto/ppcinline, glue libs in /gg/usr/local
make -f Makefile.mos static   # libSDL3_mixer_static.a (everything merged, no library)
```

After an SDL_mixer update: `make -f Makefile.mos glue` (python3) regenerates
`MIX_stubs.h`, `sdk/fd/sdl3_mixer_lib.fd` and `sdk/clib/sdl3_mixer_protos.h`
from `src/SDL_mixer.sym` (append-only upstream, so offsets never move) and
`include/SDL3_mixer/SDL_mixer.h`.

## Layout

| file | role |
|------|------|
| `MIX_library.c/h` | library base, per-task child bases, jump table (4 reserved slots), RomTag; sorts `.ctdt`, finds `.ctors`/`.dtors` |
| `MIX_startup.c/h` | per opener: opens `sdl3.library` (LIB_MINVER) and `vorbisfile.library` (optional), runs `.ctdt` then `.ctors`; cleanup: `MIX_MOS_QuitAll()`, `.dtors`, `.ctdt` destructors |
| `MIX_ctorsend.c` | end markers of `.ctors`/`.dtors`, linked after every library |
| `MIX_stubs.c/h` | `__saveds` LVO trampolines (`MIX_stubs.h` generated) |
| `MIX_mosversion.h` | version tag |
| `devenv/` | `-lSDL3_mixer` glue (constructor priority 103) |

## Callbacks and r13

sdl3.library calls callbacks with its own r13. Every callback SDL_mixer
hands to SDL (audio stream get callbacks, event watcher, property
enumerators and cleanup, the IO clamp `SDL_IOStreamInterface`, FluidSynth
properties) is `MIX_MOS_SAVEDS` and reloads our r13 from the first member of
its userdata (`MIX_MOS_R13_FIELD`), see `src/SDL_mixer_internal.h`.
