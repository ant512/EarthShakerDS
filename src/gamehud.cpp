#include "gamehud.h"

GameHUD::GameHUD() {
	_topGfx = Hardware::getTopGfx();
	_bottomGfx = Hardware::getBottomGfx();
}

void GameHUD::drawTimerBar(s32 remainingTime) {

	// Rather than draw a bar representing the amount of time left to elapse,
	// we overwrite the existing graphics from right to left with a black rect.
	// This gives the illusion of shortening the remaining time bar with much
	// less effort.

	s32 barY = 178;
	s32 width = STARTING_TIME - remainingTime;
	s32 barX = SCREEN_WIDTH - width;

	// Draw new bar graphic
	_topGfx->drawFilledRect(barX, barY, width, 4, COLOUR_BLACK);
}

void GameHUD::drawTimerBarBackground() {
	s32 barY = 178;
	s32 barWidth = SCREEN_WIDTH / 8;
	s32 barHeight = 4;

	_topGfx->drawFilledRect(0, barY, SCREEN_WIDTH, barHeight, COLOUR_BLUE_DARK);
	_topGfx->drawFilledRect(barWidth, barY, SCREEN_WIDTH, barHeight, COLOUR_BLUE);
	_topGfx->drawFilledRect(barWidth * 2, barY, SCREEN_WIDTH, barHeight, COLOUR_RED);
	_topGfx->drawFilledRect(barWidth * 3, barY, SCREEN_WIDTH, barHeight, COLOUR_MAGENTA);
	_topGfx->drawFilledRect(barWidth * 4, barY, SCREEN_WIDTH, barHeight, COLOUR_GREEN);
	_topGfx->drawFilledRect(barWidth * 5, barY, SCREEN_WIDTH, barHeight, COLOUR_CYAN);
	_topGfx->drawFilledRect(barWidth * 6, barY, SCREEN_WIDTH, barHeight, COLOUR_YELLOW);
	_topGfx->drawFilledRect(barWidth * 7, barY, SCREEN_WIDTH, barHeight, COLOUR_WHITE);
}

void GameHUD::drawBackground(s32 totalDiamonds,
							 s32 collectedDiamonds,
							 s32 remainingGravityTime,
							 bool isGravityInverted,
							 s32 remainingLives,
							 s32 score,
							 const WoopsiGfx::WoopsiString& levelName,
							 s32 levelNumber) {

	// Wipe everything
	_topGfx->drawFilledRect(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, COLOUR_BLACK);
	_bottomGfx->drawFilledRect(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, COLOUR_BLACK);

	drawTimerBarBackground();

	// Logo
	_bottomGfx->drawBitmap(0, 0, 256, 64, &_logoBmp, 0, 0);

	// Copyrights
	WoopsiGfx::WoopsiString	str = "ZX (c) 1990 Michael Batty";
	_bottomGfx->drawText((SCREEN_WIDTH - _font.getStringWidth(str)) / 2, 160, &_font, str, 0, str.getLength(), COLOUR_WHITE);

	str.setText("DS (c) 2011 Antony Dzeryn");
	_bottomGfx->drawText((SCREEN_WIDTH - _font.getStringWidth(str)) / 2, 168, &_font, str, 0, str.getLength(), COLOUR_WHITE);

	// Level name
	str.setText(levelName);
	_bottomGfx->drawText((SCREEN_WIDTH - _font.getStringWidth(str)) / 2, (SCREEN_HEIGHT - _font.getHeight()) / 2, &_font,str, 0, str.getLength(), COLOUR_WHITE);

	// Erase region for counters
	s32 counterHeight = _font.getHeight();
	s32 counterY = SCREEN_HEIGHT - counterHeight - 1;

	_topGfx->drawFilledRect(0, counterY, SCREEN_WIDTH, counterHeight, COLOUR_BLACK);

	// Level display
	str.setText("L");

	// Here we abandon calculated text co-ordinates and hard-code everything
	// with magic numbers, because it's quicker for both the computer and the
	// programmer to execute
	_topGfx->drawText(0, counterY, &_font, str, 0, str.getLength(), COLOUR_GREEN);

	str.format("%02d", levelNumber);
	_topGfx->drawText(8, counterY, &_font, str, 0, str.getLength(), COLOUR_WHITE);

	// Diamond
	str.setText("*");
	_topGfx->drawText(32, counterY, &_font, str, 0, str.getLength(), COLOUR_CYAN);

	// Diamonds
	str.setText(":");
	_topGfx->drawText(56, counterY, &_font, str, 0, str.getLength(), COLOUR_CYAN);

	// Heart
	str.setText("+");
	_topGfx->drawText(88, counterY, &_font, str, 0, str.getLength(), COLOUR_RED);

	// Gravity
	str.setText("$");
	_topGfx->drawText(112, counterY, &_font, str, 0, str.getLength(), COLOUR_GREEN);

	// "SCORE:"
	str.setText("S");
	_topGfx->drawText(160, counterY, &_font, str, 0, str.getLength(), COLOUR_WHITE);

	str.setText("C");
	_topGfx->drawText(168, counterY, &_font, str, 0, str.getLength(), COLOUR_YELLOW);

	str.setText("O");
	_topGfx->drawText(176, counterY, &_font, str, 0, str.getLength(), COLOUR_CYAN);

	str.setText("R");
	_topGfx->drawText(184, counterY, &_font, str, 0, str.getLength(), COLOUR_GREEN);

	str.setText("E");
	_topGfx->drawText(192, counterY, &_font, str, 0, str.getLength(), COLOUR_MAGENTA);

	str.setText(":");
	_topGfx->drawText(200, counterY, &_font, str, 0, str.getLength(), COLOUR_RED);

	// Draw everything else
	drawDiamondCounters(totalDiamonds, collectedDiamonds);
	drawScore(score);
	drawLifeCounter(remainingLives);
	drawGravityCounter(remainingGravityTime);
	drawGravityIndicator(isGravityInverted);
}

void GameHUD::drawDiamondCounters(s32 total, s32 collected) {
	WoopsiGfx::WoopsiString str;

	// Erase region for counters
	s32 height = _font.getHeight();
	s32 y = SCREEN_HEIGHT - height - 1;

	str.format("%02d", total);
	_topGfx->drawFilledRect(40, y, 16, height, COLOUR_BLACK);
	_topGfx->drawText(40, y, &_font, str, 0, str.getLength(), COLOUR_WHITE);

	str.format("%02d", collected);
	_topGfx->drawFilledRect(64, y, 16, height, COLOUR_BLACK);
	_topGfx->drawText(64, y, &_font, str, 0, str.getLength(), COLOUR_WHITE);
}

void GameHUD::drawGravityCounter(s32 remainingTime) {
	WoopsiGfx::WoopsiString str;
	str.format("%02d", remainingTime);

	s32 width = _font.getStringWidth(str);
	s32 height = _font.getHeight();
	s32 x = 136;
	s32 y = SCREEN_HEIGHT - height - 1;

	_topGfx->drawFilledRect(x, y, width, height, COLOUR_BLACK);
	_topGfx->drawText(x, y, &_font, str, 0, str.getLength(), COLOUR_WHITE);
}

void GameHUD::drawGravityIndicator(bool isGravityInverted) {
	WoopsiGfx::WoopsiString str;
	str.setText(isGravityInverted ? "&" : "%");

	s32 width = _font.getStringWidth(str);
	s32 height = _font.getHeight();
	s32 x = 120;
	s32 y = SCREEN_HEIGHT - height - 1;

	_topGfx->drawFilledRect(x, y, width, height, COLOUR_BLACK);
	_topGfx->drawText(x, y, &_font, str, 0, str.getLength(), COLOUR_WHITE);
}

void GameHUD::drawLifeCounter(s32 remainingLives) {

	// Prevent lives less than 0 being printed
	s32 lives = remainingLives > -1 ? remainingLives : 0;

	WoopsiGfx::WoopsiString str;
	str.format("%01d", lives);

	s32 width = _font.getStringWidth(str);
	s32 height = _font.getHeight();
	s32 x = 96;
	s32 y = SCREEN_HEIGHT - height - 1;

	_topGfx->drawFilledRect(x, y, width, height, COLOUR_BLACK);
	_topGfx->drawText(x, y, &_font, str, 0, str.getLength(), COLOUR_WHITE);
}

void GameHUD::drawScore(s32 score) {
	WoopsiGfx::WoopsiString str;
	str.format("%06d", score);

	s32 scoreWidth = _font.getStringWidth(str);
	s32 scoreHeight = _font.getHeight();
	s32 scoreX = SCREEN_WIDTH - scoreWidth;
	s32 scoreY = SCREEN_HEIGHT - scoreHeight - 1;

	_topGfx->drawFilledRect(scoreX, scoreY, scoreWidth, scoreHeight, COLOUR_BLACK);
	_topGfx->drawText(scoreX, scoreY, &_font, str, 0, str.getLength(), woopsiRGB(31, 31, 31));
}
