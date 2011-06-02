#ifndef _LEVEL_DEFINITION_H_
#define _LEVEL_DEFINITION_H_

#include <woopsistring.h>
#include <woopsiarray.h>

#include "blocktype.h"
#include "level.h"

/**
 * Defines the properties of a level.  Levels should be created as instances of
 * this class.  The game uses the LevelFactory to convert from user-defined
 * level classes into Level classes that can be played.
 */
class LevelDefinition {
public:

	/**
	 * Constructor.
	 * @param width The width of the level, in blocks.
	 * @param height The height of the level, in blocks.
	 * @param number The number of the level.
	 * @param name The name of the level.
	 * @param data The level layout.
	 * @param boulderType The type of boulders in this level.
	 * @param wallType The type of walls in this level.
	 * @param soilType The type of soil in this level.
	 * @param doorType The type of doors in this level.
	 */
	LevelDefinition(s32 width,
					s32 height,
					s32 number,
					WoopsiGfx::WoopsiString name,
					const u8* data,
					BoulderType boulderType,
					WallType wallType,
					SoilType soilType,
					DoorType doorType) {

		_width = width;
		_height = height;
		_layout = data;
		_number = number;
		_name = name;
		_boulderType = boulderType;
		_wallType = wallType;
		_soilType = soilType;
		_doorType = doorType;
	};

	/**
	 * Destructor.
	 */
	inline ~LevelDefinition() { };

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
	inline const u8* getLayout() const { return _layout; };

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

protected:
	const u8* _layout;							/**< Level map stored as a 1 dimensional array of bytes. */
	s32 _width;									/**< Width of the level in blocks. */
	s32 _height;								/**< Height of the level in blocks. */
	WoopsiGfx::WoopsiString _name;				/**< Name of the level. */
	s32 _number;								/**< Number of the level. */
	BoulderType _boulderType;					/**< Colour of boulders in this level. */
	WallType _wallType;							/**< Colour of brick walls in this level. */
	SoilType _soilType;							/**< Colour of soil in this level. */
	DoorType _doorType;							/**< Colour of doors in this level. */
};

#endif
