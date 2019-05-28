#include QMK_KEYBOARD_H
#include "version.h"
#include "tap_dance_setup.c"
#include "tap_dances.c"

#define BASE 0 // default layer
#define SYMB 1 // symbols
#define EXTN 2 // extend
#define MIRR 3 // mirror

#define ___ KC_TRNS

/* Custom Key Codes */
enum custom_keycodes {
  EPRM = SAFE_RANGE,
  VRSN,
  RGB_SLD,
  LT_1_LCBR,
  LT_1_RCBR,
  KC_ARROW,
  DELETE_LINE_B,
  DELETE_LINE_F,
  DUP_LINE,
  SELECT_LINE,
  CREATE_LINK,
  SURROUND_QUOTES
};

/* Unused Tap Dance Declarations */
enum {
  TD_LBCR = 0,
  TD_RBCR = 1
};

qk_tap_dance_action_t tap_dance_actions[] = {
  [TD_LBCR]     = ACTION_TAP_DANCE_DOUBLE(KC_LBRC, KC_LCBR),
  [TD_RBCR]     = ACTION_TAP_DANCE_DOUBLE(KC_RBRC, KC_RCBR)
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * | ESC    |   1  |   2  |   3  |   4  |   5  |      |           |      |   6  |   7  |   8  |   9  |   0  |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | TAB    |   Q  |   W  |   F  |   P  |   B  |      |           |      |   J  |   L  |   U  |   Y  |   :  | BCKSP  |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | LShift |   A  |   R  |   S  |   T  |   G  |------|           |------|   M  |   N  |   E  |   I  |   O  | RShift |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | MO(1)  |   Z  |   X  |   C  |   D  |   V  |      |           |      |   K  |   H  |   ,  |   .  |   /  | MO(1)  |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |  GUI |  '"  | MO(3)| RALT |                                       | LEFT | DOWN |  UP  | RIGHT|      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,---------------.
 *                                        |      |      |       |      |        |
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      |      |       |      |        |      |
 *                                 | RALT | Ctrl |------|       |------|  GUI   | Space|
 *                                 |      |      | ESC  |       | ESC  |        |      |
 *                                 `--------------------'       `----------------------'
 */
  [BASE] = LAYOUT_ergodox(
      // Left Side
      KC_ESCAPE,      KC_1,      KC_2,       KC_3,  KC_4,     KC_5,  ___,
      KC_TAB,         KC_Q,      KC_W,       KC_F,  KC_P,     KC_B,  ___,
      KC_LSPO,        KC_A,      KC_R,       KC_S,  KC_T,     KC_G,
      LT(1, KC_QUOTE), KC_Z,      KC_X,       KC_C,  KC_D,     KC_V,  TD(TD_LBCR),
      KC_BSPACE,      KC_LGUI,   KC_QUOTE,   ___,   MO(3),
      ___,            ___,
      MO(3),
      LT(2, KC_BSPACE), MT(MOD_LCTL, KC_ENTER),  MT(MOD_LALT, KC_ESCAPE),
      // Right Side
      ___,            KC_6,          KC_7,          KC_8,      KC_9,            KC_0,              KC_ENTER,
      ___,            KC_J,          KC_L,          KC_U,      KC_Y,            KC_SCOLON,         KC_BSPACE,
      KC_M,           KC_N,          KC_E,          KC_I,      KC_O,            KC_RSPC,
      TD(TD_RBCR),    KC_K,          KC_H,          KC_COMMA,  KC_DOT,          KC_SLASH,          LT(1, KC_QUOTE),
      KC_LEFT,        KC_DOWN,       KC_UP,         KC_RIGHT,  ___,
      ___,            ___,
      MO(3),
      MT(MOD_RALT, KC_ESCAPE),       KC_RGUI,       KC_SPACE
    ),

/* Keymap 1: Symbol layer */
  [SYMB] = LAYOUT_ergodox(
    // Left Side
    ___,        ___,       ___,        ___,          ___,          ___,        ___,
    KC_TILD,    KC_EXLM,   KC_AT,      KC_HASH,      KC_DLR,       KC_PERC,    ___,
    ___,        KC_PLUS,   KC_EQUAL,   KC_MINUS,     KC_UNDS,      KC_RABK,    ___,
    ___,        ___,       KC_ARROW,   ___,          ___,          ___,        ___,
    ___,        KC_QUOTE,  ___,        ___,
    ___,        ___,
    ___,
    ___,        ___,  ___,

    // Right Side
    ___,        ___,       ___,        ___,          ___,          ___,        ___,  ___,
    KC_CIRC,    KC_AMPR,   KC_ASTR,    KC_LPRN,      KC_RPRN,      ___,
    ___,        KC_LCBR,   KC_RCBR,    ___,          ___,          ___,
    ___,        ___,       KC_LBRC,    KC_RBRC,      ___,          KC_BSLASH,    ___,
    ___,        ___,       ___,        ___,          ___,
    ___,        ___,
    ___,
    ___,        ___,       ___
  ),

/* Keymap 2: Extend layer */
  [EXTN] = LAYOUT_ergodox(
    // Left Side
    ___,           ___,         ___,              ___,         ___,        ___,         ___,
    LALT(KC_TAB),  ___,         ___,              DELETE_LINE_B,        ___,         DELETE_LINE_F, ___,
    ___,           KC_LGUI,     KC_LCTRL,         KC_LSHIFT,   KC_LALT,    ___,
    ___,           LCTL(KC_Z),  LCTL(KC_X),       LCTL(KC_C),  DUP_LINE, LCTL(KC_V),  ___,
    ___,           ___,         ___,              ___,         ___,
    ___,           ___,
    ___,
    ___,           KC_LCTRL,    ___,

    // Right Side    
    ___,           ___,         ___,              KC_ESCAPE,   ___,        ___,         ___,
    ___,           KC_PGUP,     KC_HOME,          KC_UP,       KC_END,     SELECT_LINE,  ___,
                   KC_PGDOWN,   KC_LEFT,          KC_DOWN,     KC_RIGHT,   KC_ENTER,    ___,
    ___,           CREATE_LINK, KC_BSPACE,        KC_DELETE,   ___,        ___,         SURROUND_QUOTES,
    ___,           ___,         ___,              ___,         ___,
    ___,           ___,
    ___,
    ___,           ___,         ___),

/* Keymap 3: Mirror layer */
  [MIRR] = LAYOUT_ergodox(
    // Left Side
    ___,   VRSN,        ___,     ___,       ___,   ___,   ___,
    ___,   KC_SCOLON,  KC_Y,    KC_U,      KC_L,  KC_J,  ___,
    ___,   KC_O,       KC_I,    KC_E,      KC_N,  KC_M,
    ___,   KC_SLASH,   KC_DOT,  KC_COMMA,  KC_H,  KC_K,  ___,
    ___,   ___,        ___,     ___,       ___,
    ___,   ___,
    ___,
    ___,   ___,   ___,

    // Right Side
    ___,   ___,        ___,     ___,       ___,   ___,   ___,
    ___,   KC_B,       KC_P,    KC_F,      KC_W,  KC_Q,  ___,
    KC_G,  KC_T,       KC_S,    KC_R,      KC_A,  ___,
    ___,   KC_V,       KC_D,    KC_C,      KC_X,  KC_Z,  ___,
    ___,   ___,        ___,     ___,       ___,
    ___,   ___,
    ___,
    ___,   ___,        ___
  ),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    switch (keycode) {
      case EPRM:
        eeconfig_init();
        return false;
      case VRSN:
        SEND_STRING(QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
        return false;
      #ifdef RGBLIGHT_ENABLE
      case RGB_SLD:
        rgblight_mode(1);
        return false;
      #endif
      case KC_ARROW:
        SEND_STRING("->");
        return false;
      case SELECT_LINE:
        SEND_STRING(SS_TAP(X_END) SS_LSFT(SS_TAP(X_HOME)));
        return false;
      case DELETE_LINE_B:
        SEND_STRING(SS_LSFT(SS_TAP(X_HOME)) SS_TAP(X_BSPACE));
        return false;
      case DELETE_LINE_F:
        SEND_STRING(SS_LSFT(SS_TAP(X_END)) SS_TAP(X_BSPACE));
        return false;
      case DUP_LINE:
        SEND_STRING(SS_TAP(X_END) SS_LSFT(SS_TAP(X_HOME)) SS_LCTRL("c") SS_TAP(X_END));
        _delay_ms(50);
        SEND_STRING(SS_TAP(X_ENTER) SS_LCTRL("v"));
        return false;       
      case CREATE_LINK:
        SEND_STRING(SS_LCTRL("c"));
        _delay_ms(100);
        SEND_STRING(SS_LCTRL("k"));
        _delay_ms(100);
        SEND_STRING(SS_LCTRL("v") SS_TAP(X_ENTER));
        return false;
      case SURROUND_QUOTES:
        SEND_STRING(SS_LCTRL("x"));
        _delay_ms(50);
        SEND_STRING("\"");
        SEND_STRING(SS_LCTRL("v"));
        SEND_STRING("\"");
    }
  }
  return true;
}
