#include <woopsistring.h>

#include "game.h"
#include "diamondblock.h"
#include "boulderblock.h"
#include "soilblock.h"
#include "bubbleblock.h"
#include "wallblock.h"
#include "fireblock.h"
#include "beanblock.h"
#include "constants.h"
#include "bitmapserver.h"

Game::Game(WoopsiGfx::Graphics* topGfx, WoopsiGfx::Graphics* bottomGfx) {
	_score = 0;
	_lives = STARTING_LIVES;
	_topGfx = topGfx;
	_bottomGfx = bottomGfx;

	_upHeld = false;
	_downHeld = false;
	_leftHeld = false;
	_rightHeld = false;

	s32 levelWidth = 32;
	s32 levelHeight = 16;
	u8 levelData[512] = {6,6,6,2,1,1,1,1,1,1,1,1,1,1,1,1,2,1,1,2,1,1,1,1,1,1,1,1,1,1,1,1,
						6,1,6,1,2,1,1,1,1,1,1,1,1,2,3,1,2,1,1,1,2,1,8,1,1,1,1,1,1,2,3,1,
						6,1,3,1,2,1,5,1,1,1,1,1,1,1,2,1,2,1,3,1,2,1,5,1,1,1,1,1,1,1,2,1,
						2,2,2,2,1,1,1,1,1,1,1,1,1,1,1,1,2,2,2,2,1,1,1,1,1,1,1,1,1,1,1,1,
						1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
						1,1,1,1,1,1,1,1,1,1,1,1,4,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
						6,1,8,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
						6,6,6,6,6,1,3,1,1,1,1,1,1,1,1,1,1,1,1,8,1,1,1,1,1,1,1,1,1,1,1,1,
						6,6,6,2,1,1,3,3,1,1,1,1,1,1,1,1,2,1,1,2,1,1,1,1,1,1,1,1,1,8,1,1,
						6,1,6,1,2,3,3,3,1,1,1,1,1,2,3,1,2,1,1,1,2,1,1,1,1,1,1,1,1,2,3,1,
						6,1,3,1,2,1,5,1,1,1,1,1,1,1,2,1,2,1,3,1,2,1,5,1,1,1,1,1,1,1,2,1,
						2,2,2,2,1,1,1,1,1,1,1,1,1,1,1,1,2,2,2,2,1,1,1,1,1,1,1,1,1,1,1,1,
						1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
						1,1,1,1,1,1,1,1,1,1,1,1,6,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
						6,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
						6,6,6,6,6,1,1,1,1,1,1,1,1,1,1,7,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};

	_level = createLevel(levelData, levelWidth, levelHeight, 1, "Testing Ground");

	drawHUD();
	drawDiamondCounters();
	drawScore();
	drawLifeCounter();
}

Game::~Game() {
	delete _level;
	delete _playerBlock;
}

s32 Game::getScore() const {
	return _score;
}

s32 Game::getRemainingTime() const {
	return _remainingTime;
}

LevelBase* Game::getLevel() const {
	return _level;
}

void Game::addScore(s32 score) {
	_score += score;
	drawScore();
}

void Game::drawScore() {
	WoopsiGfx::WoopsiString str;
	str.format("%06d", _score);

	s32 scoreWidth = _font.getStringWidth(str);
	s32 scoreHeight = _font.getHeight();
	s32 scoreX = SCREEN_WIDTH - scoreWidth;
	s32 scoreY = SCREEN_HEIGHT - scoreHeight - 1;

	_topGfx->drawFilledRect(scoreX, scoreY, scoreWidth, scoreHeight, COLOUR_BLACK);
	_topGfx->drawText(scoreX, scoreY, &_font, str, 0, str.getLength(), woopsiRGB(31, 31, 31));

	// TODO: Life printing should be in another function
	str.format("Lives: %02d", _lives);
	_bottomGfx->drawFilledRect(0, _font.getHeight(), _font.getStringWidth(str), _font.getHeight(), woopsiRGB(0, 0, 0));
	_bottomGfx->drawText(0, _font.getHeight(), &_font, str, 0, str.getLength(), woopsiRGB(31, 31, 31));

	// TODO: Level printing should be in another function
	str.format("Level: %02d", _level->getLevelNumber());
	_bottomGfx->drawFilledRect(0, _font.getHeight() * 2, _font.getStringWidth(str), _font.getHeight(), woopsiRGB(0, 0, 0));
	_bottomGfx->drawText(0, _font.getHeight() * 2, &_font, str, 0, str.getLength(), woopsiRGB(31, 31, 31));
}

void Game::drawLifeCounter() {
	WoopsiGfx::WoopsiString str;
	str.format("%01d", _lives);

	s32 width = _font.getStringWidth(str);
	s32 height = _font.getHeight();
	s32 x = 104;
	s32 y = SCREEN_HEIGHT - height - 1;

	_topGfx->drawFilledRect(x, y, width, height, COLOUR_BLACK);
	_topGfx->drawText(x, y, &_font, str, 0, str.getLength(), COLOUR_WHITE);
}

PlayerBlock* Game::getPlayerBlock() const {
	return _playerBlock;
}

void Game::render() {

	// Get the size of the display measured in blocks
	s32 displayWidth = GAME_WIDTH / BlockBase::BLOCK_SIZE;
	s32 displayHeight = GAME_HEIGHT / BlockBase::BLOCK_SIZE;

	// The centre of the display should be the player, unless the player is too
	// close to an edge for the display to scroll.  In that situation, we keep
	// the edge of the map at the edge of the display and move the player
	// around instead.  Assume for the moment that the player is at the centre
	// of the screen
	s32 centreX = _playerBlock->getX();
	s32 centreY = _playerBlock->getY();

	// Get the top-left corner based on the assumption that the player is at the
	// centre of the screen
	s32 x = centreX - (displayWidth / 2);
	s32 y = centreY - (displayHeight / 2);

	// Prevent scrolling past the end of the level.  This accounts for the
	// situation in which the player is not the centre of the screen
	if (x + displayWidth > _level->getWidth()) x = _level->getWidth() - displayWidth;
	if (x < 0) x = 0;

	if (y + displayHeight > _level->getHeight()) y = _level->getHeight() - displayHeight;
	if (y < 0) y = 0;

	_level->render(x, y, displayWidth, displayHeight, _topGfx);
}


void Game::iterate() {
	animate();
	move();
	timer();
}

void Game::timer() {
	_levelTimer++;

	if (_levelTimer == TIMER_TIME) {
		_levelTimer = 0;

		decreaseTime();
	}
}

void Game::animate() {
	_animationTimer++;

	if (_animationTimer == ANIMATION_TIME) {
		_animationTimer = 0;

		render();
	}
}

void Game::move() {
	_movementTimer++;

	if (_movementTimer == MOVEMENT_TIME) {
		_movementTimer = 0;

		_level->iterate(_remainingGravityTime > 0);

		if (_remainingGravityTime > 0) --_remainingGravityTime;

		if (_upHeld) {
			_playerBlock->pushUp();
		} else if (_downHeld) {
			_playerBlock->pushDown();
		} else if (_leftHeld) {
			_playerBlock->pushLeft();
		} else if (_rightHeld) {
			_playerBlock->pushRight();
		}
	}
}

void Game::setUpHeld(bool upHeld) {
	_upHeld = upHeld;
}

void Game::setDownHeld(bool downHeld) {
	_downHeld = downHeld;
}

void Game::setLeftHeld(bool leftHeld) {
	_leftHeld = leftHeld;
}

void Game::setRightHeld(bool rightHeld) {
	_rightHeld = rightHeld;
}

bool Game::isGravityInverted() const {
	return _remainingGravityTime > 0;
}

void Game::increaseCollectedDiamonds() {
	++_collectedDiamonds;

	drawDiamondCounters();
}

void Game::drawDiamondCounters() {
	WoopsiGfx::WoopsiString str;

	// Erase region for counters
	s32 height = _font.getHeight();
	s32 y = SCREEN_HEIGHT - height - 1;

	str.format("%02d", _totalDiamonds);
	_topGfx->drawFilledRect(48, y, 16, height, COLOUR_BLACK);
	_topGfx->drawText(48, y, &_font, str, 0, str.getLength(), COLOUR_WHITE);

	str.format("%02d", _collectedDiamonds);
	_topGfx->drawFilledRect(72, y, 16, height, COLOUR_BLACK);
	_topGfx->drawText(72, y, &_font, str, 0, str.getLength(), COLOUR_WHITE);
}

void Game::decreaseTime() {
	--_remainingTime;

	drawTimerBar();
}


void Game::drawHUD() {

	// Timer bar initial state
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

	// Level name
	s32 nameWidth = _font.getStringWidth(_level->getName());
	s32 nameHeight = _font.getHeight();
	s32 nameX = (SCREEN_WIDTH - nameWidth) / 2;
	s32 nameY = (SCREEN_HEIGHT - nameHeight) / 2;

	// Erase region under name
	_bottomGfx->drawFilledRect(0, nameY, SCREEN_WIDTH, nameHeight, COLOUR_BLACK);

	// Draw name
	_bottomGfx->drawText(nameX, nameY, &_font, _level->getName(), 0, _level->getName().getLength(), COLOUR_WHITE);

	// Erase region for counters
	s32 counterHeight = _font.getHeight();
	s32 counterX = 0;
	s32 counterY = SCREEN_HEIGHT - counterHeight - 1;

	_topGfx->drawFilledRect(counterX, counterY, SCREEN_WIDTH, counterHeight, COLOUR_BLACK);

	// Level display
	WoopsiGfx::WoopsiString str("L");

	// Here we abandon calculated text co-ordinates and hard-code everything
	// with magic numbers, because it's quicker for both the computer and the
	// programmer to execute
	_topGfx->drawText(0, counterY, &_font, str, 0, str.getLength(), COLOUR_GREEN);

	str.format("%02d", _level->getLevelNumber());
	_topGfx->drawText(8, counterY, &_font, str, 0, str.getLength(), COLOUR_WHITE);

	// TODO: Draw a diamond here

	// Diamonds
	str.setText(":");
	_topGfx->drawText(64, counterY, &_font, str, 0, str.getLength(), COLOUR_CYAN);

	// TODO: Heart here

	// TODO: Gravity g here (indicator needs to be drawn elsewhere)

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
}

void Game::drawTimerBar() {

	// Rather than draw a bar representing the amount of time left to elapse,
	// we overwrite the existing graphics from right to left with a black rect.
	// This gives the illusion of shortening the remaining time bar with much
	// less effort.

	s32 barY = 178;
	s32 width = STARTING_TIME - _remainingTime;

	// Draw new bar graphic
	_topGfx->drawFilledRect(SCREEN_WIDTH - width, barY, width, 4, COLOUR_BLACK);
}

void Game::invertGravity() {
	_remainingGravityTime = GRAVITY_INVERSION_TIME;
}

LevelBase* Game::createLevel(u8* data, s32 width, s32 height, s32 number, const WoopsiGfx::WoopsiString& name) {
	_collectedDiamonds = 0;
	_totalDiamonds = 0;
	_remainingTime = STARTING_TIME;
	_remainingGravityTime = 0;

	_animationTimer = 0;
	_movementTimer = 0;
	_levelTimer = 0;

	BitmapServer::init();

	LevelBase* level = new LevelBase(width, height, number, name);

	BlockBase* block = NULL;

	for (s32 x = 0; x < width; ++x) {
		for (s32 y = 0; y < height; ++y) {

			switch (data[(y * width) + x]) {
				case 0:
					block = NULL;
					break;
				case 1:
					block = new SoilBlock(x, y, this);
					break;
				case 2:
					block = new BoulderBlock(x, y, this);
					break;
				case 3:
					block = new DiamondBlock(x, y, this);
					_totalDiamonds++;
					break;
				case 4:
					block = new PlayerBlock(x, y, this);
					_playerBlock = (PlayerBlock*)block;
					break;
				case 5:
					block = new BubbleBlock(x, y, this);
					break;
				case 6:
					block = new WallBlock(x, y, this);
					break;
				case 7:
					block = new FireBlock(x, y, this);
					break;
				case 8:
					block = new BeanBlock(x, y, this);
					break;
			}

			level->setBlockAt(x, y, block);
		}
	}

	return level;
}
