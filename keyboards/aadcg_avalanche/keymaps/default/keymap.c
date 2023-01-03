#include QMK_KEYBOARD_H

#define L1_ENT  LT(1,KC_ENT)    // Tap for ENT   ; hold for L1
#define L2_DEL  LT(2,KC_DEL)    // Tap for DEL   ; hold for L2

#define CUT   S(KC_DEL)
#define COPY  C(KC_INS)
#define PASTE S(KC_INS)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT(
            KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                                        KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINUS,
            KC_LBRC, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                                        KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_RBRC,
  XXXXXXX,  KC_TAB,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                                        KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, XXXXXXX,
            KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_GRV, KC_MUTE,  KC_PSCR, KC_EQL,  KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
                                       KC_LGUI, KC_LALT, KC_LCTL, KC_SPC, L1_ENT,   L2_DEL,  KC_BSPC, KC_RCTL, KC_RALT, KC_BSLS
                 ),
  [1] = LAYOUT(
            KC_F12,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                                       KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
            QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                                     XXXXXXX, KC_HOME, KC_UP,   KC_END,  KC_PGUP, QK_BOOT,
   XXXXXXX, KC_CAPS, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, XXXXXXX,                                     XXXXXXX, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN, XXXXXXX, _______,
            KC_NUM,  KC_SCRL, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, _______, _______, _______, KC_AGIN, PASTE,   COPY,    CUT,     KC_UNDO, _______,
                                       _______, _______, _______, _______, _______, KC_DEL,  KC_BSPC, KC_SPC,  KC_ENT,  _______
                 ),
  [2] = LAYOUT(
            _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
            QK_BOOT, XXXXXXX, XXXXXXX, KC_MS_U, XXXXXXX, XXXXXXX,                                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, QK_BOOT,
   XXXXXXX, _______, XXXXXXX, KC_MS_L, KC_MS_D, KC_MS_R, XXXXXXX,                                     XXXXXXX, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI, XXXXXXX, _______,
            XXXXXXX, KC_UNDO, CUT,     COPY,    PASTE,   KC_AGIN, _______, _______, _______, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                       _______, _______, KC_BTN3, KC_BTN1, KC_BTN2, _______, _______, _______, _______, _______
                 )
};

#ifdef OLED_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  return OLED_ROTATION_180;
}

bool oled_task_user(void) {
  // Print current layer
  switch (get_highest_layer(layer_state)) {
  case 0:
    oled_write_ln_P(PSTR("Layer: Base"), false);
    break;
  case 1:
    oled_write_ln_P(PSTR("Layer: Navigation"), false);
    break;
  case 2:
    oled_write_ln_P(PSTR("Layer: Mouse"), false);
    break;
  default:
    oled_write_ln_P(PSTR("Layer: Undefined"), false);
  }
  // Host Keyboard LED Status
  led_t led_state = host_keyboard_led_state();
  oled_write_P(led_state.caps_lock ? PSTR("CAP ") : PSTR("    "), false);
  oled_write_P(led_state.num_lock ? PSTR("NUM ") : PSTR("    "), false);
  oled_write_P(led_state.scroll_lock ? PSTR("SCR ") : PSTR("    "), false);
  oled_write_P(PSTR("\n\n"), false);
  oled_write_ln_P(PSTR("Happy Typing!"), false);

  return false;
}
#endif

#ifdef ENCODER_ENABLE
bool encoder_update_user(uint8_t index, bool clockwise) {
  /* if (!encoder_update_user(index, clockwise)) { return false; } */
  if (index == 0) {
    if (clockwise) {
      /* tap_code_delay(KC_VOLU, 10); */
      tap_code(KC_VOLU);
    } else {
      tap_code(KC_VOLD);
    }
  } else if (index == 1) {
    if (clockwise) {
      tap_code(KC_PGUP);
    } else {
      tap_code(KC_PGDN);
    }
  }
  return true;
}
#endif
