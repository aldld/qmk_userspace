// Copyright 2023 ZSA Technology Labs, Inc <@zsa>
// Copyright 2023 Christopher Courtney, aka Drashna Jael're  (@drashna) <drashna@live.com>
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
#include "version.h"
#include "i18n.h"
#include "features/achordion.h"

#define MOON_LED_LEVEL LED_LEVEL
#define ML_SAFE_RANGE SAFE_RANGE

enum layers {
    _BASE,
    _QWERTY,
    _NUM,
    _SYM,
    _NAV,
    _MEDIA,
    _VIM,
};

enum custom_keycodes {
    RGB_SLD = ML_SAFE_RANGE,
    ST_MACRO_0,
    ST_MACRO_1,
    ST_MACRO_2,
    MAC_LOCK,
};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
//    ┌────────────┬─────────────────┬─────────────────┬─────────────────┬─────────────────┬───────────────┐                          ┌───────────────┬─────────────────┬─────────────────┬─────────────────┬─────────────────┬──────────┐
//    │  MAC_LOCK  │                 │                 │                 │                 │               │                          │               │                 │                 │                 │                 │          │
//    ├────────────┼─────────────────┼─────────────────┼─────────────────┼─────────────────┼───────────────┤                          ├───────────────┼─────────────────┼─────────────────┼─────────────────┼─────────────────┼──────────┤
//    │    tab     │        q        │        w        │        f        │        p        │       b       │                          │       j       │        l        │        u        │        y        │        ;        │    \     │
//    ├────────────┼─────────────────┼─────────────────┼─────────────────┼─────────────────┼───────────────┤                          ├───────────────┼─────────────────┼─────────────────┼─────────────────┼─────────────────┼──────────┤
//    │ ALL_T(esc) │ MT(MOD_LCTL, a) │ MT(MOD_LALT, r) │ MT(MOD_LGUI, s) │ MT(MOD_LSFT, t) │       g       │                          │       m       │ MT(MOD_RSFT, n) │ MT(MOD_RGUI, e) │ MT(MOD_LALT, i) │ MT(MOD_RCTL, o) │ ALL_T(') │
//    ├────────────┼─────────────────┼─────────────────┼─────────────────┼─────────────────┼───────────────┤                          ├───────────────┼─────────────────┼─────────────────┼─────────────────┼─────────────────┼──────────┤
//    │  MEH_T(`)  │   LT(_VIM, z)   │        x        │        c        │        d        │       v       │                          │       k       │   LT(_SYM, h)   │        ,        │        .        │        /        │ MEH_T(=) │
//    └────────────┴─────────────────┴─────────────────┴─────────────────┴─────────────────┼───────────────┼───────────────┐   ┌──────┼───────────────┼─────────────────┴─────────────────┴─────────────────┴─────────────────┴──────────┘
//                                                                                         │ LT(_NAV, spc) │ LT(_MEDIA, -) │   │ bspc │ LT(_NUM, ent) │
//                                                                                         └───────────────┴───────────────┘   └──────┴───────────────┘
[_BASE] = LAYOUT_voyager(
  MAC_LOCK         , _______            , _______            , _______            , _______            , _______            ,                                      _______            , _______            , _______            , _______            , _______            , _______        ,
  KC_TAB           , KC_Q               , KC_W               , KC_F               , KC_P               , KC_B               ,                                      KC_J               , KC_L               , KC_U               , KC_Y               , KC_SCLN            , KC_BSLS        ,
  ALL_T(KC_ESCAPE) , MT(MOD_LCTL, KC_A) , MT(MOD_LALT, KC_R) , MT(MOD_LGUI, KC_S) , MT(MOD_LSFT, KC_T) , KC_G               ,                                      KC_M               , MT(MOD_RSFT, KC_N) , MT(MOD_RGUI, KC_E) , MT(MOD_LALT, KC_I) , MT(MOD_RCTL, KC_O) , ALL_T(KC_QUOTE),
  MEH_T(KC_GRAVE)  , LT(_VIM, KC_Z)     , KC_X               , KC_C               , KC_D               , KC_V               ,                                      KC_K               , LT(_SYM, KC_H)     , KC_COMMA           , KC_DOT             , KC_SLASH           , MEH_T(KC_EQUAL),
                                                                                                         LT(_NAV, KC_SPACE) , LT(_MEDIA, KC_MINUS) ,     KC_BSPC , LT(_NUM, KC_ENTER)
),

//    ┌─────┬─────────────────┬─────────────────┬─────────────────┬─────────────────┬─────┐               ┌───────┬─────────────────┬─────────────────┬─────────────────┬─────────────────┬─────┐
//    │     │                 │                 │                 │                 │     │               │ TO(0) │                 │                 │                 │                 │     │
//    ├─────┼─────────────────┼─────────────────┼─────────────────┼─────────────────┼─────┤               ├───────┼─────────────────┼─────────────────┼─────────────────┼─────────────────┼─────┤
//    │     │        q        │        w        │        e        │        r        │  t  │               │   y   │        u        │        i        │        o        │        p        │     │
//    ├─────┼─────────────────┼─────────────────┼─────────────────┼─────────────────┼─────┤               ├───────┼─────────────────┼─────────────────┼─────────────────┼─────────────────┼─────┤
//    │     │ MT(MOD_LCTL, a) │ MT(MOD_LALT, s) │ MT(MOD_LGUI, d) │ MT(MOD_LSFT, f) │  g  │               │   h   │ MT(MOD_RSFT, j) │ MT(MOD_RGUI, k) │ MT(MOD_LALT, l) │ MT(MOD_RCTL, ;) │     │
//    ├─────┼─────────────────┼─────────────────┼─────────────────┼─────────────────┼─────┤               ├───────┼─────────────────┼─────────────────┼─────────────────┼─────────────────┼─────┤
//    │     │    LT(6, z)     │        x        │        c        │        v        │  b  │               │   n   │    LT(3, m)     │        ,        │        .        │        /        │     │
//    └─────┴─────────────────┴─────────────────┴─────────────────┴─────────────────┼─────┼─────┐   ┌─────┼───────┼─────────────────┴─────────────────┴─────────────────┴─────────────────┴─────┘
//                                                                                  │     │     │   │     │       │
//                                                                                  └─────┴─────┘   └─────┴───────┘
[_QWERTY] = LAYOUT_voyager(
  _______ , _______            , _______            , _______            , _______            , _______ ,                         TO(0)   , _______            , _______            , _______            , _______               , _______,
  _______ , KC_Q               , KC_W               , KC_E               , KC_R               , KC_T    ,                         KC_Y    , KC_U               , KC_I               , KC_O               , KC_P                  , _______,
  _______ , MT(MOD_LCTL, KC_A) , MT(MOD_LALT, KC_S) , MT(MOD_LGUI, KC_D) , MT(MOD_LSFT, KC_F) , KC_G    ,                         KC_H    , MT(MOD_RSFT, KC_J) , MT(MOD_RGUI, KC_K) , MT(MOD_LALT, KC_L) , MT(MOD_RCTL, KC_SCLN) , _______,
  _______ , LT(6, KC_Z)        , KC_X               , KC_C               , KC_V               , KC_B    ,                         KC_N    , LT(3, KC_M)        , KC_COMMA           , KC_DOT             , KC_SLASH              , _______,
                                                                                                _______ , _______ ,     _______ , _______
),

//    ┌─────────┬─────┬─────┬─────┬─────┬─────┐               ┌─────┬──────┬──────┬──────┬──────┬───────────┐
//    │         │     │     │     │     │     │               │     │      │      │      │      │           │
//    ├─────────┼─────┼─────┼─────┼─────┼─────┤               ├─────┼──────┼──────┼──────┼──────┼───────────┤
//    │   up    │  [  │  7  │  8  │  9  │  ]  │               │     │      │      │      │      │           │
//    ├─────────┼─────┼─────┼─────┼─────┼─────┤               ├─────┼──────┼──────┼──────┼──────┼───────────┤
//    │ LSFT(g) │  ;  │  4  │  5  │  6  │  =  │               │     │ rsft │ rgui │ lalt │ rctl │ csag-none │
//    ├─────────┼─────┼─────┼─────┼─────┼─────┤               ├─────┼──────┼──────┼──────┼──────┼───────────┤
//    │  down   │  `  │  1  │  2  │  3  │  \  │               │     │      │      │      │      │ csa-none  │
//    └─────────┴─────┴─────┴─────┴─────┼─────┼─────┐   ┌─────┼─────┼──────┴──────┴──────┴──────┴───────────┘
//                                      │  0  │     │   │     │     │
//                                      └─────┴─────┘   └─────┴─────┘
[_NUM] = LAYOUT_voyager(
  _______    , _______  , _______ , _______ , _______ , _______  ,                         _______ , _______ , _______ , _______ , _______ , _______,
  KC_UP      , KC_LBRC  , KC_7    , KC_8    , KC_9    , KC_RBRC  ,                         _______ , _______ , _______ , _______ , _______ , _______,
  LSFT(KC_G) , KC_SCLN  , KC_4    , KC_5    , KC_6    , KC_EQUAL ,                         _______ , KC_RSFT , KC_RGUI , KC_LALT , KC_RCTL , KC_HYPR,
  KC_DOWN    , KC_GRAVE , KC_1    , KC_2    , KC_3    , KC_BSLS  ,                         _______ , _______ , _______ , _______ , _______ , KC_MEH ,
                                                        KC_0     , _______ ,     _______ , _______
),

//    ┌─────┬─────┬─────┬─────┬─────┬─────┐               ┌─────┬──────┬──────┬──────┬──────┬───────────┐
//    │     │     │     │     │     │     │               │     │      │      │      │      │           │
//    ├─────┼─────┼─────┼─────┼─────┼─────┤               ├─────┼──────┼──────┼──────┼──────┼───────────┤
//    │  <  │  {  │  &  │  *  │  (  │  }  │               │     │      │      │      │      │           │
//    ├─────┼─────┼─────┼─────┼─────┼─────┤               ├─────┼──────┼──────┼──────┼──────┼───────────┤
//    │  >  │  :  │  $  │  %  │  ^  │  +  │               │     │ rsft │ rgui │ lalt │ rctl │ csag-none │
//    ├─────┼─────┼─────┼─────┼─────┼─────┤               ├─────┼──────┼──────┼──────┼──────┼───────────┤
//    │  ~  │  =  │  !  │  @  │  #  │  |  │               │     │      │      │      │      │ csa-none  │
//    └─────┴─────┴─────┴─────┴─────┼─────┼─────┐   ┌─────┼─────┼──────┴──────┴──────┴──────┴───────────┘
//                                  │  )  │     │   │     │     │
//                                  └─────┴─────┘   └─────┴─────┘
[_SYM] = LAYOUT_voyager(
  _______ , _______  , _______ , _______ , _______ , _______ ,                         _______ , _______ , _______ , _______ , _______ , _______,
  KC_LABK , KC_LCBR  , KC_AMPR , KC_ASTR , KC_LPRN , KC_RCBR ,                         _______ , _______ , _______ , _______ , _______ , _______,
  KC_RABK , KC_COLN  , KC_DLR  , KC_PERC , KC_CIRC , KC_PLUS ,                         _______ , KC_RSFT , KC_RGUI , KC_LALT , KC_RCTL , KC_HYPR,
  KC_TILD , KC_EQUAL , KC_EXLM , KC_AT   , KC_HASH , KC_PIPE ,                         _______ , _______ , _______ , _______ , _______ , KC_MEH ,
                                                     KC_RPRN , _______ ,     _______ , _______
),

//    ┌───────────┬──────┬──────┬──────┬──────┬─────┐               ┌─────┬────────────┬─────────────────┬───────────┬────────────┬─────────┐
//    │           │      │      │      │      │     │               │     │            │                 │           │            │         │
//    ├───────────┼──────┼──────┼──────┼──────┼─────┤               ├─────┼────────────┼─────────────────┼───────────┼────────────┼─────────┤
//    │           │      │      │      │      │     │               │     │ LCTL(left) │ LCTL(LSFT(tab)) │ LCTL(tab) │ LCTL(rght) │         │
//    ├───────────┼──────┼──────┼──────┼──────┼─────┤               ├─────┼────────────┼─────────────────┼───────────┼────────────┼─────────┤
//    │ csag-none │ lctl │ lalt │ lgui │ lsft │     │               │     │    left    │      down       │    up     │    rght    │ CW_TOGG │
//    ├───────────┼──────┼──────┼──────┼──────┼─────┤               ├─────┼────────────┼─────────────────┼───────────┼────────────┼─────────┤
//    │ csa-none  │      │      │      │      │     │               │     │    home    │      pgdn       │  pAGE_UP  │    end     │         │
//    └───────────┴──────┴──────┴──────┴──────┼─────┼─────┐   ┌─────┼─────┼────────────┴─────────────────┴───────────┴────────────┴─────────┘
//                                            │     │     │   │ del │  :  │
//                                            └─────┴─────┘   └─────┴─────┘
[_NAV] = LAYOUT_voyager(
  _______ , _______ , _______ , _______ , _______ , _______ ,                           _______ , _______       , _______            , _______      , _______        , _______,
  _______ , _______ , _______ , _______ , _______ , _______ ,                           _______ , LCTL(KC_LEFT) , LCTL(LSFT(KC_TAB)) , LCTL(KC_TAB) , LCTL(KC_RIGHT) , _______,
  KC_HYPR , KC_LCTL , KC_LALT , KC_LGUI , KC_LSFT , _______ ,                           _______ , KC_LEFT       , KC_DOWN            , KC_UP        , KC_RIGHT       , CW_TOGG,
  KC_MEH  , _______ , _______ , _______ , _______ , _______ ,                           _______ , KC_HOME       , KC_PGDN            , KC_PAGE_UP   , KC_END         , _______,
                                                    _______ , _______ ,     KC_DELETE , KC_COLN
),

//    ┌─────┬──────────┬─────────┬──────────┬─────────────────────┬────────────┐                ┌─────────────┬──────┬──────┬──────┬──────┬─────┐
//    │     │          │         │          │                     │            │                │ TO(_QWERTY) │      │      │      │      │     │
//    ├─────┼──────────┼─────────┼──────────┼─────────────────────┼────────────┤                ├─────────────┼──────┼──────┼──────┼──────┼─────┤
//    │     │ LGUI(q)  │ LGUI(w) │          │                     │            │                │             │      │      │      │      │     │
//    ├─────┼──────────┼─────────┼──────────┼─────────────────────┼────────────┤                ├─────────────┼──────┼──────┼──────┼──────┼─────┤
//    │     │ LGUI(a)  │ LGUI(r) │ LGUI(s)  │       LGUI(t)       │ ST_MACRO_0 │                │             │ mprv │ vold │ volu │ mnxt │     │
//    ├─────┼──────────┼─────────┼──────────┼─────────────────────┼────────────┤                ├─────────────┼──────┼──────┼──────┼──────┼─────┤
//    │     │ mAC_UNDO │ mAC_CUT │ mAC_COPY │ LGUI(LCTL(LSFT(4))) │ mAC_PASTE  │                │             │      │      │      │      │     │
//    └─────┴──────────┴─────────┴──────────┴─────────────────────┼────────────┼─────┐   ┌──────┼─────────────┼──────┴──────┴──────┴──────┴─────┘
//                                                                │            │     │   │ mute │    mply     │
//                                                                └────────────┴─────┘   └──────┴─────────────┘
[_MEDIA] = LAYOUT_voyager(
  _______ , _______     , _______    , _______     , _______                , _______      ,                               TO(_QWERTY)         , _______             , _______           , _______         , _______             , _______,
  _______ , LGUI(KC_Q)  , LGUI(KC_W) , _______     , _______                , _______      ,                               _______             , _______             , _______           , _______         , _______             , _______,
  _______ , LGUI(KC_A)  , LGUI(KC_R) , LGUI(KC_S)  , LGUI(KC_T)             , ST_MACRO_0   ,                               _______             , KC_MEDIA_PREV_TRACK , KC_AUDIO_VOL_DOWN , KC_AUDIO_VOL_UP , KC_MEDIA_NEXT_TRACK , _______,
  _______ , KC_MAC_UNDO , KC_MAC_CUT , KC_MAC_COPY , LGUI(LCTL(LSFT(KC_4))) , KC_MAC_PASTE ,                               _______             , _______             , _______           , _______         , _______             , _______,
                                                                              _______      , _______ ,     KC_AUDIO_MUTE , KC_MEDIA_PLAY_PAUSE
),

//    ┌───────────┬──────┬──────┬──────┬──────┬─────┐               ┌────────────┬─────────┬─────────┬─────────┬─────────┬─────┐
//    │           │      │      │      │      │     │               │            │         │         │         │         │     │
//    ├───────────┼──────┼──────┼──────┼──────┼─────┤               ├────────────┼─────────┼─────────┼─────────┼─────────┼─────┤
//    │           │      │      │      │      │     │               │            │         │         │         │         │     │
//    ├───────────┼──────┼──────┼──────┼──────┼─────┤               ├────────────┼─────────┼─────────┼─────────┼─────────┼─────┤
//    │ csag-none │ lctl │ lalt │ lgui │ lsft │     │               │ ST_MACRO_1 │ RCTL(h) │ LCTL(j) │ LCTL(k) │ LCTL(l) │     │
//    ├───────────┼──────┼──────┼──────┼──────┼─────┤               ├────────────┼─────────┼─────────┼─────────┼─────────┼─────┤
//    │ csa-none  │      │      │      │      │     │               │ ST_MACRO_2 │ LALT(h) │ LALT(j) │ LALT(k) │ LALT(l) │     │
//    └───────────┴──────┴──────┴──────┴──────┼─────┼─────┐   ┌─────┼────────────┼─────────┴─────────┴─────────┴─────────┴─────┘
//                                            │     │     │   │     │            │
//                                            └─────┴─────┘   └─────┴────────────┘
[_VIM] = LAYOUT_voyager(
  _______ , _______ , _______ , _______ , _______ , _______ ,                         _______    , _______    , _______    , _______    , _______    , _______,
  _______ , _______ , _______ , _______ , _______ , _______ ,                         _______    , _______    , _______    , _______    , _______    , _______,
  KC_HYPR , KC_LCTL , KC_LALT , KC_LGUI , KC_LSFT , _______ ,                         ST_MACRO_1 , RCTL(KC_H) , LCTL(KC_J) , LCTL(KC_K) , LCTL(KC_L) , _______,
  KC_MEH  , _______ , _______ , _______ , _______ , _______ ,                         ST_MACRO_2 , LALT(KC_H) , LALT(KC_J) , LALT(KC_K) , LALT(KC_L) , _______,
                                                    _______ , _______ ,     _______ , _______
)
};
// clang-format on

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!process_achordion(keycode, record)) {
        return false;
    }
    switch (keycode) {
        case ST_MACRO_0:
            if (record->event.pressed) {
                SEND_STRING(SS_LGUI(SS_TAP(X_L)) SS_DELAY(100) SS_LGUI(SS_TAP(X_C)));
            }
            break;
        case ST_MACRO_1:
            if (record->event.pressed) {
                SEND_STRING(SS_TAP(X_ESCAPE) SS_DELAY(100) SS_LSFT(SS_TAP(X_SCLN)) SS_DELAY(100) SS_TAP(X_V) SS_DELAY(100) SS_TAP(X_S) SS_DELAY(100) SS_TAP(X_ENTER));
            }
            break;
        case ST_MACRO_2:
            if (record->event.pressed) {
                SEND_STRING(SS_TAP(X_ESCAPE) SS_DELAY(100) SS_LSFT(SS_TAP(X_SCLN)) SS_DELAY(100) SS_TAP(X_S) SS_DELAY(100) SS_TAP(X_P) SS_DELAY(100) SS_TAP(X_ENTER));
            }
            break;
        case MAC_LOCK:
            HCS(0x19E);

        case RGB_SLD:
            if (record->event.pressed) {
                rgblight_mode(1);
            }
            return false;
    }
    return true;
}

uint16_t achordion_streak_chord_timeout(uint16_t tap_hold_keycode, uint16_t next_keycode) {
    if (IS_QK_LAYER_TAP(tap_hold_keycode)) {
        return 0; // Disable streak detection on layer-tap keys.
    }

    // Otherwise, tap_hold_keycode is a mod-tap key.
    uint8_t mod = mod_config(QK_MOD_TAP_GET_MODS(tap_hold_keycode));
    if ((mod & MOD_LSFT) != 0 || (mod & MOD_RSFT) != 0) {
        return 50; // A shorter streak timeout for Shift mod-tap keys.
    } else {
        return 400; // A longer timeout otherwise.
    }
}

bool achordion_eager_mod(uint8_t mod) {
    switch (mod) {
        case MOD_LSFT:
        case MOD_RSFT:
        case MOD_LGUI:
        case MOD_RGUI:
        case MOD_LCTL:
        case MOD_RCTL:
            return true; // Eagerly apply Shift, GUI, and Ctrl mods.

        default:
            return false;
    }
}

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        // Shorter tapping term for shift mod keys.
        case MT(MOD_LSFT, KC_T):
        case MT(MOD_RSFT, KC_N):
            return 130;
        default:
            return TAPPING_TERM;
    }
}

void matrix_scan_user(void) {
    achordion_task();
}

bool is_thumb_key(keyrecord_t *record) {
    return record->event.key.row % (MATRIX_ROWS / 2) >= 4;
}

bool achordion_chord(uint16_t tap_hold_keycode, keyrecord_t *tap_hold_record, uint16_t other_keycode, keyrecord_t *other_record) {
    return is_thumb_key(tap_hold_record) || is_thumb_key(other_record) || achordion_opposite_hands(tap_hold_record, other_record);
}
