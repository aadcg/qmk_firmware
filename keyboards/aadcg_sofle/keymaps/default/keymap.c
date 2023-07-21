#include QMK_KEYBOARD_H
//
/* Distinguish between left/right Control, Meta, Shift, Super? */
/* See https://github.com/manna-harbour/miryoku/discussions/221#discussioncomment-6269153. */

/* Add C-M on hold for W and O keys? */
/* Add alpha layer without tap/hold keys */

/* Try AltGr as a one shot modifier */

/* TODO C-M-F7 is hard to type */

#define L1_BSPC LT(1,KC_BSPC)   // Tap for ⌫     ; hold for L1
#define L2_H    LT(2,KC_H)      // Tap for H     ; hold for L2
#define L3_TAB  LT(3,KC_TAB)    // Tap for TAB   ; hold for L3
/* this is not possible it seems... */
/* #define L3_LPRN LT(3,KC_LPRN)   // Tap for LPRN  ; hold for L3 */
#define C_D     CTL_T(KC_D)     // Tap for D     ; hold for Control
#define C_K     CTL_T(KC_K)     // Tap for K     ; hold for Control
#define C_SPC   CTL_T(KC_SPC)   // Tap for SPC   ; hold for Control
#define M_S     ALT_T(KC_S)     // Tap for S     ; hold for Meta
#define M_L     ALT_T(KC_L)     // Tap for L     ; hold for Meta
#define SFT_F   SFT_T(KC_F)     // Tap for F     ; hold for Shift
#define SFT_J   RSFT_T(KC_J)    // Tap for J     ; hold for Shift
#define S_A     GUI_T(KC_A)     // Tap for A     ; hold for Super
#define S_SCLN  GUI_T(KC_SCLN)  // Tap for ;     ; hold for Super
#define RA_Z    ALGR_T(KC_Z)    // Tap for Z     ; hold for AltGr
#define RA_SLSH ALGR_T(KC_SLSH) // Tap for /     ; hold for AltGr
/* Deprecate */
#define COMM    LT(0,KC_COMM)   // Tap for ,     ; hold for M-,
/* Deprecate */
#define KC__DOT LT(0,KC_DOT)    // Tap for .     ; hold for M-.
#define KC__V   LT(0,KC_V)      // Tap for V     ; hold for M-x
#define KC__X   LT(0,KC_X)      // Tap for X     ; hold for C-x
#define KC__C   LT(0,KC_C)      // Tap for C     ; hold for C-c
/* Idea: Map to Y */
#define KC__0   LT(0,KC_0)      // Tap for 0     ; hold for C-x 0
/* Idea: Map to U */
#define KC__1   LT(0,KC_1)      // Tap for 1     ; hold for C-x 1
/* Idea: Map to H */
#define KC__2   LT(0,KC_2)      // Tap for 2     ; hold for C-x 2
/* Idea: Map to M */
#define KC__3   LT(0,KC_3)      // Tap for 3     ; hold for C-x 3
/* Idea: Map to N */
#define KC__4   LT(0,KC_4)      // Tap for 4     ; hold for C-x 4
#define KC__B   LT(0,KC_B)      // Tap for B     ; hold for C-x b
#define KC__P   LT(0,KC_P)      // Tap for P     ; hold for C-x p
#define KC__G   LT(0,KC_G)      // Tap for G     ; hold for C-x g

#define CUT   S(KC_DEL)
#define COPY  C(KC_INS)
#define PASTE S(KC_INS)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[0] = LAYOUT(
  KC_ESC,  KC_9,    KC_8,    KC_7,    KC_6,    KC_5,                      KC__0,   KC__1,   KC__2,   KC__3,   KC__4,   KC_BSLS,
  KC_GRV,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                      KC_Y,    KC_U,    KC_I,    KC_O,    KC__P,   KC_LBRC,
  KC_MINS, S_A,     M_S,     C_D,     SFT_F,   KC__G,                     L2_H,    SFT_J,   C_K,     M_L,     S_SCLN,  KC_QUOT,
  KC_EQL,  RA_Z,    KC__X,   KC__C,   KC__V,   KC__B,   KC_MUTE, KC_PSCR, KC_N,    KC_M,    COMM,    KC__DOT, RA_SLSH, KC_RBRC,
                    XXXXXXX, KC_ESC,  KC_LPRN, C_SPC,   L3_TAB,  KC_ENT,  L1_BSPC, KC_DEL,  KC_BSLS, XXXXXXX
),

/* Refactor to left, up, down, right // home, pgup, pgdn, end? */
[1] = LAYOUT(
  KC_F12,  KC_F11,  KC_F10,  KC_F9,   KC_F8,   KC_F7,                     KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,
  QK_BOOT, KC_PGUP, KC_HOME, KC_UP,   KC_END,  XXXXXXX,                   XXXXXXX, QK_AREP, QK_REP,  XXXXXXX, XXXXXXX, QK_BOOT,
  XXXXXXX, KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, KC_BSLS,                   XXXXXXX, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI, DF(3),
  XXXXXXX, KC_UNDO, CUT,     COPY,    PASTE,   KC_AGIN, _______, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_ALGR, XXXXXXX,
                    XXXXXXX, XXXXXXX, KC_DEL,  _______, KC_BSPC, _______, _______, _______, _______, _______
),

[2] = LAYOUT(
  _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
  _______, _______, _______, KC_MS_U, _______, _______,                   _______, _______, _______, _______, _______, _______,
  _______, _______, KC_MS_L, KC_MS_D, KC_MS_R, _______,                   _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                    _______, _______, KC_BTN3, KC_BTN1, KC_BTN2, _______, _______, _______, _______, _______
),

[3] = LAYOUT(
  KC_F12,  KC_F11,  KC_F10,  KC_F9,   KC_F8,   KC_F7,                     KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,
  QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, KC_7,    KC_8,    KC_9,    XXXXXXX, QK_BOOT,
  XXXXXXX, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, MO(4),                     XXXXXXX, KC__1,   KC__2,   KC__3,   XXXXXXX, XXXXXXX,
  XXXXXXX, KC_UNDO, CUT,     COPY,    PASTE,   KC_AGIN, _______, _______, XXXXXXX, KC__4,   KC_5,    KC_6,    XXXXXXX, XXXXXXX,
                    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC__0,   XXXXXXX, XXXXXXX, XXXXXXX
),

[4] = LAYOUT(
  KC_F12,  KC_F11,  KC_F10,  KC_F9,   KC_F8,   KC_F7,                     KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,
  QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, KC_F7,   KC_F8,   KC_F9,   KC_F10,  QK_BOOT,
  XXXXXXX, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, _______,                   XXXXXXX, KC_F1,   KC_F2,   KC_F3,   KC_F11,  XXXXXXX,
  XXXXXXX, KC_UNDO, CUT,     COPY,    PASTE,   KC_AGIN, _______, _______, XXXXXXX, KC_F4,   KC_F5,   KC_F6,   KC_F12,  XXXXXXX,
                    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
)

/* Game layer */
/* [5] = LAYOUT( */
/*   KC_GRV,  KC_4,    KC_3,    KC_2,    KC_1,    KC_0,                      KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_GRV, */
/*   KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                      KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC, */
/*   KC_TAB,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                      KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, */
/*   KC_LCTL, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_MUTE, KC_PSCR, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, */
/*                     TO(0),   KC_LALT, KC_SPC,  KC_LSFT, KC_ENT,  MO(1),   KC_ENT,  KC_RCTL, KC_RALT, KC_RGUI */
/* ) */

/* [insert-number] = LAYOUT( */
/*   KC_F12,  KC_F11,  KC_F10,  KC_F9,   KC_F8,   KC_F7,                     KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6, */
/*   QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, KC_7,    KC_8,    KC_9,    XXXXXXX, QK_BOOT, */
/*   XXXXXXX, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, XXXXXXX,                   XXXXXXX, KC_1,    KC_2,    KC_3,    XXXXXXX, XXXXXXX, */
/*   XXXXXXX, KC_UNDO, CUT,     COPY,    PASTE,   KC_AGIN, _______, _______, XXXXXXX, KC_4,    KC_5,    KC_6,    XXXXXXX, XXXXXXX, */
/*                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_0,    XXXXXXX, XXXXXXX, XXXXXXX */
/* ) */
};

// Initialize variable holding the binary
// representation of active modifiers.
uint8_t mod_state;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  // Store the current modifier state in the variable for later reference
  mod_state = get_mods();
  switch (keycode) {
  case LT(0,KC_X):
    if (record->tap.count && record->event.pressed) {
      tap_code16(KC_X);    // Intercept tap function to send x
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
  case LT(0,KC_V):
    if (record->tap.count && record->event.pressed) {
      tap_code16(KC_V);       // Intercept tap function to send v
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
  case LT(0,KC_B):
    if (record->tap.count && record->event.pressed) {
      tap_code16(KC_B);    // Intercept tap function to send b
    } else if (record->event.pressed) {
      tap_code16(C(KC_X)); // Intercept hold function to send C-x
      tap_code16(KC_B);    // Intercept hold function to send b
    }
    return false;
  case LT(0,KC_P):
    if (record->tap.count && record->event.pressed) {
      tap_code16(KC_P);    // Intercept tap function to send p
    } else if (record->event.pressed) {
      tap_code16(C(KC_X)); // Intercept hold function to send C-x
      tap_code16(KC_P);    // Intercept hold function to send p
    }
    return false;
  case LT(0,KC_G):
    if (record->tap.count && record->event.pressed) {
      tap_code16(KC_G);    // Intercept tap function to send g
    } else if (record->event.pressed) {
      tap_code16(C(KC_X)); // Intercept hold function to send C-x
      tap_code16(KC_G);    // Intercept hold function to send g
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
    oled_write_P(PSTR("Base"), false);
    break;
  case 1:
    oled_write_P(PSTR("Nav"), false);
    break;
  case 2:
    oled_write_P(PSTR("Rat"), false);
    break;
  case 3:
    oled_write_P(PSTR("Num"), false);
    break;
  case 4:
    oled_write_P(PSTR("Fn"), false);
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
/* TODO bind encoder to `KC_MS_WH_UP`/`KC_MS_WH_DOWN` */
/* mouse wheel */
bool encoder_update_user(uint8_t index, bool clockwise) {
  /* if (!encoder_update_user(index, clockwise)) { return false; } */
  if (index == 0) {
    if (clockwise) {
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

#ifdef COMBO_ENABLE
enum combos {
  BC,
  PPL,
  THINK
};

/* TODO try to use combos with thumb keys to achieve symbols/numbers */
const uint16_t PROGMEM combo_esc[]   = {KC_Q, KC_W, COMBO_END};
const uint16_t PROGMEM combo_bc[]    = {KC__B, KC__C, COMBO_END};
const uint16_t PROGMEM combo_ppl[]   = {KC__P, S_SCLN, COMBO_END};
const uint16_t PROGMEM combo_think[] = {KC_I, C_K, COMBO_END};

combo_t key_combos[] = {
  COMBO(combo_esc, KC_ESC),
  [BC]    = COMBO_ACTION(combo_bc),
  [PPL]   = COMBO_ACTION(combo_ppl),
  [THINK] = COMBO_ACTION(combo_think),
};

void process_combo_event(uint16_t combo_index, bool pressed) {
  switch(combo_index) {
  case BC:
    if (pressed) {
      SEND_STRING("because");
    }
    break;
  case PPL:
    if (pressed) {
      SEND_STRING("people");
    }
    break;
  case THINK:
    if (pressed) {
      SEND_STRING("think");
    }
    break;
  }
}
#endif
