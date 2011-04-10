#ifndef _BOULDER_BLOCK_H_
#define _BOULDER_BLOCK_H_

#include <graphics.h>
#include <bitmap.h>

#include "game.h"
#include "blockbase.h"
#include "playerblock.h"
#include "boulderbmp.h"

class BoulderBlock : public HeavyBlockBase {
public:
	BoulderBlock(s32 x, s32 y, Game* game) : HeavyBlockBase(x, y, game) {
		_isSlippy = true;	// Boulders are born slippy

		_animation->addFrame(&_bmp, 0);
	};

	~BoulderBlock() {};

	/**
	 * Pushes this block to the left if the block to the left is empty.
	 * @return True if the block moves; false if not.
	 */
	virtual bool applyLeftwardForce() {
		if (_x == 0) return false;

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

	virtual void iterate() {
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

private:
	BoulderBmp _bmp;
};

#endif
