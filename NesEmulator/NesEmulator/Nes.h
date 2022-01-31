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
//#include "Apu.h"

class Nes
{
private:
	static Nes* nesInstance;
	Nes();

	Cpu cpu;	
	Cartridge cartridge;
	Mmu mmu;
	Ppu ppu;
	//Apu apu;

	//Joypad joypad;

	Bus bus;

public:
	static Nes* getInstance();
	void start();

};

#endif
