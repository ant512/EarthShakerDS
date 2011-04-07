#ifndef _LEVEL_BASE_H_
#define _LEVEL_BASE_H_

using namespace WoopsiUI;

class LevelBase {
public:

	LevelBase(s32 width, s32 height) {
		_width = width;
		_height = height;
		_data = new BlockBase*[width * height];
	};

	virtual ~LevelBase() {
		delete[] _data;
	};

	inline s32 getWidth() const { return _width; };

	inline s32 getHeight() const { return _height; };

	inline BlockBase* getBlockAt(s32 x, s32 y) const { return _data[(y * _width) + x]; };

	inline void setBlockAt(s32 x, s32 y, BlockBase* block) { _data[(y * _width) + x] = block; };

private:
	s32 _width;
	s32 _height;
	BlockBase* _data;
};

#endif
