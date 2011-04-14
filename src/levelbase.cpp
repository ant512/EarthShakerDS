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

	// Delete all blocks
	for (s32 i = 0; i < _width * _height; ++i) {
		if (_data[i] != NULL) delete _data[i];
	}

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

	if (!isGravityInverted) {
		stop = _width * _height;
	} else {
		start = (_width * _height) - 1;
		stop = -1;
		increment = -1;
	}

	BlockBase* block = NULL;

	// Iterate over all blocks.  This algorithm looks badly designed because
	// it iterates over all blocks 4 times.  However, this is necessary to
	// replicate the behaviour of the original game.  If the behaviours do not
	// match, the levels will not work as expected.  The algorithm will:
	//
	// - Slide all blocks left that are capable of doing so.
	// - Slide all blocks right that are capable of doing so.
	// - Cause any blocks that can fall to fall.
	// - Run the blocks' own iterate() methods to handle anything else that
	//   needs to happen to them.
	//
	// Each block will only perform one movement (slide left, right or fall)
	// per iteration of the game, so there is no problem in calling a block's
	// slideLeft() method then calling its slideRight() method immediately
	// afterwards - the second call won't cause it to slide back to its original
	// position.
	for (s32 i = start; i != stop; i += increment) {	
		block = _data[i];
		if (block == NULL) continue;
		block->slideLeft();
	}

	for (s32 i = start; i != stop; i += increment) {
		block = _data[i];
		if (block == NULL) continue;
		block->slideRight();
	}

	for (s32 i = start; i != stop; i += increment) {
		block = _data[i];
		if (block == NULL) continue;
		block->fall();
	}

	for (s32 i = start; i != stop; i += increment) {
		block = _data[i];
		if (block == NULL) continue;
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
