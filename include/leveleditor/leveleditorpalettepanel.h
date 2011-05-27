#ifndef _LEVEL_EDITOR_PALETTE_PANEL_H_
#define _LEVEL_EDITOR_PALETTE_PANEL_H_

#include <graphics.h>
#include <woopsistring.h>

#include "gamefont.h"
#include "leveleditorpanelbase.h"
#include "spectrumcolours.h"

class LevelEditorPalettePanel : public LevelEditorPanelBase {
public:
	LevelEditorPalettePanel(WoopsiGfx::Graphics* gfx) : LevelEditorPanelBase(gfx) {

	};

	~LevelEditorPalettePanel() {};

	void iterate() {
	};

	void render() {
		WoopsiGfx::WoopsiString str = "Boulders:";

		_gfx->drawText(8, 8, &_font, str, 0, str.getLength(), COLOUR_WHITE);

		str = "Soil:";
		_gfx->drawText(8, 32, &_font, str, 0, str.getLength(), COLOUR_WHITE);

		str = "Brick Wall:";
		_gfx->drawText(8, 56, &_font, str, 0, str.getLength(), COLOUR_WHITE);
	};

private:
	GameFont _font;
};

#endif
