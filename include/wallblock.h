#ifndef _WALL_BLOCK_H_
#define _WALL_BLOCK_H_

#include <graphics.h>
#include <bitmap.h>
#include <game.h>

#include "blockbase.h"
#include "wallbmp.h"

using namespace WoopsiUI;

class WallBlock : public BlockBase {
public:
	WallBlock(s32 x, s32 y, Game* game) : BlockBase(x, y, game) {
		_animation->addFrame(&_bmp, 0);
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

private:
	WallBmp _bmp;
};

#endif
