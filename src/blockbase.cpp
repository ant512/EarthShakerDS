#include "blockbase.h"
#include "levelbase.h"
#include "game.h"

using namespace WoopsiUI;

BlockBase::BlockBase(s32 x, s32 y, Game* game) {
	_x = x;
	_y = y;
	_game = game;
	_isSlippy = false;
	_bitmap = new Bitmap(16, 16);
}

BlockBase::~BlockBase() {
	delete _bitmap;
}

void BlockBase::render(Graphics* gfx) {
	gfx->drawBitmap(_x * _bitmap->getWidth(), _y * _bitmap->getHeight(), _bitmap->getWidth(), _bitmap->getHeight(), _bitmap, 0, 0);
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