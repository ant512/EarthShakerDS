#ifndef _LEVEL_DEFINITION_BASE_H_
#define _LEVEL_DEFINITION_BASE_H_

#include <woopsistring.h>
#include <woopsiarray.h>

#include "blocktype.h"
#include "level.h"

/**
 * Defines the properties of a level.  Levels should be created as instances of
 * this class.  The game uses the LevelFactory to convert from user-defined
 * level classes into Level classes that can be played.
 */
class LevelDefinitionBase {
public:
	
	LevelDefinitionBase() { _nextLevel = NULL; };

	/**
	 * Destructor.
	 */
	virtual inline ~LevelDefinitionBase() { };

	/**
	 * Gets the width of the level.
	 * @return The width of the level.
	 */
	inline s32 getWidth() const { return _width; };

	/**
	 * Gets the height of the level.
	 * @return The height of the level.
	 */
	inline s32 getHeight() const { return _height; };

	/**
	 * Gets the number of the level.
	 * @return The number of the level.
	 */
	inline s32 getNumber() const { return _number; };

	/**
	 * Gets the layout of the level.
	 * @return The layout of the level.
	 */
	virtual const u8* getLayout() const = 0;

	/**
	 * Gets the name of the level.
	 * @return The name of the level.
	 */
	inline const WoopsiGfx::WoopsiString& getName() const { return _name; };

	/**
	 * Gets the current boulder type.
	 * @return The current boulder type.
	 */
	inline BoulderType getBoulderType() const { return _boulderType; };

	/**
	 * Gets the current wall type.
	 * @return The current wall type.
	 */
	inline WallType getWallType() const { return _wallType; };

	/**
	 * Gets the current soil type.
	 * @return The current soil type.
	 */
	inline SoilType getSoilType() const { return _soilType; };

	/**
	 * Gets the current door type.
	 * @return The current door type.
	 */
	inline DoorType getDoorType() const { return _doorType; };
	
	inline LevelDefinitionBase* getNextLevel() const { return _nextLevel; };
	
	inline void setNextLevel(LevelDefinitionBase* nextLevel) { _nextLevel = nextLevel; };

protected:
	s32 _width;									/**< Width of the level in blocks. */
	s32 _height;								/**< Height of the level in blocks. */
	WoopsiGfx::WoopsiString _name;				/**< Name of the level. */
	s32 _number;								/**< Number of the level. */
	BoulderType _boulderType;					/**< Colour of boulders in this level. */
	WallType _wallType;							/**< Colour of brick walls in this level. */
	SoilType _soilType;							/**< Colour of soil in this level. */
	DoorType _doorType;							/**< Colour of doors in this level. */
	LevelDefinitionBase* _nextLevel;			/**< The level after this. */
};

#endif
