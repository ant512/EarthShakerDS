#ifndef _GAME_COMPLETE_SCREEN_H_
#define _GAME_COMPLETE_SCREEN_H_

#include <nds.h>
#include <graphics.h>
#include <woopsistring.h>

#include "gamefont.h"
#include "screenbase.h"
#include "spectrumcolours.h"

class GameCompleteScreen : public ScreenBase {
public:
	GameCompleteScreen(WoopsiGfx::Graphics* topGfx, WoopsiGfx::Graphics* bottomGfx, s32 score);

	~GameCompleteScreen() {};

	void iterate(PadState pad);

	bool isRunning() const;

private:;
	s32 _timer;
	GameFont _font;
};

#endif
