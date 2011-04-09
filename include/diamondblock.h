#ifndef _DIAMOND_BLOCK_H_
#define _DIAMOND_BLOCK_H_

#include <graphics.h>
#include <bitmap.h>

#include "game.h"
#include "heavyblockbase.h"
#include "boulderbmp.h"

using namespace WoopsiUI;

class DiamondBlock : public HeavyBlockBase {
public:
	DiamondBlock(s32 x, s32 y, Game* game) : HeavyBlockBase(x, y, game) {
		_isSlippy = true;

		_animation->addFrame(&_bmp1, 0);

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
	BoulderBmp _bmp1;
};

#endif
