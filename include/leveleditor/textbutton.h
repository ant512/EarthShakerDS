#ifndef _TEXT_BUTTON_H_
#define _TEXT_BUTTON_H_

#include <graphics.h>
#include <woopsistring.h>

#include "buttonbase.h"
#include "gamefont.h"
#include "spectrumcolours.h"

/**
 * Button that contains a text label.
 */
class TextButton : public ButtonBase {
public:

	/**
	 * Constructor.
	 * @param x X co-ordinate of the button.
	 * @param y Y co-ordinate of the button.
	 * @param width Width of the button.
	 * @param height Height of the button.
	 * @param id ID of the button.
	 * @param text Text to display within the button.
	 */
	TextButton(s32 x, s32 y, s32 width, s32 height, s32 id, const WoopsiGfx::WoopsiString& text)
	 : ButtonBase(x, y, width, height, id) {
		_text = text;
	};

	/**
	 * Destructor.
	 */
	~TextButton() { };

	/**
	 * Draws the button.  Text is automatically centred within the button.
	 * @param gfx Graphics object to draw to.
	 */
	void render(WoopsiGfx::Graphics* gfx) {
		s32 textWidth = _font.getStringWidth(_text);
		s32 textX = ((_width - textWidth) / 2) + _x;
		s32 textY = ((_height - _font.getHeight()) / 2) + _y;

		u16 backgroundColour = _clicked ? COLOUR_MAGENTA_DARK : COLOUR_MAGENTA;
		
		gfx->drawFilledRect(_x, _y + 1, _width, _height - 2, backgroundColour);
		gfx->drawLine(_x + 1, _y, _x + _width - 2, _y, backgroundColour);
		gfx->drawLine(_x + 1, _y + _height - 1, _x + _width - 2, _y + _height - 1, backgroundColour);

		gfx->drawText(textX, textY, &_font, _text, 0, _text.getLength(), COLOUR_WHITE);
	};
	
	/**
	 * Gets the button text.
	 * @return The button text.
	 */
	const WoopsiGfx::WoopsiString& getText() {
		return _text;
	};

private:
	WoopsiGfx::WoopsiString _text;		/**< Button text. */
	GameFont _font;						/**< Button font. */
};

#endif
