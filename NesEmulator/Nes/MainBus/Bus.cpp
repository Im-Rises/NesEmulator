#include "Bus.h"

#include "Cpu.h"
#include "Mmu.h"
#include "../Cartridge/Cartridge.h"
#include "../PpuBus/Ppu.h"

/// <summary>
/// https://en.wikibooks.org/wiki/NES_Programming/Memory_Map
/// </summary>
/// <param name="cpu"></param>
/// <param name="mmu"></param>
/// <param name="cartridge"></param>
/// <param name="ppu"></param>

// Bus::Bus(Cpu* cpu, Mmu* mmu, Cartridge* cartridge, Ppu* ppu)
Bus::Bus(Cpu* cpu, Cartridge* cartridge, Ppu* ppu) : memory{} // Init all array to 0
{
    // Only the CPU can read and write to the main bus
    this->cpu = cpu;
    this->cpu->connectToBus(this);

    // this->mmu = mmu;
    // this->mmu->connectToBus(this);
    // for (uint8& i : memory)
    //	i = 0;

    this->cartridge = cartridge;
    // this->cartridge->connectToBus(this);

    this->ppu = ppu;
    // this->ppu->connectToBus(this);
}

/// <summary>
/// Memory map:
/// https://wiki.nesdev.org/w/index.php/CPU_memory_map
/// </summary>
/// <param name="address"></param>
/// <returns></returns>

uint8 Bus::read(const uint16& address) const {
    if (address < 0x2000) // Read ram (Mmu)
    {
        // return mmu->read(address);
        return memory[address % 0x0800];
    }
    else if (0x2000 <= address && address < 0x4000) // Read ppu registers
    {
        return ppu->readPpuRegister(address);
    }
    else if (0x4000 <= address && address < 0x4018) // APU and I/O
    {
    }
    else if (0x4018 <= address && address < 0x4020) // UNUSED ???
    {
    }
    else if (0x4020 <= address && address < 0x10000) // Read cartridge
    {
        return cartridge->readMainBus(address);
    }
    else
    {
        return 0; // Error unknown address
    }
}

void Bus::write(const uint16& address, const uint8& data) {
    if (0 <= address && address < 0x2000) // Write to ram (Mmu)
    {
        // mmu->write(address, data);
        memory[address % 0x0800] = data;
    }
    else if (0x2000 <= address && address < 0x4000) // Write to ppu registers
    {
        ppu->writePpuRegister(address, data);
    }
    else if (0x4000 <= address && address < 0x4018) // APU and I/O
    {
    }
    else if (0x4018 <= address && address < 0x4020) // UNUSED ???
    {
    }
    else if (0x4020 <= address && address < 0x10000) // Write to cartridge
    {
        cartridge->writeMainBus(address, data);
    }
    else
    {
        return; // Error unknown address
    }
}
