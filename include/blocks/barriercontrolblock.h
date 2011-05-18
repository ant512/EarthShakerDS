#ifndef _BARRIER_CONTROL_BLOCK_H_
#define _BARRIER_CONTROL_BLOCK_H_

#include <graphics.h>
#include <bitmap.h>
#include <woopsiarray.h>

#include "barrierblock.h"
#include "blockbase.h"
#include "constants.h"
#include "game.h"
#include "soundplayer.h"

#include "barriercontrolbmp.h"

/**
 * Barrier control blocks can be destroyed by dropping other blocks on them.
 * When destroyed, any barrier blocks and other controllers in the level are
 * removed.
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
	 * Explodes the block.  Called when a heavy block lands on it.
	 */
	void squash() {
		_game->addScore(BARRIER_CONTROL_SQUASH_SCORE);
		explode();
	};

private:
	BarrierControlBmp _bmp;						/**< The block bitmap. */

	/**
	 * Removes all barrier blocks and barrier control blocks from the level.
	 */
	void onDestroyed() {
		LevelBase* level = _game->getLevel();
		BarrierBlock* barrier = NULL;
		BarrierControlBlock* control = NULL;

		for (s32 y = 0; y < level->getHeight(); ++y) {
			for (s32 x = 0; x < level->getWidth(); ++x) {

				// Skip the current block
				if ((x == getX() && (y == getY()))) continue;

				// If the block is a barrier, remove it
				barrier = dynamic_cast<BarrierBlock*>(level->getBlockAt(x, y));

				if (barrier != NULL) {
					level->removeBlockAt(x, y);
				} else {

					// If the block is a controller, remove it
					control = dynamic_cast<BarrierControlBlock*>(level->getBlockAt(x, y));

					if (control != NULL) {
						level->removeBlockAt(x, y);
					}
				}
			}
		}
	};

	/**
	 * Plays the explode sound.
	 */
	void onExplode() {
		SoundPlayer::playBarrierExplode();
	};
};

#endif
