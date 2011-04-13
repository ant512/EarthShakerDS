#ifndef _EXTRA_LIFE_BLOCK_H_
#define _EXTRA_LIFE_BLOCK_H_

#include <graphics.h>
#include <bitmap.h>

#include "game.h"
#include "blockbase.h"
#include "constants.h"

/**
 * Gives the player an extra life when collected.
 */
class ExtraLifeBlock : public BlockBase {
public:

	/**
	 * Constructor.
	 * @param x The x co-ordinate within the level map of the block.
	 * @param y The y co-ordinate within tne level map of the block.
	 * @param game Pointer to the game that contains the block.
	 */
	ExtraLifeBlock(s32 x, s32 y, Game* game) : BlockBase(x, y, game) {
		_isSlippy = true;

		// TODO: Set up animation here

		_animation->play();

	};

	/**
	 * Destructor.
	 */
	~ExtraLifeBlock() {};

	/**
	 * Adds an extra life and removes the block from the level.
	 * @return True.
	 */
	virtual bool pushUp() {
		_game->increaseLives();
		_game->getLevel()->removeBlockAt(_x, _y);
		return true;
	};

	/**
	 * Adds an extra life and removes the block from the level.
	 * @return True.
	 */
	virtual bool pushDown() {
		_game->increaseLives();
		_game->getLevel()->removeBlockAt(_x, _y);
		return true;
	};

	/**
	 * Adds an extra life and removes the block from the level.
	 * @return True.
	 */
	virtual bool pushLeft() {
		_game->increaseLives();
		_game->getLevel()->removeBlockAt(_x, _y);
		return true;
	};

	/**
	 * Adds an extra life and removes the block from the level.
	 * @return True.
	 */
	virtual bool pushRight() {
		_game->increaseLives();
		_game->getLevel()->removeBlockAt(_x, _y);
		return true;
	};

private:
};

#endif
