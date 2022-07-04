/*
This is the c configuration file for the keymap

Copyright 2012 Jun Wako <wakojun@gmail.com>
Copyright 2015 Jack Humbert

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once


/* Use I2C or Serial, not both */

#define USE_SERIAL
#define NO_ACTION_MACRO
#define NO_ACTION_FUNCTION

// Configure the global tapping term (default: 200ms)
#undef TAPPING_TERM
#define TAPPING_TERM 160
#define TAPPING_TERM_PER_KEY

// Reduce accidential mods
#define PERMISSIVE_HOLD

// Prevent normal rollover on alphas from accidentally triggering mods.
#define IGNORE_MOD_TAP_INTERRUPT

// Enable rapid switch from tap to hold, disables double tap hold auto-repeat.
#define TAPPING_FORCE_HOLD

#define BOTH_SHIFTS_TURNS_ON_CAPS_WORD

// #define USE_I2C

/* Select hand configuration */

//#define MASTER_LEFT
// #define MASTER_RIGHT
// #define EE_HANDS

//#define QMK_ESC_OUTPUT F1 // usually COL
//#define QMK_ESC_INPUT D5 // usually ROW
//#define QMK_LED B0
