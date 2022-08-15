#include "mmu.h"

MMU::MMU(Cartridge &ctg) : cartridge(ctg)
{

}

u8& MMU::operator[](const u16 addr)
{
    switch (addr & 0xF000) {
        // ROM0 (Non-switchable ROM bank)
        case 0x0000:
        case 0x1000:
        case 0x2000:
        case 0x3000:
            Debug::ShowMemAddr(this, "ROM", addr);
            return cartridge.ROM[addr];

        // ROMX (Switchable ROM bank)
        case 0x4000:
        case 0x5000:
        case 0x6000:
        case 0x7000:
            Debug::ShowMemAddr(this, "ROMX", addr);
            return cartridge.ROM[addr];

        // VRAM (Video RAM)
        case 0x8000:
        case 0x9000:

        // SRAM (External RAM)
        case 0xA000:
        case 0xB000:

        // WRAM (Work RAM)
        case 0xC000:
        case 0xD000:
            Debug::ShowMemAddr(this, "WRAM", addr);
            return WRAM[addr & 0x1FFF];

        // ECHO (Echo of 8kB Internal RAM) [E000h – FDFFh]
        case 0xE000:
        // OAM (Sprite information table) [FE00h – FE9Fh]
        // UNUSED [FEA0h – FEFFh]
        // I/O Registers [FF00h – FF7Fh]
        // HRAM (Internal CPU RAM) [FF80h – FFFEh]
        // IE Register [FFFFh]
        case 0xF000:
            Debug::ShowMemAddr(this, "HRAM", addr);
            return HRAM[addr & 0x007F]; // recheck

        default:
            // Unreachable
            return MemBlock;
    }
}
