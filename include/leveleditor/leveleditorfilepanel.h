#ifndef _LEVEL_EDITOR_FILE_PANEL_H_
#define _LEVEL_EDITOR_FILE_PANEL_H_

#include <graphics.h>
#include <woopsistring.h>

#include "buttonbank.h"
#include "buttonlistener.h"
#include "leveleditorpanelbase.h"
#include "spectrumcolours.h"

class LevelEditorFilePanel : public LevelEditorPanelBase, public ButtonListener {
public:
	LevelEditorFilePanel(WoopsiGfx::Graphics* gfx) : LevelEditorPanelBase(gfx) {
		_buttons = new ButtonBank(this, gfx);
	};

	~LevelEditorFilePanel() {
		delete _buttons;
	};

	void iterate() {
		_buttons->iterate();
	};

	void render() {
		_buttons->render();
	};

	/**
	 * Handles any button selections.
	 * @param source The button that raised the event.
	 */
	void handleButtonAction(ButtonBase* source) {
		switch (source->getId()) {
		}
	};

private:
	ButtonBank* _buttons;
};

#endif
