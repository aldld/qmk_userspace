// Copyright 2023 ZSA Technology Labs, Inc <@zsa>
// Copyright 2023 Christopher Courtney, aka Drashna Jael're  (@drashna) <drashna@live.com>
// SPDX-License-Identifier: GPL-2.0-or-later

#include "keycodes.h"
#include "keymap_us.h"
#include "quantum_keycodes.h"
#include QMK_KEYBOARD_H // IWYU pragma: keep
// #include "version.h"
#include "i18n.h"
/*#include "features/achordion.h"*/

#define MOON_LED_LEVEL LED_LEVEL
#define ML_SAFE_RANGE SAFE_RANGE

#define HRM_A MT(MOD_LCTL, KC_A)
#define HRM_R MT(MOD_LALT, KC_R)
#define HRM_S MT(MOD_LGUI, KC_S)
#define HRM_T MT(MOD_LSFT, KC_T)

#define HRM_N MT(MOD_RSFT, KC_N)
#define HRM_E MT(MOD_RGUI, KC_E)
#define HRM_I MT(MOD_LALT, KC_I)
#define HRM_O MT(MOD_RCTL, KC_O)

#define OS_LCTL OSM(MOD_LCTL)
#define OS_LSFT OSM(MOD_LSFT)
#define OS_LALT OSM(MOD_LALT)
#define OS_LGUI OSM(MOD_LGUI)
#define OS_RCTL OSM(MOD_RCTL)
#define OS_RSFT OSM(MOD_RSFT)
#define OS_RALT OSM(MOD_RALT)
#define OS_RGUI OSM(MOD_RGUI)

enum layers {
    _BASE,
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
    MD_LINK,
    CLN_EQ,
    NEQ,
    MAC_LOCK,
};

// clang-format off
const char chordal_hold_layout[MATRIX_ROWS][MATRIX_COLS] PROGMEM =
    LAYOUT_voyager(
        'L','L','L','L','L','L',          'R','R','R','R','R','R',
        'L','L','L','L','L','L',          'R','R','R','R','R','R',
        'L','L','L','L','L','L',          'R','R','R','R','R','R',
        'L','L','L','L','L','L',          'R','R','R','R','R','R',
                            '*','*',  '*','*'
    );

// TODO: Consider swapping shift/enter thumb keys. Need to consider effect on
// muscle memory to avoid mixing up enter and backspace, and ergonomics of
// activating the NUM layer.

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
//    ┌────────────┬─────────────┬───────┬───────┬───────┬───────────────┐                             ┌───────────────┬─────────────┬───────┬───────┬───────┬──────────┐
//    │  MAC_LOCK  │             │       │       │       │               │                             │               │      [      │   ]   │       │       │          │
//    ├────────────┼─────────────┼───────┼───────┼───────┼───────────────┤                             ├───────────────┼─────────────┼───────┼───────┼───────┼──────────┤
//    │    tab     │      q      │   w   │   f   │   p   │       b       │                             │       j       │      l      │   u   │   y   │   ;   │    \     │
//    ├────────────┼─────────────┼───────┼───────┼───────┼───────────────┤                             ├───────────────┼─────────────┼───────┼───────┼───────┼──────────┤
//    │ ALL_T(esc) │    HRM_A    │ HRM_R │ HRM_S │ HRM_T │       g       │                             │       m       │    HRM_N    │ HRM_E │ HRM_I │ HRM_O │ ALL_T(') │
//    ├────────────┼─────────────┼───────┼───────┼───────┼───────────────┤                             ├───────────────┼─────────────┼───────┼───────┼───────┼──────────┤
//    │  MEH_T(`)  │ LT(_VIM, z) │   x   │   c   │   d   │       v       │                             │       k       │ LT(_SYM, h) │   ,   │   .   │   /   │ MEH_T(=) │
//    └────────────┴─────────────┴───────┴───────┴───────┼───────────────┼───────────────┐   ┌─────────┼───────────────┼─────────────┴───────┴───────┴───────┴──────────┘
//                                                       │ LT(_NAV, spc) │ LT(_MEDIA, -) │   │ OS_RSFT │ LT(_NUM, ent) │
//                                                       └───────────────┴───────────────┘   └─────────┴───────────────┘
[_BASE] = LAYOUT_voyager(
  MAC_LOCK         , _______        , _______ , _______ , _______ , _______            ,                                      _______            , KC_LBRC        , KC_RBRC  , _______ , _______  , _______        ,
  KC_TAB           , KC_Q           , KC_W    , KC_F    , KC_P    , KC_B               ,                                      KC_J               , KC_L           , KC_U     , KC_Y    , KC_SCLN  , KC_BSLS        ,
  ALL_T(KC_ESCAPE) , HRM_A          , HRM_R   , HRM_S   , HRM_T   , KC_G               ,                                      KC_M               , HRM_N          , HRM_E    , HRM_I   , HRM_O    , ALL_T(KC_QUOTE),
  MEH_T(KC_GRAVE)  , LT(_VIM, KC_Z) , KC_X    , KC_C    , KC_D    , KC_V               ,                                      KC_K               , LT(_SYM, KC_H) , KC_COMMA , KC_DOT  , KC_SLASH , MEH_T(KC_EQUAL),
                                                                    LT(_NAV, KC_SPACE) , LT(_MEDIA, KC_MINUS) ,     OS_RSFT , LT(_NUM, KC_ENTER)
),

//    ┌─────────┬─────┬─────┬─────┬─────┬─────┐               ┌─────┬─────────┬─────────┬─────────┬─────────┬───────────┐
//    │         │     │     │     │     │     │               │     │         │         │         │         │           │
//    ├─────────┼─────┼─────┼─────┼─────┼─────┤               ├─────┼─────────┼─────────┼─────────┼─────────┼───────────┤
//    │   up    │  [  │  7  │  8  │  9  │  ]  │               │     │         │         │         │         │           │
//    ├─────────┼─────┼─────┼─────┼─────┼─────┤               ├─────┼─────────┼─────────┼─────────┼─────────┼───────────┤
//    │ LSFT(g) │  :  │  4  │  5  │  6  │  =  │               │     │ OS_RSFT │ OS_RGUI │ OS_LALT │ OS_RCTL │ csag-none │
//    ├─────────┼─────┼─────┼─────┼─────┼─────┤               ├─────┼─────────┼─────────┼─────────┼─────────┼───────────┤
//    │  down   │  `  │  1  │  2  │  3  │  \  │               │     │         │         │         │         │ csa-none  │
//    └─────────┴─────┴─────┴─────┴─────┼─────┼─────┐   ┌─────┼─────┼─────────┴─────────┴─────────┴─────────┴───────────┘
//                                      │  0  │     │   │     │     │
//                                      └─────┴─────┘   └─────┴─────┘
[_NUM] = LAYOUT_voyager(
  _______    , _______  , _______ , _______ , _______ , _______  ,                         _______ , _______ , _______ , _______ , _______ , _______,
  KC_UP      , KC_LBRC  , KC_7    , KC_8    , KC_9    , KC_RBRC  ,                         _______ , _______ , _______ , _______ , _______ , _______,
  LSFT(KC_G) , KC_COLN  , KC_4    , KC_5    , KC_6    , KC_EQUAL ,                         _______ , OS_RSFT , OS_RGUI , OS_LALT , OS_RCTL , KC_HYPR,
  KC_DOWN    , KC_GRAVE , KC_1    , KC_2    , KC_3    , KC_BSLS  ,                         _______ , _______ , _______ , _______ , _______ , KC_MEH ,
                                                        KC_0     , _______ ,     _______ , _______
),

//    ┌─────┬─────┬─────┬─────┬─────┬─────┐               ┌─────┬────────────┬──────────┬──────────┬───────────┬───────────┐
//    │     │     │     │     │     │     │               │     │            │          │          │           │           │
//    ├─────┼─────┼─────┼─────┼─────┼─────┤               ├─────┼────────────┼──────────┼──────────┼───────────┼───────────┤
//    │  <  │  {  │  &  │  *  │  (  │  }  │               │     │            │          │          │           │           │
//    ├─────┼─────┼─────┼─────┼─────┼─────┤               ├─────┼────────────┼──────────┼──────────┼───────────┼───────────┤
//    │  >  │  :  │  $  │  %  │  ^  │  +  │               │     │ rght_SHIFT │ rght_GUI │ left_ALT │ rght_CTRL │ csag-none │
//    ├─────┼─────┼─────┼─────┼─────┼─────┤               ├─────┼────────────┼──────────┼──────────┼───────────┼───────────┤
//    │  ~  │  =  │  !  │  @  │  #  │  |  │               │     │            │          │          │           │ csa-none  │
//    └─────┴─────┴─────┴─────┴─────┼─────┼─────┐   ┌─────┼─────┼────────────┴──────────┴──────────┴───────────┴───────────┘
//                                  │  )  │     │   │     │     │
//                                  └─────┴─────┘   └─────┴─────┘
[_SYM] = LAYOUT_voyager(
  _______ , _______  , _______ , _______ , _______ , _______ ,                         _______ , _______        , _______      , _______     , _______       , _______,
  KC_LABK , KC_LCBR  , KC_AMPR , KC_ASTR , KC_LPRN , KC_RCBR ,                         _______ , _______        , _______      , _______     , _______       , _______,
  KC_RABK , KC_COLN  , KC_DLR  , KC_PERC , KC_CIRC , KC_PLUS ,                         _______ , KC_RIGHT_SHIFT , KC_RIGHT_GUI , KC_LEFT_ALT , KC_RIGHT_CTRL , KC_HYPR,
  KC_TILD , KC_EQUAL , KC_EXLM , KC_AT   , KC_HASH , KC_PIPE ,                         _______ , _______        , _______      , _______     , _______       , KC_MEH ,
                                                     KC_RPRN , _______ ,     _______ , _______
),

//    ┌─────┬─────────┬─────────┬──────────────────┬─────────────┬─────┐               ┌─────────────────┬──────────────────────────────┬──────────────────────────────┬────────────────────────────┬──────────────────────────────┬───────────┐
//    │     │         │         │                  │             │     │               │                 │                              │                              │                            │                              │           │
//    ├─────┼─────────┼─────────┼──────────────────┼─────────────┼─────┤               ├─────────────────┼──────────────────────────────┼──────────────────────────────┼────────────────────────────┼──────────────────────────────┼───────────┤
//    │     │         │         │ LCTL(LSFT(tab))  │  LCTL(tab)  │     │               │ LCTL(LSFT(tab)) │ LALT(LGUI(LCTL(LSFT(left)))) │ LALT(LGUI(LCTL(LSFT(down)))) │ LALT(LGUI(LCTL(LSFT(up)))) │ LALT(LGUI(LCTL(LSFT(rght)))) │ LCTL(tab) │
//    ├─────┼─────────┼─────────┼──────────────────┼─────────────┼─────┤               ├─────────────────┼──────────────────────────────┼──────────────────────────────┼────────────────────────────┼──────────────────────────────┼───────────┤
//    │     │ OS_LCTL │ OS_LALT │     OS_LGUI      │   OS_LSFT   │     │               │                 │             left             │             down             │             up             │             rght             │  CW_TOGG  │
//    ├─────┼─────────┼─────────┼──────────────────┼─────────────┼─────┤               ├─────────────────┼──────────────────────────────┼──────────────────────────────┼────────────────────────────┼──────────────────────────────┼───────────┤
//    │     │         │         │ SELECT_WORD_BACK │ SELECT_WORD │     │               │                 │             home             │             pgdn             │          pAGE_UP           │             end              │           │
//    └─────┴─────────┴─────────┴──────────────────┴─────────────┼─────┼─────┐   ┌─────┼─────────────────┼──────────────────────────────┴──────────────────────────────┴────────────────────────────┴──────────────────────────────┴───────────┘
//                                                               │     │     │   │ del │        :        │
//                                                               └─────┴─────┘   └─────┴─────────────────┘
[_NAV] = LAYOUT_voyager(
  _______ , _______ , _______ , _______            , _______      , _______ ,                           _______            , _______                         , _______                         , _______                       , _______                          , _______     ,
  _______ , _______ , _______ , LCTL(LSFT(KC_TAB)) , LCTL(KC_TAB) , _______ ,                           LCTL(LSFT(KC_TAB)) , LALT(LGUI(LCTL(LSFT(KC_LEFT)))) , LALT(LGUI(LCTL(LSFT(KC_DOWN)))) , LALT(LGUI(LCTL(LSFT(KC_UP)))) , LALT(LGUI(LCTL(LSFT(KC_RIGHT)))) , LCTL(KC_TAB),
  _______ , OS_LCTL , OS_LALT , OS_LGUI            , OS_LSFT      , _______ ,                           _______            , KC_LEFT                         , KC_DOWN                         , KC_UP                         , KC_RIGHT                         , CW_TOGG     ,
  _______ , _______ , _______ , SELECT_WORD_BACK   , SELECT_WORD  , _______ ,                           _______            , KC_HOME                         , KC_PGDN                         , KC_PAGE_UP                    , KC_END                           , _______     ,
                                                                    _______ , _______ ,     KC_DELETE , KC_COLN
),

//    ┌───────────┬──────────┬─────────┬─────────────────┬─────────────────────┬────────────┐                ┌──────┬────────────────────────┬────────────────────────┬──────────────────────┬────────────────────────┬─────┐
//    │           │          │         │                 │                     │            │                │      │                        │        RM_VALD         │       RM_VALU        │        RM_TOGG         │     │
//    ├───────────┼──────────┼─────────┼─────────────────┼─────────────────────┼────────────┤                ├──────┼────────────────────────┼────────────────────────┼──────────────────────┼────────────────────────┼─────┤
//    │           │ LGUI(q)  │ LGUI(w) │ LCTL(LSFT(tab)) │      LCTL(tab)      │            │                │      │ LALT(LCTL(LSFT(left))) │ LALT(LCTL(LSFT(down))) │ LALT(LCTL(LSFT(up))) │ LALT(LCTL(LSFT(rght))) │     │
//    ├───────────┼──────────┼─────────┼─────────────────┼─────────────────────┼────────────┤                ├──────┼────────────────────────┼────────────────────────┼──────────────────────┼────────────────────────┼─────┤
//    │ csag-none │ LGUI(a)  │ LGUI(r) │     LGUI(s)     │       LGUI(t)       │ ST_MACRO_0 │                │      │          mprv          │          vold          │         volu         │          mnxt          │     │
//    ├───────────┼──────────┼─────────┼─────────────────┼─────────────────────┼────────────┤                ├──────┼────────────────────────┼────────────────────────┼──────────────────────┼────────────────────────┼─────┤
//    │ csa-none  │ mAC_UNDO │ mAC_CUT │    mAC_COPY     │ LGUI(LCTL(LSFT(4))) │ mAC_PASTE  │                │      │   SENTENCE_CASE_OFF    │    SENTENCE_CASE_ON    │         bRMD         │          bRMU          │     │
//    └───────────┴──────────┴─────────┴─────────────────┴─────────────────────┼────────────┼─────┐   ┌──────┼──────┼────────────────────────┴────────────────────────┴──────────────────────┴────────────────────────┴─────┘
//                                                                             │            │     │   │ mute │ mply │
//                                                                             └────────────┴─────┘   └──────┴──────┘
[_MEDIA] = LAYOUT_voyager(
  _______ , _______     , _______    , _______            , _______                , _______      ,                               _______             , _______                   , RM_VALD                   , RM_VALU                 , RM_TOGG                    , _______,
  _______ , LGUI(KC_Q)  , LGUI(KC_W) , LCTL(LSFT(KC_TAB)) , LCTL(KC_TAB)           , _______      ,                               _______             , LALT(LCTL(LSFT(KC_LEFT))) , LALT(LCTL(LSFT(KC_DOWN))) , LALT(LCTL(LSFT(KC_UP))) , LALT(LCTL(LSFT(KC_RIGHT))) , _______,
  KC_HYPR , LGUI(KC_A)  , LGUI(KC_R) , LGUI(KC_S)         , LGUI(KC_T)             , ST_MACRO_0   ,                               _______             , KC_MEDIA_PREV_TRACK       , KC_AUDIO_VOL_DOWN         , KC_AUDIO_VOL_UP         , KC_MEDIA_NEXT_TRACK        , _______,
  KC_MEH  , KC_MAC_UNDO , KC_MAC_CUT , KC_MAC_COPY        , LGUI(LCTL(LSFT(KC_4))) , KC_MAC_PASTE ,                               _______             , SENTENCE_CASE_OFF         , SENTENCE_CASE_ON          , KC_BRMD                 , KC_BRMU                    , _______,
                                                                                     _______      , _______ ,     KC_AUDIO_MUTE , KC_MEDIA_PLAY_PAUSE
),

//    ┌─────┬─────┬─────┬─────┬─────┬─────┐               ┌────────────┬─────────┬─────────┬─────────┬─────────┬─────────┐
//    │     │     │     │     │     │     │               │            │         │         │         │         │         │
//    ├─────┼─────┼─────┼─────┼─────┼─────┤               ├────────────┼─────────┼─────────┼─────────┼─────────┼─────────┤
//    │     │     │     │     │     │     │               │  MD_LINK   │ LALT([) │         │         │ LALT(]) │ LALT(\) │
//    ├─────┼─────┼─────┼─────┼─────┼─────┤               ├────────────┼─────────┼─────────┼─────────┼─────────┼─────────┤
//    │     │     │     │     │     │     │               │ ST_MACRO_1 │ RCTL(h) │ LCTL(j) │ LCTL(k) │ LCTL(l) │         │
//    ├─────┼─────┼─────┼─────┼─────┼─────┤               ├────────────┼─────────┼─────────┼─────────┼─────────┼─────────┤
//    │     │     │     │     │     │     │               │ ST_MACRO_2 │ LALT(h) │ LALT(j) │ LALT(k) │ LALT(l) │         │
//    └─────┴─────┴─────┴─────┴─────┼─────┼─────┐   ┌─────┼────────────┼─────────┴─────────┴─────────┴─────────┴─────────┘
//                                  │     │     │   │     │            │
//                                  └─────┴─────┘   └─────┴────────────┘
[_VIM] = LAYOUT_voyager(
  _______ , _______ , _______ , _______ , _______ , _______ ,                         _______    , _______       , _______    , _______    , _______       , _______      ,
  _______ , _______ , _______ , _______ , _______ , _______ ,                         MD_LINK    , LALT(KC_LBRC) , _______    , _______    , LALT(KC_RBRC) , LALT(KC_BSLS),
  _______ , _______ , _______ , _______ , _______ , _______ ,                         ST_MACRO_1 , RCTL(KC_H)    , LCTL(KC_J) , LCTL(KC_K) , LCTL(KC_L)    , _______      ,
  _______ , _______ , _______ , _______ , _______ , _______ ,                         ST_MACRO_2 , LALT(KC_H)    , LALT(KC_J) , LALT(KC_K) , LALT(KC_L)    , _______      ,
                                                    _______ , _______ ,     _______ , _______
)
};
// clang-format on

// const uint16_t PROGMEM combo_tg[] = {MT(MOD_LSFT, KC_T), KC_G, COMBO_END};
// const uint16_t PROGMEM combo_mn[] = {KC_M, MT(MOD_RSFT, KC_N), COMBO_END};
//
// TODO: Use macro in docs for defining combos.
//



// const uint16_t PROGMEM x = _w;

const uint16_t PROGMEM combo_fs[] = {KC_F, HRM_S, COMBO_END}; // [
const uint16_t PROGMEM combo_pt[] = {KC_P, HRM_T, COMBO_END}; // ]
const uint16_t PROGMEM combo_ln[] = {KC_L, HRM_N, COMBO_END}; // [
const uint16_t PROGMEM combo_ue[] = {KC_U, HRM_E, COMBO_END}; // ]

const uint16_t PROGMEM combo_nh[] = {HRM_N, LT(_SYM, KC_H), COMBO_END}; // _

const uint16_t PROGMEM combo_tg[] = {HRM_T, KC_G, COMBO_END}; // oneshot shift
const uint16_t PROGMEM combo_mn[] = {KC_M, HRM_N, COMBO_END}; // backspace
const uint16_t PROGMEM combo_lu[] = {KC_L, KC_U, COMBO_END}; // C-s (wezterm leader)
const uint16_t PROGMEM combo_ly[] = {KC_L, KC_Y, COMBO_END}; // alt-shift-; (aerospace service mode binding)


const uint16_t PROGMEM combo_az[] = {HRM_A, LT(_VIM, KC_Z), COMBO_END}; // :=
const uint16_t PROGMEM combo_zx[] = {LT(_VIM, KC_Z), KC_X, COMBO_END};  // !=


const uint16_t PROGMEM combo_fp[] = {KC_F, KC_P, COMBO_END};           // backspace
const uint16_t PROGMEM combo_uy[] = {KC_U, KC_Y, COMBO_END};           // backspace
const uint16_t PROGMEM combo_ysem[] = {KC_Y, KC_SEMICOLON, COMBO_END}; // delete

const uint16_t PROGMEM combo_spcenter[] = {LT(_NAV, KC_SPACE), LT(_NUM, KC_ENTER), COMBO_END}; // :


// const uint16_t PROGMEM combo_spcminus[] =  {LT(_NAV, KC_SPACE) , LT(_MEDIA, KC_MINUS), COMBO_END};


combo_t key_combos[] = {
    // COMBO(combo_tg, KC_LBRC),
    // COMBO(combo_mn, KC_RBRC),


    COMBO(combo_fs, KC_LBRC),
    COMBO(combo_pt, KC_RBRC),
    COMBO(combo_ln, KC_LBRC),
    COMBO(combo_ue, KC_RBRC),

    COMBO(combo_nh, KC_UNDERSCORE),

    COMBO(combo_tg, OS_LSFT),
    COMBO(combo_mn, KC_BSPC),
    COMBO(combo_lu, RCTL(KC_S)),
    COMBO(combo_ly, LSFT(LALT(KC_SCLN))),

    COMBO(combo_az, CLN_EQ),
    COMBO(combo_zx, NEQ),

    COMBO(combo_fp, KC_BSPC),
    COMBO(combo_uy, KC_BSPC),
    COMBO(combo_ysem, KC_DELETE),

    COMBO(combo_spcenter, KC_COLN),

    // COMBO(combo_spcminus, KC_UNDERSCORE),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
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

        case MD_LINK:
            if (record->event.pressed) {
                SEND_STRING("[]()" SS_TAP(X_LEFT) SS_TAP(X_LEFT) SS_TAP(X_LEFT));
            }
            break;

        case CLN_EQ:
            if (record->event.pressed) {
                SEND_STRING(":=");
            }
            break;
        case NEQ:
            if (record->event.pressed) {
                SEND_STRING("!=");
            }
            break;
    }
    return true;
}

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        // Shorter tapping term for shift mod keys.
        case MT(MOD_LSFT, KC_T):
        case MT(MOD_RSFT, KC_N):
            return 200;

        // Nav/num layer tap thumb keys
        case LT(_NAV, KC_SPACE):
        case LT(_NUM, KC_ENTER):

        // Symbol layer tap
        case LT(_SYM, KC_H):
            return 155;
        default:
            return TAPPING_TERM;
    }
}

uint16_t get_flow_tap_term(uint16_t keycode, keyrecord_t *record, uint16_t prev_keycode) {
    // Only apply to home row mods, excluding shift.
    switch (keycode) {
        case MT(MOD_LSFT, KC_T):
        case MT(MOD_RSFT, KC_N):
            return 100;

        case MT(MOD_LCTL, KC_A):
        case MT(MOD_LALT, KC_R):
        case MT(MOD_LGUI, KC_S):
        case MT(MOD_RGUI, KC_E):
        case MT(MOD_LALT, KC_I):
        case MT(MOD_RCTL, KC_O):
            return FLOW_TAP_TERM;
    }

    return 0;
}
