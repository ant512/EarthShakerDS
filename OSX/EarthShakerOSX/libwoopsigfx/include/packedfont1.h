/* Contributed by Jeff Laing
 * 20080414
 */

#ifndef _PACKED_FONT_1_
#define _PACKED_FONT_1_

#include "packedfontbase.h"

namespace WoopsiGfx {

	class MutableBitmapBase;

	/**
	 * PackedFont1 is a class for managing 1-bit packed fonts.
	 */
	class PackedFont1 : public PackedFontBase
	{
	public:
		/**
		 * Constructor.
		 * @param first Ascii index of first character in glphyDdata.
		 * @param last Ascii index of last character in glyphData.
		 * @param glyphData Packed array representing font.
		 * @param glyphOffset Offset into glyphData[] of character[i].
		 * @param glyphWidth Pixel width of character[i].
		 * @param spWidth The height of a space
		 * @param height The height of the font.
		 * @param charTop The height of the font minus the blank spaces below
		 * 'a'.
		 * @param fixedWidth Character width (fixed), or 0 for proportional.
		 */
		PackedFont1(
			u8 first, u8 last,
			const u16 *glyphData,
			const u16 *glyphOffset,
			const u8 *glyphWidth,
			const u8 height,
			const u8 spWidth,
			const u8 charTop,
			const u8 fixedWidth = 0)
			:
			  PackedFontBase(first, last, glyphData, glyphOffset, glyphWidth, height, spWidth, charTop, fixedWidth) { }

		/**
		 * Render an individual character of the font to the specified bitmap.
		 * @param pixelData The font-specific pixel data.
		 * @param pixelsPerRow The number of pixels to render per row (for this
		 * character).
		 * @param bitmap Bitmap to draw to.
		 * @param colour The colour to draw with.  If this is 0 the font's
		 * default colour will be used.
		 * @param x The x co-ordinate of the text.
		 * @param y The y co-ordinate of the text.
		 * @param clipX1 The left edge of the clipping rectangle.
		 * @param clipY1 The top edge of the clipping rectangle.
		 * @param clipX2 The right edge of the clipping rectangle.
		 * @param clipY2 The bottom edge of the clipping rectangle.
		 */
		void renderChar(
			const u16* pixelData, u16 pixelsPerRow,
			MutableBitmapBase* bitmap,
			u16 colour,
			s16 x, s16 y,
			u16 clipX1, u16 clipY1, u16 clipX2, u16 clipY2);
	};
}

#endif
