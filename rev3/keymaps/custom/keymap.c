/* Copyright 2020 yushakobo
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


// Defines names for use in layer keycodes and the keymap
enum layer_names {
  _QWERTY = 0,
  _LOWER,
  _RAISE,
  _ADJUST
};

// Defines the keycodes used by our macros in process_record_user
enum custom_keycodes {
  EISU = SAFE_RANGE,
  KANA,
  ADJUST,
  RGBRST,
  CARET,
  BCKTICK,
  SHIFT_UNDS,
  DEGREE,
  LAYER_SW
};

#define RAISE MO(_RAISE)
#define D_RAISE LT(_RAISE, KC_D)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* Qwerty
   * ,-----------------------------------------.             ,-----------------------------------------.
   * | Esc  |   1  |   2  |   3  |   4  |   5  |             |   6  |   7  |   8  |   9  |   0  |  ^   |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * | Tab  |   Q  |   W  |   E  |   R  |   T  |             |   Y  |   U  |   I  |   O  |   P  | Bksp |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * |  °   |   A  |   S  |   D  |   F  |   G  |             |   H  |   J  |   K  |   L  |   Ñ  |Enter |
   * |------+------+------+------+------+------+------+------+------+------+------+------+------+------|
   * | CAPS |   <  |   Z  |   X  |   C  |   V  |   `  |   +  |   B  |   N  |   M  |   ,  |   .  |  -   |
   * |------+------+------+------+------+------+------+------+------+------+------+------+------+------|
   * | Ctrl |Adjust|Layer | Print|   ¿  |   '  |   ´  |Space | Ins  |   ?  | Left | Down |  Up  |Right |
   * `-------------------------------------------------------------------------------------------------'
   */
  [_QWERTY] = LAYOUT_5row(
      KC_ESC,  KC_1,         KC_2,         KC_3,    KC_4,         KC_5,                      KC_6,   KC_7,         KC_8,    KC_9,         KC_0,            CARET,
      KC_TAB,  KC_Q,         KC_W,         KC_E,    KC_R,         KC_T,                      KC_Y,   KC_U,         KC_I,    KC_O,         KC_P,            KC_BSPC,
      DEGREE,  LALT_T(KC_A), LSFT_T(KC_S), KC_D,    LGUI_T(KC_F), KC_G,                      KC_H,   LGUI_T(KC_J), KC_K,    RSFT_T(KC_L), RALT_T(KC_SCLN), KC_ENT,
      KC_CAPS, KC_NUBS,      KC_Z,         KC_X,    KC_C,         KC_V,    BCKTICK, KC_RBRC, KC_B,   KC_N,         KC_M,    KC_COMM,      KC_DOT,          KC_SLSH,
      KC_LCTL, ADJUST,       LAYER_SW,     KC_PSCR, KC_EQL,       KC_MINS, KC_LBRC, KC_SPC,  KC_INS, SHIFT_UNDS,   KC_LEFT, KC_DOWN,      KC_UP,           KC_RGHT
    ),
  /* Lower
   * ,-----------------------------------------.             ,-----------------------------------------.
   * |      |      |      |      |      |      |             |      |      |      |      |      |      |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * |      | KP 7 | KP 8 | KP 9 | KP / |      |             |      |      |      |      |      | Del  |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * |      | KP 4 | KP 5 | KP 6 | KP * |      |             |      |      |      |      |      |      |
   * |------+------+------+------+------+------+------+------+------+------+------+------+------+------|
   * |      | KP 1 | KP 2 | KP 3 | KP - |      |      |      |      |      |      |      |      |      |
   * |------+------+------+------+------+------+------+------+------+------+------+------+------+------|
   * |      | KP 0 |Layer | KP . | KP + | NumLk| Back | Fwd  |      |   !  | Home | PgDn | PgUp | End  |
   * `-------------------------------------------------------------------------------------------------'
   */
  [_LOWER] = LAYOUT_5row(
      KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                     KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
      _______, KC_P7,   KC_P8,   KC_P9,   KC_PSLS, _______,                   _______, _______, _______, _______, _______, KC_DEL,
      _______, KC_P4,   KC_P5,   KC_P6,   KC_PAST, _______,                   _______, _______, _______, _______, _______, _______,
      _______, KC_P1,   KC_P2,   KC_P3,   KC_PMNS, _______, _______, _______, _______, _______, _______, _______, _______, _______,
      _______, KC_P0,   LAYER_SW,KC_PDOT, KC_PPLS, KC_NUM,  KC_WBAK, KC_WFWD, _______, KC_EXLM, KC_HOME, KC_PGDN, KC_PGUP, KC_END
      ),

  /* Raise
   * ,-----------------------------------------.             ,-----------------------------------------.
   * |      |      |      |      |      |      |             |      |      |      |      |      | Bksp |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * |   `  |   1  |   2  |   3  |   4  |   5  |             |   6  |   7  |   8  |   9  |   0  | Del  |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * |      |  F1  |  F2  |  F3  |  F4  |  F5  |             |  F6  |   -  |   =  |   [  |   ]  |  \   |
   * |------+------+------+------+------+------+------+------+------+------+------+------+------+------|
   * | CAPS |  F7  |  F8  |  F9  |  F10 |  F11 |      |      |  F12 |      |      |PageDn|PageUp|      |
   * |------+------+------+------+------+------+------+------+------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |      |      |      | Next | Vol- | Vol+ | Play |
   * `-------------------------------------------------------------------------------------------------'
   */
  [_RAISE] = LAYOUT_5row(
      KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                     KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
      _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, KC_DEL,
      _______, _______, _______, _______, _______, _______,                   _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______,
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
      _______, _______, _______, _______, KC_PLUS, _______, KC_WBAK, KC_WFWD, _______, KC_EXLM, KC_HOME, KC_PGDN, KC_PGUP, KC_END
      ),

  /* Adjust (Lower + Raise)
   * ,-----------------------------------------.             ,-----------------------------------------.
   * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |             |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * |      | Reset|RGBRST|EEPRST|      |      |             |      |      |      |      |      |  Del |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * |      |      |      |      |      | Mac  |             | Win  |      |      |      |      |      |
   * |------+------+------+------+------+------+------+------+------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |      |      |      |RGB ON| HUE+ | SAT+ | VAL+ |
   * |------+------+------+------+------+------+------+------+------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |      |      |      | MODE | HUE- | SAT- | VAL- |
   * `-------------------------------------------------------------------------------------------------'
   */
  [_ADJUST] = LAYOUT_5row(
      KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                     KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
      _______, QK_BOOT, RGBRST,  EE_CLR,  _______, _______,                   _______, UG_TOGG, UG_HUEU, UG_SATU, UG_VALU, KC_DEL,
      _______, _______, _______, _______, _______, AG_NORM,                   AG_SWAP, UG_NEXT, UG_HUED, UG_SATD, UG_VALD, _______,
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
      )

};

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [_QWERTY] = { ENCODER_CCW_CW(MS_WHLU, MS_WHLD),    ENCODER_CCW_CW(KC_VOLD, KC_VOLU)  },
    [_LOWER] =  { ENCODER_CCW_CW(KC_PGUP, KC_PGDN),  ENCODER_CCW_CW(KC_HOME, KC_END)  },
    [_RAISE] =  { ENCODER_CCW_CW(UG_VALD, UG_VALU),  ENCODER_CCW_CW(UG_SPDD, UG_SPDU)  },
    [_ADJUST] = { ENCODER_CCW_CW(UG_PREV, UG_NEXT), ENCODER_CCW_CW(KC_RIGHT, KC_LEFT) },
};
#endif

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

static uint16_t layer_sw_timer;
static bool layer_sw_held, layer_sw_fired;

static void layer_sw_set(uint8_t layer) {
  bool on = layer_state_is(layer);
  layer_off(_LOWER);
  layer_off(_RAISE);
  if (!on) layer_on(layer);
}

void housekeeping_task_user(void) {
  if (layer_sw_held && !layer_sw_fired && timer_elapsed(layer_sw_timer) >= 1000) {
    layer_sw_fired = true;
    layer_sw_set(_LOWER);
  }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case LAYER_SW:
      if (record->event.pressed) {
        layer_sw_timer = timer_read();
        layer_sw_held = true;
        layer_sw_fired = false;
      } else {
        layer_sw_held = false;
        if (!layer_sw_fired) {
          if (layer_state_is(_LOWER) || layer_state_is(_RAISE)) {
            layer_off(_LOWER);
            layer_off(_RAISE);
          } else {
            layer_on(_RAISE);
          }
        }
      }
      return false;
    case EISU:
      if (record->event.pressed) {
        if (is_mac_mode()) {
          register_code(KC_LNG2);
        }else{
          tap_code16(LALT(KC_GRAVE));
        }
      } else {
        unregister_code(KC_LNG2);
      }
      return false;
      break;
    case KANA:
      if (record->event.pressed) {
        if (is_mac_mode()) {
          register_code(KC_LNG1);
        }else{
          tap_code16(LALT(KC_GRAVE));
        }
      } else {
        unregister_code(KC_LNG1);
      }
      return false;
      break;
    case ADJUST:
      if (record->event.pressed) {
        layer_on(_LOWER);
        layer_on(_RAISE);
      } else {
        layer_off(_LOWER);
        layer_off(_RAISE);
      }
      break;
    case RGBRST:
      #ifdef RGB_MATRIX_ENABLE
        if (record->event.pressed) {
          eeconfig_update_rgb_matrix_default();
          rgb_matrix_enable();
        }
      #endif
      break;
    case CARET:
      if (record->event.pressed) {
        tap_code16(RALT(KC_QUOT));
      }
      return false;
      break;
    case BCKTICK:
      if (record->event.pressed) {
        tap_code16(RALT(KC_BSLS));
      }
      return false;
      break;
    case SHIFT_UNDS:
      if (record->event.pressed) {
        if (get_mods() & MOD_MASK_SHIFT) {
            tap_code16(KC_EXLM);
        } else {
            tap_code16(KC_UNDS);
        }
      }
      return false;
    case DEGREE:
      if (record->event.pressed) {
        tap_code16(LSFT(KC_GRV));
      }
      return false;
      break;
  }
  return true;
}
