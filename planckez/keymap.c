#include QMK_KEYBOARD_H
#ifdef AUDIO_ENABLE
#include "muse.h"
#endif
#include "eeprom.h"
#include "keymap_german.h"
#include "keymap_nordic.h"
#include "keymap_french.h"
#include "keymap_spanish.h"
#include "keymap_hungarian.h"
#include "keymap_swedish.h"
#include "keymap_br_abnt2.h"
#include "keymap_canadian_multilingual.h"
#include "keymap_german_ch.h"
#include "keymap_jp.h"
#include "keymap_bepo.h"
#include "keymap_italian.h"
#include "keymap_slovenian.h"
#include "keymap_danish.h"
#include "keymap_norwegian.h"
#include "keymap_portuguese.h"

#define KC_MAC_UNDO LGUI(KC_Z)
#define KC_MAC_CUT LGUI(KC_X)
#define KC_MAC_COPY LGUI(KC_C)
#define KC_MAC_PASTE LGUI(KC_V)
#define KC_PC_UNDO LCTL(KC_Z)
#define KC_PC_CUT LCTL(KC_X)
#define KC_PC_COPY LCTL(KC_C)
#define KC_PC_PASTE LCTL(KC_V)
#define ES_LESS_MAC KC_GRAVE
#define ES_GRTR_MAC LSFT(KC_GRAVE)
#define ES_BSLS_MAC ALGR(KC_6)
#define NO_PIPE_ALT KC_GRAVE
#define NO_BSLS_ALT KC_EQUAL
#define LSA_T(kc) MT(MOD_LSFT | MOD_LALT, kc)

enum planck_keycodes {
  RGB_SLD = EZ_SAFE_RANGE,
  ST_MACRO_0,
  ST_MACRO_1,
  ST_MACRO_2,
  ST_MACRO_3,
  ST_MACRO_4,
};

enum planck_layers {
  _BASE,
  _LOWER,
  _RAISE,
  _ADJUST,
  _LAYER4,
};

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT_planck_grid(KC_TAB,KC_Q,KC_W,KC_E,KC_R,KC_T,KC_Y,KC_U,KC_I,KC_O,KC_P,KC_BSPACE,MT(MOD_HYPR, KC_ESCAPE),KC_A,KC_S,KC_D,KC_F,KC_G,KC_H,KC_J,KC_K,KC_L,KC_SCOLON,KC_QUOTE,KC_LSHIFT,KC_Z,KC_X,KC_C,KC_V,KC_B,KC_N,KC_M,KC_COMMA,KC_DOT,KC_SLASH,RSFT_T(KC_ENTER),TT(4),KC_LCTRL,KC_LALT,KC_LGUI,TT(1),KC_SPACE,KC_NO,TT(2),KC_LEFT,KC_DOWN,KC_UP,KC_RIGHT),

  [_LOWER] = LAYOUT_planck_grid(KC_TILD,KC_EXLM,KC_AT,KC_HASH,KC_DLR,KC_PERC,KC_CIRC,KC_AMPR,KC_ASTR,KC_LPRN,KC_RPRN,KC_TRANSPARENT,TO(0),KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_MINUS,KC_EQUAL,KC_LCBR,KC_RCBR,KC_PIPE,KC_TRANSPARENT,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_PLUS,KC_SLASH,KC_LBRACKET,KC_RBRACKET,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_NO,KC_TRANSPARENT,KC_MEDIA_PLAY_PAUSE,KC_AUDIO_VOL_DOWN,KC_AUDIO_VOL_UP,LALT(LCTL(LSFT(KC_P)))),

  [_RAISE] = LAYOUT_planck_grid(KC_GRAVE,KC_1,KC_2,KC_3,KC_4,KC_5,KC_6,KC_7,KC_8,KC_9,KC_0,KC_TRANSPARENT,TO(0),KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_MINUS,KC_EQUAL,KC_LCBR,KC_RCBR,KC_BSLASH,KC_TRANSPARENT,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_PLUS,KC_SLASH,KC_LBRACKET,KC_RBRACKET,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_NO,KC_TRANSPARENT,KC_MEDIA_PLAY_PAUSE,KC_AUDIO_VOL_DOWN,KC_AUDIO_VOL_UP,LALT(LCTL(LSFT(KC_N)))),

  [_ADJUST] = LAYOUT_planck_grid(KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_F14,KC_F15,KC_NO,KC_NO,KC_NO,KC_NO,KC_DELETE,TO(0),KC_NO,AU_ON,AU_OFF,AU_TOG,KC_NO,KC_NO,RGB_TOG,RGB_VAI,RGB_VAD,KC_NO,RESET,KC_NO,KC_NO,MU_ON,MU_OFF,MU_TOG,KC_NO,KC_NO,RGB_MOD,RGB_HUI,RGB_HUD,KC_NO,KC_NO,KC_TRANSPARENT,KC_NO,KC_NO,KC_NO,KC_TRANSPARENT,TT(4),KC_NO,KC_TRANSPARENT,KC_NO,TOGGLE_LAYER_COLOR,KC_NO,LED_LEVEL),

  [_LAYER4] = LAYOUT_planck_grid(KC_NO,KC_MS_BTN1,KC_MS_UP,KC_MS_BTN2,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_TRANSPARENT,TO(0),KC_MS_LEFT,KC_MS_DOWN,KC_MS_RIGHT,KC_NO,KC_NO,KC_NO,KC_UNDS,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_MS_WH_UP,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,LGUI(KC_F),KC_TRANSPARENT,WEBUSB_PAIR,KC_MS_WH_LEFT,KC_MS_WH_DOWN,KC_MS_WH_RIGHT,KC_TRANSPARENT,ST_MACRO_0,KC_NO,KC_TRANSPARENT,ST_MACRO_1,ST_MACRO_2,ST_MACRO_3,ST_MACRO_4),

};

extern bool g_suspend_state;
extern rgb_config_t rgb_matrix_config;

void keyboard_post_init_user(void) {
  rgb_matrix_enable();
}

const uint8_t PROGMEM ledmap[][DRIVER_LED_TOTAL][3] = {
    [0] = { {255,255,255}, {255,255,255}, {27,249,246}, {27,249,246}, {40,251,250}, {40,251,250}, {76,250,244}, {76,250,244}, {144,255,255}, {144,255,255}, {193,255,255}, {193,255,255}, {255,255,255}, {27,249,246}, {27,249,246}, {40,251,250}, {40,251,250}, {76,250,244}, {76,250,244}, {144,255,255}, {144,255,255}, {205,255,255}, {193,255,255}, {221,249,246}, {27,249,246}, {27,249,246}, {40,251,250}, {40,251,250}, {76,250,244}, {76,250,244}, {144,255,255}, {144,255,255}, {193,255,255}, {193,255,255}, {221,249,246}, {221,249,246}, {85,203,158}, {40,251,250}, {40,251,250}, {76,250,244}, {243,222,234}, {144,255,255}, {134,255,213}, {193,255,255}, {221,249,246}, {221,249,246}, {255,255,255} },

    [1] = { {243,222,234}, {243,222,234}, {243,222,234}, {243,222,234}, {243,222,234}, {243,222,234}, {243,222,234}, {243,222,234}, {243,222,234}, {243,222,234}, {243,222,234}, {243,222,234}, {0,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {243,222,234}, {243,222,234}, {243,222,234}, {243,222,234}, {243,222,234}, {243,222,234}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {243,222,234}, {243,222,234}, {243,222,234}, {243,222,234}, {243,222,234}, {85,203,158}, {243,222,234}, {243,222,234}, {243,222,234}, {0,0,255}, {243,222,234}, {134,255,213}, {243,222,234}, {243,222,234}, {243,222,234}, {243,222,234} },

    [2] = { {134,255,213}, {134,255,213}, {134,255,213}, {134,255,213}, {134,255,213}, {134,255,213}, {134,255,213}, {134,255,213}, {134,255,213}, {134,255,213}, {134,255,213}, {134,255,213}, {0,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {134,255,213}, {134,255,213}, {134,255,213}, {134,255,213}, {134,255,213}, {134,255,213}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {134,255,213}, {134,255,213}, {134,255,213}, {134,255,213}, {134,255,213}, {85,203,158}, {134,255,213}, {134,255,213}, {134,255,213}, {243,222,234}, {134,255,213}, {0,0,255}, {134,255,213}, {134,255,213}, {134,255,213}, {134,255,213} },

    [3] = { {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {10,225,255}, {10,225,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {10,225,255}, {0,255,255}, {0,0,0}, {10,225,255}, {10,225,255}, {10,225,255}, {0,0,0}, {0,0,0}, {10,225,255}, {10,225,255}, {10,225,255}, {0,0,0}, {10,225,255}, {0,0,0}, {0,0,0}, {10,225,255}, {10,225,255}, {10,225,255}, {0,0,0}, {0,0,0}, {10,225,255}, {10,225,255}, {10,225,255}, {0,0,0}, {0,0,0}, {85,203,158}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,255}, {85,203,158}, {0,0,255}, {0,0,0}, {10,225,255}, {0,0,0}, {10,225,255} },

    [4] = { {0,0,0}, {85,203,158}, {85,203,158}, {85,203,158}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {85,203,158}, {0,255,255}, {85,203,158}, {85,203,158}, {85,203,158}, {0,0,0}, {0,0,0}, {0,0,0}, {85,203,158}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {85,203,158}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {85,203,158}, {85,203,158}, {85,203,158}, {85,203,158}, {85,203,158}, {85,203,158}, {243,222,234}, {85,203,158}, {134,255,213}, {85,203,158}, {85,203,158}, {85,203,158}, {85,203,158} },

};

void set_layer_color(int layer) {
  for (int i = 0; i < DRIVER_LED_TOTAL; i++) {
    HSV hsv = {
      .h = pgm_read_byte(&ledmap[layer][i][0]),
      .s = pgm_read_byte(&ledmap[layer][i][1]),
      .v = pgm_read_byte(&ledmap[layer][i][2]),
    };
    if (!hsv.h && !hsv.s && !hsv.v) {
        rgb_matrix_set_color( i, 0, 0, 0 );
    } else {
        RGB rgb = hsv_to_rgb( hsv );
        float f = (float)rgb_matrix_config.hsv.v / UINT8_MAX;
        rgb_matrix_set_color( i, f * rgb.r, f * rgb.g, f * rgb.b );
    }
  }
}

void rgb_matrix_indicators_user(void) {
  if (g_suspend_state || keyboard_config.disable_layer_led) { return; }
  switch (biton32(layer_state)) {
    case 0:
      set_layer_color(0);
      break;
    case 1:
      set_layer_color(1);
      break;
    case 2:
      set_layer_color(2);
      break;
    case 3:
      set_layer_color(3);
      break;
    case 4:
      set_layer_color(4);
      break;
   default:
    if (rgb_matrix_get_flags() == LED_FLAG_NONE)
      rgb_matrix_set_color_all(0, 0, 0);
    break;
  }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case ST_MACRO_0:
    if (record->event.pressed) {
      SEND_STRING(SS_LGUI(SS_LSFT(SS_TAP(X_UP))) SS_DELAY(100) SS_TAP(X_SPACE)  SS_DELAY(100) SS_TAP(X_ENTER));

    }
    break;
    case ST_MACRO_1:
    if (record->event.pressed) {
      SEND_STRING(SS_LGUI(SS_LSFT(SS_TAP(X_UP))) SS_DELAY(100) SS_LGUI(SS_TAP(X_LEFT))  SS_DELAY(100) SS_TAP(X_ENTER));

    }
    break;
    case ST_MACRO_2:
    if (record->event.pressed) {
      SEND_STRING(SS_LGUI(SS_LSFT(SS_TAP(X_UP))) SS_DELAY(100) SS_LGUI(SS_TAP(X_DOWN))  SS_DELAY(100) SS_TAP(X_ENTER));

    }
    break;
    case ST_MACRO_3:
    if (record->event.pressed) {
      SEND_STRING(SS_LGUI(SS_LSFT(SS_TAP(X_UP))) SS_DELAY(100) SS_LGUI(SS_TAP(X_UP))  SS_DELAY(100) SS_TAP(X_ENTER));

    }
    break;
    case ST_MACRO_4:
    if (record->event.pressed) {
      SEND_STRING(SS_LGUI(SS_LSFT(SS_TAP(X_UP))) SS_DELAY(100) SS_LGUI(SS_TAP(X_RIGHT))  SS_DELAY(100) SS_TAP(X_ENTER));

    }
    break;
    case RGB_SLD:
      if (record->event.pressed) {
        rgblight_mode(1);
      }
      return false;
  }
  return true;
}

#ifdef AUDIO_ENABLE
bool muse_mode = false;
uint8_t last_muse_note = 0;
uint16_t muse_counter = 0;
uint8_t muse_offset = 70;
uint16_t muse_tempo = 50;

void encoder_update(bool clockwise) {
    if (muse_mode) {
        if (IS_LAYER_ON(_RAISE)) {
            if (clockwise) {
                muse_offset++;
            } else {
                muse_offset--;
            }
        } else {
            if (clockwise) {
                muse_tempo+=1;
            } else {
                muse_tempo-=1;
            }
        }
    } else {
        if (clockwise) {
        #ifdef MOUSEKEY_ENABLE
            register_code(KC_MS_WH_DOWN);
            unregister_code(KC_MS_WH_DOWN);
        #else
            register_code(KC_PGDN);
            unregister_code(KC_PGDN);
        #endif
        } else {
        #ifdef MOUSEKEY_ENABLE
            register_code(KC_MS_WH_UP);
            unregister_code(KC_MS_WH_UP);
        #else
            register_code(KC_PGUP);
            unregister_code(KC_PGUP);
        #endif
        }
    }
}

void matrix_scan_user(void) {
#ifdef AUDIO_ENABLE
    if (muse_mode) {
        if (muse_counter == 0) {
            uint8_t muse_note = muse_offset + SCALE[muse_clock_pulse()];
            if (muse_note != last_muse_note) {
                stop_note(compute_freq_for_midi_note(last_muse_note));
                play_note(compute_freq_for_midi_note(muse_note), 0xF);
                last_muse_note = muse_note;
            }
        }
        muse_counter = (muse_counter + 1) % muse_tempo;
    }
#endif
}

bool music_mask_user(uint16_t keycode) {
    switch (keycode) {
    case RAISE:
    case LOWER:
        return false;
    default:
        return true;
    }
}
#endif

uint32_t layer_state_set_user(uint32_t state) {
    return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}
