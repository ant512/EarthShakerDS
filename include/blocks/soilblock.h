#ifndef _SOIL_BLOCK_H_
#define _SOIL_BLOCK_H_

#include <graphics.h>
#include <bitmap.h>
#include <game.h>

#include "blockbase.h"
#include "bitmapserver.h"

/**
 * Soil can be removed from the map by calling its dig methods.  It provides
 * destructable scenery that the player can move through.  Removing soil can
 * cause blocks resting on it to fall.
 */
class SoilBlock : public BlockBase {
public:

	/**
	 * Constructor.
	 * @param x The x co-ordinate within the level map of the block.
	 * @param y The y co-ordinate within tne level map of the block.
	 * @param game Pointer to the game that contains the block.
	 * @param bitmap The bitmap to use as the visual representation of the
	 * block.
	 */
	SoilBlock(s32 x, s32 y, Game* game, WoopsiGfx::BitmapBase* bitmap) : BlockBase(x, y, game) {
		_isSlippy = false;
		_animation->addFrame(bitmap, 0);
	};

	/**
	 * Destructor.
	 */
	~SoilBlock() {};

	/**
	 * Removes the block.
	 * @return True.
	 */
	bool digFromBelow() {
		_game->getLevel()->removeBlockAt(_x, _y);
		return true;
	};

	/**
	 * Removes the block.
	 * @return True.
	 */
	bool digFromAbove() {
		_game->getLevel()->removeBlockAt(_x, _y);
		return true;
	};

	/**
	 * Removes the block.
	 * @return True.
	 */
	bool digFromLeft() {
		_game->getLevel()->removeBlockAt(_x, _y);
		return true;
	};

	/**
	 * Removes the block.
	 * @return True.
	 */
	bool digFromRight() {
		_game->getLevel()->removeBlockAt(_x, _y);
		return true;
	};
};

#endif
