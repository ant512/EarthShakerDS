#ifndef _FIRE_BLOCK_H_
#define _FIRE_BLOCK_H_

#include <graphics.h>
#include <bitmap.h>

#include "game.h"
#include "blockbase.h"
#include "bubblebmp1.h"
#include "bubblebmp2.h"
#include "bubblebmp3.h"
#include "bubblebmp4.h"

class FireBlock : public BlockBase {
public:
	FireBlock(s32 x, s32 y, Game* game) : BlockBase(x, y, game) {
		_isHot = true;
		
		_animation->addFrame(&_bmp1, 0);
		_animation->addFrame(&_bmp2, 0);
		_animation->addFrame(&_bmp3, 0);
		_animation->addFrame(&_bmp4, 0);
		_animation->play();
	};

	~FireBlock() {};

private:
	BubbleBmp1 _bmp1;
	BubbleBmp2 _bmp2;
	BubbleBmp3 _bmp3;
	BubbleBmp4 _bmp4;
};

#endif
