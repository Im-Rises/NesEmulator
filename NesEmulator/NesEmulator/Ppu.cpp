#include "Ppu.h"

#include "Bus.h"
#include "PpuBus.h"

Ppu::Ppu()
{

}

void Ppu::connectToBus(Bus* bus)
{
	this->bus = bus;
}

void Ppu::connectToPpuBus(PpuBus* ppuBus)
{
	this->ppuBus = ppuBus;
}


uint8 Ppu::readPpu(const uint16& address)
{
	switch (address % 8)
	{
	case(0x0000):
	{
		break;
	}
	case(0x0001):
	{
		break;
	}
	case(0x0002):
	{
		break;
	}
	case(0x0003):
	{
		break;
	}
	case(0x0004):
	{
		break;
	}
	case(0x0005):
	{
		break;
	}
	case(0x0006):
	{
		break;
	}
	case(0x0007):
	{
		break;
	}
	default:
	{
		break;
	}
	}

	return 0;
}

void Ppu::writePpu(const uint16& address, const uint8& data)
{
	//address % 8
}



//// Main bus read/write
//uint8 Ppu::readCpuBus(const uint16& address)
//{
//	bus->read(address);
//}
//
//void Ppu::writeCpuBus(const uint16& address, const uint8& data)
//{
//	bus->write(address, data);
//}


//// Ppu bus read/write
//uint8 Ppu::readCpuBus(const uint16& address)
//{
//
//}
//
//void Ppu::writeCpuBus(const uint16& address, const uint8& data)
//{
//
//}