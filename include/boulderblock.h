#ifndef _BOULDER_BLOCK_H_
#define _BOULDER_BLOCK_H_

#include <graphics.h>
#include <bitmap.h>
#include <game.h>

#include "blockbase.h"

using namespace WoopsiUI;

class BoulderBlock : public BlockBase {
public:
	BoulderBlock() {
		Graphics* gfx = _bitmap->newGraphics();
		gfx->drawFilledEllipse(7, 7, 7, 7, woopsiRGB(0, 0, 31));
		delete gfx;
	};

	~BoulderBlock() {};

	virtual bool iterate(s32 x, s32 y, LevelBase* level) {
		return drop(x, y, level);
	};

	/**
	 * Player is moving into this block.  The direction in which the player is
	 * moving can be determined by calculating the co-ordinates of this block
	 * (given in x,y) and the co-ordinates of the player (given in playerX,
	 * playerY).
	 * @param x The x co-ordinate of this block within the level map.
	 * @param y The y co-ordinate of this block within the level map.
	 * @param playerX The x co-ordinate of the player within the level map.
	 * @param playerY The y co-ordinate of the player within the level map.
	 * @param game Pointer to the overall game object.
	 * @return True if the player successfully moves into this block; false if
	 * not.
	 */
	virtual bool movePlayerInside(s32 x, s32 y, s32 playerX, s32 playerY, Game* game) {

		// Ignore any attempts to push the block vertically
		if (playerY != y) return false;

		// Try to push the block
		if (x > playerX) {
			return pushRight(x, y, game->getLevel());
		} else if (x < playerX) {
			return pushLeft(x, y, game->getLevel());
		}

		// Block couldn't be pushed
		return false;
	};
};

#endif
