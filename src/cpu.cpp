#include "cpu.h"
#include "types.h"

CPU::CPU(MMU &m) : mmu(m)
{
    Init();
}

void CPU::Init()
{
    //DMG
    AF = 0x01B0;
    BC = 0x0013;
    DE = 0x00D8;
    HL = 0x014D;
    SP = 0xFFFE;
    PC = 0x0100;
}

void CPU::Execute()
{
    Debug::Message("***New iteration***");
    Debug::ShowRegisters(this);

    Opcode = mmu[PC++];
    
    Debug::ShowInstruction(this);
    (this->*instr[Opcode])();
}

void CPU::PushMem16(u16 data)
{
    mmu[--SP] = (u8)(data);
    mmu[--SP] = (u8)(data >> 8);
}

u16 CPU::PopMem16()
{
    u8 Low = mmu[SP++];
    u8 High = mmu[SP++];
    return High + (Low << 8);
}

void CPU::WriteMem16(const u16 addr, const u16 data)
{
    mmu[addr] = (u8)(data);
    mmu[addr+1] = (u8)(data >> 8);
}

u16 CPU::ReadMem16(const u16 addr)
{
    u8 High = mmu[addr];
    u8 Low = mmu[addr+1];
    return High + (Low << 8);
}

void CPU::ResetInterruptFlag()
{
    IF = 0;
    IE = 0;
}

bool CPU::GetIEFlag(Interrupt_mask mask)
{
    return IE & mask;
}

bool CPU::GetIFFlag(Interrupt_mask mask)
{
    return IE & mask;
}

void CPU::InterruptHandler()
{
    //Vertical Blank
    if((GetIEFlag(V_blank) && GetIFFlag(V_blank)) && (IME == 1)) {
        //Vector 0040h
    }
    //LCD STAT 
    if((GetIEFlag(LCDC_status) && GetIFFlag(LCDC_status)) && (IME == 1)) {
        //Vector 0048h
    }
    //Timer
    if((GetIEFlag(Timer_overflow) && GetIFFlag(Timer_overflow)) && (IME == 1)) {
        //Vector 0050h
    }
    //Serial
    if((GetIEFlag(Serial) && GetIFFlag(Serial)) && (IME == 1)) {
        //Vector 0058h
    }
    //Joypad
    if((GetIEFlag(Joypad) && GetIFFlag(Joypad)) && (IME == 1)) {
        //Vector 0060h
    }
    
}