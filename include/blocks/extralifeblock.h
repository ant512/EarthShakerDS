#ifndef _EXTRA_LIFE_BLOCK_H_
#define _EXTRA_LIFE_BLOCK_H_

#include <graphics.h>
#include <bitmap.h>

#include "gamesession.h"
#include "blockbase.h"
#include "constants.h"
#include "extralifebmp1.h"
#include "extralifebmp2.h"
#include "extralifebmp3.h"
#include "extralifebmp4.h"
#include "extralifemapbmp.h"
#include "soundplayer.h"

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
	ExtraLifeBlock(s32 x, s32 y, GameSession* game) : BlockBase(x, y, game) {
		_isHeavy = true;
		_isHeavyEnoughToKill = true;
		
		_animation->addFrame(&_bmp1, 0);
		_animation->addFrame(&_bmp2, 0);
		_animation->addFrame(&_bmp3, 0);
		_animation->addFrame(&_bmp4, 0);
		_animation->play();

		_mapBitmap = new ExtraLifeMapBmp();
	};

	/**
	 * Destructor.
	 */
	~ExtraLifeBlock() {
		delete _mapBitmap;
	};

	/**
	 * Adds an extra life and removes the block from the level.
	 * @return True.
	 */
	bool pushUp() {
		collect();
		return true;
	};

	/**
	 * Adds an extra life and removes the block from the level.
	 * @return True.
	 */
	bool pushDown() {
		collect();
		return true;
	};

	/**
	 * Adds an extra life and removes the block from the level.
	 * @return True.
	 */
	bool pushLeft() {
		collect();
		return true;
	};

	/**
	 * Adds an extra life and removes the block from the level.
	 * @return True.
	 */
	bool pushRight() {
		collect();
		return true;
	};

	/**
	 * Pushes this block if possible.
	 */
	void pokeUp() {
		pushUp();
	};

	/**
	 * Pushes this block if possible.
	 */
	void pokeDown() {
		pushDown();
	};

	/**
	 * Pushes this block if possible.
	 */
	void pokeLeft() {
		pushLeft();
	};

	/**
	 * Pushes this block if possible.
	 */
	void pokeRight() {
		pushRight();
	};

private:
	ExtraLifeBmp1 _bmp1;		/**< The first animation frame. */
	ExtraLifeBmp2 _bmp2;		/**< The second animation frame. */
	ExtraLifeBmp3 _bmp3;		/**< The third animation frame. */
	ExtraLifeBmp4 _bmp4;		/**< The fourth animation frame. */

	/**
	 * Collects the extra life.
	 */
	void collect() {
		_game->increaseLives();
		_game->addScore(EXTRA_LIFE_SCORE);
		_game->getLevel()->removeBlockAt(_x, _y);

		SoundPlayer::playExtraLifeCollect();
	};
};

#endif
