#include "Cartridge.h"

#include <iostream>
#include <fstream>

#include "Bus.h"
#include "PpuBus.h"
#include "Mapper.h"
#include "Mapper000.h"

Cartridge::Cartridge(const std::string& romPath)
{
	std::ifstream input(romPath, std::ios::binary);
	if (input.is_open())
	{
		//Casting the structure address as a char array 
		input.read((char*)&header, sizeof(header));// Populate the header struct

		if (header.mapper1 & 0x04)
			input.seekg(512, std::ios_base::cur);//Move cursor 512 byts away from current position

		mapperId = (header.mapper1 >> 4) | (header.mapper2 & 0xF0);

		uint8 fileFormat = 1;

		if (fileFormat == 0)
		{

		}

		if (fileFormat == 1)
		{
			//Issue
			// A sub-expression may overflow before being assigned to a wider type if writting:
			//- chrMemory.resize(header.prgRomSize * 0x4000);
			//- chrMemory.resize(header.chrRomSize * 0x2000);

			//vector.data() returns a direct pointer to the memory array used internally by the vector
			//By sending the pointer, we can directly modify it
			auto temp1 = header.prgRomSize * 0x4000;
			prgMemory.resize(temp1);//Size by 16KB, 32KB
			input.read((char*)prgMemory.data(), sizeof(prgMemory));

			auto temp2 = header.chrRomSize * 0x2000;
			chrMemory.resize(temp2);//Size by 8KB, 16KB
			input.read((char*)chrMemory.data(), sizeof(chrMemory));
		}

		if (fileFormat == 2)
		{

		}

		switch (mapperId)
		{
		case(0):
		{
			mapperPtr = std::make_shared<Mapper000>(header.prgRomSize, header.chrRomSize);//Make_shared is used for derived classes
			break;
		}
		default:
		{
			std::cout << "Unknown cartridge" << std::endl;
			break;
		}
		}

		input.close();
	}
	else
	{
		std::cout << "Rom file not found" << std::endl;
	}
}

void Cartridge::connectToBus(Bus* bus)
{
	this->bus = bus;
}

void Cartridge::connectToPpuBus(PpuBus* ppuBus)
{
	this->ppuBus = ppuBus;
}