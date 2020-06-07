# MCU name
MCU = atmega32a

# Bootloader selection
#   Teensy       halfkay
#   Pro Micro    caterina
#   Atmel DFU    atmel-dfu
#   LUFA DFU     lufa-dfu
#   QMK DFU      qmk-dfu
#   ATmega32A    bootloadHID
#   ATmega328P   USBasp
BOOTLOADER = bootloadHID

# build options
BOOTMAGIC_ENABLE = full
MOUSEKEY_ENABLE = no
EXTRAKEY_ENABLE = yes
CONSOLE_ENABLE = no
COMMAND_ENABLE = yes
BACKLIGHT_ENABLE = yes
RGBLIGHT_ENABLE = yes
RGBLIGHT_CUSTOM_DRIVER = yes
TAP_DANCE_ENABLE= yes
OPT_DEFS = -DDEBUG_LEVEL=0

SRC += i2c_master.c

# programming options
PROGRAM_CMD = ./util/atmega32a_program.py $(TARGET).hex
