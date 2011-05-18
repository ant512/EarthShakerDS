#ifndef _MENU_H_
#define _MENU_H_

#include <nds.h>
#include <graphics.h>
#include <woopsiarray.h>
#include <woopsistring.h>

#include "gamefont.h"
#include "hardware.h"
#include "padstate.h"
#include "spectrumcolours.h"

const s32 MENU_Y = 72;				/**< Y co-ordinate of menu. */
const s32 MENU_TITLE_LIST_GAP = 16;	/**< Distance between menu title and options. */

/**
 * Menu of options.
 */
class Menu {
public:

	/**
	 * Constructor.
	 * @param gfx Pointer to the graphics object used for visual output.
	 * @param title Title of the menu.
	 */
	Menu(WoopsiGfx::Graphics* gfx, const WoopsiGfx::WoopsiString& title);

	/**
	 * Destructor.
	 */
	~Menu();

	/**
	 * Runs the menu.
	 */
	void iterate();

	/**
	 * Adds a new option to the end of the menu list.
	 * @param option The text of the option.
	 */
	void addOption(const WoopsiGfx::WoopsiString& option);

	/**
	 * Gets the index of the currently-selected option.
	 * @return The index of the currently-selected option.
	 */
	s32 getSelectedIndex() const;

	/**
	 * Gets the text of the currently-selected option.
	 * @return The text of the currently-selected option.
	 */
	const WoopsiGfx::WoopsiString& getSelectedOption() const;

	/**
	 * Renders the menu.
	 */
	void render();

	/**
	 * Sets the selected index to the specified value.
	 * @param index The new selected index.
	 */
	void setSelectedIndex(s32 index);

private:
	GameFont _font;									/**< Font to use for rendering text. */
	WoopsiArray<WoopsiGfx::WoopsiString> _options;	/**< List of options to choose from. */
	WoopsiGfx::WoopsiString _title;					/**< Title of the menu. */
	s32 _selectedIndex;								/**< Currently-selected index. */
	WoopsiGfx::Graphics* _gfx;						/**< Pointer to the graphics object to draw with. */

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
