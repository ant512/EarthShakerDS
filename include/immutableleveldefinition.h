#ifndef _IMMUTABLE_LEVEL_DEFINITION_H_
#define _IMMUTABLE_LEVEL_DEFINITION_H_

#include <woopsistring.h>
#include <woopsiarray.h>

#include "leveldefinitionbase.h"
#include "blocktype.h"
#include "level.h"

/**
 * Defines the properties of a level.  Levels should be created as instances of
 * this class.  The game uses the LevelFactory to convert from user-defined
 * level classes into Level classes that can be played.
 */
class ImmutableLevelDefinition : public LevelDefinitionBase {
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
	ImmutableLevelDefinition(s32 width,
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
	inline ~ImmutableLevelDefinition() { };

	/**
	 * Gets the layout of the level.
	 * @return The layout of the level.
	 */
	inline const u8* getLayout() const { return _layout; };

protected:
	const u8* _layout;	/**< Level map stored as a 1 dimensional array of bytes. */
};

#endif
