#include "sb40.h"
#include "action_util.h"

// for clarity
#define __NO___ KC_NO
#define XXXXXXX KC_NO
#define _______ KC_TRNS
#define _SPACE_ KC_SPC

// momentary layer or keypress
#define TAB_FN LT(3,KC_TAB)

// shortcuts
#define SCRNCAP LGUI(LSFT(KC_4))
#define COLORCAP LCTL(LALT(LGUI(KC_C)))

#define LEFTSCR LALT(KC_1)
#define RIGHSCR LALT(KC_2)



// blank layer

// [0] = { 
// {_______,   _______, _______, _______, _______, _______,  _______,  _______,  _______,  _______,   _______,    _______},
// {_______,   _______, _______, _______, _______, _______,  _______,  _______,  _______,  _______,   XXXXXXX,    _______},
// {_______,   XXXXXXX, _______, _______, _______, _______,  _______,  _______,  _______,  _______,   _______,    _______},
// {XXXXXXX,   _______, XXXXXXX, _______, _______, _______,  XXXXXXX,  _______,  _______,  _______,   _______}
// }


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  // layer 0: base
  [0] = { 
    {M(0),      KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,      KC_P,       KC_BSPC },
    {TAB_FN,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,     KC_H,     KC_J,     KC_K,     KC_L,      XXXXXXX,    KC_ENTER},
    {KC_LSFT,   XXXXXXX, KC_Z,    KC_X,    KC_C,    KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,   KC_DOT,     KC_SLSH },
    {XXXXXXX,   KC_LCTL, XXXXXXX, KC_LALT, KC_LGUI, _SPACE_,  XXXXXXX,  MO(1),    MO(2),    _______,   KC_BSLS}
  },
  // layer 1: numbers
  [1] = { 
    {KC_GRV,    KC_1,    KC_2,    KC_3,    KC_4,    _______,  _______,  _______,  _______,  _______,   _______,    KC_DEL },
    {_______,   KC_5,    KC_6,    KC_7,    KC_8,    _______,  _______,  KC_QUOT,  S(KC_QUOT), KC_COLN,   XXXXXXX,  KC_SCLN},
    {_______,   XXXXXXX, KC_9,    KC_0,    KC_MINS, KC_EQUAL, _______,  _______,  _______,  _______,   _______,    _______},
    {XXXXXXX,   _______, XXXXXXX, _______,  _______,_______,  XXXXXXX,  _______,  _______,  _______,   _______}
  },
  // layer 2: symbols and punc
  [2] = { 
    {_______,   KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  _______,  _______,  KC_LBRC,  KC_RBRC,  _______,   _______,    KC_BSPC},
    {_______,   KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, _______,  _______,  KC_LCBR,  KC_RCBR,  KC_MINS,   XXXXXXX,    KC_UNDS},
    {_______,   XXXXXXX, KC_LPRN, KC_RPRN, KC_UNDS, KC_PLUS,  _______,  _______,  KC_LPRN,  KC_RPRN,   _______,    _______},
    {XXXXXXX,   _______, XXXXXXX, _______, _______, _______,  XXXXXXX,  _______,  _______,  _______,   _______}
  },
  // layer 3: arrow, media, and shortcut keys
  [3] = { 
    {_______,   _______, _______, _______, _______, _______,  _______,  _______,  KC_UP,    COLORCAP,  SCRNCAP,    KC_DEL },
    {_______,   LEFTSCR, RIGHSCR, _______, _______, _______,  _______,  KC_LEFT,  KC_DOWN,  KC_RIGHT,  XXXXXXX,    M(1)   },
    {_______,   XXXXXXX, _______, _______, _______, _______,  _______,  _______,  KC_MUTE,  KC_VOLD,   KC_VOLU,    _______},
    {XXXXXXX,   _______, XXXXXXX, _______, _______, _______,  XXXXXXX,  _______,  KC_MPRV,  KC_MNXT,   KC_MPLY}
  }
};



const uint16_t PROGMEM fn_actions[] = {
};



const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  switch(id) {
    case 0: {
      static uint8_t code;
      if (record->event.pressed) {
        code = (keyboard_report->mods & (MOD_BIT(KC_LSFT) | MOD_BIT(KC_RSFT))) ? KC_GRV : KC_ESC;
        register_code(code);
      }
      else {
        unregister_code(code);
      }
      break;
    }
    break;
    case 1: {
      if (record->event.pressed) {
        return MACRO( I(5), T(ESC), D(LSFT), T(SCLN), U(LSFT), T(W), T(Q), T(ENT), END  );
      }
    }
    break;
  }
  return MACRO_NONE;
};