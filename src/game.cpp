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

Game::Game(WoopsiGfx::Graphics* topGfx, WoopsiGfx::Graphics* bottomGfx) {
	_isGravityInverted = false;
	_score = 0;
	_remainingTime = STARTING_TIME;
	_lives = STARTING_LIVES;
	_topGfx = topGfx;
	_bottomGfx = bottomGfx;
	_animationTimer = 0;
	_movementTimer = 0;

	_upHeld = false;
	_downHeld = false;
	_leftHeld = false;
	_rightHeld = false;

	// Ensure that the score display is drawn
	addScore(0);

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

	_level = createLevel(levelData, levelWidth, levelHeight, 1, "Test Level");
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

	// TODO: Fix the quick and dirty score display
	WoopsiGfx::WoopsiString str;
	str.format("Score: %06d", _score);
	_bottomGfx->drawFilledRect(0, 0, _font.getStringWidth(str), _font.getHeight(), woopsiRGB(0, 0, 0));
	_bottomGfx->drawText(0, 0, &_font, str, 0, str.getLength(), woopsiRGB(31, 31, 31));

	// TODO: Life printing should be in another function
	str.format("Lives: %02d", _lives);
	_bottomGfx->drawFilledRect(0, _font.getHeight(), _font.getStringWidth(str), _font.getHeight(), woopsiRGB(0, 0, 0));
	_bottomGfx->drawText(0, _font.getHeight(), &_font, str, 0, str.getLength(), woopsiRGB(31, 31, 31));

	// TODO: Level printing should be in another function
	str.format("Level: %02d:", _level->getLevelNumber());
	_bottomGfx->drawFilledRect(0, _font.getHeight() * 2, _font.getStringWidth(str), _font.getHeight(), woopsiRGB(0, 0, 0));
	_bottomGfx->drawText(0, _font.getHeight() * 2, &_font, str, 0, str.getLength(), woopsiRGB(31, 31, 31));
}

PlayerBlock* Game::getPlayerBlock() const {
	return _playerBlock;
}

void Game::render() {

	// Get the size of the display measured in blocks
	s32 displayWidth = DISPLAY_WIDTH / BlockBase::BLOCK_SIZE;
	s32 displayHeight = DISPLAY_HEIGHT / BlockBase::BLOCK_SIZE;

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

		_level->iterate(_isGravityInverted);
		decreaseTime();

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
	return _isGravityInverted;
}

void Game::decreaseTime() {
	_remainingTime -= TIME_DECREMENT;

	drawTimerBar();
}

void Game::drawTimerBar() {

	// Calculate the percentage of time that has elapsed so far
	s32 percentage = (_remainingTime * 100) / STARTING_TIME;

	// Calculate the width of the timer bar - it shows the remaining percentage
	// of time
	s32 maxWidth = DISPLAY_WIDTH - 40;
	s32 width = maxWidth * percentage / 100;

	s32 green = 0;
	s32 red = 0;

	// Green is initially at 31 (max) and stays there until the percentage hits
	// 50.  At that point, green decreases to 0.  At the same time, red starts
	// at 0 (min) and increases to 31 until the percentage hits 50.  At that
	// point, red stays at 31.  This makes the bar cycle from green to yellow to
	// red.
	if (percentage >= 50) {
		green = 31;
		red = (31 - (31 * percentage / 100)) * 2;
	} else {
		red = 31;
		green = (31 * percentage / 100) * 2;
	}

	if (red > 31) red = 31;
	if (green > 31) green = 31;

	// Erase previous bar graphic - we need to erase as the bar will have become
	// shorter, so at least a portion of the previous bar won't be drawn.  We
	// could optimise by calculating the difference and drawing that, but the
	// speed at which rects are drawn (thanks to the DMA) makes the optimisation
	// moot.
	_bottomGfx->drawFilledRect(20, 50, maxWidth, 10, woopsiRGB(0, 0, 0));

	// Draw new bar graphic
	_bottomGfx->drawFilledRect(20, 50, width, 10, woopsiRGB(red, green, 0));
}

void Game::flipGravity() {
	_isGravityInverted = !_isGravityInverted;
}

LevelBase* Game::createLevel(u8* data, s32 width, s32 height, s32 number, const WoopsiGfx::WoopsiString& name) {

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
