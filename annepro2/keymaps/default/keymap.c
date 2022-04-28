//  _______  __   __  _______  _______  __   __
// |       ||  | |  ||  _    ||  _    ||  | |  |
// |  _____||  | |  || |_|   || |_|   ||  |_|  |
// | |_____ |  |_|  ||       ||       ||       |
// |_____  ||       ||  _   | |  _   | |_     _|
//  _____| ||       || |_|   || |_|   |  |   |
// |_______||_______||_______||_______|  |___|

#include QMK_KEYBOARD_H
#define RGB_MATRIX_STARTUP_MODE RGB_MATRIX_SOLID_REACTIVE_MULTINEXUS

enum anne_pro_layers {
    BASE,
    FN1,
    FN2,
};

// TAP DANCING

// Tap Dance Declarations
enum { TD_ESC_CAPS = 0, TD_1_F1, TD_2_F2, TD_3_F3, TD_4_F4, TD_5_F5, TD_6_F6, TD_7_F7, TD_8_F8, TD_9_F9, TD_0_F10, TD_minus_F11, TD_equal_F12 };

// Tap Dance Definitions
qk_tap_dance_action_t tap_dance_actions[] = {[TD_ESC_CAPS] = ACTION_TAP_DANCE_DOUBLE(KC_ESC, KC_CAPS), [TD_1_F1] = ACTION_TAP_DANCE_DOUBLE(KC_1, KC_F1), [TD_2_F2] = ACTION_TAP_DANCE_DOUBLE(KC_2, KC_F2), [TD_3_F3] = ACTION_TAP_DANCE_DOUBLE(KC_3, KC_F3), [TD_4_F4] = ACTION_TAP_DANCE_DOUBLE(KC_4, KC_F4), [TD_5_F5] = ACTION_TAP_DANCE_DOUBLE(KC_5, KC_F5), [TD_6_F6] = ACTION_TAP_DANCE_DOUBLE(KC_6, KC_F6), [TD_7_F7] = ACTION_TAP_DANCE_DOUBLE(KC_7, KC_F7), [TD_8_F8] = ACTION_TAP_DANCE_DOUBLE(KC_8, KC_F8), [TD_9_F9] = ACTION_TAP_DANCE_DOUBLE(KC_9, KC_F9), [TD_0_F10] = ACTION_TAP_DANCE_DOUBLE(KC_0, KC_F10), [TD_minus_F11] = ACTION_TAP_DANCE_DOUBLE(KC_MINS, KC_F11), [TD_equal_F12] = ACTION_TAP_DANCE_DOUBLE(KC_EQL, KC_F12)};

// clang-format off
// Key symbols are based on QMK. Use them to remap your keyboard
/*
* Layer BASE
* ,-----------------------------------------------------------------------------------------.
* | esc |  1  |  2  |  3  |  4  |  5  |  6  |  7  |  8  |  9  |  0  |  -  |  =  |    Bksp   |
* |-----------------------------------------------------------------------------------------+
* | Tab    |  q  |  w  |  e  |  r  |  t  |  y  |  u  |  i  |  o  |  p  |  [  |  ]  |   \    |
* |-----------------------------------------------------------------------------------------+
* | Caps    |  a  |  s  |  d  |  f  |  g  |  h  |  j  |  k  |  l  |  ;  |  '  |    Enter    |
* |-----------------------------------------------------------------------------------------+
* | Shift      |  z  |  x  |  c  |  v  |  b  |  n  |  m  |  ,  |  .  |  /  |    Shift       |
* |-----------------------------------------------------------------------------------------+
* | Ctrl  |  L1   |  Alt  |               space (FN1)       |  Alt  |  FN1  |  FN2  | Ctrl  |
* \-----------------------------------------------------------------------------------------/
* Layer TAP in BASE
* ,-----------------------------------------------------------------------------------------.
* |     |     |     |     |     |     |     |     |     |     |     |     |     |           |
* |-----------------------------------------------------------------------------------------+
* |        |     |     |     |     |     |     |     |     |     |     |     |     |        |
* |-----------------------------------------------------------------------------------------+
* |         |     |     |     |     |     |     |     |     |     |     |     |             |
* |-----------------------------------------------------------------------------------------+
* |            |     |     |     |     |     |     |     |     |     |     |       UP       |
* |-----------------------------------------------------------------------------------------+
* |       |       |       |                                 |       |  LEFT | DOWN  | RIGHT |
* \-----------------------------------------------------------------------------------------/
*/
 const uint16_t keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
 [BASE] = LAYOUT_60_ansi( /* Base */
        TD(TD_ESC_CAPS), KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, KC_BSPC,
        KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_RBRC, KC_BSLS,
        LT(1, KC_CAPS), KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_ENT,
        KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, RSFT_T(KC_UP),
        KC_LCTL, KC_LGUI, KC_LALT, LT(1, KC_SPC), KC_RALT, LT(1, KC_LEFT), LT(2, KC_DOWN), LT(3,KC_RGHT)),
  /*
  * Layer FN1
  * ,-----------------------------------------------------------------------------------------.
  * |  `  |  F1 |  F2 |  F3 |  F4 |  F5 |  F6 |  F7 |  F8 |  F9 | F10 | F11 | F12 |  DELETE   |
  * |-----------------------------------------------------------------------------------------+
  * | Tab    |     | UP  |     |     |     |     |     |     |     | PS | HOME | END |        |
  * |-----------------------------------------------------------------------------------------+
  * | Esc     |LEFT |DOWN |RIGHT|     |     | RGB_T | RGB_M- | RGB_M+| l | PGDN | PGUP | Enter|
  * |-----------------------------------------------------------------------------------------+
  * | Shift      |MUTE|V-DWN|V-UP |  <<  |  PP  |  >>  |     |     |INSRT| DEL |   Shift      |
  * |-----------------------------------------------------------------------------------------+
  * | Ctrl  |  L1   |  Alt  |               space             |  Alt  |  FN1  |  FN2  | Ctrl  |
  * \-----------------------------------------------------------------------------------------/
  *
  */
 [FN1] = LAYOUT_60_ansi( /* FN1 */
        KC_GRV, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_DEL,
        KC_NO, KC_NO, KC_UP, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_PSCR, KC_HOME, KC_END, KC_NO,
        KC_NO, KC_LEFT, KC_DOWN, KC_RGHT, KC_NO, KC_NO, RGB_TOG, RGB_RMOD, RGB_MOD, KC_NO, KC_PGDN, KC_PGUP, KC_NO,
        KC_NO, KC_MUTE, KC_VOLD, KC_VOLU, KC_MPRV, KC_MPLY, KC_MNXT, KC_NO, KC_NO, KC_INS, KC_DEL, KC_NO,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, MO(2), KC_NO),
\
   /*
  * Layer FN2
  * ,-----------------------------------------------------------------------------------------.
  * | RESET | BT1 | BT2 | BTD |     |     |     |     |     |     |     |    |    |  DELETE   |
  * |-----------------------------------------------------------------------------------------+
  * | Tab    |     | UP  |     |     |     |     |     |     |     |     |   |   |            |
  * |-----------------------------------------------------------------------------------------+
  * | Esc     |LEFT |DOWN |RIGHT|    |     |     |     |     |     |     |           | Enter  |
  * |-----------------------------------------------------------------------------------------+
  * | Shift      |   |    |     |     |     |     |     |     |      |         |   Shift      |
  * |-----------------------------------------------------------------------------------------+
  * | Ctrl  |  L1   |  Alt  |               space             |  Alt  |  FN1  |  FN2  | Ctrl  |
  * \-----------------------------------------------------------------------------------------/
  *
  */
 [FN2] = LAYOUT_60_ansi( /* FN2 */
        RESET, KC_AP2_BT1, KC_AP2_BT2, KC_AP2_BT_UNPAIR, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS,
        KC_TRNS, KC_NO, KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_PSCR, KC_HOME, KC_END, KC_NO,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_PGDN, KC_PGUP, KC_TRNS,
        KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_INS, KC_NO, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, MO(2), KC_TRNS),
};
// clang-format on

// Keyboard INIT
void keyboard_post_init_user(void) {
    // rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_REACTIVE_MULTINEXUS);
    rgb_matrix_enable_noeeprom();
    rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_COLOR);
    rgb_matrix_set_color_all(1, 1, 1);
    rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_REACTIVE_MULTINEXUS);
}

// CAPS LOCK INDICATION
void rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    if (host_keyboard_led_state().caps_lock) {
        for (uint8_t i = led_min; i <= led_max; i++) {
            if (g_led_config.flags[i] & LED_FLAG_KEYLIGHT) {
                rgb_matrix_set_color(i, RGB_RED);
            }
        }
    }
}

// LAYER INDICATION
void rgb_matrix_indicators_user(void) {
    switch (biton32(layer_state)) {
        case FN1:
            // Set keys 53 to 60 to green
            for (int i = 53; i <= 60; i++) {
                rgb_matrix_set_color(i, 0, 255, 0);
            }
            break;
        case FN2:
            // Set keys 53 to 60 to red
            for (int i = 53; i <= 60; i++) {
                rgb_matrix_set_color(i, 255, 0, 0);
            }
            break;
        case BASE:
            // rgb_matrix_set_color(56, 255, 255, 255);
            break;
    }
}
