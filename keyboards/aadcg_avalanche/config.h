#pragma once

/* Key matrix size */
/* Rows are doubled-up */
#define MATRIX_ROWS 10
#define MATRIX_COLS 7

/* Wiring of each half */
#define MATRIX_ROW_PINS { D4, C6, D7, E6, B4 }
#define MATRIX_COL_PINS { F5, F6, F7, B1, B3, B2, B6 }
#define DIODE_DIRECTION COL2ROW

/* Communication between halves */
#define SOFT_SERIAL_PIN D2

#define NO_MUSIC_MODE

/* Limit number of layers to 8 */
#define LAYER_STATE_8BIT

/* Encoder support */
#define ENCODERS_PAD_A { B5 }
#define ENCODERS_PAD_B { F4 }
#define ENCODER_RESOLUTION 4

/* Mouse settings */
#define MOUSEKEY_DELAY 0
#define MOUSEKEY_INTERVAL 16    /* set to 1/<monitor refresh rate in Hz> */
#define MOUSEKEY_MOVE_DELTA 12  /* acceleration */
#define MOUSEKEY_MAX_SPEED 5
#define MOUSEKEY_TIME_TO_MAX 45
