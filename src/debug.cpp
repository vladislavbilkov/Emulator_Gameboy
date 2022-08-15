#include "debug.h"
#include "cpu.h"
#include <cstdio>
#include <cstring>

#define DEBUG_MSG "\033[1;97mMSG: \033[0m"
#define DEBUG_CPU "\033[1;92mCPU: \033[0m"
#define DEBUG_MMU "\033[1;93mMMU: \033[0m"

const char* Debug::Instructions[0x100] = {
    "NOP",          "LD BC,nn",     "LD (BC),A",    "INC BC",
    "INC B",        "DEC B",        "LD B,n",       "RLCA",
    "LD (nn),SP",   "ADD HL,BC",    "LD A,(BC)",    "DEC BC",
    "INC C",        "DEC C",        "LD C,n",       "RRCA", 
    "STOP",         "LD DE,nn",     "LD (DE),A",    "INC DE",
    "INC D",        "DEC D",        "LD D,n",       "RLA",
    "JR e",         "ADD HL,DE",    "LD A,(DE)",    "DEC DE",
    "INC E",        "DEC E",        "LD E,n",       "RRA",
    "JR NZ,e",      "LD HL, nn",    "LDI (HL), A",  "INC HL",
    "INC H",        "DEC H",        "LD H, n",      "DAA",
    "JR Z, n",      "ADD HL, HL",   "LDI A, (HL)",  "DEC HL",
    "INC L",        "DEC L",        "LD L, n",      "CPL 1",
    "JR NC, n",     "LD SP, nn",    "LDD (HL), A",  "INC SP",
    "INC (HL)",     "DEC (HL)",     "LD (HL), n",   "SCF",
    "JR C, n",      "ADD HL, SP",   "LDD A, (HL)",  "DEC SP",
    "INC A",        "DEC A",        "LD A, n",      "CCF",
    "LD B, B",      "LD B, C",      "LD B, D",      "LD B, E",
    "LD B, H",      "LD B, L",      "LD B, (HL)",   "LD B, A",
    "LD C, B",      "LD C, C",      "LD C, D",      "LD C, E",
    "LD C, H",      "LD C, L",      "LD C, (HL)",   "LD C, A",
    "LD D, B",      "LD D, C",      "LD D, D",      "LD D, E",
    "LD D, H",      "LD D, L",      "LD D, (HL)",   "LD D, A",
    "LD E, B",      "LD E, C",      "LD E, D",      "LD E, E",
    "LD E, H",      "LD E, L",      "LD E, (HL)",   "LD E, A",
    "LD H, B",      "LD H, C",      "LD H, D",      "LD H, E",
    "LD H, H",      "LD H, L",      "LD H, (HL)",   "LD H, A",
    "LD L, B",      "LD L, C",      "LD L, D",      "LD L, E",
    "LD L, H",      "LD L, L",      "LD L, (HL)",   "LD L, A",
    "LD (HL), B",   "LD (HL), C",   "LD (HL), D",   "LD (HL), E",
    "LD (HL), H",   "LD (HL), L",   "HALT",         "LD (HL), A",
    "LD A, B",      "LD A, C",      "LD A, D",      "LD A, E",
    "LD A, H",      "LD A, L",      "LD A, (HL)",   "LD A, A",
    "ADD A, B",     "ADD A, C",     "ADD A, D",     "ADD A, E",
    "ADD A, H",     "ADD A, L",     "ADD A, (HL)",  "ADD A, A",
    "ADC A, B",     "ADC A, C",     "ADC A, D",     "ADC A, E",
    "ADC A, H",     "ADC A, L",     "ADC A, (HL)",  "ADC A, A",
    "SUB A, B",     "SUB A, C",     "SUB A, D",     "SUB A, E",
    "SUB A, H",     "SUB A, L",     "SUB A, (HL)",  "SUB A, A",
    "SBC A, B",     "SBC A, C",     "SBC A, D",     "SBC A, E",
    "SBC A, H",     "SBC A, L",     "SBC A, (HL)",  "SBC A, A",
    "AND B",        "AND C",        "AND D",        "AND E",
    "AND H",        "AND L",        "AND (HL)",     "AND A",
    "XOR B",        "XOR C",        "XOR D",        "XOR E",
    "XOR H",        "XOR L",        "XOR (HL)",     "XOR A",
    "OR B",         "OR C",         "OR D",         "OR E",
    "OR H",         "OR L",         "OR (HL)",      "OR A",
    "CP B",         "CP C",         "CP D",         "CP E",
    "CP H",         "CP L",         "CP (HL)",      "CP A",
    "RET NZ",       "POP BC",       "JP NZ, nn",    "JP nn",
    "CALL NZ, nn",  "PUSH BC",      "ADD A, n",     "RST 00",
    "RET Z",        "RET",          "JP Z, nn",     "CB opcode",
    "CALL Z, nn",   "CALL nn",      "ADC A, n",     "RST 08",
    "RET NC",       "POP DE",       "JP NC, nn",    "?",
    "CALL NC, nn",  "PUSH DE",      "SUB A, n",     "RST 10",
    "RET C",        "RETI",         "JP C, nn",     "?",
    "CALL C, nn",   "?",            "SBC A, n",     "RST 18",
    "LDH (n), A",   "POP HL",       "LDH (C), A",   "?",
    "?",            "PUSH HL",      "AND n",        "RST 20",
    "ADD SP, n",    "JP (HL)",      "LD (nn), A",   "?",
    "?",            "?",            "XOR n",        "RST 28",
    "LDH A, (n)",   "POP AF",       "LD A, (C)",    "DI",
    "?",            "PUSH AF",      "OR n",         "RST 30",
    "LDHL SP, n",   "LD SP, HL",    "LD A, (nn)",   "EI",
    "?",            "?",            "CP n",         "RST 38"    
};

void Debug::Message(const char *msg, ...)
{
    va_list args;
    fprintf(stderr, DEBUG_MSG);
    va_start(args, msg);
    vfprintf(stderr, msg, args);
    va_end(args);
    fprintf(stderr, "\n");
}

void Debug::ShowRegisters(CPU *cpu)
{
    fprintf(stderr, DEBUG_CPU "AF(0x%04X) BC(0x%04X)\n", cpu->AF, cpu->BC);
    fprintf(stderr, DEBUG_CPU "DE(0x%04X) HL(0x%04X)\n", cpu->DE, cpu->HL);
    fprintf(stderr, DEBUG_CPU "SP(0x%04X) PC(0x%04X)\n", cpu->SP, cpu->PC);
    fprintf(stderr, DEBUG_CPU "FLAGS(C:%d H:%d N:%d Z:%d)\n",
            cpu->F & cpu->F_C ? 1 : 0, cpu->F & cpu->F_H ? 1 : 0,
            cpu->F & cpu->F_N ? 1 : 0, cpu->F & cpu->F_Z ? 1 : 0);
}

void Debug::ShowInstruction(CPU *cpu)
{
    fprintf(stderr, DEBUG_CPU "Instruction (0x%02X) %s\n", cpu->Opcode, Instructions[cpu->Opcode]);
}

void Debug::ShowMemAddr(MMU *mmu, char const *area, u16 addr)
{
    fprintf(stderr, DEBUG_MMU "Memory access %s[0x%04X] - (0x%02X)\n", area, addr,
        strcmp(area, "ROM") == 0 ? mmu->cartridge.ROM[addr] :
        strcmp(area, "ROMX") == 0 ? mmu->cartridge.ROM[addr] :
        strcmp(area, "HRAM") == 0 ? mmu->HRAM[addr & 0x007F] :
        strcmp(area, "WRAM") == 0 ? mmu->WRAM[addr & 0x1FFF] : 0);
}
