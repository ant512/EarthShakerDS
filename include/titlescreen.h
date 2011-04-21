#ifndef _TITLE_SCREEN_H_
#define _TITLE_SCREEN_H_

#include <nds.h>
#include <graphics.h>
#include <woopsistring.h>

#include "gamefont.h"
#include "logobmp.h"
#include "screenbase.h"
#include "scroller.h"
#include "spectrumcolours.h"

class TitleScreen : public ScreenBase {
public:
	TitleScreen(WoopsiGfx::Graphics* topGfx, WoopsiGfx::Graphics* bottomGfx);

	~TitleScreen();

	void iterate(PadState pad);

	bool isRunning() const;

private:
	s32 _timer;
	GameFont _font;
	Scroller* _scroller;
	LogoBmp _logoBmp;
};

#endif
