module;

// GMF: bring in the curated wrapper headers. Each using-declaration below
// references a symbol defined here (either a raygui POD/enum type or one of
// the ck::gui:: wrapper functions). Without these includes the module
// purview cannot see them.
#include "raygui-hpp/raygui.hpp"

export module raygui;

// clang-tidy's misc-unused-using-decls misreads module re-exports as
// self-imports (e.g. `ck::gui::Button` brought into `ck::gui::`). Silence.
// NOLINTBEGIN(misc-unused-using-decls)

// -----------------------------------------------------------------------------: POD types (global ::)
export {
using ::GuiStyleProp;
}

// -----------------------------------------------------------------------------: enums and their enumerators (global ::)
// raygui's enums are plain `typedef enum { ... } Name;` — the enumerators live
// at global scope. `using enum` re-exports every enumerator so callers can
// write `STATE_NORMAL` / `BORDER_COLOR_NORMAL` / `LABEL` directly after
// `import raygui;`, matching raygui's idiomatic C usage.
export {
using ::GuiState;
using enum ::GuiState;

using ::GuiTextAlignment;
using enum ::GuiTextAlignment;

using ::GuiTextAlignmentVertical;
using enum ::GuiTextAlignmentVertical;

using ::GuiTextWrapMode;
using enum ::GuiTextWrapMode;

using ::GuiControl;
using enum ::GuiControl;

using ::GuiControlProperty;
using enum ::GuiControlProperty;

using ::GuiDefaultProperty;
using enum ::GuiDefaultProperty;

using ::GuiToggleProperty;
using enum ::GuiToggleProperty;

using ::GuiSliderProperty;
using enum ::GuiSliderProperty;

using ::GuiProgressBarProperty;
using enum ::GuiProgressBarProperty;

using ::GuiScrollBarProperty;
using enum ::GuiScrollBarProperty;

using ::GuiCheckBoxProperty;
using enum ::GuiCheckBoxProperty;

using ::GuiComboBoxProperty;
using enum ::GuiComboBoxProperty;

using ::GuiDropdownBoxProperty;
using enum ::GuiDropdownBoxProperty;

using ::GuiTextBoxProperty;
using enum ::GuiTextBoxProperty;

using ::GuiValueBoxProperty;
using enum ::GuiValueBoxProperty;

using ::GuiListViewProperty;
using enum ::GuiListViewProperty;

using ::GuiColorPickerProperty;
using enum ::GuiColorPickerProperty;

#if !defined(RAYGUI_NO_ICONS) && !defined(RAYGUI_CUSTOM_ICONS)
using ::GuiIconName;
using enum ::GuiIconName;
#endif
}

// -----------------------------------------------------------------------------: ck::gui:: wrapper functions
export namespace ck::gui {
// state.hpp
using ck::gui::Disable;
using ck::gui::Enable;
using ck::gui::GetState;
using ck::gui::IsLocked;
using ck::gui::Lock;
using ck::gui::SetAlpha;
using ck::gui::SetState;
using ck::gui::Unlock;

// font.hpp
using ck::gui::GetFont;
using ck::gui::SetFont;

// style.hpp
using ck::gui::GetStyle;
using ck::gui::kScrollbarLeftSide;
using ck::gui::kScrollbarRightSide;
using ck::gui::LoadStyle;
using ck::gui::LoadStyleDefault;
using ck::gui::SetStyle;

// tooltip.hpp
using ck::gui::DisableTooltip;
using ck::gui::EnableTooltip;
using ck::gui::SetTooltip;

// icons.hpp
using ck::gui::IconText;
#if !defined(RAYGUI_NO_ICONS)
using ck::gui::DrawIcon;
using ck::gui::GetIcons;
using ck::gui::LoadIcons;
using ck::gui::SetIconScale;
#endif

// text.hpp
using ck::gui::GetTextWidth;

// containers.hpp
using ck::gui::GroupBox;
using ck::gui::Line;
using ck::gui::Panel;
using ck::gui::ScrollPanel;
using ck::gui::TabBar;
using ck::gui::WindowBox;

// controls.hpp
using ck::gui::Button;
using ck::gui::CheckBox;
using ck::gui::ComboBox;
using ck::gui::DropdownBox;
using ck::gui::DummyRec;
using ck::gui::Grid;
using ck::gui::Label;
using ck::gui::LabelButton;
using ck::gui::ProgressBar;
using ck::gui::Slider;
using ck::gui::SliderBar;
using ck::gui::Spinner;
using ck::gui::StatusBar;
using ck::gui::TextBox;
using ck::gui::Toggle;
using ck::gui::ToggleGroup;
using ck::gui::ToggleSlider;
using ck::gui::ValueBox;
using ck::gui::ValueBoxFloat;

// advanced.hpp
using ck::gui::ColorBarAlpha;
using ck::gui::ColorBarHue;
using ck::gui::ColorPanel;
using ck::gui::ColorPanelHSV;
using ck::gui::ColorPicker;
using ck::gui::ColorPickerHSV;
using ck::gui::ListView;
using ck::gui::ListViewEx;
using ck::gui::MessageBox;
using ck::gui::TextInputBox;
}  // namespace ck::gui

// NOLINTEND(misc-unused-using-decls)
