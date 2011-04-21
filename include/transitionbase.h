#ifndef _TRANSITION_BASE_H_
#define _TRANSITION_BASE_H_

#include <graphics.h>

class TransitionBase {
public:
	TransitionBase(WoopsiGfx::Graphics* topGfx, WoopsiGfx::Graphics* bottomGfx) {
		_topGfx = topGfx;
		_bottomGfx = bottomGfx;
	}

	virtual ~TransitionBase() { };

	virtual void iterate() = 0;

	virtual void reset() = 0;

	virtual bool isRunning() = 0;

protected:
	WoopsiGfx::Graphics* _topGfx;
	WoopsiGfx::Graphics* _bottomGfx;
};

#endif
