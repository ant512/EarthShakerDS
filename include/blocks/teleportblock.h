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

		// 1, 2, 3, 4, 3, 2, 5, 6, 7, 8, 7, 6
		_animation->addFrame(&_bmp1, 0);
		_animation->addFrame(&_bmp2, 0);
		_animation->addFrame(&_bmp3, 0);
		_animation->addFrame(&_bmp4, 0);
		_animation->addFrame(&_bmp3, 0);
		_animation->addFrame(&_bmp2, 0);
		_animation->addFrame(&_bmp5, 0);
		_animation->addFrame(&_bmp6, 0);
		_animation->addFrame(&_bmp7, 0);
		_animation->addFrame(&_bmp8, 0);
		_animation->addFrame(&_bmp7, 0);
		_animation->addFrame(&_bmp6, 0);
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
	bool pushUp() {

		// Teleport only works if it has been connected up properly
		if (_link != NULL) {

			// Teleport the player
			BlockBase* player = _game->getPlayerBlock();
			LevelBase* level = _game->getLevel();

			level->moveBlock(player->getX(), player->getY(), _link->getX(), _link->getY());
		}

		// Remove this block from the level
		_game->getLevel()->removeBlockAt(_x, _y);
		return false;
	};

	/**
	 * Moves the player to the linked teleport block and removes both blocks
	 * from the level.
	 * @return False.
	 */
	bool pushDown() {

		// Teleport only works if it has been connected up properly
		if (_link != NULL) {

			// Teleport the player
			BlockBase* player = _game->getPlayerBlock();
			LevelBase* level = _game->getLevel();

			level->moveBlock(player->getX(), player->getY(), _link->getX(), _link->getY());
		}

		// Remove this block from the level
		_game->getLevel()->removeBlockAt(_x, _y);
		return false;
	};

	/**
	 * Moves the player to the linked teleport block and removes both blocks
	 * from the level.
	 * @return True.
	 */
	bool pushLeft() {

		// Teleport only works if it has been connected up properly
		if (_link != NULL) {

			// Teleport the player
			BlockBase* player = _game->getPlayerBlock();
			LevelBase* level = _game->getLevel();

			level->moveBlock(player->getX(), player->getY(), _link->getX(), _link->getY());
		}

		// Remove this block from the level
		return false;
	};

	/**
	 * Moves the player to the linked teleport block and removes both blocks
	 * from the level.
	 * @return True.
	 */
	bool pushRight() {

		// Teleport only works if it has been connected up properly
		if (_link != NULL) {

			// Teleport the player
			BlockBase* player = _game->getPlayerBlock();
			LevelBase* level = _game->getLevel();

			level->moveBlock(player->getX(), player->getY(), _link->getX(), _link->getY());
		}

		// Remove this block from the level
		_game->getLevel()->removeBlockAt(_x, _y);
		return false;
	};

	/**
	 * Set the remote teleport block that this block links to.
	 * @param link The block that this teleport links to.
	 */
	void setLink(TeleportBlock* link) {
		_link = link;
	};

private:
	// 1, 5, 2, 4, 2, 5, 7, 8, 9, 10, 9, 8
	TeleportBmp1 _bmp1;			/**< The first animation frame. */
	TeleportBmp5 _bmp2;			/**< The second animation frame. */
	TeleportBmp2 _bmp3;			/**< The third animation frame. */
	TeleportBmp4 _bmp4;			/**< The fourth animation frame. */
	TeleportBmp7 _bmp5;			/**< The fifth animation frame. */
	TeleportBmp8 _bmp6;			/**< The sixth animation frame. */
	TeleportBmp9 _bmp7;			/**< The seventh animation frame. */
	TeleportBmp10 _bmp8;		/**< The eighth animation frame. */

	TeleportBlock* _link;		/**< The teleport that this block links to. */
};

#endif
