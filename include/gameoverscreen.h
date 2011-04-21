#ifndef _GAME_OVER_SCREEN_H_
#define _GAME_OVER_SCREEN_H_

#include <nds.h>
#include <graphics.h>
#include <woopsistring.h>

#include "gamefont.h"
#include "screenbase.h"
#include "spectrumcolours.h"

class GameOverScreen : public ScreenBase {
public:
	GameOverScreen(WoopsiGfx::Graphics* topGfx, WoopsiGfx::Graphics* bottomGfx, s32 score, s32 level);

	~GameOverScreen() {};

	void iterate(PadState pad);

	bool isRunning() const;

private:;
	s32 _timer;
	GameFont _font;
};

#endif
