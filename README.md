# NesEmulator

## Description

NesEmulator made in C++ in current developpement.
The source is provided with CMake files to compile the emulator for windows, linux and macOs.  
<!-- 
## Images

## Video

## Compilation

## Start the emulator

## Emulator controls 
-->

## SFML

Follow this guide to install SFML on your distribution.
<https://www.sfml-dev.org/tutorials/2.5/>

I compile the program with Visual Studio CMake compiler, so I downloaded the `Visual C++ 15 (2017) - 64-bit` v2.5.1.
If you want to compile the app with Mingw, be sure to download the `GCC 7.3.0 MinGW (SEH) - 64-bit` v2.5.1.

## Github-Actions

[![flawfinder](https://github.com/Im-Rises/NesEmulator/actions/workflows/flawfinder.yml/badge.svg?branch=main)](https://github.com/Im-Rises/NesEmulator/actions/workflows/flawfinder.yml)
[![CMake](https://github.com/Im-Rises/NesEmulator/actions/workflows/cmake.yml/badge.svg?branch=main)](https://github.com/Im-Rises/NesEmulator/actions/workflows/cmake.yml)
[![CodeQL](https://github.com/Im-Rises/NesEmulator/actions/workflows/codeql.yml/badge.svg?branch=main)](https://github.com/Im-Rises/NesEmulator/actions/workflows/codeql.yml)
[![Microsoft C++ Code Analysis](https://github.com/Im-Rises/NesEmulator/actions/workflows/msvc.yml/badge.svg?branch=main)](https://github.com/Im-Rises/NesEmulator/actions/workflows/msvc.yml)

## To do

Updated workflow.

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
