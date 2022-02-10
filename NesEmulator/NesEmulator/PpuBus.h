#ifndef DEF_PPUBUS
#define DEF_PPUBUS

#include "binaryLib.h"

class Ppu;
class Cartridge;

/// <summary>
/// Create class for the two arrays ? 
/// </summary>

class PpuBus
{
private:
	//uint8 pattern[0x2000];// Is in the cartridge (mappers), now that i have implemented pointer to the cartridge it is not needed here
	uint8 palette[32];
	uint8 nameTable[0x800];

	Ppu* ppu = nullptr;
	Cartridge* cartridge = nullptr;

public:
	PpuBus(Ppu* ppu, Cartridge* cartridge);

	uint8 read(const uint16& address);
	void write(const uint16& address, const uint8& data);

};

#endif // !DEF_PPUBUS
