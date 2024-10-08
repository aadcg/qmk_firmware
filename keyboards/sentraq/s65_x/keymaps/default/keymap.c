#include QMK_KEYBOARD_H

#define _BL 0
#define _AL 1
#define _FL 2
#define _UL 3

#define FL_CAPS LT(_FL, KC_CAPS) // Tap to toggle caps lock and hold to activate function layer

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* 0: Main layer, swapped alt and GUI for Mac
   * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───────┬───┐
   * │GE │1 !│2 @│3 #│4 $│5 %│6 ^│7 &│8 *│9 (│0 )│- _│= +│Bksp   │Del│
   * ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─────┼───┤
   * │Tab  │ Q │ W │ E │ R │ T │ Y │ U │ I │ O │ P │[ {│] }│\ |  │End│
   * ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴─────┼───┤
   * │FnCaps│ A │ S │ D │ F │ G │ H │ J │ K │ L │; :│' "│Enter   │PUp│
   * ├──────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴────┬───┼───┤
   * │Shift   │ Z │ X │ C │ V │ B │ N │ M │, <│. >│/ ?│Shift │Up │PDn│
   * ├────┬───┴┬──┴─┬─┴───┴───┴───┴───┴───┴──┬┴──┬┴──┬┴──┬───┼───┼───┤
   * │Ctrl│GUI │Alt │Space                   │Alt│Fn │Ctl│Lft│Dwn│Rgt│
   * └────┴────┴────┴────────────────────────┴───┴───┴───┴───┴───┴───┘
   */

  /* 0: ANSI qwerty */
  [_BL] = LAYOUT_65_ansi(
    QK_GESC, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC, KC_DEL,
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS, KC_END,
    FL_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,  KC_PGUP,
    KC_LSFT,          KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, KC_UP,   KC_PGDN,
    KC_LCTL, KC_LGUI, KC_LALT,                   KC_SPC,                             KC_RALT, MO(_FL), KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT
  ),


  /* 1: Locking arrow keys to WASD for when you need dedicated arrow keys
   * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───────┬───┐
   * │   │   │   │   │   │   │   │   │   │   │   │   │   │       │   │
   * ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─────┼───┤
   * │     │   │Up │   │   │   │   │   │   │   │   │   │   │     │   │
   * ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴─────┼───┤
   * │      │Lft│Dwn│Rgt│   │   │   │   │   │   │   │   │        │   │
   * ├──────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴────┬───┼───┤
   * │        │   │   │   │   │   │   │   │   │   │   │      │   │   │
   * ├────┬───┴┬──┴─┬─┴───┴───┴───┴───┴───┴──┬┴──┬┴──┬┴──┬───┼───┼───┤
   * │    │Swp │Nrm │                        │   │   │   │   │   │   │
   * └────┴────┴────┴────────────────────────┴───┴───┴───┴───┴───┴───┘
   */

  [_AL] = LAYOUT_65_ansi(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, KC_UP,   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______,
    _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, AG_SWAP, AG_NORM,                   _______,                            _______, _______, _______, _______, _______, _______
  ),


  /* 2: Fn layer
   * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───────┬───┐
   * │` ~│F1 │F2 │F3 │F4 │F5 │F6 │F7 │F8 │F9 │F10│F11│F12│       │   │
   * ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─────┼───┤
   * │     │_AL│Up │   │   │   │   │   │PUp│PDn│PSc│SLk│Pau│     │   │
   * ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴─────┼───┤
   * │      │Lft│Dwn│Rgt│   │   │Lft│Dwn│Up │Rgt│   │   │        │   │
   * ├──────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴────┬───┼───┤
   * │        │_UL│   │   │   │   │   │   │Hm │End│   │      │VUp│   │
   * ├────┬───┴┬──┴─┬─┴───┴───┴───┴───┴───┴──┬┴──┬┴──┬┴──┬───┼───┼───┤
   * │    │    │    │                        │   │   │   │Mut│VDn│Ply│
   * └────┴────┴────┴────────────────────────┴───┴───┴───┴───┴───┴───┘
   */

  [_FL] = LAYOUT_65_ansi(
    KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, _______,
    _______, TG(_AL), KC_UP,   _______, _______, _______, _______, _______, KC_PGUP, KC_PGDN, KC_PSCR, KC_SCRL, KC_PAUS, _______, _______,
    _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, _______,          _______, _______,
    _______,          TG(_UL), _______, _______, _______, _______, _______, _______, KC_HOME, KC_END,  _______, _______, KC_VOLU, _______,
    _______, _______, _______,                   _______,                            _______, _______, _______, KC_MUTE, KC_VOLD, KC_MPLY
  ),


  /* 3: Locking layer for controlling the underglow
   * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───────┬───┐
   * │   │   │   │   │   │   │   │   │   │   │   │   │   │       │   │
   * ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─────┼───┤
   * │     │BTg│BSt│   │   │   │   │   │   │   │   │   │   │     │   │
   * ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴─────┼───┤
   * │      │RTg│RMd│   │   │   │   │   │   │   │   │   │        │   │
   * ├──────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴────┬───┼───┤
   * │        │   │RH+│RH-│RS+│RS-│RV+│RV-│   │   │   │      │   │   │
   * ├────┬───┴┬──┴─┬─┴───┴───┴───┴───┴───┴──┬┴──┬┴──┬┴──┬───┼───┼───┤
   * │    │    │    │                        │   │   │   │   │   │   │
   * └────┴────┴────┴────────────────────────┴───┴───┴───┴───┴───┴───┘
   */

  [_UL] = LAYOUT_65_ansi(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, BL_TOGG, BL_STEP, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, UG_TOGG, UG_NEXT, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______,
    _______,          _______, UG_HUEU, UG_HUED, UG_SATU, UG_SATD, UG_VALU, UG_VALD, _______, _______, _______, _______, _______, _______,
    _______, _______, _______,                   _______,                            _______, _______, _______, _______, _______, _______
  ),
};
