#ifndef _LEVEL_EDITOR_BLOCK_PANEL_H_
#define _LEVEL_EDITOR_BLOCK_PANEL_H_

#include <graphics.h>
#include <woopsiarray.h>

#include "barrierblock.h"
#include "barriercontrolblock.h"
#include "beanblock.h"
#include "blockbase.h"
#include "boulderblock.h"
#include "bubbleblock.h"
#include "constants.h"
#include "diamondblock.h"
#include "doorblock.h"
#include "extralifeblock.h"
#include "fireblock.h"
#include "gravityinversionblock.h"
#include "playerblock.h"
#include "soilblock.h"
#include "teleportblock.h"
#include "wallblock.h"
#include "wetsoilblock.h"

#include "leveleditorpanelbase.h"
#include "leveleditor.h"

class LevelEditorBlockPanel : public LevelEditorPanelBase {
public:
	LevelEditorBlockPanel(WoopsiGfx::Graphics* gfx, LevelEditor* levelEditor) : LevelEditorPanelBase(gfx) {
		_levelEditor = levelEditor;

		_blocks.push_back(new BoulderBlock(0, 0, NULL));
		_blocks.push_back(new PlayerBlock(0, 0, NULL));
	};

	~LevelEditorBlockPanel() {};

	void iterate() {
	};

private:
	LevelEditor* _levelEditor;
	WoopsiArray<BlockBase*> _blocks;

};

#endif
