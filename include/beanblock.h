#ifndef _BEAN_BLOCK_H_
#define _BEAN_BLOCK_H_

#include <graphics.h>
#include <bitmap.h>

#include "game.h"
#include "heavyblockbase.h"
#include "beanbmp1.h"
#include "beanbmp2.h"
#include "beanbmp3.h"
#include "constants.h"

/**
 * BeanBlocks give a time extension and points when collected.
 */
class BeanBlock : public HeavyBlockBase {
public:

	/**
	 * Constructor.
	 * @param x X co-ordinate within the level map of the block.
	 * @param y Y co-ordinate within tne level map of the block.
	 * @param game Pointer to the game that contains the block.
	 */
	BeanBlock(s32 x, s32 y, Game* game) : HeavyBlockBase(x, y, game) {
		_isSlippy = true;

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

	virtual bool applyUpwardForce() {
		_game->addScore(BEAN_SCORE);
		return true;
	};

	virtual bool applyDownwardForce() {
		_game->addScore(BEAN_SCORE);
		return true;
	};

	virtual bool applyLeftwardForce() {
		_game->addScore(BEAN_SCORE);
		return true;
	};

	virtual bool applyRightwardForce() {
		_game->addScore(BEAN_SCORE);
		return true;
	};

private:
	BeanBmp1 _bmp1;		/**< First animation bitmap. */
	BeanBmp2 _bmp2;		/**< Second animation bitmap. */
	BeanBmp3 _bmp3;		/**< Third animation bitmap. */
};

#endif
