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
		_blocks.push_back(new FireBlock(0, 0, NULL));
		_blocks.push_back(new GravityInversionBlock(0, 0, NULL));
		_blocks.push_back(new BarrierBlock(0, 0, NULL));
		_blocks.push_back(new BarrierControlBlock(0, 0, NULL));
		_blocks.push_back(new TeleportBlock(0, 0, NULL));
		_blocks.push_back(new ExtraLifeBlock(0, 0, NULL));
		_blocks.push_back(new DiamondBlock(0, 0, NULL));
		_blocks.push_back(new WetSoilBlock(0, 0, NULL));
		_blocks.push_back(new BeanBlock(0, 0, NULL));
		
	};

	~LevelEditorBlockPanel() {
		for (s32 i = 0; i < _blocks.size(); ++i) {
			delete _blocks[i];
		}
	};

	void iterate() {
		s32 i = 0;

		for (s32 y = 8; y < 168; y += BlockBase::BLOCK_SIZE) {
			for (s32 x = 8; x < 248; x += BlockBase::BLOCK_SIZE) {
				_blocks[i]->render(x, y, _gfx);
				++i;

				if (i == _blocks.size()) return;
			}
		}
	};

private:
	LevelEditor* _levelEditor;
	WoopsiArray<BlockBase*> _blocks;

};

#endif
