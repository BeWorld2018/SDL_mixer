/* Automatically generated header! Do not edit! */

#ifndef _PPCINLINE_SDL2_MIXER_H
#define _PPCINLINE_SDL2_MIXER_H

#ifndef __PPCINLINE_MACROS_H
#include <ppcinline/macros.h>
#endif /* !__PPCINLINE_MACROS_H */

#ifndef SDL2_MIXER_BASE_NAME
#define SDL2_MIXER_BASE_NAME SDL2MixerBase
#endif /* !SDL2_MIXER_BASE_NAME */

#define Mix_Linked_Version() \
	({ \
		long __base = (long)(SDL2_MIXER_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((const SDL_version *(*)(void))*(void**)(__base - 472))());\
	})

#define Mix_Init(__p0) \
	({ \
		int  __t__p0 = __p0;\
		long __base = (long)(SDL2_MIXER_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(int ))*(void**)(__base - 28))(__t__p0));\
	})

#define Mix_Quit() \
	({ \
		long __base = (long)(SDL2_MIXER_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(void))*(void**)(__base - 34))());\
	})

#define Mix_OpenAudio(__p0, __p1, __p2, __p3) \
	({ \
		int  __t__p0 = __p0;\
		Uint16  __t__p1 = __p1;\
		int  __t__p2 = __p2;\
		int  __t__p3 = __p3;\
		long __base = (long)(SDL2_MIXER_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(int , Uint16 , int , int ))*(void**)(__base - 40))(__t__p0, __t__p1, __t__p2, __t__p3));\
	})

#define Mix_OpenAudioDevice(__p0, __p1, __p2, __p3, __p4, __p5) \
	({ \
		int  __t__p0 = __p0;\
		Uint16  __t__p1 = __p1;\
		int  __t__p2 = __p2;\
		int  __t__p3 = __p3;\
		const char * __t__p4 = __p4;\
		int  __t__p5 = __p5;\
		long __base = (long)(SDL2_MIXER_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(int , Uint16 , int , int , const char *, int ))*(void**)(__base - 46))(__t__p0, __t__p1, __t__p2, __t__p3, __t__p4, __t__p5));\
	})

#define Mix_AllocateChannels(__p0) \
	({ \
		int  __t__p0 = __p0;\
		long __base = (long)(SDL2_MIXER_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(int ))*(void**)(__base - 52))(__t__p0));\
	})

#define Mix_QuerySpec(__p0, __p1, __p2) \
	({ \
		int * __t__p0 = __p0;\
		Uint16 * __t__p1 = __p1;\
		int * __t__p2 = __p2;\
		long __base = (long)(SDL2_MIXER_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(int *, Uint16 *, int *))*(void**)(__base - 58))(__t__p0, __t__p1, __t__p2));\
	})

#define Mix_LoadWAV_RW(__p0, __p1) \
	({ \
		SDL_RWops * __t__p0 = __p0;\
		int  __t__p1 = __p1;\
		long __base = (long)(SDL2_MIXER_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((Mix_Chunk *(*)(SDL_RWops *, int ))*(void**)(__base - 64))(__t__p0, __t__p1));\
	})

#define Mix_LoadMUS(__p0) \
	({ \
		const char * __t__p0 = __p0;\
		long __base = (long)(SDL2_MIXER_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((Mix_Music *(*)(const char *))*(void**)(__base - 70))(__t__p0));\
	})

#define Mix_LoadMUS_RW(__p0, __p1) \
	({ \
		SDL_RWops * __t__p0 = __p0;\
		int  __t__p1 = __p1;\
		long __base = (long)(SDL2_MIXER_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((Mix_Music *(*)(SDL_RWops *, int ))*(void**)(__base - 76))(__t__p0, __t__p1));\
	})

#define Mix_LoadMUSType_RW(__p0, __p1, __p2) \
	({ \
		SDL_RWops * __t__p0 = __p0;\
		Mix_MusicType  __t__p1 = __p1;\
		int  __t__p2 = __p2;\
		long __base = (long)(SDL2_MIXER_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((Mix_Music *(*)(SDL_RWops *, Mix_MusicType , int ))*(void**)(__base - 82))(__t__p0, __t__p1, __t__p2));\
	})

#define Mix_QuickLoad_WAV(__p0) \
	({ \
		Uint8 * __t__p0 = __p0;\
		long __base = (long)(SDL2_MIXER_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((Mix_Chunk *(*)(Uint8 *))*(void**)(__base - 88))(__t__p0));\
	})

#define Mix_QuickLoad_RAW(__p0, __p1) \
	({ \
		Uint8 * __t__p0 = __p0;\
		Uint32  __t__p1 = __p1;\
		long __base = (long)(SDL2_MIXER_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((Mix_Chunk *(*)(Uint8 *, Uint32 ))*(void**)(__base - 94))(__t__p0, __t__p1));\
	})

#define Mix_FreeChunk(__p0) \
	({ \
		Mix_Chunk * __t__p0 = __p0;\
		long __base = (long)(SDL2_MIXER_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(Mix_Chunk *))*(void**)(__base - 100))(__t__p0));\
	})

#define Mix_FreeMusic(__p0) \
	({ \
		Mix_Music * __t__p0 = __p0;\
		long __base = (long)(SDL2_MIXER_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(Mix_Music *))*(void**)(__base - 106))(__t__p0));\
	})

#define Mix_GetNumChunkDecoders() \
	({ \
		long __base = (long)(SDL2_MIXER_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(void))*(void**)(__base - 112))());\
	})

#define Mix_GetChunkDecoder(__p0) \
	({ \
		int  __t__p0 = __p0;\
		long __base = (long)(SDL2_MIXER_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((const char *(*)(int ))*(void**)(__base - 118))(__t__p0));\
	})

#define Mix_HasChunkDecoder(__p0) \
	({ \
		const char * __t__p0 = __p0;\
		long __base = (long)(SDL2_MIXER_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((SDL_bool (*)(const char *))*(void**)(__base - 124))(__t__p0));\
	})

#define Mix_GetNumMusicDecoders() \
	({ \
		long __base = (long)(SDL2_MIXER_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(void))*(void**)(__base - 130))());\
	})

#define Mix_GetMusicDecoder(__p0) \
	({ \
		int  __t__p0 = __p0;\
		long __base = (long)(SDL2_MIXER_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((const char *(*)(int ))*(void**)(__base - 136))(__t__p0));\
	})

#define Mix_GetMusicType(__p0) \
	({ \
		const Mix_Music * __t__p0 = __p0;\
		long __base = (long)(SDL2_MIXER_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((Mix_MusicType (*)(const Mix_Music *))*(void**)(__base - 142))(__t__p0));\
	})

#define Mix_SetPostMix(__p0, __p1) \
	({ \
		void (* __t__p0)(void *udata, Uint8 *stream, int len) = __p0;\
		void * __t__p1 = __p1;\
		long __base = (long)(SDL2_MIXER_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(void (*)(void *udata, Uint8 *stream, int len), void *))*(void**)(__base - 148))(__t__p0, __t__p1));\
	})

#define Mix_HookMusic(__p0, __p1) \
	({ \
		void (* __t__p0)(void *udata, Uint8 *stream, int len) = __p0;\
		void * __t__p1 = __p1;\
		long __base = (long)(SDL2_MIXER_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(void (*)(void *udata, Uint8 *stream, int len), void *))*(void**)(__base - 154))(__t__p0, __t__p1));\
	})

#define Mix_HookMusicFinished(__p0) \
	({ \
		void (* __t__p0)(void) = __p0;\
		long __base = (long)(SDL2_MIXER_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(void (*)(void)))*(void**)(__base - 160))(__t__p0));\
	})

#define Mix_GetMusicHookData() \
	({ \
		long __base = (long)(SDL2_MIXER_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void *(*)(void))*(void**)(__base - 166))());\
	})

#define Mix_ChannelFinished(__p0) \
	({ \
		void (* __t__p0)(int channel) = __p0;\
		long __base = (long)(SDL2_MIXER_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(void (*)(int channel)))*(void**)(__base - 172))(__t__p0));\
	})

#define Mix_RegisterEffect(__p0, __p1, __p2, __p3) \
	({ \
		int  __t__p0 = __p0;\
		Mix_EffectFunc_t  __t__p1 = __p1;\
		Mix_EffectDone_t  __t__p2 = __p2;\
		void * __t__p3 = __p3;\
		long __base = (long)(SDL2_MIXER_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(int , Mix_EffectFunc_t , Mix_EffectDone_t , void *))*(void**)(__base - 178))(__t__p0, __t__p1, __t__p2, __t__p3));\
	})

#define Mix_UnregisterEffect(__p0, __p1) \
	({ \
		int  __t__p0 = __p0;\
		Mix_EffectFunc_t  __t__p1 = __p1;\
		long __base = (long)(SDL2_MIXER_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(int , Mix_EffectFunc_t ))*(void**)(__base - 184))(__t__p0, __t__p1));\
	})

#define Mix_UnregisterAllEffects(__p0) \
	({ \
		int  __t__p0 = __p0;\
		long __base = (long)(SDL2_MIXER_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(int ))*(void**)(__base - 190))(__t__p0));\
	})

#define Mix_SetPanning(__p0, __p1, __p2) \
	({ \
		int  __t__p0 = __p0;\
		Uint8  __t__p1 = __p1;\
		Uint8  __t__p2 = __p2;\
		long __base = (long)(SDL2_MIXER_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(int , Uint8 , Uint8 ))*(void**)(__base - 196))(__t__p0, __t__p1, __t__p2));\
	})

#define Mix_SetPosition(__p0, __p1, __p2) \
	({ \
		int  __t__p0 = __p0;\
		Sint16  __t__p1 = __p1;\
		Uint8  __t__p2 = __p2;\
		long __base = (long)(SDL2_MIXER_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(int , Sint16 , Uint8 ))*(void**)(__base - 202))(__t__p0, __t__p1, __t__p2));\
	})

#define Mix_SetDistance(__p0, __p1) \
	({ \
		int  __t__p0 = __p0;\
		Uint8  __t__p1 = __p1;\
		long __base = (long)(SDL2_MIXER_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(int , Uint8 ))*(void**)(__base - 208))(__t__p0, __t__p1));\
	})

#define Mix_SetReverseStereo(__p0, __p1) \
	({ \
		int  __t__p0 = __p0;\
		int  __t__p1 = __p1;\
		long __base = (long)(SDL2_MIXER_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(int , int ))*(void**)(__base - 214))(__t__p0, __t__p1));\
	})

#define Mix_ReserveChannels(__p0) \
	({ \
		int  __t__p0 = __p0;\
		long __base = (long)(SDL2_MIXER_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(int ))*(void**)(__base - 220))(__t__p0));\
	})

#define Mix_GroupChannel(__p0, __p1) \
	({ \
		int  __t__p0 = __p0;\
		int  __t__p1 = __p1;\
		long __base = (long)(SDL2_MIXER_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(int , int ))*(void**)(__base - 226))(__t__p0, __t__p1));\
	})

#define Mix_GroupChannels(__p0, __p1, __p2) \
	({ \
		int  __t__p0 = __p0;\
		int  __t__p1 = __p1;\
		int  __t__p2 = __p2;\
		long __base = (long)(SDL2_MIXER_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(int , int , int ))*(void**)(__base - 232))(__t__p0, __t__p1, __t__p2));\
	})

#define Mix_GroupAvailable(__p0) \
	({ \
		int  __t__p0 = __p0;\
		long __base = (long)(SDL2_MIXER_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(int ))*(void**)(__base - 238))(__t__p0));\
	})

#define Mix_GroupCount(__p0) \
	({ \
		int  __t__p0 = __p0;\
		long __base = (long)(SDL2_MIXER_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(int ))*(void**)(__base - 244))(__t__p0));\
	})

#define Mix_GroupOldest(__p0) \
	({ \
		int  __t__p0 = __p0;\
		long __base = (long)(SDL2_MIXER_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(int ))*(void**)(__base - 250))(__t__p0));\
	})

#define Mix_GroupNewer(__p0) \
	({ \
		int  __t__p0 = __p0;\
		long __base = (long)(SDL2_MIXER_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(int ))*(void**)(__base - 256))(__t__p0));\
	})

#define Mix_PlayChannelTimed(__p0, __p1, __p2, __p3) \
	({ \
		int  __t__p0 = __p0;\
		Mix_Chunk * __t__p1 = __p1;\
		int  __t__p2 = __p2;\
		int  __t__p3 = __p3;\
		long __base = (long)(SDL2_MIXER_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(int , Mix_Chunk *, int , int ))*(void**)(__base - 262))(__t__p0, __t__p1, __t__p2, __t__p3));\
	})

#define Mix_PlayMusic(__p0, __p1) \
	({ \
		Mix_Music * __t__p0 = __p0;\
		int  __t__p1 = __p1;\
		long __base = (long)(SDL2_MIXER_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(Mix_Music *, int ))*(void**)(__base - 268))(__t__p0, __t__p1));\
	})

#define Mix_FadeInMusic(__p0, __p1, __p2) \
	({ \
		Mix_Music * __t__p0 = __p0;\
		int  __t__p1 = __p1;\
		int  __t__p2 = __p2;\
		long __base = (long)(SDL2_MIXER_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(Mix_Music *, int , int ))*(void**)(__base - 274))(__t__p0, __t__p1, __t__p2));\
	})

#define Mix_FadeInMusicPos(__p0, __p1, __p2, __p3) \
	({ \
		Mix_Music * __t__p0 = __p0;\
		int  __t__p1 = __p1;\
		int  __t__p2 = __p2;\
		double  __t__p3 = __p3;\
		long __base = (long)(SDL2_MIXER_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(Mix_Music *, int , int , double ))*(void**)(__base - 280))(__t__p0, __t__p1, __t__p2, __t__p3));\
	})

#define Mix_FadeInChannelTimed(__p0, __p1, __p2, __p3, __p4) \
	({ \
		int  __t__p0 = __p0;\
		Mix_Chunk * __t__p1 = __p1;\
		int  __t__p2 = __p2;\
		int  __t__p3 = __p3;\
		int  __t__p4 = __p4;\
		long __base = (long)(SDL2_MIXER_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(int , Mix_Chunk *, int , int , int ))*(void**)(__base - 286))(__t__p0, __t__p1, __t__p2, __t__p3, __t__p4));\
	})

#define Mix_Volume(__p0, __p1) \
	({ \
		int  __t__p0 = __p0;\
		int  __t__p1 = __p1;\
		long __base = (long)(SDL2_MIXER_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(int , int ))*(void**)(__base - 292))(__t__p0, __t__p1));\
	})

#define Mix_VolumeChunk(__p0, __p1) \
	({ \
		Mix_Chunk * __t__p0 = __p0;\
		int  __t__p1 = __p1;\
		long __base = (long)(SDL2_MIXER_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(Mix_Chunk *, int ))*(void**)(__base - 298))(__t__p0, __t__p1));\
	})

#define Mix_VolumeMusic(__p0) \
	({ \
		int  __t__p0 = __p0;\
		long __base = (long)(SDL2_MIXER_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(int ))*(void**)(__base - 304))(__t__p0));\
	})

#define Mix_HaltChannel(__p0) \
	({ \
		int  __t__p0 = __p0;\
		long __base = (long)(SDL2_MIXER_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(int ))*(void**)(__base - 310))(__t__p0));\
	})

#define Mix_HaltGroup(__p0) \
	({ \
		int  __t__p0 = __p0;\
		long __base = (long)(SDL2_MIXER_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(int ))*(void**)(__base - 316))(__t__p0));\
	})

#define Mix_HaltMusic() \
	({ \
		long __base = (long)(SDL2_MIXER_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(void))*(void**)(__base - 322))());\
	})

#define Mix_ExpireChannel(__p0, __p1) \
	({ \
		int  __t__p0 = __p0;\
		int  __t__p1 = __p1;\
		long __base = (long)(SDL2_MIXER_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(int , int ))*(void**)(__base - 328))(__t__p0, __t__p1));\
	})

#define Mix_FadeOutChannel(__p0, __p1) \
	({ \
		int  __t__p0 = __p0;\
		int  __t__p1 = __p1;\
		long __base = (long)(SDL2_MIXER_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(int , int ))*(void**)(__base - 334))(__t__p0, __t__p1));\
	})

#define Mix_FadeOutGroup(__p0, __p1) \
	({ \
		int  __t__p0 = __p0;\
		int  __t__p1 = __p1;\
		long __base = (long)(SDL2_MIXER_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(int , int ))*(void**)(__base - 340))(__t__p0, __t__p1));\
	})

#define Mix_FadeOutMusic(__p0) \
	({ \
		int  __t__p0 = __p0;\
		long __base = (long)(SDL2_MIXER_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(int ))*(void**)(__base - 346))(__t__p0));\
	})

#define Mix_FadingMusic() \
	({ \
		long __base = (long)(SDL2_MIXER_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((Mix_Fading (*)(void))*(void**)(__base - 352))());\
	})

#define Mix_FadingChannel(__p0) \
	({ \
		int  __t__p0 = __p0;\
		long __base = (long)(SDL2_MIXER_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((Mix_Fading (*)(int ))*(void**)(__base - 358))(__t__p0));\
	})

#define Mix_Pause(__p0) \
	({ \
		int  __t__p0 = __p0;\
		long __base = (long)(SDL2_MIXER_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(int ))*(void**)(__base - 364))(__t__p0));\
	})

#define Mix_Resume(__p0) \
	({ \
		int  __t__p0 = __p0;\
		long __base = (long)(SDL2_MIXER_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(int ))*(void**)(__base - 370))(__t__p0));\
	})

#define Mix_Paused(__p0) \
	({ \
		int  __t__p0 = __p0;\
		long __base = (long)(SDL2_MIXER_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(int ))*(void**)(__base - 376))(__t__p0));\
	})

#define Mix_PauseMusic() \
	({ \
		long __base = (long)(SDL2_MIXER_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(void))*(void**)(__base - 382))());\
	})

#define Mix_ResumeMusic() \
	({ \
		long __base = (long)(SDL2_MIXER_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(void))*(void**)(__base - 388))());\
	})

#define Mix_RewindMusic() \
	({ \
		long __base = (long)(SDL2_MIXER_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(void))*(void**)(__base - 394))());\
	})

#define Mix_PausedMusic() \
	({ \
		long __base = (long)(SDL2_MIXER_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(void))*(void**)(__base - 400))());\
	})

#define Mix_SetMusicPosition(__p0) \
	({ \
		double  __t__p0 = __p0;\
		long __base = (long)(SDL2_MIXER_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(double ))*(void**)(__base - 406))(__t__p0));\
	})

#define Mix_Playing(__p0) \
	({ \
		int  __t__p0 = __p0;\
		long __base = (long)(SDL2_MIXER_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(int ))*(void**)(__base - 412))(__t__p0));\
	})

#define Mix_PlayingMusic() \
	({ \
		long __base = (long)(SDL2_MIXER_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(void))*(void**)(__base - 418))());\
	})

#define Mix_SetMusicCMD(__p0) \
	({ \
		const char * __t__p0 = __p0;\
		long __base = (long)(SDL2_MIXER_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(const char *))*(void**)(__base - 424))(__t__p0));\
	})

#define Mix_SetSynchroValue(__p0) \
	({ \
		int  __t__p0 = __p0;\
		long __base = (long)(SDL2_MIXER_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(int ))*(void**)(__base - 430))(__t__p0));\
	})

#define Mix_GetSynchroValue() \
	({ \
		long __base = (long)(SDL2_MIXER_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(void))*(void**)(__base - 436))());\
	})

#define Mix_SetSoundFonts(__p0) \
	({ \
		const char * __t__p0 = __p0;\
		long __base = (long)(SDL2_MIXER_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(const char *))*(void**)(__base - 442))(__t__p0));\
	})

#define Mix_GetSoundFonts() \
	({ \
		long __base = (long)(SDL2_MIXER_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((const char *(*)(void))*(void**)(__base - 448))());\
	})

#define Mix_EachSoundFont(__p0, __p1) \
	({ \
		int (* __t__p0)(const char*, void*) = __p0;\
		void * __t__p1 = __p1;\
		long __base = (long)(SDL2_MIXER_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(int (*)(const char*, void*), void *))*(void**)(__base - 454))(__t__p0, __t__p1));\
	})

#define Mix_GetChunk(__p0) \
	({ \
		int  __t__p0 = __p0;\
		long __base = (long)(SDL2_MIXER_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((Mix_Chunk *(*)(int ))*(void**)(__base - 460))(__t__p0));\
	})

#define Mix_CloseAudio() \
	({ \
		long __base = (long)(SDL2_MIXER_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(void))*(void**)(__base - 466))());\
	})

#define Mix_GetMusicTitle(__p0) \
	({ \
		const Mix_Music * __t__p0 = __p0;\
		long __base = (long)(SDL2_MIXER_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((const char *(*)(const Mix_Music *))*(void**)(__base - 478))(__t__p0));\
	})

#define Mix_GetMusicTitleTag(__p0) \
	({ \
		const Mix_Music * __t__p0 = __p0;\
		long __base = (long)(SDL2_MIXER_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((const char *(*)(const Mix_Music *))*(void**)(__base - 484))(__t__p0));\
	})

#define Mix_GetMusicArtistTag(__p0) \
	({ \
		const Mix_Music * __t__p0 = __p0;\
		long __base = (long)(SDL2_MIXER_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((const char *(*)(const Mix_Music *))*(void**)(__base - 490))(__t__p0));\
	})

#define Mix_GetMusicAlbumTag(__p0) \
	({ \
		const Mix_Music * __t__p0 = __p0;\
		long __base = (long)(SDL2_MIXER_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((const char *(*)(const Mix_Music *))*(void**)(__base - 496))(__t__p0));\
	})

#define Mix_GetMusicCopyrightTag(__p0) \
	({ \
		const Mix_Music * __t__p0 = __p0;\
		long __base = (long)(SDL2_MIXER_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((const char *(*)(const Mix_Music *))*(void**)(__base - 502))(__t__p0));\
	})

#define Mix_GetMusicVolume(__p0) \
	({ \
		Mix_Music * __t__p0 = __p0;\
		long __base = (long)(SDL2_MIXER_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(Mix_Music *))*(void**)(__base - 508))(__t__p0));\
	})

#define Mix_GetMusicPosition(__p0) \
	({ \
		Mix_Music * __t__p0 = __p0;\
		long __base = (long)(SDL2_MIXER_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((double (*)(Mix_Music *))*(void**)(__base - 514))(__t__p0));\
	})

#define Mix_MusicDuration(__p0) \
	({ \
		Mix_Music * __t__p0 = __p0;\
		long __base = (long)(SDL2_MIXER_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((double (*)(Mix_Music *))*(void**)(__base - 520))(__t__p0));\
	})

#define Mix_GetMusicLoopStartTime(__p0) \
	({ \
		Mix_Music * __t__p0 = __p0;\
		long __base = (long)(SDL2_MIXER_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((double (*)(Mix_Music *))*(void**)(__base - 526))(__t__p0));\
	})

#define Mix_GetMusicLoopEndTime(__p0) \
	({ \
		Mix_Music * __t__p0 = __p0;\
		long __base = (long)(SDL2_MIXER_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((double (*)(Mix_Music *))*(void**)(__base - 532))(__t__p0));\
	})

#define Mix_GetMusicLoopLengthTime(__p0) \
	({ \
		Mix_Music * __t__p0 = __p0;\
		long __base = (long)(SDL2_MIXER_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((double (*)(Mix_Music *))*(void**)(__base - 538))(__t__p0));\
	})

#define Mix_SetTimidityCfg(__p0) \
	({ \
		const char * __t__p0 = __p0;\
		long __base = (long)(SDL2_MIXER_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(const char *))*(void**)(__base - 544))(__t__p0));\
	})

#define Mix_GetTimidityCfg() \
	({ \
		long __base = (long)(SDL2_MIXER_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((const char *(*)(void))*(void**)(__base - 550))());\
	})

#define Mix_ModMusicJumpToOrder(__p0) \
	({ \
		int  __t__p0 = __p0;\
		long __base = (long)(SDL2_MIXER_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(int ))*(void**)(__base - 556))(__t__p0));\
	})

#endif /* !_PPCINLINE_SDL2_MIXER_H */
