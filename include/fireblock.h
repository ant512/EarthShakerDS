#ifndef _FIRE_BLOCK_H_
#define _FIRE_BLOCK_H_

#include <graphics.h>
#include <bitmap.h>

#include "game.h"
#include "heavyblockbase.h"
#include "firebmp1.h"
#include "firebmp2.h"
#include "firebmp3.h"
#include "firebmp4.h"
#include "fireexplodebmp1.h"
#include "fireexplodebmp2.h"
#include "fireexplodebmp3.h"
#include "fireexplodebmp4.h"

class FireBlock : public HeavyBlockBase {
public:
	FireBlock(s32 x, s32 y, Game* game) : HeavyBlockBase(x, y, game) {
		_isHot = true;
		
		_animation->addFrame(&_bmp1, 0);
		_animation->addFrame(&_bmp2, 0);
		_animation->addFrame(&_bmp3, 0);
		_animation->addFrame(&_bmp4, 0);
		_animation->play();

		_explodingAnimation->addFrame(&_explodeBmp1, 0);
		_explodingAnimation->addFrame(&_explodeBmp2, 0);
		_explodingAnimation->addFrame(&_explodeBmp3, 0);
		_explodingAnimation->addFrame(&_explodeBmp4, 0);
	};

	~FireBlock() {};

private:
	FireBmp1 _bmp1;
	FireBmp2 _bmp2;
	FireBmp3 _bmp3;
	FireBmp4 _bmp4;

	FireExplodeBmp1 _explodeBmp1;
	FireExplodeBmp2 _explodeBmp2;
	FireExplodeBmp3 _explodeBmp3;
	FireExplodeBmp4 _explodeBmp4;
};

#endif
