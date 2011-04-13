#ifndef _WET_SOIL_BLOCK_H_
#define _WET_SOIL_BLOCK_H_

#include <graphics.h>
#include <bitmap.h>

#include "game.h"
#include "blockbase.h"
#include "constants.h"

/**
 * Wet soil works the same way as ordinary soil, except it falls like boulders
 * whenever possible.
 */
class WetSoilBlock : public BlockBase {
public:

	/**
	 * Constructor.
	 * @param x The x co-ordinate within the level map of the block.
	 * @param y The y co-ordinate within tne level map of the block.
	 * @param game Pointer to the game that contains the block.
	 */
	WetSoilBlock(s32 x, s32 y, Game* game) : BlockBase(x, y, game) {
		_isSlippy = true;
		_isHeavy = true;
		_isHeavyEnoughToKill = false;

		// TODO: Set up animation here

		_animation->play();

	};

	/**
	 * Destructor.
	 */
	~WetSoilBlock() {};

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

private:
};

#endif
