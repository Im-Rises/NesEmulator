#ifndef DEF_PPU
#define DEF_PPU

#include "binaryLib.h"

class Bus;

class Ppu
{
private:
	Bus* bus = nullptr;

public:
	Ppu();
	void connectToBus(Bus* bus);

};

#endif 