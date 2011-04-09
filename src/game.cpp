#include "game.h"
#include "diamondblock.h"
#include "boulderblock.h"
#include "soilblock.h"
#include "bubbleblock.h"
#include "wallblock.h"

using namespace WoopsiUI;

Game::Game() {

	s32 levelWidth = 32;
	s32 levelHeight = 8;
	u8 levelData[256] = {6,6,6,2,1,1,1,1,1,1,1,1,1,1,1,1,2,1,1,2,1,1,1,1,1,1,1,1,1,1,1,1,
						6,1,6,1,2,1,1,1,1,1,1,1,1,2,3,1,2,1,1,1,2,1,1,1,1,1,1,1,1,2,3,1,
						6,1,3,1,2,1,5,1,1,1,1,1,1,1,2,1,2,1,3,1,2,1,5,1,1,1,1,1,1,1,2,1,
						2,2,2,2,1,1,1,1,1,1,1,1,1,1,1,1,2,2,2,2,1,1,1,1,1,1,1,1,1,1,1,1,
						1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
						1,1,1,1,1,1,1,1,1,1,1,1,4,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
						6,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
						6,6,6,6,6,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};

	_level = createLevel(levelData, levelWidth, levelHeight);
}

Game::~Game() {
	delete _level;
	delete _playerBlock;
}

LevelBase* Game::getLevel() const {
	return _level;
}

PlayerBlock* Game::getPlayerBlock() const {
	return _playerBlock;
}

void Game::render(Graphics* gfx) {

	// TODO: Remove magic numbers
	s32 blockSize = 16;
	s32 displayWidth = 256 / blockSize;
	s32 displayHeight = 192 / blockSize;

	s32 centreX = _playerBlock->getX();
	s32 centreY = _playerBlock->getY();

	s32 x = centreX - (displayWidth / 2);
	s32 y = centreY - (displayHeight / 2);

	if (x + displayWidth > _level->getWidth()) x = _level->getWidth() - displayWidth;
	if (x < 0) x = 0;

	if (y + displayHeight > _level->getHeight()) y = _level->getHeight() - displayHeight;
	if (y < 0) y = 0;

	_level->render(x, y, displayWidth, displayHeight, gfx);
}

bool Game::iterate() {
	return _level->iterate();
}

LevelBase* Game::createLevel(u8* data, s32 width, s32 height) {

	LevelBase* level = new LevelBase(width, height);

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
			}

			level->setBlockAt(x, y, block);
		}
	}

	return level;
}
