#include "Bus.h"

#include "Cpu.h"
#include "Mmu.h"
#include "Cartridge.h"
#include "Ppu.h"

Bus::Bus(Cpu* cpu, Mmu* mmu, Cartridge* cartridge, Ppu* ppu)
{
	// Only the CPU can read and write to the main bus
	this->cpu = cpu;
	this->cpu->connectToBus(this);

	this->mmu = mmu;
	//this->mmu->connectToBus(this);

	this->cartridge = cartridge;
	//this->cartridge->connectToBus(this);

	this->ppu = ppu;
	//this->ppu->connectToBus(this);
}

uint8 Bus::read(const uint16& address)
{
	if (0 <= address && address < 0x2000)//Read ram (Mmu)
	{
		return mmu->read(address);
	}
	else if (0x2000 <= address && address < 0x4000)//Read ppu
	{
		return ppu->readPpu(address);
	}
	else if (0x4020 <= address && address < 0x10000)//Read cartridge
	{
		return cartridge->readPrg(address);
	}
	else
	{
		return 0;//Not implemented (APU, Joypads, etc...)
	}
}

void Bus::write(const uint16& address, const uint8& data)
{
	if (0 <= address && address < 0x2000)//Write to ram (Mmu)
	{
		mmu->write(address, data);
	}
	else if (0x2000 <= address && address < 0x4000)//Write to ppu
	{
		ppu->writePpu(address, data);
	}
	else if (0x4020 <= address && address < 0x10000)//Write to cartridge
	{
		cartridge->writePrg(address, data);
	}
	else
	{
		return;//Not implemented (APU, Joypads, etc...)
	}
}