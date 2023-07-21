#pragma once

/* Wiring of each half */
#define MATRIX_ROW_PINS { C6, D7, E6, B4, B5 }
#define MATRIX_COL_PINS { F6, F7, B1, B3, B2, B6 }
#define DIODE_DIRECTION COL2ROW

/* Communication between halves */
#define USE_SERIAL
#define SERIAL_USE_MULTI_TRANSACTION
#define EE_HANDS

#define NO_MUSIC_MODE

/* Syncs the on/off state of the OLED between the halves. */
#define SPLIT_OLED_ENABLE

/* Limit number of layers to 8 */
#define LAYER_STATE_8BIT

/* Tapping config */
#define TAPPING_TERM 175
/* Test */
/* #define PERMISSIVE_HOLD */

#define DEBOUNCE 5

/* Mouse settings */
#define MOUSEKEY_DELAY 0
#define MOUSEKEY_INTERVAL 16    /* set to 1/<monitor refresh rate in Hz> */
/* Try 8, 10, 30 */
#define MOUSEKEY_MOVE_DELTA 12  /* acceleration */
#define MOUSEKEY_MAX_SPEED 5
#define MOUSEKEY_TIME_TO_MAX 45

/* The idea of Caps Word is interesting, but it clashes with my KC__C  */
#define BOTH_SHIFTS_TURNS_ON_CAPS_WORD

/* It would be nice to enable depending on layer */
/* See https://github.com/qmk/qmk_firmware/issues/8946 */
#define NO_AUTO_SHIFT_ALPHA
