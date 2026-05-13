#pragma once

#include "raygui_c.hpp"

// Utility — raygui.h L773.
namespace ck::gui {

inline int GetTextWidth(const char* text) { return ::GuiGetTextWidth(text); }

}  // namespace ck::gui
