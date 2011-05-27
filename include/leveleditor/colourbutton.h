#ifndef _COLOUR_BUTTON_H_
#define _COLOUR_BUTTON_H_

#include <graphics.h>

#include "buttonbase.h"
#include "spectrumcolours.h"

class ColourButton : public ButtonBase {
public:
	ColourButton(s32 x, s32 y, s32 width, s32 height, s32 id, u16 colourLight, u16 colourDark)
	 : ButtonBase(x, y, width, height, id) {
		_colourLight = colourLight;
		_colourDark = colourDark;
	};

	~ColourButton() { };

	void render(WoopsiGfx::Graphics* gfx) {
		u16 backgroundColour = _clicked ? _colourDark : _colourLight;
		
		gfx->drawFilledRect(_x, _y + 1, _width, _height - 2, backgroundColour);
		gfx->drawLine(_x + 1, _y, _x + _width - 2, _y, backgroundColour);
		gfx->drawLine(_x + 1, _y + _height - 1, _x + _width - 2, _y + _height - 1, backgroundColour);
	};

private:
	u16 _colourLight;
	u16 _colourDark;
};

#endif
