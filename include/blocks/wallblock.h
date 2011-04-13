#ifndef _WALL_BLOCK_H_
#define _WALL_BLOCK_H_

#include <graphics.h>
#include <bitmap.h>
#include <game.h>

#include "blockbase.h"
#include "wallbmp.h"

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
	 */
	WallBlock(s32 x, s32 y, Game* game) : BlockBase(x, y, game) {
		_isSlippy = true;
		
		_animation->addFrame(&_bmp, 0);
	};

	/**
	 * Destructor.
	 */
	~WallBlock() {};

private:
	WallBmp _bmp;					/**< The wall bitmap. */
};

#endif