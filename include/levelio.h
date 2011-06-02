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

	static void save(LevelDefinitionBase* level);

	static MutableLevelDefinition* load(const WoopsiGfx::WoopsiString& fileName);

private:

	LevelIO() { };
	~LevelIO() { };
};

#endif
