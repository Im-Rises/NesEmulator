#include "Nes.h"

#include "SDL2/include/SDL.h"

Nes* Nes::nesInstance = nullptr;

Nes::Nes() :bus(&cpu, &mmu, &cartridge, &ppu), ppuBus(&ppu, &cartridge)
{

}

Nes* Nes::getInstance()
{
	if (nesInstance == nullptr)
		nesInstance = new Nes();

	return nesInstance;
}

void Nes::start()
{
	//while (true)
	//{
	//	cpu.doCycl();
	//}
}

void Nes::insertCartridge(const string& romPath)
{

}