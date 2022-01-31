#include "Mmu.h"

#include <iostream>
#include "Bus.h"

Mmu::Mmu()
{
	//memset(memory, 0, 0xFFFF);
	for (uint8& i : memory)
		i = 0;
}

void Mmu::connectToBus(Bus* bus)
{
	this->bus = bus;
}

//void Mmu::read()
//{
//
//}