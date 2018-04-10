#include "planck.h"
#include "action_layer.h"
#include "action_util.h"
#include "action_code.h"
#include "audio.h"
#include "version.h"


// leader key
LEADER_EXTERNS();

#define _MAC  0
#define _WIN  1
#define _NUM 2
#define _SYM 3
#define _ARROW 4
#define _MOUSE 5


enum custom_keycodes {
  MAC = SAFE_RANGE,
  WIN,
  NUM,
  SYM,
  ARROW,
  MOUSE
};


#define __NO___ KC_NO
#define _______ KC_TRNS
#define _SPACE_ KC_SPC

#define TAB_FN LT(4,KC_TAB)
#define SCRNCAP LGUI(LSFT(KC_4))
#define COLORCAP LCTL(LALT(LGUI(KC_C)))

#define LEFTSCR LALT(KC_1)
#define RIGHSCR LALT(KC_2)

#define HYPRSPC MT(MOD_HYPR, KC_SPC)

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
    {KC_RCTL, KC_LCTL, KC_LALT, KC_LGUI, MO(3),   HYPRSPC, _SPACE_, MO(2),   KC_QUOT, KC_BSLS,  KC_LEAD, TG(5)}
  },
  // layer 1: base windows
  [1] = {
    {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______,  _______},
    {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______,  _______},
    {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______,  _______},
    {_______, KC_LALT, KC_LGUI, KC_LCTL, _______, _______, _______, _______, _______, _______,  _______,  _______}
  },
  // layer 2: numbers
  [2] = {
    {KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    _______, _______, _______, _______, _______,  _______,  KC_DEL },
    {_______, KC_5,    KC_6,    KC_7,    KC_8,    _______, _______, KC_QUOT, KC_DQUO, KC_GRV,   S(KC_GRV),_______},
    {_______, KC_9,    KC_0,    KC_MINS, KC_EQL,  _______, _______, _______, _______, _______,  _______,  _______},
    {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______,  _______}
  },
  // layer 3: symbols
  [3] = {
    {KC_GRV,  KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  _______, _______, KC_LBRC, KC_RBRC, _______,  _______,  KC_BSPC},
    {_______, KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, _______, _______, KC_LCBR, KC_RCBR, KC_MINS,  KC_UNDS,  _______},
    {_______, KC_LPRN, KC_RPRN, KC_UNDS, KC_PLUS, _______, _______, KC_LPRN, KC_RPRN, _______,  _______,  _______},
    {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______,  _______}
  },
  // layer 4: arrows and numbers
  [4] = {
    {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______,   KC_DEL },
    {_______, LEFTSCR, RIGHSCR,COLORCAP, _______, _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT, _______,   M(7)   },
    {_______, _______, _______, SCRNCAP, _______, _______, _______, KC_VOLD, KC_VOLU, KC_MUTE,  _______,   _______},
    {_______, _______, _______, _______, _______, _______, _______, KC_MPRV, KC_MNXT, KC_MPLY,  _______,   _______}
  },
  // layer 5: mouse
  [5] = {
    {_______, _______, _______, _______, _______, _______, KC_WH_U, KC_BTN1, KC_MS_U, KC_BTN2,  _______,   RESET},
    {_______, _______, KC_ACL0, KC_ACL1, KC_ACL2, _______, KC_WH_D, KC_MS_L, KC_MS_D, KC_MS_R,  _______,   _______},
    {_______, _______, _______, _______, _______, _______, _______, KC_BTN4, KC_BTN3, KC_BTN5,  _______,   _______},
    {MAC,     WIN,     NUM,     SYM,     ARROW,   _______, _______, _______, _______, _______,  _______,   _______}
  }
};


#ifdef AUDIO_ENABLE

// Audio Stuff
float song_startup[][2]  = SONG(STARTUP_SOUND);

float tone_mac[][2]      = SONG(QWERTY_SOUND);
float tone_win[][2]      = SONG(COLEMAK_SOUND);
float tone_mouse[][2]    = SONG(DVORAK_SOUND);

float tone_goodbye[][2]  = SONG(GOODBYE_SOUND);

#endif






void matrix_init_user(void) {
  startup_user();
}

void startup_user() {
  _delay_ms(20); // gets rid of tick
  PLAY_NOTE_ARRAY(song_startup, false, 0);
}

void set_default_layer(uint32_t default_layer_state) {
  default_layer_set(1UL<<default_layer_state);
}




// Macro Stuff
const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt) {
  switch(id) {

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









// leader key dictionary
void matrix_scan_user(void) {
  LEADER_DICTIONARY() {
    leading = false;
    leader_end();

    // random 10 character hash
    SEQ_ONE_KEY (KC_R) {
      tap_random_base64();
      tap_random_base64();
      tap_random_base64();
      tap_random_base64();
      tap_random_base64();
      tap_random_base64();
      tap_random_base64();
      tap_random_base64();
      tap_random_base64();
      tap_random_base64();
    }

    // version
    SEQ_ONE_KEY (KC_V) {
      SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
    }

  }
}


/* float tone_mac[][2]      = SONG(QWERTY_SOUND); */
/* float tone_win[][2]      = SONG(COLEMAK_SOUND); */
/* float tone_mouse[][2]    = SONG(DVORAK_SOUND); */

void persistant_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case MAC:
      if (record->event.pressed) {
        PLAY_NOTE_ARRAY(tone_mac, false, 0);
        persistant_default_layer_set(1UL<<_MAC);
      }
      return false;
      break;
    case WIN:
      if (record->event.pressed) {
        PLAY_NOTE_ARRAY(tone_win, false, 0);
        persistant_default_layer_set(1UL<<_WIN);
      }
      return false;
      break;
    case NUM:
      if (record->event.pressed) {
        persistant_default_layer_set(1UL<<_NUM);
      }
      return false;
      break;
    case SYM:
      if (record->event.pressed) {
        persistant_default_layer_set(1UL<<_SYM);
      }
      return false;
      break;
    case ARROW:
      if (record->event.pressed) {
        persistant_default_layer_set(1UL<<_ARROW);
      }
      return false;
      break;
    case MOUSE:
      if (record->event.pressed) {
        PLAY_NOTE_ARRAY(tone_mouse, false, 0);
        persistant_default_layer_set(1UL<<_MOUSE);
      }
      return false;
      break;

  }
  return true;
}
