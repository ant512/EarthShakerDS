#ifndef _WALL_BLOCK_H_
#define _WALL_BLOCK_H_

#include <graphics.h>
#include <bitmap.h>
#include <game.h>

#include "blockbase.h"

using namespace WoopsiUI;

class WallBlock : public BlockBase {
public:
	WallBlock(s32 x, s32 y, Game* game) : BlockBase(x, y, game) {
		Graphics* gfx = _bitmap->newGraphics();
		gfx->drawFilledRect(0, 0, 16, 16, woopsiRGB(31, 8, 2));
		delete gfx;
	};

	~WallBlock() {};

	bool applyUpwardForce() { return false; };
	bool applyDownwardForce() { return false; };
	bool applyLeftwardForce() { return false; };
	bool applyRightwardForce() { return false; };

	bool digFromBelow() { return false; };
	bool digFromAbove() { return false; };
	bool digFromLeft() { return false; };
	bool digFromRight() { return false; };
};

#endif
