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

		_cursorX = 0;
		_cursorY = 0;
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

					drawBlock(x, y, block);

					// Redraw the cursor if necessary
					if (_cursorX == x && _cursorY == y) {
						drawCursor();
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
		drawCursor();
	};

	/**
	 * Moves the cursor to the supplied co-ordinates.
	 * @param x The x co-ordinate to move to.
	 * @param y The y co-ordinate to move to.
	 */
	void moveCursorTo(s32 x, s32 y) {

		eraseCursor();

		_cursorX = x;
		_cursorY = y;

		drawCursor();
	};

private:
	Level* _level;			/**< The level being edited. */
	BlockBase** _data;		/**< Local cache of block data. */
	s32 _cursorX;			/**< Cursor x co-ordinate. */
	s32 _cursorY;			/**< Cursor y co-ordinate. */

	/**
	 * Erase the cursor from its current location.
	 */
	void eraseCursor() {
		drawBlock(_cursorX, _cursorY, _level->getBlockAt(_cursorX, _cursorY));
	}

	/**
	 * Draw the cursor.
	 */
	void drawCursor() {
		_gfx->drawRect(BlockBase::BLOCK_MAP_SIZE + (_cursorX * BlockBase::BLOCK_MAP_SIZE), BlockBase::BLOCK_MAP_SIZE + (_cursorY * BlockBase::BLOCK_MAP_SIZE), BlockBase::BLOCK_MAP_SIZE, BlockBase::BLOCK_MAP_SIZE, COLOUR_WHITE);
	};

	/**
	 * Draw the specified block at the specified co-ordinates.
	 * @param x The x co-ordinate of the block.
	 * @param y The y co-ordinate of the block.
	 * @param block Pointer to the block to draw.  If NULL, a black rect is
	 * drawn.
	 */
	void drawBlock(s32 x, s32 y, BlockBase* block) {
		if (block != NULL) {
			block->renderMap(BlockBase::BLOCK_MAP_SIZE + (x * BlockBase::BLOCK_MAP_SIZE), BlockBase::BLOCK_MAP_SIZE + (y * BlockBase::BLOCK_MAP_SIZE), _gfx);
		} else {
			_gfx->drawFilledRect(BlockBase::BLOCK_MAP_SIZE + (x * BlockBase::BLOCK_MAP_SIZE), BlockBase::BLOCK_MAP_SIZE + (y * BlockBase::BLOCK_MAP_SIZE), BlockBase::BLOCK_MAP_SIZE, BlockBase::BLOCK_MAP_SIZE, COLOUR_BLACK);
		}
	};
};

#endif
