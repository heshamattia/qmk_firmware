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
  KC_OC_PARENS,
  DELETE_LINE_B,
  DELETE_LINE_F,
  DUP_LINE,
  SELECT_LINE,
  CREATE_LINK,
  SURROUND_QUOTES
};

/* Unused Tap Dance Declarations */
enum {
  TD_QUOTES = 0,
};

qk_tap_dance_action_t tap_dance_actions[] = {
  [TD_QUOTES]     = ACTION_TAP_DANCE_DOUBLE(KC_QUOTE, KC_DQUO),
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
 *KC_F1
                                 | RALT | Ctrl |------|       |------|  GUI   | Space|
 *                                 |      |      | ESC  |       | ESC  |        |      |
 *                                 `--------------------'       `----------------------'
 */
  [BASE] = LAYOUT_ergodox(
      // Left Side
      KC_GESC,        KC_1,      KC_2,       KC_3,     KC_4,     KC_5,  KC_6,
      KC_TAB,         KC_Q,      KC_W,       KC_F,     KC_P,     KC_B,  KC_F1,
      KC_LSFT,        KC_A,      KC_R,       KC_S,     KC_T,     KC_G,
      MO(1),          KC_Z,      KC_X,       KC_C,     KC_D,     KC_V,  KC_F2,
      KC_GRAVE,       KC_LGUI,   KC_QUOTE,   KC_LCTL,  LT(3, KC_ESCAPE),
      KC_BTN3,        ___,
      MO(3),
      MT(MOD_LGUI, KC_BSPACE), LT(2, KC_ENTER), MT(MOD_LALT, KC_ESCAPE),
      // Right Side
      KC_5,           KC_6,          KC_7,          KC_8,      KC_9,            KC_0,              KC_ENTER,
      KC_F4,          KC_J,          KC_L,          KC_U,      KC_Y,            KC_SCOLON,         KC_BSPACE,
                      KC_M,          KC_N,          KC_E,      KC_I,            KC_O,              KC_RSFT,
      KC_F3,          KC_K,          KC_H,          KC_COMMA,  KC_DOT,          KC_SLASH,          MO(1),
      KC_LEFT,        KC_DOWN,       KC_UP,         KC_RIGHT,  ___,
      KC_LBRC,        KC_RBRC,
      MO(3),
      MT(MOD_RALT, KC_ESCAPE),       KC_RCTL,       KC_SPACE
    ),

/* Keymap 1: Symbol layer */
  [SYMB] = LAYOUT_ergodox(
    // Left Side
    KC_GESC,    MEH(KC_1), MEH(KC_2),  MEH(KC_3),    MEH(KC_4),    MEH(KC_5),  MEH(KC_6),
    KC_TAB,     KC_EXLM,   KC_AT,      KC_HASH,      KC_DLR,       KC_PERC,    MEH(KC_F1),
    ___,        KC_PLUS,   KC_EQUAL,   KC_MINUS,     KC_UNDS,      KC_DQUO,
    ___,        ___,       ___,        KC_ARROW,     ___,          KC_QUOTE,   MEH(KC_F2),
    ___,        KC_QUOTE,  ___,        ___,          ___,
    ___,        ___,
    ___,
    ___,        ___,  ___,
    // Right Side
    MEH(KC_5), MEH(KC_6),  MEH(KC_7),  MEH(KC_8),    MEH(KC_9),    MEH(KC_0),    ___,
    MEH(KC_F4), KC_CIRC,   KC_AMPR,    KC_ASTR,      KC_LPRN,      KC_RPRN,      ___,
                KC_DQUO,   KC_LCBR,    KC_RCBR,      KC_PIPE,      KC_OC_PARENS, ___,
    MEH(KC_F3), KC_GRAVE,  KC_LBRC,    KC_RBRC,      ___,          KC_BSLASH,    ___,
    ___,        ___,       ___,        ___,          ___,
    ___,        ___,
    ___,
    ___,        ___,       ___
  ),

/* Keymap 2: Extend layer */
  [EXTN] = LAYOUT_ergodox(
    // Left Side
    LGUI(KC_GRV),  HYPR(KC_1),     HYPR(KC_2),          HYPR(KC_3),              HYPR(KC_4),     HYPR(KC_5), HYPR(KC_6),
    LALT(KC_ESC),  	   HYPR(KC_Q),     HYPR(KC_W),          HYPR(KC_F),              HYPR(KC_P),     HYPR(KC_B), HYPR(KC_F1),
    KC_LSFT,       KC_LGUI,        KC_LALT,             KC_LSHIFT,               KC_LCTRL,       ___,
    ___,           G(KC_Z),        G(KC_X),             G(KC_C),                 G(KC_D),        G(KC_V),  HYPR(KC_F2),
    ___,           ___,         ___,              ___,         ___,
    ___,           ___,
    ___,
    ___,           ___,    ___,

    // Right Side
    HYPR(KC_5),    HYPR(KC_6),  HYPR(KC_7),       HYPR(KC_8),  HYPR(KC_9), HYPR(KC_0),  ___,
    HYPR(KC_F4),   KC_PGUP,     KC_HOME,          KC_UP,       KC_END,     SELECT_LINE, LALT(KC_BSPACE),
                   KC_PGDOWN,   KC_LEFT,          KC_DOWN,     KC_RIGHT,   KC_ENTER,    ___,
    HYPR(KC_F3),   CREATE_LINK, KC_BSPACE,        KC_DELETE,   ___,        ___,         SURROUND_QUOTES,
    ___,           ___,         ___,              ___,         ___,
    ___,           ___,
    ___,
    ___,           ___,         KC_UNDS
  ),

/* Keymap 3: Mirror layer */
  [MIRR] = LAYOUT_ergodox(
    // Left Side
    KC_GESC, KC_0,      KC_9,       KC_8,     KC_7,     KC_6,  ___,
    ___,   KC_SCOLON,  KC_Y,    KC_U,      KC_L,  KC_J,  ___,
    ___,   KC_O,       KC_I,    KC_E,      KC_N,  KC_M,
    ___,   KC_SLASH,   KC_DOT,  KC_COMMA,  KC_H,  KC_K,  ___,
    ___,   ___,        ___,     ___,       ___,
    ___,   ___,
    ___,
    ___,   ___,   ___,

    // Right Side
    ___,   ___,        ___,     ___,       ___,   ___,   ___,
    ___,   ___,       KC_BTN1,    KC_MS_UP,      KC_BTN2,  KC_MS_WH_DOWN,  ___,
           ___,       KC_MS_LEFT,    KC_MS_DOWN,      KC_MS_RIGHT,  KC_MS_WH_UP,  ___,
    ___,   ___,       KC_MS_WH_LEFT,    ___,      KC_MS_WH_RIGHT,  ___,  ___,
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
      case KC_OC_PARENS:
        SEND_STRING("()");
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
        SEND_STRING(SS_TAP(X_ENTER) SS_LGUI("v"));
        return false;       
      case CREATE_LINK:
        SEND_STRING(SS_LGUI("c"));
        _delay_ms(100);
        SEND_STRING(SS_LGUI("k"));
        _delay_ms(100);
        SEND_STRING(SS_LGUI("v") SS_TAP(X_ENTER));
        return false;
      case SURROUND_QUOTES:
        SEND_STRING(SS_LGUI("x"));
        _delay_ms(50);
        SEND_STRING("\"");
        SEND_STRING(SS_LGUI("v"));
        SEND_STRING("\"");
        return false;
    }
  }
  return true;
}
