#ifndef _LEVEL_EDITOR_PANEL_BASE_H_
#define _LEVEL_EDITOR_PANEL_BASE_H_

#include <graphics.h>

#include "spectrumcolours.h"

class LevelEditorPanelBase {
public:
	LevelEditorPanelBase(WoopsiGfx::Graphics* gfx) {
		_gfx = gfx;
	};

	virtual ~LevelEditorPanelBase() {};
	virtual void iterate() = 0;

	void erase() {
		_gfx->drawFilledRect(4, 4, 251, 171, COLOUR_BLACK);
	};

protected:
	WoopsiGfx::Graphics* _gfx;

	void drawBorder() {
		// Top border
		_gfx->drawLine(5, 4, 250, 4, COLOUR_MAGENTA);
		_gfx->drawLine(4, 5, 251, 5, COLOUR_MAGENTA);

		// Left border
		_gfx->drawLine(4, 5, 4, 170, COLOUR_MAGENTA);
		_gfx->drawLine(5, 5, 5, 170, COLOUR_MAGENTA);

		// Right border
		_gfx->drawLine(250, 5, 250, 170, COLOUR_MAGENTA);
		_gfx->drawLine(251, 5, 251, 170, COLOUR_MAGENTA);

		// Bottom border
		_gfx->drawLine(5, 171, 250, 171, COLOUR_MAGENTA);
		_gfx->drawLine(4, 170, 250, 170, COLOUR_MAGENTA);
	};
};

#endif
