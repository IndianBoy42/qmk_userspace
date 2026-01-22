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

// NOTE: Use LAYOUT_KYRIA for standard Kyria (splitkb/kyria/rev3)
// NOTE: Use LAYOUT_KYRIA_HALCYON for Halcyon (splitkb/halcyon/kyria)

// Define your layout macro at the top of your keymap.c:
// #define LAYOUT_KYRIA LAYOUT_KYRIA  // For standard Kyria
// #define LAYOUT_KYRIA LAYOUT_KYRIA_HALCYON  // For Halcyon

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTYP] = LAYOUT_KYRIA(
     KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                                            KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
     KC_LPRN, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                                            KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_UNDS,
     KC_LCBR, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_SPC,  KC_BTN1,     KC_BTN2, KC_BSPC, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_F1,
                                KC_LGUI, KC_BSPC, KC_LSFT, SYM,     KC_ESC,      KC_LSFT, KC_SPC,  KC_TAB,  KC_DEL,  KC_F2
    ),

    [_QWERTY] = LAYOUT_KYRIA(
     TH_LBRC, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                                            KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_QUOT,
     TH_LPRN, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                                            KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_UNDS,
     TH_LCBR, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    ALT_SPC, KC_BTN1,     KC_BTN2, CTL_BSP, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_EQL,
                                KC_LGUI, FUN_BSP, KC_LSFT, SYM,     CTL_ESC,     SFT_ENT, NAV_SPC, ALT_TAB, SYM_DEL, CSA_F2
    ),

    [_SYM] = LAYOUT_KYRIA(
     KC_RBRC, KC_TILD, KC_PLUS, KC_EXLM, KC_LT,   KC_GT,                                           KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_ERRW,
     KC_RPRN, KC_CIRC, KC_ASTR, KC_AMPR, KC_EQL,  KC_DLR,                                          KC_QUOT, KC_DQUO, KC_QUES, KC_BSLS, KC_COLN, KC_MINS,
     KC_RCBR, KC_GRV,  KC_PERC, KC_HASH, KC_PIPE, KC_ARRW, KC_LALT, _______,     _______, _______, KC_0,    KC_6,    KC_7,    KC_8,    KC_9,    KC_AT,
                                _______, _______, UNUSABL, _______, UNUSABL,     LCA_ENT, KC_SPC, _______, LCS_DEL,  _______
    ),

    // TODO: more over here
    [_NAV] = LAYOUT_KYRIA(
     KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                                           KC_HOME, KC_PGDN, KC_PGUP, KC_END,  KC_PSCR, UNASSIN,
     _____,   OS_LGUI, OS_LALT, OS_LCTL, OS_LSFT, OS_CSA,                                          KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, UNASSIN, UNASSIN,
     _____,   KC_UNDO, KC_REDO, UNASSIN, KC_INS,  UNASSIN, _______, _______,     _______, KC_LCTL, KC_ESC,  KC_BSPC, KC_ENT,  KC_TAB,  KC_DEL,  UNASSIN,
                                _______, _______, _______, KC_LALT, _______,     _______, _______, _______, _______, _______
    ),

    [_SYMR] = LAYOUT_KYRIA(
     KC_GRV,  KC_TILD, KC_PLUS, KC_EXLM, KC_LT,   KC_GT,                                           KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_BSPC,
     KC_RPRN, KC_LBRC, KC_ASTR, KC_PIPE, KC_EQL,  KC_ARRW,                                         KC_ERRW, KC_DQUO, KC_QUES, KC_BSLS, KC_COLN, KC_MINS,
     KC_RCBR, KC_CIRC, UNASSIN, KC_HASH, KC_AMPR, KC_DLR,  _______, _______,     _______, _______, KC_0,    KC_6,    KC_7,    KC_8,    KC_9,    TH_DQUO,
                                _______, _______, _______, KC_SPC,  _______,     _______, _______, _______, _______, _______
    ),

    [_SYM3] = LAYOUT_KYRIA(
     KC_RBRC, KC_1   , KC_2   , KC_3,    KC_4 ,   KC_5,                                            KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_AT,
     KC_RPRN, KC_CIRC, KC_ASTR, KC_PIPE, KC_EQL,  KC_DLR,                                          KC_QUOT, KC_DQUO, KC_QUES, KC_BSLS, KC_COLN, KC_MINS,
     KC_RCBR, KC_GRV,  KC_PERC, KC_HASH, KC_AMPR, KC_ARRW, KC_LALT,  _______,    _______, _______, KC_TILD, KC_PLUS, KC_EXLM, KC_LT,   KC_GT,   KC_SLSH,
                                _______, _______, UNUSABL, _______, UNUSABL,     LCA_ENT, KC_SPC, _______, LCS_DEL,  _______
    ),

    [_NUM] = LAYOUT_KYRIA(
     _____,   _____,   _____,   _____,   _____,   _____,                                           KC_LPRN, KC_1,    KC_2,    KC_3,    KC_CIRC, KC_RPRN,
     KC_HYPR, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, KC_CSA,                                          KC_PAST, KC_4,    KC_5,    KC_6,    KC_PSLS, KC_EQL,
     _____,   _____,   _____,   _____,   _____,   _____,   _______, _______,     _______, _______, KC_PLUS, KC_7,    KC_8,    KC_9,    KC_PMNS, KC_UNDS,
                                _______, _______, _______, KC_LCTL, KC_LALT,     _______, KC_SPC,  KC_0,    KC_COMM, KC_DOT
    ),

    [_NUM2] = LAYOUT_KYRIA(
     ______,  KC_PAST, KC_PSLS, KC_PLUS, KC_PMNS, ______,                                          KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_BSPC,
     KC_HYPR, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, KC_CSA,                                          KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_GT,   KC_LT,
     ______,  KC_CIRC, KC_LPRN, KC_RPRN, KC_UNDS, ______,  _______, _______,     _______, _______, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_EQL,
                                _______, _______, _______, KC_LCTL, KC_LALT,     _______, _______, ____,    KC_COMM, KC_DOT
    ),

    // TODO: https://sites.google.com/alanreiser.com/handsdown/home/hands-down-neu#h.ze4kq734zl5w
       // TODO: concentrate on 3 thumb keys for "downgrading" in the future
    [_HANDDOWNN] = LAYOUT_KYRIA(
     NUM_ESC, KC_W,    KC_G,    KC_M,    KC_P,    KC_V,                                            KC_EQL,  KC_COMM, KC_DOT,  KC_QUOT, KC_UNDS, KC_BSPC,
     KC_LPRN, KC_R,    KC_S,    KC_N,    KC_T,    KC_B,                                            KC_SCLN, KC_A,    KC_E,    KC_I,    KC_H,    KC_J,
     KC_LCBR, KC_X,    KC_C,    KC_L,    KC_D,    KC_F,    ALT_BSP, _______,     _______, CTL_DEL, KC_SLSH, KC_U,    KC_O,    KC_Y,    KC_K,    FKEYS,
                                KC_LGUI, NAV_TAB, KC_LSFT, SYM,    CTL_ESC,      SFT_ENT, NAV_SPC, ALT_TAB, CSA_BSP, KC_ENT
    ),
    [_HANDDOWNR] = LAYOUT_KYRIA(
     NUM_ESC, KC_X,    KC_P,    KC_H,    KC_G,    KC_K,                                            KC_EQL,  KC_COMM, KC_DOT,  KC_QUOT, KC_UNDS, KC_BSPC,
     KC_LPRN, KC_C,    KC_S,    KC_N,    KC_T,    KC_J,                                            KC_SCLN, KC_A,    KC_E,    KC_I,    KC_M,    KC_DEL,
     KC_LCBR, KC_B,    KC_F,    KC_L,    KC_D,    KC_V,    ALT_BSP, _______,     _______, CTL_DEL, KC_SLSH, KC_U,    KC_O,    KC_Y,    KC_W,    FKEYS,
                                KC_LGUI, NAV_TAB, KC_LSFT, SYM_R,  CTL_ESC,      ALT_ENT, NAV_SPC, SFT_TAB, CSA_BSP, KC_ENT
    ),
    [_SYM2] = LAYOUT_KYRIA(
     KC_GRV,  ____,    KC_AT,   KC_EXLM, KC_LT,   KC_GT,                                           _______, KC_1,    KC_2,    KC_3,    KC_PLUS,  KC_BSPC,
     KC_PERC, KC_CIRC, KC_AMPR, KC_DLR,  KC_LCBR, KC_RCBR,                                         KC_0,    KC_4,    KC_5,    KC_6,    KC_BSLS,  KC_DEL,
     _______, KC_TILD, KC_PIPE, KC_HASH, KC_LBRC, KC_RBRC, _______, _______,     _______, _______, _______, KC_7,    KC_8,    KC_9,    KC_PMNS,  KC_EQL,
                                KC_LGUI, KC_LPRN, KC_RPRN, _______, _______,     _______, KC_SPC,  _______, KC_PAST, KC_PSLS
    ),


    [_MINECRAFT] = LAYOUT_KYRIA(
     KC_2,    KC_3,    KC_4,    KC_E,    KC_5,    KC_6,                                            _,       _,       _,       _,       _,       _______,
     KC_1,    KC_LSFT, KC_S,    KC_D,    KC_F,    KC_7,                                            _,       _,       _,       _,       _,       MINCRFT,
     KC_0,    KC_LCTL, KC_X,    KC_C,    KC_9,    KC_8,    KC_T,    _______,     _______, ______,  _,       _,       _,       _,       _,       FKEYS,
                                _______, KC_LCTL, KC_LSFT, KC_SPC,  KC_ESC,      KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5
    ),

    [_FUNCTION] = LAYOUT_KYRIA(
     QK_BOOT, KC_PAUS, KC_MPLY, KC_MNXT, KC_MPRV, MINCRFT,                                         KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   QK_BOOT,
     _______, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, HANDDWN,                                         KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_PSCR,
     KC_CSA,  KC_F21,  KC_F22,  KC_F23,  KC_F24,  QWERTY,  RGB_TOG, _______,     _______, KC_MUTE, KC_F11,  KC_F12,  KC_F13,  KC_F14,  KC_F15,  _______,
                                KC_NUM,  KC_CAPS, KC_SCRL, RGB_MOD, KC_F16,      KC_F17,  _______, KC_F18,  KC_F19,  KC_F20
    )

//     [_LAYERINDEX] = LAYOUT_KYRIA(
//       _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
//       _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
//       _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
//                                  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
//     ),
};

// clang-format on
