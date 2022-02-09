#include "Mapper.h"

Mapper::Mapper(const uint8& nbrPrgBanks, const uint8& nbrChrBanks)
{
	this->nbrPrgBanks = nbrPrgBanks;
	this->nbrChrBanks = nbrChrBanks;
}

//uint32 Mapper::getMappedAddress() const 
//{
//	return mappedAddress;
//}