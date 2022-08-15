#ifndef DEBUG_H
#define DEBUG_H

#include "types.h"
#include <iostream>
#include <cstdarg>
#include <string>

class CPU;
class MMU;

class Debug {
    static const char* Instructions[0x100];

public:
    static void Message(const char*, ...);
    static void ShowRegisters(CPU*);
    static void ShowInstruction(CPU*);
    static void ShowMemAddr(MMU*, const char*, u16);
};

#endif
