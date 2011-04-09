#ifndef _SOIL_BLOCK_H_
#define _SOIL_BLOCK_H_

#include <graphics.h>
#include <bitmap.h>
#include <game.h>

#include "blockbase.h"
#include "soilbmp.h"

class SoilBlock : public BlockBase {
public:
	SoilBlock(s32 x, s32 y, Game* game) : BlockBase(x, y, game) {
		_animation->addFrame(&_bmp, 0);
	};

	~SoilBlock() {};

	bool applyUpwardForce() { return false; };
	bool applyDownwardForce() { return false; };
	bool applyLeftwardForce() { return false; };
	bool applyRightwardForce() { return false; };

	bool digFromBelow() { return true; };
	bool digFromAbove() { return true; };
	bool digFromLeft() { return true; };
	bool digFromRight() { return true; };

private:
	SoilBmp _bmp;
};

#endif
