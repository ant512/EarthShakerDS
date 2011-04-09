#include "blockbase.h"
#include "levelbase.h"
#include "mapitembase.h"
#include "game.h"

using namespace WoopsiUI;

BlockBase::BlockBase(s32 x, s32 y, Game* game) : MapItemBase(x, y, game) {
	_isFalling = false;
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

bool BlockBase::isFalling() const {
	return _isFalling;
}

bool BlockBase::drop() {

	LevelBase* level = _game->getLevel();

	// Abort if we're already at the bottom of the grid
	if (_y == level->getHeight() - 1) {
		_isFalling = false;
		return false;
	}

	// Try to drop straight downwards
	MapItemBase* bottom = level->getBlockAt(_x, _y + 1);

	if (bottom == NULL) {
		level->moveBlock(_x, _y, _x, _y + 1);
		_isFalling = true;
		return true;
	}

	// Cannot drop straight down.  If the block under us is slippy, we might be
	// able to slide to the left or right.
	if (!bottom->isSlippy()) return false;

	if (_x > 0) {
		MapItemBase* left = level->getBlockAt(_x - 1, _y);
		MapItemBase* bottomLeft = level->getBlockAt(_x - 1, _y + 1);

		if ((left == NULL) && (bottomLeft == NULL)) {

			// Slide to the left
			level->moveBlock(_x, _y, _x - 1, _y);
			_isFalling = true;
			return true;
		}
	}

	if (_x < level->getWidth() - 1) {
		MapItemBase* right = level->getBlockAt(_x + 1, _y);
		MapItemBase* bottomRight = level->getBlockAt(_x + 1, _y + 1);

		if ((right == NULL) && (bottomRight == NULL)) {

			// Slide to the right
			level->moveBlock(_x, _y, _x + 1, _y);
			_isFalling = true;
			return true;
		}
	}

	_isFalling = false;
	return false;
}

bool BlockBase::applyLeftwardForce() {
	if (_x == 0) return false;

	LevelBase* level = _game->getLevel();

	if (level->getBlockAt(_x - 1, _y) == NULL) {
		level->moveBlock(_x, _y, _x - 1, _y);
		return true;
	}

	return false;
}

bool BlockBase::applyRightwardForce() {
	LevelBase* level = _game->getLevel();

	if (_x == level->getWidth() - 1) return false;

	if (level->getBlockAt(_x + 1, _y) == NULL) {
		level->moveBlock(_x, _y, _x + 1, _y);
		return true;
	}

	return false;
}
