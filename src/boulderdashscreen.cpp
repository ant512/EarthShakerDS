#include "boulderdashscreen.h"
#include "diamondblock.h"
#include "boulderblock.h"
#include "soilblock.h"

using namespace WoopsiUI;

BoulderdashScreen::BoulderdashScreen() : AmigaScreen("Boulderdash", true, true) {

	_level = new LevelBase(10, 10);
	_level->setBlockAt(0, 0, new DiamondBlock());
	_level->setBlockAt(1, 0, new DiamondBlock());
	_level->setBlockAt(2, 0, new BoulderBlock());
	_level->setBlockAt(4, 0, new SoilBlock());
	_level->setBlockAt(5, 0, new SoilBlock());
	_level->setBlockAt(6, 0, new SoilBlock());
	_level->setBlockAt(7, 0, new SoilBlock());
	_level->setBlockAt(8, 0, new SoilBlock());
	_level->setBlockAt(9, 0, new SoilBlock());

	_level->setBlockAt(0, 1, new DiamondBlock());
	_level->setBlockAt(1, 1, new DiamondBlock());
	_level->setBlockAt(2, 1, new SoilBlock());
	_level->setBlockAt(4, 1, new BoulderBlock());
	_level->setBlockAt(5, 1, new BoulderBlock());
	_level->setBlockAt(6, 1, new SoilBlock());
	_level->setBlockAt(7, 1, new SoilBlock());
	_level->setBlockAt(8, 1, new BoulderBlock());
	_level->setBlockAt(9, 1, new SoilBlock());

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
