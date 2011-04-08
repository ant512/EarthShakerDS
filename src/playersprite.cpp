#include <bitmap.h>
#include <graphics.h>

#include "game.h"
#include "playersprite.h"
#include "mapitembase.h"
#include "blockbase.h"

using namespace WoopsiUI;

PlayerSprite::PlayerSprite(s32 x, s32 y, Game* game) : MapItemBase(x, y, game) {
	_bitmap = new Bitmap(16, 16);

	Graphics* gfx = _bitmap->newGraphics();
	gfx->drawFilledRect(0, 0, 16, 16, woopsiRGB(0, 0, 0));
	gfx->drawLine(0, 0, 15, 15, woopsiRGB(0, 31, 0));
	gfx->drawLine(0, 15, 15, 0, woopsiRGB(0, 31, 0));
	delete gfx;
}

PlayerSprite::~PlayerSprite() {
	delete _bitmap;
}

void PlayerSprite::render(Graphics* gfx) {
	gfx->drawBitmap(_x * _bitmap->getWidth(), _y * _bitmap->getHeight(), _bitmap->getWidth(), _bitmap->getHeight(), _bitmap, 0, 0);
}

void PlayerSprite::moveLeft() {
	if (_x == 0) return;

	BlockBase* block = _game->getLevel()->getBlockAt(_x - 1, _y);

	// Attempt to move to the new location - this will push boulders, collect
	// diamonds, wipe out soil, etc.
	if (block->movePlayerInside()) {

		// We can move to the new location, but the block at that location may
		// not have moved (in the case of soil, for example).  In that situation
		// we need to make sure we delete the block
		block = _game->getLevel()->getBlockAt(_x - 1, _y);
		if (block != NULL) {
			delete block;
			_game->getLevel()->setBlockAt(_x - 1, _y, NULL);
		}

		// Update our own co-ordinates
		_x -= 1;
	}
}

void PlayerSprite::moveRight() {
	if (_x == _game->getLevel()->getWidth() - 1) return;

	BlockBase* block = _game->getLevel()->getBlockAt(_x + 1, _y);

	// Attempt to move to the new location - this will push boulders, collect
	// diamonds, wipe out soil, etc.
	if (block->movePlayerInside()) {

		// We can move to the new location, but the block at that location may
		// not have moved (in the case of soil, for example).  In that situation
		// we need to make sure we delete the block
		block = _game->getLevel()->getBlockAt(_x + 1, _y);
		if (block != NULL) {
			delete block;
			_game->getLevel()->setBlockAt(_x + 1, _y, NULL);
		}

		// Update our own co-ordinates
		_x += 1;
	}
}

void PlayerSprite::moveUp() {
	if (_y == 0) return;

	BlockBase* block = _game->getLevel()->getBlockAt(_x, _y - 1);

	// Attempt to move to the new location - this will push boulders, collect
	// diamonds, wipe out soil, etc.
	if (block->movePlayerInside()) {

		// We can move to the new location, but the block at that location may
		// not have moved (in the case of soil, for example).  In that situation
		// we need to make sure we delete the block
		block = _game->getLevel()->getBlockAt(_x, _y - 1);
		if (block != NULL) {
			delete block;
			_game->getLevel()->setBlockAt(_x, _y - 1, NULL);
		}

		// Update our own co-ordinates
		_y -= 1;
	}
}

void PlayerSprite::moveDown() {
	if (_y == _game->getLevel()->getHeight() - 1) return;

	BlockBase* block = _game->getLevel()->getBlockAt(_x, _y + 1);

	// Attempt to move to the new location - this will push boulders, collect
	// diamonds, wipe out soil, etc.
	if (block->movePlayerInside()) {

		// We can move to the new location, but the block at that location may
		// not have moved (in the case of soil, for example).  In that situation
		// we need to make sure we delete the block
		block = _game->getLevel()->getBlockAt(_x, _y + 1);
		if (block != NULL) {
			delete block;
			_game->getLevel()->setBlockAt(_x, _y + 1, NULL);
		}

		// Update our own co-ordinates
		_y += 1;
	}
}
