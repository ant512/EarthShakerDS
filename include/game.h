#ifndef _GAME_H_
#define _GAME_H_

#include <graphics.h>
#include <woopsiarray.h>

#include "blockbase.h"
#include "gamecompletescreen.h"
#include "gamefont.h"
#include "gamehud.h"
#include "gameoverscreen.h"
#include "gatetransition.h"
#include "hardware.h"
#include "level.h"
#include "leveldefinition.h"
#include "padstate.h"
#include "playerblock.h"
#include "scroller.h"
#include "titlescreen.h"

/**
 * Game class ultimately controls everything in the game.
 */
class Game {
public:

	/**
	 * Constructor.
	 */
	Game();

	/**
	 * Destructor.
	 */
	~Game();

	/**
	 * Always returns true.
	 */
	bool isRunning() const;

	/**
	 * Main game entry point.  Runs all game logic.
	 */
	void main();

private:

	WoopsiGfx::Graphics* _topGfx;			/**< Pointer to the graphics object for the top display. */
	WoopsiGfx::Graphics* _bottomGfx;		/**< Pointer to the graphics object for the bottom display. */

	GameSession* _session;

	WoopsiArray<LevelDefinition*> _levelDefinitions;	/**< List of all level definitions. */

	/**
	 * Runs the title screen.
	 */
	void runTitleScreen();

	/**
	 * Runs the game over screen.
	 */
	void runGameOver();

	/**
	 * Runs the transition between different sections of the game.
	 */
	void runTransition();

	/**
	 * Runs the game complete screen.
	 */
	void runGameComplete();
};

#endif
