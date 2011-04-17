#ifndef _LEVEL_FACTORY_H_
#define _LEVEL_FACTORY_H_

#include <woopsiarray.h>

#include "bitmapserver.h"

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
#include "levelbase.h"
#include "leveldefinition.h"
#include "playerblock.h"
#include "soilblock.h"
#include "teleportblock.h"
#include "wallblock.h"
#include "wetsoilblock.h"

#include "level0.h"
#include "level1.h"

/**
 * Creates new instances of LevelBase.
 */
class LevelFactory {
public:

	/**
	 * Creates and returns a new LevelBase object representing the specified
	 * level number.
	 * @param number The level to create.
	 * @param game Pointer to the overall game object.
	 * @return A new LevelBase object containing the specified level definition
	 * if a level for that number exists.  Otherwise, returns NULL.  It is the
	 * responsibility of the caller to delete the level once it is no longer
	 * required.
	 */
	static LevelBase* newLevel(s32 number, Game* game) {
		LevelDefinition* data = NULL;

		switch (number) {
			case 0:
				data = new Level0();
				break;
			case 1:
				data = new Level1();
				break;
			case 2:
				break;
		}

		LevelBase* level = NULL;

		if (data != NULL) {
			level = createLevel(data, game);
			delete data;
		}

		return level;
	};

private:

	/**
	 * Constructor is private to prevent creation.
	 */
	LevelFactory();

	/**
	 * Destructor.
	 */
	~LevelFactory();

	/**
	 * Creates a new LevelBase object and populates it with data drawn from the
	 * supplied definition.
	 * @param data The level definition to use as a data source for the level.
	 * @param game The containing game object.
	 * @return The new LevelBase object.
	 */
	static LevelBase* createLevel(LevelDefinition* data, Game* game) {

		BarrierControlBlock* barrierControlBlock = NULL;
		WoopsiArray<BarrierBlock*> barrierBlocks;

		BlockBase* block = NULL;

		LevelBase* level = new LevelBase(data->getWidth(), data->getHeight(), data->getNumber(), data->getName());

		for (s32 x = 0; x < data->getWidth(); ++x) {
			for (s32 y = 0; y < data->getHeight(); ++y) {

				switch (data->getLayout()[(y * data->getWidth()) + x]) {
					case 0:
						block = NULL;
						break;
					case 1:
						block = new SoilBlock(x, y, game, BitmapServer::getBlueSoilBmp());
						break;
					case 2:
						block = new BoulderBlock(x, y, game);
						break;
					case 3:
						block = new DiamondBlock(x, y, game);
						level->increaseDiamondCount();
						break;
					case 4:
						block = new PlayerBlock(x, y, game);
						level->setPlayerBlock((PlayerBlock*)block);
						break;
					case 5:
						block = new BubbleBlock(x, y, game);
						break;
					case 6:
						block = new WallBlock(x, y, game, BitmapServer::getBrickWallBmp());
						break;
					case 7:
						block = new FireBlock(x, y, game);
						break;
					case 8:
						block = new BeanBlock(x, y, game);
						break;
					case 9:
						block = new GravityInversionBlock(x, y, game);
						break;
					case 10:
						block = new ExtraLifeBlock(x, y, game);
						break;
					case 11:
						block = new WallBlock(x, y, game, BitmapServer::getRockWallBmp());
						break;
					case 12:
						block = new WallBlock(x, y, game, BitmapServer::getIceWallBmp());
						break;
					case 13:
						block = new WetSoilBlock(x, y, game);
						break;
					case 14:
						block = new DoorBlock(x, y, game);
						break;
					case 15:
						block = new WallBlock(x, y, game, BitmapServer::getMetalWallBmp());
						break;
					case 16:
						block = new BarrierBlock(x, y, game);
						barrierBlocks.push_back((BarrierBlock*)block);
						break;
					case 17:
						block = new BarrierControlBlock(x, y, game);
						barrierControlBlock = (BarrierControlBlock*)block;
						break;
					case 18:
						block = new TeleportBlock(x, y, game);
						break;
					case 19:
						block = new WallBlock(x, y, game, BitmapServer::getBrainWallBmp());
						break;
					case 20:
						block = new WallBlock(x, y, game, BitmapServer::getGirderWallBmp());
						break;
					case 21:
						block = new WallBlock(x, y, game, BitmapServer::getHeartWallBmp());
						break;
					case 22:
						block = new SoilBlock(x, y, game, BitmapServer::getHoneycombSoilBmp());
						break;
					case 23:
						block = new WallBlock(x, y, game, BitmapServer::getHoneycombWallBmp());
						break;
					case 24:
						block = new WallBlock(x, y, game, BitmapServer::getLeafyWallBmp());
						break;
					case 25:
						block = new WallBlock(x, y, game, BitmapServer::getNuclearWallBmp());
						break;
				}

				level->setBlockAt(x, y, block);
			}
		}

		// Wire all barrier blocks up to the controller
		for (s32 i = 0; i < barrierBlocks.size(); ++i) {
			barrierControlBlock->addBarrierBlock(barrierBlocks[i]);
		}

		// Wire up all teleport links
		for (s32 i = 0; i < data->getTeleportLinks().size(); ++i) {
			LevelDefinition::TeleportLink linkData = data->getTeleportLinks().at(i);

			TeleportBlock* local = (TeleportBlock*)level->getBlockAt(linkData.localX, linkData.localY);
			TeleportBlock* remote = (TeleportBlock*)level->getBlockAt(linkData.remoteX, linkData.remoteY);

			local->setLink(remote);
		}

		return level;
	};
};

#endif
