#ifndef _MENU_OPTION_H_
#define _MENU_OPTION_H_

#include <nds.h>
#include <woopsiarray.h>

/**
 * A single option in a menu.
 */
class MenuOption {
public:

	/**
	 * Constructor.
	 * @param text Text of the option.
	 * @param value Value of the option.
	 * @param isSubMenu True if the option represents a sub menu; false if not.
	 */
	MenuOption(const WoopsiGfx::WoopsiString& text, s32 value, bool isSubMenu) {
		_text = text;
		_value = value;
		_isSubMenu = isSubMenu;
	};

	/**
	 * Destructor.
	 */
	~MenuOption() { };

	/**
	 * Get the text of the option.
	 * @return The text of the option.
	 */
	const WoopsiGfx::WoopsiString& getText() const {
		return _text;
	};

	/**
	 * Get the value of the option.  If the option represents a sub menu, then
	 * the value refers to the index of the related sub menu in the containing
	 * Menu object's _subMenus vector.  This whole class should probably be
	 * refactored so that this isn't so messy.
	 * @return The value of the option.
	 */
	s32 getValue() const {
		return _value;
	};

	/**
	 * Check if the option represents a sub menu or not.
	 * @return True if the option represents a sub menu; false if not.
	 */
	bool isSubMenu() const {
		return _isSubMenu;
	};

private:
	WoopsiGfx::WoopsiString _text;		/**< The text of the option. */
	s32 _value;							/**< The value of the option. */
	bool _isSubMenu;					/**< Indicates whether or not the option represents a sub menu. */
};

#endif
