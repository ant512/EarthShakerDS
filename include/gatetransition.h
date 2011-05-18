#ifndef _GATE_TRANSITION_H_
#define _GATE_TRANSITION_H_

#include <graphics.h>

#include "spectrumcolours.h"
#include "transitionbase.h"

/**
 * Simple transition to black that draws lines down the screen.
 */
class GateTransition : public TransitionBase {
public:

	/**
	 * Constructor.
	 * @param topGfx Pointer to the graphics object that draws on the top
	 * physical display.
	 * @param bottomGfx Pointer to the graphics object that draws on the bottom
	 * physical display.
	 */
	GateTransition(WoopsiGfx::Graphics* topGfx, WoopsiGfx::Graphics* bottomGfx) : TransitionBase(topGfx, bottomGfx) {
		_gateSize = 16;
		_iterations = 0;
	}

	/**
	 * Destructor.
	 */
	~GateTransition() { };

	/**
	 * Runs the transition logic.
	 */
	void iterate() {
		s32 x = 0;

		for (s32 i = 0; i < SCREEN_WIDTH / _gateSize; ++i) {
			x = _iterations + (i * _gateSize);

			_topGfx->drawLine(x, 0, x, SCREEN_HEIGHT - 1, COLOUR_BLACK);
			_bottomGfx->drawLine(x, 0, x, SCREEN_HEIGHT - 1, COLOUR_BLACK);
		}

		++_iterations;
	};

	/**
	 * Resets the transition to its initial state.
	 */
	void reset() {
		_iterations = 0;
	};

	/**
	 * Indicates whether or not the transition is running.  If not, calling its
	 * iterate() method should be futile.  The program should move on to the
	 * next section and give up on this transition.
	 * @return True if the transition is running; false if not.
	 */
	bool isRunning() {
		return _iterations < _gateSize;
	};

protected:
	s32 _gateSize;		/**< Size of the gates that are drawn. */
	s32 _iterations;	/**< Number of iterations processed so far. */
};

#endif
