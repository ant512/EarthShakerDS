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

	_timer = new WoopsiTimer(10, true);
	addGadget(_timer);
	_timer->addGadgetEventHandler(this);
	_timer->start();

	Graphics* gfx = _superBitmap->getGraphics();
	_game->render(gfx);
}

BoulderdashScreen::~BoulderdashScreen() {
	delete _game;
}

void BoulderdashScreen::onKeyRepeat(KeyCode keyCode) {
	onKeyPress(keyCode);
}

void BoulderdashScreen::onKeyPress(KeyCode keyCode) {

	Graphics* gfx = _superBitmap->getGraphics();

	switch (keyCode) {
		case KEY_CODE_UP:
			_game->getPlayerBlock()->applyUpwardForce();
			_game->render(gfx);
			_superBitmap->markRectsDamaged();
			break;
		case KEY_CODE_DOWN:
			_game->getPlayerBlock()->applyDownwardForce();
			_game->render(gfx);
			_superBitmap->markRectsDamaged();
			break;
		case KEY_CODE_LEFT:
			_game->getPlayerBlock()->applyLeftwardForce();
			_game->render(gfx);
			_superBitmap->markRectsDamaged();
			break;
		case KEY_CODE_RIGHT:
			_game->getPlayerBlock()->applyRightwardForce();
			_game->render(gfx);
			_superBitmap->markRectsDamaged();
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
		}
	} else {
		AmigaScreen::handleActionEvent(e);
	}
}
