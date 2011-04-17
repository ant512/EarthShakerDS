#ifndef _BARRIER_BLOCK_H_
#define _BARRIER_BLOCK_H_

#include <graphics.h>
#include <bitmap.h>
#include <game.h>

#include "blockbase.h"

#include "barrierbmp1.h"
#include "barrierbmp2.h"
#include "barrierbmp3.h"

/**
 * Barrier blocks can be destroyed by dropping something onto their controller.
 */
class BarrierBlock : public BlockBase {
public:

	/**
	 * Constructor.
	 * @param x The x co-ordinate within the level map of the block.
	 * @param y The y co-ordinate within tne level map of the block.
	 * @param game Pointer to the game that contains the block.
	 */
	BarrierBlock(s32 x, s32 y, Game* game) : BlockBase(x, y, game) {
		_animation->setLoopType(WoopsiGfx::Animation::ANIMATION_LOOPTYPE_PINGPONG);
		_animation->addFrame(&_bmp1, 0);
		_animation->addFrame(&_bmp2, 0);
		_animation->addFrame(&_bmp3, 0);
		_animation->play();
	};

	/**
	 * Destructor.
	 */
	~BarrierBlock() {};

	/**
	 * Removes time from the player.
	 * @return False.
	 */
	bool pushLeft() {
		push();
		return false;
	};

	/**
	 * Removes time from the player.
	 * @return False.
	 */
	bool pushRight() {
		push();
		return false;
	};

	/**
	 * Removes time from the player.
	 * @return False.
	 */
	bool pushUp() {
		push();
		return false;
	};

	/**
	 * Removes time from the player.
	 * @return False.
	 */
	bool pushDown() {
		push();
		return false;
	};

private:
	BarrierBmp1 _bmp1;					/**< The first animation frame. */
	BarrierBmp2 _bmp2;					/**< The second animation frame. */
	BarrierBmp3 _bmp3;					/**< The third animation frame. */

	/**
	 * Removes time from the player.
	 */
	void push() {

		if (_isOddIteration != _game->isOddIteration()) return;
		if (_isExploding) return;

		_isOddIteration = !_isOddIteration;

		_game->decreaseTime();
	};
};

#endif
