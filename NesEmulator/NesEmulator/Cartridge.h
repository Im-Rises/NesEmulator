#ifndef DEF_CARTRIDGE
#define DEF_CARTRIDGE

#include "binaryLib.h"

class Bus;

class Cartridge
{
private:
	Bus* bus = nullptr;

public:
	Cartridge();
	void connectToBus(Bus* bus);

};

#endif
