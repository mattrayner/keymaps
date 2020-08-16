/*
  Set any config.h overrides for your specific keymap here.
  See config.h options at https://docs.qmk.fm/#/config_options?id=the-configh-file
*/
#define USB_MAX_POWER_CONSUMPTION 100

#define ORYX_CONFIGURATOR
#define FIRMWARE_VERSION u8"yZylP/PDbRJ"
#define DISABLE_RGB_MATRIX_DIGITAL_RAIN
#define DISABLE_RGB_MATRIX_ALPHAS_MODS
#define DISABLE_RGB_MATRIX_JELLYBEAN_RAINDROPS
#define DISABLE_RGB_MATRIX_RAINDROPS
#define RGB_MATRIX_STARTUP_SPD 60

#undef RGBLIGHT_HUE_STEP
#define RGBLIGHT_HUE_STEP 3

#undef RGB_MATRIX_MODES
#define RGB_MATRIX_MODES 40
