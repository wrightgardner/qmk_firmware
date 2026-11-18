/* Copyright 2018 James Laird-Wah
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

/* layer constants */
// enum {
//   DEF = 0,
//   NUM,
//   FUN,
// };


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(QK_BOOT, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, TG(1), KC_GRV, KC_Q, KC_W, KC_E, KC_R, KC_T, RM_NEXT, KC_TRNS, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_EQL, KC_PGUP, KC_A, KC_S, KC_D, KC_F, KC_G, KC_TAB, KC_ENT, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_PGDN, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_ESC, KC_TRNS, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_MINS, KC_LGUI, KC_LALT, KC_BSPC, KC_SPC, KC_LCTL, KC_RCTL, KC_LSFT, KC_RSFT, MO(2), MO(2)),
    [1] = LAYOUT(KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_PMNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_MINS, KC_7, KC_8, KC_9, KC_PPLS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_4, KC_5, KC_6, KC_PEQL, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_ASTR, KC_1, KC_2, KC_3, KC_PSLS, KC_PENT, KC_TRNS, KC_DOT, KC_TRNS, KC_0, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),
    [2] = LAYOUT(QK_BOOT, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_TAB, KC_TRNS, MS_WHLL, MS_UP, MS_RGHT, MS_WHLD, RM_TOGG, KC_MPRV, KC_MNXT, KC_LCBR, KC_RCBR, KC_LBRC, KC_RBRC, KC_F12, KC_HOME, KC_TRNS, MS_LEFT, MS_DOWN, MS_RGHT, MS_WHLU, KC_TRNS, KC_MPLY, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, KC_TRNS, KC_TRNS, KC_END, KC_PSCR, KC_INS, MS_BTN2, MS_BTN1, KC_TRNS, KC_TRNS, KC_TRNS, KC_MUTE, KC_VOLD, KC_VOLU, KC_TRNS, KC_BSLS, KC_PIPE, KC_TRNS, KC_TRNS, KC_DEL, KC_ENT, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS)
};

// // Layer-taps (Z workspace layer + thumb layers): hold as soon as any other key
// // goes down, regardless of hand. FLOW_TAP_TERM still keeps them taps mid-flow.
// // Right-shift on /: hold on the next keypress, but chordal hold still makes
// // same-hand follow-ups (/usr, /home) tap.
// bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record) {
//     return IS_QK_LAYER_TAP(keycode) || keycode == RSFT_T(KC_SLSH);
// }
//
// bool get_chordal_hold(uint16_t tap_hold_keycode, keyrecord_t *tap_hold_record,
//                       uint16_t other_keycode, keyrecord_t *other_record) {
//     // Thumb keys: never filtered by chordal hold
//     if (IS_QK_LAYER_TAP(tap_hold_keycode) || tap_hold_keycode == LGUI_T(KC_ESC)) {
//         return true;
//     }
//     // "/" is shift with any same-hand key (/m -> M), except letters that
//     // start common paths: /usr /home /opt /proc /lib
//     if (tap_hold_keycode == RSFT_T(KC_SLSH)) {
//         uint16_t other_tap = IS_QK_MOD_TAP(other_keycode) ? QK_MOD_TAP_GET_TAP_KEYCODE(other_keycode) : other_keycode;
//         switch (other_tap) {
//             case KC_U: case KC_H: case KC_O: case KC_P: case KC_L:
//                 return false;
//             default:
//                 return true;
//         }
//     }
//     // Ctrl on A: same-hand Emacs/readline chords (C-e, C-g, C-v, C-d) hold
//     if (tap_hold_keycode == LCTL_T(KC_A)) {
//         uint16_t other_tap = IS_QK_MOD_TAP(other_keycode) ? QK_MOD_TAP_GET_TAP_KEYCODE(other_keycode) : other_keycode;
//         switch (other_tap) {
//         case KC_E: case KC_G: case KC_V: case KC_D: case KC_R:
//                 return true;
//         }
//     }
//     return get_chordal_hold_default(tap_hold_record, other_record);
// }
//
// // A tapped "/" followed quickly by "i" is a fumbled capital I: swap "/i" for "I".
// static uint16_t slash_tap_time;
// static bool     slash_tapped;
//
// bool process_record_user(uint16_t keycode, keyrecord_t *record) {
//     if (keycode == RSFT_T(KC_SLSH)) {
//         if (record->tap.count) {
//             slash_tapped   = true;
//             slash_tap_time = record->event.time;
//         }
//         return true;
//     }
//     if (record->event.pressed) {
//         bool fix = slash_tapped && keycode == KC_I && timer_elapsed(slash_tap_time) < 150;
//         slash_tapped = false;
//         if (fix) {
//             tap_code(KC_BSPC);
//             tap_code16(S(KC_I));
//             return false;
//         }
//     }
//     return true;
// }
//
// // Z, Esc and "/" shift should engage fast (shift usually follows Space, so a
// // long window turns it into a tap); homerow mods and thumb keys are typed in
// // flow and get a longer window.
// uint16_t get_flow_tap_term(uint16_t keycode, keyrecord_t *record,
//                            uint16_t prev_keycode) {
//     // "/" right after Space/Enter starts a capitalised word: never a flow tap
//     if (keycode == RSFT_T(KC_SLSH) &&
//         (prev_keycode == LT(2, KC_SPC) || prev_keycode == LT(4, KC_ENT))) {
//         return 0;
//     }
//     if (keycode == LT(5, KC_Z) || keycode == LT(6, KC_ESC) ||
//         keycode == RSFT_T(KC_SLSH)) {
//         return 75;
//     }
//     return 140;
// }
//
// const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
// [DEF] = LAYOUT(
//   QK_BOOT  , KC_1   , KC_2   , KC_3   , KC_4   , KC_5   ,                      KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , TG(NUM),
//   KC_GRV , KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   , RM_NEXT,    _______, KC_Y   , KC_U   , KC_I   , KC_O   , KC_P   , KC_EQL ,
//   KC_PGUP, KC_A   , KC_S   , KC_D   , KC_F   , KC_G   , KC_TAB ,    KC_ENT , KC_H   , KC_J   , KC_K   , KC_L   , KC_SCLN, KC_QUOT,
//   KC_PGDN, KC_Z   , KC_X   , KC_C   , KC_V   , KC_B   , KC_ESC ,    _______, KC_N   , KC_M   , KC_COMM, KC_DOT , KC_SLSH, KC_MINS,
//                                          KC_LCTL,                                 KC_RCTL,
//                                             KC_BSPC,                           KC_SPC ,
//                                                KC_LGUI,                     KC_RALT,
//                                                   KC_LSFT,               KC_RSFT,
//                                       MO(FUN),                                        MO(FUN)
//   ),
// [NUM] = LAYOUT(
//   _______, _______, _______, _______, _______, _______,                      _______, KC_P7  , KC_P8  , KC_P9  , KC_PMNS, _______,
//   _______, _______, _______, _______, _______, _______, _______,    _______, _______, KC_P4  , KC_P5  , KC_P6  , KC_PPLS, _______,
//   _______, _______, _______, _______, _______, _______, _______,    _______, _______, KC_P1  , KC_P2  , KC_P3  , KC_PEQL, _______,
//   _______, _______, _______, _______, _______, _______, _______,    _______, _______, KC_P0  , KC_PDOT, KC_PAST, KC_PSLS, KC_PENT,
//                                          _______,                                 _______,
//                                             _______,                           _______,
//                                                _______,                     _______,
//                                                   _______,               _______,
//                                       _______,                                        _______
//   ),
// [FUN] = LAYOUT(
//   _______, KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  ,                      KC_F6  , KC_F7  , KC_F8  , KC_F9  , KC_F10 , KC_F11 ,
//   KC_TAB , _______, MS_UP,   _______, MS_BTN3, _______, RM_TOGG,    KC_MPRV, KC_MNXT, KC_LCBR, KC_RCBR, KC_LBRC, KC_RBRC, KC_F12 ,
//   KC_HOME, MS_LEFT, MS_DOWN, MS_RGHT, MS_BTN1, _______, _______,    KC_MPLY, KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT, _______, _______,
//   KC_END , KC_PSCR, KC_INS , _______, MS_BTN2, _______, _______,    _______, KC_MUTE, KC_VOLD, KC_VOLU, _______, KC_BSLS, KC_PIPE,
//                                          _______,                                 _______,
//                                             KC_DEL ,                           KC_ENT ,
//                                                _______,                     _______,
//                                                   _______,               _______,
//                                       _______,                                        _______
//   )
// };

/* template for new layouts:
LAYOUT(
  _______, _______, _______, _______, _______, _______,                      _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, _______, _______,
                                         _______,                                 _______,
                                            _______,                           _______,
                                               _______,                     _______,
                                                  _______,               _______,
                                      _______,                                        _______
  )
*/

/* vim: set ts=2 sw=2 et: */
