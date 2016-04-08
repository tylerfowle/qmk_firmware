#include "keymap_common.h"

const uint8_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* 0: sebright */
	 KEYMAP(
    ESC,   Q,   W,   E,   R,   T,   Y,   U,   I,   O,   P, BSPC, \
		TAB,   A,   S,   D,   F,   G,   H,   J,   K,   L,   ENT, \
		LSFT,  Z,   X,   C,   V,   B,   N,   M,   COMM, DOT,  SLSH, \
		LCTL,  LALT,  LGUI,	 SPC,	FN1, FN2, PAUS, RSFT),
    /* 1: numfunc */
	 KEYMAP(
    GRV,   1,   2,   3,   4,   TRNS, TRNS, TRNS, UP, TRNS, TRNS, DEL, \
		CAPS,  5,   6,   7,   8,   TRNS, TRNS, LEFT, DOWN, RIGHT, ENT, \
		TRNS,  9,   0,  MINS,EQUAL,TRNS,  TRNS,INS,PSCR,TRNS, TRNS, \
		TRNS,  TRNS,  TRNS,	  TRNS,	     TRNS, TRNS, TRNS, TRNS),
    /* 2: arrow */
	 KEYMAP(
    ESC,   TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS, TRNS, \
		TRNS,  TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,  \
		TRNS,  TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS, TRNS, \ 
		TRNS,  TRNS,  TRNS,	  TRNS,	       TRNS, TRNS, TRNS, TRNS),
};
const uint16_t PROGMEM fn_actions[] = {
    /* Sebright Layout */
    [1] = ACTION_LAYER_MOMENTARY(1),
    [2] = ACTION_LAYER_MOMENTARY(2),
    [3] = ACTION_LAYER_MOMENTARY(3),

    [31] = ACTION_MODS_TAP_KEY(MOD_LSFT, KC_QUOTE),
	};
