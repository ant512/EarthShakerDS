#include <woopsistring.h>
#include <woopsiarray.h>

#include "leveldefinitions.h"
#include "constants.h"

#include "level.h"
#include "leveldefinitionbase.h"
#include "levelio.h"

#include "level1.h"
#include "level2.h"
#include "level3.h"
#include "level4.h"
#include "level5.h"
#include "level6.h"
#include "level7.h"
#include "level8.h"
#include "level9.h"
#include "level10.h"
#include "level11.h"
#include "level12.h"
#include "level13.h"
#include "level14.h"
#include "level15.h"
#include "level16.h"
#include "level17.h"
#include "level18.h"
#include "level19.h"
#include "level20.h"
#include "level21.h"
#include "level22.h"
#include "level23.h"
#include "level24.h"
#include "level25.h"
#include "level26.h"
#include "level27.h"
#include "level28.h"
#include "level29.h"
#include "level30.h"
#include "level31.h"
#include "level32.h"

WoopsiArray<LevelDefinitionBase*> LevelDefinitions::_levelDefinitions;

const WoopsiArray<LevelDefinitionBase*>& LevelDefinitions::getDefinitions() {
	
	if (_levelDefinitions.size() == 0) {
		
		_levelDefinitions.push_back(new Level1());
		_levelDefinitions.push_back(new Level2());
		_levelDefinitions.push_back(new Level3());
		_levelDefinitions.push_back(new Level4());
		_levelDefinitions.push_back(new Level5());
		_levelDefinitions.push_back(new Level6());
		_levelDefinitions.push_back(new Level7());
		_levelDefinitions.push_back(new Level8());
		_levelDefinitions.push_back(new Level9());
		_levelDefinitions.push_back(new Level10());
		_levelDefinitions.push_back(new Level11());
		_levelDefinitions.push_back(new Level12());
		_levelDefinitions.push_back(new Level13());
		_levelDefinitions.push_back(new Level14());
		_levelDefinitions.push_back(new Level15());
		_levelDefinitions.push_back(new Level16());
		_levelDefinitions.push_back(new Level17());
		_levelDefinitions.push_back(new Level18());
		_levelDefinitions.push_back(new Level19());
		_levelDefinitions.push_back(new Level20());
		_levelDefinitions.push_back(new Level21());
		_levelDefinitions.push_back(new Level22());
		_levelDefinitions.push_back(new Level23());
		_levelDefinitions.push_back(new Level24());
		_levelDefinitions.push_back(new Level25());
		_levelDefinitions.push_back(new Level26());
		_levelDefinitions.push_back(new Level27());
		_levelDefinitions.push_back(new Level28());
		_levelDefinitions.push_back(new Level29());
		_levelDefinitions.push_back(new Level30());
		_levelDefinitions.push_back(new Level31());
		_levelDefinitions.push_back(new Level32());
		
		// Set up linked list connections from one level to the next
		for (s32 i = 0; i < _levelDefinitions.size() - 1; ++i) {
			_levelDefinitions[i]->setNextLevel(_levelDefinitions[i + 1]);
		}
		
		loadCustomLevels();
	}
	
	return _levelDefinitions;
}

void LevelDefinitions::loadCustomLevels() {
	
	while (_levelDefinitions.size() > STANDARD_LEVEL_COUNT) {
		delete _levelDefinitions[STANDARD_LEVEL_COUNT];
		_levelDefinitions.erase(STANDARD_LEVEL_COUNT);
	}
	
	// Add custom levels to the end of the level definition array
	WoopsiArray<WoopsiGfx::WoopsiString>* customLevelNames = LevelIO::getLevelNames();
	
	for (s32 i = 0; i < customLevelNames->size(); ++i) {
		_levelDefinitions.push_back(LevelIO::load(customLevelNames->at(i)));
	}
	
	delete customLevelNames;
}
