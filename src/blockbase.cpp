#include "blockbase.h"
#include "levelbase.h"
#include "game.h"

using namespace WoopsiUI;

BlockBase::BlockBase(s32 x, s32 y, Game* game) {
	_x = x;
	_y = y;
	_game = game;
	_isSlippy = false;
	_animation = new Animation(1, Animation::ANIMATION_LOOPTYPE_LOOP, 0);
}

BlockBase::~BlockBase() {
	delete _animation;
}

void BlockBase::render(s32 x, s32 y, Graphics* gfx) {
	_animation->run();

	const BitmapBase* bitmap = _animation->getCurrentBitmap();

	gfx->drawBitmap(x, y, bitmap->getWidth(), bitmap->getHeight(), bitmap, 0, 0);
}

bool BlockBase::iterate() {
	return false;
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