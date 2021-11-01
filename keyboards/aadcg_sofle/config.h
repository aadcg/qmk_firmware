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
#define TAP_CODE_DELAY 0

/* Enables a key to act as both a modifier and SPC/RET */
#define IGNORE_MOD_TAP_INTERRUPT

#define DEBOUNCE 5

/* Mouse settings */
#define MOUSEKEY_DELAY 0
#define MOUSEKEY_INTERVAL 16    /* set to 1/<monitor refresh rate in Hz> */
#define MOUSEKEY_MOVE_DELTA 12  /* acceleration */
#define MOUSEKEY_MAX_SPEED 5
#define MOUSEKEY_TIME_TO_MAX 45

/* See TT(layer) */
#define TAPPING_TOGGLE 2
