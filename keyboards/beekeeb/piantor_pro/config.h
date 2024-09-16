// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_TIMEOUT 1000U
#define SERIAL_USART_FULL_DUPLEX
#define SERIAL_USART_TX_PIN GP0
#define SERIAL_USART_RX_PIN GP1
#define SERIAL_USART_PIN_SWAP
#define USB_VBUS_PIN GP19
#define SPLIT_HAND_PIN GP17
#define SPLIT_HAND_PIN_LOW_IS_LEFT

/* #define PERMISSIVE_HOLD */
/* #define TAPPING_TERM 250 */

#define TAPPING_TERM 175
#define QUICK_TAP_TERM 100
#define DEBOUNCE 5
#define BOTH_SHIFTS_TURNS_ON_CAPS_WORD
#define NO_AUTO_SHIFT_ALPHA

/* Mouse settings */
#define MOUSEKEY_DELAY 0
#define MOUSEKEY_INTERVAL 16    /* set to 1/<monitor refresh rate in Hz> */
#define MOUSEKEY_MOVE_DELTA 12  /* acceleration */
#define MOUSEKEY_MAX_SPEED 5
#define MOUSEKEY_TIME_TO_MAX 45

#define LAYER_STATE_8BIT
#define NO_MUSIC_MODE
