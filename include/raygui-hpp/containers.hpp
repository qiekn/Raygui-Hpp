#pragma once

#include "raygui_c.hpp"

// Container / separator controls — raygui.h L778-783.
//
// All return int. raygui uses 0 for "no event", non-zero (control-specific)
// for button-press / tab-close / etc. We mirror that.
namespace ck::gui {

inline int WindowBox(::Rectangle bounds, const char* title) { return ::GuiWindowBox(bounds, title); }
inline int GroupBox(::Rectangle bounds, const char* text) { return ::GuiGroupBox(bounds, text); }
inline int Line(::Rectangle bounds, const char* text) { return ::GuiLine(bounds, text); }
inline int Panel(::Rectangle bounds, const char* text) { return ::GuiPanel(bounds, text); }
inline int TabBar(::Rectangle bounds, char** text, int count, int* active) {
  return ::GuiTabBar(bounds, text, count, active);
}
inline int ScrollPanel(::Rectangle bounds, const char* text, ::Rectangle content, ::Vector2* scroll, ::Rectangle* view) {
  return ::GuiScrollPanel(bounds, text, content, scroll, view);
}

}  // namespace ck::gui
