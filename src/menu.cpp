#include "constants.h"
#include "menu.h"
#include "soundplayer.h"

Menu::Menu(WoopsiGfx::Graphics* gfx, const WoopsiGfx::WoopsiString& title) {
	_selectedIndex = 0;

	_gfx = gfx;
	_title = title;
}

Menu::~Menu() {
}

void Menu::iterate() {

	const PadState& pad = Hardware::getPadState();
	
	if (pad.up) {
		if (_selectedIndex > 0) {
			--_selectedIndex;

			SoundPlayer::playBlockFall();
			render();
		} else {
			_selectedIndex = _options.size() - 1;

			SoundPlayer::playBlockFall();
			render();
		}
	} else if (pad.down || pad.select) {
		if (_selectedIndex < _options.size() - 1) {
			++_selectedIndex;

			SoundPlayer::playBlockFall();
			render();
		} else {
			_selectedIndex = 0;

			SoundPlayer::playBlockFall();
			render();
		}
	} else if (pad.right) {
		if (_selectedIndex < _options.size() - 4) {
			_selectedIndex += 3;
		} else {
			_selectedIndex = _options.size() - 1;
		}

		SoundPlayer::playBlockFall();
		render();

	} else if (pad.left) {
		if (_selectedIndex > 3) {
			_selectedIndex -= 3;
		} else {
			_selectedIndex = 0;
		}

		SoundPlayer::playBlockFall();
		render();
	}
}

const WoopsiGfx::WoopsiString& Menu::getSelectedOption() const {
	return _options[_selectedIndex];
}

void Menu::setSelectedIndex(s32 index) {

	if (index < 0) index = 0;
	if (index > _options.size() - 1) index = _options.size() - 1;

	_selectedIndex = index;
}

void Menu::addOption(const WoopsiGfx::WoopsiString& option) {
	_options.push_back(option);
}

s32 Menu::getSelectedIndex() const {
	return _selectedIndex;
}

void Menu::render() {
	renderTitle();
	renderOptions();
}

void Menu::renderTitle() {
	_gfx->drawFilledRect(0, MENU_Y, SCREEN_WIDTH, _font.getHeight() * 7, COLOUR_BLACK);
	_gfx->drawText((SCREEN_WIDTH - _font.getStringWidth(_title)) / 2, MENU_Y, &_font, _title, 0, _title.getLength(), COLOUR_WHITE);
}

void Menu::renderOptions() {

	WoopsiGfx::WoopsiString str;
	s32 y = MENU_Y + MENU_TITLE_LIST_GAP;
	SpectrumColour colour = COLOUR_WHITE;

	s32 firstOption = _selectedIndex - 3;
	s32 lastOption = _selectedIndex + 3;

	// Wipe area under options and redraw visible option subset
	_gfx->drawFilledRect(0, y, SCREEN_WIDTH, _font.getHeight() * 7, COLOUR_BLACK);

	for (s32 i = firstOption; i <= lastOption; ++i) {
		if ((i >= 0) && (i < _options.size())) {
			if (i == _selectedIndex) {
				colour = COLOUR_YELLOW;
			} else {
				colour = COLOUR_CYAN;
			}

			str = _options.at(i);
			_gfx->drawText((SCREEN_WIDTH - _font.getStringWidth(str)) / 2, y, &_font, str, 0, str.getLength(), colour);
		}

		y += _font.getHeight();
	}
}
