#ifndef _FIRE_BLOCK_H_
#define _FIRE_BLOCK_H_

#include <graphics.h>
#include <bitmap.h>

#include "game.h"
#include "blockbase.h"
#include "firebmp1.h"
#include "firebmp2.h"
#include "firebmp3.h"
#include "firebmp4.h"
#include "fireexplodebmp1.h"
#include "fireexplodebmp2.h"
#include "fireexplodebmp3.h"
#include "fireexplodebmp4.h"

/**
 * Fire explodes boulders and bubbles (which also extinguish it).  It falls if
 * not sitting on anything.  Touching fire will kill the player.
 */
class FireBlock : public BlockBase {
public:

	/**
	 * Constructor.
	 * @param x The x co-ordinate within the level map of the block.
	 * @param y The y co-ordinate within tne level map of the block.
	 * @param game Pointer to the game that contains the block.
	 */
	FireBlock(s32 x, s32 y, Game* game) : BlockBase(x, y, game) {
		_isHot = true;
		_isHeavy = true;
		_isHeavyEnoughToKill = true;
		
		_animation->addFrame(&_bmp1, 0);
		_animation->addFrame(&_bmp2, 0);
		_animation->addFrame(&_bmp3, 0);
		_animation->addFrame(&_bmp4, 0);
		_animation->play();

		_explodingAnimation->addFrame(&_explodeBmp1, 0);
		_explodingAnimation->addFrame(&_explodeBmp2, 0);
		_explodingAnimation->addFrame(&_explodeBmp3, 0);
		_explodingAnimation->addFrame(&_explodeBmp4, 0);
	};

	/**
	 * Destructor.
	 */
	~FireBlock() {};

private:
	FireBmp1 _bmp1;					/**< First animation bitmap. */
	FireBmp2 _bmp2;					/**< Second animation bitmap. */
	FireBmp3 _bmp3;					/**< Third animation bitmap. */
	FireBmp4 _bmp4;					/**< Fourth animation bitmap. */

	FireExplodeBmp1 _explodeBmp1;	/**< First exploding bitmap. */
	FireExplodeBmp2 _explodeBmp2;	/**< Second exploding bitmap. */
	FireExplodeBmp3 _explodeBmp3;	/**< Third exploding bitmap. */
	FireExplodeBmp4 _explodeBmp4;	/**< Fourth exploding bitmap. */
};

#endif
