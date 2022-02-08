#ifndef DEF_MAPPER
#define DEF_MAPPER

#include "binaryLib.h"

class Mapper
{
protected:
	uint8 nbrPrgBanks;
	uint8 nbrChrbanks;

	uint32 mappedAddress = 0;

public:
	Mapper(const uint8& nbrPrgBanks, const uint8& nbrChrbanks);

	/// <summary>
	/// The mappers are used for bank switching. If we write or read to the cartridge the bank is changed.
	/// For this reason the only values that are returned are boolean if the banking succeed.
	/// </summary>
	/// <param name="address"></param>
	/// <returns></returns>
	virtual bool readPrg(const uint16& address) = 0;
	virtual bool writePrg(const uint16& address, const uint8& data) = 0;

	virtual bool readChr(const uint16& address) = 0;
	virtual bool writeChr(const uint16& address, const uint8& data) = 0;

	uint32 getMappedAddress() const;

};

#endif // !DEF_MAPPER
