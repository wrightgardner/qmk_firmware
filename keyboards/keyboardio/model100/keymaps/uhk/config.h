#ifndef CONFIG_H_
#define CONFIG_H_
#pragma once

// turn off leds after 5 min
#define RGB_MATRIX_TIMEOUT 300000

// default but used in macros
#undef TAPPING_TERM
#define TAPPING_TERM 200

// Prevent normal rollover on alphas from accidentally triggering mods.
// #define IGNORE_MOD_TAP_INTERRUPT

// Enable rapid switch from tap to hold, disables double tap hold auto-repeat.
/* #define QUICK_TAP_TERM 0 */
#define QUICK_TAP_TERM 175 // allows scroll mode to work for homerow without having to use the arrows

// Auto Shift
#define NO_AUTO_SHIFT_ALPHA
#define AUTO_SHIFT_TIMEOUT TAPPING_TERM
#define AUTO_SHIFT_NO_SETUP

// Mouse key speed and acceleration.
#undef MOUSEKEY_DELAY
#define MOUSEKEY_DELAY          0
#undef MOUSEKEY_INTERVAL
#define MOUSEKEY_INTERVAL       16
#undef MOUSEKEY_WHEEL_DELAY
#define MOUSEKEY_WHEEL_DELAY    0
#undef MOUSEKEY_MAX_SPEED
#define MOUSEKEY_MAX_SPEED      6
#undef MOUSEKEY_TIME_TO_MAX
#define MOUSEKEY_TIME_TO_MAX    64

// #define PERMISSIVE_HOLD
#define FLOW_TAP_TERM 75
#define CHORDAL_HOLD
#define HOLD_ON_OTHER_KEY_PRESS_PER_KEY


#endif // CONFIG_H_
