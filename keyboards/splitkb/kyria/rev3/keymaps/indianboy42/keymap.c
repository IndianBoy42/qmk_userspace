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

#define LAYOUT_UNIV LAYOUT_KYRIA
#include "shared/indianboy42/common.h"
#include "shared/indianboy42/custom_keycodes.h"
#include "shared/indianboy42/tap_dance.h"
#include "shared/indianboy42/keymaps.h"

// Encoder functionality
#ifdef ENCODER_ENABLE
#    define LAYER (biton(layer_state))
#    define ENC_TAP(U, D) \
        if (clockwise) {  \
            tap_code(U);  \
        } else {          \
            tap_code(D);  \
        }
#    define ENC_L (index == 0)
#    define ENC_R (index == 1)
#    define ENCS_TAP(LU, LD, RU, RD) \
        {                            \
            if (ENC_L) {             \
                ENC_TAP(LU, LD)      \
            };                       \
            if (ENC_R) {             \
                ENC_TAP(RU, RD)      \
            };                       \
        }
#    define MOD_CHK(KC) (get_mods() & MOD_BIT(KC))
#    define MOD_CTL MOD_CHK(KC_LCTRL)
#    define MOD_ALT MOD_CHK(KC_LALT)
#    define MOD_SFT MOD_CHK(KC_LSFT)
#    define MOD_GUI MOD_CHK(KC_LGUI)
#    define LYR_CHK(L) (IS_LAYER_ON(L))
bool encoder_update_user(uint8_t index, bool clockwise) {
    switch (LAYER) {
        case _FUNCTION:
            ENC_TAP(KC_VOLU, KC_VOLD);
            break;
        case _NAV:
            ENC_TAP(KC_UP, KC_DOWN);
            break;
        default:
            if (MOD_GUI) {
                ENC_TAP(KC_RIGHT, KC_LEFT);
            } else {
                ENC_TAP(KC_WH_R, KC_WH_L);
            }
    }
    return false;
}
#endif
