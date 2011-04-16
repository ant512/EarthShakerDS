#ifndef _BRICK_WALL_BLOCK_H_
#define _BRICK_WALL_BLOCK_H_

#include <graphics.h>
#include <bitmap.h>

#include "bitmapserver.h"
#include "blockbase.h"
#include "game.h"

/**
 * Wall blocks are static.  They have no function other than providing
 * obstacles.
 */
class BrickWallBlock : public BlockBase {
public:

	/**
	 * Constructor.
	 * @param x The x co-ordinate within the level map of the block.
	 * @param y The y co-ordinate within tne level map of the block.
	 * @param game Pointer to the game that contains the block.
	 */
	BrickWallBlock(s32 x, s32 y, Game* game) : BlockBase(x, y, game) {
		_animation->addFrame(BitmapServer::getBrickWallBmp(), 0);
	};

	/**
	 * Destructor.
	 */
	~BrickWallBlock() {};
};

#endif
