#ifndef DEF_MMU
#define DEF_MMU

#include <binaryLib.h>

/// <summary>
/// Class may be useless
/// </summary>

class Bus;

class Mmu {
private:
    uint8 memory[0x800];
    Bus* bus = nullptr;

public:
    Mmu();
    void connectToBus(Bus* bus);

    uint8 read(const uint16& address) const;
    void write(const uint16& address, const uint8& data);
};

#endif
