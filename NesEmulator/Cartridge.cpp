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

		//the next 512 bytes are used for trainer area, we're not interested in copying it
		if (header.mapper1 & 0x04)
			input.seekg(512, std::ios_base::cur);//Move cursor 512 bytes away from current position

		mapperId = (header.mapper1 >> 4) | (header.mapper2 & 0xF0);

		uint8 fileFormat = 1;

		//Depending of the Ines file we get the data differently. For the moment I only implemented the fileFormat 1.
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
			prgMemory.resize(prgSize);//Define size of vector (size by 16KB, 32KB)
			input.read((char*)prgMemory.data(), prgMemory.size());//Copy rom into vector

			auto chrSize = header.nbrChrBanks * 0x2000;
			chrMemory.resize(chrSize);//Define size of vector (size by 8KB, 16KB)
			input.read((char*)chrMemory.data(), chrMemory.size());//Copy rom into vector
		}
		else if (fileFormat == 2)
		{

		}
		else
		{
			//Unknown file format
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
			exit(2);
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
/// Issue understanding the Cartridge and Mappers
/// Does it work like the GameBoy, when we write to the rom it change the current ram/rom bank or is it different ?
/// It seems to work when we write and read to the cartridge.
/// https://wiki.nesdev.org/w/index.php?title=Mapper
/// https://wiki.nesdev.org/w/index.php/CPU_memory_map
/// https://en.wikibooks.org/wiki/NES_Programming/Memory_Map
/// </summary>
/// <param name="address"></param>
/// <returns></returns>

/// <summary>
/// The main bus can read/write from different data in the cartridge (prg Rom, expansion rom and SRAM).
/// On the contrary the PpuBus can only access the chr rom.
/// This is why the read and write for the main bus implement other components.
/// </summary>
/// <param name="address"></param>
/// <returns></returns>

uint8 Cartridge::readMainBus(const uint16& address) const
{
	if (address < 0x6000)
	{
		return 0;//Access to cartridge expansion rom (not implemented)
	}
	else if (address < 0x8000)
	{
		return 0;//Access to SRAM (not implemented)
	}
	else
	{
		return prgMemory[mapperPtr->readPrg(address)];
	}
}

void Cartridge::writeMainBus(const uint16& address, const uint8& data)
{
	if (address < 0x6000)
	{
		return;//Access to cartridge expansion rom (not implemented)
	}
	else if (address < 0x8000)
	{
		return;//Access to SRAM (not implemented)
	}
	else
	{
		mapperPtr->writePrg(address, data);
	}
}


uint8 Cartridge::readPpuBus(const uint16& address) const
{
	return chrMemory[mapperPtr->readChr(address)];
}

void Cartridge::writePpuBus(const uint16& address, const uint8& data)
{
	mapperPtr->writeChr(address, data);
}
