#ifndef _BOULDERDASH_SCREEN_H_
#define _BOULDERDASH_SCREEN_H_

#include <amigascreen.h>
#include <bitmap.h>
#include <gadgeteventhandler.h>
#include <gadgeteventargs.h>
#include <graphics.h>
#include <superbitmap.h>
#include <woopsifuncs.h>
#include <woopsitimer.h>

#include "game.h"

using namespace WoopsiUI;

class BoulderdashScreen : public AmigaScreen {
public:
	BoulderdashScreen();
	~BoulderdashScreen();

	void handleActionEvent(const GadgetEventArgs& e);

	/**
	 * Handle a key press event.
	 * @param e The event data.
	 */
	void onKeyPress(KeyCode keyCode);
	void onKeyRelease(KeyCode keyCode);

private:
	Game* _game;
	SuperBitmap* _superBitmap;
	WoopsiTimer* _timer;
	bool _upHeld;
	bool _downHeld;
	bool _leftHeld;
	bool _rightHeld;
};

#endif
