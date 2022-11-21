#ifndef DEF_MAPPER000
#define DEF_MAPPER000

#include "Mapper.h"
#include "../binaryLib/binaryLib.h"

/// <summary>
/// https://wiki.nesdev.org/w/index.php?title=NROM
/// Rom capacity : 16K or 32K (0x4000 to 0x8000) only one bank
/// CHR capacity : 8K (0x2000) only one bank
/// </summary>
/// <param name="address"></param>
/// <returns></returns>

//Inheritence needs to be public "public Mapper" to be visible by shared_ptr in cartridge
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
