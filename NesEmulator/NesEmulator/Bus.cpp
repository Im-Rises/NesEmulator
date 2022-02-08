#include "Bus.h"

#include "Cpu.h"
#include "Mmu.h"
#include "Cartridge.h"
#include "Ppu.h"

Bus::Bus(Cpu* cpu, Mmu* mmu, Cartridge* cartridge, Ppu* ppu)
{
	this->cpu = cpu;
	this->cpu->connectToBus(this);

	this->mmu = mmu;
	this->mmu->connectToBus(this);

	this->cartridge = cartridge;
	this->cartridge->connectToBus(this);

	this->ppu = ppu;
	this->ppu->connectToBus(this);
}

uint8 Bus::read(const uint16& address)
{
	if (0 <= address && address < 0x2000)//Read ram (Mmu)
		return mmu->read(address);
	else if (0x2000 <= address && address < 0x4000)//Read ppu
		return ppu->readPpu(address);
	else//Read cartridge
		return cartridge->readPrg(address);
}

void Bus::write(const uint16& address, const uint8& data)
{
	if (0 <= address && address < 0x2000)//Write to ram (Mmu)
		mmu->write(address, data);
	else if (0x2000 <= address && address < 0x4000)//Write to ppu
		ppu->write(address, data);
	else//Write to cartridge
		cartridge->writePrg(address, data);
}