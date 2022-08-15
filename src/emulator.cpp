#include "emulator.h"
#include "debug.h"
#include <iostream>
#include <string>

Emulator::Emulator()
{
    cartridge = new Cartridge();
    mmu = new MMU(*cartridge);
    cpu = new CPU(*mmu);
}

void Emulator::InsertCartridge(std::string filename)
{
    cartridge->Load(filename);
}

void Emulator::Run()
{
    while (true) {
        cpu->Execute();
    }
}

Emulator::~Emulator()
{
    delete cartridge;
    delete mmu;
    delete cpu;
}
