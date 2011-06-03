#ifndef _LEVEL_IO_H_
#define _LEVEL_IO_H_

#include <nds.h>
#include <woopsistring.h>

#include "binaryfile.h"
#include "blocktype.h"
#include "leveldefinitionbase.h"
#include "mutableleveldefinition.h"

class LevelIO {
public:
	
	static WoopsiGfx::WoopsiString getTargetDirectoryName();

	/**
	 * Save the supplied level definition to disk.  Files will be saved in
	 * /data/earthshakerds.
	 * @param level Level to save.
	 */
	static void save(LevelDefinitionBase* level);

	/**
	 * Load the specified level from disk.
	 * @param fileName Name of the file to load.
	 * @return The loaded level, or NULL if an error occurred.
	 */
	static MutableLevelDefinition* load(const WoopsiGfx::WoopsiString& fileName);

private:

	/**
	 * Constructor.
	 */
	LevelIO() { };

	/**
	 * Destructor.
	 */
	~LevelIO() { };
};

#endif
