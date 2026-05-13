#pragma once

#include "raygui_c.hpp"

// Tooltip management — raygui.h L759-761.
namespace ck::gui {

inline void EnableTooltip() { ::GuiEnableTooltip(); }
inline void DisableTooltip() { ::GuiDisableTooltip(); }
inline void SetTooltip(const char* tooltip) { ::GuiSetTooltip(tooltip); }

}  // namespace ck::gui
