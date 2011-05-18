#ifndef _DIAMOND_BLOCK_H_
#define _DIAMOND_BLOCK_H_

#include <graphics.h>
#include <bitmap.h>

#include "blockbase.h"
#include "constants.h"
#include "diamondbmp1.h"
#include "diamondbmp2.h"
#include "diamondbmp3.h"
#include "diamondbmp4.h"
#include "diamondmapbmp.h"
#include "game.h"
#include "soundplayer.h"

/**
 * Diamonds can be collected for points.  They fall if not sitting on anything.
 * Collecting diamonds is the object of the game.
 */
class DiamondBlock : public BlockBase {
public:

	/**
	 * Constructor.
	 * @param x The x co-ordinate within the level map of the block.
	 * @param y The y co-ordinate within tne level map of the block.
	 * @param game Pointer to the game that contains the block.
	 */
	DiamondBlock(s32 x, s32 y, Game* game) : BlockBase(x, y, game) {
		_isHeavy = true;
		_isHeavyEnoughToKill = true;

		_animation->setLoopType(WoopsiGfx::Animation::ANIMATION_LOOPTYPE_PINGPONG);
		_animation->addFrame(&_bmp1, 0);
		_animation->addFrame(&_bmp2, 0);
		_animation->addFrame(&_bmp3, 0);
		_animation->addFrame(&_bmp4, 0);
		_animation->play();

		_mapBitmap = new DiamondMapBmp();
	};

	/**
	 * Destructor.
	 */
	~DiamondBlock() {
		delete _mapBitmap;
	};

	/**
	 * Adds to the player's score and removes the block from the level.
	 * @return True.
	 */
	bool pushUp() {
		_game->addScore(DIAMOND_SCORE);
		_game->increaseCollectedDiamonds();
		_game->getLevel()->removeBlockAt(_x, _y);
		SoundPlayer::playDiamondCollect();
		return true;
	};

	/**
	 * Adds to the player's score and removes the block from the level.
	 * @return True.
	 */
	bool pushDown() {
		_game->addScore(DIAMOND_SCORE);
		_game->increaseCollectedDiamonds();
		_game->getLevel()->removeBlockAt(_x, _y);
		SoundPlayer::playDiamondCollect();
		return true;
	};

	/**
	 * Adds to the player's score and removes the block from the level.
	 * @return True.
	 */
	bool pushLeft() {
		_game->addScore(DIAMOND_SCORE);
		_game->increaseCollectedDiamonds();
		_game->getLevel()->removeBlockAt(_x, _y);
		SoundPlayer::playDiamondCollect();
		return true;
	};

	/**
	 * Adds to the player's score and removes the block from the level.
	 * @return True.
	 */
	bool pushRight() {
		_game->addScore(DIAMOND_SCORE);
		_game->increaseCollectedDiamonds();
		_game->getLevel()->removeBlockAt(_x, _y);
		SoundPlayer::playDiamondCollect();
		return true;
	};

private:
	DiamondBmp1 _bmp1;			/**< First animation bitmap. */
	DiamondBmp2 _bmp2;			/**< Second animation bitmap. */
	DiamondBmp3 _bmp3;			/**< Third animation bitmap. */
	DiamondBmp4 _bmp4;			/**< Fourth animation bitmap. */
};

#endif
