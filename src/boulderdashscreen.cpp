#include "boulderdashscreen.h"
#include "diamondblock.h"
#include "boulderblock.h"
#include "soilblock.h"
#include "blockbase.h"

#include <debug.h>

using namespace WoopsiUI;

BoulderdashScreen::BoulderdashScreen() : AmigaScreen("Boulderdash", true, true) {

	_game = new Game();
	_game->getLevel()->getBlockAt(0, 0)->movePlayerInside(1, 0);
	_game->getLevel()->getBlockAt(14, 2)->movePlayerInside(15, 2);

	Rect rect;
	getClientRect(rect);

	_superBitmap = new SuperBitmap(rect.x, rect.y, rect.width, rect.height, rect.width, rect.height, true);
	addGadget(_superBitmap);

	_timer = new WoopsiTimer(10, false);
	addGadget(_timer);
	_timer->addGadgetEventHandler(this);
	_timer->start();

	Graphics* gfx = _superBitmap->getGraphics();
	_game->render(gfx);
}

BoulderdashScreen::~BoulderdashScreen() {
	delete _game;
}

void BoulderdashScreen::handleActionEvent(const GadgetEventArgs& e) {
	if (e.getSource() == NULL) return;

	if (e.getSource() == _timer) {

		bool requiresIteration = _game->iterate();

		if (requiresIteration) {
			
			Graphics* gfx = _superBitmap->getGraphics();
			_game->render(gfx);
			_superBitmap->markRectsDamaged();

			_timer->reset();
			_timer->start();
		}
	} else {
		AmigaScreen::handleActionEvent(e);
	}
}
