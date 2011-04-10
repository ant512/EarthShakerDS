#ifndef _BUBBLE_BLOCK_H_
#define _BUBBLE_BLOCK_H_

#include <graphics.h>
#include <bitmap.h>

#include "game.h"
#include "blockbase.h"
#include "bubblebmp1.h"
#include "bubblebmp2.h"
#include "bubblebmp3.h"
#include "bubblebmp4.h"

class BubbleBlock : public BlockBase {
public:
	BubbleBlock(s32 x, s32 y, Game* game) : BlockBase(x, y, game) {
		_isSlippy = true;
		
		_animation->addFrame(&_bmp1, 0);
		_animation->addFrame(&_bmp2, 0);
		_animation->addFrame(&_bmp3, 0);
		_animation->addFrame(&_bmp4, 0);
		_animation->play();
	};

	~BubbleBlock() {};

	virtual bool applyUpwardForce() {
		if (_y == 0) return false;

		LevelBase* level = _game->getLevel();
		BlockBase* block = level->getBlockAt(_x, _y - 1);

		// Try to push the bubble onto the next block
		if (block != NULL) {
			if (block->digFromLeft()) {
				level->moveBlock(_x, _y, _x, _y - 1);
				return true;
			}

			return false;
		}

		// Next block is empty, so just replace it
		level->moveBlock(_x, _y, _x, _y - 1);
		return true;
	};

	virtual bool applyDownwardForce() {
		LevelBase* level = _game->getLevel();

		if (_y == level->getHeight() - 1) return false;

		BlockBase* block = level->getBlockAt(_x, _y + 1);

		// Try to push the bubble onto the next block
		if (block != NULL) {
			if (block->digFromLeft()) {
				level->moveBlock(_x, _y, _x, _y + 1);
				return true;
			}

			return false;
		}

		// Next block is empty, so just replace it
		level->moveBlock(_x, _y, _x, _y + 1);
		return true;
	};

	virtual bool applyLeftwardForce() {
		if (_x == 0) return false;

		LevelBase* level = _game->getLevel();
		BlockBase* block = level->getBlockAt(_x - 1, _y);

		// Try to push the bubble onto the next block
		if (block != NULL) {
			if (block->digFromLeft()) {
				level->moveBlock(_x, _y, _x - 1, _y);
				return true;
			}

			return false;
		}

		// Next block is empty, so just replace it
		level->moveBlock(_x, _y, _x - 1, _y);
		return true;
	};

	virtual bool applyRightwardForce() {
		LevelBase* level = _game->getLevel();

		if (_x == level->getWidth() - 1) return false;

		BlockBase* block = level->getBlockAt(_x + 1, _y);

		// Try to push the bubble onto the next block
		if (block != NULL) {
			if (block->digFromRight()) {
				level->moveBlock(_x, _y, _x + 1, _y);
				return true;
			}

			return false;
		}

		// Next block is empty, so just replace it
		level->moveBlock(_x, _y, _x + 1, _y);
		return true;
	};

private:
	BubbleBmp1 _bmp1;
	BubbleBmp2 _bmp2;
	BubbleBmp3 _bmp3;
	BubbleBmp4 _bmp4;
};

#endif
