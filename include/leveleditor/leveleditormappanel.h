#ifndef _LEVEL_EDITOR_MAP_PANEL_H_
#define _LEVEL_EDITOR_MAP_PANEL_H_

#include <graphics.h>
#include <woopsiarray.h>

#include "blockbase.h"
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
		_data = new BlockBase*[_level->getWidth() * _level->getHeight()];

		for (s32 i = 0; i < _level->getWidth() * _level->getHeight(); ++i) {
			_data[i] = NULL;
		}
	};

	/**
	 * Destructor.
	 */
	~LevelEditorMapPanel() {
		delete[] _data;
	};

	/**
	 * Run a single iteration of the panel logic.
	 */
	void iterate() {
		s32 index = 0;
		BlockBase* block = NULL;

		// Iterate over the cached block data and compare it with the actual
		// level data.  Only draw blocks that have changed.
		for (s32 y = 0; y < _level->getHeight(); ++y) {
			for (s32 x = 0; x < _level->getWidth(); ++x) {
				block = _level->getBlockAt(x, y);

				index = (y * _level->getWidth()) + x;

				if (_data[index] != block) {
					_data[index] = block;

					if (block != NULL) {
						block->renderMap(BlockBase::BLOCK_MAP_SIZE + (x * BlockBase::BLOCK_MAP_SIZE), BlockBase::BLOCK_MAP_SIZE + (y * BlockBase::BLOCK_MAP_SIZE), _gfx);
					} else {
						_gfx->drawFilledRect(BlockBase::BLOCK_MAP_SIZE + (x * BlockBase::BLOCK_MAP_SIZE), BlockBase::BLOCK_MAP_SIZE + (y * BlockBase::BLOCK_MAP_SIZE), BlockBase::BLOCK_MAP_SIZE, BlockBase::BLOCK_MAP_SIZE, woopsiRGB(0, 0, 0));
					}
				}
			}
		}
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
	BlockBase** _data;		/**< Local cache of block data. */
};

#endif
