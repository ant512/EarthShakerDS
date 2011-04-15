#ifndef _BARRIER_CONTROL_BLOCK_H_
#define _BARRIER_CONTROL_BLOCK_H_

#include <graphics.h>
#include <bitmap.h>
#include <game.h>
#include <woopsiarray.h>

#include "barrierblock.h"
#include "blockbase.h"

#include "barriercontrolbmp.h"

/**
 * Barrier control blocks can be destroyed by dropping other blocks on them.
 * When destroyed, any barrier blocks in the level are removed.
 */
class BarrierControlBlock : public BlockBase {
public:

	/**
	 * Constructor.
	 * @param x The x co-ordinate within the level map of the block.
	 * @param y The y co-ordinate within tne level map of the block.
	 * @param game Pointer to the game that contains the block.
	 */
	BarrierControlBlock(s32 x, s32 y, Game* game) : BlockBase(x, y, game) {
		_animation->addFrame(&_bmp, 0);
	};

	/**
	 * Destructor.
	 */
	~BarrierControlBlock() {};

	/**
	 * Connect the supplied barrier block to this controller.
	 * @param barrierBlock The block that this controller should control.
	 */
	void addBarrierBlock(BarrierBlock* barrierBlock) {
		_barrierBlocks.push_back(barrierBlock);
	};

private:
	BarrierControlBmp _bmp;						/**< The block bitmap. */
	WoopsiArray<BarrierBlock*> _barrierBlocks;	/**< List of barrier blocks controlled by this block. */

	/**
	 * Removes all barrier blocks from the level.
	 */
	void onDestroyed() {
		LevelBase* level = _game->getLevel();

		for (s32 i = 0; i < _barrierBlocks.size(); ++i) {
			level->removeBlockAt(_barrierBlocks[i]->getX(), _barrierBlocks[i]->getY());
		}

		_barrierBlocks.clear();
	};
};

#endif
