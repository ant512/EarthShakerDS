#ifndef _GRAVITY_INVERSION_BLOCK_H_
#define _GRAVITY_INVERSION_BLOCK_H_

#include <graphics.h>
#include <bitmap.h>

#include "game.h"
#include "blockbase.h"
#include "constants.h"

/**
 * Collecting a gravity inversion block switches gravity in the game so that
  blocks* fall upwards instead of downwards.
 */
class GravityInversionBlock : public BlockBase {
public:

	/**
	 * Constructor.
	 * @param x The x co-ordinate within the level map of the block.
	 * @param y The y co-ordinate within tne level map of the block.
	 * @param game Pointer to the game that contains the block.
	 */
	GravityInversionBlock(s32 x, s32 y, Game* game) : BlockBase(x, y, game) {
		_isSlippy = true;

		_animation->play();

	};

	/**
	 * Destructor.
	 */
	~GravityInversionBlock() {};

	/**
	 * Inverts gravity and removes the block from the level.
	 * @return True.
	 */
	virtual bool pushUp() {
		_game->invertGravity();
		_game->getLevel()->removeBlockAt(_x, _y);
		return true;
	};

	/**
	 * Inverts gravity and removes the block from the level.
	 * @return True.
	 */
	virtual bool pushDown() {
		_game->invertGravity();
		_game->getLevel()->removeBlockAt(_x, _y);
		return true;
	};

	/**
	 * Inverts gravity and removes the block from the level.
	 * @return True.
	 */
	virtual bool pushLeft() {
		_game->invertGravity();
		_game->getLevel()->removeBlockAt(_x, _y);
		return true;
	};

	/**
	 * Inverts gravity and removes the block from the level.
	 * @return True.
	 */
	virtual bool pushRight() {
		_game->invertGravity();
		_game->getLevel()->removeBlockAt(_x, _y);
		return true;
	};

private:
};

#endif
