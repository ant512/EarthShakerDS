#ifndef _BEAN_BLOCK_H_
#define _BEAN_BLOCK_H_

#include <graphics.h>
#include <bitmap.h>

#include "beanbmp1.h"
#include "beanbmp2.h"
#include "beanbmp3.h"
#include "beanmapbmp.h"
#include "blockbase.h"
#include "constants.h"
#include "game.h"
#include "soundplayer.h"

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

		_mapBitmap = new BeanMapBmp();
	};

	/**
	 * Destructor.
	 */
	~BeanBlock() {
		delete _mapBitmap;
	};

	/**
	 * Adds to the player's score and removes the block from the level.
	 * @return True.
	 */
	bool pushUp() {
		collect();
		return true;
	};

	/**
	 * Adds to the player's score and removes the block from the level.
	 * @return True.
	 */
	bool pushDown() {
		collect();
		return true;
	};

	/**
	 * Adds to the player's score and removes the block from the level.
	 * @return True.
	 */
	bool pushLeft() {
		collect();
		return true;
	};

	/**
	 * Adds to the player's score and removes the block from the level.
	 * @return True.
	 */
	bool pushRight() {
		collect();
		return true;
	};

private:
	BeanBmp1 _bmp1;		/**< First animation bitmap. */
	BeanBmp2 _bmp2;		/**< Second animation bitmap. */
	BeanBmp3 _bmp3;		/**< Third animation bitmap. */

	/**
	 * Collect the bean.  Adds to the player's score and time and removes the
	 * bean from the level.
	 */
	void collect() {
		s32 remainingTime = BEAN_TIME;
		s32 timeIncreasePerIteration = 2;
		s32 scoreIncrease = (BEAN_SCORE / BEAN_TIME) * timeIncreasePerIteration;

		_game->getLevel()->removeBlockAt(_x, _y);

		SoundPlayer::playBeanCollect();

		while (remainingTime > 0) {
			_game->increaseTime(timeIncreasePerIteration);
			_game->addScore(scoreIncrease);
			remainingTime -= timeIncreasePerIteration;
			Hardware::waitForVBlank();
		}
	};
};

#endif
