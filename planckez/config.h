#pragma once

#ifdef AUDIO_ENABLE
#define STARTUP_SONG SONG(PLANCK_SOUND)
#endif

#define MIDI_BASIC

#define ENCODER_RESOLUTION 4

/*
  Set any config.h overrides for your specific keymap here.
  See config.h options at https://docs.qmk.fm/#/config_options?id=the-configh-file
*/
#define ORYX_CONFIGURATOR
#undef RGBLIGHT_HUE_STEP
#define RGBLIGHT_HUE_STEP 6

#undef RGBLIGHT_BRI_STEP
#define RGBLIGHT_BRI_STEP 6

#undef MOUSEKEY_WHEEL_MAX_SPEED
#define MOUSEKEY_WHEEL_MAX_SPEED 2

#define FIRMWARE_VERSION u8"BNvj0/9OpZA"
