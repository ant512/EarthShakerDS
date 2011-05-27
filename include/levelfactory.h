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
#include "game.h"
#include "level.h"
#include "leveldefinition.h"
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
	 * @param game The containing game object.
	 * @return The new Level object.
	 */
	static Level* createLevel(LevelDefinition* data, Game* game) {

		Level* level = new Level(data->getWidth(), data->getHeight(), data->getNumber(), data->getName());

		for (s32 x = 0; x < data->getWidth(); ++x) {
			for (s32 y = 0; y < data->getHeight(); ++y) {
				placeBlock(level, (BlockType)data->getLayout()[(y * data->getWidth()) + x], x, y, game);
			}
		}

		return level;
	};

	static void placeBlock(Level* level, BlockType blockType, s32 x, s32 y, Game* game) {
		
		BlockBase* block = NULL;

		if ((level->getPlayerBlock()->getX() == x) && (level->getPlayerBlock()->getY() == y)) {

			// If we're overwriting the player block we need to forget it
			level->setPlayerBlock(NULL);
		} else if ((level->getDoorBlock()->getX() == x) && (level->getDoorBlock()->getY() == y)) {

			// If we're overwriting the door block we need to forget it
			level->setDoorBlock(NULL);
		}

		switch (blockType) {
			case BLOCK_TYPE_NULL:
				block = NULL;
				break;
			case BLOCK_TYPE_PLAYER:
				block = new PlayerBlock(x, y, game);

				// Ensure player block is unique
				if (level->getPlayerBlock() != NULL) {
					level->removeBlockAt(level->getPlayerBlock()->getX(), level->getPlayerBlock()->getY());
				}

				level->setPlayerBlock((PlayerBlock*)block);
				break;
			case BLOCK_TYPE_DIAMOND:
				block = new DiamondBlock(x, y, game);
				level->increaseDiamondCount();
				break;
			case BLOCK_TYPE_BUBBLE:
				block = new BubbleBlock(x, y, game);
				break;
			case BLOCK_TYPE_FIRE:
				block = new FireBlock(x, y, game);
				break;
			case BLOCK_TYPE_BEAN:
				block = new BeanBlock(x, y, game);
				break;
			case BLOCK_TYPE_GRAVITY:
				block = new GravityInversionBlock(x, y, game);
				break;
			case BLOCK_TYPE_EXTRA_LIFE:
				block = new ExtraLifeBlock(x, y, game);
				break;
			case BLOCK_TYPE_BARRIER:
				block = new BarrierBlock(x, y, game);
				break;
			case BLOCK_TYPE_BARRIER_CONTROL:
				block = new BarrierControlBlock(x, y, game);
				break;
			case BLOCK_TYPE_TELEPORT:
				block = new TeleportBlock(x, y, game);
				break;

			case BLOCK_TYPE_DOOR_BLUE:
				block = new DoorBlock(x, y, game, BitmapServer::getBlueDoorBmp());

				// Ensure door block is unique
				if (level->getDoorBlock() != NULL) {
					level->removeBlockAt(level->getDoorBlock()->getX(), level->getDoorBlock()->getY());
				}

				level->setDoorBlock((DoorBlock*)block);

				break;
			case BLOCK_TYPE_DOOR_CYAN:
				block = new DoorBlock(x, y, game, BitmapServer::getCyanDoorBmp());

				// Ensure door block is unique
				if (level->getDoorBlock() != NULL) {
					level->removeBlockAt(level->getDoorBlock()->getX(), level->getDoorBlock()->getY());
				}

				level->setDoorBlock((DoorBlock*)block);

				break;
			case BLOCK_TYPE_DOOR_GREEN:
				block = new DoorBlock(x, y, game, BitmapServer::getGreenDoorBmp());

				// Ensure door block is unique
				if (level->getDoorBlock() != NULL) {
					level->removeBlockAt(level->getDoorBlock()->getX(), level->getDoorBlock()->getY());
				}

				level->setDoorBlock((DoorBlock*)block);

				break;
			case BLOCK_TYPE_DOOR_MAGENTA:
				block = new DoorBlock(x, y, game, BitmapServer::getMagentaDoorBmp());

				// Ensure door block is unique
				if (level->getDoorBlock() != NULL) {
					level->removeBlockAt(level->getDoorBlock()->getX(), level->getDoorBlock()->getY());
				}

				level->setDoorBlock((DoorBlock*)block);

				break;
			case BLOCK_TYPE_DOOR_RED:
				block = new DoorBlock(x, y, game, BitmapServer::getRedDoorBmp());

				// Ensure door block is unique
				if (level->getDoorBlock() != NULL) {
					level->removeBlockAt(level->getDoorBlock()->getX(), level->getDoorBlock()->getY());
				}

				level->setDoorBlock((DoorBlock*)block);

				break;
			case BLOCK_TYPE_DOOR_YELLOW:
				block = new DoorBlock(x, y, game, BitmapServer::getYellowDoorBmp());

				// Ensure door block is unique
				if (level->getDoorBlock() != NULL) {
					level->removeBlockAt(level->getDoorBlock()->getX(), level->getDoorBlock()->getY());
				}

				level->setDoorBlock((DoorBlock*)block);

				break;

			case BLOCK_TYPE_BOULDER:
				block = new BoulderBlock(x, y, game);
				break;

			case BLOCK_TYPE_WALL_BRICK:
				block = new WallBlock(x, y, game, BitmapServer::getBrickWallBmp());
				break;
			case BLOCK_TYPE_WALL_ROCK:
				block = new WallBlock(x, y, game, BitmapServer::getRockWallBmp());
				break;
			case BLOCK_TYPE_WALL_ICE:
				block = new WallBlock(x, y, game, BitmapServer::getIceWallBmp());
				break;
			case BLOCK_TYPE_WALL_METAL:
				block = new WallBlock(x, y, game, BitmapServer::getMetalWallBmp());
				break;
			case BLOCK_TYPE_WALL_BRAIN:
				block = new WallBlock(x, y, game, BitmapServer::getBrainWallBmp());
				break;
			case BLOCK_TYPE_WALL_GIRDER:
				block = new WallBlock(x, y, game, BitmapServer::getGirderWallBmp());
				break;
			case BLOCK_TYPE_WALL_HEART:
				block = new WallBlock(x, y, game, BitmapServer::getHeartWallBmp());
				break;
			case BLOCK_TYPE_WALL_HONEYCOMB:
				block = new WallBlock(x, y, game, BitmapServer::getHoneycombWallBmp());
				break;
			case BLOCK_TYPE_WALL_LEAFY:
				block = new WallBlock(x, y, game, BitmapServer::getLeafyWallBmp());
				break;
			case BLOCK_TYPE_WALL_NUCLEAR:
				block = new WallBlock(x, y, game, BitmapServer::getNuclearWallBmp());
				break;
			case BLOCK_TYPE_WALL_PIPE:
				block = new WallBlock(x, y, game, BitmapServer::getPipeWallBmp());
				break;
			case BLOCK_TYPE_WALL_QUESTION:
				block = new WallBlock(x, y, game, BitmapServer::getQuestionWallBmp());
				break;				
			case BLOCK_TYPE_WALL_SAND:
				block = new WallBlock(x, y, game, BitmapServer::getSandWallBmp());
				break;
			case BLOCK_TYPE_WALL_SQUARE:
				block = new WallBlock(x, y, game, BitmapServer::getSquareWallBmp());
				break;

			case BLOCK_TYPE_SOIL:
				block = new SoilBlock(x, y, game, BitmapServer::getSoilBmp());
				break;

			case BLOCK_TYPE_SOIL_HONEYCOMB:
				block = new SoilBlock(x, y, game, BitmapServer::getHoneycombSoilBmp());
				break;
			case BLOCK_TYPE_SOIL_QUESTION:
				block = new SoilBlock(x, y, game, BitmapServer::getQuestionWallBmp());
				break;

			case BLOCK_TYPE_SOIL_WET:
				block = new WetSoilBlock(x, y, game);
				break;

			case BLOCK_TYPE_DOOR_WHITE:
				block = new DoorBlock(x, y, game, BitmapServer::getWhiteDoorBmp());

				// Ensure door block is unique
				if (level->getDoorBlock() != NULL) {
					level->removeBlockAt(level->getDoorBlock()->getX(), level->getDoorBlock()->getY());
				}

				level->setDoorBlock((DoorBlock*)block);

				break;

			case BLOCK_TYPE_SOIL_BOULDER:
				block = new SoilBlock(x, y, game, BitmapServer::getBoulderBmp());
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
