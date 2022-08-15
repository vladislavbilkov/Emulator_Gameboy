#ifndef CPU_H
#define CPU_H

#include "mmu.h"
#include "types.h"
#include "debug.h"

class CPU {
    //Pair registers
    RegPair PaAF, PaBC, PaDE, PaHL;
    //Pointer for Pair
    u16 &AF = PaAF.Pair;
    u16 &BC = PaBC.Pair;
    u16 &DE = PaDE.Pair;
    u16 &HL = PaHL.Pair;
    //Pointer for registers 
    u8 &A = PaAF.High, &F = PaAF.Low;
    u8 &B = PaBC.High, &C = PaBC.Low;
    u8 &D = PaDE.High, &E = PaDE.Low;
    u8 &H = PaHL.High, &L = PaHL.Low;
    //Stack pointer && Program counter
    u16 SP, PC;

    //Interrupt register
    u8 IE;
    u8 IF;
    u8 IME;
    //Flag masks for F register
    enum F_MASKS {
        F_Z = 0b10000000, // Zero Flag
        F_N = 0b01000000, // Add/Sub Flag (BCD)
        F_H = 0b00100000, // Half Carry Flag (BCD)
        F_C = 0b00010000, // Carry Flag
    };

    //Flag mask for Interrupt
    enum Interrupt_mask {
        V_blank = 0b10000000,
        LCDC_status = 0b01000000,
        Timer_overflow = 0b00100000,
        Serial = 0b00010000,
        Joypad = 0b00001000
    };

    MMU &mmu;

    u8 Opcode;


    void Init();
    
    //work with CPU flag
    inline void SetFlag(F_MASKS flag) { F |= flag; };
    inline void ResetFlag(F_MASKS flag) { F &= ~flag; };
    inline bool GetFlag(F_MASKS flag) { return F & flag; };


    //work with interrupt flag
    inline void ResetInterruptFlag();
    inline bool GetIFFlag(Interrupt_mask mask);
    inline bool GetIEFlag(Interrupt_mask mask);
    inline void InterruptHandler();

    void PushMem16(u16 data);
    u16 PopMem16();

    void WriteMem16(const u16 addr, const u16 data);
    u16 ReadMem16(const u16 addr);

    // Opcodes functions
    void opcode00();
    void opcode01();
    void opcode02();
    void opcode03();
    void opcode04();
    void opcode05();
    void opcode06();
    void opcode07();
    void opcode08();
    void opcode09();
    void opcode0A();
    void opcode0B();
    void opcode0C();
    void opcode0D();
    void opcode0E();
    void opcode0F();
    void opcode10();
    void opcode11();
    void opcode12();
    void opcode13();
    void opcode14();
    void opcode15();
    void opcode16();
    void opcode17();
    void opcode18();
    void opcode19();
    void opcode1A();
    void opcode1B();
    void opcode1C();
    void opcode1D();
    void opcode1E();
    void opcode1F();
    void opcode20();
    void opcode21();
    void opcode22();
    void opcode23();
    void opcode24();
    void opcode25();
    void opcode26();
    void opcode27();
    void opcode28();
    void opcode29();
    void opcode2A();
    void opcode2B();
    void opcode2C();
    void opcode2D();
    void opcode2E();
    void opcode2F();
    void opcode30();
    void opcode31();
    void opcode32();
    void opcode33();
    void opcode34();
    void opcode35();
    void opcode36();
    void opcode37();
    void opcode38();
    void opcode39();
    void opcode3A();
    void opcode3B();
    void opcode3C();
    void opcode3D();
    void opcode3E();
    void opcode3F();
    void opcode40();
    void opcode41();
    void opcode42();
    void opcode43();
    void opcode44();
    void opcode45();
    void opcode46();
    void opcode47();
    void opcode48();
    void opcode49();
    void opcode4A();
    void opcode4B();
    void opcode4C();
    void opcode4D();
    void opcode4E();
    void opcode4F();
    void opcode50();
    void opcode51();
    void opcode52();
    void opcode53();
    void opcode54();
    void opcode55();
    void opcode56();
    void opcode57();
    void opcode58();
    void opcode59();
    void opcode5A();
    void opcode5B();
    void opcode5C();
    void opcode5D();
    void opcode5E();
    void opcode5F();
    void opcode60();
    void opcode61();
    void opcode62();
    void opcode63();
    void opcode64();
    void opcode65();
    void opcode66();
    void opcode67();
    void opcode68();
    void opcode69();
    void opcode6A();
    void opcode6B();
    void opcode6C();
    void opcode6D();
    void opcode6E();
    void opcode6F();
    void opcode70();
    void opcode71();
    void opcode72();
    void opcode73();
    void opcode74();
    void opcode75();
    void opcode76();
    void opcode77();
    void opcode78();
    void opcode79();
    void opcode7A();
    void opcode7B();
    void opcode7C();
    void opcode7D();
    void opcode7E();
    void opcode7F();
    void opcode80();
    void opcode81();
    void opcode82();
    void opcode83();
    void opcode84();
    void opcode85();
    void opcode86();
    void opcode87();
    void opcode88();
    void opcode89();
    void opcode8A();
    void opcode8B();
    void opcode8C();
    void opcode8D();
    void opcode8E();
    void opcode8F();
    void opcode90();
    void opcode91();
    void opcode92();
    void opcode93();
    void opcode94();
    void opcode95();
    void opcode96();
    void opcode97();
    void opcode98();
    void opcode99();
    void opcode9A();
    void opcode9B();
    void opcode9C();
    void opcode9D();
    void opcode9E();
    void opcode9F();
    void opcodeA0();
    void opcodeA1();
    void opcodeA2();
    void opcodeA3();
    void opcodeA4();
    void opcodeA5();
    void opcodeA6();
    void opcodeA7();
    void opcodeA8();
    void opcodeA9();
    void opcodeAA();
    void opcodeAB();
    void opcodeAC();
    void opcodeAD();
    void opcodeAE();
    void opcodeAF();
    void opcodeB0();
    void opcodeB1();
    void opcodeB2();
    void opcodeB3();
    void opcodeB4();
    void opcodeB5();
    void opcodeB6();
    void opcodeB7();
    void opcodeB8();
    void opcodeB9();
    void opcodeBA();
    void opcodeBB();
    void opcodeBC();
    void opcodeBD();
    void opcodeBE();
    void opcodeBF();
    void opcodeC0();
    void opcodeC1();
    void opcodeC2();
    void opcodeC3();
    void opcodeC4();
    void opcodeC5();
    void opcodeC6();
    void opcodeC7();
    void opcodeC8();
    void opcodeC9();
    void opcodeCA();
    void opcodeCB();
    void opcodeCC();
    void opcodeCD();
    void opcodeCE();
    void opcodeCF();
    void opcodeD0();
    void opcodeD1();
    void opcodeD2();
    void opcodeD3();
    void opcodeD4();
    void opcodeD5();
    void opcodeD6();
    void opcodeD7();
    void opcodeD8();
    void opcodeD9();
    void opcodeDA();
    void opcodeDB();
    void opcodeDC();
    void opcodeDD();
    void opcodeDE();
    void opcodeDF();
    void opcodeE0();
    void opcodeE1();
    void opcodeE2();
    void opcodeE3();
    void opcodeE4();
    void opcodeE5();
    void opcodeE6();
    void opcodeE7();
    void opcodeE8();
    void opcodeE9();
    void opcodeEA();
    void opcodeEB();
    void opcodeEC();
    void opcodeED();
    void opcodeEE();
    void opcodeEF();
    void opcodeF0();
    void opcodeF1();
    void opcodeF2();
    void opcodeF3();
    void opcodeF4();
    void opcodeF5();
    void opcodeF6();
    void opcodeF7();
    void opcodeF8();
    void opcodeF9();
    void opcodeFA();
    void opcodeFB();
    void opcodeFC();
    void opcodeFD();
    void opcodeFE();
    void opcodeFF();

    // Opcodes pointer array
    void (CPU::*instr[0x100])() = { 
        &CPU::opcode00,
        &CPU::opcode01,
        &CPU::opcode02,
        &CPU::opcode03,
        &CPU::opcode04,
        &CPU::opcode05,
        &CPU::opcode06,
        &CPU::opcode07,
        &CPU::opcode08,
        &CPU::opcode09,
        &CPU::opcode0A,
        &CPU::opcode0B,
        &CPU::opcode0C,
        &CPU::opcode0D,
        &CPU::opcode0E,
        &CPU::opcode0F,
        &CPU::opcode10,
        &CPU::opcode11,
        &CPU::opcode12,
        &CPU::opcode13,
        &CPU::opcode14,
        &CPU::opcode15,
        &CPU::opcode16,
        &CPU::opcode17,
        &CPU::opcode18,
        &CPU::opcode19,
        &CPU::opcode1A,
        &CPU::opcode1B,
        &CPU::opcode1C,
        &CPU::opcode1D,
        &CPU::opcode1E,
        &CPU::opcode1F,
        &CPU::opcode20,
        &CPU::opcode21,
        &CPU::opcode22,
        &CPU::opcode23,
        &CPU::opcode24,
        &CPU::opcode25,
        &CPU::opcode26,
        &CPU::opcode27,
        &CPU::opcode28,
        &CPU::opcode29,
        &CPU::opcode2A,
        &CPU::opcode2B,
        &CPU::opcode2C,
        &CPU::opcode2D,
        &CPU::opcode2E,
        &CPU::opcode2F,
        &CPU::opcode30,
        &CPU::opcode31,
        &CPU::opcode32,
        &CPU::opcode33,
        &CPU::opcode34,
        &CPU::opcode35,
        &CPU::opcode36,
        &CPU::opcode37,
        &CPU::opcode38,
        &CPU::opcode39,
        &CPU::opcode3A,
        &CPU::opcode3B,
        &CPU::opcode3C,
        &CPU::opcode3D,
        &CPU::opcode3E,
        &CPU::opcode3F,
        &CPU::opcode40,
        &CPU::opcode41,
        &CPU::opcode42,
        &CPU::opcode43,
        &CPU::opcode44,
        &CPU::opcode45,
        &CPU::opcode46,
        &CPU::opcode47,
        &CPU::opcode48,
        &CPU::opcode49,
        &CPU::opcode4A,
        &CPU::opcode4B,
        &CPU::opcode4C,
        &CPU::opcode4D,
        &CPU::opcode4E,
        &CPU::opcode4F,
        &CPU::opcode50,
        &CPU::opcode51,
        &CPU::opcode52,
        &CPU::opcode53,
        &CPU::opcode54,
        &CPU::opcode55,
        &CPU::opcode56,
        &CPU::opcode57,
        &CPU::opcode58,
        &CPU::opcode59,
        &CPU::opcode5A,
        &CPU::opcode5B,
        &CPU::opcode5C,
        &CPU::opcode5D,
        &CPU::opcode5E,
        &CPU::opcode5F,
        &CPU::opcode60,
        &CPU::opcode61,
        &CPU::opcode62,
        &CPU::opcode63,
        &CPU::opcode64,
        &CPU::opcode65,
        &CPU::opcode66,
        &CPU::opcode67,
        &CPU::opcode68,
        &CPU::opcode69,
        &CPU::opcode6A,
        &CPU::opcode6B,
        &CPU::opcode6C,
        &CPU::opcode6D,
        &CPU::opcode6E,
        &CPU::opcode6F,
        &CPU::opcode70,
        &CPU::opcode71,
        &CPU::opcode72,
        &CPU::opcode73,
        &CPU::opcode74,
        &CPU::opcode75,
        &CPU::opcode76,
        &CPU::opcode77,
        &CPU::opcode78,
        &CPU::opcode79,
        &CPU::opcode7A,
        &CPU::opcode7B,
        &CPU::opcode7C,
        &CPU::opcode7D,
        &CPU::opcode7E,
        &CPU::opcode7F,
        &CPU::opcode80,
        &CPU::opcode81,
        &CPU::opcode82,
        &CPU::opcode83,
        &CPU::opcode84,
        &CPU::opcode85,
        &CPU::opcode86,
        &CPU::opcode87,
        &CPU::opcode88,
        &CPU::opcode89,
        &CPU::opcode8A,
        &CPU::opcode8B,
        &CPU::opcode8C,
        &CPU::opcode8D,
        &CPU::opcode8E,
        &CPU::opcode8F,
        &CPU::opcode90,
        &CPU::opcode91,
        &CPU::opcode92,
        &CPU::opcode93,
        &CPU::opcode94,
        &CPU::opcode95,
        &CPU::opcode96,
        &CPU::opcode97,
        &CPU::opcode98,
        &CPU::opcode99,
        &CPU::opcode9A,
        &CPU::opcode9B,
        &CPU::opcode9C,
        &CPU::opcode9D,
        &CPU::opcode9E,
        &CPU::opcode9F,
        &CPU::opcodeA0,
        &CPU::opcodeA1,
        &CPU::opcodeA2,
        &CPU::opcodeA3,
        &CPU::opcodeA4,
        &CPU::opcodeA5,
        &CPU::opcodeA6,
        &CPU::opcodeA7,
        &CPU::opcodeA8,
        &CPU::opcodeA9,
        &CPU::opcodeAA,
        &CPU::opcodeAB,
        &CPU::opcodeAC,
        &CPU::opcodeAD,
        &CPU::opcodeAE,
        &CPU::opcodeAF,
        &CPU::opcodeB0,
        &CPU::opcodeB1,
        &CPU::opcodeB2,
        &CPU::opcodeB3,
        &CPU::opcodeB4,
        &CPU::opcodeB5,
        &CPU::opcodeB6,
        &CPU::opcodeB7,
        &CPU::opcodeB8,
        &CPU::opcodeB9,
        &CPU::opcodeBA,
        &CPU::opcodeBB,
        &CPU::opcodeBC,
        &CPU::opcodeBD,
        &CPU::opcodeBE,
        &CPU::opcodeBF,
        &CPU::opcodeC0,
        &CPU::opcodeC1,
        &CPU::opcodeC2,
        &CPU::opcodeC3,
        &CPU::opcodeC4,
        &CPU::opcodeC5,
        &CPU::opcodeC6,
        &CPU::opcodeC7,
        &CPU::opcodeC8,
        &CPU::opcodeC9,
        &CPU::opcodeCA,
        &CPU::opcodeCB,
        &CPU::opcodeCC,
        &CPU::opcodeCD,
        &CPU::opcodeCE,
        &CPU::opcodeCF,
        &CPU::opcodeD0,
        &CPU::opcodeD1,
        &CPU::opcodeD2,
        &CPU::opcodeD3,
        &CPU::opcodeD4,
        &CPU::opcodeD5,
        &CPU::opcodeD6,
        &CPU::opcodeD7,
        &CPU::opcodeD8,
        &CPU::opcodeD9,
        &CPU::opcodeDA,
        &CPU::opcodeDB,
        &CPU::opcodeDC,
        &CPU::opcodeDD,
        &CPU::opcodeDE,
        &CPU::opcodeDF,
        &CPU::opcodeE0,
        &CPU::opcodeE1,
        &CPU::opcodeE2,
        &CPU::opcodeE3,
        &CPU::opcodeE4,
        &CPU::opcodeE5,
        &CPU::opcodeE6,
        &CPU::opcodeE7,
        &CPU::opcodeE8,
        &CPU::opcodeE9,
        &CPU::opcodeEA,
        &CPU::opcodeEB,
        &CPU::opcodeEC,
        &CPU::opcodeED,
        &CPU::opcodeEE,
        &CPU::opcodeEF,
        &CPU::opcodeF0,
        &CPU::opcodeF1,
        &CPU::opcodeF2,
        &CPU::opcodeF3,
        &CPU::opcodeF4,
        &CPU::opcodeF5,
        &CPU::opcodeF6,
        &CPU::opcodeF7,
        &CPU::opcodeF8,
        &CPU::opcodeF9,
        &CPU::opcodeFA,
        &CPU::opcodeFB,
        &CPU::opcodeFC,
        &CPU::opcodeFD,
        &CPU::opcodeFE,
        &CPU::opcodeFF,
    };

    friend class Debug;

public:    
    CPU(MMU &m);
    
    void Execute();
};

#endif
