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

#include <math.h>
#include QMK_KEYBOARD_H

// Layer definitions
enum layers {
    _QWERTY = 0,
    _QWERTYP,
    _HANDDOWNN,
    _HANDDOWNR,
    _MINECRAFT,
    _NAV,
    _NUM,
    _NUM2,
    _SYM,
    _SYMR,
    _SYM2,
    _SYM3,
    _FUNCTION,
};

// Common defines and aliases
#define CSA(A) MEH(A)
#define UNASSIN KC_TRNS
#define UNUSABL KC_TRNS
#define _ KC_TRNS
#define __ KC_TRNS
#define ___ KC_TRNS
#define ____ KC_TRNS
#define _____ KC_TRNS
#define ______ KC_TRNS
#define _______ KC_TRNS
#define LCS(...) LCTL(LSFT(__VA_ARGS__))
#define LCG(...) LCTL(LGUI(__VA_ARGS__))
#define MOD_CSA MOD_LCTL | MOD_LSFT | MOD_LALT
#define KC_LCS C_S_T(OSM(MOD_LCTL | MOD_LSFT))
#define KC_LCA LCA(KC_NO)
#define KC_LSA LSA(KC_NO)
#define KC_LSG SGUI(KC_NO)
#define KC_LCG LCG(KC_NO)
#define KC_LAG LAG(KC_NO)
#define KC_LCAG LCAG(KC_NO)
#define KC_CSA CSA(KC_NO)
#define KC_SGUI SGUI(KC_NO)
#define KC_HYPR HYPR(KC_NO)
#define SMO(X) LM(X, MOD_LSFT)

#define KC_ERRW LSFT(KC_ARRW)

#define LCA_ENT LCA(KC_ENT)
#define LCS_DEL LCS(KC_DEL)
#define LCS_BSP LCS(KC_BSP)

// Layer switching aliases
#define QWERTY DF(_QWERTY)
#define HANDDWN DF(_HANDDOWNN)
#define MINCRFT TO(_MINECRAFT)
#define LEADER QK_LEAD

#define SYM3 MO(_SYM3)
#define SYM MO(_SYM)
#define SYMR MO(_SYMR)
#define NUM MO(_NUM)
#define NAV MO(_NAV)
#define FKEYS MO(_FUNCTION)

#define OS_LGUI OSM(MOD_LGUI)
#define OS_LCTL OSM(MOD_LCTL)
#define OS_LSFT OSM(MOD_LSFT)
#define OS_LALT OSM(MOD_LALT)
#define OS_CSA OSM(MOD_CSA)

// Control combinations
#define CC_LEFT LCTL(KC_LEFT)
#define CC_RIGHT LCTL(KC_RIGHT)
#define CC_DOWN LCTL(KC_DOWN)
#define CC_UP LCTL(KC_UP)
#define CC_RGHT LCTL(KC_RGHT)
#define CC_BSPC LCTL(KC_BSPC)
#define CC_DEL LCTL(KC_DEL)
#define CC_Q LCTL(KC_Q)
#define AL_Q LCTL(KC_Q)
#define AL_LEFT LALT(KC_LEFT)
#define AL_DOWN LALT(KC_DOWN)
#define AL_UP LALT(KC_UP)
#define AL_RGHT LALT(KC_RGHT)

#define KC_S_Q LSFT(KC_Q)
#define KC_S_Z LSFT(KC_Z)

// Mod-tap definitions
#define CTL_ESC MT(MOD_LCTL, KC_ESC)
#define CTL_SPC MT(MOD_LCTL, KC_SPC)
#define CTL_DEL MT(MOD_LCTL, KC_DEL)
#define CST_ESC MT(MOD_LCTL | MOD_LSFT, KC_ESC)
#define CTL_QUO MT(MOD_LCTL, KC_QUOTE)
#define CTL_MIN MT(MOD_LCTL, KC_MINUS)
#define ALT_ESC MT(MOD_LALT, KC_ESC)
#define ALT_DEL MT(MOD_LALT, KC_DEL)
#define ALT_BSP MT(MOD_LALT, KC_BSPC)
#define ALT_SPC MT(MOD_LALT, KC_SPC)
#define SFT_BSP MT(MOD_LSFT, KC_BSPC)
#define SFT_ESC MT(MOD_LSFT, KC_ESC)
#define GUI_ESC MT(MOD_LGUI, KC_ESC)
#define GUI_Q MT(MOD_LGUI, KC_Q)
#define ALT_ENT MT(MOD_LALT, KC_ENT)
#define ALT_TAB MT(MOD_LALT, KC_TAB)
#define ALT_RBR MT(MOD_LALT, KC_RBRC)
#define GUI_ENT MT(MOD_LGUI, KC_ENT)
#define GUI_TAB MT(MOD_LGUI, KC_TAB)
#define GUI_BSP MT(MOD_LGUI, KC_BSPC)
#define GUI_SPC MT(MOD_LGUI, KC_SPC)
#define SFT_ENT MT(MOD_LSFT, KC_ENT)
#define SFT_TAB MT(MOD_LSFT, KC_TAB)
#define SFT_SPC MT(MOD_LSFT, KC_SPC)
#define CTL_ENT MT(MOD_LCTL, KC_ENT)
#define CTL_TAB MT(MOD_LCTL, KC_TAB)
#define CTL_BSP MT(MOD_LCTL, KC_BSPC)

// Layer-tap definitions
#define SYM3_ENT LT(_SYM3, KC_ENT)
#define SYM3_TAB LT(_SYM3, KC_TAB)
#define NUM_DEL LT(_NUM, KC_DEL)
#define NUM_ENT LT(_NUM, KC_ENT)
#define NUM_TAB LT(_NUM, KC_TAB)
#define NUM_BSP LT(_NUM, KC_BSPC)
#define NUM_ESC LT(_NUM, KC_ESC)
#define NAV_ENT LT(_NAV, KC_ENT)
#define NAV_SPC LT(_NAV, KC_SPC)
#define NAV_TAB LT(_NAV, KC_TAB)
#define NAV_UND LT(_NAV, KC_UNDS)
#define NAV_BSL LT(_NAV, KC_BSLS)
#define NAV_ESC LT(_NAV, KC_ESC)
#define NAV_DEL LT(_NAV, KC_DEL)
#define NAV_BSP LT(_NAV, KC_BSPC)
#define SYM_R LT(_SYM, KC_R)
#define SYM_SPC LT(_SYM, KC_SPC)
#define SYM_BSP LT(_SYM, KC_BSPC)
#define SYM_DEL LT(_SYM, KC_DEL)
#define SYM_FL LT(_SYM, FOLLOW)
#define SYMR_R LT(_SYMR, KC_R)
#define SYMR_SP LT(_SYMR, KC_SPC)
#define SYMR_FL LT(_SYMR, FOLLOW)
#define CSA_ESC MT(MOD_CSA, KC_ESC)
#define CSA_BSP MT(MOD_CSA, KC_BSPC)
#define CSA_ENT MT(MOD_CSA, KC_ENT)
#define CSA_DEL MT(MOD_CSA, KC_DEL)
#define CSA_F2 MT(MOD_CSA, KC_F2)

// Common key combinations
#define KC_COPY LCTL(KC_C)
#define KC_CUT LCTL(KC_X)
#define KC_PSTE LCTL(KC_V)
#define KC_UNDO LCTL(KC_Z)
#define KC_REDO LCTL(LSFT(KC_Z))
#define FUN_F1 LT(_FUNCTION, KC_F1)
#define FUN_BSP LT(_FUNCTION, KC_BSPC)

// Home row mods
#define GU_A MT(MOD_LGUI, KC_A)
#define AL_S MT(MOD_LALT, KC_S)
#define CT_D MT(MOD_LCTL, KC_D)
#define NV_F LT(_NAV, KC_F)
#define GU_SCLN MT(MOD_LGUI, KC_SCLN)
#define AL_L MT(MOD_LALT, KC_L)
#define CT_K MT(MOD_LCTL, KC_K)
#define NV_J LT(_NAV, KC_J)
#define GU_R MT(MOD_LGUI, KC_R)
#define AL_I MT(MOD_LALT, KC_I)
#define CT_E MT(MOD_LCTL, KC_E)
#define NV_A LT(_NAV, KC_A)
