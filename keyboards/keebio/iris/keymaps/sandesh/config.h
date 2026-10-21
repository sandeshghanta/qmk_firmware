#pragma once

// Board default is 120/255; only a few keys are lit at once with a reactive
// effect, so a higher ceiling stays well within USB power.
#undef RGB_MATRIX_MAXIMUM_BRIGHTNESS
#define RGB_MATRIX_MAXIMUM_BRIGHTNESS 200
