# CMakeList.txt : CMake project for NesEmulator

cmake_minimum_required (VERSION 3.8)

# C++ version settings
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Emulator source and header files
set(SRCS main.cpp binaryLib.cpp Nes.cpp Bus.cpp Cpu.cpp Ppu.cpp Apu.cpp Mmu.cpp Joypad.cpp Cartridge.cpp PpuBus.cpp Mapper.cpp Mapper000.cpp)
set(HEADERS binaryLib.h Nes.h Bus.h Cpu.h Ppu.h Apu.h Mmu.h Joypad.h Cartridge.h PpuBus.h Mapper.h Mapper000.h)

# SFML components and linked libraries definition
set(SFML_COMPONENTS audio network graphics window system)
set(SFML_LINKED_LIBRARIES sfml-audio sfml-network sfml-graphics sfml-window sfml-system)

# SFML include directories
include_directories("${CMAKE_SOURCE_DIR}/NesEmulator/include")

# Windows static linking and Unix (Linux and macos package linking)
if(WIN32)
	set(CMAKE_PREFIX_PATH "${CMAKE_SOURCE_DIR}/NesEmulator/lib/cmake")
	set(SFML_DIR "${CMAKE_SOURCE_DIR}/NesEmulator/lib/cmake/SFML")
	find_package(SFML REQUIRED COMPONENTS ${SFML_COMPONENTS})
elseif(UNIX)
	find_package(SFML 2.5 REQUIRED COMPONENTS ${SFML_COMPONENTS})
endif()

# Executable creation
add_executable(${PROJECT_NAME} ${SRCS} ${HEADERS})

# Linking SFML libraries to project
target_link_libraries(${PROJECT_NAME} ${SFML_LINKED_LIBRARIES})
