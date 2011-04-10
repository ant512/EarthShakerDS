#ifndef _NEWTOPAZ_H_
#define _NEWTOPAZ_H_

#include <packedfont1.h>

/**
 * NewTopaz font.
 */
class NewTopaz : public WoopsiGfx::PackedFont1 {
public:
	/**
	 * Constructor.
	 * @param fixedWidth Set to 0 for proportional or 1 for fixed width.
	 */
	NewTopaz(u8 fixedWidth = 0);
};

#endif
