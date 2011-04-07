#include "boulderdashscreen.h"
#include "diamondblock.h"
#include "boulderblock.h"

using namespace WoopsiUI;

BoulderdashScreen::BoulderdashScreen() : AmigaScreen("Boulderdash", true, true) {

	_level = new LevelBase(10, 10);
	_level->setBlockAt(0, 0, new DiamondBlock());
	_level->setBlockAt(1, 1, new DiamondBlock());
	_level->setBlockAt(3, 0, new BoulderBlock());

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
