/* Copyright 2020 GhostSeven <work@ghost7.com>
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

enum encoder_names {
  _ENCODER
};

enum layers {
  _LOWER,
  _RAISE
};

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
        |                   |      | Knob 1: Vol Dn/Up  |
        | Hold: Layer 2     | Media| Press: Mute        |
        | last track        | play | next track         |
     */
    [0] = LAYOUT(
        MO(1), KC_MSEL, KC_MUTE,
        KC_MPRV, KC_MPLY, KC_MNXT
    ),
    /*
        | Held: Layer 2  | Up   | QK_BOOT      |
        | Left           | Down | Right        |
     */
    [1] = LAYOUT(
        _______, KC_UP, QK_BOOT,
        KC_LEFT, KC_DOWN , KC_RGHT
    ),
};
bool encoder_update_user(uint8_t index, bool clockwise) {
  if (index == _ENCODER){
    if(IS_LAYER_ON(0)) { // on Raise layer control volume
        if (clockwise){
        tap_code(KC_VOLU);
        } else{
        tap_code(KC_VOLD);
        }        
    } else { // on other layers emulate mouse scrollwheel
        if (clockwise){
        tap_code(MS_WHLU);
        } else{
        tap_code(MS_WHLD);
        }
    }
  }
  return true;
}