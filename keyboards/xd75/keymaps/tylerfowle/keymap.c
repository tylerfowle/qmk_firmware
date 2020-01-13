#include "xd75.h"
#include "action_layer.h"
#include "eeconfig.h"
#include "version.h"

extern keymap_config_t keymap_config;

#define _MAC  0
#define _WIN  1
#define _NUM 2
#define _SYM 3
#define _ARROW 4
#define _MOUSE 5
#define _EXT 6


enum custom_keycodes {
  MAC = SAFE_RANGE,
  WIN,
  NUM,
  SYM,
  ARROW,
  MOUSE,
  EXT
};


// for readability
#define XXXXXXX KC_NO
#define _______ KC_TRNS
#define _SPACE_ KC_SPC

#define HYPRSPC MT(MOD_HYPR, KC_SPC)
#define L_LAYER LT(3, KC_GRV)
#define R_LAYER LT(2, KC_QUOT)
#define TAB_FN LT(4,KC_TAB)

// shortcuts
#define SCRNCAP LGUI(LSFT(KC_4))
#define COLORCAP LCTL(LALT(LGUI(KC_C)))

#define LEFTSCR LALT(KC_1)
#define RIGHSCR LALT(KC_2)

#define PIPE LSFT(KC_BSLS)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* { _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ }, */
  /* _______, KC_F13,  KC_F14,  KC_F15,  KC_F16,  _______, _______, _______, _______, _______,  _______,   _______ */


  /* 0 */
  [_MAC] = {
    { M(0),    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______, _______, _______, KC_BSPC },
    { KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_INS,  KC_HOME, KC_PGUP, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    _______ },
    { TAB_FN,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_DEL,  KC_END,  KC_PGDN, KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_ENT  },
    { KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_P0,   KC_UP,   KC_PDOT, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT },
    { KC_LCTL, KC_LCTL, KC_LALT, KC_LGUI, MO(_SYM),HYPRSPC, KC_LEFT, KC_DOWN, KC_RIGHT, _SPACE_, MO(_NUM),MO(_EXT),KC_SLSH, KC_BSLS, TG(_MOUSE) },
  },

  /* 1 */
  [_WIN] = {
    { _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ },
    { _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ },
    { _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ },
    { _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ },
    { _______, KC_LALT, KC_LGUI, KC_LCTL, _______, _SPACE_, _______, _______, _______, _______, _______, _______, _______, _______, _______ },
  },

  /* 2 */
  [_NUM] = {
    { KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, KC_DEL  },
    { _______, KC_1,    KC_2,    KC_3,    KC_4,    _______, KC_P7,   KC_P8,   KC_P9,   _______, _______, _______, _______, _______, _______ },
    { _______, KC_5,    KC_6,    KC_7,    KC_8,    _______, KC_P4,   KC_P5,   KC_P6,   PIPE,    KC_QUOT, KC_DQUO, KC_GRV,  _______, _______ },
    { _______, KC_9,    KC_0,    KC_MINS, KC_EQL,  _______, KC_P1,   KC_P2,   KC_P3,   _______, _______, _______, _______, _______, _______ },
    { _______, _______, _______, _______, _______, _______, KC_P0,   KC_PPLS, KC_PDOT, _______, _______, _______, _______, _______, _______ },
  },

  /* 3 */
  [_SYM] = {
    { KC_GRV,  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_BSPC},
    { _______, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  _______, KC_P7,   KC_P8,   KC_P9,   _______, KC_LBRC, KC_RBRC, _______, _______, _______ },
    { _______, KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, _______, KC_P4,   KC_P5,   KC_P6,   PIPE,    KC_LCBR, KC_RCBR, KC_MINS, KC_UNDS, _______ },
    { _______, KC_LPRN, KC_RPRN, KC_UNDS, KC_PLUS, _______, KC_P1,   KC_P2,   KC_P3,   _______, KC_LPRN, KC_RPRN, _______, _______, _______ },
    { _______, _______, _______, _______, _______, _______, KC_P0,   KC_PPLS, KC_PDOT, _______, _______, _______, _______, _______, _______ },
  },

  /* 4 */
  [_ARROW] = {
    { _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_DEL  },
    { _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_HOME, _______, KC_END,  _______, _______ },
    { _______, LEFTSCR, RIGHSCR,COLORCAP, _______, _______, _______, _______, _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT, _______, M(1)   },
    { _______, _______, _______, SCRNCAP, _______, _______, _______, _______, _______, _______, _______, KC_VOLD, KC_VOLU, KC_MUTE, _______ },
    { _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_MPRV, KC_MNXT, KC_MPLY, _______ },
  },

  /* 5 */
  [_MOUSE] = {
    { _______, _______, _______, _______, _______, _______, M(6),    _______, _______, _______, _______, _______, _______, _______, RESET   },
    { _______, _______, _______, _______, _______, _______, M(5),    RGB_VAI, RGB_VAD, KC_WH_U, KC_BTN1, KC_MS_U, KC_BTN2, _______, _______ },
    { _______, _______, KC_ACL0, KC_ACL1, KC_ACL2, _______, M(4),    RGB_SAI, RGB_SAD, KC_WH_D, KC_MS_L, KC_MS_D, KC_MS_R, _______, _______ },
    { _______, _______, _______, _______, _______, _______, M(3),    RGB_HUI, RGB_HUD, _______, KC_BTN4, KC_BTN3, KC_BTN5, _______, _______ },
    { MAC,     WIN,     NUM,     SYM,     ARROW,   EXT,     M(2),    RGB_TOG, RGB_MOD, _______, _______, _______, _______, _______, _______ },
  },

  /* 6 */
  [_EXT] = {
    { _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ },
    { _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ },
    { _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ },
    { _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ },
    { _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ },
  }
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

            // changing rgblight modes

            // solid color
    case 2:
            if (record->event.pressed) {
              rgblight_enable();
              rgblight_mode(1);
            }
            break;
            // rainbow mood
    case 3:
            if (record->event.pressed) {
              rgblight_enable();
              rgblight_mode(6);
            }
            break;
            // rainbow swirl
    case 4:
            if (record->event.pressed) {
              rgblight_enable();
              rgblight_mode(9);
            }
            break;
            // snake
    case 5:
            if (record->event.pressed) {
              rgblight_enable();
              rgblight_mode(15);
            }
            break;
            // knight
    case 6:
            if (record->event.pressed) {
              rgblight_enable();
              rgblight_mode(21);
            }
            break;

  }
  return MACRO_NONE;
};

void persistant_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

/* this controls semi perminent layer changes */
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case MAC:
      if (record->event.pressed) {
        persistant_default_layer_set(1UL<<_MAC);
      }
      return false;
      break;
    case WIN:
      if (record->event.pressed) {
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
        persistant_default_layer_set(1UL<<_MOUSE);
      }
      return false;
      break;

  }
  return true;
}

