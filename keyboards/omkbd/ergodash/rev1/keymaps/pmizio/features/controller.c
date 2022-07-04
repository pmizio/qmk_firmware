#include "controller.h"
#include "utils/led.h"

uint8_t current_os = WINDOWS;

void process_controller_rawhid(uint8_t *data, uint8_t length) {
  if (length > 1 && data[0] == 1) {
    uint8_t command_id = data[1];
    uint8_t *command_data = &(data[2]);

    switch(command_id) {
      case MSG_PING: {
        current_os = *command_data;
        break;
      }
      case MSG_SET_LED_MODE: {
        led_set_mode(*command_data);
        break;
      }
      case MSG_SET_LED_HSV: {
        led_sethsv_state(command_data[0], command_data[1], command_data[2]);
        break;
      }
    }
  }
}

bool process_os_modifiers(uint16_t keycode, keyrecord_t* record) {
  if (current_os == OSX) {
    if(!process_rewrite_keycode(keycode, record, KC_LCTRL, KC_LGUI)) {
        return false;
    }

    if(!process_rewrite_keycode(keycode, record, KC_LGUI, KC_LCTRL)) {
        return false;
    }
  }

  return true;
}

bool process_rewrite_keycode(uint16_t keycode, keyrecord_t* record, uint16_t keycode_in, uint16_t keycode_out) {
    if (keycode == keycode_in) {
      if (record->event.pressed) {
        register_code(keycode_out);
      } else {
        unregister_code(keycode_out);
      }

      return false;
    }

    return true;
}

void set_os(uint8_t os) {
  switch (os) {
    case LINUX:
    case WINDOWS:
    case OSX:
      current_os = os;
      break;
    default:
      current_os = WINDOWS;
  }
}

void toggle_os(void) {
  switch (current_os) {
    case LINUX:
    case WINDOWS:
      current_os = OSX;
      break;
    case OSX:
      current_os = WINDOWS;
  }
}
