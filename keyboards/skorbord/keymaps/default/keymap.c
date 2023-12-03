// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

#define _QWERTY 0
#define _AOE 1
#define _LOWER 2
#define _RAISE 3
#define _ADJUST 4

enum custom_keycodes { QWERTY = SAFE_RANGE, AOE, LOWER, RAISE, ADJUST };

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* QWERTY
     * ,-----------------------.         ,--------------------------.
     * |Esc| 1 | 2 | 3 | 4 | 5 |         | 6 | 7 | 8 | 9 | 0 | Bksp |
     * |---+---+---+---+---+---|         |---+---+---+---+---+------|
     * |Tab| Q | W | E | R | T |         | Y | U | I | O | P | Del  |
     * |---+---+---+---+---+---|         |---+---+---+---+---+------|
     * |Rai| A | S | D | F | G |         | H | J | K | L | ; |  "   |
     * |---+---+---+---+---+---|         |---+---+---+---+---+------|
     * |Shft|Z | X | C | V | B |         | N | M | , | . | / |Enter |
     * |---+---+---+---+---+---|         |---+---+---+---+---+------|
     * |Ctrl|Lowe|Alt|GUI| |Spc|         |Spc|   |Left|Up|Down|Right|
     * `-----------------------`         `--------------------------'
     */

    [_QWERTY] = LAYOUT_split_5x6(
        KC_ESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0,
        KC_BSPC, KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O,
        KC_P, KC_DEL, RAISE, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K,
        KC_L, KC_SCLN, KC_QUOT, KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N,
        KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_ENT, KC_LCTL, LOWER, KC_LALT,
        KC_LGUI, KC_SPC, KC_SPC, KC_LEFT, KC_UP, KC_DOWN, KC_RGHT),

    /* LOWER
     * ,-----------------------.         ,--------------------------.
     * | F1| F2| F3| F4| F5| F6|         | F7| F8| F9|F10|F11| F12  |
     * |---+---+---+---+---+---|         |---+---+---+---+---+------|
     * |   |   |   |   |   |   |         |   |   |   | [ | ] | Del  |
     * |---+---+---+---+---+---|         |---+---+---+---+---+------|
     * |   |   |   |   |   |   |         |   | _ | + | / | \ |  |   |
     * |---+---+---+---+---+---|         |---+---+---+---+---+------|
     * |   |Und|Cut|Cpy|Pst|   |         |   | | | > | . | / |Enter |
     * |---+---+---+---+---+---|         |---+---+---+---+---+------|
     * |   |   |   |GUI|  Spc  |         | PlayP |Prv|VUp|VDwn|Next |
     * `-----------------------`         `--------------------------'
     */

    [_LOWER] = LAYOUT_split_5x6(
        KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10,
        KC_F11, KC_F12, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, KC_LBRC, KC_RBRC, KC_DEL, _______, _______,
        _______, _______, _______, _______, _______, KC_UNDS, KC_PLUS, KC_SLSH,
        KC_BSLS, KC_PIPE, _______, KC_UNDO, KC_CUT, KC_COPY, KC_PASTE, _______,
        _______, S(KC_NUHS), S(KC_NUBS), _______, _______, _______, _______,
        _______, _______, _______, _______, KC_MPLY, KC_MPRV, KC_VOLU, KC_VOLD,
        KC_MNXT),

    /* RAISE
     * ,-----------------------.         ,--------------------------.
     * | ` |   |   |   |   |   |         |   |   |   | - | + | Bksp |
     * |---+---+---+---+---+---|         |---+---+---+---+---+------|
     * |   |   |   |   |   |   |         |   |   |   | [ | ] |  \   |
     * |---+---+---+---+---+---|         |---+---+---+---+---+------|
     * |   |   |   |   |   |   |         |   |   |   |   |   |      |
     * |---+---+---+---+---+---|         |---+---+---+---+---+------|
     * |   |Und|Cut|Cpy|Pst|   |         |   | | | > | . | / |Enter |
     * |---+---+---+---+---+---|         |---+---+---+---+---+------|
     * |   |   |   |GUI|   |Spc|         |Spc|   |HOM|PGU|PDN| END  |
     * `-----------------------`         `--------------------------'
     */

    [_RAISE] = LAYOUT_split_5x6(
        KC_GRV, _______, _______, _______, _______, _______, _______, _______,
        _______, KC_MINS, KC_EQL, KC_BSPC, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, KC_LBRC, KC_RBRC, KC_BSLS,
        _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, KC_UNDO, KC_CUT, KC_COPY,
        KC_PASTE, _______, _______, S(KC_NUHS), S(KC_NUBS), _______, _______,
        _______, _______, _______, _______, _______, _______, _______, KC_HOME,
        KC_PGUP, KC_PGDN, KC_END),

    /* ADJUST
     * ,-----------------------.         ,--------------------------.
     * |PWR|   |   |   |   |   |         |   |   |   |   |   |      |
     * |---+---+---+---+---+---|         |---+---+---+---+---+------|
     * |   |   |   |   |   |   |         |   |   |   |   |   |      |
     * |---+---+---+---+---+---|         |---+---+---+---+---+------|
     * |   |   |   |   |   |FLS|         |QWE|AOE|   |   |   |      |
     * |---+---+---+---+---+---|         |---+---+---+---+---+------|
     * |   |   |   |CAL|   |   |         |   |   |   |   |   |      |
     * |---+---+---+---+---+---|         |---+---+---+---+---+------|
     * |   |   |   |   |   |   |         |   |   |   |   |   |      |
     * `-----------------------`         `--------------------------'
     */

    [_ADJUST] = LAYOUT_split_5x6(
        KC_PWR, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, QK_BOOT, QWERTY, AOE,
        _______, _______, _______, _______, _______, KC_CALC, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______),

    [_AOE] = LAYOUT_split_5x6(
        KC_ESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0,
        KC_BSPC, KC_TAB, KC_Q, KC_W, KC_E, KC_UP, KC_T, KC_Y, KC_U, KC_I, KC_O,
        KC_P, KC_DEL, RAISE, KC_A, KC_S, KC_LEFT, KC_DOWN, KC_RGHT, KC_H, KC_J,
        KC_K, KC_L, KC_SCLN, KC_QUOT, KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B,
        KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_ENT, KC_LCTL, LOWER, KC_LALT,
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

    case AOE:
      if (record->event.pressed) {
        persistent_default_layer_set(1UL << _AOE);
      }
      return false;
      break;

    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;

    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case ADJUST:
      if (record->event.pressed) {
        layer_on(_ADJUST);
      } else {
        layer_off(_ADJUST);
      }
      return false;
      break;
  }
  return true;
}

// bool encoder_update_user(uint8_t index, bool clockwise) {
//   if (index == 0) { /* First encoder */
//     if (clockwise) {
//       tap_code(KC_PGDN);
//     } else {
//       tap_code(KC_PGUP);
//     }
//   }
//   // else if (index == 1) { /* Second encoder */
//   //   if (clockwise) {
//   //     rgb_matrix_increase_hue();
//   //   } else {
//   //     rgb_matrix_decrease_hue();
//   //   }
//   // }
//   return false;
// }

#ifdef OLED_ENABLE
bool oled_task_user(void) {
  // Host Keyboard Layer Status
  oled_write_P(PSTR("Layer: "), false);

  switch (get_highest_layer(layer_state | default_layer_state)) {
    case _QWERTY:
      oled_write_P(PSTR("\nQWERTY\n"), false);
      break;
    case _AOE:
      oled_write_P(PSTR("\nAGE OF EMPIRES"), false);
      break;
    case _LOWER:
      oled_write_P(PSTR("\nLOWER\n"), false);
      break;
    case _RAISE:
      oled_write_P(PSTR("\nRAISE\n"), false);
      break;
    case _ADJUST:
      oled_write_P(PSTR("\nADJUST\n"), false);
      break;
    default:
      // Or use the write_ln shortcut over adding '\n' to the end of your string
      oled_write_ln_P(PSTR("Undefined"), false);
  }

  // Host Keyboard LED Status
  led_t led_state = host_keyboard_led_state();
  oled_write_P(led_state.num_lock ? PSTR("NUM ") : PSTR("    "), false);
  oled_write_P(led_state.caps_lock ? PSTR("CAP ") : PSTR("    "), false);
  oled_write_P(led_state.scroll_lock ? PSTR("SCR ") : PSTR("    "), false);

  return false;
}
#endif