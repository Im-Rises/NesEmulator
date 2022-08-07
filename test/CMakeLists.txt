cmake_minimum_required (VERSION 3.8)

# C++ version settings
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(CpuTest "cpuTest.cpp")

add_test (CpuTest CpuTest)
