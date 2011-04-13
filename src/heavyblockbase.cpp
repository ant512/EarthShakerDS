#include "blockbase.h"
#include "game.h"
#include "heavyblockbase.h"
#include "levelbase.h"

HeavyBlockBase::HeavyBlockBase(s32 x, s32 y, Game* game) : BlockBase(x, y, game) {
	_isHeavyEnoughToKill = true;
	_isOnPlayer = false;
}

void HeavyBlockBase::onIterate() {
	fall();
}

void HeavyBlockBase::squashBlock() {
	if (!_isHeavyEnoughToKill) return;

	BlockBase* block = NULL;
	LevelBase* level = _game->getLevel();	
	
	if (_game->isGravityInverted()) {
		block = level->getBlockAt(_x, _y - 1);

		if (block == NULL) return;

		block->squash();
	} else {
		block = level->getBlockAt(_x, _y + 1);

		if (block == NULL) return;

		block->squash();
	}
}

void HeavyBlockBase::fall() {
	if (_game->isGravityInverted()) {
		raise();
	} else {
		drop();
	}
}

void HeavyBlockBase::raise() {

	LevelBase* level = _game->getLevel();	

	// Abort if we're already at the top of the grid
	if (_y == 0) return;

	// Try to drop straight upwards
	BlockBase* top = level->getBlockAt(_x, _y - 1);

	if (top == NULL) {

		// If we know that we were just sat on top of the player and the player
		// is now above us, we give one iteration's grace period to let him 
		// escape before we start to drop
		if (_isOnPlayer) {
			_isOnPlayer = false;

			BlockBase* player = _game->getPlayerBlock();

			if (player->getX() == _x) {
				return;
			}
		}

		level->moveBlock(_x, _y, _x, _y - 1);

		onFall();

		squashBlock();

		return;
	} else {
		// Check if the player is immediately below us and remember if so
		if (top == _game->getPlayerBlock()) {
			_isOnPlayer = true;
		}
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

			onFall();

			return;
		}
	}

	if (_x < level->getWidth() - 1) {
		BlockBase* right = level->getBlockAt(_x + 1, _y);
		BlockBase* topRight = level->getBlockAt(_x + 1, _y - 1);

		if ((right == NULL) && (topRight == NULL)) {

			// Slide to the right
			level->moveBlock(_x, _y, _x + 1, _y);

			onFall();

			return;
		}
	}
}

void HeavyBlockBase::drop() {

	LevelBase* level = _game->getLevel();	

	// Abort if we're already at the bottom of the grid
	if (_y == level->getHeight() - 1) return;

	// Try to drop straight downwards
	BlockBase* bottom = level->getBlockAt(_x, _y + 1);

	if (bottom == NULL) {

		// If we know that we were just sat on top of the player and the player
		// is now above us, we give one iteration's grace period to let him 
		// escape before we start to drop
		if (_isOnPlayer) {
			_isOnPlayer = false;

			BlockBase* player = _game->getPlayerBlock();

			if (player->getX() == _x) {
				return;
			}
		}

		level->moveBlock(_x, _y, _x, _y + 1);

		onFall();

		squashBlock();

		return;
	} else {
		// Check if the player is immediately below us and remember if so
		if (bottom == _game->getPlayerBlock()) {
			_isOnPlayer = true;
		}
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

			onFall();

			return;
		}
	}

	if (_x < level->getWidth() - 1) {
		BlockBase* right = level->getBlockAt(_x + 1, _y);
		BlockBase* bottomRight = level->getBlockAt(_x + 1, _y + 1);

		if ((right == NULL) && (bottomRight == NULL)) {

			// Slide to the right
			level->moveBlock(_x, _y, _x + 1, _y);

			onFall();

			return;
		}
	}
}
