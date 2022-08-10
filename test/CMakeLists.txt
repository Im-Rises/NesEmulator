cmake_minimum_required (VERSION 3.8)

# C++ version settings
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

project("NesEmuTests")

set(SRCS "cpuTest.cpp" "../NesEmulator/Cpu.cpp" "../NesEmulator/Bus.cpp" "../NesEmulator/Cartridge.cpp" "../NesEmulator/binaryLib.cpp" "../NesEmulator/Mmu.cpp" "../NesEmulator/PpuBus.cpp" "../NesEmulator/Ppu.cpp" "../NesEmulator/Mapper.cpp" "../NesEmulator/Mapper000.cpp" )
set(HEADERS "../NesEmulator/Cpu.h" "../NesEmulator/Bus.h" "../NesEmulator/Cartridge.h" "../NesEmulator/binaryLib.h" "../NesEmulator/Mmu.h" "../NesEmulator/PpuBus.h" "../NesEmulator/Ppu.h" "../NesEmulator/Mapper.h" "../NesEmulator/Mapper000.h" )

add_executable(${PROJECT_NAME} ${SRCS} ${HEADERS})

add_test(${PROJECT_NAME} ${PROJECT_NAME})
