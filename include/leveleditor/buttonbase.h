#ifndef _BUTTON_BASE_H_
#define _BUTTON_BASE_H_

#include <graphics.h>

#include "soundplayer.h"

/**
 * Base class for all buttons.
 */
class ButtonBase {
public:

	/**
	 * Constructor.
	 * @param x X co-ordinate of the button.
	 * @param y Y co-ordinate of the buttpn.
	 * @param width Width of the button.
	 * @param height Height of the button.
	 * @param id The unique ID of the button.  Uniqueness is not enforced but
	 * problems will arise if multiple buttons have the same ID.
	 */
	ButtonBase(s32 x, s32 y, s32 width, s32 height, s32 id) {
		_x = x;
		_y = y;
		_width = width;
		_height = height;
		_id = id;
		_clicked = false;
	};

	/**
	 * Destructor.
	 */
	virtual ~ButtonBase() { };

	/**
	 * Draws the button.
	 * @param gfx The graphics object to draw to.
	 */
	virtual void render(WoopsiGfx::Graphics* gfx) = 0;

	/**
	 * Checks if the supplied co-ordinates intersect this button.
	 * @param x The x co-ordinate to check.
	 * @param y The y co-ordinate to check.
	 * @return True if the co-ordinate intersets the button; false if not.
	 */
	bool checkCollision(s32 x, s32 y) {
		return ((x >= _x) &&
				(y >= _y) &&
				(x < _x + _width) &&
				(y < _y + _height));
	};

	/**
	 * Gets the ID of the button.
	 * @return The ID of the button.
	 */
	s32 getId() const { return _id; };

	/**
	 * Click the button.
	 */
	void click() {
		SoundPlayer::playSoilDig();
		_clicked = true;
	};

	/**
	 * Release the button.
	 */
	void release() {
		_clicked = false;
	};

protected:
	s32 _x;			/**< The x co-ordinate of the button. */
	s32 _y;			/**< The y co-ordinate of the button. */
	s32 _width;		/**< The width of the button. */
	s32 _height;	/**< The height of the button. */
	s32 _id;		/**< The ID of the button. */
	bool _clicked;	/**< Indicates whether or not the button is clicked. */
};

#endif
