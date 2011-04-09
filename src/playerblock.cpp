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

	BlockBase* block = _game->getLevel()->getBlockAt(_x - 1, _y);

	bool canMove = true;

	if (block != NULL) {
		canMove = block->applyLeftwardForce();
		if (!canMove) canMove = block->digFromRight();
	}

	if (canMove) {
		_game->getLevel()->moveBlock(_x, _y, _x - 1, _y);
		return true;
	}

	return false;
}

bool PlayerBlock::applyRightwardForce() {
	if (_x == _game->getLevel()->getWidth() - 1) return false;

	BlockBase* block = _game->getLevel()->getBlockAt(_x + 1, _y);

	bool canMove = true;

	if (block != NULL) {
		canMove = block->applyRightwardForce();
		if (!canMove) canMove = block->digFromLeft();
	}

	if (canMove) {
		_game->getLevel()->moveBlock(_x, _y, _x + 1, _y);
		return true;
	}

	return false;
}

bool PlayerBlock::applyUpwardForce() {
	if (_y == 0) return false;

	BlockBase* block = _game->getLevel()->getBlockAt(_x, _y - 1);

	bool canMove = true;

	if (block != NULL) {
		canMove = block->applyUpwardForce();
		if (!canMove) canMove = block->digFromBelow();
	}

	if (canMove) {
		_game->getLevel()->moveBlock(_x, _y, _x, _y - 1);
		return true;
	}

	return false;
}

bool PlayerBlock::applyDownwardForce() {
	if (_y == _game->getLevel()->getHeight() - 1) return false;

	BlockBase* block = _game->getLevel()->getBlockAt(_x, _y + 1);

	bool canMove = true;

	if (block != NULL) {
		canMove = block->applyDownwardForce();
		if (!canMove) canMove = block->digFromAbove();
	}

	if (canMove) {
		_game->getLevel()->moveBlock(_x, _y, _x, _y + 1);
		return true;
	}

	return false;
}
