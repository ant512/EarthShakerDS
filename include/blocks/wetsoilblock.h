#ifndef _WET_SOIL_BLOCK_H_
#define _WET_SOIL_BLOCK_H_

#include <graphics.h>
#include <bitmap.h>

#include "blockbase.h"
#include "constants.h"
#include "gamesession.h"
#include "soundplayer.h"

#include "wetsoilbmp1.h"
#include "wetsoilbmp2.h"
#include "wetsoilbmp3.h"
#include "wetsoilbmp4.h"
#include "soilmapbmp.h"

/**
 * Wet soil works the same way as ordinary soil, except it falls like boulders
 * whenever possible.
 */
class WetSoilBlock : public BlockBase {
public:

	/**
	 * Constructor.
	 * @param x The x co-ordinate within the level map of the block.
	 * @param y The y co-ordinate within tne level map of the block.
	 * @param game Pointer to the game that contains the block.
	 */
	WetSoilBlock(s32 x, s32 y, GameSession* game) : BlockBase(x, y, game) {
		_isHeavy = true;

		_animation->addFrame(&_bmp1, 0);
		_animation->addFrame(&_bmp2, 0);
		_animation->addFrame(&_bmp3, 0);
		_animation->addFrame(&_bmp4, 0);
		_animation->play();

		_mapBitmap = new SoilMapBmp();
	};

	/**
	 * Destructor.
	 */
	~WetSoilBlock() {
		delete _mapBitmap;
	};

	/**
	 * Removes the block.
	 * @return True.
	 */
	bool digFromBelow() {
		_game->getLevel()->removeBlockAt(_x, _y);
		SoundPlayer::playSoilDig();
		return true;
	};

	/**
	 * Removes the block.
	 * @return True.
	 */
	bool digFromAbove() {
		_game->getLevel()->removeBlockAt(_x, _y);
		SoundPlayer::playSoilDig();
		return true;
	};

	/**
	 * Removes the block.
	 * @return True.
	 */
	bool digFromLeft() {
		_game->getLevel()->removeBlockAt(_x, _y);
		SoundPlayer::playSoilDig();
		return true;
	};

	/**
	 * Removes the block.
	 * @return True.
	 */
	bool digFromRight() {
		_game->getLevel()->removeBlockAt(_x, _y);
		SoundPlayer::playSoilDig();
		return true;
	};

	/**
	 * Removes the block.
	 */
	void pokeLeft() {
		_game->getLevel()->removeBlockAt(_x, _y);
		//SoundPlayer::playSoilPoke();
	};

	/**
	 * Removes the block.
	 */
	void pokeRight() {
		_game->getLevel()->removeBlockAt(_x, _y);
		//SoundPlayer::playSoilPoke();
	};

	/**
	 * Removes the block.
	 */
	void pokeUp() {
		_game->getLevel()->removeBlockAt(_x, _y);
		//SoundPlayer::playSoilPoke();
	};

	/**
	 * Removes the block.
	 */
	void pokeDown() {
		_game->getLevel()->removeBlockAt(_x, _y);
		//SoundPlayer::playSoilPoke();
	};

private:
	WetSoilBmp1 _bmp1;			/**< The first animation frame. */
	WetSoilBmp2 _bmp2;			/**< The second animation frame. */
	WetSoilBmp3 _bmp3;			/**< The third animation frame. */
	WetSoilBmp4 _bmp4;			/**< The fourth animation frame. */
};

#endif
