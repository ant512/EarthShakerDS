#ifndef _TITLE_SCREEN_H_
#define _TITLE_SCREEN_H_

#include <nds.h>
#include <graphics.h>
#include <woopsistring.h>

#include "blockdisplayscreen.h"
#include "gamefont.h"
#include "leveldefinition.h"
#include "logobmp.h"
#include "optionlist.h"
#include "screenbase.h"
#include "scroller.h"
#include "spectrumcolours.h"

/**
 * The title screen.
 */
class TitleScreen : public ScreenBase {
public:

	/**
	 * Constructor.
	 * @param topGfx Pointer to the top display graphics object.
	 * @param bottomGfx Pointer to the bottom display graphics object.
	 * @param levelDefinitions List of all level definitions in the game.
	 */
	TitleScreen(WoopsiGfx::Graphics* topGfx, WoopsiGfx::Graphics* bottomGfx, WoopsiArray<LevelDefinition*>* levelDefinitions);

	/**
	 * Destructor.
	 */
	~TitleScreen();

	/**
	 * Run the screen.
	 */
	void iterate();

	/**
	 * Check if the screen is running.
	 * @return True if the screen is running; false if not.
	 */
	bool isRunning() const;

	/**
	 * Get the start level for the game chosen by the player.
	 * @return The start level for the game.
	 */
	LevelDefinition* getChosenLevel() const;

private:
	s32 _timer;									/**< Timer to control speed of user input. */
	GameFont _font;								/**< Font used to draw text. */
	Scroller* _scroller;						/**< Scrolling text message. */
	LogoBmp _logoBmp;							/**< Logo drawn on top display. */
	WoopsiArray<LevelDefinition*>* _levelDefinitions;	/**< List of all level definitions. */
	LevelDefinition* _chosenLevel;				/**< Level selected by the player. */
	BlockDisplayScreen* _blockDisplayScreen;	/**< Block slideshow on bottom display. */
	WoopsiArray<OptionList*> _menu;				/**< Menu system on top display. */
	s32 _activeMenuIndex;						/**< Currently active menu index. */
};

#endif
