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

protected:
	Bitmap* _bitmap;
	s32 _x;
	s32 _y;
	Game* _game;
};

#endif
