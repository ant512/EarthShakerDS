#ifndef _TITLE_SCREEN_H_
#define _TITLE_SCREEN_H_

#include <nds.h>
#include <graphics.h>
#include <woopsistring.h>

#include "logobmp.h"
#include "screenbase.h"
#include "spectrumcolours.h"

class TitleScreen : public ScreenBase {
public:
	TitleScreen(WoopsiGfx::Graphics* topGfx, WoopsiGfx::Graphics* bottomGfx) : ScreenBase(topGfx, bottomGfx) {
		_timer = 200;

		topGfx->drawFilledRect(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, COLOUR_BLACK);
		bottomGfx->drawFilledRect(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, COLOUR_BLACK);

		topGfx->drawBitmap(0, 0, 256, 64, &_logoBmp, 0, 0);

		_scroller = new Scroller(".... Earth Shaker DS - Featuring anti-gravity, "
								 "4D teleport, forcefields, bubbles, elixirs, "
								 "jumping jelly beans and much much more .... Can "
								 "you survive 32 deadly diamond mines ? .... Well "
								 "- it depends if you are sly enough. But watch out "
								 "you don't bang your head, burn yourself or take "
								 "too long .... Coding (c) 2011 Antony Dzeryn .... "
								 "Artwork (c) 1990 Michael Batty ....");
	};

	~TitleScreen() {
		delete _scroller;
	};

	void iterate() {
		--_timer;

		_scroller->render(184, _topGfx);
	};

	bool isRunning() const {
		return _timer > 0;
	};

private:
	s32 _timer;
	GameFont _font;
	Scroller* _scroller;
	LogoBmp _logoBmp;
};

#endif
