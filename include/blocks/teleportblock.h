#ifndef _TELEPORT_BLOCK_H_
#define _TELEPORT_BLOCK_H_

#include <graphics.h>
#include <bitmap.h>

#include "game.h"
#include "blockbase.h"
#include "constants.h"
#include "teleportbmp1.h"
#include "teleportbmp2.h"
#include "teleportbmp3.h"
#include "teleportbmp4.h"
#include "teleportbmp5.h"
#include "teleportbmp6.h"
#include "teleportbmp7.h"
#include "teleportbmp8.h"
#include "teleportbmp9.h"
#include "teleportbmp10.h"
#include "teleportbmp11.h"
#include "teleportbmp12.h"

/**
 * Collecting a teleport block moves the player to another teleport block.
 */
class TeleportBlock : public BlockBase {
public:

	/**
	 * Constructor.
	 * @param x The x co-ordinate within the level map of the block.
	 * @param y The y co-ordinate within tne level map of the block.
	 * @param game Pointer to the game that contains the block.
	 */
	TeleportBlock(s32 x, s32 y, Game* game) : BlockBase(x, y, game) {
		_animation->addFrame(&_bmp1, 0);
		_animation->addFrame(&_bmp2, 0);
		_animation->addFrame(&_bmp3, 0);
		_animation->addFrame(&_bmp4, 0);
		_animation->addFrame(&_bmp5, 0);
		_animation->addFrame(&_bmp6, 0);
		_animation->addFrame(&_bmp7, 0);
		_animation->addFrame(&_bmp8, 0);
		_animation->addFrame(&_bmp9, 0);
		_animation->addFrame(&_bmp10, 0);
		_animation->addFrame(&_bmp11, 0);
		_animation->addFrame(&_bmp12, 0);
		_animation->play();
	};

	/**
	 * Destructor.
	 */
	~TeleportBlock() {};

	/**
	 * Moves the player to the linked teleport block and removes both blocks
	 * from the level.
	 * @return True.
	 */
	virtual bool pushUp() {
		// TODO: Move player to the linked teleport block
		_game->getLevel()->removeBlockAt(_x, _y);
		return true;
	};

	/**
	 * Moves the player to the linked teleport block and removes both blocks
	 * from the level.
	 * @return True.
	 */
	virtual bool pushDown() {
		// TODO: Move player to the linked teleport block
		_game->getLevel()->removeBlockAt(_x, _y);
		return true;
	};

	/**
	 * Moves the player to the linked teleport block and removes both blocks
	 * from the level.
	 * @return True.
	 */
	virtual bool pushLeft() {
		// TODO: Move player to the linked teleport block
		_game->getLevel()->removeBlockAt(_x, _y);
		return true;
	};

	/**
	 * Moves the player to the linked teleport block and removes both blocks
	 * from the level.
	 * @return True.
	 */
	virtual bool pushRight() {
		// TODO: Move player to the linked teleport block
		_game->getLevel()->removeBlockAt(_x, _y);
		return true;
	};

private:
	TeleportBmp1 _bmp1;				/**< The first animation frame. */
	TeleportBmp1 _bmp2;				/**< The second animation frame. */
	TeleportBmp1 _bmp3;				/**< The third animation frame. */
	TeleportBmp1 _bmp4;				/**< The fourth animation frame. */
	TeleportBmp1 _bmp5;				/**< The fifth animation frame. */
	TeleportBmp1 _bmp6;				/**< The sixth animation frame. */
	TeleportBmp1 _bmp7;				/**< The seventh animation frame. */
	TeleportBmp1 _bmp8;				/**< The eighth animation frame. */
	TeleportBmp1 _bmp9;				/**< The ninth animation frame. */
	TeleportBmp1 _bmp10;			/**< The tenth animation frame. */
	TeleportBmp1 _bmp11;			/**< The eleventh animation frame. */
	TeleportBmp1 _bmp12;			/**< The twelth animation frame. */
};

#endif
