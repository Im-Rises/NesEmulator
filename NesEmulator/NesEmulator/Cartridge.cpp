#include "Cartridge.h"

#include "Bus.h"
#include "PpuBus.h"

Cartridge::Cartridge()
{

}

void Cartridge::connectToBus(Bus* bus)
{
	this->bus = bus;
}

void Cartridge::connectToPpuBus(PpuBus* ppuBus)
{
	this->ppuBus = ppuBus;
}
