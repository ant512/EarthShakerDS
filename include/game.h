#ifndef _GAME_H_
#define _GAME_H_

#include <graphics.h>

#include "levelbase.h"
#include "blockbase.h"
#include "playersprite.h"

using namespace WoopsiUI;

class Game {
public:
	Game();

	~Game();

	void render(Graphics* gfx);

	LevelBase* getLevel() const;
	PlayerSprite* getPlayerSprite() const;

	bool iterate();

private:
	LevelBase* _level;
	PlayerSprite* _playerSprite;

	LevelBase* createLevel(u8* data, s32 width, s32 height);
};

#endif
