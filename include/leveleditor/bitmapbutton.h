#ifndef _BITMAP_BUTTON_H_
#define _BITMAP_BUTTON_H_

#include <graphics.h>
#include <bitmapbase.h>

#include "buttonbase.h"
#include "spectrumcolours.h"

/**
 * Button that contains a bitmap image.
 */
class BitmapButton : public ButtonBase {
public:

	/**
	 * Constructor.
	 * @param x X co-ordinate of the button.
	 * @param y Y co-ordinate of the button.
	 * @param width Width of the button.
	 * @param height Height of the button.
	 * @param id ID of the button.
	 * @param bitmap Bitmap to draw within the button.
	 */
	BitmapButton(s32 x, s32 y, s32 width, s32 height, s32 id, const WoopsiGfx::BitmapBase* bitmap)
	 : ButtonBase(x, y, width, height, id) {
		_bitmap = bitmap;
	};

	/**
	 * Destructor.
	 */
	~BitmapButton() { };


	/**
	 * Draws the button.  Bitmap is automatically centred within the button.
	 * @param gfx Graphics object to draw to.
	 */
	void render(WoopsiGfx::Graphics* gfx) {
		s32 bitmapX = ((_width - _bitmap->getWidth()) / 2) + _x;
		s32 bitmapY = ((_height - _bitmap->getHeight()) / 2) + _y;

		gfx->drawBitmap(bitmapX, bitmapY, _bitmap->getWidth(), _bitmap->getHeight(), _bitmap, 0, 0);

		if (_clicked) {
			gfx->dim(bitmapX, bitmapY, _bitmap->getWidth(), _bitmap->getHeight());
		}
	};

private:
	const WoopsiGfx::BitmapBase* _bitmap;		/**< Bitmap drawn within button. */
};

#endif
