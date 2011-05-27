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

#include "bitmapbutton.h"
#include "bitmapserver.h"
#include "buttonlistener.h"
#include "leveleditorpanelbase.h"
#include "leveleditor.h"

#include "playerbmp1.h"

class LevelEditorBlockPanel : public LevelEditorPanelBase, public ButtonListener {
public:
	LevelEditorBlockPanel(WoopsiGfx::Graphics* gfx, LevelEditor* levelEditor) : LevelEditorPanelBase(gfx) {
		_levelEditor = levelEditor;

		_buttons = new ButtonBank(this);

		_buttons->addButton(new BitmapButton(8, 8, 20, 20, 0, &_playerBmp));
	};

	~LevelEditorBlockPanel() {
		delete _buttons;
	};

	void iterate() {
		_buttons->render(_gfx);
	};

	/**
	 * Handles any button selections.
	 * @param source The button that raised the event.
	 */
	void handleButtonAction(ButtonBase* source) {

	}

private:
	LevelEditor* _levelEditor;
	ButtonBank* _buttons;

	PlayerBmp1 _playerBmp;
};

#endif
