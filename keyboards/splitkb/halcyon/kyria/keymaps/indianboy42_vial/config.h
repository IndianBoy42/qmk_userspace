/* Copyright 2022 Thomas Baart <thomas@splitkb.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

// Vial support
#define VIAL_KEYBOARD_UID {0x0F, 0x9E, 0x2D, 0x5A, 0x59, 0x3A, 0x68, 0x17}
#define VIAL_UNLOCK_COMBO_ROWS { 0, 0 }
#define VIAL_UNLOCK_COMBO_COLS { 0, 1 }

// Configure the global tapping term (default: 200ms)
#define TAPPING_TERM 200

// Prevent normal rollover on alphas from accidentally triggering mods.
#define IGNORE_MOD_TAP_INTERRUPT

// Enable rapid switch from tap to hold, disables double tap hold auto-repeat.
#define TAPPING_FORCE_HOLD

// Apply the modifier on keys that are tapped during a short hold of a modtap
#define PERMISSIVE_HOLD

#define DOUBLE_TAP_SHIFT_TURNS_ON_CAPS_WORD

#define FORCE_NKRO
#define COMBO_TERM 40
#define COMBO_SHOULD_TRIGGER

#define TAPPING_TERM_PER_KEY
#define DOUBLE_TAP_TERM 140
#define ADAPTIVE_TERM 100

// Encoder support
#ifdef ENCODER_ENABLE
#    define ENCODER_RESOLUTION 2
#endif

// Allows to use either side as the master. Look at the documentation for info:
// https://docs.qmk.fm/#/config_options?id=setting-handedness
#define EE_HANDS

// Allows to turn off the mouse movement code
#define POINTING_DEVICE_AUTO_MOUSE_ENABLE
