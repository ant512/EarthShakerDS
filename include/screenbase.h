#ifndef _SCREEN_BASE_H_
#define _SCREEN_BASE_H_

#include <graphics.h>

class ScreenBase {
public:
	ScreenBase(WoopsiGfx::Graphics* topGfx, WoopsiGfx::Graphics* bottomGfx) {
		_topGfx = topGfx;
		_bottomGfx = bottomGfx;
	};

	virtual ~ScreenBase() {};

	virtual void iterate() = 0;

	virtual bool isRunning() const = 0;

protected:
	WoopsiGfx::Graphics* _topGfx;
	WoopsiGfx::Graphics* _bottomGfx;
};

#endif
