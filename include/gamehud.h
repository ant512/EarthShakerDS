#ifndef _GAME_HUD_H_
#define _GAME_HUD_H_

#include <graphics.h>
#include <woopsistring.h>

#include "constants.h"
#include "gamefont.h"
#include "hardware.h"
#include "logobmp.h"
#include "spectrumcolours.h"

/**
 * Heads up display drawn around the level.
 */
class GameHUD {
public:

	/**
	 * Constructor.
	 */
	GameHUD();

	/**
	 * Destructor.
	 */
	~GameHUD() { };

	/**
	 * Draws the timer bar.
	 * @param remainingTime The amount of remaining time.
	 */
	void drawTimerBar(s32 remainingTime);

	/**
	 * Draws the score.
	 * @param score The current score.
	 */
	void drawScore(s32 score);

	/**
	 * Draws the count of diamonds remaining and total.
	 * @param totalDiamonds The total number of diamonds in the current level.
	 * @param collectedDiamonds The number of diamonds collected so far.
	 */
	void drawDiamondCounters(s32 totalDiamonds, s32 collectedDiamonds);

	/**
	 * Draws the count of lives remaining.
	 * @param remainingLives The number of lives remaining.
	 */
	void drawLifeCounter(s32 remainingLives);

	/**
	 * Draws the inverted gravity time remaining.
	 * @param remainingGravityTime The amount of remaining time until gravity
	 * reverts to normal.
	 */
	void drawGravityCounter(s32 remainingGravityTime);

	/**
	 * Draws the multicolour timer bar background.
	 */
	void drawTimerBarBackground();

	/**
	 * Draws the gravity direction indicator.
	 * @param isGravityInverted Indicates whether or not gravity is currently
	 * inverted.
	 */
	void drawGravityIndicator(bool isGravityInverted);

	/**
	 * Draws all of the HUD graphics.  This method should be called just once
	 * once at the start of each level.
	 * @param totalDiamonds The total number of diamonds in the current level.
	 * @param collectedDiamonds The number of diamonds collected so far.
	 * @param remainingGravityTime The amount of remaining time until gravity
	 * reverts to normal.
	 * @param isGravityInverted Indicates whether or not gravity is currently
	 * inverted.
	 * @param remainingLives The number of lives remaining.
	 * @param score The current score.
	 * @param levelName The name of the current level.
	 * @param levelNumber The number of the current level.
	 */
	void drawBackground(s32 totalDiamonds,
						s32 collectedDiamonds,
						s32 remainingGravityTime,
						bool isGravityInverted,
						s32 remainingLives,
						s32 score,
						const WoopsiGfx::WoopsiString& levelName,
						s32 levelNumber);

private:
	WoopsiGfx::Graphics* _topGfx;			/**< Pointer to the graphics object for the top display. */
	WoopsiGfx::Graphics* _bottomGfx;		/**< Pointer to the graphics object for the bottom display. */
	GameFont _font;							/**< Font used for text output. */
	LogoBmp _logoBmp;						/**< The game's logo. */
};

#endif
