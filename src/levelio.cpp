#include <nds.h>

#include <stdlib.h>
#include <stdio.h> 
#include <dirent.h>

#ifndef USING_SDL

#include <fat.h>

#else
 
#include <pwd.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>

#endif

#include "levelio.h"

void LevelIO::makeDir(const WoopsiGfx::WoopsiString& name) {

#ifndef USING_SDL

	if (!fatInitDefault()) return;

#endif

	char* buffer = new char[name.getByteCount() + 1];
	name.copyToCharArray(buffer);
	
	mkdir(buffer, S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);
	
	delete[] buffer;
}

WoopsiGfx::WoopsiString LevelIO::getTargetDirectoryName() {

#ifndef USING_SDL

	if (!fatInitDefault()) return "";

#endif
	
#ifndef USING_SDL
	
	WoopsiGfx::WoopsiString dirName("/data");
	makeDir(dirName);

#else
	
	// Get user's home directory
	const char *homeDir = getenv("HOME");
	
	if (!homeDir) {
		struct passwd* pwd = getpwuid(getuid());
		
		if (pwd) {
			homeDir = pwd->pw_dir;
		}
	}
	
	WoopsiGfx::WoopsiString dirName(homeDir);

#endif

	dirName.append("/EarthShakerDS");
	makeDir(dirName);
		
	dirName.append("/");
	
	return dirName;
}

void LevelIO::save(LevelDefinitionBase* level) {

#ifndef USING_SDL

	if (!fatInitDefault()) return;

#endif
	
	WoopsiGfx::WoopsiString fileName = getTargetDirectoryName();

	fileName.append(level->getName());

	BinaryFile file(fileName, BinaryFile::FILE_MODE_WRITE, BinaryFile::ENDIAN_MODE_BIG_ENDIAN);

	if (!file.isReadyForIO()) return;
	
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

	// Block types
	file.writeU8(level->getBoulderType());
	file.writeU8(level->getWallType());
	file.writeU8(level->getSoilType());
	file.writeU8(level->getDoorType());

	// Layout
	for (s32 i = 0; i < level->getWidth() * level->getHeight(); ++i) {
		file.writeU8(level->getLayout()[i]);
	}
}

MutableLevelDefinition* LevelIO::load(const WoopsiGfx::WoopsiString& fileName) {

#ifndef USING_SDL

	if (!fatInitDefault()) return NULL;

#endif
	
	WoopsiGfx::WoopsiString fileAndPathName = getTargetDirectoryName();
	fileAndPathName.append(fileName);

	BinaryFile file(fileAndPathName, BinaryFile::FILE_MODE_READ, BinaryFile::ENDIAN_MODE_BIG_ENDIAN);

	if (!file.isReadyForIO()) return NULL;

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

	BoulderType boulderType = (BoulderType)file.readU8();
	WallType wallType = (WallType)file.readU8();
	SoilType soilType = (SoilType)file.readU8();
	DoorType doorType = (DoorType)file.readU8();

	MutableLevelDefinition* level = new MutableLevelDefinition(width, height,
														levelNumber, levelName,
														boulderType, wallType,
														soilType, doorType);

	for (s32 i = 0; i < width * height; ++i) {
		level->setLayoutValueAt(i, file.readU8());
	}

	return level;
}

WoopsiArray<WoopsiGfx::WoopsiString>* LevelIO::getLevelNames() {
	
	WoopsiArray<WoopsiGfx::WoopsiString>* levelNames = new WoopsiArray<WoopsiGfx::WoopsiString>();
	
#ifndef USING_SDL

	if (!fatInitDefault()) return levelNames;

#endif

	WoopsiGfx::WoopsiString directoryName = getTargetDirectoryName();
	
	char* buffer = new char[directoryName.getByteCount() + 1];
	directoryName.copyToCharArray(buffer);

	struct stat st;
	
	// Get a copy of the path char array so that it can be used with libfat
	DIR* dir = opendir(buffer);
	
	// Did we get the dir successfully?
	if (dir == NULL) {
		delete [] buffer;
		return NULL;
	}
	
	// Read data into options list
	struct dirent* ent;
	
	while ((ent = readdir(dir)) != 0) {
		
		char* newPath = new char[strlen(ent->d_name) + directoryName.getByteCount() + 2];
		directoryName.copyToCharArray(newPath);
		strcat(newPath, "/");
		strcat(newPath, ent->d_name);
		int result = stat(newPath, &st);
		delete [] newPath;
		if (result) {
			continue;
		}
		
		// st.st_mode & S_IFDIR indicates a directory
		if (!(st.st_mode & S_IFDIR)) {
			levelNames->push_back(ent->d_name);
		}
	}
	
	// Close the directory
	closedir(dir);
	
	delete[] buffer;
	
	return levelNames;
}
