// Copyright 2025 Junya
// SPDX-License-Identifier: MIT

#include "quantum.h"

bool process_record_kb(uint16_t keycode, keyrecord_t *record) {
    if (!process_record_user(keycode, record)) {
        return false;
    }
    return true;
}

void matrix_scan_kb(void) {
    static bool last_state = false;
    bool current_state = !gpio_read_pin(GP1); // Active low
    
    if (current_state != last_state) {
        if (current_state) {
            tap_code(KC_MUTE);
        }
        last_state = current_state;
    }
    
    matrix_scan_user();
}

void keyboard_pre_init_kb(void) {
    gpio_set_pin_input_high(GP1);
    keyboard_pre_init_user();
}