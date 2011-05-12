#include "soundplayer.h"

mm_sound_effect SoundPlayer::_time = {
	{ SFX_TIME } ,			// id
	(int)(1.0f * (1<<10)),	// rate
	0,		// handle
	255,	// volume
	255,	// panning
};

mm_sound_effect SoundPlayer::_soilDig = {
	{ SFX_SOILDIG } ,			// id
	(int)(1.0f * (1<<10)),	// rate
	0,		// handle
	255,	// volume
	255,	// panning
};
