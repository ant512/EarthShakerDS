#include "game.h"
#include "diamondblock.h"
#include "boulderblock.h"
#include "soilblock.h"
#include "bubbleblock.h"

using namespace WoopsiUI;

Game::Game() {

	s32 levelWidth = 16;
	s32 levelHeight = 8;
	u8 levelData[128] = {2,1,1,2,1,1,1,1,1,1,1,1,1,1,1,1,
						2,1,1,0,2,0,0,0,0,0,1,1,0,2,3,0,
						2,1,3,0,2,0,5,0,0,1,1,1,0,0,2,0,
						2,2,2,2,0,0,0,1,0,1,0,1,0,0,0,1,
						1,0,0,0,0,0,1,1,0,0,0,1,0,0,0,1,
						1,1,0,1,0,1,1,1,0,0,0,0,4,0,0,1,
						1,1,0,1,1,1,1,1,0,0,0,0,0,0,0,1,
						1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};

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
	_level->render(gfx);
}

bool Game::iterate() {
	return _level->iterate();
}

LevelBase* Game::createLevel(u8* data, s32 width, s32 height) {

	LevelBase* level = new LevelBase(width, height);

	MapItemBase* block = NULL;

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
			}

			level->setBlockAt(x, y, block);
		}
	}

	return level;
}
