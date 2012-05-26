#ifndef _LEVEL_EDITOR_FILE_PANEL_H_
#define _LEVEL_EDITOR_FILE_PANEL_H_

#include <graphics.h>
#include <woopsiarray.h>
#include <woopsistring.h>

#include "blocktype.h"
#include "buttonbank.h"
#include "buttonlistener.h"
#include "level.h"
#include "leveleditor.h"
#include "leveleditorpanelbase.h"
#include "spectrumcolours.h"
#include "textbutton.h"
#include "bitmapbutton.h"

#include "gamesession.h"
#include "stylus.h"
#include "hardware.h"

/**
 * Panel with options for loading and saving the current level.
 */
class LevelEditorFilePanel : public LevelEditorPanelBase, public ButtonListener  {
public:

	/**
	 * Constructor.
	 * @param gfx Graphics object to draw with.
	 * @param editor Pointer to the editor that owns the panel.
	 */
	LevelEditorFilePanel(WoopsiGfx::Graphics* gfx, LevelEditor* editor) : LevelEditorPanelBase(gfx) {
		_editor = editor;

		_buttons = new ButtonBank(this, gfx);

		_buttons->addButton(new TextButton(208, 100, 40, 20, 0, "Load"));
		_buttons->addButton(new TextButton(208, 124, 40, 20, 1, "Save"));
		
		_buttons->addButton(new TextButton(8, 100, 16, 20, 2, "Q"));
		_buttons->addButton(new TextButton(26, 100, 16, 20, 3, "W"));
		_buttons->addButton(new TextButton(44, 100, 16, 20, 4, "E"));
		_buttons->addButton(new TextButton(62, 100, 16, 20, 5, "R"));
		_buttons->addButton(new TextButton(80, 100, 16, 20, 6, "T"));
		_buttons->addButton(new TextButton(98, 100, 16, 20, 7, "Y"));
		_buttons->addButton(new TextButton(116, 100, 16, 20, 8, "U"));
		_buttons->addButton(new TextButton(134, 100, 16, 20, 9, "I"));
		_buttons->addButton(new TextButton(152, 100, 16, 20, 10, "O"));
		_buttons->addButton(new TextButton(170, 100, 16, 20, 11, "P"));
		
		_buttons->addButton(new TextButton(16, 124, 16, 20, 12, "A"));
		_buttons->addButton(new TextButton(34, 124, 16, 20, 13, "S"));
		_buttons->addButton(new TextButton(52, 124, 16, 20, 14, "D"));
		_buttons->addButton(new TextButton(70, 124, 16, 20, 15, "F"));
		_buttons->addButton(new TextButton(88, 124, 16, 20, 16, "G"));
		_buttons->addButton(new TextButton(106, 124, 16, 20, 17, "H"));
		_buttons->addButton(new TextButton(124, 124, 16, 20, 18, "J"));
		_buttons->addButton(new TextButton(142, 124, 16, 20, 19, "K"));
		_buttons->addButton(new TextButton(160, 124, 16, 20, 20, "L"));
		
		_buttons->addButton(new TextButton(24, 148, 16, 20, 21, "Z"));
		_buttons->addButton(new TextButton(42, 148, 16, 20, 22, "X"));
		_buttons->addButton(new TextButton(60, 148, 16, 20, 23, "C"));
		_buttons->addButton(new TextButton(78, 148, 16, 20, 24, "V"));
		_buttons->addButton(new TextButton(96, 148, 16, 20, 25, "B"));
		_buttons->addButton(new TextButton(114, 148, 16, 20, 26, "N"));
		_buttons->addButton(new TextButton(132, 148, 16, 20, 27, "M"));
		_buttons->addButton(new TextButton(150, 148, 24, 20, 28, "SP"));
		_buttons->addButton(new TextButton(176, 148, 24, 20, 29, "BK"));
		
		_buttons->addButton(new TextButton(208, 148, 40, 20, 30, "DEL"));
		
		_buttons->addButton(new TextButton(238, 8, 10, 32, 31, ""));
		_buttons->addButton(new TextButton(238, 44, 10, 32, 32, ""));
		
		_filenames = LevelIO::getLevelNames();
		
		_selectedFilenameIndex = -1;
		_topFilenameIndex = 0;
	};

	/**
	 * Destructor.
	 */
	~LevelEditorFilePanel() {
		delete _buttons;
		delete _filenames;
	};

	/**
	 * Run a single iteration of the panel logic.
	 */
	void iterate() {
		_buttons->iterate();
		processFileListClick();
	};
	
	void processFileListClick() {
		Stylus stylus = Hardware::getStylus();
		
		if (!stylus.isHeld()) return;
		if (stylus.getX() < 10 || stylus.getX() >= SCREEN_WIDTH - 20) return;
		if (stylus.getY() < 10 || stylus.getY() >= 74) return;
		
		int clickedIndex = ((stylus.getY() - 10) / 8) + _topFilenameIndex;
		if (clickedIndex == _selectedFilenameIndex) return;
		
		if (clickedIndex > _filenames->size() - 1) return;
		
		_selectedFilenameIndex = clickedIndex;
		_filename = _filenames->at(clickedIndex);
		
		renderLevelFileNames();
		renderFilenameTextBox();
	};

	/**
	 * Draw the panel.  Should be called when the panel is first displayed;
	 * after that, the iterate() method redraws when needed.
	 */
	void render() {
		renderLevelFileNames();
		_buttons->render();
		renderFilenameTextBox();
	};
	
	void renderLevelFileNames() {
		_gfx->drawFilledRect(10, 10, SCREEN_WIDTH - 30, 64, COLOUR_BLACK);
		
		if (_selectedFilenameIndex >= _topFilenameIndex && _selectedFilenameIndex < _topFilenameIndex + 8) {
			_gfx->drawFilledRect(10, ((_selectedFilenameIndex - _topFilenameIndex) * 8) + 10, SCREEN_WIDTH - 30, 8, COLOUR_YELLOW);
		}
		
		GameFont *font = new GameFont();
		
		int filenameCount = _filenames->size() < 8 ? _filenames->size() : 8;
		
		for (int i = _topFilenameIndex; i < _topFilenameIndex + filenameCount; ++i) {
			
			u16 colour = _selectedFilenameIndex == i ? COLOUR_BLACK : COLOUR_WHITE;
			
			_gfx->drawText(10, 10 + ((i - _topFilenameIndex) * 8), font, _filenames->at(i), 0, _filenames->at(i).getLength(), colour);
		}
	};

	/**
	 * Handles any button selections.
	 * @param source The button that raised the event.
	 */
	void handleButtonAction(ButtonBase* source) {
		switch (source->getId()) {
			case 0:
				if (_filename.getLength() > 0) {
					_editor->loadLevel(_filename);
				}
				break;
			case 1:
				if (_filename.getLength() > 0) {
					_editor->saveLevel(_filename);
					
					// Reload the list of levels
					delete _filenames;
					
					_filenames = LevelIO::getLevelNames();
					
					renderLevelFileNames();
				}
				break;
			case 30:
				if (_filename.getLength() > 0) {
					_editor->deleteLevel(_filename);
					
					// Reload the list of levels
					delete _filenames;
					
					_filenames = LevelIO::getLevelNames();
					if (_selectedFilenameIndex > _filenames->size() - 1) {
						_selectedFilenameIndex = -1;
					} else if (_selectedFilenameIndex > -1) {
						_filename = _filenames->at(_selectedFilenameIndex);
						renderFilenameTextBox();
					}
					
					renderLevelFileNames();
				}
				break;
			case 28:
				if (_filename.getLength() < 28) {
					_filename.append(" ");
					renderFilenameTextBox();
				}
				break;
			case 29:
				_filename.remove(_filename.getLength() - 1);
				renderFilenameTextBox();
				break;
			case 32:
				if (_topFilenameIndex + 8 < _filenames->size()) {
					++_topFilenameIndex;
					renderLevelFileNames();
				}
				break;
			case 31:
				if (_topFilenameIndex > 0) {
					--_topFilenameIndex;
					renderLevelFileNames();
				}
				break;
			default:
				if (_filename.getLength() < 28) {
					_filename.append(((TextButton*)source)->getText());
					renderFilenameTextBox();
				}
				break;
		}
	};
	
	void renderFilenameTextBox() {
		_gfx->drawRect(10, 80, 236, 16, COLOUR_WHITE);
		_gfx->drawFilledRect(11, 81, 234, 14, COLOUR_BLACK);
		
		GameFont* font = new GameFont();
		_gfx->drawText(14, 84, font, _filename, 0, _filename.getLength(), COLOUR_WHITE);
		delete font;
	};
	
private:
	ButtonBank* _buttons;		/**< Collection of buttons in the panel. */
	LevelEditor* _editor;		/**< Pointer to the owning level editor. */
	WoopsiGfx::WoopsiString _filename;	/**< The filename to load/save. */
	WoopsiArray<WoopsiGfx::WoopsiString>* _filenames;
	int _selectedFilenameIndex;
	int _topFilenameIndex;
};

#endif
