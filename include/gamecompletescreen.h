#ifndef _GAME_COMPLETE_SCREEN_H_
#define _GAME_COMPLETE_SCREEN_H_

#include <nds.h>
#include <graphics.h>
#include <woopsistring.h>

#include "gamefont.h"
#include "hardware.h"
#include "screenbase.h"
#include "spectrumcolours.h"

/**
 * Displayed when the player completes the game.
 */
class GameCompleteScreen : public ScreenBase {
public:

	/**
	 * Constructor.
	 * Constructor.
	 * @param topGfx Pointer to the graphics object that draws on the top
	 * physical display.
	 * @param bottomGfx Pointer to the graphics object that draws on the bottom
	 * physical display.
	 * @param score The final score achieved by the player.
	 */
	GameCompleteScreen(WoopsiGfx::Graphics* topGfx, WoopsiGfx::Graphics* bottomGfx, s32 score);

	/**
	 * Destructor.
	 */
	~GameCompleteScreen() {};

	/**
	 * Runs the screen logic.
	 */
	void iterate();

	/**
	 * Indicates whether or not the screen is running.  If not, calling its
	 * iterate() method should be futile.  The program should move on to the
	 * next section and give up on this screen.
	 * @return True if the screen is running; false if not.
	 */
	bool isRunning() const;

private:;
	s32 _timer;			/**< Length of time screen has been visible. */
	GameFont _font;		/**< Font to render text with. */
};

#endif
