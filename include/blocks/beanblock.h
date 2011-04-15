#ifndef _BEAN_BLOCK_H_
#define _BEAN_BLOCK_H_

#include <graphics.h>
#include <bitmap.h>

#include "game.h"
#include "blockbase.h"
#include "beanbmp1.h"
#include "beanbmp2.h"
#include "beanbmp3.h"
#include "constants.h"

/**
 * BeanBlocks give a time extension and points when collected.
 */
class BeanBlock : public BlockBase {
public:

	/**
	 * Constructor.
	 * @param x The x co-ordinate within the level map of the block.
	 * @param y The y co-ordinate within tne level map of the block.
	 * @param game Pointer to the game that contains the block.
	 */
	BeanBlock(s32 x, s32 y, Game* game) : BlockBase(x, y, game) {
		_isHeavy = true;
		_isHeavyEnoughToKill = true;

		_animation->setLoopType(WoopsiGfx::Animation::ANIMATION_LOOPTYPE_PINGPONG);
		_animation->addFrame(&_bmp1, 0);
		_animation->addFrame(&_bmp2, 0);
		_animation->addFrame(&_bmp3, 0);
		_animation->play();

	};

	/**
	 * Destructor.
	 */
	~BeanBlock() {};

	/**
	 * Adds to the player's score and removes the block from the level.
	 * @return True.
	 */
	bool pushUp() {
		_game->addScore(BEAN_SCORE);
		_game->increaseTime(BEAN_TIME);
		_game->getLevel()->removeBlockAt(_x, _y);
		return true;
	};

	/**
	 * Adds to the player's score and removes the block from the level.
	 * @return True.
	 */
	bool pushDown() {
		_game->addScore(BEAN_SCORE);
		_game->increaseTime(BEAN_TIME);
		_game->getLevel()->removeBlockAt(_x, _y);
		return true;
	};

	/**
	 * Adds to the player's score and removes the block from the level.
	 * @return True.
	 */
	bool pushLeft() {
		_game->addScore(BEAN_SCORE);
		_game->increaseTime(BEAN_TIME);
		_game->getLevel()->removeBlockAt(_x, _y);
		return true;
	};

	/**
	 * Adds to the player's score and removes the block from the level.
	 * @return True.
	 */
	bool pushRight() {
		_game->addScore(BEAN_SCORE);
		_game->increaseTime(BEAN_TIME);
		_game->getLevel()->removeBlockAt(_x, _y);
		return true;
	};

private:
	BeanBmp1 _bmp1;		/**< First animation bitmap. */
	BeanBmp2 _bmp2;		/**< Second animation bitmap. */
	BeanBmp3 _bmp3;		/**< Third animation bitmap. */
};

#endif
