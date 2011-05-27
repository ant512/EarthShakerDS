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
		_gfx->drawFilledRect(8, 8, 240, 160, COLOUR_BLACK);
	};

protected:
	WoopsiGfx::Graphics* _gfx;
};

#endif
