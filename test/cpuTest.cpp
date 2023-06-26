// #include <iostream>

#include "Nes/MainBus/Cpu.h"
#include "Nes/MainBus/Bus.h"
#include "Nes/Cartridge/Cartridge.h"

using namespace std;

int main() {
    Cpu cpu;
    Cartridge cartridge("test_roms/cpu/nestest.nes");
    Bus bus(&cpu, &cartridge, nullptr);
    cpu.setPc(0xC000);

    while (cpu.getPc() != 0xC66E)
    {
        cpu.clock();
    }

    const int add02 = bus.read(0x02);
    const int add03 = bus.read(0x03);

    return add02 != 0 && add03 != 0;
}
