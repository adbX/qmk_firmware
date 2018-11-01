#include QMK_KEYBOARD_H

#define _BL 0
#define _FL 1

//Tap Dance Declarations
enum {
    TD_ESC_CAPS=0,
    TD_LCTL,
    TD_LALT,
    TD_ENTER
};

enum custom_keycodes {
    M_COPY = SAFE_RANGE,
    M_PASTE,
    M_SEL_ALL
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
            case M_SEL_ALL:
                SEND_STRING(SS_LCTRL("ac"));
                return false;
        }
    }
    return true;
};

void copy_finished (qk_tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    if (state->interrupted || !state->pressed)
    {
        register_code(KC_LCTRL);
        register_code(KC_C);    
    }
    else
    {
        register_code(KC_LCTRL);
    }
  } 
}

void copy_reset (qk_tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    if (state->interrupted || !state->pressed)
    {
        unregister_code(KC_LCTRL);
        unregister_code(KC_C);    
    }
    else
    {
        unregister_code(KC_LCTRL);
    }
  } 
}

void paste_finished (qk_tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    if (state->interrupted || !state->pressed)
    {
        register_code(KC_LCTRL);
        register_code(KC_V);    
    }
    else
    {
        register_code(KC_LALT);
    }
  } 
}

void paste_reset (qk_tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    if (state->interrupted || !state->pressed)
    {
        unregister_code(KC_LCTRL);
        unregister_code(KC_V);
        unregister_code(KC_LALT);
    
    }
    else
    {
        unregister_code(KC_LCTRL);
        unregister_code(KC_LALT);
    }
  } 
}

void up_enter_finished (qk_tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) { register_code(KC_ENTER); }
  else if (state->count == 2) { register_code(KC_UP); register_code(KC_ENTER); } 
}

void up_enter_reset (qk_tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) { unregister_code(KC_ENTER); }
  else if (state->count == 2) { unregister_code(KC_UP); unregister_code(KC_ENTER); } 
}

//Tap Dance Definitions
qk_tap_dance_action_t tap_dance_actions[] = {
    [TD_LCTL] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, copy_finished, copy_reset),
    [TD_LALT] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, paste_finished, paste_reset),
    [TD_ESC_CAPS]  = ACTION_TAP_DANCE_DOUBLE(KC_ESC, KC_CAPS),
    [TD_ENTER] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, up_enter_finished, up_enter_reset)
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	
    [_BL] = LAYOUT_75_ansi(\
        TD(TD_ESC_CAPS), KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_F6,  KC_F7,  KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_PSCR, KC_Q, RGB_MOD,
        KC_GRV,          KC_1,   KC_2,   KC_3,   KC_4,   KC_5,   KC_6,   KC_7,   KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,         KC_QUOT,    RGB_TOG,
        KC_TAB,          KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC,   KC_BSLS,    KC_MUTE,
        MO(_FL),         KC_A,   KC_S,   KC_D,   KC_F,   KC_G,   KC_H,   KC_J,   KC_K,    KC_L,    KC_SCLN, KC_BSPC,                 TD(TD_ENTER),    KC_VOLU,
        KC_LSPO,         KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,   KC_N,   KC_M,   KC_COMM, KC_DOT,  KC_SLSH, KC_RSPC,                     KC_UP,  KC_VOLD,
        KC_LCTL,  KC_LGUI, KC_LALT,    KC_SPC,                                                    KC_LALT, KC_RGUI,   KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT), 

    [_FL] = LAYOUT_75_ansi(\
        KC_TRNS, RGB_TOG, RGB_MOD, RGB_VAI, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,          KC_ASTG,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, RESET,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,          KC_ASUP,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT, KC_TRNS, KC_TRNS,          KC_TRNS,         KC_ASDN,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                   KC_ASRP,
        KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS,          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),
};