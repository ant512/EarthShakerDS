#ifndef _GAME_SESSION_H_
#define _GAME_SESSION_H_

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

class GameSession {
public:

	/**
	 * Constructor.
	 */
	GameSession(WoopsiArray<LevelDefinition*>* levelDefinitions, LevelDefinition* startingLevel);

	/**
	 * Destructor.
	 */
	~GameSession();

	/**
	 * Get the currently-running level object.
	 * @return The currently-running level object.
	 */
	Level* getLevel() const;

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
	 * Check if the game is running or not.  The game is running whilst the
	 * player has at least 0 lives.
	 * @return True if the player has at least 0 lives; false if not.
	 */
	bool isRunning() const;

	/**
	 * Check if the game is currently in an odd iteration or an even iteration.
	 * We don't want to iterate over the same block twice during a single
	 * iteration of the game, but this could occur if the block moves to a row
	 * that hasn't been iterated yet.  To prevent this, each block maintains its
	 * own odd iteration boolean.  It flips when the block has been iterated.
	 * If the game and the block's odd iteration bool do not agree when the
	 * block's iteration methods are called, the block rejects the iteration
	 * attempt.
	 * @return True if the game is in an odd iteration; false if it is an even
	 * iteration.
	 */
	bool isOddIteration() const;

	/**
	 * Inverts gravity by setting the gravity inversion timer to its maximum
	 * value.
	 */
	void invertGravity();

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
	 * Main game entry point.  Runs all game logic.
	 */
	void main();

	/**
	 * Increase the number of diamonds collected in the level by one.
	 */
	void increaseCollectedDiamonds();

	/**
	 * Increase the number of lives that the player has.
	 */
	void increaseLives();

	/**
	 * Increase the time remaining by the specified amount.
	 * @param time Amount to increase time by.
	 */
	void increaseTime(s32 time);

	/**
	 * Decreases the amount of remaining time and redraws the timer bar.
	 */
	void decreaseTime();

	/**
	 * Gets the number of remaining diamonds.
	 * @return The number of remaining diamonds.
	 */
	s32 getRemainingDiamonds() const;

	/**
	 * Marks the level as ended.  On the next game iteration, remaining time
	 * will be scored and the next level will be created.
	 */
	void endLevel();

	/**
	 * Redraws the game.
	 */
	void render();

	/**
	 * Decreases the number of lives and redraws the life counter.
	 */
	void decreaseLives();

	bool isGameOver() const;
	bool isGameComplete() const;

	/**
	 * Starts the specified level.
	 * @param levelDefinition The level to start.
	 */
	void startLevel(LevelDefinition* levelDefinition);

	void reset();

private:
	WoopsiGfx::Graphics* _topGfx;			/**< Pointer to the graphics object for the top display. */
	WoopsiGfx::Graphics* _bottomGfx;		/**< Pointer to the graphics object for the bottom display. */

	Level* _level;							/**< The currently-active level.*/
	s32 _remainingGravityTime;				/**< The amount of time left until gravity returns to normal. */
	s32 _score;								/**< The current score. */
	s32 _remainingTime;						/**< The amount of time remaining. */
	s32 _lives;								/**< The number of lives remaining. */
	s32 _collectedDiamonds;					/**< Number of diamonds collected in the level. */
	GameFont _font;							/**< Font used for text output. */
	s32 _animationTimer;					/**< Timer used to moderate animation speed. */
	s32 _movementTimer;						/**< Timer used to moderate movement speed. */
	s32 _levelTimer;						/**< Timer used to decrease remaining level time. */
	bool _isOddIteration;					/**< Indicates whether the game is in an odd or an even iteration. */
	GameHUD* _hud;							/**< Stats, and other graphics that surround the game. */

	WoopsiArray<LevelDefinition*>* _levelDefinitions;	/**< List of all level definitions. */
	bool _isMapAvailable;					/**< True if the map is available to view. */

	bool _isRunning;
	bool _isGameComplete;
	bool _isGameOver;

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
	 * Moves the player based on the current pad state.
	 */
	void movePlayer();

	/**
	 * Decreases remaining time.  Uses a timer system, so calling the method
	 * will not necessarily produce an effect other than adjusting the
	 * _levelTimer value.
	 */
	void timer();

	/**
	 * Resets the current level to its default state.
	 */
	void resetLevel();

	/**
	 * Resets all members associated with level state (diamonds collected, time
	 * remaining, etc) to their default state.  Called before starting or
	 * restarting a level.
	 */
	void resetLevelVariables();

	/**
	 * Pauses the game.
	 */
	void pause();

	/**
	 * Shows the map screen.
	 */
	void showMap();

	/**
	 * Runs the transition between different sections of the game.
	 */
	void runTransition();

	/**
	 * Commits suicide.
	 */
	void commitSuicide();
};

#endif
