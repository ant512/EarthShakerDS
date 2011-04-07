#include "boulderdashscreen.h"
#include "diamondblock.h"
#include "boulderblock.h"
#include "soilblock.h"

using namespace WoopsiUI;

BoulderdashScreen::BoulderdashScreen() : AmigaScreen("Boulderdash", true, true) {

	s32 levelWidth = 4;
	s32 levelHeight = 4;
	u8 levelData[16] = {2,1,1,1,
					 	2,1,1,1,
					 	2,1,3,1,
					 	2,2,2,2};

	_level = createLevel(levelData, levelWidth, levelHeight);

	/*
	_level->setBlockAt(0, 0, new DiamondBlock());
	_level->setBlockAt(1, 0, new DiamondBlock());
	_level->setBlockAt(2, 0, new BoulderBlock());
	_level->setBlockAt(3, 0, new SoilBlock());
	_level->setBlockAt(4, 0, new SoilBlock());
	_level->setBlockAt(5, 0, new SoilBlock());
	_level->setBlockAt(6, 0, new SoilBlock());
	_level->setBlockAt(7, 0, new SoilBlock());
	_level->setBlockAt(8, 0, new SoilBlock());
	_level->setBlockAt(9, 0, new SoilBlock());

	_level->setBlockAt(0, 1, new DiamondBlock());
	_level->setBlockAt(1, 1, new DiamondBlock());
	_level->setBlockAt(2, 1, new SoilBlock());
	_level->setBlockAt(3, 1, new SoilBlock());
	_level->setBlockAt(4, 1, new BoulderBlock());
	_level->setBlockAt(5, 1, new BoulderBlock());
	_level->setBlockAt(6, 1, new SoilBlock());
	_level->setBlockAt(7, 1, new SoilBlock());
	_level->setBlockAt(8, 1, new BoulderBlock());
	_level->setBlockAt(9, 1, new SoilBlock());

	_level->setBlockAt(0, 2, new SoilBlock());
	_level->setBlockAt(1, 2, new SoilBlock());
	_level->setBlockAt(2, 2, new SoilBlock());
	_level->setBlockAt(3, 2, new SoilBlock());
	_level->setBlockAt(4, 2, new SoilBlock());
	_level->setBlockAt(5, 2, new SoilBlock());
	_level->setBlockAt(6, 2, new SoilBlock());
	_level->setBlockAt(7, 2, new SoilBlock());
	_level->setBlockAt(8, 2, new SoilBlock());
	_level->setBlockAt(9, 2, new SoilBlock());
	*/

	Rect rect;
	getClientRect(rect);

	_superBitmap = new SuperBitmap(rect.x, rect.y, rect.width, rect.height, rect.width, rect.height, true);
	addGadget(_superBitmap);

	Graphics* gfx = _superBitmap->getGraphics();
	_level->render(gfx);
	delete gfx;
}

BoulderdashScreen::~BoulderdashScreen() {
	delete _level;
}

LevelBase* BoulderdashScreen::createLevel(u8* data, s32 width, s32 height) {

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
