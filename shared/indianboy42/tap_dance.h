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

// Tap dance helper functions
void tap_dance_multi_on_each_tap(tap_dance_state_t *state, void *user_data) {
    tap_dance_pair_t *pair = (tap_dance_pair_t *)user_data;

    if (state->count >= 3) {
        register_code16(pair->kc2);
    }
}

void tap_dance_multi_finished(tap_dance_state_t *state, void *user_data) {
    tap_dance_pair_t *pair = (tap_dance_pair_t *)user_data;

    if (state->count == 1)
        register_code16(pair->kc1);
    else
        register_code16(pair->kc2);
}

void tap_dance_multi_reset(tap_dance_state_t *state, void *user_data) {
    tap_dance_pair_t *pair = (tap_dance_pair_t *)user_data;

    if (state->count == 1) {
        wait_ms(TAP_CODE_DELAY);
        unregister_code16(pair->kc1);
    } else if (state->count >= 2) {
        unregister_code16(pair->kc2);
    }
}

// Tap dance action definitions
#define ACTION_TAP_DANCE_MULTI(kc1, kc2)                                                                   \
    {                                                                                                      \
        .fn        = {tap_dance_multi_on_each_tap, tap_dance_multi_finished, tap_dance_multi_reset, NULL}, \
        .user_data = (void *)&((tap_dance_pair_t){kc1, kc2}),                                              \
    }
#define DANCE_DOUBLE_TAP(N, ...) ACTION_TAP_DANCE_DOUBLE(__VA_ARGS__)
// TODO: make it support custom keycodes
#define DANCE_DOUBLE_TAP_CUSTOM(N, ...) ACTION_TAP_DANCE_DOUBLE(__VA_ARGS__)
#define DANCE_MULTI_TAP(N, ...) ACTION_TAP_DANCE_MULTI(__VA_ARGS__)
#define DTH_MOD(KC) register_mods(MOD_BIT(KC))
#define DTH_UMOD(KC) unregister_mods(MOD_BIT(KC))
#define DTH_REG(KC) register_code16(MOD_BIT(KC))
#define DTH_UREG(KC) unregister_code16(MOD_BIT(KC))
#define DTH_SEND(STR) SEND_STRING(STR)

// Tap dance table definitions
#define TAP_DANCE_TABLE(X)                                                                        \
    X(DT_PRNS, DANCE_DOUBLE_TAP, NOP, KC_LPRN, LR_PRN)                                            \
    X(DT_CBRS, DANCE_DOUBLE_TAP, NOP, KC_LCBR, LR_CBR)                                            \
    X(DT_BRCS, DANCE_DOUBLE_TAP, NOP, KC_LBRC, LR_BRC)                                            \
    X(DT_TRIS, DANCE_DOUBLE_TAP, NOP, KC_LT, LR_TRI)                                              \
    X(DT_QUOS, DANCE_DOUBLE_TAP, NOP, KC_QUOT, LR_QUO)                                            \
    X(DT_DQUS, DANCE_DOUBLE_TAP, NOP, KC_DQUO, LR_DQU)                                            \
    X(DT_GRVS, DANCE_DOUBLE_TAP, NOP, KC_GRV, LR_GRV)                                             \
    X(DB_LEFT, DANCE_MULTI_TAP, NOP, KC_LEFT, CC_LEFT)                                            \
    X(DB_RGHT, DANCE_MULTI_TAP, NOP, KC_RIGHT, CC_RIGHT)                                          \
    X(DB_UP, DANCE_MULTI_TAP, NOP, KC_UP, CC_UP)                                                  \
    X(DB_DOWN, DANCE_MULTI_TAP, NOP, KC_DOWN, CC_DOWN)                                            \
    X(DB_BSPC, DANCE_MULTI_TAP, NOP, KC_BSPC, CC_BSPC)                                            \
    X(CTRL_LP, DANCE_TAP_HOLD, DANCE_TAP_HOLD_FNS, KC_LPRN, DTH_MOD, DTH_UMOD, KC_LCTL)           \
    X(TH_PRNS, DANCE_TAP_HOLD, DANCE_TAP_HOLD_FNS, KC_LPRN, DTH_SEND, NOP, "()" SS_TAP(X_LEFT))   \
    X(TH_BRCS, DANCE_TAP_HOLD, DANCE_TAP_HOLD_FNS, KC_LBRC, DTH_SEND, NOP, "[]" SS_TAP(X_LEFT))   \
    X(TH_CBRS, DANCE_TAP_HOLD, DANCE_TAP_HOLD_FNS, KC_LCBR, DTH_SEND, NOP, "{}" SS_TAP(X_LEFT))   \
    X(TH_QUOS, DANCE_TAP_HOLD, DANCE_TAP_HOLD_FNS, KC_QUOT, DTH_SEND, NOP, "''" SS_TAP(X_LEFT))   \
    X(TH_DQUS, DANCE_TAP_HOLD, DANCE_TAP_HOLD_FNS, KC_DQUO, DTH_SEND, NOP, "\"\"" SS_TAP(X_LEFT)) \
    X(EQL_H_Q, DANCE_TAP_HOLD, DANCE_TAP_HOLD_FNS, KC_EQL, DTH_SEND, NOP, "q")                    \
    X(UND_H_Z, DANCE_TAP_HOLD, DANCE_TAP_HOLD_FNS, KC_UNDS, DTH_SEND, NOP, "z")

// Tap dance enum and function macros
#define X__NAME(N, ...) _##N
#define X_NAME(N, ...) N
#define X__ENUM(...) X__NAME(__VA_ARGS__),
#define X_ENUM(...) X_NAME(__VA_ARGS__) = TD(X__NAME(__VA_ARGS__)),
enum { TAP_DANCE_TABLE(X__ENUM) };
#define NOP(...)
#define TAP_DANCE_ARR(N, F, G, ...) [X__NAME(N)] = F(N, __VA_ARGS__),
#define TAP_DANCE_FN(N, F, G, ...) G(N, __VA_ARGS__)

// Tap dance state management
static enum {
    SINGLE_TAP,
    SINGLE_HOLD,
    DOUBLE_SINGLE_TAP,
} td_state;
int cur_dance(tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) {
            return SINGLE_TAP;
        } else {
            return SINGLE_HOLD;
        }
    }
    if (state->count == 2) {
        return DOUBLE_SINGLE_TAP;
    } else {
        return 3;
    }
}
#define DANCE_TAP_HOLD(N, ...) ACTION_TAP_DANCE_FN_ADVANCED(NULL, N##_finished, N##_reset)
#define DANCE_TAP_HOLD_FNS(N, TAP, HOLD, UNHOLD, ...)              \
    void N##_finished(tap_dance_state_t *state, void *user_data) { \
        td_state = cur_dance(state);                               \
        switch (td_state) {                                        \
            case SINGLE_TAP:                                       \
                register_code16(TAP);                              \
                break;                                             \
            case SINGLE_HOLD:                                      \
                HOLD(__VA_ARGS__);                                 \
                break;                                             \
            case DOUBLE_SINGLE_TAP:                                \
                tap_code16(TAP);                                   \
                register_code16(TAP);                              \
        }                                                          \
    }                                                              \
    void N##_reset(tap_dance_state_t *state, void *user_data) {    \
        switch (td_state) {                                        \
            case SINGLE_TAP:                                       \
                unregister_code16(TAP);                            \
                break;                                             \
            case SINGLE_HOLD:                                      \
                UNHOLD(__VA_ARGS__);                               \
                break;                                             \
            case DOUBLE_SINGLE_TAP:                                \
                unregister_code16(TAP);                            \
        }                                                          \
    }

// Generate tap dance functions and actions
TAP_DANCE_TABLE(TAP_DANCE_FN)
tap_dance_action_t tap_dance_actions[] = {TAP_DANCE_TABLE(TAP_DANCE_ARR)};

// Utilities for the keymap
enum { TAP_DANCE_TABLE(X_ENUM) };

// Combo definitions and implementations
#undef X_NAME
#define X_NAME(N, ...) COMBO_##N // ##_##B
#undef X_ENUM
#define X_ENUM(N, A, B, C) X_NAME(N, A, B, C),
#define X_name(N, A, B, C) combo_##N // ##_##B
#define X_SEQ(N, A, B, C) const uint16_t PROGMEM X_name(N, A, B, C)[] = {A, B, COMBO_END};
// #define X_SEQ(N, A, B, C) X_SEQ_(N, A, B, C)
#define X_COMBO(N, A, B, C) [X_NAME(N, A, B, C)] = COMBO(X_name(N, A, B, C), C),

enum combos { COMBOS_TABLE(X_ENUM) };
COMBOS_TABLE(X_SEQ)
combo_t key_combos[] = {COMBOS_TABLE(X_COMBO)};

// Key overrides for kyria
KEY_OVERRIDE_TABLE(X_DEF)
const key_override_t *key_overrides[] = {
    KEY_OVERRIDE_TABLE(X_LIST) NULL // Null terminate the array of overrides!
};
