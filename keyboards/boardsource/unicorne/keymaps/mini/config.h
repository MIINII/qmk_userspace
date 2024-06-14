/* Copyright 2021 Yang Hu
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#define MASTER_LEFT

#define QMK_LED     D5
#define QMK_SPEAKER C6

#define TAPPING_TERM 200
#define TAPPING_TERM_PER_KEY
// used for Tapping Term on thumb keys
#define TAPPING_TERM_THUMB 125
#define HOLD_ON_OTHER_KEY_PRESS
#define PERMISSIVE_HOLD // 홈로우 모드 사용할때 필요

#define OLED_FONT_H "keyboards/yanghu/unicorne/glcdfont.c"
#define ENCODER_RESOLUTION 4

#define RGBLIGHT_DEFAULT_MODE RGBLIGHT_MODE_BREATHING
#define RGBLIGHT_DEFAULT_COLOR HSV_BLUE

#define COMBO_TERM 40

// These mostly affect my one-shot Shift key, providing a CapsLock alternative.
// I want a relatively low timeout, so if I accidentally type "Shift", I can pause just briefly and move on.
#define ONESHOT_TAP_TOGGLE 3  /* Tapping this number of times holds the key until tapped once again. */
#define ONESHOT_TIMEOUT 2000  /* Time (in ms) before the one shot key is released */