#ifndef _DOOR_BLOCK_H_
#define _DOOR_BLOCK_H_

#include <graphics.h>
#include <bitmap.h>
#include <game.h>

#include "blockbase.h"

/**
 * Door blocks are static.  They become active when all diamonds in a level are
 * collected.  Touching an active door completes the level.
 */
class DoorBlock : public BlockBase {
public:

	/**
	 * Constructor.
	 * @param x The x co-ordinate within the level map of the block.
	 * @param y The y co-ordinate within tne level map of the block.
	 * @param game Pointer to the game that contains the block.
	 */
	DoorBlock(s32 x, s32 y, Game* game) : BlockBase(x, y, game) {
		_animation->addFrame(BitmapServer::getDoorBmp(), 0);
	};

	/**
	 * Destructor.
	 */
	~DoorBlock() {};
};

#endif
