#ifndef _LEVEL_EDITOR_MAP_PANEL_H_
#define _LEVEL_EDITOR_MAP_PANEL_H_

#include <graphics.h>

#include "level.h"

class LevelEditorMapPanel : public LevelEditorPanelBase {
public:
	LevelEditorMapPanel(WoopsiGfx::Graphics* gfx, Level* level) : LevelEditorPanelBase(gfx) {
		_level = level;
	};

	~LevelEditorMapPanel() {};

	void iterate() {

		// Optimise this - drawing the map every frame kills performance
		_level->renderMap(_gfx);
		drawBorder();
	};

	void erase() {
		_gfx->drawFilledRect(4, 4, 251, 171, COLOUR_BLACK);
	};

private:
	Level* _level;
};

#endif
