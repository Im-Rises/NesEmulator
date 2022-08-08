cmake_minimum_required (VERSION 3.8)

# C++ version settings
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(SRCS "main.cpp" "NesEmuUi.cpp")
set(HEADERS "NesEmuUi.h")

set(SRCS_IMGUI "imgui/imconfig.h" "imgui/imgui.h" "imgui/imgui_interl.h" "imgui/imgui_rectpack.h" "imgui/imgui_textedit.h" "imgui/imgui_truetype.h" "imgui/impl_glfw.h")
set(HEADERS_IMGUI "imgui/imgui.cpp" "imgui/imgui_draw.cpp" "imgui/imgui_tables.cpp" "imgui/imgui_widgets.cpp" "imgui/impl_glfw.cpp")

add_executable(NesEmuUi ${SRCS} ${SRCS_IMGUI} ${HEADERS} ${HEADERS_IMGUI})

add_test (NesEmuUi NesEmuUi)
