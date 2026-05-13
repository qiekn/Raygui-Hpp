#pragma once

// Internal forwarder for raygui.h. Public wrapper headers under raygui-hpp/
// pull this in instead of touching raygui.h directly.
//
// Two responsibilities, matching what raylib-hpp does for raylib.h:
//   1. Wrap the include in extern "C". raygui.h already wraps its function
//      declarations, but we keep it consistent and harmless.
//   2. raygui.h re-includes raylib.h, which redefines the colour macros
//      (RED / WHITE / ...). Undef them so they cannot leak into a TU that
//      also uses `ck::RED` etc. Mirrors raylib-hpp/raylib_c.hpp.

#ifdef __cplusplus
extern "C" {
#endif

#include "raygui.h"  // IWYU pragma: export

#undef LIGHTGRAY
#undef GRAY
#undef DARKGRAY
#undef YELLOW
#undef GOLD
#undef ORANGE
#undef PINK
#undef RED
#undef MAROON
#undef GREEN
#undef LIME
#undef DARKGREEN
#undef SKYBLUE
#undef BLUE
#undef DARKBLUE
#undef PURPLE
#undef VIOLET
#undef DARKPURPLE
#undef BEIGE
#undef BROWN
#undef DARKBROWN
#undef WHITE
#undef BLACK
#undef BLANK
#undef MAGENTA
#undef RAYWHITE

#ifdef __cplusplus
}
#endif
