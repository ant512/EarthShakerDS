#ifndef _DOOR_BLOCK_H_
#define _DOOR_BLOCK_H_

#include <bitmap.h>
#include <bitmapbase.h>
#include <graphics.h>

#include "blockbase.h"
#include "game.h"

/**
 * Door blocks are static.  They become active when all diamonds in a level are
 * collected.  Touching an active door completes the level.
 */
class DoorBlock : public BlockBase {
public:

	/**
	 * Constructor.
	 * @param x The x co-ordinate within the level map of the block.
	 * @param y The y co-ordinate within tne level map of the block.
	 * @param game Pointer to the game that contains the block.
	 */
	DoorBlock(s32 x, s32 y, Game* game, WoopsiGfx::BitmapBase* bitmap) : BlockBase(x, y, game) {
		_animation->addFrame(bitmap, 0);

		_explodingAnimation->addFrame(BitmapServer::getRedDoorBmp(), 0);
		_explodingAnimation->addFrame(BitmapServer::getGreenDoorBmp(), 0);
		_explodingAnimation->addFrame(BitmapServer::getBlueDoorBmp(), 0);
		_explodingAnimation->addFrame(BitmapServer::getCyanDoorBmp(), 0);
		_explodingAnimation->addFrame(BitmapServer::getMagentaDoorBmp(), 0);
		_explodingAnimation->setLoopType(WoopsiGfx::Animation::ANIMATION_LOOPTYPE_LOOP);
	};

	/**
	 * Destructor.
	 */
	~DoorBlock() {};

	/**
	 * Explodes the door when there are no diamonds left to collect.  This
	 * causes the door to start its colour cycling explosion animation.  We're
	 * abusing the explosion system somewhat...
	 */
	void onIterate() {
		if (_game->getRemainingDiamonds() == 0) explode();
	};

	/**
	 * Moves to the next level if all diamonds have been collected.
	 * @return True if the block moves; false if not.
	 */
	bool pushLeft() {

		if (_game->getRemainingDiamonds() > 0) return false;

		_game->endLevel();

		return false;
	};

	/**
	 * Moves to the next level if all diamonds have been collected.
	 * @return True if the block moves; false if not.
	 */
	bool pushRight() {

		if (_game->getRemainingDiamonds() > 0) return false;

		_game->endLevel();

		return false;
	};

	/**
	 * Moves to the next level if all diamonds have been collected.
	 * @return True if the block moves; false if not.
	 */
	bool pushUp() {

		if (_game->getRemainingDiamonds() > 0) return false;

		_game->endLevel();

		return false;
	};

		/**
	 * Moves to the next level if all diamonds have been collected.
	 * @return True if the block moves; false if not.
	 */
	bool pushDown() {

		if (_game->getRemainingDiamonds() > 0) return false;

		_game->endLevel();

		return false;
	};
};

#endif
