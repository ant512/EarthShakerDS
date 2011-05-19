#ifndef _MENU_LISTENER_H_
#define _MENU_LISTENER_H_

#include <nds.h>

class Menu;

/**
 * Base class for classes that need to be notified of selections from the Menu
 * class.
 */
class MenuListener {
public:

	/**
	 * Constructor.
	 */
	MenuListener() { };

	/**
	 * Destructor.
	 */
	virtual ~MenuListener() { };

	/**
	 * Handles any menu selections.
	 * @param source The menu that raised the event.
	 */
	virtual void handleMenuAction(Menu* source) = 0;
};

#endif
