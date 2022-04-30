#include <stdint.h>
#include "annepro2.h"
#include "qmk_ap2_led.h"
#include "config.h"

enum anne_pro_layers {
    _BASE_LAYER,
    _FN1_LAYER,
    _FN2_LAYER,
};

const uint16_t keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE_LAYER] = KEYMAP(KC_ESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, KC_BSPC, KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_RBRC, KC_BSLS, LT(1, KC_CAPS), KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_ENT, KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT, KC_LCTL, KC_LGUI, KC_LALT, KC_SPC, KC_RALT, LT(1, KC_NO), LT(2, KC_NO), OSL(3)),

    [_FN1_LAYER] = KEYMAP(/* Base */
KC_GRV, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_DEL, KC_TRNS, KC_TRNS, KC_UP, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_PSCR, KC_HOME, KC_END, KC_TRNS, KC_TRNS, KC_LEFT, KC_DOWN, KC_RGHT, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_PGUP, KC_PGDN, KC_TRNS, KC_TRNS, KC_MUTE, KC_VOLD, KC_VOLU, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_INS, KC_DEL, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, MO(2), KC_TRNS),    [_FN2_LAYER] = KEYMAP(/* Base */
                          KC_GRV, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_DEL, KC_TRNS, KC_TRNS, KC_UP, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_PSCR, KC_HOME, KC_END, KC_TRNS, KC_TRNS, KC_LEFT, KC_DOWN, KC_RGHT, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_PGUP, KC_PGDN, KC_TRNS, KC_TRNS, KC_VOLU, KC_VOLD, KC_MUTE, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_INS, KC_DEL, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, MO(2), KC_TRNS),
};
const uint16_t keymaps_size = sizeof(keymaps);

void matrix_init_user(void) {}

void matrix_scan_user(void) {}

// Code to run after initializing the keyboard
void keyboard_post_init_user(void) {
    // Here are two common functions that you can use. For more LED functions, refer to the file "qmk_ap2_led.h"

    // annepro2-shine disables LEDs by default. Uncomment this function to enable them at startup.
    annepro2LedEnable();

    // Additionally, it also chooses the first LED profile by default. Refer to the "profiles" array in main.c in
    // annepro2-shine to see the order. Replace "i" with the index of your preferred profile. (i.e the RED profile is index 0)
    annepro2LedSetProfile(0);
}

layer_state_t layer_state_set_user(layer_state_t layer) {
    switch (get_highest_layer(layer)) {
        case _FN1_LAYER:
            // Set the leds to green
            annepro2LedSetForegroundColor(0x00, 0xFF, 0x00);
            break;
        case _FN2_LAYER:
            // Set the leds to red
            annepro2LedSetForegroundColor(0xFF, 0x00, 0x00);
            break;
        default:
            // Reset back to the current profile
            annepro2LedResetForegroundColor();
            break;
    }
    return layer;
}

// The function to handle the caps lock logic
// It's called after the capslock changes state or after entering layers 1 and 2.
bool led_update_user(led_t leds) {
    if (leds.caps_lock) {
        // Set the caps-lock to red
        const annepro2Led_t color = {.p.red = 0xff, .p.green = 0x00, .p.blue = 0x00, .p.alpha = 0xff};

        annepro2LedMaskSetKey(2, 0, color);
        /* NOTE: Instead of colouring the capslock only, you can change the whole
           keyboard with annepro2LedSetForegroundColor */
    } else {
        // Reset the capslock if there is no layer active
        if (!layer_state_is(_FN1_LAYER) && !layer_state_is(_FN2_LAYER)) {
            const annepro2Led_t color = {.p.red = 0xff, .p.green = 0x00, .p.blue = 0x00, .p.alpha = 0x00};
            annepro2LedMaskSetKey(2, 0, color);
        }
    }

    return true;
}
