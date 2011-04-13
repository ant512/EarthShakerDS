#include <bitmap.h>

#include "game.h"
#include "blockbase.h"
#include "levelbase.h"
#include "playerblock.h"

LevelBase::LevelBase(s32 width, s32 height, s32 number, const WoopsiGfx::WoopsiString& name) {
	_width = width;
	_height = height;
	_number = number;
	_name = name;
	_data = new BlockBase*[width * height];

	_diamondCount = 0;
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

	// Notify the block that its co-ordinates have changed.
	if (block != NULL) {
		block->setX(x);
		block->setY(y);
	}
}

void LevelBase::moveBlock(s32 sourceX, s32 sourceY, s32 destX, s32 destY) {

	if ((sourceX == destX) && (sourceY == destY)) return;

	// Remove the destination block if the co-ordinate is not empty.  We use the
	// removed list to ensure that blocks can move other blocks on top of
	// themselves without therefore deleting themselves and causing memory
	// corruption.  The removed list is deleted outside of any block logic so
	// there is no chance of us deleting something currently being used.
	removeBlockAt(destX, destY);

	// Overwrite the destination with the source block
	setBlockAt(destX, destY, getBlockAt(sourceX, sourceY));

	// Wipe the original co-ordinates
	setBlockAt(sourceX, sourceY, NULL);
}

void LevelBase::removeBlockAt(s32 x, s32 y) {

	BlockBase* block = getBlockAt(x, y);

	if (block == NULL) return;

	_removedBlockList.push_back(block);
	setBlockAt(x, y, NULL);
}

void LevelBase::deleteRemovedBlocks() {
	for (s32 i = 0; i < _removedBlockList.size(); ++i) {
		delete _removedBlockList[i];
	}
	_removedBlockList.clear();
}

void LevelBase::iterateBlocks(bool isGravityInverted) {

	// Calculate the start and end points for all blocks we will iterate.  We
	// need to iterate over all blocks, but depending on the direction of
	// gravity we need to either start at the bottom-right (normal gravity) or
	// top-left (inverted gravity).
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

	// Iterate over all blocks and call their own iterate() methods
	for (s32 i = start; i != stop; i += increment) {
		block = _data[i];

		if (block == NULL) continue;
		if (block == lastBlock) continue;

		// We need to remember the last block we iterated so that we don't end
		// up iterating over it twice in one level iteration.  This can happen
		// if the block moves to the left or right (depending on loop direction)
		// and therefore appears in the next iteration of the for loop.
		// This doesn't allow for situations in which blocks change rows against
		// gravity, or move more than one block to the left or right.  In the
		// current engine this is not a problem as no blocks can do this.  If
		// the engine is updated to allow more complex block movement, a better
		// solution must be found.
		lastBlock = block;

		block->iterate();
	}
}

void LevelBase::iterate(bool isGravityInverted) {
	deleteRemovedBlocks();
	iterateBlocks(isGravityInverted);
}

PlayerBlock* LevelBase::getPlayerBlock() const {
	return _playerBlock;
}

void LevelBase::setPlayerBlock(PlayerBlock* block) {
	_playerBlock = block;
}
