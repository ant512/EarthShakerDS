#include "boulderdashscreen.h"
#include "diamondblock.h"
#include "boulderblock.h"
#include "soilblock.h"

using namespace WoopsiUI;

BoulderdashScreen::BoulderdashScreen() : AmigaScreen("Boulderdash", true, true) {

	_game = new Game();

	Rect rect;
	getClientRect(rect);

	_superBitmap = new SuperBitmap(rect.x, rect.y, rect.width, rect.height, rect.width, rect.height, true);
	addGadget(_superBitmap);

	Graphics* gfx = _superBitmap->getGraphics();

	while(_game->iterate());

	_game->render(gfx);
	delete gfx;
}

BoulderdashScreen::~BoulderdashScreen() {
	delete _game;
}
