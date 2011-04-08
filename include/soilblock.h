#ifndef _SOIL_BLOCK_H_
#define _SOIL_BLOCK_H_

#include <graphics.h>
#include <bitmap.h>
#include <game.h>

#include "blockbase.h"

using namespace WoopsiUI;

class SoilBlock : public BlockBase {
public:
	SoilBlock(s32 x, s32 y) : BlockBase(x, y) {
		Graphics* gfx = _bitmap->newGraphics();
		gfx->drawFilledRect(0, 0, 16, 16, woopsiRGB(17, 8, 2));
		delete gfx;
	};

	~SoilBlock() {};

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
		return true;
	};
};

#endif
