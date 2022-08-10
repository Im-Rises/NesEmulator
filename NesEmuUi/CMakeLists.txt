cmake_minimum_required (VERSION 3.8)

# C++ version settings
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(SRCS "main.cpp" "NesEmuUi.cpp")
set(HEADERS "NesEmuUi.h")

include_directories("${CMAKE_SOURCE_DIR}/NesEmuUi/glfw/include")

add_subdirectory("glfw")

set(HEADERS_IMGUI "imgui/imconfig.h" "imgui/imgui.h" "imgui/imgui_internal.h" "imgui/imstb_rectpack.h" "imgui/imstb_textedit.h" "imgui/imstb_truetype.h" "imgui/imgui_impl_glfw.h" "imgui/imgui_impl_opengl3.cpp")
set(SRCS_IMGUI "imgui/imgui.cpp" "imgui/imgui_demo.cpp" "imgui/imgui_draw.cpp" "imgui/imgui_tables.cpp" "imgui/imgui_widgets.cpp" "imgui/imgui_impl_glfw.cpp" "imgui/imgui_impl_opengl3.h" "imgui/imgui_impl_opengl3_loader.h")

find_package(OpenGL REQUIRED)

add_executable(NesEmuUi ${SRCS} ${SRCS_IMGUI} ${HEADERS} ${HEADERS_IMGUI})

target_link_libraries(NesEmuUi "glfw")

target_link_libraries(NesEmuUi OpenGL::GL)
