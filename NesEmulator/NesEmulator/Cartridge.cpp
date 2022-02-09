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
		else if (fileFormat == 1)
		{
			//Issue
			// A sub-expression may overflow before being assigned to a wider type if writting:
			//- chrMemory.resize(header.prgRomSize * 0x4000);
			//- chrMemory.resize(header.chrRomSize * 0x2000);
			// I used the auto keywoad to be sure the temp variable can contain the max size of the rom
			// A sub expression may overflow before being assigned to a wider type.

			//vector.data() returns a direct pointer to the memory array used internally by the vector
			//By sending the pointer, we can directly modify it

			auto prgSize = header.nbrPrgBanks * 0x4000;
			prgMemory.resize(prgSize);//Size by 16KB, 32KB
			input.read((char*)prgMemory.data(), sizeof(prgMemory));

			auto chrSize = header.nbrChrBanks * 0x2000;
			chrMemory.resize(chrSize);//Size by 8KB, 16KB
			input.read((char*)chrMemory.data(), sizeof(chrMemory));
		}
		else if (fileFormat == 2)
		{

		}

		//Make_shared is used for derived classes
		switch (mapperId)
		{
		case(0):
		{
			mapperPtr = std::make_shared<Mapper000>(header.nbrPrgBanks, header.nbrChrBanks);
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
		exit(1);
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


/// <summary>
/// RESUME HERE
/// Issue understanding the Cartridge and Mappers
/// Does it work like the GameBoy, when we write to the rom it change the current ram/rom bank or is it different ?
/// It seems to work when we write and read to the cartridge.
/// </summary>
/// <param name="address"></param>
/// <returns></returns>

uint8 Cartridge::readPrg(const uint16& address)
{

	//if (mapperPtr->readPrg(address))
	//{
	//return prgMemory[mapperPtr->getMappedAddress()];
	//}
	//return 0;//Issue ?
}

void Cartridge::writePrg(const uint16& address, const uint8& data)
{
	//if (mapperPtr->writePrg(address, data))
	//{
	//prgMemory[mapperPtr->getMappedAddress()] = data;//issue ?
//}
}


uint8 Cartridge::readChr(const uint16& address)
{
	//if (mapperPtr->readChr(address))
	//{
	//return chrMemory[mapperPtr->getMappedAddress()];
	//}
	//return 0;//issue ?
}

void Cartridge::writeChr(const uint16& address, const uint8& data)
{
	//if (mapperPtr->writeChr(address, data))
	//{
	//chrMemory[mapperPtr->getMappedAddress()] = data;//issue ?
//}
}
