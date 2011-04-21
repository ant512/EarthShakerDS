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

#include "emptylevel.h"
#include "level0.h"
#include "level1.h"
#include "level2.h"
#include "level3.h"
#include "level4.h"
#include "level5.h"

/**
 * Creates new instances of LevelBase.
 */
class LevelFactory {
public:

	/**
	 * Creates a new LevelBase object and populates it with data drawn from the
	 * supplied definition.
	 * @param data The level definition to use as a data source for the level.
	 * @param game The containing game object.
	 * @return The new LevelBase object.
	 */
	static LevelBase* createLevel(LevelDefinition* data, Game* game) {

		BlockBase* block = NULL;

		LevelBase* level = new LevelBase(data->getWidth(), data->getHeight(), data->getNumber(), data->getName());

		for (s32 x = 0; x < data->getWidth(); ++x) {
			for (s32 y = 0; y < data->getHeight(); ++y) {

				switch (data->getLayout()[(y * data->getWidth()) + x]) {
					case 0:
						block = NULL;
						break;
					case 1:
						block = new PlayerBlock(x, y, game);
						level->setPlayerBlock((PlayerBlock*)block);
						break;
					case 2:
						block = new DiamondBlock(x, y, game);
						level->increaseDiamondCount();
						break;
					case 3:
						block = new BubbleBlock(x, y, game);
						break;
					case 4:
						block = new FireBlock(x, y, game);
						break;
					case 5:
						block = new BeanBlock(x, y, game);
						break;
					case 6:
						block = new GravityInversionBlock(x, y, game);
						break;
					case 7:
						block = new ExtraLifeBlock(x, y, game);
						break;
					case 8:
						block = new BarrierBlock(x, y, game);
						break;
					case 9:
						block = new BarrierControlBlock(x, y, game);
						break;
					case 10:
						block = new TeleportBlock(x, y, game);
						break;

					case 11:
						block = new DoorBlock(x, y, game, BitmapServer::getBlueDoorBmp());
						break;
					case 12:
						block = new DoorBlock(x, y, game, BitmapServer::getCyanDoorBmp());
						break;
					case 13:
						block = new DoorBlock(x, y, game, BitmapServer::getGreenDoorBmp());
						break;
					case 14:
						block = new DoorBlock(x, y, game, BitmapServer::getMagentaDoorBmp());
						break;
					case 15:
						block = new DoorBlock(x, y, game, BitmapServer::getRedDoorBmp());
						break;
					case 16:
						block = new DoorBlock(x, y, game, BitmapServer::getYellowDoorBmp());
						break;

					case 17:
						block = new BoulderBlock(x, y, game);
						break;

					case 18:
						block = new WallBlock(x, y, game, BitmapServer::getBrickWallBmp());
						break;
					case 19:
						block = new WallBlock(x, y, game, BitmapServer::getRockWallBmp());
						break;
					case 20:
						block = new WallBlock(x, y, game, BitmapServer::getIceWallBmp());
						break;
					case 21:
						block = new WallBlock(x, y, game, BitmapServer::getMetalWallBmp());
						break;
					case 22:
						block = new WallBlock(x, y, game, BitmapServer::getBrainWallBmp());
						break;
					case 23:
						block = new WallBlock(x, y, game, BitmapServer::getGirderWallBmp());
						break;
					case 24:
						block = new WallBlock(x, y, game, BitmapServer::getHeartWallBmp());
						break;
					case 25:
						block = new WallBlock(x, y, game, BitmapServer::getHoneycombWallBmp());
						break;
					case 26:
						block = new WallBlock(x, y, game, BitmapServer::getLeafyWallBmp());
						break;
					case 27:
						block = new WallBlock(x, y, game, BitmapServer::getNuclearWallBmp());
						break;
					case 28:
						block = new WallBlock(x, y, game, BitmapServer::getPipeWallBmp());
						break;
					case 29:
						block = new WallBlock(x, y, game, BitmapServer::getQuestionWallBmp());
						break;				
					case 30:
						block = new WallBlock(x, y, game, BitmapServer::getSandWallBmp());
						break;
					case 31:
						block = new WallBlock(x, y, game, BitmapServer::getSquareWallBmp());
						break;

					case 32:
						block = new SoilBlock(x, y, game, BitmapServer::getSoilBmp());
						break;

					case 33:
						block = new SoilBlock(x, y, game, BitmapServer::getHoneycombSoilBmp());
						break;
					case 34:
						block = new SoilBlock(x, y, game, BitmapServer::getQuestionWallBmp());
						break;

					case 35:
						block = new WetSoilBlock(x, y, game);
						break;
				}

				level->setBlockAt(x, y, block);
			}
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
};

#endif
