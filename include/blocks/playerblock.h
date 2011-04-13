#ifndef _PLAYER_BLOCK_H_
#define _PLAYER_BLOCK_H_

#include <graphics.h>

#include "blockbase.h"
#include "playerbmp1.h"
#include "playerbmp2.h"
#include "playerbmp3.h"
#include "playerbmp4.h"

class Game;

/**
 * Block that represents the player.
 */
class PlayerBlock : public BlockBase {
public:

	/**
	 * Constructor.
	 * @param x The x co-ordinate within the level map of the block.
	 * @param y The y co-ordinate within tne level map of the block.
	 * @param game Pointer to the game that contains the block.
	 */
	PlayerBlock(s32 x, s32 y, Game* game);

	/**
	 * Destructor.
	 */
	~PlayerBlock();

	/**
	 * Attempts to move the player upwards.  If there is no block above this
	 * then the PlayerBlock moves up.  If there is a block then the PlayerBlock
	 * attempts to push it.  If that fails then the PlayerBlock attempts to dig
	 * it.  If either succeeds then the PlayerBlock moves into the vacated
	 * space.  If not, the PlayerBlock remains in place.
	 * @return True if the PlayerBlock moved; false if not.
	 */
	bool pushUp();

	/**
	 * Attempts to move the player downwards.  If there is no block below this
	 * then the PlayerBlock moves down.  If there is a block then the
	 * PlayerBlock attempts to push it.  If that fails then the PlayerBlock
	 * attempts to dig it.  If either succeeds then the PlayerBlock moves into
	 * the vacated space.  If not, the PlayerBlock remains in place.
	 * @return True if the PlayerBlock moved; false if not.
	 */
	bool pushDown();

	/**
	 * Attempts to move the player leftwards.  If there is no block to the left
	 * of this then the PlayerBlock moves left.  If there is a block then the
	 * PlayerBlock attempts to push it.  If that fails then the PlayerBlock
	 * attempts to dig it.  If either succeeds then the PlayerBlock moves into
	 * the vacated space.  If not, the PlayerBlock remains in place.
	 * @return True if the PlayerBlock moved; false if not.
	 */
	bool pushLeft();

	/**
	 * Attempts to move the player rightwards.  If there is no block to the
	 * right of this then the PlayerBlock moves right.  If there is a block then
	 * PlayerBlock attempts to push it.  If that fails then the PlayerBlock
	 * the attempts to dig it.  If either succeeds then the PlayerBlock moves
	 * into the vacated space.  If not, the PlayerBlock remains in place.
	 * @return True if the PlayerBlock moved; false if not.
	 */
	bool pushRight();

	/**
	 * Explodes the player.  Called when a heavy block lands on it.
	 */
	void squash() {
		explode();
	};

private:
	PlayerBmp1 _bmp1;				/**< First animation bitmap. */
	PlayerBmp2 _bmp2;				/**< Second animation bitmap. */
	PlayerBmp3 _bmp3;				/**< Third animation bitmap. */
	PlayerBmp4 _bmp4;				/**< Fourth animation bitmap. */

	/**
	 * Notifies the game that the player is dead.
	 */
	void onDestroyed();
};

#endif
