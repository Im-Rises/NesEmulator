#include "Bus.h"

#include "Cpu.h"

Bus::Bus(Cpu* cpu)
{
	this->cpu = cpu;
	this->cpu->connectToBus(this);
}

uint8 Bus::read(const uint16& address)
{
	return 0;
}

void Bus::write(const uint16& address, const uint8& data)
{

}