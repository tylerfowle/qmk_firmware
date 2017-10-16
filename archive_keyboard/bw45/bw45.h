#ifndef BW45_H
#define BW45_H

#include "matrix.h"
#include "keymap_common.h"
#include "backlight.h"
#include <stddef.h>

// This a shortcut to help you visually see your layout.
// The following is an example using the Planck MIT layout
// The first section contains all of the arguements
// The second converts the arguments into a two-dimensional array
#define KEYMAP( \
    k00, k01, k02, k03, k04, k05,      k07, k08, k09, k0A, k0B, k0C,  \
    k10, k11, k12, k13, k14, k15,      k17, k18, k19, k1A, k1B, k1C,  \
    k20, k21, k22, k23, k24, k25,      k27, k28, k29, k2A, k2B, k2C,  \
              k32, k33, k34, k35, k36, k37, k38, k39, k3A             \
) { \
    { k00, k01, k02, k03, k04, k05,      k07, k08, k09, k0A, k0B, k0C }, \
    { k10, k11, k12, k13, k14, k15,      k17, k18, k19, k1A, k1B, k1C }, \
    { k20, k21, k22, k23, k24, k25,      k27, k28, k29, k2A, k2B, k2C }, \
    {           k32, k33, k34, k35, k36, k37, k38, k39, k3A           }, \
}

void matrix_init_user(void);
void matrix_scan_user(void);
void process_action_user(keyrecord_t *record);
void led_set_user(uint8_t usb_led);

#endif
