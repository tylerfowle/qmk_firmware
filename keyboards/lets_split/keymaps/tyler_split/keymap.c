#include QMK_KEYBOARD_H

#define _MAC  0
#define _WIN  1
#define _NUM 2
#define _SYM 3
#define _ARROW 4
#define _EXTRA 5
#define _MIDI 6
#define _MOUSE 7

enum custom_keycodes {
  MAC = SAFE_RANGE,
  WIN,
  NUM,
  SYM,
  ARROW,
  MOUSE,
  EXTRA,
  MIDI
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

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_MAC] = LAYOUT_ortho_4x12( \
      M(0),    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,     KC_P,    KC_BSPC, \
      TAB_FN,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,     KC_SCLN, KC_ENT, \
      KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,   KC_SLSH, KC_RSFT, \
      KC_LCTL, KC_LCTL, KC_LALT, KC_LGUI, MO(_SYM),HYPRSPC, _SPACE_, MO(_NUM),MO(_EXTRA),KC_BSLS,KC_PIPE, TG(_MOUSE)
      ),

  [_WIN] = LAYOUT_ortho_4x12( \
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, \
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, \
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, \
      _______, KC_LALT, KC_LGUI, KC_LCTL, _______, _______, _______, _______, _______, _______,  _______, _______
      ),

  [_NUM] = LAYOUT_ortho_4x12( \
      KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_BSPC, _______, _______, _______, _______,  _______, KC_DEL , \
      _______, KC_5,    KC_6,    KC_7,    KC_8,    KC_ENT,  _______, KC_QUOT, KC_DQUO, KC_GRV,   _______, _______, \
      KC_DEL,  KC_9,    KC_0,    KC_MINS, KC_EQL,  _______, _______, _______, _______, _______,  _______, _______, \
      KC_ENT,  _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______
      ),

  [_SYM] = LAYOUT_ortho_4x12( \
      KC_GRV,  KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  _______, _______, KC_LBRC, KC_RBRC, _______,  _______, KC_BSPC, \
      _______, KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, _______, _______, KC_LCBR, KC_RCBR, KC_MINS,  KC_UNDS, _______, \
      _______, KC_LPRN, KC_RPRN, KC_UNDS, KC_PLUS, _______, _______, KC_LPRN, KC_RPRN, _______,  _______, _______, \
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______
      ),

  [_ARROW] = LAYOUT_ortho_4x12( \
      _______, _______, _______, _______, _______, _______, _______, KC_HOME, _______, KC_END,   _______, KC_DEL , \
      _______, LEFTSCR, RIGHSCR,COLORCAP, _______, _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT, _______, M(1)   , \
      _______, _______, _______, SCRNCAP, _______, _______, _______, _______, KC_VOLD, KC_VOLU,  KC_MUTE, _______, \
      _______, _______, _______, _______, _______, _______, _______, _______, KC_MPRV, KC_MNXT,  KC_MPLY, _______
      ),

  [_MIDI] = LAYOUT_ortho_4x12( \
      MI_CHU,  _______, MI_Cs,   MI_Ds,   _______, MI_Fs,   MI_Gs,    MI_As,   _______,  MI_Cs_1,  MI_Ds_1, TG(_MIDI), \
      MI_MOD,  MI_C,    MI_D,    MI_E,    MI_F,    MI_G,    MI_A,     MI_B,    MI_C_1,   MI_D_1,   MI_E_1,  MI_F_1,  \
      MI_SUS, _______, _______, _______, _______, _______, _______,   _______, MI_OCTD,  MI_OCTU,  _______, MI_SUS,  \
      MI_MOD, _______, _______, _______, _______, _______, MI_ALLOFF, _______, MI_TRNSD, MI_TRNSU, MI_TRNS_0, _______
      ),

  [_EXTRA] = LAYOUT_ortho_4x12( \
      _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   _______, _______, _______, _______, _______,  _______, _______, \
      _______, KC_F5,   KC_F6,   KC_F7,   KC_F8,   _______, _______, _______, _______, _______,  _______, _______, \
      _______, KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, _______, _______, _______, _______,  _______, _______, \
      _______, KC_F13,  KC_F14,  KC_F15,  KC_F16,  _______, _______, _______, _______, _______,  _______, _______
      ),

  [_MOUSE] = LAYOUT_ortho_4x12( \
      _______, _______, _______, _______, _______, _______, KC_WH_U, KC_BTN1, KC_MS_U, KC_BTN2,  _______, RESET, \
      _______, _______, KC_ACL0, KC_ACL1, KC_ACL2, _______, KC_WH_D, KC_MS_L, KC_MS_D, KC_MS_R,  _______, _______, \
      _______, _______, _______, _______, _______, _______, _______, KC_BTN4, KC_BTN3, KC_BTN5,  _______, _______, \
      MAC,     WIN,     NUM,     SYM,     ARROW,   TG(_MIDI),    _______, _______, _______, _______,  _______, _______
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

void persistant_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}


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
    case MIDI:
      if (record->event.pressed) {
        persistant_default_layer_set(1UL<< _MIDI);
      }
      return false;
      break;
  }
  return true;
}
