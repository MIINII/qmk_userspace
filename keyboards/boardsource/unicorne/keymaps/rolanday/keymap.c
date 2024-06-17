// Copyright 2022 Mark Stosberg (@markstos)
// SPDX-License-Identifier: GPL-2.0-or-later
#include QMK_KEYBOARD_H
#pragma once
enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  FUNC,
  BACKLIT
};

enum combos {
    QW_ESC,
    DOTCOM_SCLN
};

const uint16_t PROGMEM esc_combo[] = {KC_Q, KC_W, COMBO_END};
const uint16_t PROGMEM semi_combo[] = {KC_DOT, KC_COMM, COMBO_END};

combo_t key_combos[] = {
    [QW_ESC] = COMBO(esc_combo, KC_ESC),
    [DOTCOM_SCLN] = COMBO(semi_combo, KC_SCLN)
};

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
enum custom_layers {
    _QWERTY,
    _LOWER,
    _RAISE,
    _FUNC,
    UPDIR = SAFE_RANGE,
    BRACES,
    SELLINE,
    SELWORD,
    KC_QWERTY,
    KC_GAMING,
    KC_LOWER,
    KC_RAISE,
    KC_FUNC,
    KC_PRVWD,
    KC_NXTWD,
    KC_LSTRT,
    KC_LEND,
    KC_DLINE,
    KC_BSPC_DEL,
    KC_LAYER
};

// For _QWERTY layer
#define OSM_LCTL OSM(MOD_LCTL)
#define OSM_AGR  OSM(MOD_RALT)
#define OSL_FUN  OSL(_FUNC)
#define GUI_ENT  GUI_T(KC_ENT)
#define CTL_ENT  LCTL_T(KC_ENT)
#define LOW_TAB  LT(_LOWER, KC_TAB)
#define LOW_ENT  LT(_LOWER, KC_ENT)
#define RSE_BSP  LT(_RAISE, KC_BSPC)
#define RSE_SPC  LT(_RAISE, KC_SPC)


// For _RAISE layer
#define CTL_ESC  LCTL_T(KC_ESC)

// Left-hand home row mods
#define HOME_A LSFT_T(KC_A)
#define HOME_S LCTL_T(KC_S)
#define HOME_D LGUI_T(KC_D)
#define HOME_F LALT_T(KC_F)

// Right-hand home row mods
#define HOME_J LALT_T(KC_J)
#define HOME_K RGUI_T(KC_K)
#define HOME_L RCTL_T(KC_L)
#define HOME_SCLN RSFT_T(KC_SCLN)



const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                     KC_Y    ,KC_U    ,KC_I    ,KC_O    ,KC_P    ,KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       KC_LGUI,   KC_A,    KC_S,  KC_D,  KC_F,    KC_G,                         KC_H    ,KC_J     ,KC_K   ,KC_L    ,HOME_SCLN,KC_QUOT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       KC_LSFT,   KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                     KC_N    ,KC_M    ,KC_COMM ,KC_DOT  ,KC_SLSH ,OSL_FUN ,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                        KC_LALT, MO(_LOWER), CTL_ENT, KC_SPC, MO(_RAISE), KC_RALT
                                      //`--------------------------'  `--------------------------'
  ),


  [_LOWER] = LAYOUT(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      KC_GRV, KC_EXLM, KC_AT,  KC_HASH, KC_DLR,  KC_PERC,                      KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_MINS,  KC_DEL,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LGUI, KC_1,    KC_2,   KC_3,    KC_4,    KC_5,                         KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_EQL ,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT, XXXXXXX , KC_TILD,KC_GRV, KC_LBRC, KC_LCBR,                       KC_RCBR, KC_RBRC, KC_SCLN,KC_COLN,  KC_SLSH, _______ ,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LALT,  KC_TRNS, LOWER,    KC_TRNS, KC_TRNS, KC_COLON
                                      //`--------------------------'  `--------------------------'
  ),

  [_RAISE] = LAYOUT(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      KC_GRV, KC_DEL , XXXXXXX, KC_UNDS, KC_PLUS, KC_PGUP,                      XXXXXXX, KC_HOME, KC_UP, KC_END, KC_PIPE,KC_BSPC ,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LGUI, KC_HOME, KC_END , KC_MINS, KC_EQL , KC_PGDN,                      KC_LEFT, KC_LEFT, KC_DOWN, KC_RGHT, KC_APP ,_______ ,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT, KC_LT  , KC_GT  , KC_COPY, KC_PSTE, KC_SCLN,                      KC_MPLY, KC_PGUP, KC_DOWN, KC_PGDN, KC_VOLU,_______ ,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          CTL_ESC, KC_TRNS, XXXXXXX,    RAISE  , KC_TRNS, KC_TRNS
                                      //`--------------------------'  `--------------------------'
  ),

  [_FUNC] = LAYOUT(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      _______, KC_F1  , KC_F2  , KC_F3   , KC_F4 ,  KC_F5 ,                     KC_F6   , KC_F7  , KC_F8  , KC_F9  , KC_F10 ,_______ ,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, KC_F11 , KC_F12 , XXXXXXX, XXXXXXX, XXXXXXX,                     XXXXXXX , XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,_______ ,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, KC_CAPS, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                     XXXXXXX , XXXXXXX, XXXXXXX, XXXXXXX, QK_BOOT,XXXXXXX ,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, FUNC   , XXXXXXX
                                      //`--------------------------'  `--------------------------'
  )
};

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
      case LT(_RAISE, KC_BSPC):
            return TAPPING_TERM_THUMB;
      case LT(_LOWER, KC_TAB):
            return TAPPING_TERM_THUMB;
      default:
            return TAPPING_TERM;
    }
}
/* KEYBOARD PET START */

/* settings */
#    define MIN_WALK_SPEED      10
#    define MIN_RUN_SPEED       40

/* advanced settings */
#    define ANIM_FRAME_DURATION 200  // how long each frame lasts in ms
#    define ANIM_SIZE           96   // number of bytes in array. If you change sprites, minimize for adequate firmware size. max is 1024

/* timers */
uint32_t anim_timer = 0;

/* current frame */
uint8_t current_frame = 0;

/* status variables */
int   current_wpm = 0;
led_t led_usb_state;

bool isSneaking = false;
bool isJumping  = false;
bool showedJump = true;

/* logic */
static void render_luna(int LUNA_X, int LUNA_Y) {
    /* Sit */
    static const char PROGMEM sit[2][ANIM_SIZE] = {/* 'sit1', 32x22px */
                                                   {
                                                       0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x1c, 0x02, 0x05, 0x02, 0x24, 0x04, 0x04, 0x02, 0xa9, 0x1e, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x10, 0x08, 0x68, 0x10, 0x08, 0x04, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x06, 0x82, 0x7c, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0x04, 0x0c, 0x10, 0x10, 0x20, 0x20, 0x20, 0x28, 0x3e, 0x1c, 0x20, 0x20, 0x3e, 0x0f, 0x11, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                                                   },

                                                   /* 'sit2', 32x22px */
                                                   {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x1c, 0x02, 0x05, 0x02, 0x24, 0x04, 0x04, 0x02, 0xa9, 0x1e, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x90, 0x08, 0x18, 0x60, 0x10, 0x08, 0x04, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x0e, 0x82, 0x7c, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0x04, 0x0c, 0x10, 0x10, 0x20, 0x20, 0x20, 0x28, 0x3e, 0x1c, 0x20, 0x20, 0x3e, 0x0f, 0x11, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}};

    /* Walk */
    static const char PROGMEM walk[2][ANIM_SIZE] = {/* 'walk1', 32x22px */
                                                    {
                                                        0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x40, 0x20, 0x10, 0x90, 0x90, 0x90, 0xa0, 0xc0, 0x80, 0x80, 0x80, 0x70, 0x08, 0x14, 0x08, 0x90, 0x10, 0x10, 0x08, 0xa4, 0x78, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x08, 0xfc, 0x01, 0x00, 0x00, 0x00, 0x00, 0x80, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x18, 0xea, 0x10, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x1c, 0x20, 0x20, 0x3c, 0x0f, 0x11, 0x1f, 0x03, 0x06, 0x18, 0x20, 0x20, 0x3c, 0x0c, 0x12, 0x1e, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                                                    },

                                                    /* 'walk2', 32x22px */
                                                    {
                                                        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x40, 0x20, 0x20, 0x20, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x10, 0x28, 0x10, 0x20, 0x20, 0x20, 0x10, 0x48, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1f, 0x20, 0xf8, 0x02, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x03, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x10, 0x30, 0xd5, 0x20, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3f, 0x20, 0x30, 0x0c, 0x02, 0x05, 0x09, 0x12, 0x1e, 0x02, 0x1c, 0x14, 0x08, 0x10, 0x20, 0x2c, 0x32, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                                                    }};

    /* Run */
    static const char PROGMEM run[2][ANIM_SIZE] = {/* 'run1', 32x22px */
                                                   {
                                                       0x00, 0x00, 0x00, 0x00, 0xe0, 0x10, 0x08, 0x08, 0xc8, 0xb0, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x40, 0x40, 0x3c, 0x14, 0x04, 0x08, 0x90, 0x18, 0x04, 0x08, 0xb0, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0xc4, 0xa4, 0xfc, 0x00, 0x00, 0x00, 0x00, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xc8, 0x58, 0x28, 0x2a, 0x10, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0e, 0x09, 0x04, 0x04, 0x04, 0x04, 0x02, 0x03, 0x02, 0x01, 0x01, 0x02, 0x02, 0x04, 0x08, 0x10, 0x26, 0x2b, 0x32, 0x04, 0x05, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00,
                                                   },

                                                   /* 'run2', 32x22px */
                                                   {
                                                       0x00, 0x00, 0x00, 0xe0, 0x10, 0x10, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0x80, 0x78, 0x28, 0x08, 0x10, 0x20, 0x30, 0x08, 0x10, 0x20, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x04, 0x08, 0x10, 0x11, 0xf9, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x10, 0xb0, 0x50, 0x55, 0x20, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0x0c, 0x10, 0x20, 0x28, 0x37, 0x02, 0x1e, 0x20, 0x20, 0x18, 0x0c, 0x14, 0x1e, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                                                   }};

    /* Bark */
    static const char PROGMEM bark[2][ANIM_SIZE] = {/* 'bark1', 32x22px */
                                                    {
                                                        0x00, 0xc0, 0x20, 0x10, 0xd0, 0x30, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0x40, 0x3c, 0x14, 0x04, 0x08, 0x90, 0x18, 0x04, 0x08, 0xb0, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x04, 0x08, 0x10, 0x11, 0xf9, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xc8, 0x48, 0x28, 0x2a, 0x10, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0x0c, 0x10, 0x20, 0x28, 0x37, 0x02, 0x02, 0x04, 0x08, 0x10, 0x26, 0x2b, 0x32, 0x04, 0x05, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                                                    },

                                                    /* 'bark2', 32x22px */
                                                    {
                                                        0x00, 0xe0, 0x10, 0x10, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0x40, 0x40, 0x2c, 0x14, 0x04, 0x08, 0x90, 0x18, 0x04, 0x08, 0xb0, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x04, 0x08, 0x10, 0x11, 0xf9, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xc0, 0x48, 0x28, 0x2a, 0x10, 0x0f, 0x20, 0x4a, 0x09, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0x0c, 0x10, 0x20, 0x28, 0x37, 0x02, 0x02, 0x04, 0x08, 0x10, 0x26, 0x2b, 0x32, 0x04, 0x05, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                                                    }};

    /* Sneak */
    static const char PROGMEM sneak[2][ANIM_SIZE] = {/* 'sneak1', 32x22px */
                                                     {
                                                         0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x40, 0x40, 0x40, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0x40, 0x40, 0x80, 0x00, 0x80, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1e, 0x21, 0xf0, 0x04, 0x02, 0x02, 0x02, 0x02, 0x03, 0x02, 0x02, 0x04, 0x04, 0x04, 0x03, 0x01, 0x00, 0x00, 0x09, 0x01, 0x80, 0x80, 0xab, 0x04, 0xf8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x1c, 0x20, 0x20, 0x3c, 0x0f, 0x11, 0x1f, 0x02, 0x06, 0x18, 0x20, 0x20, 0x38, 0x08, 0x10, 0x18, 0x04, 0x04, 0x02, 0x02, 0x01, 0x00, 0x00, 0x00, 0x00,
                                                     },

                                                     /* 'sneak2', 32x22px */
                                                     {
                                                         0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x40, 0x40, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0xa0, 0x20, 0x40, 0x80, 0xc0, 0x20, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3e, 0x41, 0xf0, 0x04, 0x02, 0x02, 0x02, 0x03, 0x02, 0x02, 0x02, 0x04, 0x04, 0x02, 0x01, 0x00, 0x00, 0x00, 0x04, 0x00, 0x40, 0x40, 0x55, 0x82, 0x7c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3f, 0x20, 0x30, 0x0c, 0x02, 0x05, 0x09, 0x12, 0x1e, 0x04, 0x18, 0x10, 0x08, 0x10, 0x20, 0x28, 0x34, 0x06, 0x02, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00,
                                                     }};

    /* animation */
    void animate_luna(void) {
        /* jump */
        if (isJumping || !showedJump) {
            /* clear */
            oled_set_cursor(LUNA_X, LUNA_Y + 2);
            oled_write("     ", false);

            oled_set_cursor(LUNA_X, LUNA_Y - 1);

            showedJump = true;
        } else {
            /* clear */
            oled_set_cursor(LUNA_X, LUNA_Y - 1);
            oled_write("     ", false);

            oled_set_cursor(LUNA_X, LUNA_Y);
        }

        /* switch frame */
        current_frame = (current_frame + 1) % 2;

        /* current status */
        if (led_usb_state.caps_lock) {
            oled_write_raw_P(bark[current_frame], ANIM_SIZE);

        } else if (isSneaking) {
            oled_write_raw_P(sneak[current_frame], ANIM_SIZE);

        } else if (current_wpm <= MIN_WALK_SPEED) {
            oled_write_raw_P(sit[current_frame], ANIM_SIZE);

        } else if (current_wpm <= MIN_RUN_SPEED) {
            oled_write_raw_P(walk[current_frame], ANIM_SIZE);

        } else {
            oled_write_raw_P(run[current_frame], ANIM_SIZE);
        }
    }

#    if OLED_TIMEOUT > 0
    /* the animation prevents the normal timeout from occuring */
    if (last_input_activity_elapsed() > OLED_TIMEOUT && last_led_activity_elapsed() > OLED_TIMEOUT) {
        oled_off();
        return;
    } else {
        oled_on();
    }
#    endif

    /* animation timer */
    if (timer_elapsed32(anim_timer) > ANIM_FRAME_DURATION) {
        anim_timer = timer_read32();
        animate_luna();
    }
}

/* KEYBOARD PET END */

static void print_logo_narrow(void) {
    render_logo();

    /* wpm counter */
    uint8_t n = get_current_wpm();
    char    wpm_str[4];
    oled_set_cursor(0, 14);
    wpm_str[3] = '\0';
    wpm_str[2] = '0' + n % 10;
    wpm_str[1] = '0' + (n /= 10) % 10;
    wpm_str[0] = '0' + n / 10;
    oled_write(wpm_str, false);

    oled_set_cursor(0, 15);
    oled_write(" wpm", false);
}

static void print_status_narrow(void) {
    /* Print current mode */
    oled_set_cursor(0, 0);
    if (keymap_config.swap_lctl_lgui) {
        oled_write_raw_P(mac_logo, sizeof(mac_logo));
    } else {
        oled_write_raw_P(windows_logo, sizeof(windows_logo));
    }

    oled_set_cursor(0, 3);

    switch (get_highest_layer(default_layer_state)) {
        case _QWERTY:
            oled_write("QWRTY", false);
            break;
        default:
            oled_write("UNDEF", false);
    }

    oled_set_cursor(0, 5);

    /* Print current layer */
    oled_write("LAYER", false);

    oled_set_cursor(0, 6);

    switch (get_highest_layer(layer_state)) {
        case _QWERTY:
            oled_write("Base ", false);
            break;
        case _RAISE:
            oled_write("Raise", false);
            break;
        case _LOWER:
            oled_write("Lower", false);
            break;
        case _FUNC:
            oled_write("Adj  ", false);
            break;
        default:
            oled_write("Undef", false);
    }

    /* caps lock */
    oled_set_cursor(0, 8);
    oled_write("CPSLK", led_usb_state.caps_lock);

    /* KEYBOARD PET RENDER START */

    render_luna(0, 13);

    /* KEYBOARD PET RENDER END */
}

oled_rotation_t oled_init_user(oled_rotation_t rotation) { return OLED_ROTATION_270; }

bool oled_task_user(void) {
    /* KEYBOARD PET VARIABLES START */

    current_wpm   = get_current_wpm();
    led_usb_state = host_keyboard_led_state();

    /* KEYBOARD PET VARIABLES END */

    if (is_keyboard_master()) {
        print_status_narrow();
    } else {
        print_logo_narrow();
    }
    return false;
}

#endif

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case UPDIR: // 상위 디렉토리로 이동
            if (record->event.pressed) {
                SEND_STRING("../");
            }
            return false;

        case BRACES: // 괄호들 만들기
            if (record->event.pressed) {
                uint8_t mods         = get_mods();
                uint8_t oneshot_mods = get_oneshot_mods();
                clear_oneshot_mods(); // Temporarily disable mods.
                unregister_mods(MOD_MASK_CSAG);
                if ((mods | oneshot_mods) & MOD_MASK_SHIFT) {
                    SEND_STRING("{}");
                } else if ((mods | oneshot_mods) & MOD_MASK_CTRL) {
                    SEND_STRING("<>");
                } else {
                    SEND_STRING("[]");
                }
                tap_code(KC_LEFT); // Move cursor between braces.
                set_mods(mods);    // Restore mods.
            }
            return false;

        case SELWORD: // 단어 선택
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL(SS_TAP(X_RGHT) SS_LSFT(SS_TAP(X_LEFT))));
                // Mac users, change LCTL to LALT:
                // SEND_STRING(SS_LALT(SS_TAP(X_RGHT) SS_LSFT(SS_TAP(X_LEFT))));
            }
            return false;

        case SELLINE: // 줄 선택
            if (record->event.pressed) {
                SEND_STRING(SS_TAP(X_HOME) SS_LSFT(SS_TAP(X_END))); // home > Shift+end
                // Mac users, use:
                // SEND_STRING(SS_LCTL("a" SS_LSFT("e")));
            }
            return false;

            switch (keycode) {
                case KC_QWERTY:
                    if (record->event.pressed) {
                        set_single_persistent_default_layer(_QWERTY);
                    }
                    return false;
                case KC_GAMING:
                    if (record->event.pressed) {
                        set_single_persistent_default_layer(_GAMING);
                    }
                    return false;
                case KC_LOWER:
                    if (record->event.pressed) {
                        layer_on(_LOWER);
                        update_tri_layer(_LOWER, _RAISE, _FUNC);
                    } else {
                        layer_off(_LOWER);
                        update_tri_layer(_LOWER, _RAISE, _FUNC);
                    }
                    return false;
                case KC_RAISE:
                    if (record->event.pressed) {
                        layer_on(_RAISE);
                        update_tri_layer(_LOWER, _RAISE, _FUNC);
                    } else {
                        layer_off(_RAISE);
                        update_tri_layer(_LOWER, _RAISE, _FUNC);
                    }
                    return false;
                case KC_FUNC:
                    if (record->event.pressed) {
                        layer_on(_FUNC);
                    } else {
                        layer_off(_FUNC);
                    }
                    return false;
                case KC_PRVWD:
                    if (record->event.pressed) {
                        if (keymap_config.swap_lctl_lgui) {
                            register_mods(mod_config(MOD_LALT));
                            register_code(KC_LEFT);
                        } else {
                            register_mods(mod_config(MOD_LCTL));
                            register_code(KC_LEFT);
                        }
                    } else {
                        if (keymap_config.swap_lctl_lgui) {
                            unregister_mods(mod_config(MOD_LALT));
                            unregister_code(KC_LEFT);
                        } else {
                            unregister_mods(mod_config(MOD_LCTL));
                            unregister_code(KC_LEFT);
                        }
                    }
                    break;
                case KC_NXTWD:
                    if (record->event.pressed) {
                        if (keymap_config.swap_lctl_lgui) {
                            register_mods(mod_config(MOD_LALT));
                            register_code(KC_RIGHT);
                        } else {
                            register_mods(mod_config(MOD_LCTL));
                            register_code(KC_RIGHT);
                        }
                    } else {
                        if (keymap_config.swap_lctl_lgui) {
                            unregister_mods(mod_config(MOD_LALT));
                            unregister_code(KC_RIGHT);
                        } else {
                            unregister_mods(mod_config(MOD_LCTL));
                            unregister_code(KC_RIGHT);
                        }
                    }
                    break;
                case KC_LSTRT:
                    if (record->event.pressed) {
                        if (keymap_config.swap_lctl_lgui) {
                            /* CMD-arrow on Mac, but we have CTL and GUI swapped */
                            register_mods(mod_config(MOD_LCTL));
                            register_code(KC_LEFT);
                        } else {
                            register_code(KC_HOME);
                        }
                    } else {
                        if (keymap_config.swap_lctl_lgui) {
                            unregister_mods(mod_config(MOD_LCTL));
                            unregister_code(KC_LEFT);
                        } else {
                            unregister_code(KC_HOME);
                        }
                    }
                    break;
                case KC_LEND:
                    if (record->event.pressed) {
                        if (keymap_config.swap_lctl_lgui) {
                            /* CMD-arrow on Mac, but we have CTL and GUI swapped */
                            register_mods(mod_config(MOD_LCTL));
                            register_code(KC_RIGHT);
                        } else {
                            register_code(KC_END);
                        }
                    } else {
                        if (keymap_config.swap_lctl_lgui) {
                            unregister_mods(mod_config(MOD_LCTL));
                            unregister_code(KC_RIGHT);
                        } else {
                            unregister_code(KC_END);
                        }
                    }
                    break;
                case KC_DLINE:
                    if (record->event.pressed) {
                        register_mods(mod_config(MOD_LCTL));
                        register_code(KC_BSPC);
                    } else {
                        unregister_mods(mod_config(MOD_LCTL));
                        unregister_code(KC_BSPC);
                    }
                    break;
                case KC_COPY:
                    if (record->event.pressed) {
                        register_mods(mod_config(MOD_LCTL));
                        register_code(KC_C);
                    } else {
                        unregister_mods(mod_config(MOD_LCTL));
                        unregister_code(KC_C);
                    }
                    return false;
                case KC_PASTE:
                    if (record->event.pressed) {
                        register_mods(mod_config(MOD_LCTL));
                        register_code(KC_V);
                    } else {
                        unregister_mods(mod_config(MOD_LCTL));
                        unregister_code(KC_V);
                    }
                    return false;
                case KC_CUT:
                    if (record->event.pressed) {
                        register_mods(mod_config(MOD_LCTL));
                        register_code(KC_X);
                    } else {
                        unregister_mods(mod_config(MOD_LCTL));
                        unregister_code(KC_X);
                    }
                    return false;
                    break;
                case KC_UNDO:
                    if (record->event.pressed) {
                        register_mods(mod_config(MOD_LCTL));
                        register_code(KC_Z);
                    } else {
                        unregister_mods(mod_config(MOD_LCTL));
                        unregister_code(KC_Z);
                    }
                    return false;

                    /* Smart Backspace Delete */

                case KC_RSFT:
                case KC_LSFT:
                    shift_held = record->event.pressed;
                    held_shift = keycode;
                    break;
                case KC_BSPC_DEL:
                    if (record->event.pressed) {
                        if (shift_held) {
                            unregister_code(held_shift);
                            register_code(KC_DEL);
                        } else {
                            register_code(KC_BSPC);
                        }
                    } else {
                        unregister_code(KC_DEL);
                        unregister_code(KC_BSPC);
                        if (shift_held) {
                            register_code(held_shift);
                        }
                    }
                    return false;

                    /* LAYER */

                case KC_LAYER:
                    if (record->event.pressed) {
                        if (shift_held) {
                            if (record->event.pressed) {
                                if (get_highest_layer(default_layer_state) == _QWERTY) {
                                    set_single_persistent_default_layer(_GAMING);
                                } else if (get_highest_layer(default_layer_state) == _GAMING) {
                                    set_single_persistent_default_layer(_QWERTY);
                                }
                            }
                        } else {
                            layer_on(_LOWER);
                            update_tri_layer(_LOWER, _RAISE, _FUNC);
                        }
                    } else {
                        layer_off(_LOWER);
                        update_tri_layer(_LOWER, _RAISE, _FUNC);
                    }
                    return false;

                    /* KEYBOARD PET STATUS START */

                case KC_LCTL:
                case KC_RCTL:
                    if (record->event.pressed) {
                        isSneaking = true;
                    } else {
                        isSneaking = false;
                    }
                    break;
                case KC_SPC:
                    if (record->event.pressed) {
                        isJumping  = true;
                        showedJump = false;
                    } else {
                        isJumping = false;
                    }
                    break;

                    /* KEYBOARD PET STATUS END */
            }

            return true;
    };