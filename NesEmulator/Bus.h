#ifndef DEF_BUS
#define DEF_BUS

#include "binaryLib/binaryLib.h"

class Cpu;
class Mmu;
class Cartridge;
class Ppu;

/// <summary>
/// 16 bit address bus
/// 8 bit data bus
/// </summary>

class Bus
{
private:
	Cpu* cpu = nullptr;
	//Mmu* mmu = nullptr;
	Cartridge* cartridge = nullptr;
	Ppu* ppu = nullptr;
	uint8 memory[0x800];

public:
	//Bus(Cpu* cpu, Mmu* mmu, Cartridge* cartridge, Ppu* ppu);
	Bus(Cpu* cpu, Cartridge* cartridge, Ppu* ppu);
	uint8 read(const uint16& address) const;
	void write(const uint16& address, const uint8& data);
};

#endif
