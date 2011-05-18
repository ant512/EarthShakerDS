#ifndef _SCREEN_BASE_H_
#define _SCREEN_BASE_H_

#include <graphics.h>

/**
 * Base class for all separate "screens" or sections of the game, ie. the title
 * screen, game over screen, and even the game itself.
 */
class ScreenBase {
public:

	/**
	 * Constructor.
	 * @param topGfx Pointer to the graphics object that draws on the top
	 * physical display.
	 * @param bottomGfx Pointer to the graphics object that draws on the bottom
	 * physical display.
	 */
	ScreenBase(WoopsiGfx::Graphics* topGfx, WoopsiGfx::Graphics* bottomGfx) {
		_topGfx = topGfx;
		_bottomGfx = bottomGfx;
	};

	/**
	 * Destructor.
	 */
	virtual ~ScreenBase() {};

	/**
	 * Iterate method runs the screen logic.  Should be called every vbl, or as
	 * often as necessary to make the screen work correctly.
	 */
	virtual void iterate() = 0;

	/**
	 * Indicates whether or not the screen is running.  If not, calling its
	 * iterate() method should be futile.  The program should move on to the
	 * next section and give up on this screen.
	 * @return True if the screen is running; false if not.
	 */
	virtual bool isRunning() const = 0;

protected:
	WoopsiGfx::Graphics* _topGfx;		/**< Pointer to the graphics object for the top display. */
	WoopsiGfx::Graphics* _bottomGfx;	/**< Pointer to the graphics object for the bottom display. */
};

#endif
