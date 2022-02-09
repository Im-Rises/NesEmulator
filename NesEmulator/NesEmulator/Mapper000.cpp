#include "Mapper000.h"

Mapper000::Mapper000(const uint8& nbrPrgBanks, const uint8& nbrChrbanks) : Mapper(nbrPrgBanks, nbrChrbanks)
{

}


uint32 Mapper000::readPrg(const uint16& address)
{
	mappedAddress = address & ((nbrPrgBanks > 1) ? 0x8000 : 0x4000);
}

void Mapper000::writePrg(const uint16& address, const uint8& data)
{
	mappedAddress = address & ((nbrPrgBanks > 1) ? 0x8000 : 0x4000);
}


uint32 Mapper000::readChr(const uint16& address)
{
	mappedAddress = address;
}

void Mapper000::writeChr(const uint16& address, const uint8& data)
{
	//if (0x0000 <= address && address < 0x2000)
	//{
	//	uint16 mappedAddress = address;
	//	return true;
	//}
}
