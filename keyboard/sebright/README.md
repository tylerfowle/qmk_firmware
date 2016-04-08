Sebright keyboard firmware
======================
DIY compact keyboard designed by Alex Jackson (Panc Interactive).


## Build
Move to this directory then just run `make` like:

    $ make

Use `make -f Makefile.pjrc` if you want to use PJRC stack but I find no reason to do so now.


## Layouts

    /* 0: sebright */
	 KEYMAP(ESC,   Q,   W,   E,   R,   T,   Y,   U,   I,   O,   P, BSPC, \
			TAB,   A,   S,   D,   F,   G,   H,   J,   K,   L,   ENT, \
			LCTL,  Z,   X,   C,   V,   B,   N,   M,   COMM, FN1,  FN0, \
			LSFT,  LALT,     FN2,	 SPC,	QUOT,DOT, FN31,SLSH),
			
    /* 1: numfunc */
	 KEYMAP(GRV,   1,   2,   3,   4,   5,   6,   7,   8,   9,   0, DEL, \
			CAPS,  TRNS, TRNS, TRNS,  FN3,DOT, MINS, EQL,  LBRC,RBRC, ENT, \
			TRNS,TRNS,TRNS,TRNS,FN11,TRNS,TRNS,INS,PSCR,TRNS, TRNS, \
			TRNS,  TRNS,TRNS,	  TRNS,	     END,  PGUP, PGDN, TRNS),
    /* 2: arrow */
	 KEYMAP(ESC,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS, TRNS, \
			TRNS, TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,  \
			TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS, TRNS, \ 
			TRNS,  TRNS,TRNS,	  TRNS,	       LEFT,UP,  DOWN, RIGHT),
    /* 3: symbol */
	 KEYMAP(ESC,   1,   2,   3,   4,   5,   6,   7,   8,   9,   0, DEL, \
			BSPC,  A,   R,   S,   T,   D,   H,   N,   E,   I,   O, \
			LSFT,  Z,   X,   C,   V,   B,   K,   M,   COMM,FN1, FN0, \
			LCTL,  LALT,FN2,	  SPC,	    LEFT,UP,  DOWN, RIGHT),
};
const uint16_t PROGMEM fn_actions[] = {
    /* Sebright Layout */
    [0] = ACTION_LAYER_MOMENTARY(1),  // to numfunc overlay
    [1] = ACTION_LAYER_TOGGLE(2),     // toggle arrow overlay
    [2] = ACTION_LAYER_MOMENTARY(3),  // toggle symbol overlay
    [31] = ACTION_MODS_TAP_KEY(MOD_LSFT, KC_QUOTE),
	};

