#ifndef DEF_MAPPER000
#define DEF_MAPPER000

#include "Mapper.h"
#include "binaryLib.h"

//Inheritence needs to be public (public Mapper) to be visible by shared_ptr in cartridge
class Mapper000 : public Mapper
{
public:
	Mapper000(const uint8& nbrPrgBanks, const uint8& nbrChrbanks);

	bool readPrg(const uint16& address);
	bool writePrg(const uint16& address, const uint8& data);
	bool readChr(const uint16& address);
	bool writeChr(const uint16& address, const uint8& data);
};

#endif // !DEF_MAPPER000
