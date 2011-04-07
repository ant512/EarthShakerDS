#ifndef _GAME_H_
#define _GAME_H_

#include <graphics.h>

#include "levelbase.h"
#include "blockbase.h"

using namespace WoopsiUI;

class Game {
public:
	Game();

	~Game();

	void render(Graphics* gfx);

private:
	LevelBase* _level;

	LevelBase* createLevel(u8* data, s32 width, s32 height);
};

#endif
