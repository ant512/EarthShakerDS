#include <bitmap.h>

#include "blockbase.h"
#include "levelbase.h"

using namespace WoopsiUI;

LevelBase::LevelBase(s32 width, s32 height) {
	_width = width;
	_height = height;
	_data = new BlockBase*[width * height];

	for (s32 i = 0; i < _width * _height; ++i) {
		_data[i] = NULL;
	}
}

LevelBase::~LevelBase() {
	delete[] _data;
}

void LevelBase::render(Graphics* gfx) {
	for (s32 i = 0; i < _width * _height; ++i) {

		s32 y = i / _width;
		s32 x = i % _width;

		BlockBase* block = getBlockAt(x, y);
		if (block != NULL) block->render(x, y, gfx);
	}
}
