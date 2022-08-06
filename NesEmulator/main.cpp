/*
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
*/

#include <SFML/Window.hpp>

int main() {
    sf::Window window(sf::VideoMode(800, 600), "My window");

    // run the program as long as the window is open
    while (window.isOpen()) {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event)) {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
        }
    }

    return 0;
}