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
		mmLoadEffect(SFX_SOILDIG);
		mmLoadEffect(SFX_TIME);
	};

	static void playTime() {
		mmEffectEx(&_time);
	};

	static void playSoilDig() {
		mmEffectEx(&_soilDig);
	};

	static void shutdown() {
		mmUnloadEffect(SFX_TIME);
		mmUnloadEffect(SFX_SOILDIG);
	};

private:
	static mm_sound_effect _time;
	static mm_sound_effect _soilDig;

	SoundPlayer();
	~SoundPlayer();
};

#endif
