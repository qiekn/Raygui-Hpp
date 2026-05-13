#pragma once

#include "raygui_c.hpp"

// Global gui state — raygui.h L737-744.
namespace ck::gui {

inline void Enable() { ::GuiEnable(); }
inline void Disable() { ::GuiDisable(); }
inline void Lock() { ::GuiLock(); }
inline void Unlock() { ::GuiUnlock(); }
inline bool IsLocked() { return ::GuiIsLocked(); }
inline void SetAlpha(float alpha) { ::GuiSetAlpha(alpha); }
inline void SetState(int state) { ::GuiSetState(state); }
inline int GetState() { return ::GuiGetState(); }

}  // namespace ck::gui
