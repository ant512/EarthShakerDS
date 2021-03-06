#ifndef _MENU_H_
#define _MENU_H_

#include <nds.h>
#include <graphics.h>
#include <woopsiarray.h>
#include <woopsistring.h>

#include "gamefont.h"
#include "hardware.h"
#include "menuoption.h"
#include "pad.h"
#include "spectrumcolours.h"

/**
 * Menu of options.
 */
class Menu {
public:

	/**
	 * Constructor.
	 * @param title Title of the menu.
	 * @param id Unique ID for the menu.
	 */
	Menu(const WoopsiGfx::WoopsiString& title, s32 id);

	/**
	 * Destructor.  Deletes the entire tree of menus automatically.
	 */
	~Menu();

	/**
	 * Adds a new option to the end of the menu list.
	 * @param text The text of the option.
	 * @param value The value of the option.
	 */
	void addOption(const WoopsiGfx::WoopsiString& text, s32 value);

	/**
	 * Get the number of options in the menu.
	 * @return The number of options in the menu.
	 */
	s32 getOptionCount() const;

	/**
	 * Gets the text of the specified option.
	 * @param index The index of the option to retrieve.
	 * @return The text of the option.
	 */
	const WoopsiGfx::WoopsiString& getOptionText(s32 index) const;

	/**
	 * Gets the value of the specified option.
	 * @param index The index of the option to retrieve.
	 * @return The value of the option.
	 */
	s32 getOptionValue(s32 index) const;

	/**
	 * Gets the specified sub menu.
	 * @param index The index of the sub menu to retrieve.
	 * @return The sub menu.
	 */
	Menu* getSubMenu(s32 index) const;

	/**
	 * Get the selected sub menu.
	 * @return The selected sub menu if one is selected, or NULL if not.
	 */
	Menu* getSelectedSubMenu() const;

	/**
	 * Check if a sub menu is selected.
	 * @return True if a sub menu is selected; false if not (either an option is
	 * selected instead, or the menu is empty).
	 */
	bool isSubMenuSelected() const;

	/**
	 * Adds the supplied menu into this menu's list of sub menus.
	 * @param subMenu The sub menu to add.
	 */
	void addSubMenu(Menu* subMenu);

	/**
	 * Set the parent of this menu to the supplied menu.  Automatically called
	 * by addSubMenu() when adding a menu to another.
	 * @param menu The menu to set as this menu's parent.
	 */
	void setParent(Menu* menu);

	/**
	 * Get the parent of the current menu.  Returns NULL if the menu has no
	 * parent.
	 * @return The parent of the current menu.
	 */
	Menu* getParent() const;

	/**
	 * Gets the ID of the menu.
	 */
	s32 getId() const;

	/**
	 * Moves the selected index to the next option, or wraps to the top if
	 * necessary.
	 */
	void moveToNextOption();

	/**
	 * Moves the selected index to the previous option, or wraps to the bottom
	 * if necessary.
	 */
	void moveToPreviousOption();

	/**
	 * Moves the selected index to the next page.
	 */
	void moveToNextPage();

	/**
	 * Moves the selected index to the previous page.
	 */
	void moveToPreviousPage();

	/**
	 * Gets the title of the menu.
	 * @return The title of the menu.
	 */
	const WoopsiGfx::WoopsiString& getTitle() const;

	/**
	 * Gets the index of the currently-selected option.
	 * @return The index of the currently-selected option.
	 */
	s32 getSelectedIndex() const;

	/**
	 * Gets the value of the currently-selected option.
	 * @return The value of the currently-selected option.
	 */
	s32 getSelectedValue() const;

	/**
	 * Gets the text of the currently-selected option.
	 * @return The text of the currently-selected option.
	 */
	const WoopsiGfx::WoopsiString& getSelectedText() const;

	/**
	 * Sets the selected index to the specified value.
	 * @param index The new selected index.
	 */
	void setSelectedIndex(s32 index);

private:
	WoopsiArray<MenuOption*> _options;					/**< List of all options. */
	WoopsiGfx::WoopsiString _title;						/**< Title of the menu. */
	s32 _selectedIndex;									/**< Currently-selected index. */
	WoopsiArray<Menu*> _subMenus;						/**< List of sub menus. */
	Menu* _parent;										/**< The menu's parent menu. */
	s32 _id;											/**< The ID of the menu. */
};

#endif
