#include "boulderdashscreen.h"

using namespace WoopsiUI;

BoulderdashScreen::BoulderdashScreen() : AmigaScreen("Boulderdash", true, true) {
	Bitmap* bmp = new Bitmap(16, 16);

	Graphics* gfx = bmp->newGraphics();
	gfx->drawFilledRect(0, 0, 8, 8, woopsiRGB(31, 0, 0));
	gfx->drawFilledRect(8, 0, 8, 8, woopsiRGB(0, 31, 0));
	gfx->drawFilledRect(0, 8, 8, 8, woopsiRGB(0, 31, 0));
	gfx->drawFilledRect(8, 8, 8, 8, woopsiRGB(31, 0, 0));
	delete gfx;

	_level = new LevelBase(10, 10);
	_level->setBlockAt(0, 0, new BlockBase(bmp));
	_level->setBlockAt(1, 1, new BlockBase(bmp));
	_level->setBlockAt(3, 0, new BlockBase(bmp));

	Rect rect;
	getClientRect(rect);

	_superBitmap = new SuperBitmap(rect.x, rect.y, rect.width, rect.height, rect.width, rect.height, true);
	addGadget(_superBitmap);

	gfx = _superBitmap->getGraphics();
	_level->render(gfx);
	delete gfx;
}

BoulderdashScreen::~BoulderdashScreen() {
	delete _level;
}
