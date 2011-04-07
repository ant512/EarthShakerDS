#include "game.h"
#include "diamondblock.h"
#include "boulderblock.h"
#include "soilblock.h"

using namespace WoopsiUI;

Game::Game() {

	s32 levelWidth = 4;
	s32 levelHeight = 4;
	u8 levelData[16] = {2,1,1,1,
					 	2,1,1,1,
					 	2,1,3,1,
					 	2,2,2,2};

	_level = createLevel(levelData, levelWidth, levelHeight);
}

Game::~Game() {
	delete _level;
}

void Game::render(Graphics* gfx) {
	_level->render(gfx);
}

LevelBase* Game::createLevel(u8* data, s32 width, s32 height) {

	LevelBase* level = new LevelBase(width, height);

	BlockBase* block = NULL;

	for (s32 x = 0; x < width; ++x) {
		for (s32 y = 0; y < height; ++y) {

			switch (data[(y * width) + x]) {
				case 0:
					// Empty
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
