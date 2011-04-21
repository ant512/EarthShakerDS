#ifndef _GAME_H_
#define _GAME_H_

#include <graphics.h>
#include <woopsiarray.h>

#include "blockbase.h"
#include "gamefont.h"
#include "gameoverscreen.h"
#include "levelbase.h"
#include "leveldefinition.h"
#include "logobmp.h"
#include "padstate.h"
#include "playerblock.h"
#include "screenbase.h"
#include "scroller.h"
#include "titlescreen.h"

/**
 * Game class ultimately controls everything in the game.
 */
class Game : public ScreenBase {
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
	 * Updates the game state.  This will redraw the level and move any objects
	 * around.  Redrawing and moving work on a timer system, so calling this
	 * method will not necessarily produce an observable effect if the timers
	 * have not reached the required values.
	 * @param pad State of the DS keypad.
	 */
	void iterate(PadState pad);

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
	 * Informs the game that the player has been killed.  The next call to
	 * iterate() will reset the level or end the game.
	 */
	void killPlayer();

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

private:

	/**
	 * List of all possible states the game can be in.
	 */
	enum GameState {
		GAME_STATE_RUNNING = 1,				/**< Normal gameplay. */
		GAME_STATE_LEVEL_COMPLETE = 2,		/**< Player has completed the level. */
		GAME_STATE_GAME_COMPLETE = 3,		/**< Player has completed the game. */
		GAME_STATE_PLAYER_DEAD = 4,			/**< Player has died. */
		GAME_STATE_PLAYER_SUICIDE = 5,		/**< Player has committed suicide. */
		GAME_STATE_GAME_OVER = 6,			/**< Player has lost all lives. */
		GAME_STATE_GAME_OVER_SCREEN = 7,	/**< Game over screen is displayed. */
		GAME_STATE_TITLE_SCREEN = 8,		/**< Title screen shown. */
		GAME_STATE_STARTUP = 9,				/**< Game is initialising. */
		GAME_STATE_LEVEL_TITLE_SETUP = 10,	/**< Setting up the next level title screen */
		GAME_STATE_LEVEL_TITLE_SCREEN = 11	/**< Level title screen is displayed. */
	};

	LevelBase* _level;						/**< The currently-active level.*/
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
	LogoBmp _logoBmp;						/**< The game's logo. */
	GameState _state;						/**< Current state of the game. */

	WoopsiArray<LevelDefinition*> _levelDefinitions;

	GameOverScreen* _gameOverScreen;		/**< The screen displayed when the game ends. */
	TitleScreen* _titleScreen;				/**< The screen displayed when the game starts. */

	/**
	 * Draws the timer bar.
	 */
	void drawTimerBar();

	/**
	 * Draws the score.
	 */
	void drawScore();

	/**
	 * Draws the count of diamonds remaining and total.
	 */
	void drawDiamondCounters();

	/**
	 * Draws the count of lives remaining.
	 */
	void drawLifeCounter();

	/**
	 * Draws the inverted gravity time remaining.
	 */
	void drawGravityCounter();

	/**
	 * Draws the multicolour timer bar background.
	 */
	void drawTimerBarBackground();

	/**
	 * Draws the gravity direction indicator.
	 */
	void drawGravityIndicator();

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
	 * @param pad State of the DS' keypad.
	 */
	void move(PadState pad);

	/**
	 * Decreases remaining time.  Uses a timer system, so calling the method
	 * will not necessarily produce an effect other than adjusting the
	 * _levelTimer value.
	 */
	void timer();

	/**
	 * Redraws the game.
	 */
	void render();

	/**
	 * Draws the background HUD graphics.  This method should be called just
	 * once at the start of each level.  It draws just the parts that do not
	 * change during the course of a level.
	 */
	void drawHUD();

	/**
	 * Starts the specified level.
	 * @param levelDefinition The level to start.
	 */
	void startLevel(LevelDefinition* levelDefinition);

	/**
	 * Resets the current level to its default state.
	 */
	void resetLevel();

	/**
	 * Decreases the number of lives and redraws the life counter.
	 */
	void decreaseLives();

	/**
	 * Draws the name of the level to the bottom display.
	 */
	void drawLevelName();
};

#endif
