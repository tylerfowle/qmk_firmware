#include QMK_KEYBOARD_H
#include "Joystick.h"
//#include <print.h>
#include "analog.h"
#include "action_layer.h"
#include "eeconfig.h"

//CHANGE THIS
/* char arrow_keys[4] = {KC_UP, KC_LEFT, KC_DOWN, KC_RIGHT}; // up, left, down, right */
char arrow_keys[4] = {KC_W, KC_A, KC_S, KC_D}; // up, left, down, right

static uint8_t joystickMode = 1;
/* static uint8_t joystick_modes = 2; // amount of modes */
static int actuation = 256; // actuation point for arrows (0-511)

enum my_keycodes {
    JSMODE = SAFE_RANGE,
};

bool arrows[4];


// layer leds
#define LED1 D7 // pin 6
#define LED2 C6 // pin 5
#define LED3 D0 // pin 3

void keyboard_pre_init_user(void) {
    // set pins as output
    setPinOutput(LED1);
    setPinOutput(LED2);
    setPinOutput(LED3);

    // turn first led on
    /* writePin(LED1, 50); */
}


// layouts
#define _GAME 0
#define _MAC 1
#define _WIN 2
#define _NUM 3
#define _SYM 4
#define _ARROW 5
#define _LAYERS 6

enum custom_keycodes {
    GAME = SAFE_RANGE,
    MAC,
    WIN,
    NUM,
    SYM,
    ARROW,
    LAYERS
};

// for readability
#define XXXXXXX KC_NO
#define _______ KC_TRNS
#define _SPACE_ KC_SPC
#define _PIPE__ LSFT(KC_BSLS)

// layer taps
#define TAB_FN   LT(_SYM, KC_TAB)
#define I_FN     LT(_ARROW, KC_I)

// mod taps
#define HYPRSPC MT(MOD_HYPR, KC_SPC)

// change what mode the joystick is in
// JSMODE

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    // 0
    [_GAME] = LAYOUT(
            M(0),    KC_C,    KC_P,    KC_Z,    KC_V,   KC_R,   KC_BSPC,
            TAB_FN,  KC_M,    KC_Q,    KC_F,    KC_E,   KC_EQL,
            I_FN,    KC_1,    KC_2,    KC_3,    KC_4,   KC_5,
            TO(1),   KC_COMM, KC_6,    KC_7,    KC_8,   KC_9,   KC_0,
            KC_LCTL, KC_LALT, KC_LGUI, OSL(_LAYERS), KC_SPC
            ),

    // 1
    [_MAC] = LAYOUT(
            M(0),    KC_1,    KC_2,    KC_3,    KC_4,   KC_5,  KC_BSPC,
            KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,   KC_T,
            TAB_FN,  KC_A,    KC_S,    KC_D,    KC_F,   KC_G,
            TO(2),   KC_LSFT, KC_Z,    KC_X,    KC_C,   KC_V,  KC_B,
            KC_LCTL, KC_LALT, KC_LGUI, _______, HYPRSPC
            ),

    // 2
    [_WIN] = LAYOUT(
            M(0),    KC_1,    KC_2,    KC_3,    KC_4,   KC_5,  KC_BSPC,
            KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,   KC_T,
            TAB_FN,  KC_A,    KC_S,    KC_D,    KC_F,   KC_G,
            TO(3),   KC_LSFT, KC_Z,    KC_X,    KC_C,   KC_V,  KC_B,
            KC_LALT, KC_LGUI, KC_LCTL, _______, HYPRSPC
            ),

    // 3
    [_NUM] = LAYOUT(
            KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F5,
            _______, KC_1,    KC_2,    KC_3,    KC_4,    _______,
            _______, KC_5,    KC_6,    KC_7,    KC_8,    _______,
            TO(4),   KC_9,    KC_0,    KC_MINS, KC_EQL,  _______, _______,
            _______, _______, _______, _______, _______
            ),

    // 4
    [_SYM] = LAYOUT(
            _______, KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,
            _______, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  _______,
            _______, KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, _______,
            TO(5),   KC_LPRN, KC_RPRN, KC_UNDS, KC_PLUS, _______, _______,
            _______, _______, _______, _______, _______
            ),

    // 5
    [_ARROW] = LAYOUT(
            _______, _______, _______, _______,  _______, _______, KC_DEL,
            _______, KC_HOME, KC_UP,   KC_END,   _______, _______,
            _______, KC_LEFT, KC_DOWN, KC_RIGHT, _______, _______,
            TO(6),   _______, _______, _______,  _______, _______, _______,
            _______, _______, _______, _______,  _______
            ),

    // 6
    [_LAYERS] = LAYOUT(
            RESET,   GAME,    MAC,     WIN,     NUM,     SYM,     ARROW,
            _______, _______, _______, _______, _______, _______,
            _______, _______, _______, _______, _______, _______,
            TG(6),   _______, _______, _______, _______, _______, _______,
            _______, _______, _______, _______, _______
            ),


};







//joystick config
joystick_config_t joystick_axes[JOYSTICK_AXES_COUNT] = {
    [0] = JOYSTICK_AXIS_VIRTUAL,
    [1] = JOYSTICK_AXIS_VIRTUAL
};

void joystick_task(){

    switch (joystickMode) {
        case 0: // gamepad
            joystick_status.axes[0] = -(analogReadPin(F5)/4 - 127);
            joystick_status.axes[1] = analogReadPin(F4)/4 - 128;
            joystick_status.status |= JS_UPDATED;
            send_joystick_packet(&joystick_status);
            break;
        case 1: // arrows
            if (!arrows[0] && analogReadPin(F5) - 512 > actuation){
                arrows[0] = true;
                register_code16(arrow_keys[1]);
            }
            else if (arrows[0] &&  analogReadPin(F5) - 512 < actuation){
                arrows[0] = false;
                unregister_code16(arrow_keys[1]);
            }
            if (!arrows[1] && analogReadPin(F5) - 512 < -actuation){
                arrows[1] = true;
                register_code16(arrow_keys[3]);
            }
            else if (arrows[1] && analogReadPin(F5) - 512 > -actuation){
                arrows[1] = false;
                unregister_code16(arrow_keys[3]);
            }
            if (!arrows[2] && analogReadPin(F4) - 512 > actuation){
                arrows[2] = true;
                register_code16(arrow_keys[2]);
            }
            else if (arrows[2] &&  analogReadPin(F4) - 512 < actuation){
                arrows[2] = false;
                unregister_code16(arrow_keys[2]);
            }
            if (!arrows[3] && analogReadPin(F4) - 512 < -actuation){
                arrows[3] = true;
                register_code16(arrow_keys[0]);
            }
            else if (arrows[3] && analogReadPin(F4) - 512 > -actuation){
                arrows[3] = false;
                unregister_code16(arrow_keys[0]);
            }
            break;

            /*case 2: // mouse

              report_mouse_t currentReport = pointint_device_get_report()
              currentReport.x = (analogReadPin(F5)-512)/4;
              currentReport.y = -(analogReadPin(F4)-512)/4;
              pointint_device_set_report(currentReport);
              poining_device_send();
              break;*/
    }
}



// MACROS
const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
    switch(id) {
        case 0: {
                    // esc is esc
                    // shift esc is grv
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
    }
    return MACRO_NONE;
};




void persistant_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {

    switch (keycode) {

        /* case JSMODE: */
        /*     if (record->event.pressed) { */
        /*         joystickMode++; */
        /*         if (joystickMode == joystick_modes){ */
        /*             joystickMode = 0; */
        /*         } */
        /*     } */
        /*     break; */

        // this controls semi perminent layer changes
        case GAME:      if (record->event.pressed) { persistant_default_layer_set(1UL<<_GAME); }      return false; break;
        case MAC:       if (record->event.pressed) { persistant_default_layer_set(1UL<<_MAC); }       return false; break;
        case WIN:       if (record->event.pressed) { persistant_default_layer_set(1UL<<_WIN); }       return false; break;
        case NUM:       if (record->event.pressed) { persistant_default_layer_set(1UL<<_NUM); }       return false; break;
        case SYM:       if (record->event.pressed) { persistant_default_layer_set(1UL<<_SYM); }       return false; break;
        case ARROW:     if (record->event.pressed) { persistant_default_layer_set(1UL<<_ARROW); }     return false; break;
        case LAYERS:    if (record->event.pressed) { persistant_default_layer_set(1UL<<_LAYERS); }    return false; break;

    }
    return true;
}






// from sketch
// LED configuration for each layout 1=on 0=off
/* byte layerLEDs[layers][3] = { */
/* {1, 0, 0}, */
/* {0, 1, 0}, */
/* {0, 0, 1}, */
/* {0, 0, 0} */
/* }; */

// from sketch
// analogWrite(LED1, brightness * layerLEDs[layer][0]);
// analogWrite(LED2, brightness * layerLEDs[layer][1]);
// analogWrite(LED3, brightness * layerLEDs[layer][2]);


/* void set_layer_led(int layerId) { */
/*     writePin(LED1, 0); */
/*     writePin(LED2, 0); */
/*     writePin(LED3, 0); */
/*     switch(layerId) { */
/*         case 0: */
/*             writePin(LED1, 50); */
/*             break; */
/*         case 1: */
/*             writePin(LED2, 50); */
/*             break; */
/*         case 2: */
/*             writePin(LED3, 50); */
/*             break; */
/*     } */
/* } */


//Set a led based on the layer
uint32_t layer_state_set_user(uint32_t state) {

    writePin(LED1, 0);
    writePin(LED2, 0);
    writePin(LED3, 0);

    switch(biton32(state)) {

        case 0:
            writePin(LED1, 50);
            break;

        case 1:
            writePin(LED2, 50);
            break;

        case 2:
            writePin(LED3, 50);
            break;

        case 3:
            writePin(LED1, 50);
            writePin(LED2, 50);
            break;

        case 4:
            writePin(LED1, 50);
            writePin(LED3, 50);
            break;

        case 5:
            writePin(LED2, 50);
            writePin(LED3, 50);
            break;

        case 6: // LAYERS
            writePin(LED1, 50);
            writePin(LED2, 50);
            writePin(LED3, 50);
            break;

    }
    return state;
}


/* void led_set_layer(int layer) { */
/*     switch(layer) { */
/*         case 0: */
/*             set_layer_led(0); // Turn on only the first layer indicator */
/*             break; */
/*         case 1: */
/*             set_layer_led(1); // Turn on only the second layer indicator */
/*             break; */
/*         case 2: */
/*             set_layer_led(2); // Turn on only the third layer indicator */
/*             break; */
/*     } */
/* } */
