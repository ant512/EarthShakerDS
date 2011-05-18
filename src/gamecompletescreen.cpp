#include "gamecompletescreen.h"
#include "soundplayer.h"

GameCompleteScreen::GameCompleteScreen(WoopsiGfx::Graphics* topGfx, WoopsiGfx::Graphics* bottomGfx, s32 score) : ScreenBase(topGfx, bottomGfx) {
	_timer = 400;

	topGfx->drawFilledRect(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, COLOUR_BLACK);
	bottomGfx->drawFilledRect(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, COLOUR_BLACK);

	WoopsiGfx::WoopsiString str = "Game complete";
	topGfx->drawText((SCREEN_WIDTH - _font.getStringWidth(str)) / 2, 80, &_font, str, 0, str.getLength(), COLOUR_GREEN);

	str = "Congratulations";
	topGfx->drawText((SCREEN_WIDTH - _font.getStringWidth(str)) / 2, 96, &_font, str, 0, str.getLength(), COLOUR_RED);

	str = "You scored";
	topGfx->drawText(60, 112, &_font, str, 0, str.getLength(), COLOUR_CYAN);

	str.format("%06d", score);
	topGfx->drawText(148, 112, &_font, str, 0, str.getLength(), COLOUR_WHITE);

	SoundPlayer::playGameOverTheme();
}

void GameCompleteScreen::iterate() {
	--_timer;

	const PadState& pad = Hardware::getPadState();

	if (pad.a) {

		// Wait for A to be released so that it doesn't start a new game
		while (pad.a) {
			Hardware::waitForVBlank();
		}

		SoundPlayer::stopGameOverTheme();
		_timer = 0;
	}
}

bool GameCompleteScreen::isRunning() const {
	return _timer > 0;
}
