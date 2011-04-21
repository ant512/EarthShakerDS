#ifndef _GATE_TRANSITION_H_
#define _GATE_TRANSITION_H_

#include <graphics.h>

#include "spectrumcolours.h"
#include "transitionbase.h"

class GateTransition : public TransitionBase {
public:
	GateTransition(WoopsiGfx::Graphics* topGfx, WoopsiGfx::Graphics* bottomGfx) : TransitionBase(topGfx, bottomGfx) {
		_gateSize = 16;
		_iterations = 0;
	}

	~GateTransition() { };

	void iterate() {
		s32 x = 0;

		for (s32 i = 0; i < SCREEN_WIDTH / _gateSize; ++i) {
			x = _iterations + (i * _gateSize);

			_topGfx->drawLine(x, 0, x, SCREEN_HEIGHT - 1, COLOUR_BLACK);
			_bottomGfx->drawLine(x, 0, x, SCREEN_HEIGHT - 1, COLOUR_BLACK);
		}

		++_iterations;
	};

	void reset() {
		_iterations = 0;
	};

	bool isRunning() {
		return _iterations < _gateSize;
	};

protected:
	s32 _gateSize;
	s32 _iterations;
};

#endif
