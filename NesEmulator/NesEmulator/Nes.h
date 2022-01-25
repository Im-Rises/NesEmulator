#ifndef DEF_NES
#define DEF_NES

#define VER 0.1
#define AUTHOR "Im-Rises"
#define PROJECT_NAME "NesEmulator"

#include "Cpu.h"
#include "Ppu.h"
#include "Apu.h"
#include "Mmu.h"
#include "Bus.h"

class Nes
{
private:
	static Nes* nesInstance;
	Nes();

	Cpu cpu;
	//Ppu ppu;
	//Apu apu;
	//Mmu mmu;
	//Joypad joypad;
	Bus bus;

public:
	static Nes* getInstance();
	void start();

};

#endif
