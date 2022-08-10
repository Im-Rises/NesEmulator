cmake_minimum_required(VERSION 3.8)

# Emulator
add_subdirectory("NesEmulator")

# Emulator UI
add_subdirectory("NesEmuUi")

# Unit tests
enable_testing()
add_subdirectory("test")
