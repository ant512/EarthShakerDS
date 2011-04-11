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

class BoulderBlock : public HeavyBlockBase {
public:
	BoulderBlock(s32 x, s32 y, Game* game) : HeavyBlockBase(x, y, game) {
		_isSlippy = true;	// Boulders are born slippy

		_animation->addFrame(&_bmp, 0);

		_explodingAnimation->addFrame(&_explodingBmp1, 0);
		_explodingAnimation->addFrame(&_explodingBmp2, 0);
		_explodingAnimation->addFrame(&_explodingBmp3, 0);
		_explodingAnimation->addFrame(&_explodingBmp4, 0);
		_explodingAnimation->addFrame(&_explodingBmp5, 0);
		_explodingAnimation->addFrame(&_explodingBmp6, 0);
		_explodingAnimation->addFrame(&_explodingBmp7, 0);
	};

	~BoulderBlock() {};

	/**
	 * Pushes this block to the left if the block to the left is empty.
	 * @return True if the block moves; false if not.
	 */
	virtual bool applyLeftwardForce() {
		if (_x == 0) return false;
		if (_isExploding) return false;

		LevelBase* level = _game->getLevel();
		BlockBase* block = level->getBlockAt(_x - 1, _y);

		// Check if we're pushing the block into fire
		if (block != NULL) {
			if (block->isHot()) {
				explode();
				return false;
			}
		} else {
			level->moveBlock(_x, _y, _x - 1, _y);
			return true;
		}

		return false;
	};

	/**
	 * Pushes this block to the right if the block to the left is empty.
	 * @return True if the block moves; false if not.
	 */
	virtual bool applyRightwardForce() {
		if (_isExploding) return false;

		LevelBase* level = _game->getLevel();

		if (_x == level->getWidth() - 1) return false;

		BlockBase* block = level->getBlockAt(_x + 1, _y);

		// Check if we're pushing the block into fire
		if (block != NULL) {
			if (block->isHot()) {
				explode();
				return false;
			}
		} else {
			level->moveBlock(_x, _y, _x + 1, _y);
			return true;
		}

		return false;
	};

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

	void explodeIfHotBlockAt(s32 x, s32 y) {

		if (x < 0) return;
		if (y < 0) return;
		if (x > _game->getLevel()->getWidth() - 1) return;
		if (y > _game->getLevel()->getHeight() - 1) return;

		BlockBase* block = _game->getLevel()->getBlockAt(x, y);

		if (block == NULL) return;

		if (block->isHot()) explode();
	};

private:
	BoulderBmp _bmp;
	BoulderExplodeBmp1 _explodingBmp1;
	BoulderExplodeBmp2 _explodingBmp2;
	BoulderExplodeBmp3 _explodingBmp3;
	BoulderExplodeBmp4 _explodingBmp4;
	BoulderExplodeBmp5 _explodingBmp5;
	BoulderExplodeBmp6 _explodingBmp6;
	BoulderExplodeBmp7 _explodingBmp7;
};

#endif
