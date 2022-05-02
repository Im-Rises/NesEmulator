# CMakeList.txt : CMake project for NesEmulator

cmake_minimum_required (VERSION 3.8)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(SRCS main.cpp binaryLib.cpp Nes.cpp Bus.cpp Cpu.cpp Ppu.cpp Apu.cpp Mmu.cpp Joypad.cpp Cartridge.cpp PpuBus.cpp Mapper.cpp Mapper000.cpp)
set(HEADERS binaryLib.h Nes.h Bus.h Cpu.h Ppu.h Apu.h Mmu.h Joypad.h Cartridge.h PpuBus.h Mapper.h Mapper000.h)

add_executable(${PROJECT_NAME} ${SRCS} ${HEADERS})