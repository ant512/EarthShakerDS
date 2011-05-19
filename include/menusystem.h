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
	 * @param gfx Pointer to the graphics object.
	 */
	MenuSystem(MenuListener* listener, WoopsiGfx::Graphics* gfx, WoopsiGfx::WoopsiString title, s32 rootMenuId);

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
		STATE_NEXT_MENU = 2,							/**< Switching to the next menu. */
		STATE_PREVIOUS_MENU = 3							/**< Switching to the previous menu. */
	};

	static const s32 MENU_Y = 72;						/**< Y co-ordinate of menu. */
	static const s32 MENU_TITLE_LIST_GAP = 16;			/**< Distance between menu title and options. */

	s32 _timer;											/**< Timer to control speed of user input. */
	GameFont _font;										/**< Font used to draw text. */
	WoopsiGfx::Graphics* _gfx;							/**< Graphics object used for drawing. */
	MenuState _state;									/**< Current state of the menu system. */
	Menu* _rootMenu;									/**< The top of the menu tree. */
	Menu* _activeMenu;									/**< The currently active menu. */
	MenuListener* _listener;							/**< Listener that processes selections. */

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
