#include "boulderdashscreen.h"
#include "diamondblock.h"
#include "boulderblock.h"
#include "soilblock.h"
#include "blockbase.h"

#include <debug.h>

using namespace WoopsiUI;

BoulderdashScreen::BoulderdashScreen() : AmigaScreen("Boulderdash", true, true) {

	_upHeld = false;
	_downHeld = false;
	_leftHeld = false;
	_rightHeld = false;

	_game = new Game();

	Rect rect;
	getClientRect(rect);

	_superBitmap = new SuperBitmap(rect.x, rect.y, rect.width, rect.height, rect.width, rect.height, false);
	addGadget(_superBitmap);
	_superBitmap->addGadgetEventHandler(this);

	_timer = new WoopsiTimer(5, true);
	addGadget(_timer);
	_timer->addGadgetEventHandler(this);
	_timer->start();

	Graphics* gfx = _superBitmap->getGraphics();
	_game->render(gfx);
}

BoulderdashScreen::~BoulderdashScreen() {
	delete _game;
}

void BoulderdashScreen::onKeyRelease(KeyCode keyCode) {
	switch (keyCode) {
		case KEY_CODE_UP:
			_upHeld = false;
			break;
		case KEY_CODE_DOWN:
			_downHeld = false;
			break;
		case KEY_CODE_LEFT:
			_leftHeld = false;
			break;
		case KEY_CODE_RIGHT:
			_rightHeld = false;
			break;
		default:
			break;
	}
}

void BoulderdashScreen::onKeyPress(KeyCode keyCode) {
	_upHeld = keyCode == KEY_CODE_UP;
	_downHeld = keyCode == KEY_CODE_DOWN;
	_leftHeld = keyCode == KEY_CODE_LEFT;
	_rightHeld = keyCode == KEY_CODE_RIGHT;
}

void BoulderdashScreen::handleActionEvent(const GadgetEventArgs& e) {
	if (e.getSource() == NULL) return;

	if (e.getSource() == _timer) {

		if (_upHeld) _game->getPlayerBlock()->applyUpwardForce();
		if (_downHeld) _game->getPlayerBlock()->applyDownwardForce();
		if (_leftHeld) _game->getPlayerBlock()->applyLeftwardForce();
		if (_rightHeld) _game->getPlayerBlock()->applyRightwardForce();

		_game->iterate();
		
		Graphics* gfx = _superBitmap->getGraphics();
		_game->render(gfx);
		_superBitmap->markRectsDamaged();

	} else {
		AmigaScreen::handleActionEvent(e);
	}
}
