cmake_minimum_required(VERSION 3.28)
project(raygui_hpp VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# raygui.h needs raylib.h and raylib symbols. We rely on the consumer
# (parent project) to provide a `raylib` (or `raylib_hpp`) target.
if(NOT TARGET raylib)
  message(FATAL_ERROR
    "raygui_hpp expects a `raylib` target to be defined by the parent project. "
    "Add `add_subdirectory(deps/Raylib-Hpp)` (which vendors raylib) before this.")
endif()

# raygui.h is the upstream single-header; we treat it like Raylib-Hpp treats
# raylib — kept out of the wrapper repo, must be present locally. The build
# fails configure if it's missing rather than failing later with a cryptic
# preprocessor error.
if(NOT EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/raygui.h")
  message(FATAL_ERROR
    "raygui.h missing under ${CMAKE_CURRENT_SOURCE_DIR}. "
    "Download raygui v5 from https://github.com/raysan5/raygui/blob/master/src/raygui.h "
    "and place it at deps/Raygui-Hpp/raygui.h.")
endif()

# --- Header-only wrapper (raygui-hpp/*.hpp) ---
# The include dir exposes both `raygui-hpp/*.hpp` (under include/) and
# `raygui.h` itself (under the parent dir). Consumers should reach raygui via
# the wrapper headers or via `import raygui;`, not by including raygui.h.
add_library(raygui_hpp INTERFACE)
target_include_directories(raygui_hpp INTERFACE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
    $<INSTALL_INTERFACE:include>
)
target_link_libraries(raygui_hpp INTERFACE raylib)

# --- raygui implementation TU (C, compiled once) ---
# raygui.h is single-header with implementation gated by RAYGUI_IMPLEMENTATION.
# Compiling as C avoids extern "C" / C++ linkage mismatch between the
# `extern "C"` prototypes in raygui.h and the unwrapped function definitions
# in its impl block.
add_library(raygui_impl STATIC src/raygui_impl.c)
target_include_directories(raygui_impl PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}
)
target_link_libraries(raygui_impl PUBLIC raylib)
set_target_properties(raygui_impl PROPERTIES
    C_STANDARD 11
    CXX_SCAN_FOR_MODULES OFF
)
target_link_libraries(raygui_hpp INTERFACE raygui_impl)

# --- C++23 module (`import raygui;`) ---
option(BUILD_RAYGUI_HPP_MODULES "Build raygui-hpp C++23 module" ON)
if(BUILD_RAYGUI_HPP_MODULES)
    add_library(raygui_hpp_modules)
    target_sources(raygui_hpp_modules
        PUBLIC
            FILE_SET CXX_MODULES FILES src/raygui.cppm
    )
    target_link_libraries(raygui_hpp_modules PUBLIC raygui_hpp)
    target_compile_features(raygui_hpp_modules PUBLIC cxx_std_23)
endif()
