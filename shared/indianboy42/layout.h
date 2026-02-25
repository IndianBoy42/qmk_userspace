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
     ESC, Q,    W,    E,    R,    T,                          Y,    U,    I,    O,    P,    QUO, \
     PRN, A,    S,    D,    F,    G,                          H,    J,    K,    L,    SCL, UND, \
     CBR, Z,    X,    C,    V,    B,    ALT, BTN1, BTN2, BSP, N,    M, COM, DOT,  SLS, MIN, \
                     LGUI, ALT_BSP, LSFT, SYM, CTL, ENT, SPC, TAB, DEL, CSA ) LAYOUT_split_3x6_5( \
     ESC, Q,    W,    E,    R,    T,                          Y,    U,    I,    O,    P,    QUO, \
     PRN, A,    S,    D,    F,    G,                          H,    J,    K,    L,    SCL, UND, \
     CBR, Z,    X,    C,    V,    B,    ALT, BTN1, BTN2, BSP, N,    M, COM, DOT,  SLS, MIN, \
                     LGUI, ALT_BSP, LSFT, SYM, CTL, ENT, SPC, TAB, DEL, CSA )

#define LAYOUT_KYRIA_HALCYON( \
     ESC, Q,    W,    E,    R,    T,                                     Y,    U,    I,    O,    P,    QUO, \
     PRN, A,    S,    D,    F,    G,                                     H,    J,    K,    L,    SCL, UND, \
     CBR, Z,    X,    C,    V,    B,    ALT, BTN1, BTN2, BSP, N,    M, COM, DOT,  SLS, MIN, \
                     LGUI, ALT_BSP, LSFT, SYM, CTL, ENT, SPC, TAB, DEL, CSA ) LAYOUT_split_3x6_5_hlc( \
     ESC, Q,    W,    E,    R,    T,                          Y,    U,    I,    O,    P,    QUO, \
     PRN, A,    S,    D,    F,    G,                          H,    J,    K,    L,    SCL, UND, \
     CBR, Z,    X,    C,    V,    B,    ALT, BTN1, BTN2, BSP, N,    M, COM, DOT,  SLS, MIN, \
                     LGUI, ALT_BSP, LSFT, SYM, CTL, ENT, SPC, TAB, DEL, CSA, \
                                KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO)
#define LAYOUT_CRKBD_V4( \
     ESC, Q,    W,    E,    R,    T,                          Y,    U,    I,    O,    P,    QUO, \
     PRN, A,    S,    D,    F,    G,                          H,    J,    K,    L,    SCL, UND, \
     CBR, Z,    X,    C,    V,    B,    ALT, BTN1, BTN2, BSP, N,    M, COM, DOT,  SLS, MIN, \
                     LGUI, ALT_BSP, LSFT, SYM, CTL, ENT, SPC, TAB, DEL, CSA ) LAYOUT_split_3x6_3_ex2( \
     ESC, Q,    W,    E,    R,    T,   LGUI, CSA,  Y,    U,    I,    O,    P,    QUO, \
     PRN, A,    S,    D,    F,    G,   ALT,  BSP,  H,    J,    K,    L,    SCL, UND, \
     CBR, Z,    X,    C,    V,    B,               N,    M, COM, DOT,  SLS, MIN, \
                      LSFT, SYM, CTL,             ENT, SPC, TAB)

// clang-format on
