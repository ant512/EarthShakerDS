#ifndef _LEVEL_FACTORY_H_
#define _LEVEL_FACTORY_H_

#include <woopsiarray.h>

#include "bitmapserver.h"
#include "blocktype.h"

#include "barrierblock.h"
#include "barriercontrolblock.h"
#include "beanblock.h"
#include "boulderblock.h"
#include "bubbleblock.h"
#include "diamondblock.h"
#include "doorblock.h"
#include "extralifeblock.h"
#include "fireblock.h"
#include "gravityinversionblock.h"
#include "gamesession.h"
#include "level.h"
#include "leveldefinitionbase.h"
#include "playerblock.h"
#include "soilblock.h"
#include "teleportblock.h"
#include "wallblock.h"
#include "wetsoilblock.h"

/**
 * Creates new instances of Level.
 */
class LevelFactory {
public:

	/**
	 * Creates a new Level object and populates it with data drawn from the
	 * supplied definition.
	 * @param data The level definition to use as a data source for the level.
	 * @param session The containing game session object.
	 * @return The new Level object.
	 */
	static Level* createLevel(LevelDefinitionBase* data, GameSession* session) {

		Level* level = new Level(data->getWidth(), data->getHeight(), data->getNumber(), data->getName());

		for (s32 y = 0; y < data->getHeight(); ++y) {
			for (s32 x = 0; x < data->getWidth(); ++x) {
				placeBlock(level, (BlockType)data->getLayout()[(y * data->getWidth()) + x], x, y, session);
			}
		}

		return level;
	};

	/**
	 * Places a block of the specified type into the level at the specified
	 * co-ordinates.
	 * @param level The level into which to insert the block.
	 * @param blockType Type of block to insert.
	 * @param x The X co-ordinate of the block.
	 * @param y The y co-ordinate of the block.
	 * @param session The game session that owns the level.
	 */
	static void placeBlock(Level* level, BlockType blockType, s32 x, s32 y, GameSession* session) {
		
		BlockBase* block = NULL;

		if (level->getPlayerBlock() != NULL) {
			if ((level->getPlayerBlock()->getX() == x) && (level->getPlayerBlock()->getY() == y)) {

				// If we're overwriting the player block we need to forget it
				level->setPlayerBlock(NULL);
			}
		}

		if (level->getDoorBlock() != NULL) {
			if ((level->getDoorBlock()->getX() == x) && (level->getDoorBlock()->getY() == y)) {

				// If we're overwriting the door block we need to forget it
				level->setDoorBlock(NULL);
			}
		}

		switch (blockType) {
			case BLOCK_TYPE_NULL:
				block = NULL;
				break;
			case BLOCK_TYPE_PLAYER:
				block = new PlayerBlock(x, y, session);

				// Ensure player block is unique
				if (level->getPlayerBlock() != NULL) {
					level->removeBlockAt(level->getPlayerBlock()->getX(), level->getPlayerBlock()->getY());
				}

				level->setPlayerBlock((PlayerBlock*)block);
				break;
			case BLOCK_TYPE_DIAMOND:
				block = new DiamondBlock(x, y, session);
				level->increaseDiamondCount();
				break;
			case BLOCK_TYPE_BUBBLE:
				block = new BubbleBlock(x, y, session);
				break;
			case BLOCK_TYPE_FIRE:
				block = new FireBlock(x, y, session);
				break;
			case BLOCK_TYPE_BEAN:
				block = new BeanBlock(x, y, session);
				break;
			case BLOCK_TYPE_GRAVITY:
				block = new GravityInversionBlock(x, y, session);
				break;
			case BLOCK_TYPE_EXTRA_LIFE:
				block = new ExtraLifeBlock(x, y, session);
				break;
			case BLOCK_TYPE_BARRIER:
				block = new BarrierBlock(x, y, session);
				break;
			case BLOCK_TYPE_BARRIER_CONTROL:
				block = new BarrierControlBlock(x, y, session);
				break;
			case BLOCK_TYPE_TELEPORT:
				block = new TeleportBlock(x, y, session);
				break;

			case BLOCK_TYPE_DOOR:
				block = new DoorBlock(x, y, session);
				
				// Ensure door block is unique
				if (level->getDoorBlock() != NULL) {
					level->removeBlockAt(level->getDoorBlock()->getX(), level->getDoorBlock()->getY());
				}

				level->setDoorBlock((DoorBlock*)block);

				break;
			case BLOCK_TYPE_BOULDER:
				block = new BoulderBlock(x, y, session);
				break;
			case BLOCK_TYPE_WALL:
				block = new WallBlock(x, y, session);
				break;
			case BLOCK_TYPE_SOIL:
				block = new SoilBlock(x, y, session);
				break;
			case BLOCK_TYPE_SOIL_WET:
				block = new WetSoilBlock(x, y, session);
				break;
		}

		level->removeBlockAt(x, y);
		level->setBlockAt(x, y, block);
		level->deleteRemovedBlocks();
	};

private:

	/**
	 * Constructor is private to prevent creation.
	 */
	LevelFactory() { };

	/**
	 * Destructor.
	 */
	~LevelFactory() { };
};

#endif
