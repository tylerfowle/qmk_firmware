#include "planck.h"
#include "action_util.h"
#include "action_code.h"
#include "audio.h"

#define __NO___ KC_NO
#define _______ KC_TRNS
#define _SPACE_ KC_SPC

#define TAB_FN LT(4,KC_TAB)
#define SCRNCAP LGUI(LSFT(KC_4))
#define COLORCAP LCTL(LALT(LGUI(KC_C)))

#define LEFTSCR LALT(KC_1)
#define RIGHSCR LALT(KC_2)


// Blank Layer

// layer 1: Description
// [1] = {
//   {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______,   _______},
//   {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______,   _______},
//   {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______,   _______},
//   {_______, _______, _______, _______, _______, _SPACE_, __NO___, _______, _______, _______,  _______,   _______}
// }


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  // layer 1: base mac
  [0] = {
    {M(6),    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,     KC_P,    KC_BSPC},
    {TAB_FN,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,     KC_SCLN, KC_ENT},
    {KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,   KC_SLSH, KC_RSFT},
    {M(0),   KC_LCTL, KC_LALT, KC_LGUI, MO(3),   _SPACE_, _SPACE_, MO(2),   KC_QUOT, KC_BSLS,  _______, TG(5)}
  },
  // layer 1: base windows
  [1] = {
    {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______,  _______},
    {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______,  _______},
    {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______,  _______},
    {M(1),   KC_LGUI, KC_LALT, KC_LCTL, _______, _______, _______, _______, _______, _______,  _______,  _______}
  },
  // layer 2: numbers
  [2] = {
    {KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    _______, _______, _______, _______, _______,  _______,  KC_DEL },
    {_______, KC_5,    KC_6,    KC_7,    KC_8,    _______, _______, _______, _______, _______,  _______,  _______},
    {_______, KC_9,    KC_0,    KC_MINS, KC_EQL,  _______, _______, _______, _______, _______,  _______,  _______},
    {M(2),   _______, _______, _______, _______, _SPACE_, __NO___, _______, _______, _______,  _______,  _______}
  },
  // layer 3: symbols
  [3] = {
    {KC_GRV,  KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  _______, _______, KC_LBRC, KC_RBRC, _______,  _______,  KC_BSPC},
    {_______, KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, _______, _______, KC_LCBR, KC_RCBR, KC_MINS,  KC_UNDS,  _______},
    {_______, KC_LPRN, KC_RPRN, KC_UNDS, KC_PLUS, _______, _______, KC_LPRN, KC_RPRN, _______,  _______,  _______},
    {M(3),   _______, _______, _______, _______, _SPACE_, __NO___, _______, _______, _______,  _______,  _______}
  },
  // layer 4: arrows and numbers
  [4] = {
    {_______, _______, _______, _______, _______, _______, _______, _______, KC_UP,   _______,  _______,   KC_DEL },
    {_______, LEFTSCR, RIGHSCR,COLORCAP, _______, _______, _______, KC_LEFT, KC_DOWN, KC_RIGHT, _______,   M(7)   },
    {_______, _______, _______, SCRNCAP, _______, _______, _______, KC_VOLD, KC_VOLU, KC_MUTE,  _______,   _______},
    {M(4),   _______, _______, _______, _______, _SPACE_, __NO___, KC_MPRV, KC_MNXT, KC_MPLY,  _______,   _______}
  },
  // layer 5: mouse
  [5] = {
    {_______, _______, _______, _______, _______, _______, KC_WH_U, KC_BTN1, KC_MS_U, KC_BTN2,  _______,   _______},
    {_______, _______, KC_ACL0, KC_ACL1, KC_ACL2, _______, KC_WH_D, KC_MS_L, KC_MS_D, KC_MS_R,  _______,   _______},
    {_______, _______, _______, _______, _______, _______, _______, KC_BTN4, KC_BTN3, KC_BTN5,  _______,   _______},
    {M(5),   _______, _______, _______, _______, _SPACE_, __NO___, _______, _______, _______,  _______,   _______}
  }
};


const uint16_t PROGMEM fn_actions[] = {
};

// Audio Stuff
float tone_startup[][2]    = SONG(STARTUP_SOUND);

float tone_0[][2] = {
  ED_NOTE(_G2 )
};
float tone_1[][2] = {
  ED_NOTE(_GS3 )
};
float tone_2[][2] = {
  ED_NOTE(_DS4 )
};
float tone_3[][2] = {
  ED_NOTE(_GS4 )
};
float tone_4[][2] = {
  ED_NOTE(_CS5 )
};
float tone_5[][2] = {
  ED_NOTE(_FS5 )
};


void matrix_init_user(void) {
  startup_user();
}
void startup_user() {
  _delay_ms(20); // gets rid of tick
  PLAY_NOTE_ARRAY(tone_startup, false, 0);
}

void set_default_layer(uint32_t default_layer_state)
{
  default_layer_set(1UL<<default_layer_state);
}




// Macro Stuff

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  switch(id) {
    case 0:
    if (record->event.pressed) {
      set_default_layer(1);
      PLAY_NOTE_ARRAY(tone_1, false, 0);
    }
    break;
    case 1:
    if (record->event.pressed) {
      set_default_layer(2);
      PLAY_NOTE_ARRAY(tone_2, false, 0);
    }
    break;
    case 2:
    if (record->event.pressed) {
      set_default_layer(3);
      PLAY_NOTE_ARRAY(tone_3, false, 0);
    }
    break;
    case 3:
    if (record->event.pressed) {
      set_default_layer(4);
      PLAY_NOTE_ARRAY(tone_4, false, 0);
    }
    break;
    case 4:
    if (record->event.pressed) {
      set_default_layer(5);
      PLAY_NOTE_ARRAY(tone_5, false, 0);
    }
    break;
    case 5:
    if (record->event.pressed) {
      set_default_layer(0);
      PLAY_NOTE_ARRAY(tone_0, false, 0);
    }
    break;


    case 6: {
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
    case 7:
    if (record->event.pressed) {
      return MACRO( I(5), D(LSFT), T(SCLN), U(LSFT), T(W), T(Q), T(ENT), END  );
    }
    break;

  }
  return MACRO_NONE;
};





