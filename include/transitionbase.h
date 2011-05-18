#ifndef _TRANSITION_BASE_H_
#define _TRANSITION_BASE_H_

#include <graphics.h>

/**
 * Base class for all screen transitions.
 */
class TransitionBase {
public:

	/**
	 * Constructor.
	 * @param topGfx Pointer to the graphics object that draws on the top
	 * physical display.
	 * @param bottomGfx Pointer to the graphics object that draws on the bottom
	 * physical display.
	 */
	TransitionBase(WoopsiGfx::Graphics* topGfx, WoopsiGfx::Graphics* bottomGfx) {
		_topGfx = topGfx;
		_bottomGfx = bottomGfx;
	}

	/**
	 * Destructor.
	 */
	virtual ~TransitionBase() { };

	/**
	 * Iterate method runs the transition logic.  Should be called every vbl, or
	 * as often as necessary to make the transition work correctly.
	 */
	virtual void iterate() = 0;

	/**
	 * Resets the transition to its initial state.
	 */
	virtual void reset() = 0;

	/**
	 * Indicates whether or not the transition is running.  If not, calling its
	 * iterate() method should be futile.  The program should move on to the
	 * next section and give up on this transition.
	 * @return True if the transition is running; false if not.
	 */
	virtual bool isRunning() = 0;

protected:
	WoopsiGfx::Graphics* _topGfx;		/**< Pointer to the graphics object for the top display. */
	WoopsiGfx::Graphics* _bottomGfx;	/**< Pointer to the graphics object for the bottom display. */
};

#endif
