#include "Mmu.h"

#include <iostream>
#include "Bus.h"

Mmu::Mmu() :memory{}
{
	//memset(memory, 0, 0xFFFF);
	//for (uint8& i : memory)
	//	i = 0;
}

void Mmu::connectToBus(Bus* bus)
{
	this->bus = bus;
}

uint8 Mmu::read(const uint16& address) const
{
	// Memory mirroring between the address and the max address value
	return memory[address % 0x0800];
}

void Mmu::write(const uint16& address, const uint8& data)
{
	memory[address % 0x0800] = data;
}
