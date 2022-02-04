#include "Nes.h"

#include "SDL2/include/SDL.h"

Nes* Nes::nesInstance = nullptr;

Nes::Nes(const std::string romPath) :cartridge(romPath), bus(&cpu, &mmu, &cartridge, &ppu), ppuBus(&ppu, &cartridge)
{

}

Nes* Nes::getInstance(const std::string romPath)
{
	if (nesInstance == nullptr)
		nesInstance = new Nes(romPath);

	return nesInstance;
}

void Nes::start()
{
	//while (true)
	//{
	//	cpu.doCycl();
	//}
}

void Nes::insertCartridge(const std::string& romPath)
{

}