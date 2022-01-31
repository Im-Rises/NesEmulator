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
	//this->cartridge->connectToBus(this);

	this->ppu = ppu;
	this->ppu->connectToBus(this);
}

uint8 Bus::read(const uint16& address)
{
	return 0;
}

void Bus::write(const uint16& address, const uint8& data)
{

}