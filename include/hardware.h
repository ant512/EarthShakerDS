#ifndef _HARDWARE_H_
#define _HARDWARE_H_

#include <nds.h>

#include "framebuffer.h"
#include "graphics.h"
#include "padstate.h"

/**
 * Provides an interface to the DS' hardware.
 */
class Hardware {
public:

	/**
	 * Number of key presses stored in the pad history queue.
	 */
	static const s32 PAD_HISTORY_SIZE = 10;

	/**
	 * Initialise the hardware.
	 */
	static void init();

	/**
	 * Shutdown the hardware.
	 */
	static void shutdown();

	/**
	 * Get a pointer to a Graphics object that can draw to the top screen.
	 * @return A pointer to a Graphics object that can draw to the top screen.
	 */
	static inline WoopsiGfx::Graphics* getTopGfx() {
		return _topGfx;
	};

	/**
	 * Get a pointer to a Graphics object that can draw to the bottom screen.
	 * @return A pointer to a Graphics object that can draw to the bottom
	 * screen.
	 */
	static inline WoopsiGfx::Graphics* getBottomGfx() {
		return _bottomGfx;
	};

	/**
	 * Get a reference to a struct representing the state of the DS' buttons.
	  *@return A reference to the current pad state.
	 */
	static inline const PadState& getPadState() {
		return _pad;
	};

	static inline const StylusState& getStylusState() {
		return _stylus;
	};

	/**
	 * Waits for the next VBlank.  Also updates the pad state.
	 */
	static void waitForVBlank();

	/**
	 * Check if the most recently-pressed direction was vertical or horizontal.
	 * @return True if the most recently-pressed direction was vertical; false
	 * if it was horizontal.
	 */
	static bool isMostRecentDirectionVertical();

private:
	static PadState _pad;							/**< State of the DS' pad. */
	static StylusState _stylus;						/**< State of the DS' stylus. */
	static WoopsiGfx::FrameBuffer* _topBuffer;		/**< Top frame buffer. */
	static WoopsiGfx::FrameBuffer* _bottomBuffer;	/**< Bottom frame buffer. */
	static WoopsiGfx::Graphics* _topGfx;			/**< Top display graphics object. */
	static WoopsiGfx::Graphics* _bottomGfx;			/**< Bottom display graphics object. */
	static bool _isMostRecentDirectionVertical;		/**< Remembers the last direction pressed. */

	/**
	 * Constructor.
	 */
	Hardware() { };

	/**
	 * Destructor.
	 */
	~Hardware() { };

	/**
	 * Update the cached pad state to match the current DS pad state.
	 */ 
	static void updatePadState();
};

#endif
