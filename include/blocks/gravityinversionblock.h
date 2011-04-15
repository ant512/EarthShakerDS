#ifndef _GRAVITY_INVERSION_BLOCK_H_
#define _GRAVITY_INVERSION_BLOCK_H_

#include <graphics.h>
#include <bitmap.h>

#include "game.h"
#include "blockbase.h"
#include "constants.h"
#include "gravityinversionbmp1.h"
#include "gravityinversionbmp2.h"
#include "gravityinversionbmp3.h"

/**
 * Collecting a gravity inversion block switches gravity in the game so that
 * blocks fall upwards instead of downwards.
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

		_animation->setLoopType(WoopsiGfx::Animation::ANIMATION_LOOPTYPE_PINGPONG);
		_animation->addFrame(&_bmp1, 0);
		_animation->addFrame(&_bmp2, 0);
		_animation->addFrame(&_bmp3, 0);
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
		_game->addScore(GRAVITY_INVERSION_SCORE);
		_game->invertGravity();
		_game->getLevel()->removeBlockAt(_x, _y);
		return true;
	};

	/**
	 * Inverts gravity and removes the block from the level.
	 * @return True.
	 */
	virtual bool pushDown() {
		_game->addScore(GRAVITY_INVERSION_SCORE);
		_game->invertGravity();
		_game->getLevel()->removeBlockAt(_x, _y);
		return true;
	};

	/**
	 * Inverts gravity and removes the block from the level.
	 * @return True.
	 */
	virtual bool pushLeft() {
		_game->addScore(GRAVITY_INVERSION_SCORE);
		_game->invertGravity();
		_game->getLevel()->removeBlockAt(_x, _y);
		return true;
	};

	/**
	 * Inverts gravity and removes the block from the level.
	 * @return True.
	 */
	virtual bool pushRight() {
		_game->addScore(GRAVITY_INVERSION_SCORE);
		_game->invertGravity();
		_game->getLevel()->removeBlockAt(_x, _y);
		return true;
	};

private:
	GravityInversionBmp1 _bmp1;		/**< The first animation frame. */
	GravityInversionBmp2 _bmp2;		/**< The second animation frame. */
	GravityInversionBmp3 _bmp3;		/**< The third animation frame. */
};

#endif
