#ifndef _BOULDER_BLOCK_H_
#define _BOULDER_BLOCK_H_

#include <graphics.h>
#include <bitmap.h>

#include "bitmapserver.h"
#include "blockbase.h"
#include "gamesession.h"
#include "playerblock.h"
#include "soundplayer.h"

#include "bouldermapbmp.h"

/**
 * Boulders fall if not sitting on anything and can be pushed horizontally.
 * They are the primary "enemy" in the game.
 */
class BoulderBlock : public BlockBase {
public:

	/**
	 * Constructor.
	 * @param x The x co-ordinate within the level map of the block.
	 * @param y The y co-ordinate within tne level map of the block.
	 * @param game Pointer to the game that contains the block.
	 */
	BoulderBlock(s32 x, s32 y, GameSession* game) : BlockBase(x, y, game) {
		_isHeavy = true;
		_isHeavyEnoughToKill = true;

		_animation->addFrame(BitmapServer::getBoulderBmp(), 0);

		_explodingAnimation->addFrame(BitmapServer::getBoulderExplodeBmp1(), 0);
		_explodingAnimation->addFrame(BitmapServer::getBoulderExplodeBmp2(), 0);
		_explodingAnimation->addFrame(BitmapServer::getBoulderExplodeBmp3(), 0);
		_explodingAnimation->addFrame(BitmapServer::getBoulderExplodeBmp4(), 0);
		_explodingAnimation->addFrame(BitmapServer::getBoulderExplodeBmp5(), 0);
		_explodingAnimation->addFrame(BitmapServer::getBoulderExplodeBmp6(), 0);
		_explodingAnimation->addFrame(BitmapServer::getBoulderExplodeBmp7(), 0);

		_mapBitmap = new BoulderMapBmp();
	};

	/**
	 * Destructor.
	 */
	~BoulderBlock() {
		delete _mapBitmap;
	};

	/**
	 * Pushes this block to the left if the block to the left is empty.
	 * @return True if the block moves; false if not.
	 */
	bool pushLeft() {

		if (_isOddIteration != _game->isOddIteration()) return false;
		if (_x == 0) return false;
		if (_isExploding) return false;
		if (_isFalling) return false;

		_isOddIteration = !_isOddIteration;

		Level* level = _game->getLevel();
		BlockBase* block = level->getBlockAt(_x - 1, _y);

		if (block == NULL) {
			level->moveBlock(_x, _y, _x - 1, _y);
			_isOddIteration = !_isOddIteration;

			SoundPlayer::playBlockLand();
			return true;
		}

		return false;
	};

	/**
	 * Pushes this block to the right if the block to the left is empty.
	 * @return True if the block moves; false if not.
	 */
	bool pushRight() {

		if (_isOddIteration != _game->isOddIteration()) return false;
		if (_isExploding) return false;
		if (_isFalling) return false;

		Level* level = _game->getLevel();

		if (_x == level->getWidth() - 1) return false;

		_isOddIteration = !_isOddIteration;

		BlockBase* block = level->getBlockAt(_x + 1, _y);

		if (block == NULL) {
			level->moveBlock(_x, _y, _x + 1, _y);
			_isOddIteration = !_isOddIteration;

			SoundPlayer::playBlockLand();
			return true;
		}

		return false;
	};

	/**
	 * Drops or raises the block depending on gravity.  If the block is sat on
	 * a hot block it explodes.
	 */
	void onIterate() {

		// If we're sat on a hot tile then explode
		if (_game->isGravityInverted()) {
			explodeIfHotBlockAt(_x, _y - 1);
		} else {
			explodeIfHotBlockAt(_x, _y + 1);
		}

		if (_isExploding) return;
	};

	/**
	 * Causes the block to explode if the block at the specified co-ordinates
	 * is hot.
	 * @param x The x co-ordinate to check for a hot block.
	 * @param y The y co-ordinate to check for a hot block.
	 */
	void explodeIfHotBlockAt(s32 x, s32 y) {

		BlockBase* block = _game->getLevel()->getBlockAt(x, y);

		if (block == NULL) return;

		if (block->isHot()) explode();
	};

	/**
	 * Pushes this block if the adjacent block is empty.
	 */
	void pokeUp() {
		pushUp();
	};

	/**
	 * Pushes this block if the adjacent block is empty.
	 */
	void pokeDown() {
		pushDown();
	};

	/**
	 * Pushes this block if the adjacent block is empty.
	 */
	void pokeLeft() {
		pushLeft();
	};

	/**
	 * Pushes this block if the adjacent block is empty.
	 */
	void pokeRight() {
		pushRight();
	};

private:
	
	/**
	 * Plays explode sound.
	 */
	void onExplode() {
		SoundPlayer::playBoulderExplode();
	};

	/**
	 * Plays landing sound.
	 */
	void onLand() {
		SoundPlayer::playBlockLand();
	}
};

#endif
