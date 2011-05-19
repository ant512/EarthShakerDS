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
}

void Menu::moveToNextOption() {
	if (_selectedIndex < getTotalOptionCount() - 1) {
		++_selectedIndex;
	} else {
		_selectedIndex = 0;
	}
}

void Menu::moveToPreviousOption() {
	if (_selectedIndex > 0) {
		--_selectedIndex;
	} else {
		_selectedIndex = getTotalOptionCount() - 1;
	}
}

void Menu::moveToNextPage() {
	if (_selectedIndex < getTotalOptionCount() - 4) {
		_selectedIndex += 3;
	} else {
		_selectedIndex = getTotalOptionCount() - 1;
	}
}

void Menu::moveToPreviousPage() {
	if (_selectedIndex > 3) {
		_selectedIndex -= 3;
	} else {
		_selectedIndex = 0;
	}
}

const WoopsiGfx::WoopsiString& Menu::getSelectedOption() const {
	return _options[_selectedIndex];
}

s32 Menu::getTotalOptionCount() const {
	return _options.size() + _subMenus.size();
}

void Menu::setSelectedIndex(s32 index) {

	if (index < 0) index = 0;
	if (index > _options.size() - 1) index = _options.size() - 1;

	_selectedIndex = index;
}

void Menu::addOption(const WoopsiGfx::WoopsiString& option) {
	_options.push_back(option);
}

s32 Menu::getOptionCount() const {
	return _options.size();
}

const WoopsiGfx::WoopsiString& Menu::getOption(s32 index) const {
	return _options[index];
}

Menu* Menu::getSubMenu(s32 index) const {
	return _subMenus[index];
}

bool Menu::isSubMenuSelected() const {
	return _selectedIndex >= _options.size();
}

Menu* Menu::getSelectedSubMenu() const {
	if (!isSubMenuSelected()) return NULL;

	return _subMenus[_selectedIndex - _options.size()];
}

s32 Menu::getSelectedIndex() const {
	return _selectedIndex;
}

void Menu::addSubMenu(Menu* subMenu) {
	subMenu->setParent(this);
	_subMenus.push_back(subMenu);
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
