/* Copyright 2019 Thomas Baart <thomas@splitkb.com>
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

// clang-format off
#define LAYOUT_KYRIA( \
     ESC,  Q,    W,    E,    R,    T,                                        Y,    U,    I,    O,    P,    BSPC, \
     LPRN, A,    S,    D,    F,    G,                                        H,    J,    K,    L,    SCLN, UNDS, \
     LCBR, Z,    X,    C,    V,    B,    ALT_RBR, BTN1, BTN2, CTL_BSP, N,    M,    COMM, DOT,  SLSH, QUOT, \
                                LGUI, ALT_BSP, LSFT, SYM,     CTL_ESC, SFT_ENT, NAV_SPC, ALT_TAB, CTL_DEL, CSA_DEL ) LAYOUT_split_3x6_5( \
     ESC,  Q,    W,    E,    R,    T,                                        Y,    U,    I,    O,    P,    BSPC, \
     LPRN, A,    S,    D,    F,    G,                                        H,    J,    K,    L,    SCLN, UNDS, \
     LCBR, Z,    X,    C,    V,    B,    ALT_RBR, BTN1, BTN2, CTL_BSP, N,    M,    COMM, DOT,  SLSH, QUOT, \
                                LGUI, ALT_BSP, LSFT, SYM,     CTL_ESC, SFT_ENT, NAV_SPC, ALT_TAB, CTL_DEL, CSA_DEL )

#define LAYOUT_KYRIA_HALCYON( \
     ESC,  Q,    W,    E,    R,    T,                                        Y,    U,    I,    O,    P,    BSPC, \
     LPRN, A,    S,    D,    F,    G,                                        H,    J,    K,    L,    SCLN, UNDS, \
     LCBR, Z,    X,    C,    V,    B,    ALT_RBR, BTN1, BTN2, CTL_BSP, N,    M,    COMM, DOT,  SLSH, QUOT, \
                                LGUI, ALT_BSP, LSFT, SYM,     CTL_ESC, SFT_ENT, NAV_SPC, ALT_TAB, CTL_DEL, CSA_DEL ) LAYOUT_split_3x6_5_hlc( \
     ESC,  Q,    W,    E,    R,    T,                                        Y,    U,    I,    O,    P,    BSPC, \
     LPRN, A,    S,    D,    F,    G,                                        H,    J,    K,    L,    SCLN, UNDS, \
     LCBR, Z,    X,    C,    V,    B,    ALT_RBR, BTN1, BTN2, CTL_BSP, N,    M,    COMM, DOT,  SLSH, QUOT, \
                                LGUI, ALT_BSP, LSFT, SYM,     CTL_ESC, SFT_ENT, NAV_SPC, ALT_TAB, CTL_DEL, CSA_DEL, \
                                KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO)
// clang-format on
