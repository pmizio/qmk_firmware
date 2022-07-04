#include "led.h"

uint32_t mem_mode;
uint16_t mem_hue;
uint8_t mem_sat;
uint8_t mem_val;

void led_save_state(void) {
#ifdef RGBLIGHT_ENABLE
  mem_mode = rgblight_get_mode();
  mem_hue = rgblight_get_hue();
  mem_sat = rgblight_get_sat();
  mem_val = rgblight_get_val();
#endif // RGBLIGHT_ENABLE
}

void led_restore_state(void) {
#ifdef RGBLIGHT_ENABLE
  rgblight_mode_noeeprom(mem_mode);
  rgblight_sethsv_noeeprom(mem_hue, mem_sat, mem_val);
#endif // RGBLIGHT_ENABLE
}

void led_sethsv_tmp_state(uint16_t hue, uint8_t sat, uint8_t val) {
#ifdef RGBLIGHT_ENABLE
  rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_LIGHT);
  rgblight_sethsv_noeeprom(hue, sat, val);
#endif // RGBLIGHT_ENABLE
}

void led_set_mode(uint8_t mode) {
#ifdef RGBLIGHT_ENABLE
  rgblight_mode(mode);
#endif // RGBLIGHT_ENABLE
}

void led_set_tmp_mode(uint8_t mode) {
#ifdef RGBLIGHT_ENABLE
  rgblight_mode_noeeprom(mode);
#endif // RGBLIGHT_ENABLE
}

void led_sethsv_state(uint16_t hue, uint8_t sat, uint8_t val) {
#ifdef RGBLIGHT_ENABLE
  rgblight_sethsv(hue, sat, val);
#endif // RGBLIGHT_ENABLE
}
