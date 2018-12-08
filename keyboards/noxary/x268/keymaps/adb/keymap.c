#include QMK_KEYBOARD_H

// Layers
#define BL 0
#define FL 1
#define SL 2
#define WL 3
#define MAC 4
#define LI 5

#define TD_ESC TD(TD_ESC_CAPS)
#define S_OTAB LCTL(KC_T)
#define S_ROTAB LCTL(LSFT(KC_T))
#define S_CLOSE LCTL(KC_X)
#define S_DWORD LCTL(KC_BSPC)

#define S_UP LCTL(KC_HOME)
#define S_DOWN LCTL(KC_END)
#define S_LEFT LCTL(KC_LEFT)
#define S_RIGHT LCTL(KC_RIGHT)

// Window management
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
#define WIN_N (LCTL(LGUI(LALT(KC_N))))
#define WIN_P (LCTL(LGUI(LALT(KC_P))))

// Macros
enum custom_keycodes {
    M_COPY = SAFE_RANGE,
    M_PASTE,
    M_SALL,
    M_UENT,
    M_UP,
    M_DOWN,
    M_LEFT,
    M_RIGHT
};

//Tap Dance
enum {
    TD_ESC_CAPS=0,
    TD_ENTER,
    WTD_CP,
    MTD_CP,
    TD_MINUS
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [BL] = LAYOUT_65_ansi(
        TD_ESC,  KC_1,    KC_2,    KC_3,   KC_4,    KC_5,  KC_6,    KC_7,    KC_8,    KC_9,    KC_0,     KC_MINS, KC_EQL,  KC_BSLS, MO(LI) , KC_GRV,
        KC_TAB,  KC_Q,    KC_W,    KC_E,   KC_R,    KC_T,  KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,     KC_LBRC, KC_ENT,           KC_QUOT, KC_MUTE,
        MO(FL),  KC_A,    KC_S,    KC_D,   KC_F,    KC_G,  KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,  KC_BSPC, KC_NUHS,          KC_RBRC, KC_VOLU,
        KC_LSPO, MO(SL),  KC_Z,    KC_X,   KC_C,    KC_V,  KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,   KC_SLSH, KC_RSPC,          MO(WL),  KC_VOLD,
        KC_LCTL, KC_LGUI, KC_LALT,                         KC_SPC,                    MO(WL),  KC_LGUI,  KC_NUHS, KC_LEFT,          KC_DOWN, KC_RGHT),

    [FL] = LAYOUT_65_ansi(
        KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,    KC_F10,  KC_F11,    KC_F12,  _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______,   _______,          _______, _______,
        _______, _______, _______, _______, _______, _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT, _______, KC_DELETE, _______,          _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______,   _______,          _______, _______,
        _______, _______, _______,                            _______,                   _______,  _______, _______,   _______,          _______, _______),

    [SL] = LAYOUT_65_ansi(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, RESET,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______,
        _______, _______, _______, _______, _______, _______, S_LEFT,  S_DOWN,  S_UP,    S_RIGHT, _______, S_DWORD, _______,          _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______,
        _______, _______, _______,                            _______,                   _______, _______, _______, _______,          _______, _______),

    [WL] = LAYOUT_65_ansi(
        _______, WIN_SQ1, WIN_SQ2, WIN_SQ3, WIN_SQ4, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, WIN_P,   _______, _______,          _______, _______,
        _______, _______, _______, _______, _______, _______, WIN_L,   WIN_D,   WIN_U,   WIN_R,   _______, _______, _______,          _______, _______,
        _______, _______, _______, _______, WIN_C,   _______, _______, WIN_N,   WIN_M,   _______, _______, _______, _______,          _______, _______,
        _______, _______, _______,                            _______,                   _______, _______, _______, _______,          _______, _______),

    [MAC] = LAYOUT_65_ansi(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______,
        _______, _______, _______, _______, _______, _______, S_LEFT,  S_DOWN,  S_UP,    S_RIGHT, _______, _______, _______,          _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______,
        _______, _______, _______,                            _______,                   _______, _______, _______, _______,          _______, _______),

    [LI] = LAYOUT_65_ansi(
        RGB_TOG, RGB_MOD, RGB_RMOD, RGB_SAI, RGB_SAD, RGB_HUI, RGB_HUD, RGB_M_P, RGB_M_SW, _______, _______, _______, _______, _______, _______, _______,
        BL_TOGG, BL_INC,  BL_DEC,   BL_BRTG, _______, _______, _______, _______, _______,  _______, _______, _______, _______,          _______, _______,
        _______, _______, _______,  _______, _______, _______, _______, _______, _______,  _______, _______, _______, _______,          _______, _______,
        _______, _______, _______,  _______, _______, _______, _______, _______, _______,  _______, _______, _______, _______,          _______, _______,
        _______, _______, _______,                             _______,                    _______, _______, _______, _______,          _______, _______),

};


void matrix_init_user(void) {
}

void matrix_scan_user(void) {
}

// Macros
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

// Tap Dance Definitions
qk_tap_dance_action_t tap_dance_actions[] = {
    [TD_ESC_CAPS]  = ACTION_TAP_DANCE_DOUBLE(KC_ESC, KC_CAPS),
    // [WTD_CP] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, wcp_finished, wcp_reset),
    // [MTD_CP] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, mcp_finished, mcp_reset)

};
