include_directories("${CMAKE_SOURCE_DIR}/dependencies")
include_directories("${CMAKE_SOURCE_DIR}/dependencies/binaryLib")
include_directories("${CMAKE_SOURCE_DIR}/dependencies/glad/include")
include_directories("${CMAKE_SOURCE_DIR}/dependencies/glfw/include")

file(GLOB_RECURSE SRCS_IMGUI "${CMAKE_SOURCE_DIR}/dependencies/imgui/*.cpp")
file(GLOB_RECURSE SRCS_GLAD "${CMAKE_SOURCE_DIR}/dependencies/glad/*.c")

file(GLOB_RECURSE SRCS "${CMAKE_SOURCE_DIR}/${PROJECT_NAME}/*.cpp")

set(OpenGL_GL_PREFERENCE GLVND)
find_package(OpenGL REQUIRED)

add_executable(${PROJECT_NAME} main.cpp ${SRCS} ${SRCS_IMGUI} ${SRCS_GLAD})

target_link_libraries(${PROJECT_NAME} OpenGL::GL)

if (WIN32)
    target_link_libraries(${PROJECT_NAME} winmm.lib)
    if (MSVC)
        target_link_libraries(${PROJECT_NAME} "${CMAKE_SOURCE_DIR}/dependencies/glfw/lib-vc2019/glfw3.lib")
    elseif (MINGW)
        target_link_libraries(${PROJECT_NAME} "${CMAKE_SOURCE_DIR}/dependencies/glfw/lib-mingw-w64/libglfw3.a")
    endif ()
elseif (UNIX)
    find_package(glfw3 3.3 REQUIRED)
    target_link_libraries(${PROJECT_NAME} glfw ${CMAKE_DL_LIBS})
else ()
    message(FATAL_ERROR "OS not configured in CMakeLists.txt")
endif ()
