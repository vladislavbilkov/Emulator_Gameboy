#ifndef TYPES_H
#define TYPES_H

#include <cstdint>

typedef uint8_t u8;
typedef uint16_t u16;

#define u8max 0xF
#define u16max 0xFF
#define Zero 0x00

#define u8max 0xF
#define u16max 0xFF
#define u24max 0xFFF
#define u32max 0xFFFF
#define Zero 0x00

//pair registers
union RegPair {
    struct {
        u8 Low;
        u8 High;
    };
    u16 Pair;
};

#endif
