#ifndef _WALL_BLOCK_H_
#define _WALL_BLOCK_H_

#include <graphics.h>
#include <bitmapbase.h>

#include "game.h"
#include "blockbase.h"
#include "brickwallmapbmp.h"

/**
 * Wall blocks are static.  They have no function other than providing
 * obstacles.
 */
class WallBlock : public BlockBase {
public:

	/**
	 * Constructor.
	 * @param x The x co-ordinate within the level map of the block.
	 * @param y The y co-ordinate within tne level map of the block.
	 * @param game Pointer to the game that contains the block.
	 * @param bitmap The bitmap to use as the visual representation of the
	 * block.
	 */
	WallBlock(s32 x, s32 y, Game* game, WoopsiGfx::BitmapBase* bitmap) : BlockBase(x, y, game) {
		_animation->addFrame(bitmap, 0);

		_mapBitmap = new BrickWallMapBmp();
	};

	/**
	 * Destructor.
	 */
	~WallBlock() {
		delete _mapBitmap;
	};
};

#endif
