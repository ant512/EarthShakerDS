#ifndef _BEAN_BLOCK_H_
#define _BEAN_BLOCK_H_

#include <graphics.h>
#include <bitmap.h>

#include "game.h"
#include "heavyblockbase.h"
#include "beanbmp1.h"
#include "beanbmp2.h"
#include "beanbmp3.h"

class BeanBlock : public HeavyBlockBase {
public:
	BeanBlock(s32 x, s32 y, Game* game) : HeavyBlockBase(x, y, game) {
		_isSlippy = true;

		_animation->setLoopType(WoopsiGfx::Animation::ANIMATION_LOOPTYPE_PINGPONG);
		_animation->addFrame(&_bmp1, 0);
		_animation->addFrame(&_bmp2, 0);
		_animation->addFrame(&_bmp3, 0);
		_animation->play();

	};

	~BeanBlock() {};

	virtual void iterate() {
		if (_game->isGravityInverted()) {
			raise();
		} else {
			drop();
		}
	};

	virtual bool applyUpwardForce() {
		
		// TODO: Player should collect bean here.
		return true;
	};

	virtual bool applyDownwardForce() {
		
		// TODO: Player should collect bean here.
		return true;
	};

	virtual bool applyLeftwardForce() {
		
		// TODO: Player should collect bean here.
		return true;
	};

	virtual bool applyRightwardForce() {
		
		// TODO: Player should collect bean here.
		return true;
	};

private:
	BeanBmp1 _bmp1;
	BeanBmp2 _bmp2;
	BeanBmp3 _bmp3;
};

#endif
