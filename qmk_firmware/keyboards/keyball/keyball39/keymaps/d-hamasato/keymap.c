/*
Copyright 2022 @Yowkees
Copyright 2022 MURAOKA Taro (aka KoRoN, @kaoriya)

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H

#include "quantum.h"

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  // keymap for default
  [0] = LAYOUT_universal(
    KC_Q     , KC_W     , KC_E     , KC_R     , KC_T     ,                            KC_Y     , KC_U     , KC_I     , KC_O     , KC_P     ,
LCTL_T(KC_A) , KC_S     , KC_D     , KC_F     , KC_G     ,                            KC_H     , KC_J     , KC_K     , KC_L     , RCTL_T(KC_SCLN),
LSFT_T(KC_Z) , KC_X     , KC_C     , KC_V     , KC_B     ,                            KC_N     , KC_M     , KC_COMM  , KC_DOT   , RSFT_T(KC_SLSH),
    KC_TAB   ,RGUI_T(KC_LEFT),RALT_T(KC_RIGHT),KC_BSPC,MO(1),GUI_T(KC_SPC),  ALT_T(KC_ENT),MO(2),XXXXXXX  , XXXXXXX  , XXXXXXX  , KC_ESC
  ),

  [1] = LAYOUT_universal(
    KC_1     , KC_2     , KC_3     , KC_4     , KC_5     ,                            KC_6     , KC_7     , KC_8     , KC_9     , KC_0     ,
LCTL_T(KC_TAB),XXXXXXX  , XXXXXXX  , XXXXXXX  , XXXXXXX  ,                            KC_LEFT  , KC_DOWN  , KC_UP    , KC_RIGHT , KC_RCTL  ,
    KC_LSFT  , XXXXXXX  , XXXXXXX  , XXXXXXX  , XXXXXXX  ,                            KC_HOME  , KC_PGDN  , KC_PGUP  , KC_END   , KC_RSFT  ,
    _______  , _______  , _______  , _______  , _______  , _______  ,     _______  ,  MO(5)    , XXXXXXX  , XXXXXXX  , XXXXXXX  , _______
  ),

  [2] = LAYOUT_universal(
    KC_EXLM  , KC_AT    , KC_HASH  , KC_DLR   , KC_PERC  ,                            KC_CIRC  , KC_AMPR  , KC_ASTR  , KC_LPRN  , KC_RPRN  ,
LCTL_T(KC_TAB),XXXXXXX  , XXXXXXX  , KC_QUOT  , KC_GRV   ,                            KC_MINS  , KC_EQL   , KC_LBRC  , KC_RBRC  , KC_BSLS  ,
    KC_LSFT  , XXXXXXX  , XXXXXXX  , KC_DQT   , KC_TILD  ,                            KC_UNDS  , KC_PLUS  , KC_LCBR  , KC_RCBR  , KC_PIPE  , // RSFT_T(KC_PIPE) ←これがバグなのか tapで バックスラッシュになってしまう。修正されたら切り替える
    _______  , _______  , _______  , KC_DEL   , MO(5)    , _______  ,     _______  ,  _______  , XXXXXXX  , XXXXXXX  , XXXXXXX  , _______
  ),

  [3] = LAYOUT_universal( // scroll layer
    XXXXXXX  , XXXXXXX  , XXXXXXX  , XXXXXXX  , XXXXXXX  ,                            XXXXXXX  , XXXXXXX  , XXXXXXX  , XXXXXXX  , XXXXXXX ,
    _______  , XXXXXXX  , XXXXXXX  , XXXXXXX  , XXXXXXX  ,                            XXXXXXX  , KC_BTN1  , XXXXXXX  , KC_BTN2  , XXXXXXX ,
    XXXXXXX  , XXXXXXX  , XXXXXXX  , XXXXXXX  , XXXXXXX  ,                            XXXXXXX  , XXXXXXX  , XXXXXXX  , XXXXXXX  , XXXXXXX ,
    XXXXXXX  , XXXXXXX  , TG(3)    , XXXXXXX  , XXXXXXX  , _______  ,      _______ ,  XXXXXXX  , XXXXXXX  , XXXXXXX  , XXXXXXX  , XXXXXXX
  ),

  [4] = LAYOUT_universal( // AUTO_MOUSE_DEFAULT_LAYER
    XXXXXXX  , XXXXXXX  , XXXXXXX  , XXXXXXX  , XXXXXXX  ,                            XXXXXXX  , XXXXXXX  , XXXXXXX  , XXXXXXX  , XXXXXXX  ,
    XXXXXXX  , XXXXXXX  , XXXXXXX  , XXXXXXX  , XXXXXXX  ,                            KC_BTN4  , KC_BTN1  , MO(3)    , KC_BTN2  , KC_BTN5  ,
    XXXXXXX  , XXXXXXX  , XXXXXXX  , XXXXXXX  , XXXXXXX  ,                            XXXXXXX  , XXXXXXX  , XXXXXXX  , XXXXXXX  , XXXXXXX  ,
    XXXXXXX  , XXXXXXX  , XXXXXXX  , XXXXXXX  , XXXXXXX  , XXXXXXX  ,      XXXXXXX ,  XXXXXXX  , XXXXXXX  , XXXXXXX  , XXXXXXX  , XXXXXXX
  ),

  [5] = LAYOUT_universal( // device control layer

    XXXXXXX  , LCA(KC_E), LCA(KC_R), LCA(KC_T), XXXXXXX  ,                            XXXXXXX  , XXXXXXX  , KC_MUTE  , KC_VOLD  , KC_VOLU  ,
    XXXXXXX  , LCA(KC_D), LCA(KC_F), LCA(KC_G), XXXXXXX  ,                            LCA(KC_LEFT),LCA(KC_DOWN),LCA(KC_UP),LCA(KC_RIGHT), XXXXXXX  ,
    XXXXXXX  , XXXXXXX  , XXXXXXX  , XXXXXXX  , XXXXXXX  ,                            XXXXXXX  , XXXXXXX  , XXXXXXX  , XXXXXXX  , XXXXXXX  ,
    XXXXXXX  , XXXXXXX  , XXXXXXX  , _______  , _______  , _______  ,    LCA(KC_ENT), _______  , XXXXXXX  , XXXXXXX  , XXXXXXX  , XXXXXXX
  ),

  [6] = LAYOUT_universal( // setting layer
    RGB_TOG  , XXXXXXX  , XXXXXXX  , XXXXXXX  , XXXXXXX  ,                            XXXXXXX  , XXXXXXX  , XXXXXXX  , XXXXXXX  , KBC_RST ,
    RGB_MOD  , RGB_HUI  , RGB_SAI  , RGB_VAI  , XXXXXXX  ,                            SCRL_DVI , CPI_I1K  , CPI_I100 , XXXXXXX  , XXXXXXX ,
    RGB_RMOD , RGB_HUD  , RGB_SAD  , RGB_VAD  , XXXXXXX  ,                            SCRL_DVD , CPI_D1K  , CPI_D100 , XXXXXXX  , KBC_SAVE ,
    QK_BOOT  ,RGUI_T(KC_LEFT),RALT_T(KC_RIGHT),XXXXXXX,XXXXXXX, _______,   _______ ,  XXXXXXX  , XXXXXXX  , XXXXXXX  , XXXXXXX  , QK_BOOT
  ),
};
// clang-format on

layer_state_t layer_state_set_user(layer_state_t state) {
    switch(get_highest_layer(remove_auto_mouse_layer(state, true))) {
      case 0:
          set_auto_mouse_enable(true);
          keyball_set_scroll_mode(false);
          rgblight_sethsv(HSV_OFF);
          break;
      case 3:
          // Auto enable scroll mode when the highest layer is 3
          // remove_auto_mouse_target must be called to adjust state *before* setting enable
          state = remove_auto_mouse_layer(state, false);
          set_auto_mouse_enable(false);
          keyball_set_scroll_mode(true);
          rgblight_sethsv(HSV_PURPLE);
          break;
      case 6:
          set_auto_mouse_enable(false);
          keyball_set_scroll_mode(false);
          rgblight_sethsv(HSV_RED);
          break;
      default:
          set_auto_mouse_enable(false);
          keyball_set_scroll_mode(false);
          rgblight_sethsv(HSV_OFF);
          break;
    }

    return state;
}


bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LCTL_T(KC_A):
        case LSFT_T(KC_Z):
            // Do not force the mod-tap key press to be handled as a modifier
            // if any other key was pressed while the mod-tap key is held down.
            return false;
        default:
            // Force the dual-role key press to be handled as a modifier if any
            // other key was pressed while the mod-tap key is held down.
            return true;
    }
}

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LCTL_T(KC_A):
        case LSFT_T(KC_Z):
            return 150; // midSwitchに変えてから、175だと遅く感じたので150でしばらく様子見
        default:
            return TAPPING_TERM;
    }
}


enum combos {
  TG_SCROLL_LAYER,
  TG_SETTING_LAYER,
  COMBO_LENGTH
};

uint16_t COMBO_LEN = COMBO_LENGTH;

const uint16_t PROGMEM scroll_combo[] = {KC_BTN1, KC_BTN2, COMBO_END};
const uint16_t PROGMEM setting_combo[] = {RGUI_T(KC_LEFT), RALT_T(KC_RIGHT), COMBO_END};

combo_t key_combos[] = {
  [TG_SCROLL_LAYER] = COMBO(scroll_combo, TG(3)),
  [TG_SETTING_LAYER] = COMBO(setting_combo, TG(6)),
};


static bool lower_pressed = false;
static bool raise_pressed = false;
static uint16_t lower_pressed_time = 0;
static uint16_t raise_pressed_time = 0;

static bool mo3_pressed = false;
static uint16_t mo3_pressed_time = 0;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    // HOLD_ON_OTHER_KEY_PRESSオプションと LT()の組み合わせだとたまに意図しない入力になったので、シングルタップで入力言語切り替えになるようMO()をオーバーライド
    case MO(1):
      if (record->event.pressed) {
        lower_pressed = true;
        lower_pressed_time = record->event.time;
        layer_on(1);
      } else {
        layer_off(1);
        if (lower_pressed && (TIMER_DIFF_16(record->event.time, lower_pressed_time) < TAPPING_TERM)) {
          tap_code(KC_LNG2);
        }
        lower_pressed = false;
      }
      return false;
      break;
    case MO(2):
      if (record->event.pressed) {
        raise_pressed = true;
        raise_pressed_time = record->event.time;
        layer_on(2);
      } else {
        layer_off(2);
        if (raise_pressed && (TIMER_DIFF_16(record->event.time, raise_pressed_time) < TAPPING_TERM)) {
          tap_code(KC_LNG1);
        }
        raise_pressed = false;
      }
      return false;
      break;
    // AUTO_MOUSE_DEFAULT_LAYER 内で LT(3,KC_BTN3) としたところ、レイヤー切り替えは動作するも KD_BTN3 が動作しなかったため MO(3)をオーバーライド
    case MO(3):
      if (record->event.pressed) {
        mo3_pressed = true;
        mo3_pressed_time = record->event.time;
        layer_on(3);
      } else {
        layer_off(3);
        if (mo3_pressed && (TIMER_DIFF_16(record->event.time, mo3_pressed_time) < TAPPING_TERM)) {
          tap_code(KC_BTN3);
        }
        mo3_pressed = false;
      }
      return false;
      break;
    default:
      if (record->event.pressed) {
        lower_pressed = false;
        raise_pressed = false;
        mo3_pressed   = false;
      }
      break;
  }
  return true;
}


#ifdef OLED_ENABLE

#    include "lib/oledkit/oledkit.h"

void oledkit_render_info_user(void) {
    keyball_oled_render_keyinfo();
    keyball_oled_render_ballinfo();
}
#endif

void caps_word_set_user(bool active) {
    if (active) {
        rgblight_sethsv(HSV_WHITE);
    } else {
        rgblight_sethsv(HSV_OFF);
    }
}
