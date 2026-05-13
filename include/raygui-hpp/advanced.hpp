#pragma once

#include "raygui_c.hpp"

// Advanced controls — raygui.h L809-818.
namespace ck::gui {

// -----------------------------------------------------------------------------: list views
inline int ListView(::Rectangle bounds, const char* text, int* scroll_index, int* active) {
  return ::GuiListView(bounds, text, scroll_index, active);
}
inline int ListViewEx(::Rectangle bounds, char** text, int count, int* scroll_index, int* active, int* focus) {
  return ::GuiListViewEx(bounds, text, count, scroll_index, active, focus);
}

// -----------------------------------------------------------------------------: dialog boxes
inline int MessageBox(::Rectangle bounds, const char* title, const char* message, const char* buttons) {
  return ::GuiMessageBox(bounds, title, message, buttons);
}
inline int TextInputBox(::Rectangle bounds, const char* title, const char* message, const char* buttons, char* text,
                        int text_max_size, bool* secret_view_active) {
  return ::GuiTextInputBox(bounds, title, message, buttons, text, text_max_size, secret_view_active);
}

// -----------------------------------------------------------------------------: color controls
inline int ColorPicker(::Rectangle bounds, const char* text, ::Color* color) {
  return ::GuiColorPicker(bounds, text, color);
}
inline int ColorPanel(::Rectangle bounds, const char* text, ::Color* color) {
  return ::GuiColorPanel(bounds, text, color);
}
inline int ColorBarAlpha(::Rectangle bounds, const char* text, float* alpha) {
  return ::GuiColorBarAlpha(bounds, text, alpha);
}
inline int ColorBarHue(::Rectangle bounds, const char* text, float* value) {
  return ::GuiColorBarHue(bounds, text, value);
}
inline int ColorPickerHSV(::Rectangle bounds, const char* text, ::Vector3* color_hsv) {
  return ::GuiColorPickerHSV(bounds, text, color_hsv);
}
inline int ColorPanelHSV(::Rectangle bounds, const char* text, ::Vector3* color_hsv) {
  return ::GuiColorPanelHSV(bounds, text, color_hsv);
}

}  // namespace ck::gui
