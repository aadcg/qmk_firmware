#include QMK_KEYBOARD_H

#define C_SPC    CTL_T(KC_SPC) // Tap for Space; hold for Control
#define M_RET    ALT_T(KC_ENT) // Tap for Enter; hold for Meta
#define C_M_SPC  LCA_T(KC_SPC) // Tap for Space; hold for Control-Meta
#define C_M_RET  LCA_T(KC_ENT) // Tap for Enter; hold for Control-Meta
#define SUP      OSM(MOD_LGUI) // Sticky Left Super
#define ALTGR    KC_ALGR       // Right Alt (turning into a sticky key
                               // doesn't let you type "á" and friends)

#define KC__I     LT(0,KC_I)     // Tap for i  ; hold for I
#define KC__COMM  LT(0,KC_COMM)  // Tap for ,  ; hold for M-,
#define KC__DOT   LT(0,KC_DOT)   // Tap for .  ; hold for M-.
#define KC__K     LT(0,KC_K)     // Tap for k  ; hold for M-x
#define KC__D     LT(0,KC_D)     // Tap for d  ; hold for C-x
#define KC__C     LT(0,KC_C)     // Tap for c  ; hold for C-c
#define KC__U     LT(0,KC_U)     // Tap for u  ; hold for C-u
#define KC__A     LT(0,KC_A)     // Tap for a  ; hold for C-a
#define KC__W     LT(0,KC_W)     // Tap for w  ; hold for C-w
#define KC__E     LT(0,KC_E)     // Tap for e  ; hold for C-e
#define KC__S     LT(0,KC_S)     // Tap for s  ; hold for C-s
#define KC__Y     LT(0,KC_Y)     // Tap for y  ; hold for C-y
#define KC__R     LT(0,KC_R)     // Tap for r  ; hold for C-r
#define KC__G     LT(0,KC_G)     // Tap for g  ; hold for (
#define KC__H     LT(0,KC_H)     // Tap for h  ; hold for )
#define KC__J     LT(0,KC_J)     // Tap for j  ; hold for C-SPC
#define KC__0     LT(0,KC_0)     // Tap for 0  ; hold for C-x 0
#define KC__1     LT(0,KC_1)     // Tap for 1  ; hold for C-x 1
#define KC__2     LT(0,KC_2)     // Tap for 2  ; hold for C-x 2
#define KC__3     LT(0,KC_3)     // Tap for 3  ; hold for C-x 3
#define KC__4     LT(0,KC_4)     // Tap for 4  ; hold for C-x 4
#define KC__B     LT(0,KC_B)     // Tap for b  ; hold for C-x b
#define KC__O     LT(0,KC_O)     // Tap for o  ; hold for s-o
#define KC__F     LT(0,KC_F)     // Tap for f  ; hold for C-x C-f
#define KC__QUOT  LT(0,KC_QUOT)  // Tap for '  ; hold for "
#define KC__MINUS LT(0,KC_MINUS) // Tap for -  ; hold for _
#define KC__RBRC  LT(0,KC_RBRC)  // Tap for ]} ; hold for =

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
                 KC_GRV,    KC_9,  KC_8,  KC_7,  KC_6,    KC_5,                                      KC__0, KC__1,  KC__2,    KC__3,   KC__4,   KC__RBRC, \
                 KC__QUOT,  KC_Q,  KC__W, KC__E, KC__R,   KC_T,                                      KC__Y, KC__U,  KC__I,    KC__O,   KC_P,    KC_LBRC,  \
        KC_CAPS, KC_TAB,    KC__A, KC__S, KC__D, KC__F,   KC__G,                                     KC__H, KC__J,  KC__K,    KC_L,    KC_SCLN, KC_BSPC,  KC_RBRC, \
                 KC__MINUS, KC_Z,  KC_X,  KC__C, KC_V,    KC__B, XXXXXXX, KC_MUTE, KC_PSCR, XXXXXXX, KC_N,  KC_M,   KC__COMM, KC__DOT, KC_SLSH, KC_BSLS,  \
                                          SUP,   KC_LSFT, C_SPC, C_M_RET, KC_ESC,  KC_RSPC, C_M_SPC, M_RET, OSL(1), ALTGR                                 \
    ),
    [1] = LAYOUT(
                 KC_F12,  KC_F11,  KC_F10,  KC_F9,   KC_F8,   KC_F7,                                       KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,    KC_F6,
                 QK_BOOT, XXXXXXX, KC_BTN2, KC_MS_U, KC_BTN1, KC_LCBR,                                     KC_RCBR, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  QK_BOOT,
        _______, _______, XXXXXXX, KC_MS_L, KC_MS_D, KC_MS_R, KC_LBRC,                                     KC_RBRC, KC_UP,   KC_DOWN, KC_LEFT, KC_RIGHT, _______, _______,
                 _______, XXXXXXX, XXXXXXX, XXXXXXX, KC_BTN3, XXXXXXX, _______, _______, _______, _______, XXXXXXX, KC_PGUP, KC_PGDN, XXXXXXX, XXXXXXX,  _______,
                                            _______, _______, _______, _______, _______, _______, _______, _______, _______, _______

)
};

// Initialize variable holding the binary
// representation of active modifiers.
uint8_t mod_state;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  // Store the current modifier state in the variable for later reference
  mod_state = get_mods();
  switch (keycode) {
  case LT(0,KC_D):
    if (record->tap.count && record->event.pressed) {
      tap_code16(KC_D);    // Intercept tap function to send d
    } else if (record->event.pressed) {
      tap_code16(C(KC_X)); // Intercept hold function to send C-x
    }
    return false;
  case LT(0,KC_C):
    if (record->tap.count && record->event.pressed) {
      tap_code16(KC_C);    // Intercept tap function to send c
    } else if (record->event.pressed) {
      tap_code16(C(KC_C)); // Intercept hold function to send C-c
    }
    return false;
  case LT(0,KC_K):
    if (record->tap.count && record->event.pressed) {
      tap_code16(KC_K);       // Intercept tap function to send c
    } else if (record->event.pressed) {
      tap_code16(LALT(KC_X)); // Intercept hold function to send M-x
    }
    return false;
  case LT(0,KC_0):
    if (record->tap.count && record->event.pressed) {
      tap_code16(KC_0);    // Intercept tap function to send 0
    } else if (record->event.pressed) {
      tap_code16(C(KC_X)); // Intercept hold function to send C-x
      tap_code16(KC_0);    // Intercept hold function to send 0
    }
    return false;
  case LT(0,KC_1):
    if (record->tap.count && record->event.pressed) {
      tap_code16(KC_1);    // Intercept tap function to send 1
    } else if (record->event.pressed) {
      tap_code16(C(KC_X)); // Intercept hold function to send C-x
      tap_code16(KC_1);    // Intercept hold function to send 1
    }
    return false;
  case LT(0,KC_2):
    if (record->tap.count && record->event.pressed) {
      tap_code16(KC_2);    // Intercept tap function to send 2
    } else if (record->event.pressed) {
      tap_code16(C(KC_X)); // Intercept hold function to send C-x
      tap_code16(KC_2);    // Intercept hold function to send 2
    }
    return false;
  case LT(0,KC_3):
    if (record->tap.count && record->event.pressed) {
      tap_code16(KC_3);    // Intercept tap function to send 3
    } else if (record->event.pressed) {
      tap_code16(C(KC_X)); // Intercept hold function to send C-x
      tap_code16(KC_3);    // Intercept hold function to send 3
    }
    return false;
  case LT(0,KC_4):
    if (record->tap.count && record->event.pressed) {
      tap_code16(KC_4);    // Intercept tap function to send 4
    } else if (record->event.pressed) {
      tap_code16(C(KC_X)); // Intercept hold function to send C-x
      tap_code16(KC_4);    // Intercept hold function to send 4
    }
    return false;
  case LT(0,KC_O):
    if (record->tap.count && record->event.pressed) {
      tap_code16(KC_O);    // Intercept tap function to send o
    } else if (record->event.pressed) {
      tap_code16(LGUI(KC_O)); // Intercept hold function to send s-O
    }
    return false;
  case LT(0,KC_B):
    if (record->tap.count && record->event.pressed) {
      tap_code16(KC_B);    // Intercept tap function to send b
    } else if (record->event.pressed) {
      tap_code16(C(KC_X)); // Intercept hold function to send C-x
      tap_code16(KC_B);    // Intercept hold function to send b
    }
    return false;
  case LT(0,KC_S):
    if (record->tap.count && record->event.pressed) {
      tap_code16(KC_S);    // Intercept tap function to send s
    } else if (record->event.pressed) {
      tap_code16(C(KC_S)); // Intercept hold function to send C-s
    }
    return false;
  case LT(0,KC_Y):
    if (record->tap.count && record->event.pressed) {
      tap_code16(KC_Y);    // Intercept tap function to send y
    } else if (record->event.pressed) {
      tap_code16(C(KC_Y)); // Intercept hold function to send C-y
    }
    return false;
  case LT(0,KC_R):
    if (record->tap.count && record->event.pressed) {
      tap_code16(KC_R);    // Intercept tap function to send r
    } else if (record->event.pressed) {
      tap_code16(C(KC_R)); // Intercept hold function to send C-r
    }
    return false;
  case LT(0,KC_G):
    if (record->tap.count && record->event.pressed) {
      tap_code16(KC_G);    // Intercept tap function to send g
    } else if (record->event.pressed) {
      tap_code16(KC_LPRN); // Intercept hold function to send (
    }
    return false;
  case LT(0,KC_H):
    if (record->tap.count && record->event.pressed) {
      tap_code16(KC_H);    // Intercept tap function to send h
    } else if (record->event.pressed) {
      tap_code16(KC_RPRN); // Intercept hold function to send )
    }
    return false;
  case LT(0,KC_U):
    if (record->tap.count && record->event.pressed) {
      tap_code16(KC_U);    // Intercept tap function to send u
    } else if (record->event.pressed) {
      tap_code16(C(KC_U)); // Intercept hold function to send C-u
    }
    return false;
  case LT(0,KC_A):
    if (record->tap.count && record->event.pressed) {
      tap_code16(KC_A);    // Intercept tap function to send a
    } else if (record->event.pressed) {
      tap_code16(C(KC_A)); // Intercept hold function to send C-a
    }
    return false;
  case LT(0,KC_W):
    if (record->tap.count && record->event.pressed) {
      tap_code16(KC_W);    // Intercept tap function to send w
    } else if (record->event.pressed) {
      tap_code16(C(KC_W)); // Intercept hold function to send C-w
    }
    return false;
  case LT(0,KC_E):
    if (record->tap.count && record->event.pressed) {
      tap_code16(KC_E);    // Intercept tap function to send e
    } else if (record->event.pressed) {
      tap_code16(C(KC_E)); // Intercept hold function to send C-e
    }
    return false;
  case LT(0,KC_J):
    if (record->tap.count && record->event.pressed) {
      tap_code16(KC_J);    // Intercept tap function to send j
    } else if (record->event.pressed) {
      tap_code16(C(KC_SPC)); // Intercept hold function to send C-SPC
    }
    return false;
  case LT(0,KC_F):
    if (record->tap.count && record->event.pressed) {
      tap_code16(KC_F);    // Intercept tap function to send f
    } else if (record->event.pressed) {
      tap_code16(C(KC_X)); // Intercept hold function to send C-x C-f
      tap_code16(C(KC_F)); // Intercept hold function to send C-x C-f
    }
    return false;
  case LT(0,KC_COMM):
    if (record->tap.count && record->event.pressed) {
      tap_code16(KC_COMM);       // Intercept tap function to send ,
    } else if (record->event.pressed) {
      tap_code16(LALT(KC_COMM)); // Intercept hold function to send M-,
    }
    return false;
  case LT(0,KC_DOT):
    if (record->tap.count && record->event.pressed) {
      tap_code16(KC_DOT);       // Intercept tap function to send .
    } else if (record->event.pressed) {
      tap_code16(LALT(KC_DOT)); // Intercept hold function to send M-.
    }
    return false;
  case LT(0,KC_I):
    if (record->tap.count && record->event.pressed) {
      tap_code16(KC_I);       // Intercept tap function to send i
    } else if (record->event.pressed) {
      tap_code16(LSFT(KC_I)); // Intercept hold function to send I
    }
    return false;
  case LT(0,KC_QUOT):
    if (record->tap.count && record->event.pressed) {
      tap_code16(KC_QUOT);    // Intercept tap function to send '
    } else if (record->event.pressed) {
      tap_code16(LSFT(KC_QUOT)); // Intercept hold function to send "
    }
    return false;
  case LT(0,KC_MINUS):
    if (record->tap.count && record->event.pressed) {
      tap_code16(KC_MINUS); // Intercept tap function to send -
    } else if (record->event.pressed) {
      tap_code16(KC_UNDS); // Intercept hold function to send _
    }
    return false;
  case LT(0,KC_RBRC):
    if (record->tap.count && record->event.pressed) {
      tap_code16(KC_RBRC);    // Intercept tap function to send ]
    } else if (record->event.pressed) {
      tap_code16(KC_EQL); // Intercept hold function to send =
    }
    return false;
  case KC_BSPC:
    {
      // Initialize a boolean variable that keeps track
      // of the delete key status: registered or not?
      static bool delkey_registered;
      if (record->event.pressed) {
        // Detect the activation of either shift keys
        if (mod_state & MOD_MASK_SHIFT) {
          // First temporarily canceling both shifts so that
          // shift isn't applied to the KC_DEL keycode
          del_mods(MOD_MASK_SHIFT);
          register_code(KC_DEL);
          // Update the boolean variable to reflect the status of KC_DEL
          delkey_registered = true;
          // Reapplying modifier state so that the held shift key(s)
          // still work even after having tapped the Backspace/Delete key.
          set_mods(mod_state);
          return false;
        }
      } else { // on release of KC_BSPC
        // In case KC_DEL is still being sent even after the release of KC_BSPC
        if (delkey_registered) {
          unregister_code(KC_DEL);
          delkey_registered = false;
          return false;
        }
      }
      // Let QMK process the KC_BSPC keycode as usual outside of shift
      return true;
    }
  }
  return true;
}

#ifdef OLED_ENABLE

static void print_status_narrow(void) {
  // Print current mode
  oled_write_P(PSTR("\n\n"), false);
  oled_write_ln_P(PSTR("MODE"), false);
  oled_write_ln_P(PSTR(""), false);
  if (keymap_config.swap_lctl_lgui) {
    oled_write_ln_P(PSTR("MAC"), false);
  } else {
    oled_write_ln_P(PSTR("Guix"), false);
  }
  oled_write_P(PSTR("\n\n"), false);
  // Print current layer
  oled_write_ln_P(PSTR("LAYER"), false);
  switch (get_highest_layer(layer_state)) {
  case 0:
    oled_write_P(PSTR("Base\n"), false);
    break;
  case 1:
    oled_write_P(PSTR("Fn\n"), false);
    break;
  default:
    oled_write_ln_P(PSTR("Undef"), false);
  }
  oled_write_P(PSTR("\n\n"), false);
  led_t led_usb_state = host_keyboard_led_state();
  oled_write_ln_P(PSTR("RU"), led_usb_state.caps_lock);
}

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  return OLED_ROTATION_270;
}

bool oled_task_user(void) {
  if (is_keyboard_master()) {
    print_status_narrow();
  } else {
    oled_write_P(PSTR("     "), false);
    oled_write_P(PSTR("    H"), false);
    oled_write_P(PSTR("     "), false);
    oled_write_P(PSTR("H   A"), false);
    oled_write_P(PSTR("     "), false);
    oled_write_P(PSTR("A   C"), false);
    oled_write_P(PSTR("     "), false);
    oled_write_P(PSTR("P   K"), false);
    oled_write_P(PSTR("     "), false);
    oled_write_P(PSTR("P   I"), false);
    oled_write_P(PSTR("     "), false);
    oled_write_P(PSTR("Y   N"), false);
    oled_write_P(PSTR("     "), false);
    oled_write_P(PSTR("    G"), false);
  }
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
      tap_code(KC_PGDN);
    } else {
      tap_code(KC_PGUP);
    }
  }
  return true;
}

#endif
