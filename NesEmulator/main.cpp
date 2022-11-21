#include <iostream>

#include "../NesEmulator/NesEmuUi.h"
#include <SDL.h>

/// <summary>
/// Errors :
/// 1 - Target rom not found
/// 2 - Unknown cartridge (mapper not implemented)
/// </summary>
/// <param name="argc"></param>
/// <param name="argv"></param>
/// <returns></returns>

/// <summary>
/// To Do list:
/// - Re-implement mappers
/// </summary>
/// <param name="argc"></param>
/// <param name="argv"></param>
/// <returns></returns>

int main(int argc, char* argv[]) {
    std::cout << PROJECT_NAME << " " << VER << " by " << AUTHOR << std::endl;

    NesEmuUi nesEmuUi;
    nesEmuUi.start();

    return 0;
}
