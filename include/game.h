#ifndef _GAME_H_
#define _GAME_H_

#include <graphics.h>

#include "levelbase.h"
#include "blockbase.h"
#include "playerblock.h"

class Game {
public:
	Game();

	~Game();

	void render(WoopsiGfx::Graphics* gfx);

	LevelBase* getLevel() const;
	PlayerBlock* getPlayerBlock() const;

	bool iterate();

private:
	LevelBase* _level;
	PlayerBlock* _playerBlock;

	LevelBase* createLevel(u8* data, s32 width, s32 height);
};

#endif
