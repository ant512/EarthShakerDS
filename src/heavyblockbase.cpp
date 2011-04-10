#include "heavyblockbase.h"
#include "levelbase.h"
#include "blockbase.h"
#include "game.h"

HeavyBlockBase::HeavyBlockBase(s32 x, s32 y, Game* game) : BlockBase(x, y, game) {
	_isFalling = false;
}

bool HeavyBlockBase::isFalling() const {
	return _isFalling;
}

void HeavyBlockBase::raise() {

	LevelBase* level = _game->getLevel();	

	// Abort if we're already at the top of the grid
	if (_y == 0) {
		_isFalling = false;
		return;
	}

	// Try to drop straight upwards
	BlockBase* top = level->getBlockAt(_x, _y - 1);

	if (top == NULL) {
		level->moveBlock(_x, _y, _x, _y - 1);
		_isFalling = true;
		return;
	}

	// Cannot raise straight up.  If the block above us is slippy, we might be
	// able to slide to the left or right.
	if (!top->isSlippy()) return;

	if (_x > 0) {
		BlockBase* left = level->getBlockAt(_x - 1, _y);
		BlockBase* topLeft = level->getBlockAt(_x - 1, _y - 1);

		if ((left == NULL) && (topLeft == NULL)) {

			// Slide to the left
			level->moveBlock(_x, _y, _x - 1, _y);
			_isFalling = true;
			return;
		}
	}

	if (_x < level->getWidth() - 1) {
		BlockBase* right = level->getBlockAt(_x + 1, _y);
		BlockBase* topRight = level->getBlockAt(_x + 1, _y - 1);

		if ((right == NULL) && (topRight == NULL)) {

			// Slide to the right
			level->moveBlock(_x, _y, _x + 1, _y);
			_isFalling = true;
			return;
		}
	}

	_isFalling = false;
	return;
}

void HeavyBlockBase::drop() {

	LevelBase* level = _game->getLevel();	

	// Abort if we're already at the bottom of the grid
	if (_y == level->getHeight() - 1) {
		_isFalling = false;
		return;
	}

	// Try to drop straight downwards
	BlockBase* bottom = level->getBlockAt(_x, _y + 1);

	if (bottom == NULL) {
		level->moveBlock(_x, _y, _x, _y + 1);
		_isFalling = true;
		return;
	}

	// Cannot drop straight down.  If the block under us is slippy, we might be
	// able to slide to the left or right.
	if (!bottom->isSlippy()) return;

	if (_x > 0) {
		BlockBase* left = level->getBlockAt(_x - 1, _y);
		BlockBase* bottomLeft = level->getBlockAt(_x - 1, _y + 1);

		if ((left == NULL) && (bottomLeft == NULL)) {

			// Slide to the left
			level->moveBlock(_x, _y, _x - 1, _y);
			_isFalling = true;
			return;
		}
	}

	if (_x < level->getWidth() - 1) {
		BlockBase* right = level->getBlockAt(_x + 1, _y);
		BlockBase* bottomRight = level->getBlockAt(_x + 1, _y + 1);

		if ((right == NULL) && (bottomRight == NULL)) {

			// Slide to the right
			level->moveBlock(_x, _y, _x + 1, _y);
			_isFalling = true;
			return;
		}
	}

	_isFalling = false;
	return;
}

bool HeavyBlockBase::applyLeftwardForce() {
	if (_x == 0) return false;

	LevelBase* level = _game->getLevel();

	if (level->getBlockAt(_x - 1, _y) == NULL) {
		level->moveBlock(_x, _y, _x - 1, _y);
		return true;
	}

	return false;
}

bool HeavyBlockBase::applyRightwardForce() {
	LevelBase* level = _game->getLevel();

	if (_x == level->getWidth() - 1) return false;

	if (level->getBlockAt(_x + 1, _y) == NULL) {
		level->moveBlock(_x, _y, _x + 1, _y);
		return true;
	}

	return false;
}
