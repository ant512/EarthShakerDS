#ifndef _SOUND_PLAYER_H_
#define _SOUND_PLAYER_H_

#include <nds.h>

#ifndef USING_SDL

#include <maxmod9.h>

#include "soundbank.h"
#include "soundbank_bin.h"

#else

#include <SDL_mixer/SDL_mixer.h>
#include <unistd.h>
#include <mach-o/dyld.h>
#include <woopsistring.h>

#endif

/**
 * Manages all sounds within the game.
 */
class SoundPlayer {
public:

	/**
	 * Initialises all game sounds.
	 */
	static void init() {

#ifndef USING_SDL

		mmInitDefaultMem((mm_addr)soundbank_bin);
		mmLoadEffect(SFX_BARRIEREXPLODE);
		mmLoadEffect(SFX_BARRIERPUSH);
		mmLoadEffect(SFX_BEANCOLLECT);
		mmLoadEffect(SFX_BLOCKFALL);
		mmLoadEffect(SFX_BLOCKLAND);
		mmLoadEffect(SFX_BOULDEREXPLODE);
		mmLoadEffect(SFX_BUBBLEEXPLODE);
		mmLoadEffect(SFX_DIAMONDCOLLECT);
		mmLoadEffect(SFX_DOOROPEN);
		mmLoadEffect(SFX_EXTRALIFECOLLECT);
		mmLoadEffect(SFX_GAMEOVERTHEME);
		mmLoadEffect(SFX_GRAVITYINVERSION);
		mmLoadEffect(SFX_LEVELCOMPLETE);
		mmLoadEffect(SFX_PAUSE);
		mmLoadEffect(SFX_PLAYEREXPLODE);
		mmLoadEffect(SFX_MAPTHEME);
		mmLoadEffect(SFX_SOILDIG);
		mmLoadEffect(SFX_SOILPOKE);
		mmLoadEffect(SFX_SUICIDE);
		mmLoadEffect(SFX_TELEPORTCOLLECT);
		mmLoadEffect(SFX_TIME);
		mmLoadEffect(SFX_TITLETHEME);
		
#else
		
		Mix_OpenAudio(MIX_DEFAULT_FREQUENCY, AUDIO_S8, MIX_DEFAULT_CHANNELS, 512);		
		Mix_Volume(-1, 60);
		
		// Load sfx from resources folder
		loadWav(SFX_BARRIEREXPLODE, "../Resources/barrierexplode.wav");
		loadWav(SFX_BARRIERPUSH, "../Resources/barrierpush.wav");
		loadWav(SFX_BEANCOLLECT, "../Resources/beancollect.wav");
		loadWav(SFX_BLOCKFALL, "../Resources/blockfall.wav");
		loadWav(SFX_BLOCKLAND, "../Resources/blockland.wav");
		loadWav(SFX_BOULDEREXPLODE, "../Resources/boulderexplode.wav");
		loadWav(SFX_BUBBLEEXPLODE, "../Resources/bubbleexplode.wav");
		loadWav(SFX_DIAMONDCOLLECT, "../Resources/diamondcollect.wav");
		loadWav(SFX_DOOROPEN, "../Resources/dooropen.wav");
		loadWav(SFX_EXTRALIFECOLLECT, "../Resources/extralifecollect.wav");
		loadWav(SFX_GAMEOVERTHEME, "../Resources/gameovertheme.wav");
		loadWav(SFX_GRAVITYINVERSION, "../Resources/gravityinversion.wav");
		loadWav(SFX_LEVELCOMPLETE, "../Resources/levelcomplete.wav");
		loadWav(SFX_PAUSE, "../Resources/pause.wav");
		loadWav(SFX_PLAYEREXPLODE, "../Resources/playerexplode.wav");
		loadWav(SFX_MAPTHEME, "../Resources/maptheme.wav");
		loadWav(SFX_SOILDIG, "../Resources/soildig.wav");
		loadWav(SFX_SOILPOKE, "../Resources/soilpoke.wav");
		loadWav(SFX_SUICIDE, "../Resources/suicide.wav");
		loadWav(SFX_TELEPORTCOLLECT, "../Resources/teleportcollect.wav");
		loadWav(SFX_TIME, "../Resources/time.wav");
		loadWav(SFX_TITLETHEME, "../Resources/titletheme.wav");
#endif
	};

	/**
	 * Plays the barrier explosion sound.
	 */
	static void playBarrierExplode() {
#ifndef USING_SDL
		mmEffect(SFX_BARRIEREXPLODE);
#else
		Mix_PlayChannel(CHANNEL_SFX, _sounds[SFX_BARRIEREXPLODE], 0);
#endif
	};

	/**
	 * Plays the barrier pushed sound.
	 */
	static void playBarrierPush() {
#ifndef USING_SDL
		mmEffect(SFX_BARRIERPUSH);
#else
		Mix_PlayChannel(CHANNEL_SFX, _sounds[SFX_BARRIERPUSH], 0);
#endif
	};

	/**
	 * Plays the bean collection sound.
	 */
	static void playBeanCollect() {
#ifndef USING_SDL
		mmEffect(SFX_BEANCOLLECT);
#else
		Mix_PlayChannel(CHANNEL_SFX, _sounds[SFX_BEANCOLLECT], 0);
#endif
	};

	/**
	 * Plays the block falling sound.
	 */
	static void playBlockFall() {
#ifndef USING_SDL
		mmEffect(SFX_BLOCKFALL);
#else
		Mix_PlayChannel(CHANNEL_SFX, _sounds[SFX_BLOCKFALL], 0);
#endif
	};

	/**
	 * Plays the block landing sound.
	 */
	static void playBlockLand() {
#ifndef USING_SDL
		mmEffect(SFX_BLOCKLAND);
#else
		Mix_PlayChannel(CHANNEL_SFX, _sounds[SFX_BLOCKLAND], 0);
#endif
	};

	/**
	 * Plays the boulder explosion sound.
	 */
	static void playBoulderExplode() {
#ifndef USING_SDL
		mmEffect(SFX_BOULDEREXPLODE);
#else
		Mix_PlayChannel(CHANNEL_SFX, _sounds[SFX_BOULDEREXPLODE], 0);
#endif
	};

	/**
	 * Plays the bubble explosion sound.
	 */
	static void playBubbleExplode() {
#ifndef USING_SDL
		mmEffect(SFX_BUBBLEEXPLODE);
#else
		Mix_PlayChannel(CHANNEL_SFX, _sounds[SFX_BUBBLEEXPLODE], 0);
#endif
	};

	/**
	 * Plays the diamond collection sound.
	 */
	static void playDiamondCollect() {
#ifndef USING_SDL
		mmEffect(SFX_DIAMONDCOLLECT);
#else
		Mix_PlayChannel(CHANNEL_SFX, _sounds[SFX_DIAMONDCOLLECT], 0);
#endif
	};

	/**
	 * Plays the door opening sound.
	 */
	static void playDoorOpen() {
#ifndef USING_SDL
		mmEffect(SFX_DOOROPEN);
#else
		Mix_PlayChannel(CHANNEL_SFX, _sounds[SFX_DOOROPEN], 0);
#endif
	};

	/**
	 * Plays the extra life collection sound.
	 */
	static void playExtraLifeCollect() {
#ifndef USING_SDL
		mmEffect(SFX_EXTRALIFECOLLECT);
#else
		Mix_PlayChannel(CHANNEL_SFX, _sounds[SFX_EXTRALIFECOLLECT], 0);
#endif
	};

	/**
	 * Plays the game over music.
	 */
	static void playGameOverTheme() {
#ifndef USING_SDL
		_gameOverHandle = mmEffect(SFX_GAMEOVERTHEME);
#else
		Mix_PlayChannel(CHANNEL_MUSIC, _sounds[SFX_GAMEOVERTHEME], 0);
#endif
	};

	/**
	 * Stops the game over music.
	 */
	static void stopGameOverTheme() {
#ifndef USING_SDL
		mmEffectCancel(_gameOverHandle);
#else
		Mix_HaltChannel(CHANNEL_MUSIC);
#endif
	};

	/**
	 * Plays the gravity inversion sound.
	 */
	static void playGravityInversion() {
#ifndef USING_SDL
		mmEffectCancel(_gravityHandle);
		_gravityHandle = mmEffect(SFX_GRAVITYINVERSION);
#else
		Mix_HaltChannel(CHANNEL_GRAVITY);
		Mix_PlayChannel(CHANNEL_GRAVITY, _sounds[SFX_GRAVITYINVERSION], 0);
#endif
	};

	/**
	 * Plays the level complete sound.
	 */
	static void playLevelComplete() {
#ifndef USING_SDL
		mmEffect(SFX_LEVELCOMPLETE);
#else
		Mix_PlayChannel(CHANNEL_SFX, _sounds[SFX_LEVELCOMPLETE], 0);
#endif
	};

	/**
	 * Plays the map music.
	 */
	static void playMapTheme() {
#ifndef USING_SDL
		mmEffectCancel(_mapHandle);
		_mapHandle = mmEffect(SFX_MAPTHEME);
#else
		Mix_HaltChannel(CHANNEL_MUSIC);
		Mix_PlayChannel(CHANNEL_MUSIC, _sounds[SFX_MAPTHEME], 0);
#endif
	};

	/**
	 * Stops the map music.
	 */
	static void stopMapTheme() {
#ifndef USING_SDL
		mmEffectCancel(_mapHandle);
#else
		Mix_HaltChannel(CHANNEL_MUSIC);
#endif
	};

	/**
	 * Plays the game paused sound.
	 */
	static void playPause() {
#ifndef USING_SDL
		mmEffect(SFX_PAUSE);
#else
		Mix_PlayChannel(CHANNEL_SFX, _sounds[SFX_PAUSE], 0);
#endif
	};

	/**
	 * Plays the player explosion sound.
	 */
	static void playPlayerExplode() {
#ifndef USING_SDL
		mmEffect(SFX_PLAYEREXPLODE);
#else
		Mix_PlayChannel(CHANNEL_SFX, _sounds[SFX_PLAYEREXPLODE], 0);
#endif
	};

	/**
	 * Plays the soil digging sound.
	 */
	static void playSoilDig() {
#ifndef USING_SDL
		mmEffect(SFX_SOILDIG);
#else
		Mix_PlayChannel(CHANNEL_SFX, _sounds[SFX_SOILDIG], 0);
#endif
	};

	/**
	 * Plays the soil poking sound.
	 */
	static void playSoilPoke() {
#ifndef USING_SDL
		mmEffect(SFX_SOILPOKE);
#else
		Mix_PlayChannel(CHANNEL_SFX, _sounds[SFX_SOILPOKE], 0);
#endif
	};

	/**
	 * Plays the suicide sound.
	 */
	static void playSuicide() {
#ifndef USING_SDL
		mmEffect(SFX_SUICIDE);
#else
		Mix_PlayChannel(CHANNEL_SFX, _sounds[SFX_SUICIDE], 0);
#endif
	};

	/**
	 * Plays the teleport collection sound.
	 */
	static void playTeleportCollect() {
#ifndef USING_SDL
		mmEffect(SFX_TELEPORTCOLLECT);
#else
		Mix_PlayChannel(CHANNEL_SFX, _sounds[SFX_TELEPORTCOLLECT], 0);
#endif
	};

	/**
	 * Plays the time ticking sound.
	 */
	static void playTime() {
#ifndef USING_SDL
		mmEffect(SFX_TIME);
#else
		Mix_PlayChannel(CHANNEL_SFX, _sounds[SFX_TIME], 0);
#endif
	};

	/**
	 * Plays the title music.
	 */
	static void playTitleTheme() {
#ifndef USING_SDL
		mmEffectCancel(_titleHandle);
		_titleHandle = mmEffect(SFX_TITLETHEME);
#else
		Mix_HaltChannel(CHANNEL_MUSIC);
		Mix_PlayChannel(CHANNEL_MUSIC, _sounds[SFX_TITLETHEME], 0);
#endif
	};

	/**
	 * Stops the title music.
	 */
	static void stopTitleTheme() {
#ifndef USING_SDL
		mmEffectCancel(_titleHandle);
#else
		Mix_HaltChannel(CHANNEL_MUSIC);
#endif
	};

	/**
	 * Stops all (long running) sounds.
	 */
	static void stopAll() {
#ifndef USING_SDL
		mmEffectCancel(_titleHandle);
		mmEffectCancel(_gravityHandle);
		mmEffectCancel(_gameOverHandle);
		mmEffectCancel(_mapHandle);
#else
		Mix_HaltChannel(CHANNEL_MUSIC);
		Mix_HaltChannel(CHANNEL_SFX);
		Mix_HaltChannel(CHANNEL_GRAVITY);
#endif
	};

	/**
	 * Shuts down all game sounds.
	 */
	static void shutdown() {
		
#ifndef USING_SDL
		
		mmUnloadEffect(SFX_BARRIEREXPLODE);
		mmUnloadEffect(SFX_BARRIERPUSH);
		mmUnloadEffect(SFX_BEANCOLLECT);
		mmUnloadEffect(SFX_BLOCKFALL);
		mmUnloadEffect(SFX_BLOCKLAND);
		mmUnloadEffect(SFX_BOULDEREXPLODE);
		mmUnloadEffect(SFX_BUBBLEEXPLODE);
		mmUnloadEffect(SFX_DIAMONDCOLLECT);
		mmUnloadEffect(SFX_DOOROPEN);
		mmUnloadEffect(SFX_EXTRALIFECOLLECT);
		mmUnloadEffect(SFX_GAMEOVERTHEME);
		mmUnloadEffect(SFX_GRAVITYINVERSION);
		mmUnloadEffect(SFX_LEVELCOMPLETE);
		mmUnloadEffect(SFX_PAUSE);
		mmUnloadEffect(SFX_PLAYEREXPLODE);
		mmUnloadEffect(SFX_MAPTHEME);
		mmUnloadEffect(SFX_SOILDIG);
		mmUnloadEffect(SFX_SOILPOKE);
		mmUnloadEffect(SFX_SUICIDE);
		mmUnloadEffect(SFX_TELEPORTCOLLECT);
		mmUnloadEffect(SFX_TIME);
		mmUnloadEffect(SFX_TITLETHEME);
		
#else
		
		for (u32 i = 0; i < SOUND_TYPE_COUNT; i++) {
			Mix_FreeChunk(_sounds[i]);
		}
		
		Mix_CloseAudio();
		
#endif
		
	};

private:
#ifndef USING_SDL

	static mm_sfxhand _titleHandle;		/**< Handle for the title music. */
	static mm_sfxhand _gravityHandle;	/**< Handle for the gravity inversion sound. */
	static mm_sfxhand _gameOverHandle;	/**< Handle for the game over music. */
	static mm_sfxhand _mapHandle;		/**< Handle for the map music. */
	
#else
	
	static const u32 SOUND_TYPE_COUNT = 22;
	
	enum SFXType {
		SFX_BARRIEREXPLODE = 0,
		SFX_BARRIERPUSH = 1,
		SFX_BEANCOLLECT = 2,
		SFX_BLOCKFALL = 3,
		SFX_BLOCKLAND = 4,
		SFX_BOULDEREXPLODE = 5,
		SFX_BUBBLEEXPLODE = 6,
		SFX_DIAMONDCOLLECT = 7,
		SFX_DOOROPEN = 8,
		SFX_EXTRALIFECOLLECT = 9,
		SFX_GAMEOVERTHEME = 10,
		SFX_GRAVITYINVERSION = 11,
		SFX_LEVELCOMPLETE = 12,
		SFX_MAPTHEME = 13,
		SFX_PAUSE = 14,
		SFX_PLAYEREXPLODE = 15,
		SFX_SOILDIG = 16,
		SFX_SOILPOKE = 17,
		SFX_SUICIDE = 18,
		SFX_TELEPORTCOLLECT = 19,
		SFX_TIME = 20,
		SFX_TITLETHEME = 21
	};
	
	enum ChannelType {
		CHANNEL_SFX = -1,
		CHANNEL_MUSIC = 0,
		CHANNEL_GRAVITY = 1,
	};
	
	static Mix_Chunk* _sounds[SOUND_TYPE_COUNT];

	static void loadWav(SFXType type, const char* fileName) {
		
		// Get path of executable
		char path[1024];
		uint32_t size = sizeof(path);
		_NSGetExecutablePath(path, &size);
		
		WoopsiGfx::WoopsiString str(path);
		
		// Strip the name of the executable
		s32 lastIndex = str.lastIndexOf('/');
		str = str.subString(0, lastIndex);
		
		// Add the name of the wav
		str.append("/");
		str.append(fileName);
		
		char* buffer = new char[str.getByteCount() + 1];
		str.copyToCharArray(buffer);
		
		_sounds[type] = Mix_LoadWAV(buffer);
		
		delete[] buffer;
	};

#endif

	/**
	 * Constructor.
	 */
	SoundPlayer() { };

	/**
	 * Destructor.
	 */
	~SoundPlayer() { };
};

#endif
