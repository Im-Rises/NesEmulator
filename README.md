# NesEmulator

<p align="center">
      <img src="https://user-images.githubusercontent.com/59691442/183268126-b3d19e66-8f2d-463a-805e-ae6ef7cc6c01.png" alt="cmakeLogo" style="height:60px;"/>
      <img src="https://img.shields.io/badge/C%2B%2B-00599C?style=for-the-badge&logo=c%2B%2B&logoColor=white" alt="cppLogo" style="height:60px;"/>
</p>

## Description

NesEmulator made in C++ in current development for windows, linux and macOS.

You can try the webgl version 🚀🚀 [here](https://im-rises.github.io/nes-emulator-webgl/) 🚀🚀

## Dependencies

- CMake
- C++17
- GLFW
- GLAD
- OpenGL/WebGL
- OpenAL
- ImGui
- Emscripten

## Features

PlaceHolder

## Images

PlaceHolder

## Video

PlaceHolder

## Quickstart

To download the emulator, you can click one of the icons below depending on your operating system, or you can click the
release section of the GitHub page.

Depending on you `operating system` you will need to install some libs, they are installed differently depending on your
system, please follow one of the section below `Windows` or `Linux` or `MacOs`.

### Windows

<a href="https://github.com/Im-Rises/NesEmulator/releases/latest"><img src="https://img.shields.io/badge/Windows-0078D6?style=for-the-badge&logo=windows&logoColor=white" alt="cmakeLogo" style="height:40px;"/></a>

### Linux

<a href="https://github.com/Im-Rises/NesEmulator/releases/latest"><img src="https://img.shields.io/badge/Linux-FCC624?style=for-the-badge&logo=linux&logoColor=black" alt="cmakeLogo" style="height:40px;"/></a>

### MacOs

<a href="https://github.com/Im-Rises/NesEmulator/releases/latest"><img src="https://img.shields.io/badge/mac%20os-000000?style=for-the-badge&logo=apple&logoColor=white" alt="cmakeLogo" style="height:40px;"/></a>

## Emulator controls

Placeholder

## Compilation

```bash
cmake .
```

```bash
cmake --build . --config Release
```

## Run tests

The CPU good behaviour has been tested with the `nestests.nes` test rom that you can find in the test_roms folder.

A CMake test is set up to directly test the program. You can find it in the `test`folder and start it by typing the
command below at the project root folder.

```bash
ctest
```

> **Note**
> You need to compile the whole project before processing any tests.

Test rom passed:

[] nestest.nes
[] nestest.nes
[] nestest.nes
[] nestest.nes
[] nestest.nes

## Github-Actions

[![CMake](https://github.com/Im-Rises/NesEmulator/actions/workflows/cmake.yml/badge.svg?branch=main)](https://github.com/Im-Rises/NesEmulator/actions/workflows/cmake.yml)
[![Cpp Cmake Publish](https://github.com/Im-Rises/NesEmulator/actions/workflows/cpp-cmake-publish.yml/badge.svg?branch=main)](https://github.com/Im-Rises/NesEmulator/actions/workflows/cpp-cmake-publish.yml)
[![cpp-linter](https://github.com/Im-Rises/NesEmulator/actions/workflows/cpp-linter.yml/badge.svg?branch=main)](https://github.com/Im-Rises/NesEmulator/actions/workflows/cpp-linter.yml)
[![flawfinder](https://github.com/Im-Rises/NesEmulator/actions/workflows/flawfinder.yml/badge.svg?branch=main)](https://github.com/Im-Rises/NesEmulator/actions/workflows/flawfinder.yml)
[![CodeQL](https://github.com/Im-Rises/NesEmulator/actions/workflows/codeql.yml/badge.svg?branch=main)](https://github.com/Im-Rises/NesEmulator/actions/workflows/codeql.yml)

The project is set with a set of different scripts:

- CMake : Compile the project
- Cpp Cmake Publish : Compile the project and publish the executable
- CPP-linter : Check for code style issues
- flawfinder : Check for security issues
- CodeQl : Check for security issues

## Documentations

Main documentation:  
<https://wiki.nesdev.org/w/index.php/NES_reference_guide> ❤️  
<https://www.youtube.com/watch?v=nViZg02IMQo&list=PLrOv9FMX8xJHqMvSGB_9G9nZZ_4IgteYf> ❤️  
<https://emudev.de/nes-emulator/overview/>

Cpu:  
<http://archive.6502.org/datasheets/rockwell_r65c00_microprocessors.pdf>  
<http://archive.6502.org/datasheets/rockwell_r650x_r651x.pdf>  
<http://archive.6502.org/datasheets/rockwell_r65c00-21_r65c29.pdf>  
<http://archive.6502.org/datasheets/mos_6501-6505_mpu_preliminary_aug_1975.pdf>  
<http://matthieu.benoit.free.fr/cross/data_sheets/R6502.pdf>

MOS 6502 technical reference:  
<http://archive.6502.org/datasheets/mos_6501-6505_mpu_preliminary_aug_1975.pdf>

Opcodes detail:  
<https://www.masswerk.at/6502/6502_instruction_set.html>  
<https://ltriant.github.io/2019/11/22/nes-emulator.html>

Memory map:  
<https://en.wikibooks.org/wiki/NES_Programming/Memory_Map>

Test roms:  
<https://www.nesdev.org/wiki/Emulator_tests>

## Libraries

CMake:  
<https://cmake.org/>

GLFW:  
<https://www.glfw.org/docs/latest/>

glad:  
<https://glad.dav1d.de/>

OpenGL:  
<https://www.opengl.org/>

WebGL:  
<https://developer.mozilla.org/en-US/docs/Web/API/WebGL_API>

OpenAL:  
<https://www.openal.org/>

Dear ImGui:  
<https://github.com/ocornut/imgui>

Dear ImGui - Memory Editor:  
<https://github.com/ocornut/imgui_club/blob/master/imgui_memory_editor/imgui_memory_editor.h>

Emscripten:  
<https://emscripten.org/>

## Contributors

Quentin MOREL :

- @Im-Rises
- <https://github.com/Im-Rises>

[![GitHub contributors](https://contrib.rocks/image?repo=Im-Rises/NesEmulator)](https://github.com/Im-Rises/NesEmulator/graphs/contributors)
