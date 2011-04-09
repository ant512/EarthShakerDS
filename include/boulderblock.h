#ifndef _BOULDER_BLOCK_H_
#define _BOULDER_BLOCK_H_

#include <graphics.h>
#include <bitmap.h>

#include "game.h"
#include "blockbase.h"
#include "playerblock.h"
#include "boulderbmp.h"

class BoulderBlock : public HeavyBlockBase {
public:
	BoulderBlock(s32 x, s32 y, Game* game) : HeavyBlockBase(x, y, game) {
		_isSlippy = true;	// Boulders are born slippy

		_animation->addFrame(&_bmp, 0);
	};

	~BoulderBlock() {};

	virtual bool iterate() {
		return drop();
	};

private:
	BoulderBmp _bmp;
};

#endif
