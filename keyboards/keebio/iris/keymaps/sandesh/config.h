#pragma once

// Board default is 120/255; only a few keys are lit at once with a reactive
// effect, so a higher ceiling stays well within USB power.
#undef RGB_MATRIX_MAXIMUM_BRIGHTNESS
#if defined(KEYBOARD_keebio_iris_rev7)
// Rev. 7 LEDs read much dimmer through the keycaps, so run them at full.
#    define RGB_MATRIX_MAXIMUM_BRIGHTNESS 255
#else
#    define RGB_MATRIX_MAXIMUM_BRIGHTNESS 200
#endif
