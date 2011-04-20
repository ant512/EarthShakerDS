#ifndef _PAD_STATE_H_
#define _PAD_STATE_H_

/**
 * Abstraction of the DS' pad state to aid porting.
 */
typedef struct {
	bool up : 1;		/**< Is up pressed? */
	bool down : 1;		/**< Is down pressed? */
	bool left : 1;		/**< Is left pressed? */
	bool right : 1;		/**< Is right pressed? */
	bool a : 1;			/**< Is a pressed? */
	bool b : 1;			/**< Is b pressed? */
	bool x : 1;			/**< Is x pressed? */
	bool y : 1;			/**< Is y pressed? */
	bool l : 1;			/**< Is l pressed? */
	bool r : 1;			/**< Is r pressed? */
	bool start : 1;		/**< Is start pressed? */
	bool select : 1;	/**< Is select pressed? */
} PadState;

#endif
