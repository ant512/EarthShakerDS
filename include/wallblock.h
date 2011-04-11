#ifndef _WALL_BLOCK_H_
#define _WALL_BLOCK_H_

#include <graphics.h>
#include <bitmap.h>
#include <game.h>

#include "blockbase.h"
#include "wallbmp.h"

class WallBlock : public BlockBase {
public:
	WallBlock(s32 x, s32 y, Game* game) : BlockBase(x, y, game) {
		_isSlippy = true;
		
		_animation->addFrame(&_bmp, 0);
	};

	~WallBlock() {};

private:
	WallBmp _bmp;
};

#endif
