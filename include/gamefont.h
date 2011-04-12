#ifndef _GAMEFONT_H_
#define _GAMEFONT_H_

#include <packedfont1.h>

/**
 * GameFont font.
 */
class GameFont : public WoopsiGfx::PackedFont1 {
public:
	/**
	 * Constructor.
	 * @param fixedWidth Set to 0 for proportional or 1 for fixed width.
	 */
	GameFont(u8 fixedWidth = 0);
};

#endif
