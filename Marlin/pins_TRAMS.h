#include "pins_RAMPS.h"

// DIR/STEP are connected from corresponding ENDSTOP header to to AUX2.

#define X_DIR_PIN          42 // D42
#define X_STEP_PIN         65 // A11
#define X_ENABLE_PIN       38
#define X_CS_PIN           46

#define Y_DIR_PIN          44 // D44
#define Y_STEP_PIN         66 // A12
#define Y_ENABLE_PIN       62 // A8
#define Y_CS_PIN           49

#define Z_DIR_PIN          59 // A5
#define Z_STEP_PIN         64 // A10
#define Z_ENABLE_PIN       56 // A2
#define Z_CS_PIN           48

#define E0_DIR_PIN         63 // A9
#define E0_STEP_PIN        40 // D40
#define E0_ENABLE_PIN      24
#define E0_CS_PIN          47

// ENDSTOP live on servo connector
#define X_MIN_PIN          4 
#define Y_MIN_PIN          5 
#define Z_MIN_PIN          6 

#if ENABLED(SENSORLESS_HOMING)
#define X_MIN_PIN          2 
#define Y_MIN_PIN          3 
#endif

// Fan is always on along w/ extruder.
// Controlled via E0_AUTO_FAN_PIN 
#undef FAN_PIN

// We reuse servo pins for other purposes.
#undef NUM_SERVOS
