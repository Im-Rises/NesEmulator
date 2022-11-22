#ifndef DEF_CARTRIDGE
#define DEF_CARTRIDGE

#include <binaryLib.h>
#include <string>
#include <vector>
#include <memory>

class Bus;
class PpuBus;
class Mapper;

class Cartridge {
private:
    // Program and character's size may be different depending of the cartridge. So I use vector to size it depending of the rom/mapper etc...
    std::vector<uint8> prgMemory;
    std::vector<uint8> chrMemory;

    std::shared_ptr<Mapper> mapperPtr; // Allow us to delete the mapper and deallocate the memory.

    // Header is the 16 first bytes of the rom
    struct
    {
        char gameName[4];
        uint8 nbrPrgBanks; // Number of rom banks
        uint8 nbrChrBanks; // Number of chr banks
        uint8 mapper1;
        uint8 mapper2;
        uint8 ramSize;
        uint8 tvSystem1;
        uint8 tvSystem2;
        char unused[5];
    } header;

    uint16 mapperId;

    // Useless, already present in the structure "header"
    // uint8 prgBanks;
    // uint8 chrBanks;

    Bus* bus = nullptr;
    PpuBus* ppuBus = nullptr;

public:
    Cartridge(const std::string& romPath);

    void connectToBus(Bus* bus);          // Main bus connection
    void connectToPpuBus(PpuBus* ppuBus); // PpuBus connection

    // Read and write for the Main bus (read/write from CPU)
    uint8 readMainBus(const uint16& address) const;
    void writeMainBus(const uint16& address, const uint8& data);

    // Read and write for the PpuBus (read/write from PPU)
    uint8 readPpuBus(const uint16& address) const;
    void writePpuBus(const uint16& address, const uint8& data);
};

#endif
