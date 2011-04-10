#include <bitmap.h>

#include "blockbase.h"
#include "levelbase.h"

LevelBase::LevelBase(s32 width, s32 height, s32 number, const WoopsiGfx::WoopsiString& name) {
	_width = width;
	_height = height;
	_levelNumber = number;
	_name = name;
	_data = new BlockBase*[width * height];
}

LevelBase::~LevelBase() {
	delete[] _data;
}

void LevelBase::render(s32 blockX, s32 blockY, s32 numBlocksX, s32 numBlocksY, WoopsiGfx::Graphics* gfx) {

	// Ensure we don't try to draw more blocks than exist
	s32 stopX = numBlocksX + blockX;
	s32 stopY = numBlocksY + blockY;

	if (stopX > _width) stopX = _width;
	if (stopY > _height) stopY = _height;

	BlockBase* block = NULL;

	for (s32 x = blockX; x < stopX; ++x) {
		for (s32 y = blockY; y < stopY; ++y) {
			s32 index = (y * _width) + x;

			block = _data[index];

			if (block != NULL) {
				block->render((x - blockX) * BlockBase::BLOCK_SIZE, (y - blockY) * BlockBase::BLOCK_SIZE, gfx);
			} else {
				gfx->drawFilledRect((x - blockX) * BlockBase::BLOCK_SIZE, (y - blockY) * BlockBase::BLOCK_SIZE, BlockBase::BLOCK_SIZE, BlockBase::BLOCK_SIZE, woopsiRGB(0, 0, 0));
			}
		}
	}
}

BlockBase* LevelBase::getBlockAt(s32 x, s32 y) const {
	if ((x < 0) || (x >= _width)) return NULL;
	if ((y < 0) || (y >= _height)) return NULL;

	return _data[(y * _width) + x];
}

void LevelBase::setBlockAt(s32 x, s32 y, BlockBase* block) {
	if ((x < 0) || (x >= _width)) return;
	if ((y < 0) || (y >= _height)) return;

	s32 index = (y * _width) + x;

	_data[index] = block;
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

void LevelBase::iterate(bool isGravityInverted) {

	s32 start = 0;
	s32 stop = 0;
	s32 increment = 1;

	if (isGravityInverted) {
		stop = _width * _height;
	} else {
		start = (_width * _height) - 1;
		stop = -1;
		increment = -1;
	}

	BlockBase* block = NULL;
	BlockBase* lastBlock = NULL;

	for (s32 i = start; i != stop; i += increment) {
		block = _data[i];

		if (block == NULL) continue;
		if (block == lastBlock) continue;

		lastBlock = block;

		// Remove the block if it has finished exploding
		if (block->isDestroyed()) {
			_data[i] = NULL;
			delete block;
		}

		// Try and grab the block again - it may have been deleted
		block = _data[i];
		
		if (block == NULL) continue;

		block->iterate();
	}
}


