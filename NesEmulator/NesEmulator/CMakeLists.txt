# CMakeList.txt : CMake project for NesEmulator

cmake_minimum_required (VERSION 3.8)

# set(SRCS main.c)
# set(HEADERSS main.h)
# add_executable(NesEmulator ${SRCS} ${HEADERS})

add_executable (NesEmulator   "main.cpp" "Nes.cpp" "Nes.h" "Cpu.h" "Cpu.cpp" "Bus.h" "Bus.cpp")

if(WIN32)
	target_link_libraries(NesEmulator ${CMAKE_CURRENT_SOURCE_DIR}/SDL2/lib/x64/SDL2.lib) # Use static lib to compile program
	target_link_libraries(NesEmulator ${CMAKE_CURRENT_SOURCE_DIR}/SDL2/lib/x64/SDL2main.lib)
	target_link_libraries(NesEmulator ${CMAKE_CURRENT_SOURCE_DIR}/SDL2/lib/x64/SDL2test.lib)
elseif(UNIX)
	# for linux, you need to install the SDL2 package; <sudo apt-get install libsdl2-dev>
	find_package(SDL2 REQUIRED) # Find SDL2 package
	target_link_libraries(NesEmulator PUBLIC SDL2.so) # Use SDL2 linux's package
	# target_link_libraries(NesEmulator PUBLIC SDL2main.so) # Use SDL2 linux's package
	# target_link_libraries(NesEmulator PUBLIC SDL2test.so) # Use SDL2 linux's package
else()
	message(FATAL_ERROR "OS not configured in CMakeLists.txt")
endif()

target_compile_features(NesEmulator PUBLIC cxx_nullptr) # Implement nullptr if compiler does not
