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

		// Copyrights
		WoopsiGfx::WoopsiString	str = "ZX (c) 1990 Michael Batty";
		topGfx->drawText((SCREEN_WIDTH - _font.getStringWidth(str)) / 2, 160, &_font, str, 0, str.getLength(), COLOUR_WHITE);

		str.setText("DS (c) 2011 Antony Dzeryn");
		topGfx->drawText((SCREEN_WIDTH - _font.getStringWidth(str)) / 2, 168, &_font, str, 0, str.getLength(), COLOUR_WHITE);

		// High scores
		str.setText("High Scores");
		bottomGfx->drawText((SCREEN_WIDTH - _font.getStringWidth(str)) / 2, 16, &_font, str, 0, str.getLength(), COLOUR_WHITE);

		str.setText("020000  M. Batty");
		bottomGfx->drawText((SCREEN_WIDTH - _font.getStringWidth(str)) / 2, 32, &_font, str, 0, str.getLength(), COLOUR_YELLOW);

		str.setText("016000  M. Batty");
		bottomGfx->drawText((SCREEN_WIDTH - _font.getStringWidth(str)) / 2, 48, &_font, str, 0, str.getLength(), COLOUR_CYAN);

		str.setText("012000  M. Batty");
		bottomGfx->drawText((SCREEN_WIDTH - _font.getStringWidth(str)) / 2, 64, &_font, str, 0, str.getLength(), COLOUR_GREEN);

		str.setText("008000  M. Batty");
		bottomGfx->drawText((SCREEN_WIDTH - _font.getStringWidth(str)) / 2, 80, &_font, str, 0, str.getLength(), COLOUR_MAGENTA);

		str.setText("004000  M. Batty");
		bottomGfx->drawText((SCREEN_WIDTH - _font.getStringWidth(str)) / 2, 96, &_font, str, 0, str.getLength(), COLOUR_RED);

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

	void iterate(PadState pad) {
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
