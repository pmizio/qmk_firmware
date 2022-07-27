 /* Balnk Layer
   * ,----------------------------------------------------------------------------------------------------------------------.
   * |      |      |      |      |      |      |      |                    |      |      |      |      |      |      |      |
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |                    |      |      |      |      |      |      |      |
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |                    |      |      |      |      |      |      |      |
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |      |      |      |      |      |      |      |      |      |      |
   * |-------------+------+------+------+------+      +------+------+------+      +------+------+------+------+-------------|
   * |      |      |      |      ||||||||      |      |      ||||||||      |      |      ||||||||      |      |      |      |
   * ,----------------------------------------------------------------------------------------------------------------------.

  [_BLANK] = LAYOUT(
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                         XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                         XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                         XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX,       XXXXXXX,          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX, XXXXXXX, XXXXXXX,       XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
  ),
*/

#include QMK_KEYBOARD_H
#include "raw_hid.h"

#include "features/controller.h"
#include "utils/led.h"

#define _QWERTY  0
#define _GAMING  1
#define _LOWER   2
#define _RAISE   3
#define _ADJUST  16

enum custom_keycodes {
  OS = SAFE_RANGE,
  TARROW, // ->
  FARROW, // =>
  DDASH,  // --
  TEQ,    // ===
};

#define QWERTY  DF(_QWERTY)
#define GAMING  DF(_GAMING)
#define RAISE   MO(_RAISE)
#define LOWER   MO(_LOWER)

// Left-hand home row mods
#define GUI_A LGUI_T(KC_A)
#define ALT_S RALT_T(KC_S)
#define CTL_D LCTL_T(KC_D)
#define SFT_F LSFT_T(KC_F)

// Right-hand home row mods
#define SFT_J RSFT_T(KC_J)
#define CTL_K RCTL_T(KC_K)
#define ALT_L RALT_T(KC_L)
#define GUI_SCLN RGUI_T(KC_SCLN)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /* Qwerty
   * ,----------------------------------------------------------------------------------------------------------------------.
   * |     |      |      |      |      |      |      |                    |      |      |      |      |      |      |       |
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * | Tab  |   Q  |   W  |   E  |   R  |   T  |      |                    |      |   Y  |   U  |   I  |   O  |   P  |  \   |
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * |      | A(G) | S(A) | D(C) | F(S) |   G  |      |                    |      |   H  | J(S) | K(C) | L(A) | ;(G) |  "   |
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * |      |   Z  |   X  |   C  |   V  |   B  |      |      |      |      |      |   N  |   M  |   ,  |   .  |   /  |      |
   * |-------------+------+------+------+------+ Space+------+------+------+ Enter+------+------+------+------+-------------|
   * |      |      |      | Bksp |||||||| Lower|      |      ||||||||      |      | Raise|||||||| Esc  |      |      |      |
   * ,----------------------------------------------------------------------------------------------------------------------.
   */
  [_QWERTY] = LAYOUT(
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX,                        XXXXXXX,    XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX,
    KC_TAB,  KC_Q,    KC_W,    KC_E,     KC_R,    KC_T,    XXXXXXX,                        XXXXXXX,    KC_Y,     KC_U,    KC_I,    KC_O,     KC_P,    KC_BSLS,
    CAPSWRD, GUI_A,   ALT_S,   CTL_D,    SFT_F,   KC_G,    XXXXXXX,                        XXXXXXX,    KC_H,     SFT_J,   CTL_K,   ALT_L,    GUI_SCLN,KC_QUOT,
    XXXXXXX, KC_Z,    KC_X,    KC_C,     KC_V,    KC_B,            XXXXXXX,        XXXXXXX,            KC_N,     KC_M,    KC_COMM, KC_DOT,   KC_SLSH, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, KC_BSPC,           LOWER,   KC_SPC, XXXXXXX,        XXXXXXX,KC_ENT,     RAISE,             KC_ESC,  XXXXXXX,  XXXXXXX, XXXXXXX
  ),

  /* Gaming
   * ,----------------------------------------------------------------------------------------------------------------------.
   * | ESC  |   1  |   2  |   3  |   4  |   5  |      |                    |      |   6  |   7  |   8  |   9  |   0  | Bksp |
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * | Tab  |   Q  |   W  |   E  |   R  |   T  |      |                    |      |   Y  |   U  |   I  |   O  |   P  |  \   |
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * | Ctrl |   A  |   S  |   D  |   F  |   G  |      |                    |      |   H  |   J  |   K  |   L  |   ;  |  "   |
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * | Shift|   Z  |   X  |   C  |   V  |   B  |      |      |      |      |      |   N  |   M  |   ,  |   .  |   /  | Shift|
   * |-------------+------+------+------+------+ Space+------+------+------+ Enter+------+------+------+------+-------------|
   * |      |  GUI |      | Lower||||||||  Alt |      |      ||||||||      |      | Raise|||||||| RAlt |      |      |      |
   * ,----------------------------------------------------------------------------------------------------------------------.
   */
  [_GAMING] = LAYOUT(
    KC_ESC,  KC_1,    KC_2,    KC_3,     KC_4,    KC_5,    XXXXXXX,                        XXXXXXX,    KC_6,     KC_7,    KC_8,    KC_9,     KC_0,    XXXXXXX,
    KC_TAB,  KC_Q,    KC_W,    KC_E,     KC_R,    KC_T,    XXXXXXX,                        XXXXXXX,    KC_Y,     KC_U,    KC_I,    KC_O,     KC_P,    KC_BSLS,
    KC_LCTL, KC_A,    KC_S,    KC_D,     KC_F,    KC_G,    XXXXXXX,                        XXXXXXX,    KC_H,     KC_J,    KC_K,    KC_L,     KC_SCLN, KC_QUOT,
    KC_LSFT, KC_Z,    KC_X,    KC_C,     KC_V,    KC_B,            XXXXXXX,        XXXXXXX,            KC_N,     KC_M,    KC_COMM, KC_DOT,   KC_SLSH, KC_RSFT,
    XXXXXXX, KC_LGUI, XXXXXXX, LOWER,           KC_LALT,   KC_SPC, KC_BSPC,        XXXXXXX,KC_ENT,     RAISE,             KC_RALT, XXXXXXX,  XXXXXXX, XXXXXXX
  ),
  
  /* Lower
   * ,----------------------------------------------------------------------------------------------------------------------.
   * |      |      |      |      |      |      |      |                    |      |      |      |      |      |      |      |
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * |      |   1  |   2  |   3  |   4  |   5  |      |                    |      |   6  |   7  |   8  |   9  |   0  |      |
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * |      |  GUI |  Alt | Ctrl | Shift|      |      |                    |      | Left | Down |  Up  |Right |      |      |
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |      |      |      |      |      |      |      |      |      |      |
   * |-------------+------+------+------+------+ Space+------+------+------+ Enter+------+------+------+------+-------------|
   * |      |      |      |      ||||||||      |      |      ||||||||      |      |      ||||||||      |      |      |      |
   * ,----------------------------------------------------------------------------------------------------------------------.
   */
  [_LOWER] = LAYOUT(
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                         XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    XXXXXXX,                         XXXXXXX, KC_6,    KC_8,    KC_8,    KC_9,    KC_0,    XXXXXXX,
    XXXXXXX, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, XXXXXXX, XXXXXXX,                         XXXXXXX, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX,       XXXXXXX,          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          _______, _______, _______,       XXXXXXX, _______, _______,          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
  ),

  /* Raise
   * ,----------------------------------------------------------------------------------------------------------------------.
   * |      |      |      |      |      |      |      |                    |      |      |      |      |      |      |      |
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * |  `   |  !   |  @   |  #   |  $   |  %   |      |                    |      |  ^   |  &   |  *   |  === |      |      |
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * |  ~   |  [   |  ]   |  (   |  )   |      |      |                    |      |  =>  |  =   |  -   |      |      |      |
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * |      |      |      |  {   |  }   |      |      |      |      |      |      |  ->  |  +   |  --  |      |      |      |
   * |-------------+------+------+------+------+  _   +------+------+------+      +------+------+------+------+-------------|
   * |      |      |      |      ||||||||      |      |      ||||||||      |      |      ||||||||      |      |      |      |
   * ,----------------------------------------------------------------------------------------------------------------------.
   */
  [_RAISE] = LAYOUT(
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                         XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    KC_GRV,  KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, XXXXXXX,                         XXXXXXX, KC_CIRC, KC_AMPR, KC_ASTR, TEQ,     XXXXXXX, XXXXXXX,
    KC_TILD, KC_LBRC, KC_RBRC, KC_LPRN, KC_RPRN, XXXXXXX, XXXXXXX,                         XXXXXXX, FARROW,  KC_EQL,  KC_MINS, XXXXXXX, XXXXXXX, XXXXXXX,
    _______, XXXXXXX, XXXXXXX, KC_LCBR, KC_RCBR, XXXXXXX,          XXXXXXX,       XXXXXXX,          TARROW,  KC_PLUS, DDASH,   XXXXXXX, XXXXXXX, XXXXXXX,
    _______, XXXXXXX, XXXXXXX, XXXXXXX,          KC_DEL,  _______, KC_UNDS,       XXXXXXX, _______, _______,          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
  ),

  /* Adjust
   * ,----------------------------------------------------------------------------------------------------------------------.
   * | Reset|      |      |      |      |      |      |                    |      |      |      |      |      |      |      |
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * | Reset|  F1  |  F2  |  F3  |  F4  |  F5  |      |                    |      |  F6  |  F7  |  F8  |  F9  |  F10 |  F11 |
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * |RGB TG| HUE+ | SAT+ | VAL+ |      |      |      |                    |      | BL TG|  BL+ |  BL- |      |      |  F12 |
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * | MODE | HUE- | SAT- | VAL- |      |      |      |      |      |      |      |      |      |      |      |      |      |
   * |-------------+------+------+------+------+      +------+------+------+      +------+------+------+------+-------------|
   * |      |      |      |      ||||||||      |      |      ||||||||      |      |      ||||||||      |      |      |      |
   * ,----------------------------------------------------------------------------------------------------------------------.
   */
  [_ADJUST] = LAYOUT(
    RESET,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    RESET,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   XXXXXXX,                       XXXXXXX, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
    RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, XXXXXXX, XXXXXXX, XXXXXXX,                       XXXXXXX, BL_TOGG, BL_INC,  BL_DEC,  XXXXXXX, XXXXXXX, KC_F12,
    RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD, XXXXXXX, XXXXXXX,          OS,          XXXXXXX,          XXXXXXX, GAMING,  QWERTY,  XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX, XXXXXXX, XXXXXXX,     XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
  )
};

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

void raw_hid_receive(uint8_t *data, uint8_t length) {
  process_controller_rawhid(data, length);
}

#ifdef RGBLIGHT_ENABLE
void layer_state_set_rgb_light(layer_state_t state) {
  switch(get_highest_layer(state)) {
    case _QWERTY:
      led_set_tmp_mode(RGBLIGHT_MODE_RAINBOW_SWIRL);
      break;
    case _LOWER:
      led_sethsv_tmp_state(HSV_RED);
      break;
    case _RAISE:
      led_sethsv_tmp_state(HSV_GREEN);
      break;
    case _ADJUST:
      led_sethsv_tmp_state(HSV_BLUE);
      break;
  }
}
#endif // RGBLIGHT_ENABLE

layer_state_t layer_state_set_user(layer_state_t state) {
  state = update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
  #ifdef RGBLIGHT_ENABLE
  layer_state_set_rgb_light(state);
  #endif // RGBLIGHT_ENABLE

  return state;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (!process_os_modifiers(keycode, record)) {
    return false;
  }

  if (record->event.pressed) {
    switch (keycode) {
      case OS:
        toggle_os();
        break;
      case TARROW:
        SEND_STRING("->");
        break;
      case FARROW:
        SEND_STRING("=>");
        break;
     case DDASH:
        SEND_STRING("--");
        break;
      case TEQ:
        SEND_STRING("===");
        break;
    }
  }
  return true;
}

#ifdef CAPS_WORD_ENABLE
void caps_word_set_user(bool active) {
  if (active) {
    led_save_state();
    led_sethsv_tmp_state(HSV_WHITE);
  } else {
    led_restore_state();
  }
}

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case GUI_A:
    case GUI_SCLN:
      return TAPPING_TERM + 20;
    default:
      return TAPPING_TERM;
  }
}
#endif // CAPS_WORD_ENABLE
