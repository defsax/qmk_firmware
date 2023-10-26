// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

#define _QWERTY 0
#define _GAMING 1
#define _MODIFY 2

enum custom_keycodes { QWERTY = SAFE_RANGE, GAMING, MODIFY };

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * ,-----------------------.         ,--------------------------.
     * | ` | 1 | 2 | 3 | 4 | 5 |         | 6 | 7 | 8 | 9 | 0 | Bksp |
     * |---+---+---+---+---+---|         |---+---+---+---+---+------|
     * |Tab| Q | W | E | R | T |         | Y | U | I | O | P | Del  |
     * |---+---+---+---+---+---|         |---+---+---+---+---+------|
     * |Esc| A | S | D | F | G |         | H | J | K | L | ; |  "   |
     * |---+---+---+---+---+---|         |---+---+---+---+---+------|
     * |Shft|Z | X | C | V | B |         | N | M | , | . | / |Enter |
     * |---+---+---+---+---+---|         |---+---+---+---+---+------|
     * |Ctrl|Adjt|Alt|GUI| |Spc|         |Spc|   |Left|Up|Down|Right|
     * `-----------------------`         `--------------------------'
     */

    [_QWERTY] = LAYOUT_split_5x6(
        KC_GRV, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0,
        KC_BSPC, KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O,
        KC_P, KC_DEL, KC_ESC, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K,
        KC_L, KC_SCLN, KC_QUOT, KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N,
        KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_ENT, KC_LCTL, MODIFY, KC_LALT,
        KC_LGUI, KC_SPC, KC_SPC, KC_LEFT, KC_UP, KC_DOWN, KC_RGHT),

    /*
     * ,-----------------------.         ,--------------------------.
     * |   | F1| F2| F3| F4| F5|         | F6| F7| F8| - | + | Bksp |
     * |---+---+---+---+---+---|         |---+---+---+---+---+------|
     * |   | F9|F10|F11|F12|   |         |   |   |   | [ | ] | Del  |
     * |---+---+---+---+---+---|         |---+---+---+---+---+------|
     * |   |   |   |   |   |   |         |GAM| _ | + | / | \ |  |   |
     * |---+---+---+---+---+---|         |---+---+---+---+---+------|
     * |   |   |Cut|Cpy|Pst|   |         |QWE| | | > | . | / |Enter |
     * |---+---+---+---+---+---|         |---+---+---+---+---+------|
     * |   |   |   |GUI|   |Spc|         |Spc|   |Nxt|VUp|VDwn|PlayP|
     * `-----------------------`         `--------------------------'
     */

    [_MODIFY] = LAYOUT_split_5x6(
        _______, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8,
        KC_MINS, KC_EQL, KC_BSPC, _______, KC_F9, KC_F10, KC_F11, KC_F12,
        _______, _______, _______, _______, KC_LBRC, KC_RBRC, KC_DEL, _______,
        _______, _______, _______, _______, _______, GAMING, KC_UNDS, KC_PLUS,
        KC_SLSH, KC_BSLS, KC_PIPE, _______, _______, KC_CUT, KC_COPY, KC_PASTE,
        _______, QWERTY, S(KC_NUHS), S(KC_NUBS), _______, _______, _______,
        _______, _______, _______, _______, _______, _______, KC_MNXT, KC_VOLD,
        KC_VOLU, KC_MPLY),

    [_GAMING] = LAYOUT_split_5x6(
        KC_GRV, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0,
        KC_BSPC, KC_TAB, KC_Q, KC_W, KC_E, KC_UP, KC_T, KC_Y, KC_U, KC_I, KC_O,
        KC_P, KC_DEL, KC_ESC, KC_A, KC_S, KC_LEFT, KC_DOWN, KC_RGHT, KC_H, KC_J,
        KC_K, KC_L, KC_SCLN, KC_QUOT, KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B,
        KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_ENT, KC_LCTL, MODIFY, KC_LALT,
        KC_LGUI, KC_SPC, KC_SPC, KC_D, KC_F, KC_R, KC_G),
};

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        persistent_default_layer_set(1UL << _QWERTY);
      }
      return false;
      break;

    case GAMING:
      if (record->event.pressed) {
        persistent_default_layer_set(1UL << _GAMING);
      }
      return false;
      break;

    case MODIFY:
      if (record->event.pressed) {
        layer_on(_MODIFY);
        // update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_MODIFY);
        // update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
  }
  return true;
}