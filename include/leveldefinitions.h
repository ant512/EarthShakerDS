#ifndef _LEVEL_DEFINITIONS_H_
#define _LEVEL_DEFINITIONS_H_

#include <woopsiarray.h>

#include "leveldefinitionbase.h"

class LevelDefinitions {
public:
	
	static const WoopsiArray<LevelDefinitionBase*>& getDefinitions();
	
	static void loadCustomLevels();

private:
	static WoopsiArray<LevelDefinitionBase*> _levelDefinitions;
};

#endif
