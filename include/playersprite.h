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

	void moveLeft();
	void moveRight();
	void moveUp();
	void moveDown();
};

#endif
