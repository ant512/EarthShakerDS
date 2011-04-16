#include <bitmap.h>
#include <graphics.h>

#include "game.h"
#include "playerblock.h"
#include "blockbase.h"

PlayerBlock::PlayerBlock(s32 x, s32 y, Game* game) : BlockBase(x, y, game) {
	_isSlippy = false;
	
	_animation->addFrame(&_bmp1, 0);
	_animation->addFrame(&_bmp2, 0);
	_animation->addFrame(&_bmp3, 0);
	_animation->addFrame(&_bmp4, 0);
	_animation->play();

	_explodingAnimation->addFrame(&_explodeBmp, 20);
}

PlayerBlock::~PlayerBlock() { }

bool PlayerBlock::pushLeft() {

	if (_x == 0) return false;
	if (_isExploding) return false;

	// Get the block to the left of this
	BlockBase* block = _game->getLevel()->getBlockAt(_x - 1, _y);

	if (block != NULL) {

		// If the block is hot, we've committed suicide
		if (block->isHot()) {
			explode();
			return false;
		}

		// Attempt to apply a force to the block or, if that fails, attempt to
		// dig the block
		if (!block->pushLeft()) block->digFromRight();
	}

	// Ensure that pushing the block hasn't put us in a situation where we can't
	// move; this can happen after teleporting
	if (_x == 0) return false;
	if (_isExploding) return false;

	// Re-fetch the block in case it has moved or no longer exists
	block = _game->getLevel()->getBlockAt(_x - 1, _y);

	// We can move into the block if it has been vacated
	if (block == NULL) {
		_game->getLevel()->moveBlock(_x, _y, _x - 1, _y);
		return true;
	}

	return false;
}

bool PlayerBlock::pushRight() {

	if (_x == _game->getLevel()->getWidth() - 1) return false;
	if (_isExploding) return false;

	// Get the block to the right of this
	BlockBase* block = _game->getLevel()->getBlockAt(_x + 1, _y);

	if (block != NULL) {

		// If the block is hot, we've committed suicide
		if (block->isHot()) {
			explode();
			return false;
		}

		// Attempt to apply a force to the block or, if that fails, attempt to
		// dig the block
		if (!block->pushRight()) block->digFromLeft();
	}

	// Ensure that pushing the block hasn't put us in a situation where we can't
	// move; this can happen after teleporting
	if (_x == _game->getLevel()->getWidth() - 1) return false;
	if (_isExploding) return false;

	// Re-fetch the block in case it has moved or no longer exists
	block = _game->getLevel()->getBlockAt(_x + 1, _y);

	// We can move into the block if it has been vacated
	if (block == NULL) {
		_game->getLevel()->moveBlock(_x, _y, _x + 1, _y);
		return true;
	}

	return false;
}

bool PlayerBlock::pushUp() {

	if (_y == 0) return false;
	if (_isExploding) return false;

	// Get the block above this
	BlockBase* block = _game->getLevel()->getBlockAt(_x, _y - 1);

	if (block != NULL) {

		// If the block is hot, we've committed suicide
		if (block->isHot()) {
			explode();
			return false;
		}

		// Attempt to apply a force to the block or, if that fails, attempt to
		// dig the block
		if (!block->pushUp()) block->digFromBelow();
	}

	// Ensure that pushing the block hasn't put us in a situation where we can't
	// move; this can happen after teleporting
	if (_y == 0) return false;
	if (_isExploding) return false;

	// Re-fetch the block in case it has moved or no longer exists
	block = _game->getLevel()->getBlockAt(_x, _y - 1);

	// We can move into the block if it has been vacated
	if (block == NULL) {
		_game->getLevel()->moveBlock(_x, _y, _x, _y - 1);
		return true;
	}

	return false;
}

bool PlayerBlock::pushDown() {

	if (_y == _game->getLevel()->getHeight() - 1) return false;
	if (_isExploding) return false;

	// Get the block below this
	BlockBase* block = _game->getLevel()->getBlockAt(_x, _y + 1);

	if (block != NULL) {

		// If the block is hot, we've committed suicide
		if (block->isHot()) {
			explode();
			return false;
		}

		// Attempt to apply a force to the block or, if that fails, attempt to
		// dig the block
		if (!block->pushDown()) block->digFromAbove();
	}

	// Ensure that pushing the block hasn't put us in a situation where we can't
	// move; this can happen after teleporting
	if (_y == _game->getLevel()->getHeight() - 1) return false;
	if (_isExploding) return false;

	// Re-fetch the block in case it has moved or no longer exists
	block = _game->getLevel()->getBlockAt(_x, _y + 1);

	// We can move into the block if it has been vacated
	if (block == NULL) {
		_game->getLevel()->moveBlock(_x, _y, _x, _y + 1);
		return true;
	}

	return false;
}

void PlayerBlock::onDestroyed() {
	_game->killPlayer();
}
