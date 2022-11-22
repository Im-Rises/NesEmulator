#include "Nes.h"

Nes* Nes::nesInstance = nullptr;

// Nes::Nes(const std::string romPath) :cartridge(romPath), bus(&cpu, &mmu, &cartridge, &ppu), ppuBus(&ppu, &cartridge)
Nes::Nes(const std::string romPath) : cartridge(romPath), bus(&cpu, &cartridge, &ppu), ppuBus(&ppu, &cartridge) {
    cyclesCounter = 0;
}

Nes* Nes::getInstance(const std::string romPath) {
    if (nesInstance == nullptr)
        nesInstance = new Nes(romPath);

    return nesInstance;
}

void Nes::start() {
    // while (true)
    //{
    //
    // }
}

void Nes::reset() {
    cpu.reset();
    cyclesCounter = 0;
}

void Nes::insertCartridge(const std::string& romPath) {
}

void Nes::clock() {
}
