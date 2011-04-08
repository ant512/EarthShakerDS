#include "blockbase.h"
#include "levelbase.h"
#include "game.h"

using namespace WoopsiUI;

BlockBase::BlockBase(s32 x, s32 y) {
	_x = x;
	_y = y;
	_isFalling = false;
	_bitmap = new Bitmap(16, 16);
}

BlockBase::~BlockBase() {
	delete _bitmap;
}

void BlockBase::setX(s32 x) {
	_x = x;
}

void BlockBase::setY(s32 y) {
	_y = y;
}

void BlockBase::render(Graphics* gfx) {
	gfx->drawBitmap(_x * _bitmap->getWidth(), _y * _bitmap->getHeight(), _bitmap->getWidth(), _bitmap->getHeight(), _bitmap, 0, 0);
}

bool BlockBase::iterate(LevelBase* level) {
	return false;
}

bool BlockBase::isFalling() const {
	return _isFalling;
}

bool BlockBase::drop(LevelBase* level) {

	// Abort if we're already at the bottom of the grid
	if (_y == level->getHeight() - 1) {
		_isFalling = false;
		return false;
	}

	BlockBase* bottom = level->getBlockAt(_x, _y + 1);

	if (bottom == NULL) {
		level->moveBlock(_x, _y, _x, _y + 1);
		_isFalling = true;
		return true;
	}

	if (_x > 0) {
		BlockBase* left = level->getBlockAt(_x - 1, _y);
		BlockBase* bottomLeft = level->getBlockAt(_x - 1, _y + 1);

		if ((left == NULL) && (bottomLeft == NULL)) {
			level->moveBlock(_x, _y, _x - 1, _y + 1);
			_isFalling = true;
			return true;
		}
	}

	if (_x < level->getWidth() - 1) {
		BlockBase* right = level->getBlockAt(_x - 1, _y);
		BlockBase* bottomRight = level->getBlockAt(_x, _y + 1);

		if ((right == NULL) && (bottomRight == NULL)) {
			level->moveBlock(_x, _y, _x + 1, _y + 1);
			_isFalling = true;
			return true;
		}
	}

	_isFalling = false;
	return false;
}

bool BlockBase::pushLeft(LevelBase* level) {
	if (_x == 0) return false;
	return (level->getBlockAt(_x - 1, _y) == NULL);
}

bool BlockBase::pushRight(LevelBase* level) {
	if (_x == level->getWidth() - 1) return false;
	return (level->getBlockAt(_x + 1, _y) == NULL);
}
