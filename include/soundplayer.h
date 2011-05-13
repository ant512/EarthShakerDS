#ifndef _SOUND_PLAYER_H_
#define _SOUND_PLAYER_H_

#include <nds.h>
#include <maxmod9.h>

#include "soundbank.h"
#include "soundbank_bin.h"

class SoundPlayer {
public:
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
	};

	static void playBarrierExplode() {
		mmEffect(SFX_BARRIEREXPLODE);
	};

	static void playBarrierPush() {
		mmEffect(SFX_BARRIERPUSH);
	};

	static void playBeanCollect() {
		mmEffect(SFX_BEANCOLLECT);
	};

	static void playBlockFall() {
		mmEffect(SFX_BLOCKFALL);
	};

	static void playBlockLand() {
		mmEffect(SFX_BLOCKLAND);
	};

	static void playBoulderExplode() {
		mmEffect(SFX_BOULDEREXPLODE);
	};

	static void playBubbleExplode() {
		mmEffect(SFX_BUBBLEEXPLODE);
	};

	static void playDiamondCollect() {
		mmEffect(SFX_DIAMONDCOLLECT);
	};

	static void playDoorOpen() {
		mmEffect(SFX_DOOROPEN);
	};

	static void playGravityInversion() {
		mmEffect(SFX_GRAVITYINVERSION);
	};

	static void playLevelComplete() {
		mmEffect(SFX_LEVELCOMPLETE);
	};

	static void playPause() {
		mmEffect(SFX_PAUSE);
	};

	static void playPlayerExplode() {
		mmEffect(SFX_PLAYEREXPLODE);
	};

	static void playSoilDig() {
		mmEffect(SFX_SOILDIG);
	};

	static void playTeleportCollect() {
		mmEffect(SFX_TELEPORTCOLLECT);
	};

	static void playTime() {
		mmEffect(SFX_TIME);
	};

	static void playTitleTheme() {
		_titleHandle = mmEffect(SFX_TITLETHEME);
	};

	static void stopTitleTheme() {
		mmEffectCancel(_titleHandle);
	};

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
	};

private:
	static mm_sfxhand _titleHandle;

	SoundPlayer();
	~SoundPlayer();
};

#endif
