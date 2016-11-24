#include "planck.h"
#include "action_layer.h"
#ifdef AUDIO_ENABLE
#include "audio.h"
#endif
#include "eeconfig.h"

extern keymap_config_t keymap_config;

// Based on the Callum layout.

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _BASE 0
#define _LANG 1
#define _MOVE 2
#define _SYMB 3
#define _FUNC 4

// Shortcut for the layer matrixes
#define _L _LANG

enum planck_keycodes {
  BASE = SAFE_RANGE,
  MOVE,
  SYMB,
  FUNC,
  LANG
};

// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* BASE
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | RCtr |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |Enter |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   "  |   /  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Func | RAlt | LAlt | GUI  | Symb |    Space    | Move | GUI  | RAlt | LAlt |   -  |
 * `-----------------------------------------------------------------------------------'
 */
[_BASE] = {
  {KC_TAB,     KC_Q,    KC_W,    KC_E,  KC_R,   KC_T,   KC_Y,  KC_U,    KC_I,    KC_O,    KC_P, KC_BSPC},
  {KC_RCTL,    KC_A,    KC_S,    KC_D,  KC_F,   KC_G,   KC_H,  KC_J,    KC_K,    KC_L, KC_SCLN, KC_ENT },
  {KC_LSFT,    KC_Z,    KC_X,    KC_C,  KC_V,   KC_B,   KC_N,  KC_M, KC_COMM,  KC_DOT, KC_QUOT, KC_SLSH},
  {FUNC,    KC_RALT, KC_LALT, KC_LGUI,  SYMB, KC_SPC, KC_SPC,  MOVE, KC_RGUI, KC_RALT, KC_LALT, KC_MINS}
},

/* LANG:SWE
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | RCtr |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |  [Å  |Enter |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |  ;Ö  |  "Ä  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Func | RAlt | LAlt | GUI  | Symb |    Space    | Move | GUI  | RAlt | LAlt |   /  |
 * `-----------------------------------------------------------------------------------'
 */
[_LANG] = {
  {KC_TAB,     KC_Q,    KC_W,    KC_E,  KC_R,   KC_T,   KC_Y,  KC_U,    KC_I,    KC_O,    KC_P, KC_BSPC},
  {KC_RCTL,    KC_A,    KC_S,    KC_D,  KC_F,   KC_G,   KC_H,  KC_J,    KC_K,    KC_L, KC_LBRC,  KC_ENT},
  {KC_LSFT,    KC_Z,    KC_X,    KC_C,  KC_V,   KC_B,   KC_N,  KC_M, KC_COMM,  KC_DOT, KC_SCLN, KC_QUOT},
  {FUNC,    KC_RALT, KC_LALT, KC_LGUI,  SYMB, KC_SPC, KC_SPC,  MOVE, KC_RGUI, KC_RALT, KC_LALT, KC_SLSH}
},

/* MOVE
 * ,-----------------------------------------------------------------------------------.
 * | Esc  |Pg Up | Home |  Up  | End  |      |      | Home |  Up  | End  |Pg Up | Esc  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Del  |Pg Dn | Left | Down |Right |      |      | Left | Down |Right |Pg Dn | Del  |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |Pg Up |Pg Dn |      |      |Pg Dn |Pg Up |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_MOVE] = {
  {KC_ESC,  KC_PGUP, KC_HOME,   KC_UP,  KC_END, _______, _______, KC_HOME,   KC_UP,  KC_END, KC_PGUP,  KC_ESC},
  {KC_DEL,  KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN,  KC_DEL},
  {_______, _______, _______, KC_PGUP, KC_PGDN, _______, _______, KC_PGDN, KC_PGUP, _______, _______, _______},
  {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______}
},

/* SYMB
 * ,-----------------------------------------------------------------------------------.
 * |  Esc |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Esc  |
 * |-----------------------------------------------------------------------------------.
 * |  Del |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |   ~  |   |  |   +  |   [  |   ]  |  {   |   }  |   =  |   \  |   `  |   <  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_SYMB] = {
  {KC_ESC,     KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,  KC_ESC},
  {KC_DEL,  KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN,  KC_DEL},
  {_______, KC_TILD, KC_PIPE, KC_PLUS, KC_LBRC, KC_RBRC, KC_LCBR, KC_RCBR,  KC_EQL, KC_BSLS,  KC_GRV, KC_NUBS},
  {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______}
},

/* FUNC
 * ,-----------------------------------------------------------------------------------.
 * | F12  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  | F10  | F11  |
 * |-----------------------------------------------------------------------------------.
 * | LANG | Prev | Play | Next | BL+  |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | LANG | Mute | Vol- | Vol+ | BL-  | LANG |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |Reset |
 * `-----------------------------------------------------------------------------------'
 */
[_FUNC] = {
  { KC_F12,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11},
  { TG(_L), KC_MPRV, KC_MPLY, KC_MNXT, KC_PAUS, _______, _______, _______, _______, _______, _______, _______},
  {   LANG, KC_MUTE, KC_VOLD, KC_VOLU, KC_SLCK,    LANG, _______, _______, _______, _______, _______, _______},
  {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,   RESET}
}

};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case MOVE:
      if (record->event.pressed) {
        layer_on(_MOVE);
        update_tri_layer(_MOVE, _SYMB, _FUNC);
      } else {
        layer_off(_MOVE);
        update_tri_layer(_MOVE, _SYMB, _FUNC);
      }
      return false;
      break;
    case SYMB:
      if (record->event.pressed) {
        layer_on(_SYMB);
        update_tri_layer(_MOVE, _SYMB, _FUNC);
      } else {
        layer_off(_SYMB);
        update_tri_layer(_MOVE, _SYMB, _FUNC);
      }
      return false;
      break;
    case FUNC:
      if (record->event.pressed) {
        layer_on(_FUNC);
      } else {
        layer_off(_FUNC);
      }
      return false;
      break;
    case LANG:
      if (record->event.pressed) {
	register_code(KC_LGUI);
	register_code(KC_SPC);
	unregister_code(KC_SPC);
	unregister_code(KC_LGUI);
	layer_invert(_LANG);
      }
      return false;
      break;
  }
  return true;
}