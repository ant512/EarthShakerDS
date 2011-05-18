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
#include "bubblemapbmp.h"
#include "constants.h"

/**
 * Bubbles can be pushed around in any direction.  They can dig other blocks, so
 * it is possible to push them through soil.  Pushing them onto hot blocks such
 * as fire causes the bubble and the hot block to explode.
 */
class BubbleBlock : public BlockBase {
public:

	/**
	 * Constructor.
	 * @param x The x co-ordinate within the level map of the block.
	 * @param y The y co-ordinate within tne level map of the block.
	 * @param game Pointer to the game that contains the block.
	 */
	BubbleBlock(s32 x, s32 y, Game* game) : BlockBase(x, y, game) {
		_animation->addFrame(&_bmp1, 0);
		_animation->addFrame(&_bmp2, 0);
		_animation->addFrame(&_bmp3, 0);
		_animation->addFrame(&_bmp4, 0);
		_animation->play();

		_mapBitmap = new BubbleMapBmp();
	};

	/**
	 * Destructor.
	 */
	~BubbleBlock() {
		delete _mapBitmap;
	};

	/**
	 * If there is no block above the bubble, it moves upwards.  If the block
	 * above the bubble is hot, both the bubble and the hot block are exploded.
	 * Otherwise, the bubble tries to dig the block.  In the case of soil this
	 * works.  If the block becomes vacated, the bubble moves into the block.
	 * @return True if the bubble moved; false if not.
	 */
	bool pushUp() {
		if (_y == 0) return false;
		if (_isExploding) return false;

		if (_isOddIteration != _game->isOddIteration()) return false;
		_isOddIteration = !_isOddIteration;

		LevelBase* level = _game->getLevel();
		BlockBase* block = level->getBlockAt(_x, _y - 1);

		if (block != NULL) {

			// If we're pushing the bubble onto fire, explode this and the fire
			// block
			if (block->isHot()) {
				block->explode();
				explode();

				_game->addScore(FIRE_EXTINGUISH_SCORE);

				return false;
			}

			// Try to push the bubble onto the next block
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

	/**
	 * If there is no block below the bubble, it moves downwards.  If the block
	 * below the bubble is hot, both the bubble and the hot block are exploded.
	 * Otherwise, the bubble tries to dig the block.  In the case of soil this
	 * works.  If the block becomes vacated, the bubble moves into the block.
	 * @return True if the bubble moved; false if not.
	 */
	bool pushDown() {
		if (_isExploding) return false;

		LevelBase* level = _game->getLevel();

		if (_y == level->getHeight() - 1) return false;

		if (_isOddIteration != _game->isOddIteration()) return false;
		_isOddIteration = !_isOddIteration;

		BlockBase* block = level->getBlockAt(_x, _y + 1);

		if (block != NULL) {

			// If we're pushing the bubble onto fire, explode this and the fire
			// block
			if (block->isHot()) {
				block->explode();
				explode();

				_game->addScore(FIRE_EXTINGUISH_SCORE);

				return false;
			}

			// Try to push the bubble onto the next block
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

	/**
	 * If there is no block to the left of the bubble, it moves leftwards.  If
	 * the block to the left of the bubble is hot, both the bubble and the hot
	 * block are exploded.  Otherwise, the bubble tries to dig the block.  In
	 * the case of soil this works.  If the block becomes vacated, the bubble
	 * moves into the block.
	 * @return True if the bubble moved; false if not.
	 */
	bool pushLeft() {
		if (_x == 0) return false;
		if (_isExploding) return false;

		if (_isOddIteration != _game->isOddIteration()) return false;
		_isOddIteration = !_isOddIteration;

		LevelBase* level = _game->getLevel();
		BlockBase* block = level->getBlockAt(_x - 1, _y);

		if (block != NULL) {

			// If we're pushing the bubble onto fire, explode this and the fire
			// block
			if (block->isHot()) {
				block->explode();
				explode();

				_game->addScore(FIRE_EXTINGUISH_SCORE);

				return false;
			}

			// Try to push the bubble onto the next block
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

	/**
	 * If there is no block to the right of the bubble, it moves rightwards.  If
	 * the block to the right of the bubble is hot, both the bubble and the hot
	 * block are exploded.  Otherwise, the bubble tries to dig the block.  In
	 * the case of soil this works.  If the block becomes vacated, the bubble
	 * moves into the block.
	 * @return True if the bubble moved; false if not.
	 */
	bool pushRight() {
		if (_isExploding) return false;
		
		LevelBase* level = _game->getLevel();

		if (_x == level->getWidth() - 1) return false;

		if (_isOddIteration != _game->isOddIteration()) return false;
		_isOddIteration = !_isOddIteration;

		BlockBase* block = level->getBlockAt(_x + 1, _y);

		if (block != NULL) {

			// If we're pushing the bubble onto fire, explode this and the fire
			// block
			if (block->isHot()) {
				block->explode();
				explode();

				_game->addScore(FIRE_EXTINGUISH_SCORE);
				
				return false;
			}

			// Try to push the bubble onto the next block
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
	BubbleBmp1 _bmp1;		/**< First animation bitmap. */
	BubbleBmp2 _bmp2;		/**< Second animation bitmap. */
	BubbleBmp3 _bmp3;		/**< Third animation bitmap. */
	BubbleBmp4 _bmp4;		/**< Fourth animation bitmap. */

private:
	
	/**
	 * Plays explode sound.
	 */
	void onExplode() {
		SoundPlayer::playBubbleExplode();
	};
};

#endif
