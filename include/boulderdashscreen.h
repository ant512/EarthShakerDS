#ifndef _BOULDERDASH_SCREEN_H_
#define _BOULDERDASH_SCREEN_H_

#include <amigascreen.h>
#include <bitmap.h>
#include <graphics.h>
#include <superbitmap.h>
#include <woopsifuncs.h>

#include "levelbase.h"
#include "blockbase.h"

using namespace WoopsiUI;

class BoulderdashScreen : public AmigaScreen {
public:
	BoulderdashScreen();

	~BoulderdashScreen();

private:
	LevelBase* _level;
	SuperBitmap* _superBitmap;

	LevelBase* createLevel(u8* data, s32 width, s32 height);
};

#endif
