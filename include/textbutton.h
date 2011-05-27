#ifndef _TEXT_BUTTON_H_
#define _TEXT_BUTTON_H_

#include <graphics.h>
#include <woopsistring.h>

#include "buttonbase.h"
#include "gamefont.h"
#include "spectrumcolours.h"

class TextButton : public ButtonBase {
public:
	TextButton(s32 x, s32 y, s32 width, s32 height, s32 id, const WoopsiGfx::WoopsiString& text)
	 : ButtonBase(x, y, width, height, id) {
		_text = text;
	};

	~TextButton() { };

	void render(WoopsiGfx::Graphics* gfx) {
		s32 textWidth = _font.getStringWidth(_text);
		s32 textX = ((_width - textWidth) / 2) + _x;
		s32 textY = ((_height - _font.getHeight()) / 2) + _y;

		u16 backgroundColour = _clicked ? COLOUR_MAGENTA_DARK : COLOUR_MAGENTA;
		
		gfx->drawFilledRect(_x, _y + 1, _width, _height - 2, backgroundColour);
		gfx->drawLine(_x + 1, _y, _x + _width - 2, _y, backgroundColour);
		gfx->drawLine(_x + 1, _y + _height - 1, _x + _width - 2, _y + _height - 1, backgroundColour);

		gfx->drawText(textX, textY, &_font, _text, 0, _text.getLength(), COLOUR_WHITE);
	};

private:
	WoopsiGfx::WoopsiString _text;
	GameFont _font;
};

#endif
