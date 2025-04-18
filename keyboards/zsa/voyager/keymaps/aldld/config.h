/*
  Set any config.h overrides for your specific keymap here.
  See config.h options at https://docs.qmk.fm/#/config_options?id=the-configh-file
*/

#define USB_SUSPEND_WAKEUP_DELAY 0
#define SERIAL_NUMBER "bZvgQ/QodNz"
#define LAYER_STATE_8BIT
#define HCS(report)                                         \
    host_consumer_send(record->event.pressed ? report : 0); \
    return false

#define RGB_MATRIX_STARTUP_SPD 60

#define CAPS_WORD_INVERT_ON_SHIFT
#define CAPS_WORD_IDLE_TIMEOUT 5000

/*#define ACHORDION_STREAK*/

#define CHORDAL_HOLD

#define TAPPING_TERM_PER_KEY
#undef TAPPING_TERM
#define TAPPING_TERM 300 // 220
#define PERMISSIVE_HOLD

#define TAP_FLOW_TERM 80

#define SELECT_WORD_OS_MAC
