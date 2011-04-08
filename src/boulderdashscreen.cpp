#include "boulderdashscreen.h"
#include "diamondblock.h"
#include "boulderblock.h"
#include "soilblock.h"
#include "blockbase.h"

#include <debug.h>

using namespace WoopsiUI;

BoulderdashScreen::BoulderdashScreen() : AmigaScreen("Boulderdash", true, true) {

	_game = new Game();

	Rect rect;
	getClientRect(rect);

	_superBitmap = new SuperBitmap(rect.x, rect.y, rect.width, rect.height, rect.width, rect.height, false);
	addGadget(_superBitmap);
	_superBitmap->addGadgetEventHandler(this);

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

void BoulderdashScreen::onKeyPress(KeyCode keyCode) {

	Graphics* gfx = _superBitmap->getGraphics();

	switch (keyCode) {
		case KEY_CODE_UP:
			_game->getPlayerSprite()->moveUp();
			_game->render(gfx);
			_superBitmap->markRectsDamaged();
			_timer->reset();
			_timer->start();
			break;
		case KEY_CODE_DOWN:
			_game->getPlayerSprite()->moveDown();
			_game->render(gfx);
			_superBitmap->markRectsDamaged();
			_timer->reset();
			_timer->start();
			break;
		case KEY_CODE_LEFT:
			_game->getPlayerSprite()->moveLeft();
			_game->render(gfx);
			_superBitmap->markRectsDamaged();
			_timer->reset();
			_timer->start();
			break;
		case KEY_CODE_RIGHT:
			_game->getPlayerSprite()->moveRight();
			_game->render(gfx);
			_superBitmap->markRectsDamaged();
			_timer->reset();
			_timer->start();
			break;
		default:
			break;
	}
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
