#ifndef _BOULDERDASH_SCREEN_H_
#define _BOULDERDASH_SCREEN_H_

#include <amigascreen.h>
#include <bitmap.h>
#include <graphics.h>
#include <superbitmap.h>
#include <woopsifuncs.h>

#include "game.h"

using namespace WoopsiUI;

class BoulderdashScreen : public AmigaScreen {
public:
	BoulderdashScreen();
	~BoulderdashScreen();

private:
	Game* _game;
	SuperBitmap* _superBitmap;
};

#endif
