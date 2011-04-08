#ifndef _DIAMOND_BLOCK_H_
#define _DIAMOND_BLOCK_H_

#include <graphics.h>
#include <bitmap.h>

#include "game.h"
#include "blockbase.h"

using namespace WoopsiUI;

class DiamondBlock : public BlockBase {
public:
	DiamondBlock(s32 x, s32 y, Game* game) : BlockBase(x, y, game) {
		Graphics* gfx = _bitmap->newGraphics();

		gfx->drawLine(0, 7, 7, 0, woopsiRGB(0, 0, 31));
		gfx->drawLine(8, 0, 15, 7, woopsiRGB(0, 0, 31));
		gfx->drawLine(0, 8, 7, 15, woopsiRGB(0, 0, 31));
		gfx->drawLine(8, 15, 15, 8, woopsiRGB(0, 0, 31));

		gfx->floodFill(7, 7, woopsiRGB(0, 0, 31));

		delete gfx;
	};

	~DiamondBlock() {};

	virtual bool iterate() {
		return drop();
	};

	/**
	 * Player is moving into this block.  The direction in which the player is
	 * moving can be determined by comparing the co-ordinates of this block
	 * with the co-ordinates of the player.
	 * @param playerX The x co-ordinate of the player within the level map.
	 * @param playerY The y co-ordinate of the player within the level map.
	 * @param game Pointer to the overall game object.
	 * @return True if the player successfully moves into this block; false if
	 * not.
	 */
	virtual bool movePlayerInside(s32 playerX, s32 playerY) {
		
		// TODO: Player should collect diamond here.
		return true;
	};

};

#endif
