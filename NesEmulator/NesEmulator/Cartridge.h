#ifndef DEF_CARTRIDGE
#define DEF_CARTRIDGE

#include "binaryLib.h"
#include <string>
#include <vector>
#include <memory>

class Bus;
class PpuBus;
class Mapper;

class Cartridge
{
private:
	std::vector<uint8> prgMemory;
	std::vector<uint8> chrMemory;

	std::shared_ptr<Mapper> mapperPtr;// Allow us to be sure of deleting the mapper

	// Header is the 16 first bytes of the rom
	struct
	{
		char gameName[4];
		uint8 prgRomSize;
		uint8 chrRomSize;
		uint8 mapper1;
		uint8 mapper2;
		uint8 ramSize;
		uint8 tvSystem1;
		uint8 tvSystem2;
		char unused[5];
	}header;

	uint8 mapperId;

	Bus* bus = nullptr;
	PpuBus* ppuBus = nullptr;

public:
	Cartridge(const std::string& romPath);

	void connectToBus(Bus* bus);//Main bus connection
	void connectToPpuBus(PpuBus* ppuBus);//PpuBus connection

	// Read and write for the Main bus
	uint8 readPrg(const uint16& address);
	void writePrg(const uint16& address, const uint8& data);

	// Read and write for the PpuBus
	uint8 readChr(const uint16& address);
	void writeChr(const uint16& address, const uint8& data);
};

#endif
