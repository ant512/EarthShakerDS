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
	static WoopsiGfx::FrameBuffer* _topBuffer;		/**< Top frame buffer. */
	static WoopsiGfx::FrameBuffer* _bottomBuffer;	/**< Bottom frame buffer. */
	static WoopsiGfx::Graphics* _topGfx;			/**< Top display graphics object. */
	static WoopsiGfx::Graphics* _bottomGfx;			/**< Bottom display graphics object. */
	static s32 _padHistory[PAD_HISTORY_SIZE];		/**< Queue of recent button presses. */
	static s32 _upPriority;							/**< How recently up was pressed relative to other directions. */
	static s32 _downPriority;						/**< How recently down was pressed relative to other directions. */
	static s32 _leftPriority;						/**< How recently left was pressed relative to other directions. */
	static s32 _rightPriority;						/**< How recently right was pressed relative to other directions. */

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

	/**
	 * Calculates the priority of all held directions by working out which were
	 * pressed most recently.  This allows us to favour the most recently-
	 * pressed direction when reacting to the pad.  Priorities are 8 (highest),
	 * 4, 2 and 1 (lowest), so that they can be added together to obtain the
	 * priority of the vertical vs. the horizontal direction.
	 */
	static void calculateDirectionPriorities();

	/**
	 * Adds the specified key to the front of the pad history queue.
	 * @param key The key to enqueue.
	 */
	static void queuePadHistory(s32 key);
};

#endif
