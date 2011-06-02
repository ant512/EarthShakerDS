#ifndef USING_SDL
#include <fat.h>
#endif

#include "levelio.h"

void LevelIO::save(LevelDefinitionBase* level) {

#ifndef USING_SDL

	if (!fatInitDefault()) return;

#endif

	WoopsiGfx::WoopsiString fileName("/data/earthshakerds/");
	fileName.append(level->getName());

	BinaryFile file(fileName, BinaryFile::FILE_MODE_WRITE, BinaryFile::ENDIAN_MODE_BIG_ENDIAN);
	
	// Header
	file.writeU8('E');
	file.writeU8('S');
	file.writeU8('D');
	file.writeU8('S'); 

	// Level number
	file.writeS32(level->getNumber());

	// Bytes in level name
	s32 bufferSize = level->getName().getByteCount();

	file.writeS32(bufferSize);

	// Level name
	char* buffer = new char[bufferSize];
	level->getName().copyToCharArray(buffer);

	for (s32 i = 0; i < bufferSize; ++i) {
		file.writeU8(buffer[i]);
	}

	delete[] buffer;

	// Width
	file.writeS32(level->getWidth());

	// Height
	file.writeS32(level->getHeight());

	// Layout
	for (s32 i = 0; i < level->getWidth() * level->getHeight(); ++i) {
		file.writeU8(level->getLayout()[i]);
	}

	// Block types
	file.writeU8(level->getBoulderType());
	file.writeU8(level->getWallType());
	file.writeU8(level->getSoilType());
	file.writeU8(level->getDoorType());
}

MutableLevelDefinition* LevelIO::load(const WoopsiGfx::WoopsiString& fileName) {

#ifndef USING_SDL

	if (!fatInitDefault()) return NULL;

#endif

	BinaryFile file(fileName, BinaryFile::FILE_MODE_READ, BinaryFile::ENDIAN_MODE_BIG_ENDIAN);

	// Validate header
	u8 header[4];

	header[0] = file.readU8();
	header[1] = file.readU8();
	header[2] = file.readU8();
	header[3] = file.readU8();

	if (header[0] != 'E') return NULL;
	if (header[1] != 'S') return NULL;
	if (header[2] != 'D') return NULL;
	if (header[3] != 'S') return NULL;

	s32 levelNumber = file.readS32();
	s32 nameBytes = file.readS32();

	WoopsiGfx::WoopsiString levelName;

	for (s32 i = 0; i < nameBytes; ++i) {
		levelName.append(file.readU8());
	}

	s32 width = file.readS32();
	s32 height = file.readS32();

	u8* layout = new u8[width * height];

	for (s32 i = 0; i < width * height; ++i) {
		layout[i] = file.readU8();
	}

	BoulderType boulderType = (BoulderType)file.readU8();
	WallType wallType = (WallType)file.readU8();
	SoilType soilType = (SoilType)file.readU8();
	DoorType doorType = (DoorType)file.readU8();

	MutableLevelDefinition* level = new MutableLevelDefinition(width, height,
														levelNumber, levelName,
														boulderType, wallType,
														soilType, doorType);
	
	for (s32 i = 0; i < width * height; ++i) {
		level->setLayoutValueAt(i, layout[i]);
	}

	delete[] layout;

	return level;
}
