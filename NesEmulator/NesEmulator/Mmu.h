#ifndef DEF_MMU
#define DEF_MMU

#include "binaryLib.h"

class Bus;

class Mmu
{
private:
	uint8 memory[0xFFFF];
	Bus* bus = nullptr;

public:
	Mmu();
	void connectToBus(Bus* bus);

	uint8 read();
	void write();

};

#endif