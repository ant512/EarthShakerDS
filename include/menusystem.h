#ifndef _MENU_SYSTEM_H_
#define _MENU_SYSTEM_H_

#include <nds.h>
#include <graphics.h>
#include <woopsistring.h>

#include "gamefont.h"
#include "menu.h"
#include "menulistener.h"
#include "spectrumcolours.h"

/**
 * Menu system contains menu pages and controls them.
 */
class MenuSystem {
public:

	/**
	 * Constructor.
	 * @param listener Listener that reacts to selections within the menu
	 * system.
	 * @param gfx Pointer to the graphics object.
	 * @param title Title of the root menu.
	 * @param rootMenuId ID of the root menu.
	 */
	MenuSystem(MenuListener* listener, WoopsiGfx::Graphics* gfx, WoopsiGfx::WoopsiString title, s32 rootMenuId, s32 y, s32 width, s32 titleGap);

	/**
	 * Destructor.
	 */
	~MenuSystem();

	/**
	 * Gets the root menu.
	 * @return The root menu.
	 */
	Menu* getRootMenu() const;

	/**
	 * Run the menu system.
	 */
	void iterate();

	/**
	 * Draws the menu system.  Typically this will only be used once - when the
	 * menu is first built - as it redraws itself when necessary after that
	 * point.
	 */
	void render();

private:

	/**
	 * List of states that the menu can be in.
	 */
	enum MenuState {
		STATE_NORMAL = 1,								/**< Normal operation. */
		STATE_SWITCHING_MENU = 2						/**< Switching to the next menu. */
	};

	s32 _timer;											/**< Timer to control speed of user input. */
	GameFont _font;										/**< Font used to draw text. */
	WoopsiGfx::Graphics* _gfx;							/**< Graphics object used for drawing. */
	MenuState _state;									/**< Current state of the menu system. */
	Menu* _rootMenu;									/**< The top of the menu tree. */
	Menu* _activeMenu;									/**< The currently active menu. */
	MenuListener* _listener;							/**< Listener that processes selections. */
	s32 _y;
	s32 _width;
	s32 _titleGap;
	
	/**
	 * Runs the active menu.
	 */
	void iterateMenu();

	/**
	 * Renders the menu title.
	 */
	void renderTitle();

	/**
	 * Renders the visible subset of menu options.
	 */
	void renderOptions();
};

#endif
