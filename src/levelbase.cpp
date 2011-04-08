#include <bitmap.h>

#include "blockbase.h"
#include "levelbase.h"

using namespace WoopsiUI;

LevelBase::LevelBase(s32 width, s32 height) {
	_width = width;
	_height = height;
	_data = new BlockBase*[width * height];
}

LevelBase::~LevelBase() {
	delete[] _data;
}

void LevelBase::render(Graphics* gfx) {
	for (s32 i = 0; i < _width * _height; ++i) {

		s32 y = i / _width;
		s32 x = i % _width;

		BlockBase* block = getBlockAt(x, y);
		if (block != NULL) {
			block->render(gfx);
		} else {

			// TODO: Magic numbers to constants
			gfx->drawFilledRect(x * 16, y * 16, 16, 16, woopsiRGB(0, 0, 0));
		}
	}
}

BlockBase* LevelBase::getBlockAt(s32 x, s32 y) const {
	if ((x < 0) || (x >= _width)) return NULL;
	if ((y < 0) || (y >= _height)) return NULL;

	return _data[(y * _width) + x];
}

void LevelBase::moveBlock(s32 sourceX, s32 sourceY, s32 destX, s32 destY) {
	BlockBase* dest = getBlockAt(destX, destY);
	if (dest != NULL) delete dest;

	BlockBase* source = getBlockAt(sourceX, sourceY);
	setBlockAt(sourceX, sourceY, NULL);
	setBlockAt(destX, destY, source);

	if (source != NULL) {
		source->setX(destX);
		source->setY(destY);
	}
}

bool LevelBase::iterate() {
	bool requiresIteration = false;

	for (s32 y = _height - 1; y >= 0; --y) {
		for (s32 x = _width - 1; x >= 0; --x) {

			BlockBase* block = getBlockAt(x, y);

			if (block == NULL) continue;

			if (block->iterate(this)) {
				requiresIteration = true;
			}
		}
	}

	return requiresIteration;
}


