#ifndef _SOUND_PLAYER_H_
#define _SOUND_PLAYER_H_

#include <nds.h>
#include <maxmod9.h>

#include "soundbank.h"
#include "soundbank_bin.h"

class SoundPlayer {
public:
	static void test() {
		mmInitDefaultMem((mm_addr)soundbank_bin);
		mmLoadEffect(SFX_BOOM);

		mm_sound_effect boom = {
			{ SFX_BOOM } ,			// id
			(int)(1.0f * (1<<10)),	// rate
			0,		// handle
			255,	// volume
			255,	// panning
		};

		mmEffectEx(&boom);
	};

private:
	SoundPlayer();
	~SoundPlayer();
};

#endif
