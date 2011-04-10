#include "blockbase.h"
#include "levelbase.h"
#include "game.h"

BlockBase::BlockBase(s32 x, s32 y, Game* game) {
	_x = x;
	_y = y;
	_game = game;
	_isSlippy = false;
	_isHot = false;
	_animation = new WoopsiGfx::Animation(1, WoopsiGfx::Animation::ANIMATION_LOOPTYPE_LOOP, 0);
}

BlockBase::~BlockBase() {
	delete _animation;
}

void BlockBase::render(s32 x, s32 y, WoopsiGfx::Graphics* gfx) {
	_animation->run();

	const WoopsiGfx::BitmapBase* bitmap = _animation->getCurrentBitmap();

	gfx->drawBitmap(x, y, bitmap->getWidth(), bitmap->getHeight(), bitmap, 0, 0);
}

void BlockBase::setX(s32 x) {
	_x = x;
}

void BlockBase::setY(s32 y) {
	_y = y;
}

s32 BlockBase::getX() const {
	return _x;
}

s32 BlockBase::getY() const {
	return _y;
}