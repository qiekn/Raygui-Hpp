// Sole compilation unit holding raygui's implementation. Compiled as C so the
// function definitions match the `extern "C"` declarations in raygui.h
// without any C++ linkage drama. raylib.h is pulled in transitively by
// raygui.h itself.
#define RAYGUI_IMPLEMENTATION
#include "raygui.h"
