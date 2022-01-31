#include "PpuBus.h"

#include "Ppu.h"
#include "Cartridge.h"

PpuBus::PpuBus(Ppu* ppu, Cartridge* cartridge)
{
	this->ppu = ppu;
	this->cartridge = cartridge;
}
