#include "PpuBus.h"

#include "Ppu.h"
#include "Cartridge.h"

/// <summary>
/// https://en.wikibooks.org/wiki/NES_Programming/Memory_Map
/// </summary>
/// <param name="ppu"></param>
/// <param name="cartridge"></param>

PpuBus::PpuBus(Ppu* ppu, Cartridge* cartridge) : palette{}, nameTable{}
{
	// Only the PPU can read and write to the ppuBus
	this->ppu = ppu;
	this->ppu->connectToPpuBus(this);

	this->cartridge = cartridge;
	//this->cartridge->connectToPpuBus(this);

	//for (uint8& i : palette)
	//	i = 0;

	//for (uint8& i : nameTable)
	//	i = 0;
}

uint8 PpuBus::read(const uint16& address) const
{
	if (0 <= address && address < 0x2000)
	{
		return cartridge->readPpuBus(address);
	}
	else if (0x2000 <= address && address < 0x3F00)
	{
		return nameTable[(address - 0x2000) % 0x800];//Or (address % 0x800)
	}
	else if (0x3F00 <= address && address < 0x4000)
	{
		return palette[address - 0x3F00];
	}
	else
	{
		return 0;
		//?
	}
}

void PpuBus::write(const uint16& address, const uint8& data)
{
	if (0 <= address && address < 0x2000)
	{
		cartridge->writePpuBus(address, data);
	}
	else if (0x2000 <= address && address < 0x3F00)
	{
		nameTable[address % 0x800] = data;
	}
	else if (0x3F00 <= address && address < 0x4000)
	{
		palette[address - 0x4000] = data;
	}
	else
	{
		return;
		//?
	}
}
