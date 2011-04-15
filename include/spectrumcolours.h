#ifndef _SPECTRUM_COLOURS_H_
#define _SPECTRUM_COLOURS_H_

/**
 * List of all colours in the game.  Algorithm for producing a colour from an
 * HTML colour code is:
 * (1<<15) + ((b>>3)<<10) + ((g>>3)<<5) + (r>>3)
 */
enum SpectrumColour {
	COLOUR_BLACK = 32768,			/**< #000000 */
	COLOUR_BLUE = 64512,			/**< #0000FF */
	COLOUR_BLUE_DARK = 58368,		/**< #0000CC */
	COLOUR_CYAN = 65504,			/**< #00FFFF */
	COLOUR_CYAN_DARK = 59168,		/**< #00CCCC */
	COLOUR_WHITE = 65535,			/**< #FFFFFF */
	COLOUR_WHITE_DARK = 59193,		/**< #CCCCCC */
	COLOUR_YELLOW = 33791,			/**< #FFFF00 */
	COLOUR_YELLOW_DARK = 33593,		/**< #CCCC00 */
	COLOUR_RED = 32799,				/**< #FF0000 */
	COLOUR_RED_DARK = 32793,		/**< #CC0000 */
	COLOUR_GREEN = 33760,			/**< #00FF00 */
	COLOUR_GREEN_DARK = 33568,		/**< #00CC00 */
	COLOUR_MAGENTA = 64543,			/**< #FF00FF */
	COLOUR_MAGENTA_DARK = 58393		/**< #CC00CC */
};

#endif
