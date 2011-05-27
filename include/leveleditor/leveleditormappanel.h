#ifndef _LEVEL_EDITOR_MAP_PANEL_H_
#define _LEVEL_EDITOR_MAP_PANEL_H_

#include <graphics.h>

#include "level.h"

/**
 * Panel that shows the map of the current level.
 */
class LevelEditorMapPanel : public LevelEditorPanelBase {
public:

	/**
	 * Constructor.
	 * @param gfx Graphics object to draw with.
	 * @param level The level being edited.
	 */
	LevelEditorMapPanel(WoopsiGfx::Graphics* gfx, Level* level) : LevelEditorPanelBase(gfx) {
		_level = level;
	};

	/**
	 * Destructor.
	 */
	~LevelEditorMapPanel() {};

	/**
	 * Run a single iteration of the panel logic.
	 */
	void iterate() {

		// Optimise this - drawing the map every frame kills performance
		_level->renderMap(_gfx);
	};

	/**
	 * Draw the panel.  Should be called when the panel is first displayed;
	 * after that, the iterate() method redraws when needed.
	 */
	void render() {
		_level->renderMap(_gfx);
	};

private:
	Level* _level;			/**< The level being edited. */
};

#endif
