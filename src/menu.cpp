#include "constants.h"
#include "menu.h"
#include "soundplayer.h"

Menu::Menu(const WoopsiGfx::WoopsiString& title, s32 id) {
	_selectedIndex = 0;

	_title = title;
	_id = id;

	_parent = NULL;
}

Menu::~Menu() {
	for (s32 i = 0; i < _subMenus.size(); ++i) {
		delete _subMenus[i];
	}

	for (s32 i = 0; i < _options.size(); ++i) {
		delete _options[i];
	}
}

void Menu::moveToNextOption() {
	if (_selectedIndex < getOptionCount() - 1) {

		// Options without text are treated as spaces
		do {
			++_selectedIndex;
		} while (getSelectedText().getLength() == 0);
	} else {
		_selectedIndex = 0;

		// Options without text are treated as spaces
		while (getSelectedText().getLength() == 0) {
			++_selectedIndex;
		}
	}
}

void Menu::moveToPreviousOption() {
	if (_selectedIndex > 0) {

		// Options without text are treated as spaces
		do {
			--_selectedIndex;
		} while (getSelectedText().getLength() == 0);
	} else {
		_selectedIndex = getOptionCount() - 1;

		// Options without text are treated as spaces
		while (getSelectedText().getLength() == 0) {
			--_selectedIndex;
		}
	}
}

void Menu::moveToNextPage() {
	if (_selectedIndex < getOptionCount() - 4) {
		_selectedIndex += 3;

		// Options without text are treated as spaces
		while (getSelectedText().getLength() == 0) {
			++_selectedIndex;
		}
	} else {
		_selectedIndex = getOptionCount() - 1;

		// Options without text are treated as spaces
		while (getSelectedText().getLength() == 0) {
			--_selectedIndex;
		}
	}
}

void Menu::moveToPreviousPage() {
	if (_selectedIndex > 3) {
		_selectedIndex -= 3;

		// Options without text are treated as spaces
		while (getSelectedText().getLength() == 0) {
			--_selectedIndex;
		}
	} else {
		_selectedIndex = 0;


		// Options without text are treated as spaces
		while (getSelectedText().getLength() == 0) {
			++_selectedIndex;
		}
	}
}

void Menu::setSelectedIndex(s32 index) {

	if (index < 0) index = 0;
	if (index > _options.size() - 1) index = _options.size() - 1;

	_selectedIndex = index;

	// Options without text are treated as spaces
	while (getSelectedText().getLength() == 0) {
		++_selectedIndex;
	}
}

void Menu::addOption(const WoopsiGfx::WoopsiString& text, s32 value) {
	MenuOption* menuOption = new MenuOption(text, value, false);
	_options.push_back(menuOption);
}

s32 Menu::getOptionCount() const {
	return _options.size();
}

const WoopsiGfx::WoopsiString& Menu::getOptionText(s32 index) const {
	return _options[index]->getText();
}

s32 Menu::getOptionValue(s32 index) const {
	return _options[index]->getValue();
}

Menu* Menu::getSubMenu(s32 index) const {
	return _subMenus[index];
}

bool Menu::isSubMenuSelected() const {
	return _options[_selectedIndex]->isSubMenu();
}

Menu* Menu::getSelectedSubMenu() const {
	if (!isSubMenuSelected()) return NULL;

	return _subMenus[getSelectedValue()];
}

s32 Menu::getSelectedIndex() const {
	return _selectedIndex;
}

s32 Menu::getSelectedValue() const {
	return _options[_selectedIndex]->getValue();
}

const WoopsiGfx::WoopsiString& Menu::getSelectedText() const {
	return _options[_selectedIndex]->getText();
}

void Menu::addSubMenu(Menu* subMenu) {
	subMenu->setParent(this);
	_subMenus.push_back(subMenu);

	MenuOption* option = new MenuOption(subMenu->getTitle(), _subMenus.size() - 1, true);
	_options.push_back(option);
}

Menu* Menu::getParent() const {
	return _parent;
}

void Menu::setParent(Menu* menu) {
	_parent = menu;
}

s32 Menu::getId() const {
	return _id;
}

const WoopsiGfx::WoopsiString& Menu::getTitle() const {
	return _title;
}
