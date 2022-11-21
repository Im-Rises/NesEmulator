#include "Mapper000.h"

Mapper000::Mapper000(const uint8& nbrPrgBanks, const uint8& nbrChrbanks) : Mapper(nbrPrgBanks, nbrChrbanks)
{

}

/// <summary>
/// RESUME HERE
/// </summary>
/// <param name="address"></param>
/// <returns></returns>

uint32 Mapper000::readPrg(const uint16& address)
{
	//return address & ((nbrPrgBanks > 1) ? 0x8000 : 0x4000);
	return 0;
}

void Mapper000::writePrg(const uint16& address, const uint8& data)
{
	//mappedAddress = address & ((nbrPrgBanks > 1) ? 0x8000 : 0x4000);
}


uint32 Mapper000::readChr(const uint16& address)
{
	return address;//Only one bank so no modification of the address (no address mapping)
}

void Mapper000::writeChr(const uint16& address, const uint8& data)
{
	//Do nothing
}
