#ifndef _GAME_OVER_SCREEN_H_
#define _GAME_OVER_SCREEN_H_

#include <nds.h>
#include <graphics.h>
#include <woopsistring.h>

#include "screenbase.h"
#include "spectrumcolours.h"

class GameOverScreen : public ScreenBase {
public:
	GameOverScreen(WoopsiGfx::Graphics* topGfx, WoopsiGfx::Graphics* bottomGfx, s32 score, s32 lives) : ScreenBase(topGfx, bottomGfx) {
		_score = score;
		_lives = lives;
		_timer = 200;

		topGfx->drawFilledRect(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, COLOUR_BLACK);
		bottomGfx->drawFilledRect(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, COLOUR_BLACK);

		WoopsiGfx::WoopsiString str;
		str.format("Lives: %02d", lives);

		topGfx->drawText(0, 0, &_font, str, 0, str.getLength(), COLOUR_WHITE);
	};

	~GameOverScreen() {};

	void iterate() {
		--_timer;
	};

	bool isRunning() const {
		return _timer > 0;
	};

private:
	WoopsiGfx::Graphics* _topGfx;
	WoopsiGfx::Graphics* _bottomGfx;
	s32 _score;
	s32 _lives;
	s32 _timer;
	GameFont _font;
};

#endif
