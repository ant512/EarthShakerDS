#ifndef _DIAMOND_BLOCK_H_
#define _DIAMOND_BLOCK_H_

#include <graphics.h>
#include <bitmap.h>

#include "game.h"
#include "heavyblockbase.h"
#include "diamondbmp1.h"
#include "diamondbmp2.h"
#include "diamondbmp3.h"
#include "diamondbmp4.h"

class DiamondBlock : public HeavyBlockBase {
public:
	DiamondBlock(s32 x, s32 y, Game* game) : HeavyBlockBase(x, y, game) {
		_isSlippy = true;

		_animation->setLoopType(WoopsiGfx::Animation::ANIMATION_LOOPTYPE_PINGPONG);
		_animation->addFrame(&_bmp1, 0);
		_animation->addFrame(&_bmp2, 0);
		_animation->addFrame(&_bmp3, 0);
		_animation->addFrame(&_bmp4, 0);
		_animation->play();

	};

	~DiamondBlock() {};

	virtual bool iterate() {
		return drop();
	};

	virtual bool applyUpwardForce() {
		
		// TODO: Player should collect diamond here.
		return true;
	};

	virtual bool applyDownwardForce() {
		
		// TODO: Player should collect diamond here.
		return true;
	};

	virtual bool applyLeftwardForce() {
		
		// TODO: Player should collect diamond here.
		return true;
	};

	virtual bool applyRightwardForce() {
		
		// TODO: Player should collect diamond here.
		return true;
	};

private:
	DiamondBmp1 _bmp1;
	DiamondBmp2 _bmp2;
	DiamondBmp3 _bmp3;
	DiamondBmp4 _bmp4;
};

#endif
