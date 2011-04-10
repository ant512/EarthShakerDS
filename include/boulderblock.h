#ifndef _BOULDER_BLOCK_H_
#define _BOULDER_BLOCK_H_

#include <graphics.h>
#include <bitmap.h>

#include "game.h"
#include "blockbase.h"
#include "playerblock.h"
#include "boulderbmp.h"

class BoulderBlock : public HeavyBlockBase {
public:
	BoulderBlock(s32 x, s32 y, Game* game) : HeavyBlockBase(x, y, game) {
		_isSlippy = true;	// Boulders are born slippy

		_animation->addFrame(&_bmp, 0);
	};

	~BoulderBlock() {};

	virtual void iterate() {
		if (_game->isGravityInverted()) {
			raise();

			// If we're sat on a hot tile then explode
			if (_y == 0) return;
			
			BlockBase* block = _game->getLevel()->getBlockAt(_x, _y + 1);

			if (block == NULL) return;

			if (block->isHot()) explode();

		} else {
			drop();

			// If we're sat on a hot tile then explode
			if (_y == _game->getLevel()->getHeight() - 1) return;
			
			BlockBase* block = _game->getLevel()->getBlockAt(_x, _y + 1);

			if (block == NULL) return;

			if (block->isHot()) explode();
		}
	};

private:
	BoulderBmp _bmp;
};

#endif
