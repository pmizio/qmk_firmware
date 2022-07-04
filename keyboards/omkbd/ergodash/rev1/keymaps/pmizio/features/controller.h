#pragma once

#include QMK_KEYBOARD_H

#define MSG_PING         0x00
#define MSG_SET_LED_MODE 0x01
#define MSG_SET_LED_HSV  0x02

#define LINUX   0x00
#define WINDOWS 0x01
#define OSX     0x02

void process_controller_rawhid(uint8_t *data, uint8_t length);
bool process_rewrite_keycode(uint16_t keycode, keyrecord_t* record, uint16_t keycode_in, uint16_t keycode_out);
bool process_os_modifiers(uint16_t keycode, keyrecord_t* record);
void toggle_os(void);
