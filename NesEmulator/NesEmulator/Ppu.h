#ifndef DEF_PPU
#define DEF_PPU

#include "binaryLib.h"

class Bus;
class PpuBus;

class Ppu
{
private:
	Bus* bus = nullptr;
	PpuBus* ppuBus = nullptr;

	//SDL_window* sdlWindow = nullptr;
	//SDL_Renderer* sdlRenderer = nullptr;

	uint16 scanLine;

public:
	Ppu();
	~Ppu();
	void connectToBus(Bus* bus);//Main bus connection
	void connectToPpuBus(PpuBus* ppuBus);//PpuBus connection

	//Cpu read and write to the registers of the Ppu
	uint8 readPpu(const uint16& address);
	void writePpu(const uint16& address, const uint8& data);

	// Ppu bus read/write
	uint8 readPpuBus(const uint16& address);
	void writePpuBus(const uint16& address, const uint8& data);

};

#endif 
