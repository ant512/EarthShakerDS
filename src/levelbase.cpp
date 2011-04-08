#include <bitmap.h>

#include "game.h"
#include "mapitembase.h"
#include "levelbase.h"

using namespace WoopsiUI;

LevelBase::LevelBase(s32 width, s32 height) {
	_width = width;
	_height = height;
	_data = new MapItemBase*[width * height];
}

LevelBase::~LevelBase() {
	delete[] _data;
}

void LevelBase::render(Graphics* gfx) {
	for (s32 i = 0; i < _damagedBlockList.size(); ++i) {

		s32 y = _damagedBlockList[i] / _width;
		s32 x = _damagedBlockList[i] % _width;

		MapItemBase* block = _data[_damagedBlockList[i]];

		if (block != NULL) {
			block->render(gfx);
		} else {

			// TODO: Magic numbers to constants
			gfx->drawFilledRect(x * 16, y * 16, 16, 16, woopsiRGB(0, 0, 0));
		}
	}
}

MapItemBase* LevelBase::getBlockAt(s32 x, s32 y) const {
	if ((x < 0) || (x >= _width)) return NULL;
	if ((y < 0) || (y >= _height)) return NULL;

	return _data[(y * _width) + x];
}

void LevelBase::setBlockAt(s32 x, s32 y, MapItemBase* block) {
	if ((x < 0) || (x >= _width)) return;
	if ((y < 0) || (y >= _height)) return;

	s32 index = (y * _width) + x;

	_data[index] = block;
	
	addDamagedBlockIndex(index);
}

void LevelBase::moveBlock(s32 sourceX, s32 sourceY, s32 destX, s32 destY) {
	MapItemBase* dest = getBlockAt(destX, destY);
	if (dest != NULL) delete dest;

	MapItemBase* source = getBlockAt(sourceX, sourceY);
	setBlockAt(sourceX, sourceY, NULL);
	setBlockAt(destX, destY, source);

	if (source != NULL) {
		source->setX(destX);
		source->setY(destY);
	}

	addDamagedBlockIndex((_width * sourceY) + sourceX);
	addDamagedBlockIndex((_width * destY) + destX);
}

void LevelBase::addDamagedBlockIndex(s32 index) {

	// Ensure each block is only listed once
	for (s32 i = 0; i < _damagedBlockList.size(); ++i) {
		if (_damagedBlockList[i] == index) return;
	}

	_damagedBlockList.push_back(index);
}

bool LevelBase::iterate() {
	bool requiresIteration = false;

	for (s32 y = _height - 1; y >= 0; --y) {
		for (s32 x = _width - 1; x >= 0; --x) {

			MapItemBase* block = getBlockAt(x, y);

			if (block == NULL) continue;

			if (block->iterate()) {
				requiresIteration = true;
			}
		}
	}

	return requiresIteration;
}


