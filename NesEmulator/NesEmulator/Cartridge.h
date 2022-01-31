#ifndef DEF_CARTRIDGE
#define DEF_CARTRIDGE

#include "binaryLib.h"

class Bus;
class PpuBus;

class Cartridge
{
private:
	//uint8 rom[];

	Bus* bus = nullptr;
	PpuBus* ppuBus = nullptr;

public:
	Cartridge();
	void connectToBus(Bus* bus);//Main bus connection
	void connectToPpuBus(PpuBus* ppuBus);//PpuBus connection

	uint8 read(const uint16& address);
	void write(const uint16& address, const uint8 data);
};

#endif
