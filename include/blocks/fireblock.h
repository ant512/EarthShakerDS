#ifndef _FIRE_BLOCK_H_
#define _FIRE_BLOCK_H_

#include <graphics.h>
#include <bitmap.h>

#include "gamesession.h"
#include "blockbase.h"
#include "firebmp1.h"
#include "firebmp2.h"
#include "firebmp3.h"
#include "firebmp4.h"
#include "fireexplodebmp1.h"
#include "fireexplodebmp2.h"
#include "fireexplodebmp3.h"
#include "fireexplodebmp4.h"
#include "firemapbmp.h"

/**
 * Fire explodes boulders and bubbles (which also extinguish it).  It falls if
 * not sitting on anything.  Touching fire will kill the player.
 */
class FireBlock : public BlockBase {
public:

	/**
	 * Constructor.
	 * @param x The x co-ordinate within the level map of the block.
	 * @param y The y co-ordinate within tne level map of the block.
	 * @param game Pointer to the game that contains the block.
	 */
	FireBlock(s32 x, s32 y, GameSession* game) : BlockBase(x, y, game) {
		_isHot = true;
		_isHeavy = true;
		_isHeavyEnoughToKill = true;
		
		_animation->addFrame(&_bmp1, 0);
		_animation->addFrame(&_bmp2, 0);
		_animation->addFrame(&_bmp3, 0);
		_animation->addFrame(&_bmp4, 0);
		_animation->play();

		_explodingAnimation->addFrame(&_explodeBmp1, 0);
		_explodingAnimation->addFrame(&_explodeBmp2, 0);
		_explodingAnimation->addFrame(&_explodeBmp3, 0);
		_explodingAnimation->addFrame(&_explodeBmp4, 0);

		_mapBitmap = new FireMapBmp();
	};

	/**
	 * Destructor.
	 */
	~FireBlock() {
		delete _mapBitmap;
	};

	/**
	 * Explodes the block pushing this and removes this block from the level.
	 */
	bool pushLeft() {
		if (_isExploding) return false;

		// Get the block pushing this
		BlockBase* block = _game->getLevel()->getBlockAt(_x + 1, _y);

		if (block == NULL) return false;
		block->explode();

		_game->getLevel()->removeBlockAt(_x, _y);

		return true;
	};

	/**
	 * Explodes the block pushing this and removes this block from the level.
	 * @return True if the fire is removed from the level.
	 */
	bool pushRight() {
		if (_isExploding) return false;

		// Get the block pushing this
		BlockBase* block = _game->getLevel()->getBlockAt(_x - 1, _y);

		if (block == NULL) return false;
		block->explode();

		_game->getLevel()->removeBlockAt(_x, _y);

		return true;
	};

	/**
	 * Explodes the block pushing this and removes this block from the level.
	 * @return True if the fire is removed from the level.
	 */
	bool pushUp() {
		if (_isExploding) return false;

		// Get the block pushing this
		BlockBase* block = _game->getLevel()->getBlockAt(_x, _y + 1);

		if (block == NULL) return false;
		block->explode();

		_game->getLevel()->removeBlockAt(_x, _y);

		return true;
	};

	/**
	 * Explodes the block pushing this and removes this block from the level.
	 * @return True if the fire is removed from the level.
	 */
	bool pushDown() {
		if (_isExploding) return false;
		
		// Get the block pushing this
		BlockBase* block = _game->getLevel()->getBlockAt(_x, _y - 1);

		if (block == NULL) return false;
		block->explode();

		_game->getLevel()->removeBlockAt(_x, _y);

		return true;
	};

private:
	FireBmp1 _bmp1;					/**< First animation bitmap. */
	FireBmp2 _bmp2;					/**< Second animation bitmap. */
	FireBmp3 _bmp3;					/**< Third animation bitmap. */
	FireBmp4 _bmp4;					/**< Fourth animation bitmap. */

	FireExplodeBmp1 _explodeBmp1;	/**< First exploding bitmap. */
	FireExplodeBmp2 _explodeBmp2;	/**< Second exploding bitmap. */
	FireExplodeBmp3 _explodeBmp3;	/**< Third exploding bitmap. */
	FireExplodeBmp4 _explodeBmp4;	/**< Fourth exploding bitmap. */
};

#endif
