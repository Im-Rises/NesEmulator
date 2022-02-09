#ifndef DEF_MAPPER000
#define DEF_MAPPER000

#include "Mapper.h"
#include "binaryLib.h"

//Inheritence needs to be public (public Mapper) to be visible by shared_ptr in cartridge
class Mapper000 : public Mapper
{
private:
	//Nothing

public:
	Mapper000(const uint8& nbrPrgBanks, const uint8& nbrChrbanks);

	uint32 readPrg(const uint16& address) override;
	void writePrg(const uint16& address, const uint8& data) override;

	uint32 readChr(const uint16& address) override;
	void writeChr(const uint16& address, const uint8& data) override;
};

#endif // !DEF_MAPPER000
