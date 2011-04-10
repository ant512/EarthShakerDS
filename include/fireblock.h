#ifndef _FIRE_BLOCK_H_
#define _FIRE_BLOCK_H_

#include <graphics.h>
#include <bitmap.h>

#include "game.h"
#include "blockbase.h"
#include "firebmp1.h"
#include "firebmp2.h"
#include "firebmp3.h"
#include "firebmp4.h"

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
	FireBmp1 _bmp1;
	FireBmp2 _bmp2;
	FireBmp3 _bmp3;
	FireBmp4 _bmp4;
};

#endif
