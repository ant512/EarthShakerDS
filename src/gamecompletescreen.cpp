#include "gamecompletescreen.h"

GameCompleteScreen::GameCompleteScreen(WoopsiGfx::Graphics* topGfx, WoopsiGfx::Graphics* bottomGfx, s32 score) : ScreenBase(topGfx, bottomGfx) {
	_timer = 200;

	topGfx->drawFilledRect(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, COLOUR_BLACK);
	bottomGfx->drawFilledRect(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, COLOUR_BLACK);

	WoopsiGfx::WoopsiString str = "Well done! Game complete!";
	topGfx->drawText(92, 80, &_font, str, 0, str.getLength(), COLOUR_GREEN);

	str = "You scored";
	topGfx->drawText(60, 96, &_font, str, 0, str.getLength(), COLOUR_CYAN);

	str.format("%06d", score);
	topGfx->drawText(148, 96, &_font, str, 0, str.getLength(), COLOUR_WHITE);
}

void GameCompleteScreen::iterate(PadState pad) {
	--_timer;
}

bool GameCompleteScreen::isRunning() const {
	return _timer > 0;
}
