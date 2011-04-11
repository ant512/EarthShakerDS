#include <bitmap.h>
#include <graphics.h>

#include "game.h"
#include "playerblock.h"
#include "blockbase.h"

PlayerBlock::PlayerBlock(s32 x, s32 y, Game* game) : BlockBase(x, y, game) {
	_animation->addFrame(&_bmp1, 0);
	_animation->addFrame(&_bmp2, 0);
	_animation->addFrame(&_bmp3, 0);
	_animation->addFrame(&_bmp4, 0);
	_animation->play();
}

PlayerBlock::~PlayerBlock() { }

bool PlayerBlock::applyLeftwardForce() {
	if (_x == 0) return false;;

	// Get the block to the left of this
	BlockBase* block = _game->getLevel()->getBlockAt(_x - 1, _y);

	// Attempt to apply a force to the block or, if that fails, attempt to dig
	// the block
	if (block != NULL) {
		if (!block->applyLeftwardForce()) block->digFromRight();
	}

	// Re-fetch the block in case it has moved or no longer exists
	block = _game->getLevel()->getBlockAt(_x - 1, _y);

	// We can move into the block if it has been vacated
	if (block == NULL) {
		_game->getLevel()->moveBlock(_x, _y, _x - 1, _y);
		return true;
	}

	return false;
}

bool PlayerBlock::applyRightwardForce() {
	if (_x == _game->getLevel()->getWidth() - 1) return false;

	// Get the block to the right of this
	BlockBase* block = _game->getLevel()->getBlockAt(_x + 1, _y);

	// Attempt to apply a force to the block or, if that fails, attempt to dig
	// the block
	if (block != NULL) {
		if (!block->applyRightwardForce()) block->digFromLeft();
	}

	// Re-fetch the block in case it has moved or no longer exists
	block = _game->getLevel()->getBlockAt(_x + 1, _y);

	// We can move into the block if it has been vacated
	if (block == NULL) {
		_game->getLevel()->moveBlock(_x, _y, _x + 1, _y);
		return true;
	}

	return false;
}

bool PlayerBlock::applyUpwardForce() {
	if (_y == 0) return false;

	// Get the block above this
	BlockBase* block = _game->getLevel()->getBlockAt(_x, _y - 1);

	// Attempt to apply a force to the block or, if that fails, attempt to dig
	// the block
	if (block != NULL) {
		if (!block->applyUpwardForce()) block->digFromBelow();
	}

	// Re-fetch the block in case it has moved or no longer exists
	block = _game->getLevel()->getBlockAt(_x, _y - 1);

	// We can move into the block if it has been vacated
	if (block == NULL) {
		_game->getLevel()->moveBlock(_x, _y, _x, _y - 1);
		return true;
	}

	return false;
}

bool PlayerBlock::applyDownwardForce() {
	if (_y == _game->getLevel()->getHeight() - 1) return false;

	// Get the block below this
	BlockBase* block = _game->getLevel()->getBlockAt(_x, _y + 1);

	// Attempt to apply a force to the block or, if that fails, attempt to dig
	// the block
	if (block != NULL) {
		if (!block->applyDownwardForce()) block->digFromAbove();
	}

	// Re-fetch the block in case it has moved or no longer exists
	block = _game->getLevel()->getBlockAt(_x, _y + 1);

	// We can move into the block if it has been vacated
	if (block == NULL) {
		_game->getLevel()->moveBlock(_x, _y, _x, _y + 1);
		return true;
	}

	return false;
}
