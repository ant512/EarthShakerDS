#ifndef _PLAYER_BLOCK_H_
#define _PLAYER_BLOCK_H_

#include <graphics.h>

#include "blockbase.h"
#include "playerbmp1.h"
#include "playerbmp2.h"
#include "playerbmp3.h"
#include "playerbmp4.h"

class Game;

class PlayerBlock : public BlockBase {
public:
	PlayerBlock(s32 x, s32 y, Game* game);
	~PlayerBlock();

	bool pushUp();
	bool pushDown();
	bool pushLeft();
	bool pushRight();

private:
	PlayerBmp1 _bmp1;
	PlayerBmp2 _bmp2;
	PlayerBmp3 _bmp3;
	PlayerBmp4 _bmp4;
};

#endif
