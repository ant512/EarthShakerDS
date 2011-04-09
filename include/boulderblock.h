#ifndef _BOULDER_BLOCK_H_
#define _BOULDER_BLOCK_H_

#include <graphics.h>
#include <bitmap.h>

#include "game.h"
#include "blockbase.h"
#include "playerblock.h"

using namespace WoopsiUI;

class BoulderBlock : public BlockBase {
public:
	BoulderBlock(s32 x, s32 y, Game* game) : BlockBase(x, y, game) {
		_isSlippy = true;	// Boulders are born slippy

		Graphics* gfx = _bitmap->newGraphics();
		gfx->drawFilledEllipse(7, 7, 7, 7, woopsiRGB(31, 0, 0));
		delete gfx;
	};

	~BoulderBlock() {};

	virtual bool iterate() {
		return drop();
	};

	/**
	 * Player is moving into this block.  The direction in which the player is
	 * moving can be determined by comparing the co-ordinates of this block
	 * with the co-ordinates of the player.
	 * @return True if the player successfully moves into this block; false if
	 * not.
	 */
	virtual bool movePlayerInside() {

		PlayerBlock* player = _game->getPlayerBlock();

		// Ignore any attempts to push the block vertically
		if (player->getY() != _y) return false;

		// Try to push the block
		if (_x > player->getX()) {
			return pushRight();
		} else if (_x < player->getX()) {
			return pushLeft();
		}

		// Block couldn't be pushed
		return false;
	};
};

#endif
