#include <bitmap.h>

#include "blockbase.h"
#include "doorblock.h"
#include "game.h"
#include "level.h"
#include "playerblock.h"

Level::Level(s32 width, s32 height, s32 number, const WoopsiGfx::WoopsiString& name) {
	_width = width;
	_height = height;
	_number = number;
	_name = name;
	_data = new BlockBase*[width * height];

	_playerBlock = NULL;
	_doorBlock = NULL;

	_diamondCount = 0;
}

Level::~Level() {

	deleteRemovedBlocks();

	// Delete all blocks
	for (s32 i = 0; i < _width * _height; ++i) {
		if (_data[i] != NULL) delete _data[i];
	}

	delete[] _data;
}

void Level::animate() {
	for (s32 i = 0; i < _width * _height; ++i) {
		if (_data[i] != NULL) _data[i]->animate();
	}
}

void Level::render(s32 centreX, s32 centreY, WoopsiGfx::Graphics* gfx) {

	// Get the size of the display measured in blocks
	s32 numBlocksX = GAME_WIDTH / BlockBase::BLOCK_SIZE;
	s32 numBlocksY = GAME_HEIGHT / BlockBase::BLOCK_SIZE;

	// Get the top-left corner based on the assumption that the player is at the
	// centre of the screen
	s32 blockX = centreX - (numBlocksX / 2);
	s32 blockY = centreY - (numBlocksY / 2);

	// Prevent scrolling past the end of the level.  The central point will not
	// be at the centre of the screen
	if (blockX + numBlocksX > _width) blockX = _width - numBlocksX;
	if (blockX < 0) blockX = 0;

	if (blockY + numBlocksY > _height) blockY = _height - numBlocksY;
	if (blockY < 0) blockY = 0;

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

void Level::renderMap(WoopsiGfx::Graphics* gfx) {

	BlockBase* block = NULL;

	for (s32 x = 0; x < _width; ++x) {
		for (s32 y = 0; y < _height; ++y) {
			s32 index = (y * _width) + x;

			block = _data[index];

			if (block != NULL) {
				block->renderMap(BlockBase::BLOCK_MAP_SIZE + (x * BlockBase::BLOCK_MAP_SIZE), BlockBase::BLOCK_MAP_SIZE + (y * BlockBase::BLOCK_MAP_SIZE), gfx);
			} else {
				gfx->drawFilledRect(BlockBase::BLOCK_MAP_SIZE + (x * BlockBase::BLOCK_MAP_SIZE), BlockBase::BLOCK_MAP_SIZE + (y * BlockBase::BLOCK_MAP_SIZE), BlockBase::BLOCK_MAP_SIZE, BlockBase::BLOCK_MAP_SIZE, woopsiRGB(0, 0, 0));
			}
		}
	}
}

BlockBase* Level::getBlockAt(s32 x, s32 y) const {
	if ((x < 0) || (x >= _width)) return NULL;
	if ((y < 0) || (y >= _height)) return NULL;

	return _data[(y * _width) + x];
}

void Level::setBlockAt(s32 x, s32 y, BlockBase* block) {
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

void Level::moveBlock(s32 sourceX, s32 sourceY, s32 destX, s32 destY) {

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

void Level::removeBlockAt(s32 x, s32 y) {

	BlockBase* block = getBlockAt(x, y);

	if (block == NULL) return;

	_removedBlockList.push_back(block);
	setBlockAt(x, y, NULL);
}

void Level::deleteRemovedBlocks() {
	for (s32 i = 0; i < _removedBlockList.size(); ++i) {
		delete _removedBlockList[i];
	}
	_removedBlockList.clear();
}

void Level::iterateBlocks(bool isGravityInverted) {

	// Calculate the start and end points for all blocks we will iterate.  We
	// need to iterate over all blocks, but depending on the direction of
	// gravity we need to either start at the bottom (normal gravity) or top
	// top (inverted gravity).
	s32 start = 0;
	s32 stop = 0;
	s32 increment = 1;

	if (!isGravityInverted) {
		stop = _height;
	} else {
		start = _height - 1;
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
	for (s32 y = start; y != stop; y += increment) {
		for (s32 x = _width - 1; x > -1; --x) {
			block = getBlockAt(x, y);
			if (block == NULL) continue;
			block->slideLeft();
		}
	}

	for (s32 y = start; y != stop; y += increment) {
		for (s32 x = _width - 1; x > -1; --x) {
			block = getBlockAt(x, y);
			if (block == NULL) continue;
			block->slideRight();
		}
	}

	for (s32 y = start; y != stop; y += increment) {
		for (s32 x = _width - 1; x > -1; --x) {
			block = getBlockAt(x, y);
			if (block == NULL) continue;
			block->fall();
		}
	}

	for (s32 y = start; y != stop; y += increment) {
		for (s32 x = _width - 1; x > -1; --x) {
			block = getBlockAt(x, y);
			if (block == NULL) continue;
			block->iterate();
		}
	}
}

void Level::iterate(bool isGravityInverted) {
	deleteRemovedBlocks();
	iterateBlocks(isGravityInverted);
}

PlayerBlock* Level::getPlayerBlock() const {
	return _playerBlock;
}

void Level::setPlayerBlock(PlayerBlock* block) {
	_playerBlock = block;
}

DoorBlock* Level::getDoorBlock() const {
	return _doorBlock;
}

void Level::setDoorBlock(DoorBlock* block) {
	_doorBlock = block;
}
