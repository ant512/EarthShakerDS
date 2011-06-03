#include "soundplayer.h"

#ifndef USING_SDL

mm_sfxhand SoundPlayer::_titleHandle;
mm_sfxhand SoundPlayer::_gravityHandle;
mm_sfxhand SoundPlayer::_gameOverHandle;
mm_sfxhand SoundPlayer::_mapHandle;

#else

Mix_Chunk* SoundPlayer::_sounds[SOUND_TYPE_COUNT];

#endif
