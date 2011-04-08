#ifndef _PLAYER_SPRITE_H_
#define _PLAYER_SPRITE_H_

#include <graphics.h>

#include "mapitembase.h"

using namespace WoopsiUI;

class Game;

class PlayerSprite : public MapItemBase {
public:
	PlayerSprite(s32 x, s32 y, Game* game);
	~PlayerSprite();

	void render(Graphics* gfx);

	/**
	 * The block examines the level and based on its layout acts appropriately.
	 * @return True if the block performs an action that changes the layout of
	 * the map; false if not.
	 */
	bool iterate() { return false; }

	bool moveLeft();
	bool moveRight();
	bool moveUp();
	bool moveDown();
};

#endif
