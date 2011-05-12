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
		mmLoadEffect(SFX_BOOM);
	};

	static void test() {
		mmEffectEx(&_boom);
	};

	static void shutdown() {
		mmUnloadEffect(SFX_BOOM);
	};

private:
	static mm_sound_effect _boom;

	SoundPlayer();
	~SoundPlayer();
};

mm_sound_effect SoundPlayer::_boom = {
	{ SFX_BOOM } ,			// id
	(int)(1.0f * (1<<10)),	// rate
	0,		// handle
	255,	// volume
	255,	// panning
};

#endif
