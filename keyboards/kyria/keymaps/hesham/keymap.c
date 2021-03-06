/* Copyright 2019 Thomas Baart <thomas@splitkb.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H

#define ___ KC_TRNS

enum layers {
    _BASE = 0,
    _SHIFT,
    _SYMB,
    _EXTN,
    _MEDIA,
    _MIRR
};

enum custom_keycodes {
  EPRM = SAFE_RANGE,
  KC_ARROW,
};

//Tap Dance Declarations
enum {
  TD_COMMA_TAB = 0
};

//Tap Dance Definitions
qk_tap_dance_action_t tap_dance_actions[] = {
  //Tap once for Esc, twice for Caps Lock
  [TD_COMMA_TAB]  = ACTION_TAP_DANCE_DOUBLE(KC_COMMA, KC_TAB),
// Other declarations would go here, separated by commas, if you have them
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* 
 * Base Layer: QWERTY
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |   Q  |   W  |   F  |   P  |   B  |                              |   J  |   L  |   U  |   Y  |   :  |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |   A  |   R  |  S   |   T  |   G  |                              |   M  |   N  |   E  |   I  |   O  |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |   Z  |   X  |   C  |   D  |   V  |LShift|LShift|  |LShift|LShift|   K  |   H  |   ,  |   .  |   /  |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        | GUI  | Del  | Enter| Space| Esc  |  | Enter| Space| Tab  | Bksp | AltGr|
 *                        |      |      | Alt  | Lower| Raise|  | Lower| Raise|      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_BASE] = LAYOUT(
      KC_TAB,  KC_Q,   KC_W,   KC_F,   KC_P,   KC_B,                                    KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCOLON,    KC_SLASH,
      KC_QUOTE,KC_A,   KC_R,   KC_S,   KC_T,   KC_G,                                    KC_M,    KC_N,    KC_E,    KC_I,    KC_O,         KC_MINS,
      KC_GRV,  KC_Z,   KC_X,   KC_C,   KC_D,   KC_V,   MO(_MIRR),   MO(_SHIFT), MO(_SHIFT), MO(_MIRR), KC_K, KC_H,    TD(TD_COMMA_TAB), KC_DOT,  KC_UNDS,   KC_QUES,
              KC_LEFT, LALT_T(KC_RIGHT),  LT(_EXTN, KC_BSPC), LT(_SYMB, KC_ESC), LGUI_T(KC_ENTER), LCTL_T(KC_ENTER),   OSL(_SHIFT), KC_SPACE, LALT_T(KC_DOWN), KC_UP
    ),
/* 
 * Shift Layer: QWERTY
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |   Q  |   W  |   F  |   P  |   B  |                              |   J  |   L  |   U  |   Y  |   :  |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |   A  |   R  |  S   |   T  |   G  |                              |   M  |   N  |   E  |   I  |   O  |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |   Z  |   X  |   C  |   D  |   V  |LShift|LShift|  |LShift|LShift|   K  |   H  |   ,  |   .  |   /  |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        | GUI  | Del  | Enter| Space| Esc  |  | Enter| Space| Tab  | Bksp | AltGr|
 *                        |      |      | Alt  | Lower| Raise|  | Lower| Raise|      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_SHIFT] = LAYOUT(
      LSFT(KC_TAB),LSFT(KC_Q),LSFT(KC_W),LSFT(KC_F),LSFT(KC_P),LSFT(KC_B),                         LSFT(KC_J),    LSFT(KC_L),    LSFT(KC_U),    LSFT(KC_Y),   LSFT(KC_SCOLON),  KC_PIPE,
      KC_DQUO,     LSFT(KC_A),LSFT(KC_R),LSFT(KC_S),LSFT(KC_T),LSFT(KC_G),                         LSFT(KC_M),    LSFT(KC_N),    LSFT(KC_E),    LSFT(KC_I),   LSFT(KC_O),       KC_PLUS,
      KC_TILD,     LSFT(KC_Z),LSFT(KC_X),LSFT(KC_C),LSFT(KC_D),LSFT(KC_V),   ___,   ___, ___, ___, LSFT(KC_K),    LSFT(KC_H),    LSFT(KC_COMMA),LSFT(KC_DOT), LSFT(KC_UNDS),    ___,
                                 _______, _______, _______, LSFT(KC_ESC), ___, ___, ___, LSFT(KC_SPACE), _______, _______
    ),
/*
 * Lower Layer: Symbols
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |  !   |  @   |  {   |  }   |  |   |                              |      |      |      |      |      |  | \   |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |  #   |  $   |  (   |  )   |  `   |                              |   +  |  -   |  /   |  *   |  %   |  ' "   |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |  %   |  ^   |  [   |  ]   |  ~   |      |      |  |      |      |   &  |  =   |  ,   |  .   |  / ? | - _    |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |  ;   |  =   |  |  =   |  ;   |      |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_SYMB] = LAYOUT(
      ___, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                     _______,   KC_LPRN, KC_RPRN, _______, _______, KC_BSLASH,
      KC_DQUO, _______, _______, _______, _______,  _______,                _______,   KC_LCBR, KC_RCBR, KC_QUOTE,  KC_DQUO, KC_PLUS,
      KC_TILD, KC_CIRC, KC_AMPR, KC_ASTR, _______, _______, ___, ___, ___, ___, _______,   KC_LBRC, KC_RBRC, KC_ARROW,  ___, KC_EQL,
                                 _______, _______, _______, ___, ___, ___, ___, _______, _______, _______
    ),
/*
 * Raise Layer: Number keys, media, navigation
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |   1  |  2   |  3   |  4   |  5   |                              |  6   |  7   |  8   |  9   |  0   |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |      | Prev | Play | Next | VolUp|                              | Left | Down | Up   | Right|      |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |      |      |      | Mute | VolDn|      |      |  |      |      | MLeft| Mdown| MUp  |MRight|      |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_EXTN] = LAYOUT(
      ___, KC_1, KC_2, KC_3, KC_4, KC_5,                                     KC_6, KC_7, KC_8,  KC_9, KC_0, _______,
      ___, KC_LGUI, KC_LALT, KC_LSFT, KC_LCTRL, MO(_MEDIA),                  KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, A(KC_BSPC), ___,
      ___, G(KC_Z), G(KC_X), G(KC_C), G(KC_D), G(KC_V), ___, ___, ___, ___, _______, _______, _______, _______, _______, KC_EQL,
                                 _______, _______, _______, _______, _______, _______, KC_LSHIFT, _______, _______, _______
    ),
/*
 * Numbers Layer: Numpad
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |      |      | VolUp|      |      |                              | / ?  | 7 &  | 8 *  | 9 (  | - _  |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |      | Prev | Play | Next |      |                              | *    | 4 $  | 5 %  | 6 ^  | , <  | +      |
 * |--------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |      |      | VolDn| Mute |      |      |      |  |      |      | 0 )  | 1 !  | 2 @  | 3 #  | = +  |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        |      |      | Lower|      |      |  |      | Nav  | Raise|      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_MEDIA] = LAYOUT(
      ___, C(G(KC_Q)), KC_POWER, KC_MPLY, _______, _______,                                 _______, KC_BRID, KC_BRIU, _______, _______, ___,
      RESET, _______, _______, _______, _______, _______,                                 KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT, _______, ___,
      ___, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  ___,
                                 _______, _______, _______, _______, _______, _______, KC_MUTE, KC_MPLY, _______, _______
    ),
/*
 * Mirror Layer
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |      |  |      |      |      |      |      |      |      |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_MIRR] = LAYOUT(
      ___, KC_SCOLON, KC_Y, KC_U, KC_L, KC_J,                                     _______, _______, _______, _______, _______, ___,
      ___, KC_O, KC_I, KC_E, KC_N, KC_M,                                     _______, _______, _______, _______, _______, ___,
      ___, KC_SLASH, KC_DOT, KC_COMMA, KC_H, KC_K, _______, _______, _______, _______, _______, _______, _______, _______, _______, ___,
                                 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    )

// /*
//  * Layer template
//  *
//  * ,-------------------------------------------.                              ,-------------------------------------------.
//  * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
//  * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
//  * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
//  * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
//  * |        |      |      |      |      |      |      |      |  |      |      |      |      |      |      |      |        |
//  * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
//  *                        |      |      |      |      |      |  |      |      |      |      |      |
//  *                        |      |      |      |      |      |  |      |      |      |      |      |
//  *                        `----------------------------------'  `----------------------------------'
//  */
//     [_LAYERINDEX] = LAYOUT(
//       _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
//       _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
//       _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
//                                  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
//     ),
};

LEADER_EXTERNS();

#ifdef RGBLIGHT_ENABLE
void keyboard_post_init_user(void) {
  rgblight_enable_noeeprom(); // Enables RGB, without saving settings
  rgblight_sethsv_noeeprom(HSV_BLUE);
  rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_LIGHT);
}
#endif

layer_state_t layer_state_set_user(layer_state_t state) {
  switch (get_highest_layer(state)) {
    case _BASE:
      rgblight_setrgb(RGB_BLUE);
      rgblight_sethsv_noeeprom(HSV_BLUE);
      break;
    case _SHIFT:
      rgblight_setrgb(RGB_BLUE);
      rgblight_sethsv_noeeprom(HSV_BLUE);
      break;
    case _SYMB:
      rgblight_setrgb(RGB_BLUE);
      rgblight_sethsv_noeeprom(HSV_BLUE);
      break;
    case _EXTN:
      rgblight_setrgb(RGB_BLUE);
      rgblight_sethsv_noeeprom(HSV_BLUE);
      break;
    case _MEDIA:
      rgblight_setrgb(RGB_PURPLE);
      rgblight_sethsv_noeeprom(HSV_PURPLE);
      break;
    case _MIRR:
      rgblight_setrgb(RGB_BLUE);
      rgblight_sethsv_noeeprom(HSV_BLUE);
      break;
  }
  return state;
}

void matrix_scan_user(void) {
  LEADER_DICTIONARY() {
    leading = false;
    leader_end();

    SEQ_ONE_KEY(KC_T) {
      SEND_STRING(SS_LCTRL(SS_LSFT("t")));
    }
    SEQ_ONE_KEY(KC_Q) {
      SEND_STRING(SS_LCTL("1"));
    }
    SEQ_ONE_KEY(KC_W) {
      SEND_STRING(SS_LCTL("2"));
    }
  }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    switch (keycode) {
      case EPRM:
        eeconfig_init();
        return false;
      case KC_ARROW:
        SEND_STRING("->");
        return false;
    }
  }
  return true;
}
