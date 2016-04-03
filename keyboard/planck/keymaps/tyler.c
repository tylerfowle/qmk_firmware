#include "planck.h"
#include "action_util.h"

#define __NO___ KC_NO
#define _______ KC_TRNS
#define _SPACE_ KC_SPC
#define TAB_FN1 LT(1,KC_TAB)
#define SCRNCAP LGUI(LSFT(KC_4))

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = {  /* Base */
    {M(0),    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,     KC_P,    KC_BSPC},
    {TAB_FN1, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,     KC_SCLN, KC_ENT},
    {KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,   KC_SLSH, KC_RSFT},
    {__NO___, KC_LCTL, KC_LALT, KC_LGUI, MO(1),   _SPACE_, __NO___, MO(2),   __NO___, __NO___,  KC_BSLS, KC_PENT}
  },
  [1] = { /* FN1 // Left FN */
    {KC_GRV,  KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  _______, _______, _______, KC_UP,   _______,  SCRNCAP, KC_DELETE},
    {_______, KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, _______, M(1),    KC_LEFT, KC_DOWN, KC_RIGHT, KC_QUOT, S(KC_QUOT)},
    {_______, KC_LPRN, KC_RPRN, KC_UNDS, KC_PLUS, _______, _______, _______, KC_PAUS, KC_VOLD,  KC_VOLU, KC_MUTE},
    {_______, _______, _______, _______, _______, _SPACE_, __NO___, _______, KC_SLCK, KC_MPRV,  KC_MNXT, KC_MPLY}
  },
  [2] = { /* FN2 // Right FN */
    {_______, KC_1,    KC_2,    KC_3,    KC_4,    _______, _______, KC_LBRC, KC_RBRC, KC_QUOT,  S(KC_QUOT), KC_BSPC},
    {_______, KC_5,    KC_6,    KC_7,    KC_8,    _______, _______, KC_LCBR, KC_RCBR, KC_MINS,  KC_UNDS,   _______},
    {_______, KC_9,    KC_0,    KC_MINS, KC_EQL,  _______, _______, KC_LPRN, KC_RPRN, _______,  _______,   _______},
    {_______, _______, _______, _______, _______, _SPACE_, __NO___, _______, _______, _______,  _______,   _______}
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
    case 1:
    if (record->event.pressed) {
      return MACRO( I(5), D(LSFT), T(SCLN), U(LSFT), T(W), T(Q), T(ENT), END  );
    }
    break;
  }
  return MACRO_NONE;
};