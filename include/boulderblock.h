#ifndef _BOULDER_BLOCK_H_
#define _BOULDER_BLOCK_H_

#include <debug.h>
#include <graphics.h>
#include <bitmap.h>
#include <game.h>

#include "blockbase.h"

using namespace WoopsiUI;

class BoulderBlock : public BlockBase {
public:
	BoulderBlock(s32 x, s32 y) : BlockBase(x, y) {
		Graphics* gfx = _bitmap->newGraphics();
		gfx->drawFilledEllipse(7, 7, 7, 7, woopsiRGB(0, 0, 31));
		delete gfx;
	};

	~BoulderBlock() {};

	virtual bool iterate(LevelBase* level) {
		return drop(level);
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
	virtual bool movePlayerInside(s32 playerX, s32 playerY, Game* game) {


		Debug::printf("go");

		// Ignore any attempts to push the block vertically
		if (playerY != _y) return false;

		// Try to push the block
		if (_x > playerX) {
			return pushRight(game->getLevel());
		} else if (_x < playerX) {
			return pushLeft(game->getLevel());
		}

		// Block couldn't be pushed
		return false;
	};
};

#endif
