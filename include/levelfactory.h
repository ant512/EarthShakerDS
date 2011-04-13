#ifndef _LEVEL_FACTORY_H_
#define _LEVEL_FACTORY_H_

#include "leveldefinition.h"
#include "level0.h"
#include "levelbase.h"
#include "boulderblock.h"
#include "game.h"
#include "beanblock.h"
#include "wallblock.h"
#include "diamondblock.h"
#include "soilblock.h"
#include "playerblock.h"
#include "bubbleblock.h"
#include "fireblock.h"

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
		BlockBase* block = NULL;

		LevelBase* level = new LevelBase(data->getWidth(), data->getHeight(), data->getNumber(), data->getName());

		for (s32 x = 0; x < data->getWidth(); ++x) {
			for (s32 y = 0; y < data->getHeight(); ++y) {

				switch (data->getLayout()[(y * data->getWidth()) + x]) {
					case 0:
						block = NULL;
						break;
					case 1:
						block = new SoilBlock(x, y, game);
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
						block = new WallBlock(x, y, game);
						break;
					case 7:
						block = new FireBlock(x, y, game);
						break;
					case 8:
						block = new BeanBlock(x, y, game);
						break;
				}

				level->setBlockAt(x, y, block);
			}
		}

		return level;
	};
};

#endif
