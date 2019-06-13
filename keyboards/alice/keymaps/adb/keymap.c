#include QMK_KEYBOARD_H

// Layers
#define BL 0
#define GAME 1
#define WIN 2
#define FL 3
#define SL 4

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

#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [BL] = LAYOUT(
        KC_GRV,     TD_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_DEL,  KC_BSLS, \
        KC_VOLU,    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_ENT, KC_RBRC,          \
        KC_VOLD,    MO(FL),  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_BSPC,          KC_QUOT,           \
                    KC_LSPO, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    TG(GAME),  KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSPC, MO(SL),            \
                    KC_RCTL,          KC_LALT,          MO(SL),  KC_LGUI,          KC_SPC,           KC_RALT,                            KC_RCTL           \
    ),

    [FL] = LAYOUT(
        _______,    KC_GRV , KC_F1,   KC_F2,   KC_F3,   KC_F4,    KC_F6,   KC_F6,   KC_F7,   KC_F8,   KC_F9,    KC_F10,  KC_F11,  KC_F12,  KC_DEL,  KC_INS,  \
        _______,    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______, _______,  _______, _______  , _______, _______,          \
        _______,    _______,  _______,  _______,  _______, _______, _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT, _______, _______, _______,                   \
                    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______, _______,          \
                    _______,          _______,          _______, _______,          _______,          _______,                            _______           \
    ),

    [SL] = LAYOUT(
        RESET,    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
        _______,  _______, KC_BTN1, KC_MS_U, KC_BTN2, _______, _______, _______, _______, _______, _______, _______, _______  , _______, _______,          \
        _______,  _______, KC_MS_L, KC_MS_D, KC_MS_R, _______, _______, S_LEFT,  S_DOWN,  S_UP,    S_RIGHT, _______, S_DWORD,          _______,          \
                    _______, _______, _______, _______, _______, _______, KC_PGDN, _______, _______, _______, _______, _______, _______, _______,          \
                    _______,          _______,          _______, _______,          _______,          _______,                            _______           \
    ),

    [WIN] = LAYOUT(
        _______,    _______, WIN_SQ1, WIN_SQ2, WIN_SQ3, WIN_SQ4, _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______,  \
        _______,    _______, _______, WIN_U,   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          \
        _______,    _______, WIN_L,   WIN_D,   WIN_R,   _______, _______, _______, _______, _______, _______, _______, _______, _______,                   \
                    _______, _______, _______, _______, _______, _______, _______, WIN_N, WIN_M, _______, _______, _______, _______, _______,          \
                    _______,          _______,          _______, _______,          _______,          _______,                            _______           \
    ),

    [GAME] = LAYOUT(
        _______,    _______ , _______,   _______,   _______,   _______,    _______,   _______,   _______,   _______,   _______,    _______,  _______,  _______,  _______,  _______,  \
        _______,    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______, _______,  _______, _______  , _______, _______,          \
        _______,    _______,  _______,  _______,  _______, _______, _______, _______, _______, _______,   _______, _______, _______, _______,                   \
                    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______, _______,          \
                    _______,          _______,          KC_SPC, KC_LALT,          _______,          _______,                            _______           \
    ),

};

// Tap Dance Definitions
qk_tap_dance_action_t tap_dance_actions[] = {
    [TD_ESC_CAPS]  = ACTION_TAP_DANCE_DOUBLE(KC_ESC, KC_CAPS),
};

void led_set_user(uint8_t usb_led) {
    if (IS_LED_ON(usb_led, USB_LED_NUM_LOCK)) {
        PORTD |= (1 << USB_LED_NUM_LOCK);
    }
    else{
        PORTD &= ~(1 << USB_LED_NUM_LOCK);
    }

    if (IS_LED_ON(usb_led, USB_LED_CAPS_LOCK)) {
        PORTD |= (1 << USB_LED_CAPS_LOCK);
    }
    else{
        PORTD &= ~(1 << USB_LED_CAPS_LOCK);
    }

    if (IS_LED_ON(usb_led, USB_LED_SCROLL_LOCK)) {
        PORTD |= (1 << USB_LED_SCROLL_LOCK);
    }
    else{
        PORTD &= ~(1 << USB_LED_SCROLL_LOCK);
    }
}
