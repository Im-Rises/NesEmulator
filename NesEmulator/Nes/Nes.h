#ifndef DEF_NES
#define DEF_NES

#include "Bus.h"
#include "Cpu.h"
#include "Mmu.h"
#include "Cartridge.h"
#include "Ppu.h"
#include "PpuBus.h"
//#include "Apu.h"
//#include "Joypad.h"

class Nes
{
private:
	static Nes* nesInstance;
	Nes(const std::string romPath);

	Cpu cpu;	
	Cartridge cartridge;
	//Mmu mmu;
	Ppu ppu;
	//Apu apu;
	//Joypad joypad;

	Bus bus;// main bus
	PpuBus ppuBus;// ppu bus

	int cyclesCounter;

public:
	static Nes* getInstance(const std::string romPath);
	void start();
	void reset();
	//void insertCartridge(const std::string& romPath);

private:
	void clock();

public:
#ifdef DEF_NES_EMU_UI
	*uint8 getCpuState();
	*uint8 getRam();

#endif


};

#endif