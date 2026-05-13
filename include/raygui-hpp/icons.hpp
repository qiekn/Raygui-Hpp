#pragma once

#include "raygui_c.hpp"

// Icons — raygui.h L764-769. Compiled out when raygui.h is built with
// RAYGUI_NO_ICONS; consumers should keep icons enabled to use this header.
namespace ck::gui {

inline const char* IconText(int icon_id, const char* text) { return ::GuiIconText(icon_id, text); }

#if !defined(RAYGUI_NO_ICONS)
inline void SetIconScale(int scale) { ::GuiSetIconScale(scale); }
inline unsigned int* GetIcons() { return ::GuiGetIcons(); }
inline char** LoadIcons(const char* file_name, bool load_icons_name) { return ::GuiLoadIcons(file_name, load_icons_name); }
inline void DrawIcon(int icon_id, int pos_x, int pos_y, int pixel_size, ::Color color) {
  ::GuiDrawIcon(icon_id, pos_x, pos_y, pixel_size, color);
}
#endif

}  // namespace ck::gui
