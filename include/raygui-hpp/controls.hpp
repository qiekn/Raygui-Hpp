#pragma once

#include "raygui_c.hpp"

// Basic controls — raygui.h L786-806.
//
// raygui v5.0 returns int for every control; we keep that for state-bearing
// controls (Toggle, Slider, …) and convert click-style controls (Button,
// LabelButton) to bool so `if (ck::gui::Button(…))` reads naturally.
namespace ck::gui {

// -----------------------------------------------------------------------------: labels & buttons
inline int Label(::Rectangle bounds, const char* text) { return ::GuiLabel(bounds, text); }
inline bool Button(::Rectangle bounds, const char* text) { return ::GuiButton(bounds, text) != 0; }
inline bool LabelButton(::Rectangle bounds, const char* text) { return ::GuiLabelButton(bounds, text) != 0; }

// -----------------------------------------------------------------------------: toggles & checks
inline int Toggle(::Rectangle bounds, const char* text, bool* active) { return ::GuiToggle(bounds, text, active); }
inline int ToggleGroup(::Rectangle bounds, const char* text, int* active) {
  return ::GuiToggleGroup(bounds, text, active);
}
inline int ToggleSlider(::Rectangle bounds, const char* text, int* active) {
  return ::GuiToggleSlider(bounds, text, active);
}
inline int CheckBox(::Rectangle bounds, const char* text, bool* checked) {
  return ::GuiCheckBox(bounds, text, checked);
}
inline int ComboBox(::Rectangle bounds, const char* text, int* active) { return ::GuiComboBox(bounds, text, active); }

// -----------------------------------------------------------------------------: dropdown / spinner / value / text
inline int DropdownBox(::Rectangle bounds, const char* text, int* active, bool edit_mode) {
  return ::GuiDropdownBox(bounds, text, active, edit_mode);
}
inline int Spinner(::Rectangle bounds, const char* text, int* value, int min_value, int max_value, bool edit_mode) {
  return ::GuiSpinner(bounds, text, value, min_value, max_value, edit_mode);
}
inline int ValueBox(::Rectangle bounds, const char* text, int* value, int min_value, int max_value, bool edit_mode) {
  return ::GuiValueBox(bounds, text, value, min_value, max_value, edit_mode);
}
inline int ValueBoxFloat(::Rectangle bounds, const char* text, char* text_value, float* value, bool edit_mode) {
  return ::GuiValueBoxFloat(bounds, text, text_value, value, edit_mode);
}
inline int TextBox(::Rectangle bounds, char* text, int text_size, bool edit_mode) {
  return ::GuiTextBox(bounds, text, text_size, edit_mode);
}

// -----------------------------------------------------------------------------: sliders & bars
inline int Slider(::Rectangle bounds, const char* text_left, const char* text_right, float* value, float min_value,
                  float max_value) {
  return ::GuiSlider(bounds, text_left, text_right, value, min_value, max_value);
}
inline int SliderBar(::Rectangle bounds, const char* text_left, const char* text_right, float* value, float min_value,
                     float max_value) {
  return ::GuiSliderBar(bounds, text_left, text_right, value, min_value, max_value);
}
inline int ProgressBar(::Rectangle bounds, const char* text_left, const char* text_right, float* value, float min_value,
                       float max_value) {
  return ::GuiProgressBar(bounds, text_left, text_right, value, min_value, max_value);
}
inline int StatusBar(::Rectangle bounds, const char* text) { return ::GuiStatusBar(bounds, text); }
inline int DummyRec(::Rectangle bounds, const char* text) { return ::GuiDummyRec(bounds, text); }
inline int Grid(::Rectangle bounds, const char* text, float spacing, int subdivs, ::Vector2* mouse_cell) {
  return ::GuiGrid(bounds, text, spacing, subdivs, mouse_cell);
}

}  // namespace ck::gui
