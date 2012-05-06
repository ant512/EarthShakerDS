#include "constants.h"
#include "hardware.h"
#include "menusystem.h"
#include "soundplayer.h"

MenuSystem::MenuSystem(MenuListener* listener, WoopsiGfx::Graphics* gfx, WoopsiGfx::WoopsiString title, s32 rootMenuId) {
	_timer = 0;
	_listener = listener;
	_gfx = gfx;
	_state = STATE_NORMAL;

	_rootMenu = new Menu(title, rootMenuId);

	_activeMenu = _rootMenu;
}

MenuSystem::~MenuSystem() {
	delete _rootMenu;
}

Menu* MenuSystem::getRootMenu() const {
	return _rootMenu;
}

void MenuSystem::render() {
	renderTitle();
	renderOptions();
}

void MenuSystem::renderTitle() {
	_gfx->drawFilledRect(0, MENU_Y, SCREEN_WIDTH, _font.getHeight() * 7, COLOUR_BLACK);
	_gfx->drawText((SCREEN_WIDTH - _font.getStringWidth(_activeMenu->getTitle())) / 2, MENU_Y, &_font, _activeMenu->getTitle(), 0, _activeMenu->getTitle().getLength(), COLOUR_WHITE);
}

void MenuSystem::renderOptions() {

	WoopsiGfx::WoopsiString str;
	s32 y = MENU_Y + MENU_TITLE_LIST_GAP;
	SpectrumColour colour = COLOUR_WHITE;

	s32 firstOption = _activeMenu->getSelectedIndex() - 3;
	s32 lastOption = _activeMenu->getSelectedIndex() + 3;

	if (lastOption > _activeMenu->getOptionCount() - 1) {
		lastOption = _activeMenu->getOptionCount() - 1;
	}

	// Wipe area under options and redraw visible option subset
	_gfx->drawFilledRect(0, y, SCREEN_WIDTH, _font.getHeight() * 7, COLOUR_BLACK);

	for (s32 i = firstOption; i <= lastOption; ++i) {

		if (i < 0) {
			y += _font.getHeight();
			continue;
		}

		if (i == _activeMenu->getSelectedIndex()) {
			colour = COLOUR_YELLOW;
		} else {
			colour = COLOUR_CYAN;
		}

		// Draw an option if one is available; otherwise, draw a submenu if one
		// of those is available
		str = _activeMenu->getOptionText(i);

		_gfx->drawText((SCREEN_WIDTH - _font.getStringWidth(str)) / 2, y, &_font, str, 0, str.getLength(), colour);
		y += _font.getHeight();
	}
}


void MenuSystem::iterate() {

	const Pad& pad = Hardware::getPad();

	switch (_state) {
		case STATE_NORMAL:
			iterateMenu();
			break;

		case STATE_SWITCHING_MENU:

			// Wait for buttons to be released so we don't immediately choose an
			// option on the next menu
			if (!pad.isAHeld() && !pad.isStartHeld() && !pad.isBHeld()) {
				_state = STATE_NORMAL;
			}
			break;
	}
}

void MenuSystem::iterateMenu() {

	++_timer;

	if (_timer < MOVEMENT_TIME) return;

	_timer = 0;

	const Pad& pad = Hardware::getPad();

	if (pad.isAHeld() || pad.isStartHeld()) {
		if (_activeMenu->isSubMenuSelected()) {
			
			// Abort if there's nothing to select
			if (_activeMenu->getSelectedSubMenu() == NULL) return;

			// Switch to sub menu
			_activeMenu = _activeMenu->getSelectedSubMenu();
			
			_activeMenu->setSelectedIndex(0);
			render();

			SoundPlayer::playDiamondCollect();
		} else {
			// Raise event
			_listener->handleMenuAction(_activeMenu);
		}

		_state = STATE_SWITCHING_MENU;

	} else if (pad.isBHeld()) {
		if (_activeMenu->getParent() != NULL) {

			// Switch to parent menu
			_activeMenu = _activeMenu->getParent();

			_activeMenu->setSelectedIndex(0);
			render();

			SoundPlayer::playBlockLand();
			_state = STATE_SWITCHING_MENU;
		}
	} else if (pad.isUpHeld()) {
		_activeMenu->moveToPreviousOption();
		SoundPlayer::playBlockFall();
		render();
	} else if (pad.isDownHeld() || pad.isSelectHeld()) {
		_activeMenu->moveToNextOption();
		SoundPlayer::playBlockFall();
		render();
	} else if (pad.isRightHeld()) {
		_activeMenu->moveToNextPage();
		SoundPlayer::playBlockFall();
		render();
	} else if (pad.isLeftHeld()) {
		_activeMenu->moveToPreviousPage();
		SoundPlayer::playBlockFall();
		render();
	}
}
