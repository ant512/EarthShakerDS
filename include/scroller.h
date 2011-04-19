#ifndef _SCROLLER_H_
#define _SCROLLER_H_

#include <nds.h>
#include <graphics.h>
#include <woopsistring.h>

#include "gamefont.h"
#include "spectrumcolours.h"

class Scroller {
public:
	Scroller(const WoopsiGfx::WoopsiString& text) {
		_offset = -SCREEN_WIDTH;
		_text = text;

		_stringWidth = _font.getStringWidth(text);
	};

	~Scroller() { };

	void render(s32 y, WoopsiGfx::Graphics* gfx) {
		s32 start = _offset / 8;
		s32 length = SCREEN_WIDTH / 8;
		s32 x = -(_offset % 8);

		if (start < 0) {
			x -= start * 8;
			start = 0;
		}

		gfx->drawFilledRect(0, y, SCREEN_WIDTH, _font.getHeight(), COLOUR_BLACK);
		gfx->drawText(x, y, &_font, _text, start, length, COLOUR_WHITE);

		_offset += 2;

		if (_offset - _stringWidth > 0) _offset = -SCREEN_WIDTH;
	};

private:
	s32 _offset;
	s32 _stringWidth;
	GameFont _font;
	WoopsiGfx::WoopsiString _text;
};

#endif
