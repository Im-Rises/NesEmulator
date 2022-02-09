#include "PpuBus.h"

#include "Ppu.h"
#include "Cartridge.h"

PpuBus::PpuBus(Ppu* ppu, Cartridge* cartridge)
{
	// Only the PPU can read and write to the ppuBus
	this->ppu = ppu;
	this->ppu->connectToPpuBus(this);

	this->cartridge = cartridge;
	//this->cartridge->connectToPpuBus(this);

	for (uint8& i : palette)
		i = 0;

	for (uint8& i : nameTable)
		i = 0;
}

uint8 PpuBus::read(const uint16& address)
{
	if (0 <= address && address < 0x2000)
	{
		return cartridge->readChr(address);
	}
	else if (0x2000 <= address && address < 0x3F00)
	{
		return nameTable[address % 0x800];
	}
	else if (0x3F00 <= address && address < 0x4000)
	{
		return palette[address - 0x4000];
	}
	else
	{
		return 0;
		//?
	}
}

void PpuBus::write(const uint16& address, const uint8& data)
{
	//
}