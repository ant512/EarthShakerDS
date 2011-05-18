#ifndef _SOUND_PLAYER_H_
#define _SOUND_PLAYER_H_

#include <nds.h>
#include <maxmod9.h>

#include "soundbank.h"
#include "soundbank_bin.h"

/**
 * Manages all sounds within the game.
 */
class SoundPlayer {
public:

	/**
	 * Initialises all game sounds.
	 */
	static void init() {
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
		mmLoadEffect(SFX_GRAVITYINVERSION);
		mmLoadEffect(SFX_LEVELCOMPLETE);
		mmLoadEffect(SFX_PAUSE);
		mmLoadEffect(SFX_PLAYEREXPLODE);
		mmLoadEffect(SFX_SOILDIG);
		mmLoadEffect(SFX_TELEPORTCOLLECT);
		mmLoadEffect(SFX_TIME);
		mmLoadEffect(SFX_TITLETHEME);
		mmLoadEffect(SFX_GAMEOVERTHEME);
	};

	/**
	 * Plays the barrier explosion sound.
	 */
	static void playBarrierExplode() {
		mmEffect(SFX_BARRIEREXPLODE);
	};

	/**
	 * Plays the barrier pushed sound.
	 */
	static void playBarrierPush() {
		mmEffect(SFX_BARRIERPUSH);
	};

	/**
	 * Plays the bean collection sound.
	 */
	static void playBeanCollect() {
		mmEffect(SFX_BEANCOLLECT);
	};

	/**
	 * Plays the block falling sound.
	 */
	static void playBlockFall() {
		mmEffect(SFX_BLOCKFALL);
	};

	/**
	 * Plays the block landing sound.
	 */
	static void playBlockLand() {
		mmEffect(SFX_BLOCKLAND);
	};

	/**
	 * Plays the boulder explosion sound.
	 */
	static void playBoulderExplode() {
		mmEffect(SFX_BOULDEREXPLODE);
	};

	/**
	 * Plays the bubble explosion sound.
	 */
	static void playBubbleExplode() {
		mmEffect(SFX_BUBBLEEXPLODE);
	};

	/**
	 * Plays the diamond collection sound.
	 */
	static void playDiamondCollect() {
		mmEffect(SFX_DIAMONDCOLLECT);
	};

	/**
	 * Plays the door opening sound.
	 */
	static void playDoorOpen() {
		mmEffect(SFX_DOOROPEN);
	};

	/**
	 * Plays the game over music.
	 */
	static void playGameOverTheme() {
		_gameOverHandle = mmEffect(SFX_GAMEOVERTHEME);
	};

	/**
	 * Stops the game over music.
	 */
	static void stopGameOverTheme() {
		mmEffectCancel(_gameOverHandle);
	};

	/**
	 * Plays the gravity inversion sound.
	 */
	static void playGravityInversion() {
		mmEffectCancel(_gravityHandle);
		_gravityHandle = mmEffect(SFX_GRAVITYINVERSION);
	};

	/**
	 * Plays the level complete sound.
	 */
	static void playLevelComplete() {
		mmEffect(SFX_LEVELCOMPLETE);
	};

	/**
	 * Plays the game paused sound.
	 */
	static void playPause() {
		mmEffect(SFX_PAUSE);
	};

	/**
	 * Plays the player explosion sound.
	 */
	static void playPlayerExplode() {
		mmEffect(SFX_PLAYEREXPLODE);
	};

	/**
	 * Plays the soil digging sound.
	 */
	static void playSoilDig() {
		mmEffect(SFX_SOILDIG);
	};

	/**
	 * Plays the teleport collection sound.
	 */
	static void playTeleportCollect() {
		mmEffect(SFX_TELEPORTCOLLECT);
	};

	/**
	 * Plays the time ticking sound.
	 */
	static void playTime() {
		mmEffect(SFX_TIME);
	};

	/**
	 * Plays the title music.
	 */
	static void playTitleTheme() {
		_titleHandle = mmEffect(SFX_TITLETHEME);
	};

	/**
	 * Stops the title music.
	 */
	static void stopTitleTheme() {
		mmEffectCancel(_titleHandle);
	};

	/**
	 * Shuts down all game sounds.
	 */
	static void shutdown() {
		mmUnloadEffect(SFX_BARRIEREXPLODE);
		mmUnloadEffect(SFX_BARRIERPUSH);
		mmUnloadEffect(SFX_BEANCOLLECT);
		mmUnloadEffect(SFX_BLOCKFALL);
		mmUnloadEffect(SFX_BLOCKLAND);
		mmUnloadEffect(SFX_BOULDEREXPLODE);
		mmUnloadEffect(SFX_BUBBLEEXPLODE);
		mmUnloadEffect(SFX_DIAMONDCOLLECT);
		mmUnloadEffect(SFX_DOOROPEN);
		mmUnloadEffect(SFX_GRAVITYINVERSION);
		mmUnloadEffect(SFX_LEVELCOMPLETE);
		mmUnloadEffect(SFX_PAUSE);
		mmUnloadEffect(SFX_PLAYEREXPLODE);
		mmUnloadEffect(SFX_SOILDIG);
		mmUnloadEffect(SFX_TELEPORTCOLLECT);
		mmUnloadEffect(SFX_TIME);
		mmUnloadEffect(SFX_TITLETHEME);
		mmUnloadEffect(SFX_GAMEOVERTHEME);
	};

private:
	static mm_sfxhand _titleHandle;		/**< Handle for the title music. */
	static mm_sfxhand _gravityHandle;	/**< Handle for the gravity inversion sound. */
	static mm_sfxhand _gameOverHandle;	/**< Handle for the game over music. */

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
