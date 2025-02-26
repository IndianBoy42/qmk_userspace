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
#include QMK_KEYBOARD_H

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
    _HOLY,
    _HOLYR,
    _HOLY2,
    _FUNCTION,
};

#define CSA(A) MEH(A)
#define UNASSIN KC_TRNS
#define _ KC_TRNS
#define __ KC_TRNS
#define ___ KC_TRNS
#define ____ KC_TRNS
#define _____ KC_TRNS
#define ______ KC_TRNS
#define _______ KC_TRNS
#define LCS(...) LCTL(LSFT(__VA_ARGS__))
#define LCG(...) LCTL(LGUI(__VA_ARGS__))
#define KC_LCS C_S_T(OSM(MOD_LCTL | MOD_LSFT))
#define KC_LCA LCA(KC_NO)
#define KC_LSA LSA(KC_NO)
#define KC_LSG SGUI(KC_NO)
#define KC_LCG LCG(KC_NO)
#define KC_LAG LAG(KC_NO)
#define KC_LCAG LCAG(KC_NO)
#define KC_CSA CSA(KC_NO) // TODO: Use one shot mod
#define KC_SGUI SGUI(KC_NO)
#define KC_HYPR HYPR(KC_NO)
#define SMO(X) LM(X, MOD_LSFT)

bool custom_keys(uint16_t keycode, const keyrecord_t *record);
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
    KC_ARROW,
};

// Aliases for readability
#define QWERTY DF(_QWERTY)
#define HANDDWN DF(_HANDDOWNN)
#define MINCRFT TO(_MINECRAFT)

#define SYM MO(_SYM)
#define HOLY MO(_HOLY)
#define HOLYR MO(_HOLYR)
#define NUM MO(_NUM)
#define NAV MO(_NAV)
#define FKEYS MO(_FUNCTION)

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

#define CTL_ESC MT(MOD_LCTL, KC_ESC)
#define CTL_SPC MT(MOD_LCTL, KC_SPC)
#define CTL_DEL MT(MOD_LCTL, KC_DEL)
#define CST_ESC MT(MOD_LCTL | MOD_LSFT, KC_ESC)
#define CTL_QUOT MT(MOD_RCTL, KC_QUOTE)
#define CTL_MINS MT(MOD_RCTL, KC_MINUS)
#define ALT_ESC MT(MOD_LALT, KC_ESC)
#define ALT_DEL MT(MOD_LALT, KC_DEL)
#define ALT_BSP MT(MOD_LALT, KC_BSPC)
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
#define SFT_ENT MT(MOD_LSFT, KC_ENT)
#define SFT_TAB MT(MOD_LSFT, KC_TAB)
#define SFT_SPC MT(MOD_LSFT, KC_SPC)
#define CTL_ENT MT(MOD_LCTL, KC_ENT)
#define CTL_TAB MT(MOD_LCTL, KC_TAB)
#define CTL_BSP MT(MOD_LCTL, KC_BSPC)
#define SYM_ENT LT(_SYM, KC_ENT)
#define SYM_TAB LT(_SYM, KC_TAB)
#define NUM_DEL LT(_NUM, KC_DEL)
#define NUM_ENT LT(_NUM, KC_ENT)
#define NUM_TAB LT(_NUM, KC_TAB)
#define NUM_BSP LT(_NUM, KC_BSPC)
#define NUM_ESC LT(_NUM, KC_ESC)
#define HLY_ENT LT(_HLY, KC_ENT)
#define HLY_SPC LT(_HLY, KC_SPC)
#define HLY_TAB LT(_HLY, KC_TAB)
#define HLY_UND LT(_HLY, KC_UNDS)
#define HLY_BSL LT(_HLY, KC_BSLS)
#define HLY_ESC LT(_HLY, KC_ESC)
#define HLY_DEL LT(_HLY, KC_DEL)
#define HLY_BSP LT(_HLY, KC_BSPC)
#define NAV_ENT LT(_NAV, KC_ENT)
#define NAV_SPC LT(_NAV, KC_SPC)
#define NAV_TAB LT(_NAV, KC_TAB)
#define NAV_UND LT(_NAV, KC_UNDS)
#define NAV_BSL LT(_NAV, KC_BSLS)
#define NAV_ESC LT(_NAV, KC_ESC)
#define NAV_DEL LT(_NAV, KC_DEL)
#define NAV_BSP LT(_NAV, KC_BSPC)
#define HOLY_R LT(_HOLY, KC_R)
#define HOLY_SP LT(_HOLY, KC_SPC)
#define CSA_ESC MT(MOD_LCTL | MOD_LSFT | MOD_LALT, KC_ESC)
#define CSA_BSP MT(MOD_LCTL | MOD_LSFT | MOD_LALT, KC_BSPC)
#define CSA_ENT MT(MOD_LCTL | MOD_LSFT | MOD_LALT, KC_ENT)
#define KC_COPY LCTL(KC_C)
#define KC_CUT LCTL(KC_X)
#define KC_PSTE LCTL(KC_V)
#define KC_UNDO LCTL(KC_Z)
#define KC_REDO LCTL(LSFT(KC_Z))

#define GU_A MT(MOD_LGUI, KC_A)
#define AL_S MT(MOD_LALT, KC_S)
#define CT_D MT(MOD_LCTL, KC_D)
#define NV_F LT(_NAV, KC_F)
#define GU_SCLN MT(MOD_LGUI, KC_SCLN)
#define AL_L MT(MOD_LALT, KC_L)
#define CT_K MT(MOD_LCTL, KC_K)
#define NV_J LT(_NAV, KC_J)
#define GU_R MT(MOD_LGUI, KC_R)
#define AL_S MT(MOD_LALT, KC_S)
#define CT_N MT(MOD_LCTL, KC_N)
#define NV_T LT(_NAV, KC_T)
#define GU_H MT(MOD_LGUI, KC_H)
#define AL_I MT(MOD_LALT, KC_I)
#define CT_E MT(MOD_LCTL, KC_E)
#define NV_A LT(_NAV, KC_A)

#define TAPTAP(KC, HOLD)                                   \
    case LT(0, KC):                                        \
        if (!record->tap.count && record->event.pressed) { \
            tap_code16(HOLD);                              \
            return false;                                  \
        }                                                  \
        return true;
#define TTKC(KC, HOLD) LT(0, KC)

// TODO: https://docs.qmk.fm/#/feature_key_overrides?id=key-overrides
// Use Key overrides
#define C_SHIFT(X, A, B) X(shift_##A##_##B, ko_make_basic(MOD_MASK_SHIFT, A, B))
#define C_ALT(X, A, B) X(alt_##A##_##B, ko_make_basic(MOD_MASK_ALT, A, B))
#define KEY_OVERRIDE_TABLE(X)    \
    C_SHIFT(X, KC_UNDS, KC_MINS) \
    C_SHIFT(X, KC_EQL, KC_ASTR)  \
    C_SHIFT(X, KC_DOT, KC_DLR)   \
    C_SHIFT(X, KC_COMM, KC_CIRC) \
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
KEY_OVERRIDE_TABLE(X_DEF)
const key_override_t *key_overrides[] = {
    KEY_OVERRIDE_TABLE(X_LIST) NULL // Null terminate the array of overrides!
};

#define COMBOS_TABLE(X)             \
    X(23, KC_LPRN, KC_A, LR_PRN)    \
    X(25, KC_LCBR, KC_Z, LR_CBR)    \
    X(26, KC_LBRC, KC_RBRC, LR_BRC) \
    X(27, KC_LT, KC_GT, LR_TRI)     \
    X(29, KC_SCLN, KC_QUOT, LR_QUO) \
    X(31, KC_COLN, KC_DQUO, LR_DQU) \
    X(35, KC_A, KC_S, KC_LGUI)      \
    X(37, KC_L, KC_SCLN, KC_LGUI)

#define DANCE_DOUBLE_TAP(N, ...) ACTION_TAP_DANCE_DOUBLE(__VA_ARGS__)
#define DTH_MOD(KC) register_mods(MOD_BIT(KC))
#define DTH_UMOD(KC) unregister_mods(MOD_BIT(KC))
#define DTH_REG(KC) register_code16(MOD_BIT(KC))
#define DTH_UREG(KC) unregister_code16(MOD_BIT(KC))
#define DTH_SEND(STR) SEND_STRING(STR)
#define TAP_DANCE_TABLE(X)                                                                        \
    X(DT_PRN, DANCE_DOUBLE_TAP, NOP, KC_LPRN, LR_PRN)                                             \
    X(DT_CBR, DANCE_DOUBLE_TAP, NOP, KC_LCBR, LR_CBR)                                             \
    X(DT_BRC, DANCE_DOUBLE_TAP, NOP, KC_LBRC, LR_BRC)                                             \
    X(DT_TRI, DANCE_DOUBLE_TAP, NOP, KC_LT, LR_TRI)                                               \
    X(DT_QUO, DANCE_DOUBLE_TAP, NOP, KC_QUOT, LR_QUO)                                             \
    X(DT_DQU, DANCE_DOUBLE_TAP, NOP, KC_DQUO, LR_DQU)                                             \
    X(DT_GRV, DANCE_DOUBLE_TAP, NOP, KC_GRV, LR_GRV)                                              \
    X(DB_LEFT, DANCE_DOUBLE_TAP, NOP, KC_LEFT, CC_LEFT)                                           \
    X(DB_RGHT, DANCE_DOUBLE_TAP, NOP, KC_RIGHT, CC_RIGHT)                                         \
    X(DB_UP, DANCE_DOUBLE_TAP, NOP, KC_UP, CC_UP)                                                 \
    X(DB_DOWN, DANCE_DOUBLE_TAP, NOP, KC_DOWN, CC_DOWN)                                           \
    X(CTRL_LP, DANCE_TAP_HOLD, DANCE_TAP_HOLD_FNS, KC_LPRN, DTH_MOD, DTH_UMOD, KC_LCTL)           \
    X(TH_LPRN, DANCE_TAP_HOLD, DANCE_TAP_HOLD_FNS, KC_LPRN, DTH_SEND, NOP, "()" SS_TAP(X_LEFT))   \
    X(TH_LBRC, DANCE_TAP_HOLD, DANCE_TAP_HOLD_FNS, KC_LBRC, DTH_SEND, NOP, "[]" SS_TAP(X_LEFT))   \
    X(TH_LCBR, DANCE_TAP_HOLD, DANCE_TAP_HOLD_FNS, KC_LCBR, DTH_SEND, NOP, "{}" SS_TAP(X_LEFT))   \
    X(TH_QUOT, DANCE_TAP_HOLD, DANCE_TAP_HOLD_FNS, KC_QUOT, DTH_SEND, NOP, "''" SS_TAP(X_LEFT))   \
    X(TH_DQUO, DANCE_TAP_HOLD, DANCE_TAP_HOLD_FNS, KC_DQUO, DTH_SEND, NOP, "\"\"" SS_TAP(X_LEFT)) \
    X(EQL_H_Q, DANCE_TAP_HOLD, DANCE_TAP_HOLD_FNS, KC_EQL, DTH_SEND, NOP, "q")                    \
    X(UND_H_Z, DANCE_TAP_HOLD, DANCE_TAP_HOLD_FNS, KC_UNDS, DTH_SEND, NOP, "z")

#define X__NAME(N, ...) _##N
#define X_NAME(N, ...) N
#define X__ENUM(...) X__NAME(__VA_ARGS__),
#define X_ENUM(...) X_NAME(__VA_ARGS__) = TD(X__NAME(__VA_ARGS__)),
enum { TAP_DANCE_TABLE(X__ENUM) TAP_DANCE_TABLE(X_ENUM) };
#define NOP(...)
#define TAP_DANCE_ARR(N, F, G, ...) [X__NAME(N)] = F(N, __VA_ARGS__),
#define TAP_DANCE_FN(N, F, G, ...) G(N, __VA_ARGS__)

// determine the tapdance state to return
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
    } // any number higher than the maximum state value you return above
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

TAP_DANCE_TABLE(TAP_DANCE_FN)
tap_dance_action_t tap_dance_actions[] = {TAP_DANCE_TABLE(TAP_DANCE_ARR)};

// TODO: generate hint strings for the oled automatically
// TODO: try and use alternate hands home-row mod-tap
// or combos for mods/layers (only uncommon ones)
// Ctrl - Alt - Shift - Symbols
// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTYP] = LAYOUT_split_3x6_5_hlc(
     KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                                        KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
     TH_LPRN, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                                        KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_DEL,
     TH_LCBR, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    NUM_BSP, _______, _______, CTL_DEL, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_QUOT, FKEYS,
                                // GUI_ESC, NAV_TAB, KC_LSFT, SYM,     CTL_ESC, ALT_ENT, NAV_SPC, SFT_TAB, CSA_BSP, KC_ENT,
                                KC_LGUI, CTL_TAB, KC_LSFT, SYM,     CTL_ESC, SFT_ENT, NAV_SPC, ALT_TAB, CTL_BSP, CSA_ENT,
     KC_MUTE, KC_NO,  KC_NO, KC_NO, KC_NO,                                                                KC_MUTE, KC_NO, KC_NO, KC_NO, KC_NO
    ),

    [_QWERTY] = LAYOUT_split_3x6_5_hlc(
     KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                                        KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
     TH_LPRN, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,             /*LEADER FOLLOW*/          KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, TH_QUOT,
     TH_LCBR, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    ALT_RBR, _______, _______, CTL_DEL, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_UNDS,
                                KC_LGUI, CTL_BSP, KC_LSFT, HOLY,    CTL_ESC, SFT_ENT, NAV_SPC, ALT_TAB, CTL_DEL, CSA_ENT,
     _______, _______,  _______, _______, _______,                                                       _______, _______, _______, _______, _______
    ),

    [_HOLY] = LAYOUT_split_3x6_5_hlc(
     KC_GRV,  KC_PIPE, KC_PLUS, KC_EXLM, KC_LT,   KC_GT,                                       KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_BSPC,
     KC_RPRN, KC_LBRC, KC_ASTR, KC_AMPR, KC_EQL,  KC_RBRC,                                     DB_LEFT, DB_DOWN, DB_UP,   DB_RGHT, KC_BSLS, TH_DQUO,
     KC_RCBR, KC_PERC, KC_MINS, KC_HASH, KC_TILD, KC_AT,   _______, _______, _______, _______, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,
                                _______, _______, _______, _______, _______, _______, KC_SPC,  _______, _______, _______,
     _______, _______,  _______, _______, _______,                                                       _______, _______, _______, _______, _______
    ),

    [_HOLYR] = LAYOUT_split_3x6_5_hlc(
     KC_GRV,  KC_PIPE, KC_PLUS, KC_EXLM, KC_LT,   KC_GT,                                       KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_BSPC,
     KC_RPRN, KC_LBRC, KC_ASTR, KC_AMPR, KC_EQL,  KC_RBRC,                                     DB_LEFT, DB_DOWN, DB_UP,   DB_RGHT, KC_BSLS, TH_DQUO,
     KC_RCBR, KC_PERC, KC_MINS, KC_HASH, KC_TILD, KC_AT,   _______, _______, _______, _______, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,
                                _______,  _______, _______, KC_SPC,  _______, _______, _______, _______, _______, _______,
     _______, _______,  _______, _______, _______,                                                       _______, _______, _______, _______, _______
    ),

    [_SYM] = LAYOUT_split_3x6_5_hlc(
     KC_LGUI, KC_GRV,  KC_LPRN, KC_EXLM, KC_PIPE, KC_AT,                                       KC_DQUO, KC_CIRC, KC_QUES, KC_PERC, KC_0,    _______,
     KC_LCTL, KC_LCBR, KC_ASTR, KC_DLR,  KC_RCBR, KC_RPRN,                                     KC_QUOT, KC_UNDS, KC_EQL,  KC_BSLS, KC_COLN, _______,
     KC_LCA,  KC_TILD, KC_LBRC, KC_HASH, KC_AMPR, KC_RBRC, KC_LCTL, _______, _______, KC_LSFT, KC_SLSH, KC_MINS, KC_PLUS, KC_LT,   KC_GT,   KC_Z,
                                _______, _______, _______, _______, _______, KC_LALT, KC_SPC,  KC_LCTL, KC_COMM, KC_DOT,
     _______, _______,  _______, _______, _______,                                                       _______, _______, _______, _______, _______
    ),

    [_NUM] = LAYOUT_split_3x6_5_hlc(
     _____,   _____,   _____,   _____,   _____,   _____,                                       KC_LPRN, KC_1,    KC_2,    KC_3,    KC_CIRC, KC_RPRN,
     KC_HYPR, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, KC_CSA,                                      KC_PAST, KC_4,    KC_5,    KC_6,    KC_PSLS, KC_EQL,
     _____,   _____,   _____,   _____,   _____,   _____,   _______, _______, _______, _______, KC_PLUS, KC_7,    KC_8,    KC_9,    KC_PMNS, KC_UNDS,
                                _______, _______, _______, KC_LCTL, KC_LALT, _______, KC_SPC,  KC_0,    KC_COMM, KC_DOT,
     _______, _______,  _______, _______, _______,                                                       _______, _______, _______, _______, _______
    ),

    [_NUM2] = LAYOUT_split_3x6_5_hlc(
     ______,  KC_PAST, KC_PSLS, KC_PLUS, KC_PMNS, ______,                                      KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_BSPC,
     KC_HYPR, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, KC_CSA,                                      KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_GT,   KC_LT,
     ______,  KC_CIRC, KC_LPRN, KC_RPRN, KC_UNDS, ______,  _______, _______, _______, _______, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_EQL,
                                _______, _______, _______, KC_LCTL, KC_LALT, _______, _______, ____,    KC_COMM, KC_DOT,
     _______, _______,  _______, _______, _______,                                                       _______, _______, _______, _______, _______
    ),

    // TODO: https://sites.google.com/alanreiser.com/handsdown/home/hands-down-neu#h.ze4kq734zl5w
       // TODO: concentrate on 3 thumb keys for "downgrading" in the future
    [_HANDDOWNN] = LAYOUT_split_3x6_5_hlc(
     NUM_ESC, KC_W,    KC_G,    KC_M,    KC_P,    KC_V,                                        KC_EQL,  KC_COMM, KC_DOT,  KC_QUOT, KC_UNDS, KC_BSPC,
     KC_LPRN, KC_R,    KC_S,    KC_N,    KC_T,    KC_B,                                        KC_SCLN, KC_A,    KC_E,    KC_I,    KC_H,    KC_J,
     KC_LCBR, KC_X,    KC_C,    KC_L,    KC_D,    KC_F,    ALT_BSP, _______, _______, CTL_DEL, KC_SLSH, KC_U,    KC_O,    KC_Y,    KC_K,    FKEYS,
                                // KC_LGUI, NAV_TAB, KC_LSFT, HOLY,    CTL_ESC, ALT_ENT, NAV_SPC, SFT_TAB, CSA_BSP, KC_ENT,
                                KC_LGUI, NAV_TAB, KC_LSFT, HOLY,    CTL_ESC, SFT_ENT, NAV_SPC, ALT_TAB, CSA_BSP, KC_ENT,
     _______, _______,  _______, _______, _______,                                                       _______, _______, _______, _______, _______
    ),
    [_HANDDOWNR] = LAYOUT_split_3x6_5_hlc(
     NUM_ESC, KC_X,    KC_P,    KC_H,    KC_G,    KC_K,                                        KC_EQL,  KC_COMM, KC_DOT,  KC_QUOT, KC_UNDS, KC_BSPC,
     KC_LPRN, KC_C,    KC_S,    KC_N,    KC_T,    KC_J,                                        KC_SCLN, KC_A,    KC_E,    KC_I,    KC_M,    KC_DEL,
     KC_LCBR, KC_B,    KC_F,    KC_L,    KC_D,    KC_V,    ALT_BSP, _______, _______, CTL_DEL, KC_SLSH, KC_U,    KC_O,    KC_Y,    KC_W,    FKEYS,
                                KC_LGUI, NAV_TAB, KC_LSFT, HOLY_R,  CTL_ESC, ALT_ENT, NAV_SPC, SFT_TAB, CSA_BSP, KC_ENT,
     _______, _______,  _______, _______, _______,                                                       _______, _______, _______, _______, _______
    ),
    [_HOLY2] = LAYOUT_split_3x6_5_hlc(
     KC_GRV,  ____,    KC_AT,   KC_EXLM, KC_LT,   KC_GT,                                       _______, KC_1,    KC_2,    KC_3,    KC_PLUS,  KC_BSPC,
     KC_PERC, KC_CIRC, KC_AMPR, KC_DLR,  KC_LCBR, KC_RCBR,                                     KC_0,    KC_4,    KC_5,    KC_6,    KC_BSLS,  KC_DEL,
     _______, KC_TILD, KC_PIPE, KC_HASH, KC_LBRC, KC_RBRC, _______, _______, _______, _______, _______, KC_7,    KC_8,    KC_9,    KC_PMNS,  KC_EQL,
                                KC_LGUI, KC_LPRN, KC_RPRN, _______, _______, _______, KC_SPC,  _______, KC_PAST, KC_PSLS,
     _______, _______,  _______, _______, _______,                                                       _______, _______, _______, _______, _______
    ),

    // TODO: more over here
    [_NAV] = LAYOUT_split_3x6_5_hlc(
     _____,   KC_UNDO,  KC_CUT, KC_COPY, KC_PSTE, KC_REDO,                                     KC_HOME, KC_PGDN, KC_PGUP, KC_END,  KC_MENU, _______,
     _____,   KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, KC_CSA,                                      KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_ENT,  _______,
     _____,   AL_LEFT, KC_BSPC, KC_DEL,  AL_RGHT, KC_INS,  _______, _______, _______, _______, KC_BSPC, CC_BSPC, CC_DEL,  KC_DEL,  _______, FKEYS,
                                _______, _______, _______, KC_SPC,  _______, _______, _______, _______, _______, _______,
     _______, _______,  _______, _______, _______,                                                       _______, _______, _______, _______, _______
    ),


    [_MINECRAFT] = LAYOUT_split_3x6_5_hlc(
     KC_2,    KC_3,    KC_4,    KC_E,    KC_5,    KC_6,                                        _,       _,       _,       _,       _,       _______,
     KC_1,    KC_LSFT, KC_S,    KC_D,    KC_F,    KC_7,                                        _,       _,       _,       _,       _,       MINCRFT,
     KC_0,    KC_LCTL, KC_X,    KC_C,    KC_9,    KC_8,    KC_T,    _______, _______, ______,  _,       _,       _,       _,       _,       FKEYS,
                                _______, KC_LCTL, KC_LSFT, KC_SPC,  KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,
     _______, _______,  _______, _______, _______,                                                       _______, _______, _______, _______, _______
    ),

    [_FUNCTION] = LAYOUT_split_3x6_5_hlc(
     QK_BOOT, KC_PAUS, KC_MPLY, KC_MNXT, KC_MPRV, MINCRFT,                                     KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   QK_BOOT,
     _______, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, HANDDWN,                                     KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_PSCR,
     KC_CSA,  KC_F21,  KC_F22,  KC_F23,  KC_F24,  QWERTY,  RGB_TOG, _______, _______, KC_MUTE, KC_F11,  KC_F12,  KC_F13,  KC_F14,  KC_F15,  _______,
                                KC_NUM,  KC_CAPS, KC_SCRL, RGB_MOD, KC_F16,  KC_F17,  _______, KC_F18,  KC_F19,  KC_F20,
     _______, _______,  _______, _______, _______,                                                       _______, _______, _______, _______, _______
    )

//     [_LAYERINDEX] = LAYOUT_split_3x6_5_hlc(
//       _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
//       _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
//       _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
//                                  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
//     ),
};

// TODO: achordion and try home row mods again
// https://getreuer.info/posts/keyboards/achordion/index.html
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case TH_LPRN: return DOUBLE_TAP_TERM;
        default:
            return TAPPING_TERM;
    }
}

#undef X_NAME
#define X_NAME(N, ...) COMBO_##N // ##_##B
#undef X_ENUM
#define X_ENUM(N, A, B, C) X_NAME(N, A, B, C),
#define X_name(N, A, B, C) combo_##N // ##_##B
#define X_SEQ(N, A, B, C) const uint16_t PROGMEM X_name(N, A, B, C)[] = {A, B, COMBO_END};
#define X_COMBO(N, A, B, C) [X_NAME(N, A, B, C)] = COMBO(X_name(N, A, B, C), C),

enum combos { COMBOS_TABLE(X_ENUM) };
COMBOS_TABLE(X_SEQ)
combo_t key_combos[] = {COMBOS_TABLE(X_COMBO)};

#define KC_MACRO(KC, STR)            \
case KC:                         \
    if (record->event.pressed) { \
        SEND_STRING(STR);        \
        return false;            \
    }                            \
    break;
#define KC_MACRO2(KC, STR, SSTR) \
case KC:                         \
    if (record->event.pressed) { \
        if ((mods | oneshot_mods) & MOD_MASK_SHIFT && !caps_word) {\
            del_oneshot_mods(MOD_MASK_SHIFT); \
            unregister_mods(MOD_MASK_SHIFT); \
            SEND_STRING(SSTR);        \
            register_mods(mods); \
            return false;            \
        }else{\
            if (caps_word) register_mods(MOD_LSFT); \
            SEND_STRING(STR);        \
            register_mods(mods); \
            return false;            \
        }                            \
    } \
    break;
bool combo_should_trigger(uint16_t combo_index, combo_t *combo, uint16_t keycode, keyrecord_t *record) {
    /* Disable combo `SOME_COMBO` on layer `_LAYER_A` */
    switch (combo_index) {
    }
    return true;
}
bool custom_keys(uint16_t keycode, const keyrecord_t *record) {
    const uint8_t mods = get_mods();
    const uint8_t oneshot_mods = get_oneshot_mods();
    const uint8_t caps_word = is_caps_word_on();
    switch (keycode) {
        KC_MACRO2(KC_QU, "qu", "Qu") // TODO: send q if ctl/alt/gui?
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
#define KC_PAIR(N, L, R) \
        KC_MACRO2(LR_##N, L R SS_TAP(X_LEFT), L "  " R SS_TAP(X_LEFT) SS_TAP(X_LEFT)) \
        KC_MACRO2(KR_##N,  R SS_TAP(X_LEFT),  " " R SS_TAP(X_LEFT) SS_TAP(X_LEFT))
        KC_PAIR(PRN, "(", ")")
        KC_PAIR(CBR, "{", "}")
        KC_PAIR(BRC, "[", "]")
        KC_PAIR(TRI, "<", ">")
        KC_PAIR(QUO, "'", "'")
        KC_PAIR(DQU, "\"", "\"")
        KC_PAIR(GRV, "`", "`")
    }

    return true;
}
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    // Everything above here doesn't work with macros
    if (!custom_keys(keycode, record)) {
        return false;
    }

    return true;
};

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
#    define LYR_CHK(L) (IS_LAYER_ON(L))
bool encoder_update_user(uint8_t index, bool clockwise) {
    /* // clang-format off */
    switch (LAYER) {
        case _FUNCTION:
            ENCS_TAP(KC_VOLU, KC_VOLD, KC_WH_U, KC_WH_D);
            break;
        case _NAV:
            ENCS_TAP(KC_UP, KC_DOWN, KC_RIGHT, KC_LEFT);
            break;
        case _SYM:
        default:
            if (MOD_GUI) {
                ENCS_TAP(KC_RIGHT, KC_LEFT, KC_UP, KC_DOWN);
            } else {
                ENCS_TAP(KC_WH_R, KC_WH_L, KC_WH_U, KC_WH_D);
            }
    }
    /* // clang-format on */
    return false;
}
#endif
