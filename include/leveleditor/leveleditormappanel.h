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
	};

	void render() {
		_level->renderMap(_gfx);
	};

private:
	Level* _level;
};

#endif
