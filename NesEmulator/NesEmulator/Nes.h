#ifndef DEF_NES
#define DEF_NES

#define VER 0.1
#define AUTHOR "Im-Rises"
#define PROJECT_NAME "NesEmulator"

#include "Cpu.h"
#include "Bus.h"

class Nes
{
private:
	static Nes* nesInstance;
	Nes();

	Bus bus;
	Cpu cpu;
	//Ppu ppu;
	//Apu apu;
	//Memory memory;
	//Joypad joypad;

public:
	static Nes* getInstance();
	void start();

};

#endif
