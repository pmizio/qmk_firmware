BOOTLOADER = qmk-dfu
BACKLIGHT_ENABLE = yes
RGBLIGHT_ENABLE = yes
CAPS_WORD_ENABLE = yes
RAW_ENABLE = yes
LTO_ENABLE = yes

AUDIO_ENABLE = no
MOUSEKEY_ENABLE = no
COMMAND_ENABLE = no
SWAP_HANDS_ENABLE = no

SRC += utils/led.c
SRC += features/controller.c
