// Copyright 2025 Junya
// SPDX-License-Identifier: MIT

#include QMK_KEYBOARD_H

#ifdef OLED_ENABLE
bool oled_task_user(void) {
    oled_write_P(PSTR("JunyaPad\n"), false);
    oled_write_P(PSTR("Layer: "), false);
    oled_write_P(PSTR("0\n"), false);
    return false;
}
#endif

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * ┌───┬───┬───┐
     * │ A │ B │ C │
     * ├───┼───┼───┤
     * │ D │ E │ F │
     * └───┴───┴───┘
     */
    [0] = LAYOUT_ortho_2x3(
        KC_PAGE_UP,    KC_UP,    KC_PAGE_DOWN,
        KC_LEFT,    KC_DOWN,    KC_RIGHT
    )
};
