#pragma once

#include QMK_KEYBOARD_H

void led_save_state(void);
void led_restore_state(void);
void led_sethsv_tmp_state(uint16_t hue, uint8_t sat, uint8_t val);
void led_set_mode(uint8_t mode);
void led_set_tmp_mode(uint8_t mode);
void led_sethsv_state(uint16_t hue, uint8_t sat, uint8_t val);
