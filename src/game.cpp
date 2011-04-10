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
	_levelTime = 100;
	_topGfx = topGfx;
	_bottomGfx = bottomGfx;

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

s32 Game::getLevelTime() const {
	return _levelTime;
}

LevelBase* Game::getLevel() const {
	return _level;
}

void Game::addScore(s32 score) {
	_score += score;
}

PlayerBlock* Game::getPlayerBlock() const {
	return _playerBlock;
}

void Game::render() {

	s32 displayWidth = DISPLAY_WIDTH / BlockBase::BLOCK_SIZE;
	s32 displayHeight = DISPLAY_HEIGHT / BlockBase::BLOCK_SIZE;

	s32 centreX = _playerBlock->getX();
	s32 centreY = _playerBlock->getY();

	s32 x = centreX - (displayWidth / 2);
	s32 y = centreY - (displayHeight / 2);

	if (x + displayWidth > _level->getWidth()) x = _level->getWidth() - displayWidth;
	if (x < 0) x = 0;

	if (y + displayHeight > _level->getHeight()) y = _level->getHeight() - displayHeight;
	if (y < 0) y = 0;

	_level->render(x, y, displayWidth, displayHeight, _topGfx);
}

void Game::iterate() {
	_level->iterate(_isGravityInverted);
}

bool Game::isGravityInverted() const {
	return _isGravityInverted;
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
