#ifndef DEF_BUS
#define DEF_BUS

#include "binaryLib.h"

class Cpu;
class Mmu;
class Cartridge;
class Ppu;

class Bus
{
private:
	Cpu* cpu = nullptr;
	Mmu* mmu = nullptr;
	Cartridge* cartridge = nullptr;
	Ppu* ppu = nullptr;

public:
	Bus(Cpu* cpu, Mmu* mmu, Cartridge* cartridge, Ppu* ppu);
	uint8 read(const uint16& address);
	void write(const uint16& address, const uint8& data);
};

#endif
