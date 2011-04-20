#ifndef _SCROLLER_H_
#define _SCROLLER_H_

#include <nds.h>
#include <graphics.h>
#include <woopsistring.h>

#include "gamefont.h"
#include "spectrumcolours.h"

class Scroller {
public:
	Scroller(const WoopsiGfx::WoopsiString& text);

	~Scroller() { };

	void render(s32 y, WoopsiGfx::Graphics* gfx);

private:
	s32 _offset;
	s32 _stringWidth;
	GameFont _font;
	WoopsiGfx::WoopsiString _text;
};

#endif
