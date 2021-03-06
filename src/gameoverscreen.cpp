#include "gameoverscreen.h"
#include "soundplayer.h"

GameOverScreen::GameOverScreen(WoopsiGfx::Graphics* topGfx, WoopsiGfx::Graphics* bottomGfx, s32 score, s32 level) : ScreenBase(topGfx, bottomGfx) {
	_timer = 200;

	topGfx->drawFilledRect(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, COLOUR_BLACK);
	bottomGfx->drawFilledRect(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, COLOUR_BLACK);

	WoopsiGfx::WoopsiString str = "Game Over";
	topGfx->drawText(92, 80, &_font, str, 0, str.getLength(), COLOUR_GREEN);

	str = "You scored";
	topGfx->drawText(60, 96, &_font, str, 0, str.getLength(), COLOUR_CYAN);

	str.format("%06d", score);
	topGfx->drawText(148, 96, &_font, str, 0, str.getLength(), COLOUR_WHITE);

	str = "And reached level";
	topGfx->drawText(54, 110, &_font, str, 0, str.getLength(), COLOUR_CYAN);

	str.format("%02d", level);
	topGfx->drawText(196, 110, &_font, str, 0, str.getLength(), COLOUR_WHITE);

	SoundPlayer::playGameOverTheme();
}

void GameOverScreen::iterate() {
	--_timer;

	const Pad& pad = Hardware::getPad();

	if (pad.isANewPress()) {

		// Wait for A to be released so that it doesn't start a new game
		while (pad.isAHeld()) {
			Hardware::waitForVBlank();
		}

		SoundPlayer::stopGameOverTheme();
		_timer = 0;
	}
}

bool GameOverScreen::isRunning() const {
	return _timer > 0;
}
