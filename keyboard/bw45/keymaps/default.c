#include "bw45.h"
#include "action_util.h"

// for clarity
#define __NO___ KC_NO
#define XXXXXXX KC_NO
#define _______ KC_TRNS
#define _SPACE_ KC_SPC

// momentary layer or keypress
#define SPC_FN1 LT(1,KC_SPC)
#define SPC_FN2 LT(2,KC_SPC)
#define TAB_FN LT(3,KC_TAB)

// shortcuts
#define SCRNCAP LGUI(LSFT(KC_4))
#define COLORCAP LCTL(LALT(LGUI(KC_C)))

#define LEFTSCR LALT(KC_1)
#define RIGHSCR LALT(KC_2)



// blank layer
// [1] = { 
//   {_______,   _______, _______, _______, _______, _______,  XXXXXXX,  _______,  _______,  _______,  _______,   _______,   _______ },
//   {_______,   _______, _______, _______, _______, _______,  XXXXXXX,  _______,  _______,  _______,  _______,   _______,   _______ },
//   {_______,   _______, _______, _______, _______, _______,  XXXXXXX,  _______,  _______,  _______,  _______,   _______,   _______ },
//   {XXXXXXX,   XXXXXXX, _______, _______, _______, _______,  _______,  _______,  _______,  _______,  _______,   XXXXXXX,   XXXXXXX }
// },


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  // layer 0: base
  [0] = { 
    {M(0),      KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,     XXXXXXX,  KC_Y,     KC_U,     KC_I,     KC_O,      KC_P,      KC_BSPC },
    {TAB_FN,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,     XXXXXXX,  KC_H,     KC_J,     KC_K,     KC_L,      KC_SCLN,   KC_ENTER},
    {KC_LSFT,   KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,     XXXXXXX,  KC_N,     KC_M,     KC_COMM,  KC_DOT,    KC_SLSH,   KC_RSFT },
    {XXXXXXX,   XXXXXXX, KC_LCTL, KC_LALT, KC_LGUI, SPC_FN2,  KC_QUOT,  _SPACE_,  MO(1),    MO(2),    KC_BSLS,   XXXXXXX,   XXXXXXX }
  },
  // layer 1: numbers
  [1] = { 
    {KC_GRV,    KC_1,    KC_2,    KC_3,    KC_4,    _______,  XXXXXXX,  _______,  _______,  _______,  _______,   _______,   KC_DEL  },
    {_______,   KC_5,    KC_6,    KC_7,    KC_8,    _______,  XXXXXXX,  _______,  KC_QUOT, S(KC_QUOT),KC_COLN,   KC_SCLN,   _______ },
    {_______,   KC_9,    KC_0,    KC_MINS, KC_EQUAL,_______,  XXXXXXX,  _______,  _______,  _______,  _______,   _______,   _______ },
    {XXXXXXX,   XXXXXXX, _______, _______, _______, _______,  _______,  _______,  _______,  _______,  _______,   XXXXXXX,   XXXXXXX }
  },
  // layer 2: symbols
  [2] = { 
    {_______,   KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  _______,  XXXXXXX,  _______,  KC_LBRC,  KC_RBRC,  _______,   _______,   KC_BSPC },
    {_______,   KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, _______,  XXXXXXX,  _______,  KC_LCBR,  KC_RCBR,  KC_MINS,   KC_UNDS,   _______ },
    {_______,   KC_LPRN, KC_RPRN, KC_UNDS, KC_PLUS, _______,  XXXXXXX,  _______,  KC_LPRN,  KC_RPRN,  _______,   _______,   _______ },
    {XXXXXXX,   XXXXXXX, _______, _______, _______, _______,  _______,  _______,  _______,  _______,  _______,   XXXXXXX,   XXXXXXX }
  },
  // layer 3: arrows and shortcuts
  [3] = { 
    {_______,   _______, _______, _______, _______, _______,  XXXXXXX,  _______,  _______,  KC_UP,    _______,   _______,   KC_DEL  },
    {_______,   LEFTSCR, RIGHSCR, COLORCAP,KC_WREF, _______,  XXXXXXX,  _______,  KC_LEFT,  KC_DOWN,  KC_RIGHT,  _______,   M(1)    },
    {_______,   _______, _______, SCRNCAP, _______, _______,  XXXXXXX,  _______,  KC_VOLD,  KC_VOLU,  KC_MUTE,   _______,   _______ },
    {XXXXXXX,   XXXXXXX, _______, _______, _______, MO(4),    _______,  _______,  KC_MPRV,  KC_MNXT,  KC_MPLY,   XXXXXXX,   XXXXXXX }
  },
  // layer 4: mouse
  [4] = {   
    {_______,   _______, _______, _______, _______, _______,  XXXXXXX,  KC_WH_U,  KC_BTN1,  KC_MS_U,  KC_BTN2,   _______,   _______ },
    {_______,   _______, KC_ACL0, KC_ACL1, KC_ACL2, _______,  XXXXXXX,  KC_WH_D,  KC_MS_L,  KC_MS_D,  KC_MS_R,   _______,   _______ },
    {_______,   _______, _______, _______, _______, _______,  XXXXXXX,  _______,  KC_BTN4,  KC_BTN3,  KC_BTN5,   _______,   _______ },
    {XXXXXXX,   XXXXXXX, _______, _______, _______, TG(4),    _______,  _______,  _______,  _______,  _______,   XXXXXXX,   XXXXXXX }
  },
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