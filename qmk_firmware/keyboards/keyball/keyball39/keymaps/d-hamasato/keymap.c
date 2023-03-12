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
    KC_TAB   , _______  , _______  ,LT(3,KC_BSPC),MO(1),GUI_T(KC_SPC),      ALT_T(KC_ENT),MO(2), _______  , _______  , _______  , KC_ESC
  ),

  [1] = LAYOUT_universal(
    KC_1     , KC_2     , KC_3     , KC_4     , KC_5     ,                            KC_6     , KC_7     , KC_8     , KC_9     , KC_0     ,
    _______  , _______  , _______  , KC_BTN1  , KC_BTN2  ,                            KC_LEFT  , KC_DOWN  , KC_UP    , KC_RIGHT , _______  ,
    _______  , _______  , _______  , _______  , _______  ,                            KC_HOME  , KC_PGDN  , KC_PGUP  , KC_END   , _______  ,
    _______  , _______  , _______  , _______  , _______  , KC_SPC   ,       KC_ENT ,  _______  , _______  , _______  , _______  , _______
  ),

  [2] = LAYOUT_universal(
    KC_EXLM  , KC_AT    , KC_HASH  , KC_DLR   , KC_PERC  ,                            KC_CIRC  , KC_AMPR  , KC_ASTR  , KC_LPRN  , KC_RPRN  ,
    _______  , _______  , _______  , KC_QUOT  , KC_GRV   ,                            KC_MINS  , KC_EQL   , KC_LBRC  , KC_RBRC  , KC_BSLS  ,
    _______  , _______  , _______  , KC_DQT   , KC_TILD  ,                            KC_UNDS  , KC_PLUS  , KC_LCBR  , KC_RCBR  , KC_PIPE  ,
    _______  , _______  , _______  , KC_DEL   , _______  , KC_SPC   ,      KC_ENT  ,  _______  , _______  , _______  , _______  , _______
  ),

  [3] = LAYOUT_universal(
    RGB_TOG  , _______  , _______  , _______  , _______  ,                            RGB_M_P  , RGB_M_B  , RGB_M_R  , RGB_M_SW , RGB_M_SN ,
    RGB_MOD  , RGB_HUI  , RGB_SAI  , RGB_VAI  , SCRL_DVI ,                            RGB_M_K  , RGB_M_X  , RGB_M_G  , RGB_M_T  , RGB_M_TW ,
    RGB_RMOD , RGB_HUD  , RGB_SAD  , RGB_VAD  , SCRL_DVD ,                            CPI_D1K  , CPI_D100 , CPI_I100 , CPI_I1K  , KBC_SAVE ,
    QK_BOOT  , KBC_RST  , _______  , _______  , _______  , _______  ,      _______ ,  _______  , _______  , _______  , KBC_RST  , QK_BOOT
  ),

  [4] = LAYOUT_universal( // AUTO_MOUSE_DEFAULT_LAYER
    _______  , _______  , _______  , _______  , _______  ,                            _______  , _______  , _______  , _______  , _______  ,
    _______  , _______  , _______  , _______  , _______  ,                            _______  , KC_BTN1  , KC_BTN3  , KC_BTN2  , _______  ,
    _______  , _______  , _______  , _______  , _______  ,                            _______  , _______  , _______  , _______  , _______  ,
    _______  , _______  , _______  , _______  , _______  , _______  ,      _______ ,  _______  , _______  , _______  , _______  , _______
  ),
};
// clang-format on

layer_state_t layer_state_set_user(layer_state_t state) {
    switch(get_highest_layer(remove_auto_mouse_layer(state, true))) {
      case 0:
          set_auto_mouse_enable(true);
          keyball_set_scroll_mode(false);
          break;
      case 3:
          // Auto enable scroll mode when the highest layer is 3
          // remove_auto_mouse_target must be called to adjust state *before* setting enable
          state = remove_auto_mouse_layer(state, false);
          set_auto_mouse_enable(false);
          keyball_set_scroll_mode(true);
          break;
      default:
          set_auto_mouse_enable(false);
          keyball_set_scroll_mode(false);
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


#ifdef OLED_ENABLE

#    include "lib/oledkit/oledkit.h"

void oledkit_render_info_user(void) {
    keyball_oled_render_keyinfo();
    keyball_oled_render_ballinfo();
}
#endif
