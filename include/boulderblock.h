#ifndef _BOULDER_BLOCK_H_
#define _BOULDER_BLOCK_H_

#include <graphics.h>
#include <bitmap.h>

#include "blockbase.h"

using namespace WoopsiUI;

class BoulderBlock : public BlockBase {
public:
	BoulderBlock() {
		Graphics* gfx = _bitmap->newGraphics();
		gfx->drawFilledEllipse(7, 7, 7, 7, woopsiRGB(0, 0, 31));
		delete gfx;
	};

	~BoulderBlock() {};

	virtual bool iterate(s32 x, s32 y, LevelBase* level) {
		return drop(x, y, level);
	};

};

#endif
