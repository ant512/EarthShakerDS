#ifndef _LEVEL_EDITOR_H_
#define _LEVEL_EDITOR_H_

class LevelEditor {
public:
	LevelEditor() {
		_topGfx = Hardware::getTopGfx();
		_bottomGfx = Hardware::getBottomGfx();

		_level = new Level(LEVEL_WIDTH, LEVEL_HEIGHT, 0, "Test");
	};

	~LevelEditor() { };

	void main() {

	};

private:

	static const s32 LEVEL_WIDTH = 30;
	static const s32 LEVEL_HEIGHT = 20;

	WoopsiGfx::Graphics* _topGfx;			/**< Pointer to the graphics object for the top display. */
	WoopsiGfx::Graphics* _bottomGfx;		/**< Pointer to the graphics object for the bottom display. */

	Level* _level;							/**< The currently-active level.*/
};

#endif
