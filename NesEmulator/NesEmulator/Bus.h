#ifndef DEF_BUS
#define DEF_BUS

#include "binaryLib.h"

class Cpu;

class Bus
{
private:
	Cpu* cpu = nullptr;

public:
	Bus(Cpu* cpu);
	uint8 read(const uint16& address);
	void write(const uint16& address, const uint8& data);
};

#endif
