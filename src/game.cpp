#include "game.h"
#include "diamondblock.h"
#include "boulderblock.h"
#include "soilblock.h"

using namespace WoopsiUI;

Game::Game() {

	s32 levelWidth = 8;
	s32 levelHeight = 8;
	u8 levelData[64] = {2,1,1,2,1,1,1,1,
					 	2,1,1,0,2,0,0,0,
					 	2,1,3,0,2,0,0,0,
					 	2,2,2,2,0,0,0,1,
					 	1,0,0,0,0,0,1,1,
					 	1,1,0,1,0,1,1,1,
					 	1,1,0,1,1,1,1,1,
					 	1,1,1,1,1,1,1,1};

	_level = createLevel(levelData, levelWidth, levelHeight);
}

Game::~Game() {
	delete _level;
}

void Game::render(Graphics* gfx) {
	_level->render(gfx);
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
					block = new SoilBlock();
					break;
				case 2:
					block = new BoulderBlock();
					break;
				case 3:
					block = new DiamondBlock();
					break;
			}

			level->setBlockAt(x, y, block);
		}
	}

	return level;
}