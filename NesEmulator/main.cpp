#include <iostream>

#include "Nes.h"

/// <summary>
/// Errors :
/// 1 - Target rom not found
/// 2 - Unknown cartridge (mapper not implemented)
/// </summary>
/// <param name="argc"></param>
/// <param name="argv"></param>
/// <returns></returns>

int main(int argc, char *argv[]) {
    std::cout << PROJECT_NAME << " " << VER << " by " << AUTHOR << std::endl;

    if (argc > 1) {
        std::string romPath = argv[1];
        Nes *nes = Nes::getInstance(romPath);
    }

    return 0;
}
