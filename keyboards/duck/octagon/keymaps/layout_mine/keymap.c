#include QMK_KEYBOARD_H

//Layers
#define _BL 0
#define _FL 1
#define _SL 2

#define TD_ESC TD(TD_ESC_CAPS)
#define KC_OTAB LCTL(KC_T)
#define KC_ROTAB LCTL(LSFT(KC_T))
#define KC_CLOSE LCTL(KC_X)
#define KC_DWORD LCTL(KC_BSPC)

//Window management
#define WIN_SQ1 (LCTL(LGUI(LALT(KC_1))))
#define WIN_SQ2 (LCTL(LGUI(LALT(KC_2))))
#define WIN_SQ3 (LCTL(LGUI(LALT(KC_3))))
#define WIN_SQ4 (LCTL(LGUI(LALT(KC_4))))
#define WIN_L (LCTL(LGUI(LALT(KC_H))))
#define WIN_R (LCTL(LGUI(LALT(KC_L))))
#define WIN_U (LCTL(LGUI(LALT(KC_K))))
#define WIN_D (LCTL(LGUI(LALT(KC_J))))
#define WIN_M (LCTL(LGUI(LALT(KC_M))))
#define WIN_C (LCTL(LGUI(LALT(KC_C))))

//testing stuff

// void backlight_init_ports(void);
// void indicator_leds_set([1 1 1 1 1 1 1 1]);
// void indicator_leds_set(bool leds[8]);
// void backlight_toggle_rgb(bool enabled);
// void backlight_set_rgb(uint8_t cfg[17][3]);
// void backlight_init_ports(void);
// void send_color(uint8_t r, uint8_t g, uint8_t b, enum Device device);
// void show(void);

void numlock_led_on(void) {
  PORTF |= (1 << 7);
}

void numlock_led_off(void) {
  PORTF &= ~(1 << 7);
}


//end testing stuff

//Tap Dance
enum {
    TD_ESC_CAPS=0,
    TD_ENTER,
    TD_CP,
    TD_MINUS
};

//Macros
enum custom_keycodes {
    M_COPY = SAFE_RANGE,
    M_PASTE,
    M_SALL,
    M_UENT
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
            case M_SALL:
                SEND_STRING(SS_LCTRL("ac"));
                return false;
            case M_UENT:
                SEND_STRING(SS_TAP(X_UP));
                SEND_STRING(SS_TAP(X_ENTER));
                return false;
        }
    }
    return true;
};

//Copy paste key
void cp_finished (qk_tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    if (state->interrupted || !state->pressed)
    {
        register_code(KC_LCTRL);
        register_code(KC_C);    
    }
  }
  if (state->count == 2) {
    if (state->interrupted || !state->pressed)
    {
        register_code(KC_LCTRL);
        register_code(KC_V);    
    }
  }
}

void cp_reset (qk_tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    if (state->interrupted || !state->pressed)
    {
        unregister_code(KC_LCTRL);
        unregister_code(KC_C);    
    }
  }
  if (state->count == 2) {
    if (state->interrupted || !state->pressed)
    {
        unregister_code(KC_LCTRL);
        unregister_code(KC_V);    
    }
  }
}

//TODO Move up+enter to a macro on layer

//Tap Dance Definitions
qk_tap_dance_action_t tap_dance_actions[] = {
    [TD_ESC_CAPS]  = ACTION_TAP_DANCE_DOUBLE(KC_ESC, KC_CAPS),
    [TD_CP] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, cp_finished, cp_reset)
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	
    [_BL] = LAYOUT_75_ansi(\
        TD_ESC,   WIN_SQ1,  WIN_SQ2,  WIN_SQ3,  WIN_SQ4,  WIN_L,  WIN_D,  WIN_U,  WIN_R,   WIN_M,   WIN_C,  KC_F11,  F(numlock_led_on),  KC_NLCK, BL_TOGG, RGB_MOD,
        KC_GRV,   KC_1,   KC_2,   KC_3,   KC_4,   KC_5,   KC_6,   KC_7,   KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,     KC_QUOT,    RGB_TOG,
        KC_TAB,   KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC,   KC_BSLS,     KC_MUTE,
        MO(_FL),  KC_A,   KC_S,   KC_D,   KC_F,   KC_G,   KC_H,   KC_J,   KC_K,    KC_L,    KC_SCLN, KC_BSPC,            KC_ENTER,    KC_VOLU,
        KC_LSPO,  KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,   KC_N,   KC_M,   KC_COMM, KC_DOT,  KC_SLSH, KC_RSPC,                 KC_UP,  KC_VOLD,
        KC_LCTL,  KC_LGUI, KC_LALT,    KC_SPC,                                       TD(TD_CP), KC_RGUI,   KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT), 

    [_FL] = LAYOUT_75_ansi(\
        KC_TRNS, KC_F1,     KC_F2,    KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,    KC_F10,  KC_F11,  KC_F12, KC_TRNS, KC_TRNS, RESET,
        KC_TRNS, KC_TRNS,   KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,          KC_ASTG,
        KC_TRNS, KC_TRNS,   KC_TRNS,  KC_TRNS, KC_OTAB, KC_ROTAB, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,          KC_ASUP,
        KC_TRNS, M(M_SALL), KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT, KC_TRNS, KC_DWORD,          KC_TRNS,         KC_ASDN,
        KC_TRNS, KC_TRNS,   KC_CLOSE, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS,                   KC_ASRP,
        KC_TRNS, KC_TRNS,   KC_TRNS,          KC_TRNS,          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS),
};