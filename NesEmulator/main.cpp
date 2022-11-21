#include <SDL.h>
#include <iostream>

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;

int main(int arc, char ** argv) {

    if (SDL_Init( SDL_INIT_VIDEO ) < 0) {
        std::cout << "SDL could not initialize! SDL_Error: " << SDL_GetError() << std::endl;
    } else {

        SDL_CreateWindow(
            "SDL2 Demo",
            SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
            SCREEN_WIDTH, SCREEN_HEIGHT,
            SDL_WINDOW_SHOWN
        );

        SDL_Delay(2000);
    }

    return 0;
}

//#include <iostream>
//
//#include "../NesEmulator/NesEmuUi.h"
//#include <SDL.h>
//
///// <summary>
///// Errors :
///// 1 - Target rom not found
///// 2 - Unknown cartridge (mapper not implemented)
///// </summary>
///// <param name="argc"></param>
///// <param name="argv"></param>
///// <returns></returns>
//
///// <summary>
///// To Do list:
///// - Re-implement mappers
///// </summary>
///// <param name="argc"></param>
///// <param name="argv"></param>
///// <returns></returns>
//
//int main(int argc, char* argv[]) {
//    std::cout << PROJECT_NAME << " " << VER << " by " << AUTHOR << std::endl;
//
//    NesEmuUi nesEmuUi;
//    nesEmuUi.start();
//
//    return 0;
//}
