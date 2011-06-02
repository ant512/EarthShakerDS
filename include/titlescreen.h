#ifndef _TITLE_SCREEN_H_
#define _TITLE_SCREEN_H_

#include <nds.h>
#include <graphics.h>
#include <woopsistring.h>

#include "blockslideshowscreen.h"
#include "gamefont.h"
#include "leveldefinitionbase.h"
#include "logobmp.h"
#include "menu.h"
#include "menulistener.h"
#include "menusystem.h"
#include "screenbase.h"
#include "scroller.h"
#include "spectrumcolours.h"

/**
 * The title screen.
 */
class TitleScreen : public ScreenBase, public MenuListener {
public:

	/**
	 * Constructor.
	 * @param topGfx Pointer to the top display graphics object.
	 * @param bottomGfx Pointer to the bottom display graphics object.
	 * @param levelDefinitions List of all level definitions in the game.
	 */
	TitleScreen(WoopsiGfx::Graphics* topGfx, WoopsiGfx::Graphics* bottomGfx, WoopsiArray<LevelDefinitionBase*>* levelDefinitions);

	/**
	 * Destructor.
	 */
	~TitleScreen();

	/**
	 * Run the screen.
	 */
	void iterate();

	/**
	 * Indicates whether or not the screen is running.  If not, calling its
	 * iterate() method should be futile.  The program should move on to the
	 * next section and give up on this screen.
	 * @return True if the screen is running; false if not.
	 */
	bool isRunning() const;

	/**
	 * Get the start level for the game chosen by the player.
	 * @return The start level for the game.
	 */
	LevelDefinitionBase* getChosenLevel() const;

	/**
	 * Handles any menu selections.
	 * @param source The menu that raised the event.
	 */
	void handleMenuAction(Menu* source);

private:

	/**
	 * List of all menus in the menu system.
	 */
	enum MenuId {
		MENU_MAIN = 1,										/**< The main menu. */
		MENU_LEVEL_SELECT = 2,								/**< The level select menu. */
		MENU_SOUND_TEST = 3									/**< The sound test menu. */
	};

	s32 _timer;												/**< Timer to control speed of user input. */
	GameFont _font;											/**< Font used to draw text. */
	Scroller* _scroller;									/**< Scrolling text message. */
	LogoBmp _logoBmp;										/**< Logo drawn on top display. */
	WoopsiArray<LevelDefinitionBase*>* _levelDefinitions;	/**< List of all level definitions. */
	LevelDefinitionBase* _chosenLevel;						/**< Level selected by the player. */
	BlockSlideshowScreen* _blockSlideshowScreen;			/**< Block slideshow on bottom display. */
	MenuSystem* _menuSystem;								/**< The menu system on the top display. */

	/**
	 * Plays the specified sound.
	 */
	void soundTest(s32 sound);

	/**
	 * Main menu option execution.
	 */
	void mainMenu(s32 option);

	/**
	 * Draws the logo and copyright messages.
	 */
	void renderBackground();
};

#endif
