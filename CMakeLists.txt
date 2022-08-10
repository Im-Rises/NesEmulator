cmake_minimum_required(VERSION 3.8)

add_subdirectory("NesEmulator")

add_subdirectory("NesEmuUi")

enable_testing()
add_subdirectory("test")
