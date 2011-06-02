#ifndef _SOUND_PLAYER_H_
#define _SOUND_PLAYER_H_

#include <nds.h>

#ifndef USING_SDL

#include <maxmod9.h>

#include "soundbank.h"
#include "soundbank_bin.h"

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

#endif
	};

	/**
	 * Plays the barrier explosion sound.
	 */
	static void playBarrierExplode() {
#ifndef USING_SDL
		mmEffect(SFX_BARRIEREXPLODE);
#endif
	};

	/**
	 * Plays the barrier pushed sound.
	 */
	static void playBarrierPush() {
#ifndef USING_SDL
		mmEffect(SFX_BARRIERPUSH);
#endif
	};

	/**
	 * Plays the bean collection sound.
	 */
	static void playBeanCollect() {
#ifndef USING_SDL
		mmEffect(SFX_BEANCOLLECT);
#endif
	};

	/**
	 * Plays the block falling sound.
	 */
	static void playBlockFall() {
#ifndef USING_SDL
		mmEffect(SFX_BLOCKFALL);
#endif
	};

	/**
	 * Plays the block landing sound.
	 */
	static void playBlockLand() {
#ifndef USING_SDL
		mmEffect(SFX_BLOCKLAND);
#endif
	};

	/**
	 * Plays the boulder explosion sound.
	 */
	static void playBoulderExplode() {
#ifndef USING_SDL
		mmEffect(SFX_BOULDEREXPLODE);
#endif
	};

	/**
	 * Plays the bubble explosion sound.
	 */
	static void playBubbleExplode() {
#ifndef USING_SDL
		mmEffect(SFX_BUBBLEEXPLODE);
#endif
	};

	/**
	 * Plays the diamond collection sound.
	 */
	static void playDiamondCollect() {
#ifndef USING_SDL
		mmEffect(SFX_DIAMONDCOLLECT);
#endif
	};

	/**
	 * Plays the door opening sound.
	 */
	static void playDoorOpen() {
#ifndef USING_SDL
		mmEffect(SFX_DOOROPEN);
#endif
	};

	/**
	 * Plays the extra life collection sound.
	 */
	static void playExtraLifeCollect() {
#ifndef USING_SDL
		mmEffect(SFX_EXTRALIFECOLLECT);
#endif
	};

	/**
	 * Plays the game over music.
	 */
	static void playGameOverTheme() {
#ifndef USING_SDL
		_gameOverHandle = mmEffect(SFX_GAMEOVERTHEME);
#endif
	};

	/**
	 * Stops the game over music.
	 */
	static void stopGameOverTheme() {
#ifndef USING_SDL
		mmEffectCancel(_gameOverHandle);
#endif
	};

	/**
	 * Plays the gravity inversion sound.
	 */
	static void playGravityInversion() {
#ifndef USING_SDL
		mmEffectCancel(_gravityHandle);
		_gravityHandle = mmEffect(SFX_GRAVITYINVERSION);
#endif
	};

	/**
	 * Plays the level complete sound.
	 */
	static void playLevelComplete() {
#ifndef USING_SDL
		mmEffect(SFX_LEVELCOMPLETE);
#endif
	};

	/**
	 * Plays the map music.
	 */
	static void playMapTheme() {
#ifndef USING_SDL
		mmEffectCancel(_mapHandle);
		_mapHandle = mmEffect(SFX_MAPTHEME);
#endif
	};

	/**
	 * Stops the map music.
	 */
	static void stopMapTheme() {
#ifndef USING_SDL
		mmEffectCancel(_mapHandle);
#endif
	};

	/**
	 * Plays the game paused sound.
	 */
	static void playPause() {
#ifndef USING_SDL
		mmEffect(SFX_PAUSE);
#endif
	};

	/**
	 * Plays the player explosion sound.
	 */
	static void playPlayerExplode() {
#ifndef USING_SDL
		mmEffect(SFX_PLAYEREXPLODE);
#endif
	};

	/**
	 * Plays the soil digging sound.
	 */
	static void playSoilDig() {
#ifndef USING_SDL
		mmEffect(SFX_SOILDIG);
#endif
	};

	/**
	 * Plays the soil poking sound.
	 */
	static void playSoilPoke() {
#ifndef USING_SDL
		mmEffect(SFX_SOILPOKE);
#endif
	};

	/**
	 * Plays the suicide sound.
	 */
	static void playSuicide() {
#ifndef USING_SDL
		mmEffect(SFX_SUICIDE);
#endif
	};

	/**
	 * Plays the teleport collection sound.
	 */
	static void playTeleportCollect() {
#ifndef USING_SDL
		mmEffect(SFX_TELEPORTCOLLECT);
#endif
	};

	/**
	 * Plays the time ticking sound.
	 */
	static void playTime() {
#ifndef USING_SDL
		mmEffect(SFX_TIME);
#endif
	};

	/**
	 * Plays the title music.
	 */
	static void playTitleTheme() {
#ifndef USING_SDL
		_titleHandle = mmEffect(SFX_TITLETHEME);
#endif
	};

	/**
	 * Stops the title music.
	 */
	static void stopTitleTheme() {
#ifndef USING_SDL
		mmEffectCancel(_titleHandle);
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
#endif
	};

private:
#ifndef USING_SDL

	static mm_sfxhand _titleHandle;		/**< Handle for the title music. */
	static mm_sfxhand _gravityHandle;	/**< Handle for the gravity inversion sound. */
	static mm_sfxhand _gameOverHandle;	/**< Handle for the game over music. */
	static mm_sfxhand _mapHandle;		/**< Handle for the map music. */

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
