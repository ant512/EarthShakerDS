#ifndef _SOIL_BLOCK_H_
#define _SOIL_BLOCK_H_

#include <graphics.h>
#include <bitmap.h>
#include <game.h>

#include "blockbase.h"

using namespace WoopsiUI;

class SoilBlock : public BlockBase {
public:
	SoilBlock(s32 x, s32 y, Game* game) : BlockBase(x, y, game) {
		Graphics* gfx = _bitmap->newGraphics();
		gfx->drawFilledRect(0, 0, 16, 16, woopsiRGB(17, 8, 2));
		delete gfx;
	};

	~SoilBlock() {};

	/**
	 * Player is moving into this block.  The direction in which the player is
	 * moving can be determined by comparing the co-ordinates of this block
	 * with the co-ordinates of the player.
	 * @return True if the player successfully moves into this block; false if
	 * not.
	 */
	virtual bool movePlayerInside() {
		return true;
	};
};

#endif
