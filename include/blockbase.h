#ifndef _BLOCK_BASE_H_
#define _BLOCK_BASE_H_

#include <bitmap.h>
#include <graphics.h>
#include <animation.h>

class LevelBase;
class Game;

class BlockBase {
public:

	/**
	 * Constructor.
	 */
	BlockBase(s32 x, s32 y, Game* game);

	/**
	 * Destructor.
	 */
	virtual ~BlockBase();

	void setX(s32 x);
	void setY(s32 y);
	s32 getX() const;
	s32 getY() const;

	/**
	 * Draw the block to the graphics object using the supplied map co-ordinates
	 * to inform the location the block's bitmap will be drawn at.
	 * @param x The x co-ordinate to render to.
	 * @param y The y co-ordinate to render to.
	 * @param gfx The graphics object to draw to.
	 */
	virtual void render(s32 x, s32 y, WoopsiGfx::Graphics* gfx);

	/**
	 * The block examines the level and based on its layout acts appropriately.
	 * @return True if the block performs an action that changes the layout of
	 * the map; false if not.
	 */
	virtual void iterate() { };

	/**
	 * Check if the block is slippy.  If this is true, blocks sitting on this
	 * block will slip to the left or right if the left or right block adjacent
	 * to this is empty.  For example:
	 *
	 *   x   If block o is slippy, x slides to the left.
	 *   oo
	 *  ooo
	 *
	 *   x   If block o is slippy, x will not fall.
	 *  ooo
	 *
	 *   x   If block o is not slippy, x will not fall.
	 *   o
	 *  ooo
	 * @return True if the block is slippy; false if not.
	 */
	inline bool isSlippy() const { return _isSlippy; };

	inline bool isHot() const { return _isHot; };
	inline bool isExploding() const { return _isExploding; };
	bool isDestroyed() const;

	void explode();

	virtual bool digFromBelow() { return false; };
	virtual bool digFromAbove() { return false; };
	virtual bool digFromLeft() { return false; };
	virtual bool digFromRight() { return false; };

	virtual bool applyUpwardForce() { return false; };
	virtual bool applyDownwardForce() { return false; };
	virtual bool applyLeftwardForce() { return false; };
	virtual bool applyRightwardForce() { return false; };


protected:
	WoopsiGfx::Animation* _animation;
	WoopsiGfx::Animation* _explodingAnimation;
	s32 _x;
	s32 _y;
	Game* _game;
	bool _isSlippy;			/**< If true, blocks sitting on this will slip to
								 the left or right if this block has empty space
								 net to it. */
	bool _isHot;
	bool _isExploding;
};

#endif
