// Layers live in keymap.json; this file only adds lighting behaviour.
#include QMK_KEYBOARD_H

// Terminal-phosphor green: HSV_GREEN (85) nudged toward yellow, fully saturated
// (any desaturation mixes in blue and reads as emerald).
#define KEY_HUE 78
#define KEY_SAT 255
// Capped by RGB_MATRIX_MAXIMUM_BRIGHTNESS (config.h).
#define KEY_VAL 200
// Lower = slower fade after a keypress (default 128).
#define FADE_SPEED 48

void keyboard_post_init_user(void) {
    // Applied at every boot without touching EEPROM, so whatever mode was saved
    // before (e.g. the rainbow) can't come back.
    rgb_matrix_enable_noeeprom();
    rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_REACTIVE_SIMPLE);
    rgb_matrix_sethsv_noeeprom(KEY_HUE, KEY_SAT, KEY_VAL);
    rgb_matrix_set_speed_noeeprom(FADE_SPEED);
    // Per-key LEDs only; underglow stays off.
    rgb_matrix_set_flags_noeeprom(LED_FLAG_KEYLIGHT);
}

bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    // Keep the non-grid keys dark: matrix rows 4 (left) and 9 (right) hold the
    // three thumb keys and the angled inner key on each half.
    static const uint8_t dark_rows[] = {4, 9};
    for (uint8_t i = 0; i < ARRAY_SIZE(dark_rows); i++) {
        for (uint8_t col = 0; col < MATRIX_COLS; col++) {
            uint8_t led = g_led_config.matrix_co[dark_rows[i]][col];
            if (led != NO_LED && led >= led_min && led < led_max) {
                rgb_matrix_set_color(led, RGB_OFF);
            }
        }
    }
    return false;
}
