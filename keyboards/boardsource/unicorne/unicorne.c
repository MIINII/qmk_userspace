#include "unicorne.h"

#ifdef OLED_ENABLE
#    include "oled_driver.h"

oled_rotation_t oled_init_kb(oled_rotation_t rotation) {
    return is_keyboard_master() ? rotation : OLED_ROTATION_180;
}

bool oled_task_kb(void) {
    if (!oled_task_user()) return false;

    if (is_keyboard_master()) {
        oled_write_ln_P(PSTR("Layer:"), false);
        switch (get_highest_layer(layer_state)) {
            case 0: oled_write_ln_P(PSTR("Base"), false); break;
            case 1: oled_write_ln_P(PSTR("Lower"), false); break;
            case 2: oled_write_ln_P(PSTR("Raise"), false); break;
            case 2: oled_write_ln_P(PSTR("Fn"), false); break;
            default: oled_write_ln_P(PSTR("Unknown"), false); break;
        }
    } else {
        oled_write_ln_P(PSTR("Unicorne"), false);
    }
    return false;
}
#endif
