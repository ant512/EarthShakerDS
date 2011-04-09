#ifndef _MAP_ITEM_BASE_H_
#define _MAP_ITEM_BASE_H_

#include <bitmap.h>
#include <graphics.h>

using namespace WoopsiUI;

class LevelBase;
class Game;

class MapItemBase {
public:

	/**
	 * Constructor.
	 */
	MapItemBase(s32 x, s32 y, Game* game) {
		_x = x;
		_y = y;
		_game = game;
		_isSlippy = false;
	}

	/**
	 * Destructor.
	 */
	virtual ~MapItemBase() { };

	void setX(s32 x) { _x = x; };
	void setY(s32 y) { _y = y; };
	s32 getX() const { return _x; };
	s32 getY() const { return _y; };

	/**
	 * Draw the block to the graphics object using the supplied map co-ordinates
	 * to inform the location the block's bitmap will be drawn at.
	 * @param x The x co-ordinate of this block within the level map.
	 * @param y The y co-ordinate of this block within the level map.
	 * @param gfx The graphics object to draw to.
	 */
	virtual void render(Graphics* gfx) = 0;

	/**
	 * The block examines the level and based on its layout acts appropriately.
	 * @return True if the block performs an action that changes the layout of
	 * the map; false if not.
	 */
	virtual bool iterate() = 0;


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

	virtual bool applyUpwardForce() = 0;
	virtual bool applyDownwardForce() = 0;
	virtual bool applyRightwardForce() = 0;
	virtual bool applyLeftwardForce() = 0;

	virtual bool digFromBelow() = 0;
	virtual bool digFromAbove() = 0;
	virtual bool digFromLeft() = 0;
	virtual bool digFromRight() = 0;


protected:
	Bitmap* _bitmap;
	s32 _x;
	s32 _y;
	Game* _game;
	bool _isSlippy;			/**< If true, blocks sitting on this will slip to
								 the left or right if this block has empty space
								 net to it. */
};

#endif
