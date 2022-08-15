#ifndef MMU_H
#define MMU_H

#include "cartridge.h"
#include "types.h"
#include "debug.h"

class MMU {
    Cartridge &cartridge;

    u8 HRAM[0x007F];
    u8 WRAM[0x2000];

    // For testing purposes
    u8 MemBlock;

    friend class Debug;

public:
    MMU(Cartridge &ctg);

    u8& operator[](const u16 addr);

};

#endif
