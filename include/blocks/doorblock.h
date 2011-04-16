#ifndef _DOOR_BLOCK_H_
#define _DOOR_BLOCK_H_

#include <graphics.h>
#include <bitmap.h>
#include <game.h>

#include "blockbase.h"

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
	DoorBlock(s32 x, s32 y, Game* game) : BlockBase(x, y, game) {
		_animation->addFrame(BitmapServer::getRedDoorBmp(), 0);
		_animation->addFrame(BitmapServer::getGreenDoorBmp(), 0);
		_animation->addFrame(BitmapServer::getBlueDoorBmp(), 0);
		_animation->addFrame(BitmapServer::getCyanDoorBmp(), 0);
		_animation->addFrame(BitmapServer::getMagentaDoorBmp(), 0);
	};

	/**
	 * Destructor.
	 */
	~DoorBlock() {};

	/**
	 * Starts the door animation when there are no diamonds left to collect.
	 */
	void onIterate() {
		if (_game->getRemainingDiamonds() == 0) _animation->play();
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
