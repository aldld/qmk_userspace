/* Copyright 2023 Colin Lam (Ploopy Corporation)
 * Copyright 2020 Christopher Courtney, aka Drashna Jael're  (@drashna) <drashna@live.com>
 * Copyright 2019 Sunjun Kim
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
#include "keycodes.h"
#include QMK_KEYBOARD_H

// top left, top middle left, top middle right, top right, bottom left, bottom
// right
//
// Idea:
// top left: alt-tab (switch displays)
// middle left: back? (forward on double click?)
// middle right: forward? or middle click?
// top right: right click, drag scroll when held, toggle drag scroll when double
// clicked? Or top right + bottom left?
// bottom left: left click
// bottom right: middle click?
//
// Functions that could be useful
// Note: mouse/trackball mainly used for browser
// browser tab switching
// close tab/window
// toggle drag scrolling
// activate drag scrolling with key
//

typedef enum {
    TD_NONE,
    TD_UNKNOWN,
    TD_SINGLE_TAP,
    TD_SINGLE_HOLD,
    TD_DOUBLE_TAP,
    TD_DOUBLE_HOLD,
    TD_DOUBLE_SINGLE_TAP, // Send two single taps
    TD_TRIPLE_TAP,
    TD_TRIPLE_HOLD
} td_state_t;

td_state_t cur_dance(tap_dance_state_t *state);

enum td_keycodes {
    // single tap: btn2
    // hold: activate layer 1 and enable drag scroll
    MSE_BTN2_DRAG,
    LOCK_DRAG_SCROLL,
    BACK_FWD
};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
        LGUI(LALT(KC_TAB)), TD(BACK_FWD), KC_BTN3,  TD(MSE_BTN2_DRAG),
                 KC_BTN1, KC_BTN3
    ),
    [1] = LAYOUT( // Activate by holding top right
        _______, _______, _______, _______,
                 TD(LOCK_DRAG_SCROLL),  _______ // lock drag scroll
    )
};
// clang-format on

extern bool is_drag_scroll;
td_state_t  msbtn2_state           = TD_NONE;
td_state_t  lock_drag_scroll_state = TD_NONE;
bool        is_drag_scroll_locked  = false;

void msebtn2_finished(tap_dance_state_t *state, void *user_data) {
    msbtn2_state = cur_dance(state);
    switch (msbtn2_state) {
        case TD_SINGLE_HOLD:
            is_drag_scroll = true;
            layer_on(1);
            break;
        default:
            break;
    }
}
void msebtn2_reset(tap_dance_state_t *state, void *user_data) {
    switch (msbtn2_state) {
        case TD_SINGLE_TAP:
            if (is_drag_scroll_locked) {
                is_drag_scroll_locked = false;
                is_drag_scroll        = false;
            } else {
                tap_code16(KC_BTN2);
            }
            break;
        case TD_SINGLE_HOLD:
            if (!is_drag_scroll_locked) {
                is_drag_scroll = false;
            }
            layer_off(1);
            break;
        default:
            break;
    }
}

void lock_drag_scroll_finished(tap_dance_state_t *state, void *user_data) {
    lock_drag_scroll_state = cur_dance(state);
}
void lock_drag_scroll_reset(tap_dance_state_t *state, void *user_data) {
    switch (lock_drag_scroll_state) {
        case TD_SINGLE_TAP:
            is_drag_scroll        = true;
            is_drag_scroll_locked = true;
            break;
        default:
            break;
    }
}

tap_dance_action_t tap_dance_actions[] = {
    [MSE_BTN2_DRAG]    = ACTION_TAP_DANCE_FN_ADVANCED(NULL, msebtn2_finished, msebtn2_reset),
    [LOCK_DRAG_SCROLL] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, lock_drag_scroll_finished, lock_drag_scroll_reset),
    [BACK_FWD]         = ACTION_TAP_DANCE_DOUBLE(LGUI(KC_LBRC), LGUI(KC_RBRC)),
};

td_state_t cur_dance(tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) return TD_SINGLE_TAP;
        // Key has not been interrupted, but the key is still held. Means you want to send a 'HOLD'.
        else
            return TD_SINGLE_HOLD;
    } else if (state->count == 2) {
        // TD_DOUBLE_SINGLE_TAP is to distinguish between typing "pepper", and actually wanting a double tap
        // action when hitting 'pp'. Suggested use case for this return value is when you want to send two
        // keystrokes of the key, and not the 'double tap' action/macro.
        if (state->interrupted)
            return TD_DOUBLE_SINGLE_TAP;
        else if (state->pressed)
            return TD_DOUBLE_HOLD;
        else
            return TD_DOUBLE_TAP;
    }

    // Assumes no one is trying to type the same letter three times (at least not quickly).
    // If your tap dance key is 'KC_W', and you want to type "www." quickly - then you will need to add
    // an exception here to return a 'TD_TRIPLE_SINGLE_TAP', and define that enum just like 'TD_DOUBLE_SINGLE_TAP'
    if (state->count == 3) {
        if (state->interrupted || !state->pressed)
            return TD_TRIPLE_TAP;
        else
            return TD_TRIPLE_HOLD;
    } else
        return TD_UNKNOWN;
}
