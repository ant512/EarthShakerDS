#ifndef _BOULDER_BLOCK_H_
#define _BOULDER_BLOCK_H_

#include <graphics.h>
#include <bitmap.h>

#include "game.h"
#include "blockbase.h"
#include "playerblock.h"

using namespace WoopsiUI;

class BoulderBlock : public HeavyBlockBase {
public:
	BoulderBlock(s32 x, s32 y, Game* game) : HeavyBlockBase(x, y, game) {
		_isSlippy = true;	// Boulders are born slippy

		Graphics* gfx = _bitmap->newGraphics();
		gfx->drawFilledEllipse(7, 7, 7, 7, woopsiRGB(31, 0, 0));
		delete gfx;
	};

	~BoulderBlock() {};

	virtual bool iterate() {
		return drop();
	};
};

#endif
