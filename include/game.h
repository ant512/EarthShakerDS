#ifndef _GAME_H_
#define _GAME_H_

#include <graphics.h>

#include "levelbase.h"
#include "blockbase.h"
#include "playerblock.h"
#include "newtopaz.h"

class Game {
public:

	/**
	 * Constructor.
	 * @param topGfx Pointer to the graphics object for the top display.
	 * @param bottomGfx Pointer to the graphics object for the bottom display.
	 */
	Game(WoopsiGfx::Graphics* topGfx, WoopsiGfx::Graphics* bottomGfx);

	/**
	 * Destructor.
	 */
	~Game();

	/**
	 * Get the currently-running level object.
	 * @return The currently-running level object.
	 */
	LevelBase* getLevel() const;

	/**
	 * Gets the player block.
	 * @return The player block.
	 */
	PlayerBlock* getPlayerBlock() const;

	/**
	 * Check if gravity is currently inverted.
	 * @return True if gravity is inverted; false if not.
	 */
	bool isGravityInverted() const;

	/**
	 * Flips gravity from inverted to not and vice-versa.
	 */
	void flipGravity();

	/**
	 * Get the current score.
	 * @return The current score.
	 */
	s32 getScore() const;

	/**
	 * Gets the remaining time for the level.
	 */
	s32 getRemainingTime() const;

	/**
	 * Adds the supplied value to the current score and redraws the score
	 * display.
	 */
	void addScore(s32 score);

	/**
	 * Sets the held state of the up button.
	 * @param upHeld The held state of the up button.
	 */
	void setUpHeld(bool upHeld);

	/**
	 * Sets the held state of the down button.
	 * @param downHeld The held state of the down button.
	 */
	void setDownHeld(bool downHeld);

	/**
	 * Sets the held state of the left button.
	 * @param downHeld The held state of the left button.
	 */
	void setLeftHeld(bool leftHeld);

	/**
	 * Sets the held state of the right button.
	 * @param downHeld The held state of the right button.
	 */
	void setRightHeld(bool rightHeld);

	/**
	 * Updates the game state.  This will redraw the level and move any objects
	 * around.  Redrawing and moving work on a timer system, so calling this
	 * method will not necessarily produce an observable effect if the timers
	 * have not reached the required values.
	 */
	void iterate();

private:
	LevelBase* _level;					/**< The currently-active level.*/
	PlayerBlock* _playerBlock;			/**< The player's block within the level. */
	bool _isGravityInverted;			/**< The inversion state of gravity. */
	s32 _score;							/**< The current score. */
	s32 _remainingTime;					/**< The amount of time remaining. */
	s32 _lives;							/**< The number of lives remaining. */
	WoopsiGfx::Graphics* _topGfx;		/**< The graphics object for the top display. */
	WoopsiGfx::Graphics* _bottomGfx;	/**< The graphics object for the bottom display. */
	NewTopaz _font;						/**< Font used for text output. */
	s32 _animationTimer;				/**< Timer used to moderate animation speed. */
	s32 _movementTimer;					/**< Timer used to moderate movement speed. */

	bool _upHeld;						/**< State of the up button. */
	bool _downHeld;						/**< State of the down button. */
	bool _leftHeld;						/**< State of the left button. */
	bool _rightHeld;					/**< State of the right button. */

	LevelBase* createLevel(u8* data, s32 width, s32 height, s32 number, const WoopsiGfx::WoopsiString& name);

	/**
	 * Decreases the amount of remaining time and redraws the timer bar.
	 */
	void decreaseTime();

	/**
	 * Draws the timer bar.
	 */
	void drawTimerBar();

	/**
	 * Redraws the level.  Uses a timer system, so calling the method will not
	 * necessarily produce an effect other than adjusting the _animationTimer
	 * value.
	 */
	void animate();

	/**
	 * Moves level blocks.  Uses a timer system, so calling the method will not
	 * necessarily produce an effect other than adjusting the _movementTimer
	 * value.
	 */
	void move();

	/**
	 * Redraws the game.
	 */
	void render();
};

#endif
