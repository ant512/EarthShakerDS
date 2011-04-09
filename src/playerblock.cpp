#include <bitmap.h>
#include <graphics.h>

#include "game.h"
#include "PlayerBlock.h"
#include "mapitembase.h"
#include "blockbase.h"

using namespace WoopsiUI;

PlayerBlock::PlayerBlock(s32 x, s32 y, Game* game) : MapItemBase(x, y, game) {
	_bitmap = new Bitmap(16, 16);

	Graphics* gfx = _bitmap->newGraphics();
	gfx->drawFilledRect(0, 0, 16, 16, woopsiRGB(0, 0, 0));
	gfx->drawLine(0, 0, 15, 15, woopsiRGB(0, 31, 0));
	gfx->drawLine(0, 15, 15, 0, woopsiRGB(0, 31, 0));
	delete gfx;
}

PlayerBlock::~PlayerBlock() {
	delete _bitmap;
}

void PlayerBlock::render(Graphics* gfx) {
	gfx->drawBitmap(_x * _bitmap->getWidth(), _y * _bitmap->getHeight(), _bitmap->getWidth(), _bitmap->getHeight(), _bitmap, 0, 0);
}

bool PlayerBlock::applyLeftwardForce() {
	if (_x == 0) return false;;

	BlockBase* block = (BlockBase*)(_game->getLevel()->getBlockAt(_x - 1, _y));

	bool canMove = block->applyLeftwardForce();

	if (!canMove) canMove = block->digFromRight();

	if (canMove) {
		_game->getLevel()->moveBlock(_x, _y, _x - 1, _y);
		return true;
	}

	return false;
}

bool PlayerBlock::applyRightwardForce() {
	if (_x == _game->getLevel()->getWidth() - 1) return false;

	BlockBase* block = (BlockBase*)(_game->getLevel()->getBlockAt(_x + 1, _y));

	bool canMove = block->applyRightwardForce();

	if (!canMove) canMove = block->digFromLeft();

	if (canMove) {
		_game->getLevel()->moveBlock(_x, _y, _x + 1, _y);
		return true;
	}

	return false;
}

bool PlayerBlock::applyUpwardForce() {
	if (_y == 0) return false;

	BlockBase* block = (BlockBase*)(_game->getLevel()->getBlockAt(_x, _y - 1));

	bool canMove = block->applyUpwardForce();

	if (!canMove) canMove = block->digFromBelow();

	if (canMove) {
		_game->getLevel()->moveBlock(_x, _y, _x, _y - 1);
		return true;
	}

	return false;
}

bool PlayerBlock::applyDownwardForce() {
	if (_y == _game->getLevel()->getHeight() - 1) return false;

	BlockBase* block = (BlockBase*)(_game->getLevel()->getBlockAt(_x, _y + 1));

	bool canMove = block->applyDownwardForce();

	if (!canMove) canMove = block->digFromAbove();

	if (canMove) {
		_game->getLevel()->moveBlock(_x, _y, _x, _y + 1);
		return true;
	}

	return false;
}
