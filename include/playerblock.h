#ifndef _PLAYER_BLOCK_H_
#define _PLAYER_BLOCK_H_

#include <graphics.h>

#include "blockbase.h"
#include "playerbmp1.h"
#include "playerbmp2.h"
#include "playerbmp3.h"
#include "playerbmp4.h"

using namespace WoopsiUI;

class Game;

class PlayerBlock : public BlockBase {
public:
	PlayerBlock(s32 x, s32 y, Game* game);
	~PlayerBlock();

	/**
	 * The block examines the level and based on its layout acts appropriately.
	 * @return True if the block performs an action that changes the layout of
	 * the map; false if not.
	 */
	bool iterate() { return false; }

	bool digFromBelow() { return false; };
	bool digFromAbove() { return false; };
	bool digFromLeft() { return false; };
	bool digFromRight() { return false; };

	bool applyUpwardForce();
	bool applyDownwardForce();
	bool applyRightwardForce();
	bool applyLeftwardForce();

private:
	PlayerBmp1 _bmp1;
	PlayerBmp2 _bmp2;
	PlayerBmp3 _bmp3;
	PlayerBmp4 _bmp4;
};

#endif
