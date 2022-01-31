#ifndef DEF_PPUBUS
#define DEF_PPUBUS

#include "binaryLib.h"

class Ppu;
class Cartridge;

class PpuBus
{
private:
	//uint8 pattern[0x2000];// Is in the cartridge (mappers), now that i have implemented pointer to the cartridge
	uint8 palette[32];
	uint8 nameTable[0x800];

	Ppu* ppu = nullptr;
	Cartridge* cartridge = nullptr;

public:
	PpuBus(Ppu* ppu, Cartridge* cartridge);

};

#endif // !DEF_PPUBUS
