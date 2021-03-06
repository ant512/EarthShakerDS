#ifndef _CONSTANTS_H_
#define _CONSTANTS_H_

#include <nds.h>

/**
 * Number of frames before the screen is redrawn and block animations are
 * cycled.
 */
const s32 ANIMATION_TIME = 3;

/**
 * Number of frames before the level is iterated and block movements are
 * performed.
 */
const s32 MOVEMENT_TIME = 8;

/**
 * Number of frames before remaining time decreases.  The DS runs at 60hz, so we
 * decrease the time once per second.
 */
const s32 TIMER_TIME = 30;

/**
 * Amount of time that the map screen is visible.
 */
const s32 MAP_TIME = 600;

/**
 * Width of the game display.
 */
const s32 GAME_WIDTH = 256;

/**
 * Height of the game display.
 */
const s32 GAME_HEIGHT = 176;

/**
 * Points for collecting a diamond.
 */
const s32 DIAMOND_SCORE = 10;

/**
 * Points for extinguising a fire with a bubble.
 */
const s32 FIRE_EXTINGUISH_SCORE = 100;

/**
 * Points for collecting an extra life.
 */
const s32 EXTRA_LIFE_SCORE = 20;

/**
 * Points for collecting a bean.
 */
const s32 BEAN_SCORE = 64;

/**
 * Time increase for collecting a bean.
 */
const s32 BEAN_TIME = 32;

/**
 * Number of lives players start with.
 */
const s32 STARTING_LIVES = 5;

/**
 * Amount of time each level starts with.  Starting time value is the same as
 * the screen width, which makes drawing the timer bar simple.
 */
const s32 STARTING_TIME = 256;

/**
 * Amount of time gravity is inverted for on picking up the gravity switch
 * block.
 */
const s32 GRAVITY_INVERSION_TIME = 99;

/**
 * Points for collecting a gravity inversion block.
 */
const s32 GRAVITY_INVERSION_SCORE = 200;

/**
 * Points for crushing a barrier control block.
 */
const s32 BARRIER_CONTROL_SQUASH_SCORE = 250;

const s32 STANDARD_LEVEL_COUNT = 32;

#endif
