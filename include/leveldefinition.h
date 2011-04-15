#ifndef _LEVEL_DEFINITION_H_
#define _LEVEL_DEFINITION_H_

#include <woopsistring.h>
#include <woopsiarray.h>

#include "levelbase.h"

/**
 * Defines the properties of a level.  Levels should be created as instances of
 * this class.  The game uses the LevelFactory to convert from user-defined
 * level classes into LevelBase classes that can be played.
 */
class LevelDefinition {
public:

	typedef struct {
		s32 localX;
		s32 localY;
		s32 remoteX;
		s32 remoteY;
	} TeleportLink;

	/**
	 * Constructor.
	 * @param width The width of the level, in blocks.
	 * @param height The height of the level, in blocks.
	 * @param number The number of the level.
	 * @param name The name of the level.
	 */
	LevelDefinition(s32 width, s32 height, s32 number, WoopsiGfx::WoopsiString name) {
		_width = width;
		_height = height;
		_layout = new u8[width * height];
		_number = number;
		_name = name;
	};

	/**
	 * Destructor.
	 */
	~LevelDefinition() {
		if (_layout != NULL) delete[] _layout;
	};

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
	inline u8* getLayout() const { return _layout; }

	/**
	 * Gets the name of the level.
	 * @return The name of the level.
	 */
	const WoopsiGfx::WoopsiString& getName() const { return _name; };

	const WoopsiArray<TeleportLink>& getTeleportLinks() const { return _teleportLinks; };

protected:
	u8* _layout;						/**< Level map stored as a 1 dimensional array of bytes. */
	s32 _width;							/**< Width of the level in blocks. */
	s32 _height;						/**< Height of the level in blocks. */
	WoopsiGfx::WoopsiString _name;		/**< Name of the level. */
	s32 _number;						/**< Number of the level. */
	WoopsiArray<TeleportLink> _teleportLinks;	/**< Connections between teleports. */

	void addTeleportLink(s32 x1, s32 y1, s32 x2, s32 y2) {
		TeleportLink link;
		link.localX = x1;
		link.localY = y1;
		link.remoteX = x2;
		link.remoteY = y2;

		_teleportLinks.push_back(link);
	};

	/**
	 * Copies the layout from the supplied data into the internal store.
	 * @param layout The layout to copy.
	 */
	void setLayout(u8* layout) {
		for (s32 i = 0; i < _width * _height; ++i) {
			_layout[i] = layout[i];
		}
	};
};

#endif
