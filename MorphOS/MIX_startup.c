#include <proto/exec.h>

#include "MIX_library.h"

#define KILL_PENDING_AUDIO_AT_UNINIT 1
#if KILL_PENDING_AUDIO_AT_UNINIT
#include "SDL_mixer.h"
#endif

/*********************************************************************/

extern struct Library    *SDL2Base;
extern struct Library    *SDL2MixerBase;

int ThisRequiresConstructorHandling = 0;

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

APTR libnix_mempool;

/**********************************************************************
	Startup/Cleanup
**********************************************************************/

int SAVEDS AMIGA_Startup(struct SDL2MixerLibrary *LibBase)
{
	SDL2MixerBase = &LibBase->Library;

	if ((SDL2Base = OpenLibrary("sdl2.library", 53)) == NULL)
		return 0;

	return 1;
}

VOID SAVEDS AMIGA_Cleanup(struct SDL2MixerLibrary *LibBase)
{
#if KILL_PENDING_AUDIO_AT_UNINIT

	/*
	 * Make sure no pending mixer objects are running. Any running
	 * mixer object would randomly nuke the system as the userdata
	 * points to SDL2Mixer. - Piru
	 */

	/* NOTE: Depends on Mix_QuerySpec returning audio_opened counter */
	int cnt = Mix_QuerySpec(NULL, NULL, NULL);
	if (cnt)
	{
		//kprintf("SDL_mixer/UnInit: audio is still opened, call Mix_CloseAudio %ld time%s!\n", cnt, cnt != 1 ? "s" : "");
		do
		{
			Mix_CloseAudio();
		} while (--cnt);

		//kprintf("SDL_mixer/UnInit: audio mixer stuff closed\n");
	}
#endif

	CloseLibrary(SDL2Base);
	SDL2Base = NULL;

}

void __chkabort(void) { }
void abort(void) { for (;;) Wait(0); }