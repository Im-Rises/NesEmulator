#include "Cartridge.h"

#include "Bus.h"

Cartridge::Cartridge()
{

}

void Cartridge::connectToBus(Bus* bus)
{
	this->bus = bus;
}
