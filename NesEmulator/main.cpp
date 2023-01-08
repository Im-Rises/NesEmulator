#include <iostream>

#include "../NesEmulator/NesEmuUi.h"

/// Errors :
/// 1 - Target rom not found
/// 2 - Unknown cartridge (mapper not implemented)

/// To Do list:
/// - Re-implement mappers
/// - Correct CPU bugs in testCpu.cpp

int main(int argc, char* argv[]) {
    std::cout << PROJECT_NAME << " " << PROJECT_VERSION << " by " << AUTHOR << std::endl;

    NesEmuUi nesEmuUi;
    nesEmuUi.start();

    return 0;
}
