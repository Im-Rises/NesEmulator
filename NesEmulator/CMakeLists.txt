# CMakeList.txt : CMake project for NesEmulator

cmake_minimum_required (VERSION 3.8)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(SRCS main.cpp binaryLib.cpp Nes.cpp Bus.cpp Cpu.cpp Ppu.cpp Apu.cpp Mmu.cpp Joypad.cpp Cartridge.cpp PpuBus.cpp Mapper.cpp Mapper000.cpp)
set(HEADERS binaryLib.h Nes.h Bus.h Cpu.h Ppu.h Apu.h Mmu.h Joypad.h Cartridge.h PpuBus.h Mapper.h Mapper000.h)

add_executable(${PROJECT_NAME} ${SRCS} ${HEADERS})

if(WIN32)
	target_link_libraries(${PROJECT_NAME} ${CMAKE_SOURCE_DIR}/NesEmulator/lib/sfml-graphics.lib)
	target_link_libraries(${PROJECT_NAME} ${CMAKE_SOURCE_DIR}/NesEmulator/lib/sfml-audio.lib)
	target_link_libraries(${PROJECT_NAME} ${CMAKE_SOURCE_DIR}/NesEmulator/lib/sfml-network.lib)
	target_link_libraries(${PROJECT_NAME} ${CMAKE_SOURCE_DIR}/NesEmulator/lib/sfml-system.lib)
	target_link_libraries(${PROJECT_NAME} ${CMAKE_SOURCE_DIR}/NesEmulator/lib/sfml-window.lib)
elseif(UNIX)
	find_package(SFML 2.5 COMPONENTS graphics audio network system window REQUIRED)
	target_link_libraries(${PROJECT_NAME} PRIVATE sfml-graphics sfml-audio sfml-network sfml-system sfml-window)
else()
	message(FATAL_ERROR "OS not configured in CMakeLists.txt")
endif()

include_directories(${CMAKE_SOURCE_DIR}/NesEmulator/include)

set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 14)
set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD_REQUIRED ON)
