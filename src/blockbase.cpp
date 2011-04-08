#include "blockbase.h"
#include "levelbase.h"

using namespace WoopsiUI;

BlockBase::BlockBase() {
	_bitmap = new Bitmap(16, 16);
}

BlockBase::~BlockBase() {
	delete _bitmap;
}

void BlockBase::render(s32 x, s32 y, Graphics* gfx) {
	gfx->drawBitmap(x * _bitmap->getWidth(), y * _bitmap->getHeight(), _bitmap->getWidth(), _bitmap->getHeight(), _bitmap, 0, 0);
}

bool BlockBase::iterate(s32 x, s32 y, LevelBase* level) {
	return false;
}

bool BlockBase::tryToDrop(s32 x, s32 y, LevelBase* level) {

	// Abort if we're already at the bottom of the grid
	if (y == level->getHeight() - 1) return false;

	BlockBase* bottom = level->getBlockAt(x, y + 1);

	if (bottom == NULL) {
		level->moveBlock(x, y, x, y + 1);
		return true;
	}

	if (x > 0) {
		BlockBase* left = level->getBlockAt(x - 1, y);
		BlockBase* bottomLeft = level->getBlockAt(x - 1, y + 1);

		if ((left == NULL) && (bottomLeft == NULL)) {
			level->moveBlock(x, y, x - 1, y + 1);
			return true;
		}
	}

	if (x < level->getWidth() - 1) {
		BlockBase* right = level->getBlockAt(x - 1, y);
		BlockBase* bottomRight = level->getBlockAt(x, y + 1);

		if ((right == NULL) && (bottomRight == NULL)) {
			level->moveBlock(x, y, x + 1, y + 1);
			return true;
		}
	}

	return false;
}
