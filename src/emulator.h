#ifndef EMULATOR_H
#define EMULATOR_H

#include <iostream>

#include "cartridge.h"
#include "cpu.h"
#include "mmu.h"
#include "debug.h"

class Emulator {

    CPU *cpu;
    Cartridge *cartridge;
    MMU *mmu;

public:
    Emulator();
    ~Emulator();

    void Run();
    void InsertCartridge(std::string filename);

};

#endif
