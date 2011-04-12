#ifndef _BOULDER_BLOCK_H_
#define _BOULDER_BLOCK_H_

#include <graphics.h>
#include <bitmap.h>

#include "game.h"
#include "blockbase.h"
#include "playerblock.h"
#include "boulderbmp.h"
#include "boulderexplodebmp1.h"
#include "boulderexplodebmp2.h"
#include "boulderexplodebmp3.h"
#include "boulderexplodebmp4.h"
#include "boulderexplodebmp5.h"
#include "boulderexplodebmp6.h"
#include "boulderexplodebmp7.h"

/**
 * Boulders fall if not sitting on anything and can be pushed horizontally.
 * They are the primary "enemy" in the game.
 */
class BoulderBlock : public HeavyBlockBase {
public:

	/**
	 * Constructor.
	 * @param x The x co-ordinate within the level map of the block.
	 * @param y The y co-ordinate within tne level map of the block.
	 * @param game Pointer to the game that contains the block.
	 */
	BoulderBlock(s32 x, s32 y, Game* game) : HeavyBlockBase(x, y, game) {
		_isSlippy = true;

		_animation->addFrame(&_bmp, 0);

		_explodingAnimation->addFrame(&_explodingBmp1, 0);
		_explodingAnimation->addFrame(&_explodingBmp2, 0);
		_explodingAnimation->addFrame(&_explodingBmp3, 0);
		_explodingAnimation->addFrame(&_explodingBmp4, 0);
		_explodingAnimation->addFrame(&_explodingBmp5, 0);
		_explodingAnimation->addFrame(&_explodingBmp6, 0);
		_explodingAnimation->addFrame(&_explodingBmp7, 0);
	};

	/**
	 * Destructor.
	 */
	~BoulderBlock() {};

	/**
	 * Pushes this block to the left if the block to the left is empty.
	 * @return True if the block moves; false if not.
	 */
	virtual bool pushLeft() {
		if (_x == 0) return false;
		if (_isExploding) return false;

		LevelBase* level = _game->getLevel();
		BlockBase* block = level->getBlockAt(_x - 1, _y);

		if (block == NULL) {
			level->moveBlock(_x, _y, _x - 1, _y);
			return true;
		}

		return false;
	};

	/**
	 * Pushes this block to the right if the block to the left is empty.
	 * @return True if the block moves; false if not.
	 */
	virtual bool pushRight() {
		if (_isExploding) return false;

		LevelBase* level = _game->getLevel();

		if (_x == level->getWidth() - 1) return false;

		BlockBase* block = level->getBlockAt(_x + 1, _y);

		if (block == NULL) {
			level->moveBlock(_x, _y, _x + 1, _y);
			return true;
		}

		return false;
	};

	/**
	 * Drops or raises the block depending on gravity.  If the block is sat on
	 * a hot block it explodes.
	 */
	virtual void onIterate() {
		if (_game->isGravityInverted()) {

			// If we're sat on a hot tile then explode
			explodeIfHotBlockAt(_x, _y - 1);

			if (_isExploding) return;

			raise();

		} else {
			explodeIfHotBlockAt(_x, _y + 1);

			if (_isExploding) return;

			drop();
		}
	};

	/**
	 * Causes the block to explode if the block at the specified co-ordinates
	 * is hot.
	 * @param x The x co-ordinate to check for a hot block.
	 * @param y The y co-ordinate to check for a hot block.
	 */
	void explodeIfHotBlockAt(s32 x, s32 y) {

		BlockBase* block = _game->getLevel()->getBlockAt(x, y);

		if (block == NULL) return;

		if (block->isHot()) explode();
	};

private:
	BoulderBmp _bmp;						/**< Static bitmap. */
	BoulderExplodeBmp1 _explodingBmp1;		/**< First explosion bitmap. */
	BoulderExplodeBmp2 _explodingBmp2;		/**< Second explosion bitmap. */
	BoulderExplodeBmp3 _explodingBmp3;		/**< Third explosion bitmap. */
	BoulderExplodeBmp4 _explodingBmp4;		/**< Fourth explosion bitmap. */
	BoulderExplodeBmp5 _explodingBmp5;		/**< Fifth explosion bitmap. */
	BoulderExplodeBmp6 _explodingBmp6;		/**< Sixth explosion bitmap. */
	BoulderExplodeBmp7 _explodingBmp7;		/**< Seventh explosion bitmap. */
};

#endif
