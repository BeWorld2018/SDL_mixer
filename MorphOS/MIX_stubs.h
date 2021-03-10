/*
  Simple DirectMedia Layer
  Copyright (C) 1997-2014 Sam Lantinga <slouken@libsdl.org>

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

#undef STUB

#if defined(GENERATE_STUBS)
#define STUB(name) extern int name(); int __saveds LIB_##name() { return name(); }
#elif defined(GENERATE_POINTERS)
#define STUB(name) (APTR)&LIB_##name ,
#else
#define STUB(name) extern int LIB_##name();
#endif

	STUB(Mix_Init)
	STUB(Mix_Quit)
	STUB(Mix_OpenAudio)
	STUB(Mix_OpenAudioDevice)
	STUB(Mix_AllocateChannels)
	STUB(Mix_QuerySpec)
	STUB(Mix_LoadWAV_RW)
	STUB(Mix_LoadMUS)
	STUB(Mix_LoadMUS_RW)
	STUB(Mix_LoadMUSType_RW)
	STUB(Mix_QuickLoad_WAV)
	STUB(Mix_QuickLoad_RAW)
	STUB(Mix_FreeChunk)
	STUB(Mix_FreeMusic)
	STUB(Mix_GetNumChunkDecoders)
	STUB(Mix_GetChunkDecoder)
	STUB(Mix_HasChunkDecoder)
	STUB(Mix_GetNumMusicDecoders)
	STUB(Mix_GetMusicDecoder)
	STUB(Mix_GetMusicType)
	STUB(Mix_SetPostMix)
	STUB(Mix_HookMusic)
	STUB(Mix_HookMusicFinished)
	STUB(Mix_GetMusicHookData)
	STUB(Mix_ChannelFinished)
	STUB(Mix_RegisterEffect)
	STUB(Mix_UnregisterEffect)
	STUB(Mix_UnregisterAllEffects)
	STUB(Mix_SetPanning)
	STUB(Mix_SetPosition)
	STUB(Mix_SetDistance)
	STUB(Mix_SetReverseStereo)
	STUB(Mix_ReserveChannels)
	STUB(Mix_GroupChannel)
	STUB(Mix_GroupChannels)
	STUB(Mix_GroupAvailable)
	STUB(Mix_GroupCount)
	STUB(Mix_GroupOldest)
	STUB(Mix_GroupNewer)
	STUB(Mix_PlayChannelTimed)
	STUB(Mix_PlayMusic)
	STUB(Mix_FadeInMusic)
	STUB(Mix_FadeInMusicPos)
	STUB(Mix_FadeInChannelTimed)
	STUB(Mix_Volume)
	STUB(Mix_VolumeChunk)
	STUB(Mix_VolumeMusic)
	STUB(Mix_HaltChannel)
	STUB(Mix_HaltGroup)
	STUB(Mix_HaltMusic)
	STUB(Mix_ExpireChannel)
	STUB(Mix_FadeOutChannel)
	STUB(Mix_FadeOutGroup)
	STUB(Mix_FadeOutMusic)
	STUB(Mix_FadingMusic)
	STUB(Mix_FadingChannel)
	STUB(Mix_Pause)
	STUB(Mix_Resume)
	STUB(Mix_Paused)
	STUB(Mix_PauseMusic)
	STUB(Mix_ResumeMusic)
	STUB(Mix_RewindMusic)
	STUB(Mix_PausedMusic)
	STUB(Mix_SetMusicPosition)
	STUB(Mix_Playing)
	STUB(Mix_PlayingMusic)
	STUB(Mix_SetMusicCMD)
	STUB(Mix_SetSynchroValue)
	STUB(Mix_GetSynchroValue)
	STUB(Mix_SetSoundFonts)
	STUB(Mix_GetSoundFonts)
	STUB(Mix_EachSoundFont)
	STUB(Mix_GetChunk)
	STUB(Mix_CloseAudio)
	STUB(Mix_Linked_Version)
	STUB(Mix_GetMusicTitle)
	STUB(Mix_GetMusicTitleTag)
	STUB(Mix_GetMusicArtistTag)
	STUB(Mix_GetMusicAlbumTag)
	STUB(Mix_GetMusicCopyrightTag)
	STUB(Mix_GetMusicVolume)
	STUB(Mix_GetMusicPosition)
	STUB(Mix_MusicDuration)
	STUB(Mix_GetMusicLoopStartTime)
	STUB(Mix_GetMusicLoopEndTime)
	STUB(Mix_GetMusicLoopLengthTime)
	STUB(Mix_SetTimidityCfg)
	STUB(Mix_GetTimidityCfg)
	STUB(Mix_ModMusicJumpToOrder)
	