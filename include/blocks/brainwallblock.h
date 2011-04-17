#ifndef _BRAIN_WALL_BLOCK_H_
#define _BRAIN_WALL_BLOCK_H_

#include <graphics.h>
#include <bitmap.h>
#include <game.h>

#include "blockbase.h"

#include "brainwallbmp.h"

/**
 * Wall blocks are static.  They have no function other than providing
 * obstacles.
 */
class BrainWallBlock : public BlockBase {
public:

	/**
	 * Constructor.
	 * @param x The x co-ordinate within the level map of the block.
	 * @param y The y co-ordinate within tne level map of the block.
	 * @param game Pointer to the game that contains the block.
	 */
	BrainWallBlock(s32 x, s32 y, Game* game) : BlockBase(x, y, game) {
		_animation->addFrame(&_bmp, 0);
	};

	/**
	 * Destructor.
	 */
	~BrainWallBlock() {};

private:
	BrainWallBmp _bmp;					/**< The wall bitmap. */
};

#endif
