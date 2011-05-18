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

const s32 OPTION_LIST_Y = 72;				/**< Y co-ordinate of menu. */
const s32 OPTION_LIST_TITLE_LIST_GAP = 16;	/**< Distance between menu title and options. */

class Menu {
public:
	Menu(WoopsiGfx::Graphics* gfx, const WoopsiGfx::WoopsiString& title);

	~Menu();

	void iterate();

	void addOption(const WoopsiGfx::WoopsiString& option);

	s32 getSelectedIndex() const;

	const WoopsiGfx::WoopsiString& getSelectedOption() const;

	void render();

	void setSelectedIndex(s32 index);

private:
	GameFont _font;
	WoopsiArray<WoopsiGfx::WoopsiString> _options;
	WoopsiGfx::WoopsiString _title;
	s32 _selectedIndex;
	WoopsiGfx::Graphics* _gfx;

	void renderTitle();
	void renderOptions();
};

#endif
