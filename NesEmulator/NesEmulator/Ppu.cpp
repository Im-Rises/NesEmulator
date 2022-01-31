#include "Ppu.h"

#include "Bus.h"

Ppu::Ppu()
{

}


void Ppu::connectToBus(Bus* bus)
{
	this->bus = bus;
}