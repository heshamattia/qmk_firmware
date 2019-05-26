#include QMK_KEYBOARD_H
#include "version.h"

#define BASE 0 // default layer
#define SYMB 1 // symbols
#define EXTN 2 // extend
#define MIRR 3 // mirror

#define ___ KC_TRNS

enum custom_keycodes {
  EPRM = SAFE_RANGE,
  VRSN,
  RGB_SLD,
  DELETE_LINE
};

//Tap Dance Declarations
enum {
  TD_LBRC = 0,
  TD_RBRC = 1
};

//Tap Dance Definitions
qk_tap_dance_action_t tap_dance_actions[] = {
  //Tap once for Esc, twice for Caps Lock
  [TD_LBRC] = ACTION_TAP_DANCE_DOUBLE(KC_LCBR, KC_LBRC),
  [TD_RBRC] = ACTION_TAP_DANCE_DOUBLE(KC_RCBR, KC_RBRC)
// Other declarations would go here, separated by commas, if you have them
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * | ESC    |   1  |   2  |   3  |   4  |   5  |      |           |      |   6  |   7  |   8  |   9  |   0  |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | TAB    |   Q  |   W  |   F  |   P  |   B  |      |           |      |   J  |   L  |   U  |   Y  |   :  | BCKSP  |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | RShift |   A  |   R  |   S  |   T  |   G  |------|           |------|   M  |   N  |   E  |   I  |   O  | RShift |
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
      KC_TAB,         KC_Q,      KC_W,       KC_F,  KC_P,     KC_B,  TD(TD_LBRC),
      OSM(MOD_RSFT),  KC_A,      KC_R,       KC_S,  KC_T,     KC_G,
      MO(1),          KC_Z,      KC_X,       KC_C,  KC_D,     KC_V,  KC_QUOTE,
      KC_BSPACE,      KC_LGUI,   KC_QUOTE,   ___,   MO(3),
      ___,            ___,
      MO(3),
      LT(2, KC_BSPACE),   MT(MOD_LCTL, KC_ENTER),  MT(MOD_LALT, KC_ESCAPE),
      // Right Side
      ___,            KC_6,          KC_7,          KC_8,      KC_9,            KC_0,              KC_ENTER,
      TD(TD_RBRC),    KC_J,          KC_L,          KC_U,      KC_Y,            KC_SCOLON,         KC_BSPACE,
      KC_M,           KC_N,          KC_E,          KC_I,      KC_O,            OSM(MOD_LSFT),
      KC_BSLASH,      KC_K,          KC_H,          KC_COMMA,  KC_DOT,          KC_SLASH,  MO(1),
      ___,            KC_LEFT,       KC_DOWN,       KC_UP,     KC_RIGHT,
      ___,            ___,
      MO(3),
      MT(MOD_RALT, KC_ESCAPE),      OSM(MOD_LSFT),       KC_SPACE
    ),

/* Keymap 1: Symbol layer */
  [SYMB] = LAYOUT_ergodox(
    // Left Side
    KC_ESCAPE,  ___,       ___,        ___,          ___,          ___,        ___,
    KC_TILD,    KC_EXLM,   KC_AT,      KC_HASH,      KC_DLR,       KC_PERC,    ___,
    KC_LSHIFT,  KC_PLUS,   KC_EQUAL,   KC_MINUS,     KC_UNDS,      KC_RABK,    ___,
    ___,        ___,       ___,        ___,          ___,          ___,        ___,
    KC_LGUI,    KC_QUOTE,  ___,        KC_ENTER,
    ___,        ___,
    ___,
    KC_LALT,    KC_LCTRL,  KC_ESCAPE,

    // Right Side
    ___,        ___,       ___,        ___,          ___,          ___,        ___,  KC_ENTER,
    KC_CIRC,    KC_AMPR,   KC_ASTR,    KC_LPRN,      KC_RPRN,      KC_BSPACE,
    KC_GRAVE,   KC_DQUO,   KC_QUOTE,   KC_LCBR,      KC_RCBR,      KC_RSHIFT,
    ___,        ___,       KC_PIPE,    KC_LBRACKET,  KC_RBRACKET,  KC_BSLASH,  ___,
    KC_RALT,    ___,       KC_BSLASH,  KC_RGUI,      ___,
    ___,        ___,
    ___,
    KC_ESCAPE,  KC_RGUI,   KC_ENTER
  ),

/* Keymap 2: Extend layer */
  [EXTN] = LAYOUT_ergodox(
    ___,           ___,         ___,              ___,         ___,        ___,         ___,
    LALT(KC_TAB),  ___,         ___,              ___,         ___,        ___,         ___,
    KC_LSHIFT,     KC_LGUI,     KC_LALT,          KC_LSHIFT,   KC_LCTRL,   ___,
    ___,           LCTL(KC_Z),  LCTL(KC_X),       LCTL(KC_C),  ___,        LCTL(KC_V),  ___,
    ___,           ___,         ___,              ___,         ___,
    ___,           ___,
    ___,
    ___,           KC_LCTRL,    ___,
    ___,           ___,         ___,              KC_ESCAPE,   ___,        ___,         ___,
    ___,           KC_PGUP,     KC_HOME,          KC_UP,       KC_END,     KC_BSPACE,   KC_ENTER,
    KC_PGDOWN,     KC_LEFT,     KC_DOWN,          KC_RIGHT,    KC_DELETE,  KC_RSHIFT,
    ___,           ___,         DELETE_LINE,      KC_ENTER,    ___,        ___,         ___,
    ___,           ___,         ___,              ___,         ___,
    ___,           ___,
    ___,
    ___,           ___,         LCTL(KC_SPACE)),

/* Keymap 3: Mirror layer */
  [MIRR] = LAYOUT_ergodox(
    ___,   VRSN,        ___,     ___,       ___,   ___,   ___,
    ___,   KC_SCOLON,  KC_Y,    KC_U,      KC_L,  KC_J,  ___,
    ___,   KC_O,       KC_I,    KC_E,      KC_N,  KC_M,
    ___,   KC_SLASH,   KC_DOT,  KC_COMMA,  KC_H,  KC_K,  ___,
    ___,   ___,        ___,     ___,       ___,
    ___,   ___,
    ___,
    ___,   KC_LCTRL,   ___,
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
      case DELETE_LINE:
        SEND_STRING(SS_TAP(X_END) SS_LSFT(SS_TAP(X_HOME)) SS_TAP(X_BSPACE) SS_TAP(X_BSPACE));
        return false;
    }
  }
  return true;
}
