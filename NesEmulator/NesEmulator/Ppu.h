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

	//Read and write to Ppu
	uint8 readPpu(const uint16& address);
	void write(const uint16& address, const uint8& data);


	//// Main bus read/write
	//uint8 readCpuBus(const uint16& address);
	//void writeCpuBus(const uint16& address, const uint8& data);

	//// Ppu bus read/write
	//uint8 readCpuBus(const uint16& address);
	//void writeCpuBus(const uint16& address, const uint8& data);

};

#endif 
