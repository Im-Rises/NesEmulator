include_directories("${CMAKE_SOURCE_DIR}/dependencies/binaryLib")

set(SRCS_TEST "cpuTest.cpp")

file(GLOB_RECURSE SRCS_BINARY_LIB "${CMAKE_SOURCE_DIR}/dependencies/binaryLib/*.h" "${CMAKE_SOURCE_DIR}/dependencies/binaryLib/*.cpp")
file(GLOB_RECURSE SRCS_HEADERS "${CMAKE_SOURCE_DIR}/${PROJECT_NAME}/Nes/**/*.h" "${CMAKE_SOURCE_DIR}/${PROJECT_NAME}/Nes/**/*.cpp")

#set(SRCS "${CMAKE_SOURCE_DIR}/${PROJECT_NAME}/Nes/Cpu.cpp"
#        "${CMAKE_SOURCE_DIR}/${PROJECT_NAME}/Nes/Bus.cpp"
#        "${CMAKE_SOURCE_DIR}/${PROJECT_NAME}/Nes/Cartridge.cpp"
#        "${CMAKE_SOURCE_DIR}/${PROJECT_NAME}/binaryLib/binaryLib.cpp"
#        "${CMAKE_SOURCE_DIR}/${PROJECT_NAME}/Nes/Mmu.cpp"
#        "${CMAKE_SOURCE_DIR}/${PROJECT_NAME}/Nes/PpuBus.cpp"
#        "${CMAKE_SOURCE_DIR}/${PROJECT_NAME}/Nes/Ppu.cpp"
#        "${CMAKE_SOURCE_DIR}/${PROJECT_NAME}/Nes/Mapper.cpp"
#        "${CMAKE_SOURCE_DIR}/${PROJECT_NAME}/Nes/Mapper000.cpp")

enable_testing()

foreach (test ${SRCS_TEST})
    get_filename_component(testName ${test} NAME_WE)
    add_executable(${testName} ${test} ${SRCS_HEADERS} ${SRCS_BINARY_LIB})
    add_test(${testName} ${testName})
endforeach ()

