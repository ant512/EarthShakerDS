#include "blockbase.h"
#include "levelbase.h"
#include "game.h"

BlockBase::BlockBase(s32 x, s32 y, Game* game) {
	_x = x;
	_y = y;
	_game = game;
	_isSlippy = false;
	_isHot = false;
	_isExploding = false;

	_animation = new WoopsiGfx::Animation(1, WoopsiGfx::Animation::ANIMATION_LOOPTYPE_LOOP, 0);
	_explodingAnimation = new WoopsiGfx::Animation(1, WoopsiGfx::Animation::ANIMATION_LOOPTYPE_NONE, 0);
}

BlockBase::~BlockBase() {
	delete _animation;
	delete _explodingAnimation;
}

void BlockBase::render(s32 x, s32 y, WoopsiGfx::Graphics* gfx) {

	const WoopsiGfx::BitmapBase* bitmap = NULL;

	if (!_isExploding) {
		_animation->run();

		bitmap = _animation->getCurrentBitmap();
	} else {
		_explodingAnimation->run();

		bitmap = _explodingAnimation->getCurrentBitmap();
	}

	if (bitmap == NULL) return;

	gfx->drawBitmap(x, y, bitmap->getWidth(), bitmap->getHeight(), bitmap, 0, 0);
}

void BlockBase::iterate() {

	// Do not allow exploding blocks to do anything
	if (_isExploding) return;

	// Remove the block from the level if it has been destroyed.  This will
	// prevent it from being iterated over again, so onDestroyed() will only be
	// called once
	if (isDestroyed()) {
		onDestroyed();

		_game->getLevel()->removeBlockAt(_x, _y);
	} else {
		onIterate();
	}
}

void BlockBase::explode() {

	if (_isExploding) return;

	_isExploding = true;
	_explodingAnimation->play();

	onExplode();
}

bool BlockBase::isDestroyed() const {
	return (_isExploding && (_explodingAnimation->getStatus() == WoopsiGfx::Animation::ANIMATION_STATUS_STOPPED));
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
