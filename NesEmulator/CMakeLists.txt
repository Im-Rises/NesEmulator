#include_directories(${CMAKE_SOURCE_DIR}/dependencies)
include_directories(${CMAKE_SOURCE_DIR}/dependencies/SDL2/include)
include_directories(${CMAKE_SOURCE_DIR}/dependencies/imgui)

file(GLOB_RECURSE SRCS_HEADERS_IMGUI "${CMAKE_SOURCE_DIR}/dependencies/imgui/*.cpp" "${CMAKE_SOURCE_DIR}/dependencies/imgui/*.h")

#file(GLOB_RECURSE SRCS "${CMAKE_SOURCE_DIR}/${PROJECT_NAME}/*.cpp")
#file(GLOB_RECURSE HEADERS "${CMAKE_SOURCE_DIR}/${PROJECT_NAME}/*.h")

#set(SRCS main.cpp NesEmuUi.cpp)
#set(HEADERS NesEmuUi.h)
#add_executable(${PROJECT_NAME} ${SRCS} ${HEADERS} ${SRCS_HEADERS_IMGUI})


#if(WIN32)
#	set(CMAKE_PREFIX_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/dependencies/SDL2/cmake/")
#endif()

#find_package(SDL2 REQUIRED)
find_package(OpenGL REQUIRED)

add_executable(${PROJECT_NAME} main.cpp ${SRCS_HEADERS_IMGUI})
#if (WIN32)
#	target_link_libraries(${PROJECT_NAME} ${SDL2_LIBRARIES} ${OPENGL_LIBRARIES})
#else()
#	target_link_libraries(${PROJECT_NAME} ${SDL2_LIBRARIES} ${OPENGL_LIBRARIES} dl)
#	#target_link_libraries(${PROJECT_NAME} PRIVATE SDL2)
#endif()
target_link_libraries(${PROJECT_NAME} OpenGL::GL)

if(WIN32)
	set(SDL2PATH ${CMAKE_SOURCE_DIR}/dependencies/SDL2/lib/)
	target_link_libraries(${PROJECT_NAME} ${SDL2PATH}x64/SDL2.lib)
	target_link_libraries(${PROJECT_NAME} ${SDL2PATH}x64/SDL2main.lib)
	target_link_libraries(${PROJECT_NAME} ${SDL2PATH}x64/SDL2test.lib)
elseif(UNIX)
	find_package(SDL2 REQUIRED)
	target_link_libraries(${PROJECT_NAME} PUBLIC SDL2)
else()
	message(FATAL_ERROR "OS not configured in CMakeLists.txt")
endif()

#target_link_libraries(${PROJECT_NAME} ${SDL2_LIBRARIES})

