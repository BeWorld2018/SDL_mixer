#ifndef SDL2_MIXER_PROTOS
#define SDL2_MIXER_PROTOS

#ifndef	_SDL_H
#include <SDL.h>
#endif

//#include <SDL_mixer.h>

#ifdef __cplusplus
extern "C" {
#endif
	
const SDL_version * Mix_Linked_Version(void);
int  Mix_Init(int flags);
void Mix_Quit(void);
int Mix_OpenAudio(int frequency, Uint16 format, int channels, int chunksize);
int Mix_OpenAudioDevice(int frequency, Uint16 format, int channels, int chunksize, const char* device, int allowed_changes);
int Mix_AllocateChannels(int numchans);
int Mix_QuerySpec(int *frequency,Uint16 *format,int *channels);
Mix_Chunk * Mix_LoadWAV_RW(SDL_RWops *src, int freesrc);
Mix_Music * Mix_LoadMUS(const char *file);
Mix_Music * Mix_LoadMUS_RW(SDL_RWops *src, int freesrc);
Mix_Music * Mix_LoadMUSType_RW(SDL_RWops *src, Mix_MusicType type, int freesrc);
Mix_Chunk * Mix_QuickLoad_WAV(Uint8 *mem);
Mix_Chunk * Mix_QuickLoad_RAW(Uint8 *mem, Uint32 len);
void Mix_FreeChunk(Mix_Chunk *chunk);
void Mix_FreeMusic(Mix_Music *music);
	
int Mix_GetNumChunkDecoders(void);
const char * Mix_GetChunkDecoder(int index);
SDL_bool Mix_HasChunkDecoder(const char *name);
int Mix_GetNumMusicDecoders(void);
const char * Mix_GetMusicDecoder(int index);
//SDL_bool Mix_HasMusicDecoder(const char *name);

Mix_MusicType Mix_GetMusicType(const Mix_Music *music);
void Mix_SetPostMix(void (*mix_func)(void *udata, Uint8 *stream, int len), void *arg);
void Mix_HookMusic(void (*mix_func)(void *udata, Uint8 *stream, int len), void *arg);
void Mix_HookMusicFinished(void (*music_finished)(void));
void * Mix_GetMusicHookData(void);
void Mix_ChannelFinished(void (*channel_finished)(int channel));

int Mix_RegisterEffect(int chan, Mix_EffectFunc_t f, Mix_EffectDone_t d, void *arg);
int Mix_UnregisterEffect(int channel, Mix_EffectFunc_t f);
int Mix_UnregisterAllEffects(int channel);
int Mix_SetPanning(int channel, Uint8 left, Uint8 right);
int Mix_SetPosition(int channel, Sint16 angle, Uint8 distance);
int Mix_SetDistance(int channel, Uint8 distance);
int Mix_SetReverseStereo(int channel, int flip);
int Mix_ReserveChannels(int num);
int Mix_GroupChannel(int which, int tag);
int Mix_GroupChannels(int from, int to, int tag);
int Mix_GroupAvailable(int tag);
int Mix_GroupCount(int tag);
int Mix_GroupOldest(int tag);
int Mix_GroupNewer(int tag);
int Mix_PlayChannelTimed(int channel, Mix_Chunk *chunk, int loops, int ticks);
int Mix_PlayMusic(Mix_Music *music, int loops);
int Mix_FadeInMusic(Mix_Music *music, int loops, int ms);
int Mix_FadeInMusicPos(Mix_Music *music, int loops, int ms, double position);
int Mix_FadeInChannelTimed(int channel, Mix_Chunk *chunk, int loops, int ms, int ticks);
int Mix_Volume(int channel, int volume);
int Mix_VolumeChunk(Mix_Chunk *chunk, int volume);
int Mix_VolumeMusic(int volume);
int Mix_HaltChannel(int channel);
int Mix_HaltGroup(int tag);
int Mix_HaltMusic(void);
int Mix_ExpireChannel(int channel, int ticks);
int Mix_FadeOutChannel(int which, int ms);
int Mix_FadeOutGroup(int tag, int ms);
int Mix_FadeOutMusic(int ms);
Mix_Fading Mix_FadingMusic(void);
Mix_Fading Mix_FadingChannel(int which);
void Mix_Pause(int channel);
void Mix_Resume(int channel);
int Mix_Paused(int channel);
void Mix_PauseMusic(void);
void Mix_ResumeMusic(void);
void Mix_RewindMusic(void);
int Mix_PausedMusic(void);
int Mix_SetMusicPosition(double position);
int Mix_Playing(int channel);
int Mix_PlayingMusic(void);
int Mix_SetMusicCMD(const char *command);
int Mix_SetSynchroValue(int value);
int Mix_GetSynchroValue(void);
int Mix_SetSoundFonts(const char *paths);
const char* Mix_GetSoundFonts(void);
int Mix_EachSoundFont(int (*function)(const char*, void*), void *data);
Mix_Chunk * Mix_GetChunk(int channel);
void Mix_CloseAudio(void);
const char* Mix_GetMusicTitle(const Mix_Music *music);
const char* Mix_GetMusicTitleTag(const Mix_Music *music);
const char* Mix_GetMusicArtistTag(const Mix_Music *music);
const char* Mix_GetMusicAlbumTag(const Mix_Music *music);
const char* Mix_GetMusicCopyrightTag(const Mix_Music *music);
int Mix_GetMusicVolume(Mix_Music *music);
double Mix_GetMusicPosition(Mix_Music *music);
double Mix_MusicDuration(Mix_Music *music);
double Mix_GetMusicLoopStartTime(Mix_Music *music);
double Mix_GetMusicLoopEndTime(Mix_Music *music);
double Mix_GetMusicLoopLengthTime(Mix_Music *music);
int Mix_SetTimidityCfg(const char *path);
const char* Mix_GetTimidityCfg(void);
int Mix_ModMusicJumpToOrder(int order);

#ifdef __cplusplus
}
#endif

#endif /* SDL2_IMAGE_PROTOS */
