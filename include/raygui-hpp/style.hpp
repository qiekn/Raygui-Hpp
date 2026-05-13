#pragma once

#include "raygui_c.hpp"

// Style get/set + style file loading — raygui.h L751-756.
//
// `control` and `property` are int slots referring to the GuiControl /
// GuiControlProperty / GuiDefaultProperty / ... enums. raygui keeps them as
// int so generic style code can treat them uniformly.
namespace ck::gui {

inline void SetStyle(int control, int property, int value) { ::GuiSetStyle(control, property, value); }
inline int GetStyle(int control, int property) { return ::GuiGetStyle(control, property); }

inline void LoadStyle(const char* file_name) { ::GuiLoadStyle(file_name); }
inline void LoadStyleDefault() { ::GuiLoadStyleDefault(); }

// Scrollbar-side constants — raygui.h L720-721. Defined as macros there, but
// we expose them as constexpr so `import raygui;` users can reach them by
// `ck::gui::ScrollbarLeftSide` (or via `using namespace`) without dragging
// raygui.h's preprocessor scope into the TU.
inline constexpr int kScrollbarLeftSide = 0;
inline constexpr int kScrollbarRightSide = 1;

}  // namespace ck::gui
