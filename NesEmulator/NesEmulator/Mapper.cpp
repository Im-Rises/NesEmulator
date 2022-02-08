#include "Mapper.h"

Mapper::Mapper(const uint8& nbrPrgBanks, const uint8& nbrChrbanks)
{
	this->nbrPrgBanks = nbrPrgBanks;
	this->nbrChrbanks = nbrChrbanks;
}

uint32 Mapper::getMappedAddress() const 
{
	return mappedAddress;
}