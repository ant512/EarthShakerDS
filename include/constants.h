#ifndef _CONSTANTS_H_
#define _CONSTANTS_H_

/**
 * Number of frames before the screen is redrawn and block animations are
 * cycled.
 */
const s32 ANIMATION_TIME = 3;

/**
 * Number of frames before the level is iterated and block movements are
 * performed.
 */
const s32 MOVEMENT_TIME = 6;

/**
 * Width of the screen.
 */
const s32 DISPLAY_WIDTH = 256;

/**
 * Height of the screen.
 */
const s32 DISPLAY_HEIGHT = 176;

/**
 * Points for collecting a diamond.
 */
const s32 DIAMOND_SCORE = 10;

/**
 * Points for extinguising a fire with a bubble.
 */
const s32 FIRE_EXTINGUISH_SCORE = 100;

/**
 * Points for collecting a bean.
 */
const s32 BEAN_SCORE= 64;

/**
 * Number of lives players start with.
 */
const s32 STARTING_LIVES = 5;


/**
 * Amount of time each level starts with.
 */
const s32 STARTING_TIME = 2000;


/**
 * Amount removed from remaining time every time the game is updated.
 */
const s32 TIME_DECREMENT = 1;

#endif
