#ifndef SB40_H
#define SB40_H

#include "matrix.h"
#include "keymap_common.h"
#include "backlight.h"
#include <stddef.h>

// This a shortcut to help you visually see your layout.
// The following is an example using the Planck MIT layout
// The first section contains all of the arguements
// The second converts the arguments into a two-dimensional array
#define KEYMAP( \
    k00, k01, k02, k03, k04, k05, k06, k07, k08, k09, k0A, k0B,  \
    k10, k11, k12, k13, k14, k15, k16, k17, k18, k19,      k1A,  \
    k20,      k22, k23, k24, k25, k26, k27, k28, k29, k2A, k2B,  \
         k31, k33, k34,      k35,      k37, k38, k39, k3A        \
) { \
    { k00, k01, k02, k03, k04, k05, k06, k07, k08, k09, k0A, k0B }, \
    { k10, k11, k12, k13, k14, k15, k16, k17, k18, k19, KC_NO,    k1A }, \
    { k20, KC_NO,    k22, k23, k24, k25, k26, k27, k28, k29, k2A, k2B }, \
    { KC_NO,    k31, KC_NO,    k33, k34, k35, KC_NO,    k37, k38, k39, k3A, KC_NO    } \
}

void matrix_init_user(void);
void matrix_scan_user(void);
void process_action_user(keyrecord_t *record);
void led_set_user(uint8_t usb_led);

#endif
