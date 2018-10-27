// #include QMK_KEYBOARD_H

// // Helpful defines
// #define _______ KC_TRNS

// #define _BL 0
// #define _FL 1

// const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
// 	[_BL] = LAYOUT(KC_GESC,  KC_F1, KC_F2,   KC_F3,  KC_F4,   KC_F5, KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,  KC_F12,  KC_PSCR, KC_SLCK, KC_PGUP, 
// 				 KC_GRV,   KC_1,  KC_2,    KC_3,   KC_4,    KC_5,  KC_6,    KC_7,    KC_8,    KC_9,   KC_0,    KC_MINS, KC_EQL,  KC_INS,  KC_PGUP, KC_PGDN,
// 				 KC_TAB,   KC_Q,  KC_W,    KC_E,   KC_R,    KC_T,  KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,    KC_LBRC, KC_RBRC, KC_BSPC,          KC_VOLU, 
// 				 KC_LCTL,  KC_A,  KC_S,    KC_D,   KC_F,    KC_G,  KC_H,    KC_J,    KC_K,    KC_L,   KC_SCLN, KC_QUOT, KC_NO,   KC_ENT,           KC_VOLD, 
// 				 KC_LSPO,  KC_Z,  KC_X,    KC_C,   KC_V,    KC_B,  KC_N,    KC_M,    KC_COMM, KC_DOT, KC_SLSH, KC_RSPC, KC_NO,   KC_UP,            KC_MUTE, 
// 				 KC_LCTL,  KC_NO, KC_LALT, KC_SPC, KC_LALT, KC_NO, KC_LCTL,                                    KC_LEFT,                            KC_DOWN, KC_RGHT)        
// };

/* Copyright 2018 MechMerlin <mechmerlin@gmail.com>
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

#define _BL 0 // Base Layer
#define _FL 1 // Fn Layer

//Tap Dance Declarations
enum {
    TD_LCTL = 0,
    TD_LALT
    TD_ESC_CAPS
};

enum custom_keycodes {
    M_COPY = SAFE_RANGE,
    M_PASTE
};



bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        switch(keycode) {
            case M_COPY:
                SEND_STRING(SS_LCTRL("ac")); // selects all and copies               
                return false;
            case M_PASTE:
                SEND_STRING(SS_LCTRL("v")); // selects all and copies
                return false;
        }
    }
    return true;
};

//Tap Dance Definitions
qk_tap_dance_action_t tap_dance_actions[] = {
    //Tap once for Esc, twice for Caps Lock
    [TD_LCTL] = ACTION_TAP_DANCE_DOUBLE(KC_LCTL, M_COPY),
    [TD_LALT] = ACTION_TAP_DANCE_DOUBLE(KC_LALT, M_PASTE),
    [TD_ESC_CAPS]  = ACTION_TAP_DANCE_DOUBLE(KC_ESC, KC_CAPS)
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	// [_BL] = LAYOUT(KC_GESC,  KC_F1, KC_F2,   KC_F3,  KC_F4,   KC_F5, KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,  KC_F12,  KC_PSCR, KC_SLCK, KC_PGUP, 
	// 			   KC_GRV,   KC_1,  KC_2,    KC_3,   KC_4,    KC_5,  KC_6,    KC_7,    KC_8,    KC_9,   KC_0,    KC_MINS, KC_EQL,  KC_INS,  KC_PGDN,
	// 			   KC_TAB,   KC_Q,  KC_W,    KC_E,   KC_R,    KC_T,  KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,    KC_LBRC, KC_RBRC, KC_BSPC,          KC_VOLU, 
	// 			   KC_LCTL,  KC_A,  KC_S,    KC_D,   KC_F,    KC_G,  KC_H,    KC_J,    KC_K,    KC_L,   KC_SCLN, KC_QUOT, KC_NO,   KC_ENT,           KC_VOLD, 
	// 			   KC_LSPO,  KC_NO  KC_Z,  KC_X,    KC_C,   KC_V,    KC_B,  KC_N,    KC_M,    KC_COMM, KC_DOT, KC_SLSH, KC_RSPC, KC_NO,   KC_UP,            KC_MUTE, 
	// 			   KC_LCTL,  KC_NO, KC_LALT, KC_SPC, KC_LALT, KC_NO, KC_LCTL,                                    KC_LEFT,                            KC_DOWN, KC_RGHT),

    [_BL] = LAYOUT_75_ansi(\
        TD_ESC_CAPS,          KC_F1,                KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_F6,  KC_F7,  KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_PSCR, M_COPY, RGB_MOD,
        KC_GRV,               KC_1,                 KC_2,   KC_3,   KC_4,   KC_5,   KC_6,   KC_7,   KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_QUOT,          RGB_TOG,
        KC_TAB,               KC_Q,                 KC_W,   KC_E,   KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_ENT,           KC_VOLU,
        OSL(_FL),             KC_A,                 KC_S,   KC_D,   KC_F,   KC_G,   KC_H,   KC_J,   KC_K,    KC_L,    KC_SCLN, KC_BSPC,          KC_BSLS,          KC_VOLD,
        KC_LSPO,              KC_Z,                 KC_X,   KC_C,   KC_V,   KC_B,   KC_N,   KC_M,   KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, KC_UP,                     KC_MUTE,
        TD_LCTL,              TD_LALT, KC_NO,                KC_SPC,                                     KC_LALT, KC_NO,   KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT),

    [_FL] = LAYOUT_75_ansi(\
        KC_TRNS, RGB_TOG, RGB_MOD, RGB_VAI, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,          KC_ASTG,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, RESET,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,          KC_ASUP,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT, KC_TRNS, KC_TRNS,          KC_TRNS,         KC_ASDN,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                   KC_ASRP,
        KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS,          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),

};