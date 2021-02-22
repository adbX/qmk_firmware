#include QMK_KEYBOARD_H

//Layers
#define _BL 0
#define _FL 1

#define S_ESC TD(TD_ESC_CAPS)
#define S_OTAB LCTL(KC_T)
#define S_ROTAB LCTL(LSFT(KC_T))
#define S_CLOSE LCTL(KC_X)
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
#define WIN_N (LCTL(LGUI(LALT(KC_N))))

//Macros
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

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_BL] = LAYOUT_75_ansi(\
        KC_ESC,      WIN_SQ1,  WIN_SQ2,  WIN_SQ3,  WIN_SQ4,  WIN_L,  WIN_D,  WIN_U,  WIN_R,   WIN_M,   WIN_C,   WIN_N,  RGB_TOG,  RGB_MOD, KC_HOME, KC_PGUP,
        KC_GRAVE,     KC_1,     KC_2,     KC_3,     KC_4,     KC_5,   KC_6,   KC_7,   KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,     KC_BSLS,       KC_PGDN,
        KC_TAB,      KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,   KC_Y,   KC_U,   KC_I,    KC_O,    KC_P,    KC_LBRC, KC_QUOT,   KC_RBRC,        KC_MUTE,
        MO(_FL),     KC_A,     KC_S,     KC_D,     KC_F,     KC_G,   KC_H,   KC_J,   KC_K,    KC_L,    KC_SCLN, KC_BSPC,            KC_ENTER,       KC_VOLU,
        KC_LSPO,     KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,   KC_N,   KC_M,   KC_COMM, KC_DOT,  KC_SLSH, KC_RSPC,                 KC_UP,     KC_VOLD,
        KC_LCTL,     KC_LALT,  KC_LGUI,                                KC_SPC,                         MO(_FL), KC_RGUI,   KC_RCTL, KC_LEFT, KC_DOWN,    KC_RGHT),

    [_FL] = LAYOUT_75_ansi(\
        KC_TRNS, KC_TRNS,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, RESET,
        KC_TRNS, KC_TRNS,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_LEFT,  KC_DOWN,  KC_UP,    KC_RIGHT, KC_TRNS, KC_DWORD,          KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS,   KC_TRNS,          KC_TRNS,           KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),

};
