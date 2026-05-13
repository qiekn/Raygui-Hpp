#pragma once

#include "raygui_c.hpp"

// Font set/get — raygui.h L747-748. Takes the raylib ::Font value type.
namespace ck::gui {

inline void SetFont(::Font font) { ::GuiSetFont(font); }
inline ::Font GetFont() { return ::GuiGetFont(); }

}  // namespace ck::gui
