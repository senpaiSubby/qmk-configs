//  _______  __   __  _______  _______  __   __
// |       ||  | |  ||  _    ||  _    ||  | |  |
// |  _____||  | |  || |_|   || |_|   ||  |_|  |
// | |_____ |  |_|  ||       ||       ||       |
// |_____  ||       ||  _   | |  _   | |_     _|
//  _____| ||       || |_|   || |_|   |  |   |
// |_______||_______||_______||_______|  |___|

#include QMK_KEYBOARD_H

// RGB KEY NUMBERS
// clang-format off
enum {
    key_esc, key_1, key_2, key_3, key_4, key_5, key_6, key_7, key_8, key_9, key_0, key_minus, key_plus, key_backspace,
    key_tab, key_q, key_w, key_e, key_r, key_t, key_y, key_u, key_i, key_o, key_p, key_lbracket, key_rbracket, key_bslash,
    key_caps, key_a, key_s, key_d, key_f, key_g, key_h, key_j, key_k, key_l, key_semi, key_quote, key_enter,
    key_lshift, key_z, key_x, key_c, key_v, key_b, key_n, key_m, key_comma, key_period, key_fslash, key_rshift,
    key_lctrl, key_win, key_lalt, key_space, key_ralt, key_green, key_red, key_purple

};
// clang-format on

/*
 *  _____ _   ___   ___   _   _  _  ___ ___ _  _  ___
 * |_   _/_\ | _ \ |   \ /_\ | \| |/ __|_ _| \| |/ __|
 *   | |/ _ \|  _/ | |) / _ \| .` | (__ | || .` | (_ |
 *   |_/_/ \_\_|   |___/_/ \_\_|\_|\___|___|_|\_|\___|
 */

// clang-format off
enum { TD_ESC_TILD, TD_ESC_L0 };
qk_tap_dance_action_t tap_dance_actions[] = {
        [TD_ESC_TILD] = ACTION_TAP_DANCE_DOUBLE(KC_ESC, KC_TILD),
        [TD_ESC_L0] = ACTION_TAP_DANCE_DOUBLE(KC_ESC, TO(0))
    };
// clang-format on

/*
 *  _  __
 * | |/ /___ _  _ _ __  __ _ _ __ ___
 * | ' </ -_) || | '  \/ _` | '_ (_-<
 * |_|\_\___|\_, |_|_|_\__,_| .__/__/
 *           |__/           |_|
 */

enum anne_pro_layers { BASE, BASIC, HELPER, MOUSE, GAMING };

// clang-format off
 const uint16_t keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
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
* | Ctrl  |  L1   |  Alt  |        space (BASIC)       |  Alt  |  BASIC  |  HELPER  | Ctrl  |
* \-----------------------------------------------------------------------------------------/
* Layer TAP in BASE
* ,-----------------------------------------------------------------------------------------.
* |  ~  |     |     |     |     |     |     |     |     |     |     |     |     |           |
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
 [BASE] = LAYOUT_60_ansi( /* Base */
        TD(TD_ESC_TILD), KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, KC_BSPC,
        KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_RBRC, KC_BSLS,
        KC_CAPS, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_ENT,
        KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, RSFT_T(KC_UP),
        KC_LCTL, KC_LGUI, KC_LALT, LT(1, KC_SPC), KC_RALT, LT(1, KC_LEFT), LT(2, KC_DOWN), LT(3,KC_RGHT)),
  /*
  * Layer BASIC
  * ,-----------------------------------------------------------------------------------------.
  * |  `  |  F1 |  F2 |  F3 |  F4 |  F5 |  F6 |  F7 |  F8 |  F9 | F10 | F11 | F12 |  DELETE   |
  * |-----------------------------------------------------------------------------------------+
  * | Tab    |PGDN| UP  |PGUP  |     |     |     |     |     |     | PS | HOME | END |        |
  * |-----------------------------------------------------------------------------------------+
  * | Esc     |LEFT |DOWN |RIGHT|     |     | RGB_T | RGB_M- | RGB_M+| l |      |      | Enter|
  * |-----------------------------------------------------------------------------------------+
  * | Shift      |MUTE|V-DWN|V-UP |  <<  |  PP  |  >>  |     |     |INSRT| DEL |   Shift      |
  * |-----------------------------------------------------------------------------------------+
  * | Ctrl  |  L1   |  Alt  |            space          |  Alt  |  BASIC  |  HELPER  | MOUSE  |
  * \-----------------------------------------------------------------------------------------/
  *
  */
 [BASIC] = LAYOUT_60_ansi( /* BASIC */
        KC_GRV, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_DEL,
        KC_NO, KC_PGDN, KC_UP, KC_PGUP, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_PSCR, KC_HOME, KC_END, KC_NO,
        KC_NO, KC_LEFT, KC_DOWN, KC_RGHT, KC_NO, KC_NO, RGB_TOG, RGB_RMOD, RGB_MOD, KC_NO, KC_NO, KC_NO, KC_ENT,
        KC_NO, KC_MUTE, KC_VOLD, KC_VOLU, KC_MPRV, KC_MPLY, KC_MNXT, KC_NO, KC_NO, KC_INS, KC_DEL, KC_TRNS,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS, KC_TRNS, KC_TRNS),

   /*
  * Layer HELPER
  * ,-----------------------------------------------------------------------------------------.
  * | esc | BT1 | BT2 | BTD |     |     |     |     |     |     |     |    |    |    RESET    |
  * |-----------------------------------------------------------------------------------------+
  * | Tab    | DESK-L| MAXIMIZE | DESK-R |    |     |    |    |     |     |     |   |   |     |
  * |-----------------------------------------------------------------------------------------+
  * | Esc     | SNAP-L |DOWN | SNAP-R|    |     |     |     |     |     |    |       | Enter  |
  * |-----------------------------------------------------------------------------------------+
  * | Shift      |   |    |     |     |     |     |     |     |      |         |   Shift      |
  * |-----------------------------------------------------------------------------------------+
  * | Ctrl  |  L1   |  Alt  |             esc            |  Alt  |  BASIC  |  HELPER  | Ctrl  |
  * \-----------------------------------------------------------------------------------------/
  *
  */
 [HELPER] = LAYOUT_60_ansi( /* HELPER */
        KC_ESC, KC_AP2_BT1, KC_AP2_BT2, KC_AP2_BT_UNPAIR, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, RESET,
        KC_TRNS, KC_NO, LGUI(KC_UP), KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_PSCR, KC_HOME, KC_END, KC_NO,
        KC_TRNS, LGUI(KC_LEFT), LGUI(KC_DOWN), LGUI(KC_RIGHT), KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_PGDN, KC_PGUP, KC_TRNS,
        KC_TRNS, KC_F13, KC_NO, KC_F14, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_INS, KC_NO, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_ESC, KC_TRNS, TO(4), KC_TRNS, TO(3)),

   /*
  * Layer MOUSE
  * ,-----------------------------------------------------------------------------------------.
  * | esc | BT1 | BT2 | BTD |     |     |     |     |     |     |     |    |    |    RESET    |
  * |-----------------------------------------------------------------------------------------+
  * | Tab    |MOUSE-RC| MOUSE-U |MOUSE-LC|    |    |    |    |     |     |     |   |   |      |
  * |-----------------------------------------------------------------------------------------+
  * | Esc     | MOUSE-L |MOUSE-D | MOUSE-R|    |    |    |    |    |    |    |       | Enter  |
  * |-----------------------------------------------------------------------------------------+
  * | Shift      |   |    |     |     |     |     |     |     |      |         |   Shift      |
  * |-----------------------------------------------------------------------------------------+
  * | Ctrl  |  L1   |  Alt  |              esc           |  Alt  |  BASIC  |  HELPER  | Ctrl  |
  * \-----------------------------------------------------------------------------------------/
  *
  */
 [MOUSE] = LAYOUT_60_ansi( /* MOUSE */
        KC_ESC, KC_ACL0, KC_ACL1, KC_ACL2, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, RESET,
        KC_TRNS, KC_BTN2, KC_MS_U, KC_BTN1, KC_NO, KC_MS_U, KC_NO, KC_NO, KC_NO, KC_NO, KC_PSCR, KC_HOME, KC_END, KC_NO,
        KC_TRNS, KC_MS_L, KC_MS_D, KC_MS_R, KC_MS_L, KC_MS_D, KC_MS_R, KC_NO, KC_NO, KC_NO, KC_PGDN, KC_PGUP, KC_TRNS,
        KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_INS, KC_NO, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_ESC, KC_TRNS, TO(0), TO(0), TO(0)),
/*
* Layer GAMING
* ,-----------------------------------------------------------------------------------------.
* | esc |  1  |  2  |  3  |  4  |  5  |  6  |  7  |  8  |  9  |  0  |  -  |  =  |    Bksp   |
* |-----------------------------------------------------------------------------------------+
* | Tab    |  q  |  w  |  e  |  r  |  t  |  y  |  u  |  i  |  o  |  p  |  [  |  ]  |   \    |
* |-----------------------------------------------------------------------------------------+
* | Caps    |  a  |  s  |  d  |  f  |  g  |  h  |  j  |  k  |  l  |  ;  |  '  |    Enter    |
* |-----------------------------------------------------------------------------------------+
* | Shift      |  z  |  x  |  c  |  v  |  b  |  n  |  m  |  ,  |  .  |  /  |    Shift       |
* |-----------------------------------------------------------------------------------------+
* | Ctrl  |  L1   |  Alt  |           space            |  Alt  |  BASIC  |  HELPER  | Ctrl  |
* \-----------------------------------------------------------------------------------------/
*/
 [GAMING] = LAYOUT_60_ansi( /* GAMING */
        TD(TD_ESC_L0), KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, KC_BSPC,
        KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_RBRC, KC_BSLS,
        KC_CAPS, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_ENT,
        KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, RSFT_T(KC_UP),
        KC_LCTL, KC_LGUI, KC_LALT, KC_SPC, KC_RALT, TO(0), LT(2, KC_DOWN), LT(3,KC_RGHT)),
};
// clang-format on

/*
 *  ___  ___ ___   __  __   _ _____ ___ _____  __
 * | _ \/ __| _ ) |  \/  | /_\_   _| _ \_ _\ \/ /
 * |   / (_ | _ \ | |\/| |/ _ \| | |   /| | >  <
 * |_|_\\___|___/ |_|  |_/_/ \_\_| |_|_\___/_/\_\
 */

void keyboard_pre_init_user(void) {}

void keyboard_post_init_user(void) {
    rgb_matrix_set_color_all(1, 1, 1);
    rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_REACTIVE_MULTINEXUS);
}

// CAPS LOCK INDICATION
void rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    if (host_keyboard_led_state().caps_lock) {
        rgb_matrix_set_color(key_caps, RGB_RED);
    }
}

// LAYER INDICATION
void rgb_matrix_indicators_user(void) {
    switch (biton32(layer_state)) {
        case GAMING:
            rgb_matrix_set_color(key_space, RGB_TEAL);
            rgb_matrix_set_color(key_w, RGB_TEAL);
            rgb_matrix_set_color(key_a, RGB_TEAL);
            rgb_matrix_set_color(key_s, RGB_TEAL);
            rgb_matrix_set_color(key_d, RGB_TEAL);

            rgb_matrix_set_color(key_1, RGB_CORAL);
            rgb_matrix_set_color(key_2, RGB_CORAL);
            rgb_matrix_set_color(key_3, RGB_RED);
            rgb_matrix_set_color(key_4, RGB_ORANGE);
            rgb_matrix_set_color(key_5, RGB_GOLDENROD);

            rgb_matrix_set_color(key_q, RGB_MAGENTA);

            rgb_matrix_set_color(key_e, RGB_GREEN);
            rgb_matrix_set_color(key_r, RGB_RED);
            rgb_matrix_set_color(key_f, RGB_CORAL);
            rgb_matrix_set_color(key_t, RGB_RED);
            rgb_matrix_set_color(key_y, RGB_CORAL);
            rgb_matrix_set_color(key_x, RGB_TURQUOISE);
            rgb_matrix_set_color(key_z, RGB_CHARTREUSE);

            break;
        case MOUSE:
            rgb_matrix_set_color(key_space, RGB_PURPLE);

            break;
        case HELPER:
            rgb_matrix_set_color(key_space, RGB_RED);

            rgb_matrix_set_color(42, 88, 101, 242);
            rgb_matrix_set_color(44, 88, 101, 242);

            break;
        case BASIC:
            rgb_matrix_set_color(key_space, RGB_GREEN);
            rgb_matrix_set_color(key_g, RGB_RED);
            rgb_matrix_set_color(key_z, RGB_RED);
            rgb_matrix_set_color(key_x, RGB_GOLD);
            rgb_matrix_set_color(key_c, RGB_GREEN);
            rgb_matrix_set_color(key_w, RGB_TEAL);
            rgb_matrix_set_color(key_a, RGB_TEAL);
            rgb_matrix_set_color(key_s, RGB_TEAL);
            rgb_matrix_set_color(key_d, RGB_TEAL);

            break;
        case BASE:
            break;
    }
}
