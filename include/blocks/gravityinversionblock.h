#ifndef _GRAVITY_INVERSION_BLOCK_H_
#define _GRAVITY_INVERSION_BLOCK_H_

#include <graphics.h>
#include <bitmap.h>

#include "game.h"
#include "blockbase.h"
#include "constants.h"
#include "gravityinversionbmp1.h"
#include "gravityinversionbmp2.h"
#include "gravityinversionbmp3.h"
#include "gravityinversionmapbmp.h"

/**
 * Collecting a gravity inversion block switches gravity in the game so that
 * blocks fall upwards instead of downwards.
 */
class GravityInversionBlock : public BlockBase {
public:

	/**
	 * Constructor.
	 * @param x The x co-ordinate within the level map of the block.
	 * @param y The y co-ordinate within tne level map of the block.
	 * @param game Pointer to the game that contains the block.
	 */
	GravityInversionBlock(s32 x, s32 y, Game* game) : BlockBase(x, y, game) {
		_isHeavy = true;
		_isHeavyEnoughToKill = true;

		_animation->setLoopType(WoopsiGfx::Animation::ANIMATION_LOOPTYPE_PINGPONG);
		_animation->addFrame(&_bmp1, 0);
		_animation->addFrame(&_bmp2, 0);
		_animation->addFrame(&_bmp3, 0);
		_animation->play();

		_mapBitmap = new GravityInversionMapBmp();
	};

	/**
	 * Destructor.
	 */
	~GravityInversionBlock() {
		delete _mapBitmap;
	};

	/**
	 * Inverts gravity and removes the block from the level.
	 * @return True.
	 */
	bool pushUp() {
		_game->addScore(GRAVITY_INVERSION_SCORE);
		_game->invertGravity();
		_game->getLevel()->removeBlockAt(_x, _y);
		return true;
	};

	/**
	 * Inverts gravity and removes the block from the level.
	 * @return True.
	 */
	bool pushDown() {
		_game->addScore(GRAVITY_INVERSION_SCORE);
		_game->invertGravity();
		_game->getLevel()->removeBlockAt(_x, _y);
		return true;
	};

	/**
	 * Inverts gravity and removes the block from the level.
	 * @return True.
	 */
	bool pushLeft() {
		_game->addScore(GRAVITY_INVERSION_SCORE);
		_game->invertGravity();
		_game->getLevel()->removeBlockAt(_x, _y);
		return true;
	};

	/**
	 * Inverts gravity and removes the block from the level.
	 * @return True.
	 */
	bool pushRight() {
		_game->addScore(GRAVITY_INVERSION_SCORE);
		_game->invertGravity();
		_game->getLevel()->removeBlockAt(_x, _y);
		return true;
	};

	/**
	 * Pushes this block if possible.
	 * @return True if the block moves; false if not.
	 */
	bool pokeUp() {
		return pushUp();
	};

	/**
	 * Pushes this block if possible.
	 * @return True if the block moves; false if not.
	 */
	bool pokeDown() {
		return pushDown();
	};

	/**
	 * Pushes this block if possible.
	 * @return True if the block moves; false if not.
	 */
	bool pokeLeft() {
		return pushLeft();
	};

	/**
	 * Pushes this block if possible.
	 * @return True if the block moves; false if not.
	 */
	bool pokeRight() {
		return pushRight();
	};

private:
	GravityInversionBmp1 _bmp1;		/**< The first animation frame. */
	GravityInversionBmp2 _bmp2;		/**< The second animation frame. */
	GravityInversionBmp3 _bmp3;		/**< The third animation frame. */
};

#endif
