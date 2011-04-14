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
	_isOddIteration = true;
	_isFalling = false;

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

	if (_isOddIteration != _game->isOddIteration()) return;

	_isOddIteration = !_isOddIteration;

	// Remove the block from the level if it has been destroyed.  This will
	// prevent it from being iterated over again, so onDestroyed() will only be
	// called once
	if (isDestroyed()) {
		onDestroyed();

		_game->getLevel()->removeBlockAt(_x, _y);
	} else if (_isExploding) {
		
		// Do not allow exploding blocks to do anything
		return;
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

bool BlockBase::isFalling() const {
	return _isFalling;
}

void BlockBase::squashBlock() {
	if (!_isHeavyEnoughToKill) return;
	if (!_isFalling) return;

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

void BlockBase::fall() {
	if (_isOddIteration != _game->isOddIteration()) return;

	if (!_isHeavy) return;

	if (_game->isGravityInverted()) {
		raise();
	} else {
		drop();
	}
}

void BlockBase::raise() {

	LevelBase* level = _game->getLevel();	

	// Abort if we're already at the top of the grid
	if (_y == 0) return;

	// Try to drop straight upwards
	BlockBase* top = level->getBlockAt(_x, _y - 1);

	if (top == NULL) {

		// If we are at the same x co-ord as the player and below the player, we
		// give him an iteration's grace period to escape if we're not already
		// falling
		if (!_isFalling) {
			_isFalling = true;

			BlockBase* player = _game->getPlayerBlock();

			if ((player->getX() == _x) && (player->getY() < _y)) {
				_isOddIteration = !_isOddIteration;
				return;
			}
		}

		level->moveBlock(_x, _y, _x, _y - 1);

		// Flip the iteration bit so that we don't iterate twice during a single
		// iteration of the game object.  This can happen when we move into a
		// row or column that has not yet been iterated over.
		_isOddIteration = !_isOddIteration;

		onFall();

		squashBlock();
	} else {

		// Do not stop raising if the block above us is also being raised.
		// This prevents blocks from settling on top of blocks that are falling
		// and will fall again during the next iteration.
		if (!top->isFalling()) {
			_isFalling = false;
		}
	}
}

void BlockBase::drop() {

	LevelBase* level = _game->getLevel();	

	// Abort if we're already at the bottom of the grid
	if (_y == level->getHeight() - 1) return;

	// Try to drop straight downwards
	BlockBase* bottom = level->getBlockAt(_x, _y + 1);

	if (bottom == NULL) {

		// If we are at the same x co-ord as the player and above the player, we
		// give him an iteration's grace period to escape if we're not already
		// falling
		if (!_isFalling) {
			_isFalling = true;

			BlockBase* player = _game->getPlayerBlock();

			if ((player->getX() == _x) && (player->getY() > _y)) {
				_isOddIteration = !_isOddIteration;
				return;
			}
		}

		level->moveBlock(_x, _y, _x, _y + 1);

		// Flip the iteration bit so that we don't iterate twice during a single
		// iteration of the game object.  This can happen when we move into a
		// row or column that has not yet been iterated over.
		_isOddIteration = !_isOddIteration;

		onFall();

		squashBlock();
	} else {

		// Do not stop raising if the block above us is also being raised.
		// This prevents blocks from settling on top of blocks that are falling
		// and will fall again during the next iteration.
		if (!bottom->isFalling()) {
			_isFalling = false;
		}
	}
}

void BlockBase::slideLeft() {

	if (_isOddIteration != _game->isOddIteration()) return;
	if (!_isHeavy) return;
	if (_isFalling) return;

	LevelBase* level = _game->getLevel();
	BlockBase* restingOn = NULL;

	// We can only slide if the block we're resting on is slippy.  We can't
	// slide if the block is NULL as that would mean we are sliding over an
	// empty block.
	if (_game->isGravityInverted()) {
		restingOn = level->getBlockAt(_x, _y - 1);
	} else {
		restingOn = level->getBlockAt(_x, _y + 1);
	}

	if (restingOn == NULL) return;
	if (!restingOn->isSlippy()) return;

	// At this point, we can slide if the block immediately to our left is NULL
	// and the block below that is also NULL.
	if (_x > 0) {

		BlockBase* left = level->getBlockAt(_x - 1, _y);
		BlockBase* leftDiagonal = NULL;

		if (_game->isGravityInverted()) {
			leftDiagonal = level->getBlockAt(_x - 1, _y - 1);
		} else {
			leftDiagonal = level->getBlockAt(_x - 1, _y + 1);
		}

		if ((left == NULL) && (leftDiagonal == NULL)) {

			// Slide to the left
			level->moveBlock(_x, _y, _x - 1, _y);
			_isOddIteration = !_isOddIteration;
			_isFalling = true;
		}
	}
}

void BlockBase::slideRight() {

	if (_isOddIteration != _game->isOddIteration()) return;
	if (!_isHeavy) return;
	if (_isFalling) return;

	LevelBase* level = _game->getLevel();
	BlockBase* restingOn = NULL;

	// We can only slide if the block we're resting on is slippy.  We can't
	// slide if the block is NULL as that would mean we are sliding over an
	// empty block.
	if (_game->isGravityInverted()) {
		restingOn = level->getBlockAt(_x, _y - 1);
	} else {
		restingOn = level->getBlockAt(_x, _y + 1);
	}

	if (restingOn == NULL) return;
	if (!restingOn->isSlippy()) return;

	// At this point, we can slide if the block immediately to our left is NULL
	// and the block below that is also NULL.
	if (_x < level->getWidth() - 1) {
		
		BlockBase* right = level->getBlockAt(_x + 1, _y);
		BlockBase* rightDiagonal = NULL;

		if (_game->isGravityInverted()) {
			rightDiagonal = level->getBlockAt(_x + 1, _y - 1);
		} else {
			rightDiagonal = level->getBlockAt(_x + 1, _y + 1);
		}

		if ((right == NULL) && (rightDiagonal == NULL)) {

			// Slide to the right
			level->moveBlock(_x, _y, _x + 1, _y);
			_isOddIteration = !_isOddIteration;
			_isFalling = true;
		}
	}
}
