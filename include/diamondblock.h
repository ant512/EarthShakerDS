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
#include "constants.h"

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

	virtual void iterate() {
		if (_game->isGravityInverted()) {
			raise();
		} else {
			drop();
		}
	};

	virtual bool applyUpwardForce() {
		_game->addScore(DIAMOND_SCORE);
		return true;
	};

	virtual bool applyDownwardForce() {
		_game->addScore(DIAMOND_SCORE);
		return true;
	};

	virtual bool applyLeftwardForce() {
		_game->addScore(DIAMOND_SCORE);
		return true;
	};

	virtual bool applyRightwardForce() {
		_game->addScore(DIAMOND_SCORE);
		return true;
	};

private:
	DiamondBmp1 _bmp1;
	DiamondBmp2 _bmp2;
	DiamondBmp3 _bmp3;
	DiamondBmp4 _bmp4;
};

#endif
