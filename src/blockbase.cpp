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

void BlockBase::explode() {

	if (_isExploding) return;

	_isExploding = true;
	_explodingAnimation->play();
}

void BlockBase::explodeIfHotBlockAt(s32 x, s32 y) {

	if (_isExploding) return;

	if (x < 0) return;
	if (y < 0) return;
	if (x > _game->getLevel()->getWidth() - 1) return;
	if (y > _game->getLevel()->getHeight() - 1) return;

	BlockBase* block = _game->getLevel()->getBlockAt(x, y);

	if (block == NULL) return;

	if (block->isHot()) explode();
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