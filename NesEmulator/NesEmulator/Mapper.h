#ifndef DEF_MAPPER
#define DEF_MAPPER

#include "binaryLib.h"

/// <summary>
/// The purpose of the mapper is to transform a given address to another to do banking.
/// This is why the mappers return an address that point to the real address we're writing or reading to/from.
/// </summary>

class Mapper
{
protected:
	uint8 nbrPrgBanks;
	uint8 nbrChrBanks;

	uint32 mappedAddress = 0;

public:
	Mapper(const uint8& nbrPrgBanks, const uint8& nbrChrBanks);

	/// <summary>
	/// The mappers are used for bank switching. If we write or read to the cartridge the bank is changed.
	/// For this reason the only values that are returned are boolean if the banking succeed.
	/// Internally the mappedAddress variable is modified to know from which address we fetch the data in the cartridge.
	/// </summary>
	/// <param name="address"></param>
	/// <returns></returns>
	virtual uint32 readPrg(const uint16& address) = 0;
	virtual void writePrg(const uint16& address, const uint8& data) = 0;

	virtual uint32 readChr(const uint16& address) = 0;
	virtual void writeChr(const uint16& address, const uint8& data) = 0;

	//uint32 getMappedAddress() const;
};

#endif // !DEF_MAPPER
