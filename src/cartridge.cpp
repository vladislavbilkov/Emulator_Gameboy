#include "cartridge.h"
#include "debug.h"
#include "types.h"
#include <cstdio>

Cartridge::Cartridge()
{

}

void Cartridge::Load(std::string filename)
{
    std::ifstream file(filename,std::ios::binary);
    file.seekg(0,std::ios::end);
    int size = file.tellg();
    file.seekg(0,std::ios::beg);
    ROM = new u8[size];
    file.read((char*)ROM, size);
    file.close();
}

void Cartridge::Unload(std::string filename)
{
    delete[] ROM;
}

void Cartridge::PrintTitle()
{
    fprintf(stdout, "Title Cartridge - ");
    for (int i = Begin_Title; i < End_Title; i++) {
        fprintf(stdout, "%c", ROM[i]);
    }
}

void Cartridge::PrintGBorSGBIndicator()
{
    if (ROM[GB_SGB_Indicator] == GB) {
        fprintf(stdout, "\nCartridge use GB function\n");
    }
    else if (ROM[GB_SGB_Indicator] == SGB) {
        fprintf(stdout, "\nCartridge use SGB function\n");
    }
    else {
        fprintf(stdout, "\nnot add");
    }
}

void::Cartridge::PrintCartridgeType()
{
    switch (ROM[Type_cartridge]) {
        case ROM_ONLY:
            fprintf(stdout, "\nCartridge type - ROM ONLY\n");
        break;
        case ROM_MBC1:
            fprintf(stdout, "\nCartridge type - ROM MBC1\n");
        break;
        case ROM_MBC1_RAM:
            fprintf(stdout, "\nCartridge type - ROM MBC1 RAM\n");
        break;
        case ROM_MBC1_RAM_BATT:
            fprintf(stdout, "\nCartridge type - ROM MBC1 RAM BATT\n");
        break;
        case ROM_MBC2:
            fprintf(stdout, "\nCartridge type - ROM MBC2\n");
        break;
        case ROM_MBC2_BATTERY:
            fprintf(stdout, "\nCartridge type - ROM MBC2 BATTERY\n");
        break;
        case ROM_RAM:
            fprintf(stdout, "\nCartridge type - ROM_RAM\n");
        break;
        case ROM_RAM_BATTERY:
            fprintf(stdout, "\nCartridge type - ROM RAM BATTERY\n");
        break;
        case ROM_MMM01:
            fprintf(stdout, "\nCartridge type - ROM_MMM01\n");
        break;
        case ROM_MMM01_SRAM:
            fprintf(stdout, "\nCartridge type - ROM MMM01 SRAM\n");
        break;
        case ROM_MMM01_SRAM_BATT_FE_Hudson_HuC_3:
            fprintf(stdout, "\nCartridge type - ROM MMM01 SRAM BATT FE Hudson HuC 3\n");
        break;
        case ROM_MBC3_TIMER_BATT:
            fprintf(stdout, "\nCartridge type - ROM MBC3 TIMER BATT\n");
        break;
        case ROM_MBC3_TIMER_RAM_BATT:
            fprintf(stdout, "\nCartridge type - ROM MBC3 TIMER RAM BATT\n");
        break;
        case ROM_MBC3:
            fprintf(stdout, "\nCartridge type - ROM_MBC3\n");
        break;
        case ROM_MBC3_RAM:
            fprintf(stdout, "\nCartridge type - ROM MBC3 RAM\n");
        break;
        case ROM_MBC3_RAM_BATT:
            fprintf(stdout, "\nCartridge type - ROM MBC3 RAM BATT\n");
        break;
        case ROM_MBC5:
            fprintf(stdout, "\nCartridge type - ROM MBC5:\n");
        break;
        case ROM_MBC5_RAM:
            fprintf(stdout, "\nCartridge type - ROM MBC5 RAM\n");
        break;
        case ROM_MBC5_RAM_BATT:
            fprintf(stdout, "\nCartridge type - ROM MBC5 RAM BATT\n");
        break;
        case ROM_MBC5_RUMBLE:
            fprintf(stdout, "\nCartridge type - ROM MBC5 RUMBLE\n");
        break;
        case ROM_MBC5_RUMBLE_SRAM:
            fprintf(stdout, "\nCartridge type - ROM MBC5 RUMBLE SRAM\n");
        break;
        case ROM_MBC5_RUMBLE_SRAM_BATT:
            fprintf(stdout, "\nCartridge type - ROM MBC5 RUMBLE SRAM BATT\n");
        break;
        case Pocket_Camera:
            fprintf(stdout, "\nCartridge type - Pocket Camera\n");
        break;
        case Bandai_TAMA5:
            fprintf(stdout, "\nCartridge type - Bandai TAMA5\n");
        break;
        case Hudson_HuC_1:
            fprintf(stdout, "\nCartridge type - Hudson HuC 1\n");
        break;
    }
}

void Cartridge::PrintCartridgeLang()
{
    if (ROM[Destination_code] == 0x00) {
        fprintf(stdout, "Cartridge lang - Japanese\n");
    } else {
        fprintf(stdout, "Cartridge lang - Non - Japanese\n");
    }    
}

void Cartridge::PrintCartridgeSizeRom()
{
    switch (ROM[ROM_size]) {
        case Rom32KByte:
            fprintf(stdout, "ROM size - 32KByte\n");
        break;
        case Rom64KByte:
            fprintf(stdout, "ROM size - 64KByte\n");
        break;
        case Rom128KByte:
            fprintf(stdout, "ROM size - 128KByte\n");
        break;
        case Rom256KByte:
            fprintf(stdout, "ROM size - 256KByte\n");
        break;
        case Rom512KByte:
            fprintf(stdout, "ROM size - 512KByte\n");
        break;
        case Rom1MByte:
            fprintf(stdout, "ROM size - 1MByte\n");
        break;
        case Rom2MByte:
            fprintf(stdout, "ROM size - 2MByte\n");
        break;
        case Rom1_1MByte:
            fprintf(stdout, "ROM size - 1.1MByte\n");
        break;
        case Rom1_2MByte:
            fprintf(stdout, "ROM size - 1.22MByte\n");
        break;
        case Rom1_5MByte:
            fprintf(stdout, "ROM size - 1.5MByte\n");
        break;
    }
}

void Cartridge::PrintCartridgeSizeRam()
{
    switch (ROM[RAM_size]) {
        case RamNone:
            fprintf(stdout, "RAM size - none\n");
        break;
        case Ram2kB:
            fprintf(stdout, "RAM size - 2KByte\n");
        break;
        case Ram8kB:
            fprintf(stdout, "RAM size - 8KByte\n");
        break;
        case Ram32kB:
            fprintf(stdout, "RAM size - 32KByte\n");
        break;
        case Ram128kB:
            fprintf(stdout, "RAM size - 128KByte\n");
        break;
    }
}

void Cartridge::ShowCartridgeHeader()
{
    PrintTitle();
    PrintGBorSGBIndicator();
    PrintCartridgeType();    
    PrintCartridgeLang();
    PrintCartridgeSizeRom();
    PrintCartridgeSizeRam();
}

Cartridge::~Cartridge()
{

}
