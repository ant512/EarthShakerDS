#ifndef _TELEPORT_BLOCK_H_
#define _TELEPORT_BLOCK_H_

#include <graphics.h>
#include <bitmap.h>

#include "game.h"
#include "blockbase.h"
#include "constants.h"
#include "soundplayer.h"
#include "teleportbmp1.h"
#include "teleportbmp2.h"
#include "teleportbmp3.h"
#include "teleportbmp4.h"
#include "teleportbmp5.h"
#include "teleportbmp6.h"
#include "teleportbmp7.h"
#include "teleportbmp8.h"
#include "teleportmapbmp.h"

/**
 * Collecting a teleport block moves the player to another teleport block.
 */
class TeleportBlock : public BlockBase {
public:

	static const s32 TELEPORT_TIME = 50;

	/**
	 * Constructor.
	 * @param x The x co-ordinate within the level map of the block.
	 * @param y The y co-ordinate within tne level map of the block.
	 * @param game Pointer to the game that contains the block.
	 */
	TeleportBlock(s32 x, s32 y, Game* game) : BlockBase(x, y, game) {
		_animation->addFrame(&_bmp1, 0);
		_animation->addFrame(&_bmp4, 0);
		_animation->addFrame(&_bmp2, 0);
		_animation->addFrame(&_bmp3, 0);
		_animation->addFrame(&_bmp2, 0);
		_animation->addFrame(&_bmp4, 0);
		_animation->addFrame(&_bmp5, 0);
		_animation->addFrame(&_bmp6, 0);
		_animation->addFrame(&_bmp7, 0);
		_animation->addFrame(&_bmp8, 0);
		_animation->addFrame(&_bmp7, 0);
		_animation->addFrame(&_bmp6, 0);
		_animation->play();

		_mapBitmap = new TeleportMapBmp();
	};

	/**
	 * Destructor.
	 */
	~TeleportBlock() {
		delete _mapBitmap;
	};

	/**
	 * Moves the player to the next teleport block and removes both blocks
	 * from the level.
	 * @return True.
	 */
	bool pushUp() {
		return teleportPlayer();
	};

	/**
	 * Moves the player to the next teleport block and removes both blocks
	 * from the level.
	 * @return False.
	 */
	bool pushDown() {
		return teleportPlayer();
	};

	/**
	 * Moves the player to the next teleport block and removes both blocks
	 * from the level.
	 * @return True.
	 */
	bool pushLeft() {
		return teleportPlayer();
	};

	/**
	 * Moves the player to the next teleport block and removes both blocks
	 * from the level.
	 * @return True.
	 */
	bool pushRight() {
		return teleportPlayer();
	};

private:
	TeleportBmp1 _bmp1;			/**< The first animation frame. */
	TeleportBmp2 _bmp2;			/**< The second animation frame. */
	TeleportBmp3 _bmp3;			/**< The third animation frame. */
	TeleportBmp4 _bmp4;			/**< The fourth animation frame. */
	TeleportBmp5 _bmp5;			/**< The fifth animation frame. */
	TeleportBmp6 _bmp6;			/**< The sixth animation frame. */
	TeleportBmp7 _bmp7;			/**< The seventh animation frame. */
	TeleportBmp8 _bmp8;			/**< The eighth animation frame. */

	/**
	 * Finds the next teleport block in the level.  Search starts from the top-
	 * left and proceeds to the bottom-right in rows.
	 * @return The next teleport block in the level, or NULL if none is found.
	 */
	TeleportBlock* getNextTeleport() {
		Level* level = _game->getLevel();
		TeleportBlock* teleport = NULL;

		for (s32 y = 0; y < level->getHeight(); ++y) {
			for (s32 x = 0; x < level->getWidth(); ++x) {

				// Yuck - RTTI, but there's no practical way around this
				teleport = dynamic_cast<TeleportBlock*>(level->getBlockAt(x, y));

				if (teleport != NULL) {
					if (teleport != this) {
						return teleport;
					}
				}
			}
		}

		return NULL;
	}

	/**
	 * Teleports the player from this block to the next teleporter.
	 */
	bool teleportPlayer() {
		TeleportBlock* destination = getNextTeleport();

		// Teleport only works if there is an end point
		if (destination == NULL) return false;

		// Teleport the player
		BlockBase* player = _game->getPlayerBlock();
		Level* level = _game->getLevel();

		SoundPlayer::playTeleportCollect();

		s32 timer = 0;
		while (timer < TELEPORT_TIME) {
			Hardware::waitForVBlank();
			timer++;
		}

		// Remove this block from the level
		_game->getLevel()->removeBlockAt(_x, _y);

		level->moveBlock(player->getX(), player->getY(), destination->getX(), destination->getY());

		_game->render();

		timer = 0;
		while (timer < TELEPORT_TIME) {
			timer++;
			Hardware::waitForVBlank();
		}

		return false;
	}
};

#endif
