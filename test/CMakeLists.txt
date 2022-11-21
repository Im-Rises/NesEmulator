#cmake_minimum_required (VERSION 3.8)
#
#set(CMAKE_CXX_STANDARD 14)
#set(CMAKE_CXX_STANDARD_REQUIRED ON)
#set(CMAKE_CXX_EXTENSIONS OFF)
#
#project("NesEmuTests")
#
#set(SRCS "cpuTest.cpp" "Nes/Cpu.cpp" "Nes/Bus.cpp" "Nes/Cartridge.cpp" "../NesEmulator/binaryLib/binaryLib.cpp" "Nes/Mmu.cpp" "Nes/PpuBus.cpp" "Nes/Ppu.cpp" "Nes/Mapper.cpp" "Nes/Mapper000.cpp" )
#set(HEADERS "Nes/Cpu.h" "Nes/Bus.h" "Nes/Cartridge.h" "../NesEmulator/binaryLib/binaryLib.h" "Nes/Mmu.h" "Nes/PpuBus.h" "Nes/Ppu.h" "Nes/Mapper.h" "Nes/Mapper000.h" )
#
#enable_testing()
#
#add_executable(${PROJECT_NAME} ${SRCS} ${HEADERS})
#
#add_test(${PROJECT_NAME} ${PROJECT_NAME})
