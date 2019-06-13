#include QMK_KEYBOARD_H
// #include "quantum.h"

extern keymap_config_t keymap_config;

#define BL 0
#define GAME 1
#define SL 2
#define FL 3

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

enum {
    TD_ESC_CAPS=0,
    TD_ENTER,
    WTD_CP,
    MTD_CP,
    TD_MINUS
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [BL] = LAYOUT_default(
    KC_GRV,  TD_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,   KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_DEL,  KC_BSLS,
    KC_PGUP, KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,             KC_Y,   KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_QUOT, KC_RBRC,
    KC_PGDN, MO(SL),  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,             KC_H,   KC_J,    KC_K,    KC_L,    KC_SCLN, KC_BSPC,          KC_ENT,
             KC_LSPO, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,             TG(GAME), KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSPC, MO(FL),
             KC_LCTL,          KC_LALT, MO(SL),  KC_RGUI,                          KC_SPC,           KC_RALT,          KC_RCTL
  ),

  [GAME] = LAYOUT_default(
    _______,  _______, _______, _______, _______, _______, _______,   _______,   _______, _______, _______, _______, _______, _______, _______, _______,
    KC_VOLU,  _______, _______, _______, _______, _______, _______,              _______, _______, _______, _______, _______, _______, _______, _______,
    KC_VOLD,  KC_LCTL, _______, _______, _______, _______, _______,              _______, _______, _______, _______, _______, _______,          _______,
              _______, _______, _______, _______, _______, _______,              _______, _______, _______, _______, _______, _______, _______, _______,
              _______,          _______, KC_SPC, _______,                            _______,          _______,          _______
  ),

  [SL] = LAYOUT_default(
    RGB_TOG,  _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,   KC_F11,  KC_F12,  _______, _______,
    RGB_MOD,  _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______,  _______, _______, _______, _______,
    RGB_RMOD, _______, _______, _______, _______, _______, _______,          KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT, _______, _______,          _______,
              _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______,  _______, _______, _______, _______,
              _______,          _______, KC_SPC, _______,                            _______,          _______,          _______
  ),

  [FL] = LAYOUT_default(
    RESET,  _______, _______, _______, _______, _______, _______,   _______,   _______, _______, _______, _______, _______, _______, _______, _______,
    _______,  _______, _______, _______, _______, _______, _______,              _______, _______, _______, _______, _______, _______, _______, _______,
    _______,  _______, _______, _______, _______, _______, _______,              _______, _______, _______, _______, _______, _______,          _______,
              _______, _______, _______, _______, _______, _______,              _______, _______, _______, _______, _______, _______, _______, _______,
              _______,          _______, _______, _______,                            _______,          _______,          _______
  )
};

// Tap Dance Definitions
qk_tap_dance_action_t tap_dance_actions[] = {
    [TD_ESC_CAPS]  = ACTION_TAP_DANCE_DOUBLE(KC_ESC, KC_CAPS),
};
