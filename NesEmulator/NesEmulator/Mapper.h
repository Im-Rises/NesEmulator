#ifndef DEF_MAPPER
#define DEF_MAPPER

#include "binaryLib.h"

class Mapper
{
protected:
	uint8 nbrPrgBanks;
	uint8 nbrChrbanks;

public:
	Mapper(const uint8& nbrPrgBanks, const uint8& nbrChrbanks);

	virtual bool readPrg(const uint16& address) = 0;
	virtual bool writePrg(const uint16& address, const uint8& data) = 0;

	virtual bool readChr(const uint16& address) = 0;
	virtual bool writeChr(const uint16& address, const uint8& data) = 0;

};

#endif // !DEF_MAPPER
