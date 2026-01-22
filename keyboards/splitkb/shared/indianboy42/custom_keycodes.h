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

// Forward declaration
bool custom_keys(uint16_t keycode, const keyrecord_t *record);

// Custom keycodes
enum custom_keycodes {
    KC_DUMMY_CUSTOM = SAFE_RANGE,
    KC_QU,
    KC_Qu,
    KC_TH,
    KC_CH,
    KC_SH,
    KC_WH,
    KC_GH,
    KC_PH,
    KC_LTEQ,
    KC_GTEQ,
    KC_NTEQ,
    KC_PLEQ,
    KC_MNEQ,
    KC_STEQ,
    KC_SLEQ,
    KC_ARRW,
    KC_LFT_TH,
    KC_RGT_TH,
    LR_PRN, // Sends L and R and place the cursor inside
    LR_CBR,
    LR_BRC,
    LR_TRI,
    LR_QUO,
    LR_DQU,
    LR_GRV,
    // TODO: magic key for closing brackets/parens?
    KR_PRN, // Sends R and move the cursor left (inside)
    KR_CBR,
    KR_BRC,
    KR_TRI,
    KR_QUO,
    KR_DQU,
    KR_GRV,
    FOLLOW,
};

// Key override definitions
#define C_SHIFT(X, A, B) X(shift_##A##_##B, ko_make_basic(MOD_MASK_SHIFT, A, B))
#define C_ALT(X, A, B) X(alt_##A##_##B, ko_make_basic(MOD_MASK_ALT, A, B))
#define KEY_OVERRIDE_TABLE(X)    \
    C_SHIFT(X, KC_UNDS, KC_MINS) \
    C_SHIFT(X, KC_EQL, KC_ASTR)  \
    C_SHIFT(X, KC_DOT, KC_AT)    \
    C_SHIFT(X, KC_COMM, KC_PERC) \
    C_SHIFT(X, KC_MINS, KC_PLUS) \
    C_SHIFT(X, KC_LPRN, KC_RPRN) \
    C_SHIFT(X, KC_LCBR, KC_RCBR) \
    C_SHIFT(X, KC_LBRC, KC_RBRC) \
    C_SHIFT(X, KC_RPRN, KC_LPRN) \
    C_SHIFT(X, KC_RCBR, KC_LCBR) \
    C_SHIFT(X, KC_RBRC, KC_LBRC) \
    C_ALT(X, KC_BSPC, KC_DEL)    \
    C_SHIFT(X, KC_QU, KC_Qu)
#define X_DEF(A, B) const key_override_t A = B;
#define X_LIST(A, B) &A,

// Combo definitions
#define COMBOS_TABLE(X)             \
    X(23, KC_LPRN, KC_A, LR_PRN)    \
    X(25, KC_LCBR, KC_Z, LR_CBR)    \
    X(26, KC_LBRC, KC_RBRC, LR_BRC) \
    X(27, KC_LT, KC_GT, LR_TRI)     \
    X(29, KC_SLSH, KC_QUOT, LR_QUO) \
    X(31, KC_QUES, KC_DQUO, LR_DQU) \
    X(35, KC_A, KC_S, KC_LGUI)      \
    X(37, KC_L, KC_SCLN, KC_LGUI)   \
    X(38, KC_EQL, KC_ARRW, LSFT(KC_ARRW))

// Macro definitions for custom_keys function
#define KC_MACRO(KC, STR)            \
    case KC:                         \
        if (record->event.pressed) { \
            SEND_STRING(STR);        \
            return false;            \
        }                            \
        break;
#define KC_MACRO2(KC, STR, SSTR)                                        \
    case KC:                                                            \
        if (record->event.pressed) {                                    \
            if ((mods | oneshot_mods) & MOD_MASK_SHIFT && !caps_word) { \
                del_oneshot_mods(MOD_MASK_SHIFT);                       \
                unregister_mods(MOD_MASK_SHIFT);                        \
                SEND_STRING(SSTR);                                      \
                register_mods(mods);                                    \
                return false;                                           \
            } else {                                                    \
                if (caps_word) register_mods(MOD_LSFT);                 \
                SEND_STRING(STR);                                       \
                register_mods(mods);                                    \
                return false;                                           \
            }                                                           \
        }                                                               \
        break;

#define KC_PAIR(N, L, R)                                                          \
    KC_MACRO2(LR_##N, L R SS_TAP(X_LEFT), L "  " R SS_TAP(X_LEFT) SS_TAP(X_LEFT)) \
    KC_MACRO2(KR_##N, R SS_TAP(X_LEFT), " " R SS_TAP(X_LEFT) SS_TAP(X_LEFT))
#define FOLLOWED_BY(KC1, KC2) \
    case KC1:                 \
        tap_code16(KC2);      \
        break;
#define FOLLOWED_BY2(KC0, KC1, KC2)               \
    case KC1:                                     \
        if (last_keycode == KC0) tap_code16(KC2); \
        break;

// Key overrides for kyria
KEY_OVERRIDE_TABLE(X_DEF)
const key_override_t *key_overrides[] = {
    KEY_OVERRIDE_TABLE(X_LIST) NULL // Null terminate the array of overrides!
};

// Tapping term adjustments
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        default:
            return TAPPING_TERM;
    }
}

// Combo trigger conditions
bool combo_should_trigger(uint16_t combo_index, combo_t *combo, uint16_t keycode, keyrecord_t *record) {
    /* Disable combo `SOME_COMBO` on layer `_LAYER_A` */
    switch (combo_index) {}
    return true;
}

// Custom key implementation
uint16_t curr_keycode, last_keycode, last_keycode2;
bool     custom_keys(uint16_t keycode, const keyrecord_t *record) {
    if (record->event.pressed) {
        last_keycode2 = last_keycode;
        last_keycode  = curr_keycode;
        curr_keycode  = keycode;
    }
    const uint8_t mods         = get_mods();
    const uint8_t oneshot_mods = get_oneshot_mods();
    const uint8_t caps_word    = is_caps_word_on();
    switch (keycode) {
        KC_MACRO2(KC_QU, "qu", "Qu")
        KC_MACRO(KC_Qu, "Qu")
        KC_MACRO(KC_TH, "th")
        KC_MACRO(KC_CH, "ch")
        KC_MACRO(KC_SH, "sh")
        KC_MACRO(KC_WH, "wh")
        KC_MACRO(KC_GH, "gh")
        KC_MACRO(KC_PH, "ph")
        KC_MACRO2(KC_LTEQ, "<=", "<<")
        KC_MACRO2(KC_GTEQ, ">=", ">>")
        KC_MACRO2(KC_NTEQ, "!=", "==")
        KC_MACRO2(KC_PLEQ, "+=", "*=")
        KC_MACRO2(KC_MNEQ, "-=", "/=")
        KC_MACRO2(KC_STEQ, "*=", "+=")
        KC_MACRO2(KC_SLEQ, "/=", "-=")
        KC_MACRO2(KC_ARRW, "->", "=>")
        KC_PAIR(PRN, "(", ")")
        KC_PAIR(CBR, "{", "}")
        KC_PAIR(BRC, "[", "]")
        KC_PAIR(TRI, "<", ">")
        KC_PAIR(QUO, "'", "'")
        KC_PAIR(DQU, "\"", "\"")
        KC_PAIR(GRV, "`", "`")
        case FOLLOW:
        case SYM_FL:
        case SYMR_FL:
            if (record->event.pressed && record->tap.count) {
                switch (last_keycode) {
                    FOLLOWED_BY(KC_LPRN, KC_RPRN)
                    FOLLOWED_BY(KC_LCBR, KC_RCBR)
                    FOLLOWED_BY(KC_LBRC, KC_RBRC)
                    FOLLOWED_BY(KC_QUOT, KC_QUOT)
                    FOLLOWED_BY(KC_DQUO, KC_DQUO)
                    FOLLOWED_BY(KC_LT, KC_GT)
                }
                return false;
            }
            break;
    }

    return true;
}

// Process record handler
int  highest_layer;
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    highest_layer = get_highest_layer(layer_state);

    if (!custom_keys(keycode, record)) {
        return false;
    }

    return true;
};
