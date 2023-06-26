include_directories("${CMAKE_SOURCE_DIR}/dependencies/binaryLib")
include_directories("${CMAKE_SOURCE_DIR}/${PROJECT_NAME}")

set(SRCS_TEST "cpuTest.cpp")

file(GLOB_RECURSE SRCS_BINARY_LIB "${CMAKE_SOURCE_DIR}/dependencies/binaryLib/*.cpp")
file(GLOB_RECURSE SRCS "${CMAKE_SOURCE_DIR}/${PROJECT_NAME}/Nes/**/*.cpp")

enable_testing()

foreach (test ${SRCS_TEST})
    get_filename_component(testName ${test} NAME_WE)
    add_executable(${testName} ${test} ${SRCS_HEADERS} ${SRCS_BINARY_LIB})
    add_test(${testName} ${testName})
endforeach ()
