#ifndef DEF_NES
#define DEF_NES

#define VER 0.1
#define AUTHOR "Im-Rises"
#define PROJECT_NAME "NesEmulator"

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
	Mmu mmu;
	Ppu ppu;
	//Apu apu;
	//Joypad joypad;

	Bus bus;// main bus
	PpuBus ppuBus;// ppu bus

public:
	static Nes* getInstance(const std::string romPath);
	void start();
	void insertCartridge(const std::string& romPath);

};

#endif
