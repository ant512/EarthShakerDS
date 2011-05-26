#ifndef _LEVEL_EDITOR_BLOCK_PANEL_H_
#define _LEVEL_EDITOR_BLOCK_PANEL_H_

#include <graphics.h>

#include "leveleditor.h"

class LevelEditorBlockPanel : public LevelEditorPanelBase {
public:
	LevelEditorBlockPanel(WoopsiGfx::Graphics* gfx, LevelEditor* levelEditor) : LevelEditorPanelBase(gfx) {
		_levelEditor = levelEditor;
	};

	~LevelEditorMapPanel() {};

	void iterate() {
		drawBorder();
	};

private:
	LevelEditor* _levelEditor;
};

#endif
