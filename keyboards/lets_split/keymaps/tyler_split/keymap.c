#include "lets_split.h"
#include "action_layer.h"
#include "eeconfig.h"

extern keymap_config_t keymap_config;

// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO

// Custom macros
#define CTL_ESC     CTL_T(KC_ESC)               // Tap for Esc, hold for Ctrl
#define SFT_ENT     SFT_T(KC_ENT)               // Tap for Enter, hold for Shift
#define HPR_TAB     ALL_T(KC_TAB)               // Tap for Tab, hold for Hyper (Super+Ctrl+Alt+Shift)
#define MEH_GRV     MEH_T(KC_GRV)               // Tap for Backtick, hold for Meh (Ctrl+Alt+Shift)

//
#define __NO___ KC_NO
#define _______ KC_TRNS
#define _SPACE_ KC_SPC

#define TAB_FN LT(4,KC_TAB)
#define SCRNCAP LGUI(LSFT(KC_4))
#define COLORCAP LCTL(LALT(LGUI(KC_C)))

#define LEFTSCR LALT(KC_1)
#define RIGHSCR LALT(KC_2)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [0] = KEYMAP( \
    M(6),    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,     KC_P,    KC_BSPC, \
    TAB_FN,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,     KC_SCLN, KC_ENT, \
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,   KC_SLSH, KC_RSFT, \
    TG(1),   KC_LCTL, KC_LALT, KC_LGUI, MO(3),   _SPACE_, _SPACE_, MO(2),   KC_QUOT, KC_BSLS,  _______, TG(5)
  ),

  [1] = KEYMAP( \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______,  _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______,  _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______,  _______, \
    TG(0),   KC_LALT, KC_LGUI, KC_LCTL, _______, _______, _______, _______, _______, _______,  _______,  _______
  ),

  [2] = KEYMAP( \
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    _______, _______, _______, _______, _______,  _______,  KC_DEL , \
    _______, KC_5,    KC_6,    KC_7,    KC_8,    _______, _______, _______, _______, _______,  _______,  _______, \
    _______, KC_9,    KC_0,    KC_MINS, KC_EQL,  _______, _______, _______, _______, _______,  _______,  _______, \
    M(2),    _______, _______, _______, _______, _SPACE_, _SPACE_, _______, _______, _______,  _______,  _______
  ),

  [3] = KEYMAP( \
    KC_GRV,  KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  _______, _______, KC_LBRC, KC_RBRC, _______,  _______,  KC_BSPC, \
    _______, KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, _______, _______, KC_LCBR, KC_RCBR, KC_MINS,  KC_UNDS,  _______, \
    _______, KC_LPRN, KC_RPRN, KC_UNDS, KC_PLUS, _______, _______, KC_LPRN, KC_RPRN, _______,  _______,  _______, \
    M(3),    _______, _______, _______, _______, _SPACE_, _SPACE_, _______, _______, _______,  _______,  _______
  ),

  [4] = KEYMAP( \
    _______, _______, _______, _______, _______, _______, _______, _______, KC_UP,   _______,  _______,   KC_DEL , \
    _______, LEFTSCR, RIGHSCR,COLORCAP, _______, _______, _______, KC_LEFT, KC_DOWN, KC_RIGHT, _______,   M(7)   , \
    _______, _______, _______, SCRNCAP, _______, _______, _______, KC_VOLD, KC_VOLU, KC_MUTE,  _______,   _______, \
    M(4),    _______, _______, _______, _______, _SPACE_, _SPACE_, KC_MPRV, KC_MNXT, KC_MPLY,  _______,   RESET
  ),

  [5] = KEYMAP( \
    _______, _______, _______, _______, _______, _______, KC_WH_U, KC_BTN1, KC_MS_U, KC_BTN2,  _______,   RESET, \
    _______, _______, KC_ACL0, KC_ACL1, KC_ACL2, _______, KC_WH_D, KC_MS_L, KC_MS_D, KC_MS_R,  _______,   _______, \
    _______, _______, _______, _______, _______, _______, _______, KC_BTN4, KC_BTN3, KC_BTN5,  _______,   _______, \
    M(5),    _______, _______, _______, _______, _SPACE_, _SPACE_, _______, _______, _______,  _______,   _______
  )

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
