#include "cpu.h"
#include "types.h"

void CPU::opcode00() // NOP
{

}

void CPU::opcode01() // LD BC,nn
{
    BC = ReadMem16(PC);
    PC += 2;
}

void CPU::opcode02() // LD (ВС),A
{
    mmu[BC] = A; 
}

void CPU::opcode03() // INC BC
{
    BC++;
}

void CPU::opcode04() // INC B
{
    ResetFlag(F_N);
    if ((B & 0x0F) + 1 > u8max) {
        SetFlag(F_H);
    }
    B++;
    if(B == Zero) {
        SetFlag(F_Z);
    }
}

void CPU::opcode05() // DEC B
{
    SetFlag(F_H);
    if ((B & 0x0F)-1 > u8max) {
        SetFlag(F_H);
    }
    B--;
    if (B == Zero) {
        SetFlag(F_Z);
    }
}
void CPU::opcode06() // LD B, n
{ 
    B = mmu[PC++];
}

void CPU::opcode07() { std::cout << "Not implemented\n"; exit(0); } // RLCA

void CPU::opcode08() // LD (nn),SP
{ 
    WriteMem16(ReadMem16(PC), SP);
    PC +=2;
}

void CPU::opcode09() // ADD HL,BC
{
    ResetFlag(F_N);
    if ((HL & 0x00FF) + (BC & 0x00FF) > u32max) {
        SetFlag(F_C);
    }
    else if ((HL & 0x0FF) + (BC & 0x0FF) > u24max) {
        SetFlag(F_H);
    }
    HL += BC;
    if (HL == Zero) {
        SetFlag(F_Z);
    }
}

void CPU::opcode0A() // LD A,(BC) 
{ 
    A = mmu[BC];
}

void CPU::opcode0B() // DEC BC
{
    BC--;    
}

void CPU::opcode0C() // INC C 
{
    ResetFlag(F_N);
    if ((C & 0x0F) + 1 > u8max) {
        SetFlag(F_H);
    }
    C++;
    if(C == Zero) {
        SetFlag(F_Z);
    }    
} 

void CPU::opcode0D() // DEC C 
{
    SetFlag(F_H);
    if ((C & 0x0F)-1 > u8max) {
        SetFlag(F_H);
    }
    C--;
    if (C == Zero) {
        SetFlag(F_Z);
    }    
}

void CPU::opcode0E() // LD C,n
{ 
    C = mmu[PC++];
}

void CPU::opcode0F() { std::cout << "Not implemented\n"; exit(0); } // RRCA

void CPU::opcode10() { std::cout << "Not implemented\n"; exit(0); } // STOP

void CPU::opcode11() // LD DE,nn
{
    DE = ReadMem16(PC);
    PC += 2;    
}

void CPU::opcode12() // LD DE,A 
{ 
    mmu[DE] = A;
}

void CPU::opcode13() // INC DE
{
    DE++;
}

void CPU::opcode14() // INC D
{
    ResetFlag(F_N);
    if ((D & 0x0F) + 1 > u8max) {
        SetFlag(F_H);
    }
    D++;
    if(D == Zero) {
        SetFlag(F_Z);
    }    
}

void CPU::opcode15() // DEC D
{
    SetFlag(F_H);
    if ((D & 0x0F)-1 > u8max) {
        SetFlag(F_H);
    }
    D--;
    if (D == Zero) {
        SetFlag(F_Z);
    }    
}

void CPU::opcode16() // LD D,n 
{ 
    D = mmu[PC++];
}

void CPU::opcode17() { std::cout << "Not implemented\n"; exit(0); } // RLA

void CPU::opcode18() // JR e
{
    u8 e = mmu[PC++];
    PC += e;
}

void CPU::opcode19() // ADD HL,DE
{
    ResetFlag(F_N);
    if ((HL & 0x00FF) + (DE & 0x00FF) > u32max) {
        SetFlag(F_C);
    }
    else if ((HL & 0x0FF) + (DE & 0x0FF) > u24max) {
        SetFlag(F_H);
    }
    HL += DE;
    if (HL == Zero) {
        SetFlag(F_Z);
    }        
}

void CPU::opcode1A() // LD A,(DE) 
{ 
    A = mmu[DE];
}

void CPU::opcode1B() // DEC DE
{
    DE--;    
}

void CPU::opcode1C() // INC E
{
    ResetFlag(F_N);
    if ((E & 0x0F) + 1 > u8max) {
        SetFlag(F_H);
    }
    E++;
    if(E == Zero) {
        SetFlag(F_Z);
    }    
}

void CPU::opcode1D() // DEC E
{
    SetFlag(F_H);
    if ((E & 0x0F)-1 > u8max) {
        SetFlag(F_H);
    }
    E--;
    if (E == Zero) {
        SetFlag(F_Z);
    }    
}

void CPU::opcode1E() // LD E,n
{ 
    E = mmu[PC++];
}

void CPU::opcode1F() { std::cout << "Not implemented\n"; exit(0); } // RRA

void CPU::opcode20() // JR NZ,e
{
    if (!GetFlag(F_Z)) {
        opcode18();
    }
}

void CPU::opcode21() // LD HL,nn
{
    HL = ReadMem16(PC);
    PC += 2;      
}

void CPU::opcode22() // LD (HL++),A
{ 
    mmu[HL++] = A;
}

void CPU::opcode23() // INC HL
{
    HL++;
}

void CPU::opcode24() // INC H
{
    ResetFlag(F_N);
    if ((H & 0x0F) + 1 > u8max) {
        SetFlag(F_H);
    }
    H++;
    if(H == Zero) {
        SetFlag(F_Z);
    }    
}

void CPU::opcode25() // DEC H
{
    SetFlag(F_H);
    if ((H & 0x0F)-1 > u8max) {
        SetFlag(F_H);
    }
    H--;
    if (H == Zero) {
        SetFlag(F_Z);
    }    
}

void CPU::opcode26() // LD H,n
{ 
     H = mmu[PC++]; 
}

void CPU::opcode27() // DAA 
{
    ResetFlag(F_H);
    if (GetFlag(F_Z)) {
        ResetFlag(F_Z);
    } 
    else {
        SetFlag(F_Z);
    }
    if (GetFlag(F_C)) {
        ResetFlag(F_C);
    } 
    else {
        SetFlag(F_C);
    }
}

void CPU::opcode28() // JR cc,n if flag z is set  
{
    if (GetFlag(F_Z)) {
        opcode18();
    }
}

void CPU::opcode29() // ADD HL,HL
{
    ResetFlag(F_N);
    if ((HL & 0x00FF) + (HL & 0x00FF) > u32max) {
        SetFlag(F_C);
    }
    else if ((HL & 0x0FF) + (HL & 0x0FF) > u24max) {
        SetFlag(F_H);
    }
    HL += HL;
    if (HL == Zero) {
        SetFlag(F_Z);
    }        
}

void CPU::opcode2A() // LD A,(HL+) 
{ 
    A = mmu[HL++];
}

void CPU::opcode2B() // DEC HL
{
    HL--;    
}

void CPU::opcode2C() // INC L
{
    ResetFlag(F_N);
    if ((L & 0x0F) + 1 > u8max) {
        SetFlag(F_H);
    }
    L++;
    if(L == Zero) {
        SetFlag(F_Z);
    }    
}

void CPU::opcode2D() // DEC L
{
    SetFlag(F_H);
    if ((L & 0x0F)-1 > u8max) {
        SetFlag(F_H);
    }
    L--;
    if (L == Zero) {
        SetFlag(F_Z);
    }    
}

void CPU::opcode2E() // LD L,n 
{ 
    L = mmu[PC++];
}

void CPU::opcode2F() // CPL
{
    SetFlag(F_N);
    SetFlag(F_H);
    A = (!A);// Check
}

void CPU::opcode30() // JR cc,n if flag c is reset
{
    if (!GetFlag(F_C)) {
        opcode18();
    }
}

void CPU::opcode31() // LD SP,nn
{
    SP = ReadMem16(PC);
    PC += 2;     
}

void CPU::opcode32() // LDD (HL--),A
{ 
    mmu[HL--] = A;
}

void CPU::opcode33() // INC SP
{
    SP++;
}

void CPU::opcode34() // INC (HL)
{
    ResetFlag(F_N);
    if ((mmu[HL] & 0x0F) + 1 > u8max) {
        SetFlag(F_H);
    }
    mmu[HL]++;
    if(mmu[HL] == Zero) {
        SetFlag(F_Z);
    }    
}

void CPU::opcode35() // DEC (HL)
{
    SetFlag(F_H);
    if ((mmu[HL] & 0x0F)-1 > u8max) {
        SetFlag(F_H);
    }
    mmu[HL]--;
    if (mmu[HL] == Zero) {
        SetFlag(F_Z);
    }    
}

void CPU::opcode36() // LD (HL),n
{
    mmu[HL] = mmu[PC++];      
}

void CPU::opcode37() // SCF 
{
    ResetFlag(F_H);
    ResetFlag(F_N);
    SetFlag(F_C);
}

void CPU::opcode38() // JR cc,n if flag c is set
{
    if (GetFlag(F_C)) {
        opcode18();
    }
}

void CPU::opcode39() // ADD HL,SP
{
    ResetFlag(F_N);
    if ((HL & 0x00FF) + (SP & 0x00FF) > u32max) {
        SetFlag(F_C);
    }
    else if ((HL & 0x0FF) + (SP & 0x0FF) > u24max) {
        SetFlag(F_H);
    }
    HL += SP;
    if (HL == Zero) {
        SetFlag(F_Z);
    }     
}

void CPU::opcode3A() // LD A,(HL--)
{ 
    A = mmu[HL--];
}

void CPU::opcode3B() // DEC SP
{
    SP--;    
}

void CPU::opcode3C() // INC A
{
    ResetFlag(F_N);
    if ((A & 0x0F) + 1 > u8max) {
        SetFlag(F_H);
    }
    A++;
    if(A == Zero) {
        SetFlag(F_Z);
    }    
}

void CPU::opcode3D() // DEC A
{
    SetFlag(F_H);
    if ((A & 0x0F)-1 > u8max) {
        SetFlag(F_H);
    }
    A--;
    if (A == Zero) {
        SetFlag(F_Z);
    }
}

void CPU::opcode3E() // LD A,#
{
    A = mmu[PC++];    
}

void CPU::opcode3F() // CCF 
{
    ResetFlag(F_H);
    ResetFlag(F_N);
    if (GetFlag(F_C)) {
        ResetFlag(F_C);
    } 
    else {
        SetFlag(F_C);
    }
}

void CPU::opcode40() // LD B,B 
{ 

}

void CPU::opcode41() // LD B,C 
{ 
    B = C; 
}

void CPU::opcode42() // LD B,D
{ 
    B = D; 
}

void CPU::opcode43() // LD B,E
{ 
    B = E; 
}

void CPU::opcode44() // LD B,H
{ 
    B = H; 
}

void CPU::opcode45() // LD B,L
{ 
    B = L; 
}

void CPU::opcode46() // LD B,(HL)
{ 
    B = mmu[HL]; 
}

void CPU::opcode47() // LD B,A
{ 
    B = A; 
}

void CPU::opcode48() // LD C,B
{ 
    C = B; 
}

void CPU::opcode49() // LD C,C
{ 

}

void CPU::opcode4A() // LD C,D
{ 
    C = D; 
}

void CPU::opcode4B() // LD C,E
{ 
    C = E; 
}

void CPU::opcode4C() // LD C,H
{ 
    C = H; 
}

void CPU::opcode4D() // LD C,L
{ 
    C = L; 
}

void CPU::opcode4E() // LD C,(HL)
{ 
    C = mmu[HL]; 
}

void CPU::opcode4F() // LD C,A
{ 
    C = A;
}

void CPU::opcode50() // LD D,B 
{ 
    D = B; 
}

void CPU::opcode51() // LD D,C 
{ 
    D = C; 
}

void CPU::opcode52() // LD D,D 
{ 

}

void CPU::opcode53() // LD D,E 
{ 
    D = E; 
}

void CPU::opcode54() // LD D,H 
{ 
    D = H; 
}

void CPU::opcode55() // LD D,L 
{ 
    D = L; 
}
void CPU::opcode56() // LD D,(HL) 
{ 
    D = mmu[HL]; 
}
void CPU::opcode57() // LD D.А 
{ 
    D = A;
}

void CPU::opcode58() // LD E,B 
{ 
    E = B;
}

void CPU::opcode59() // LD E,C 
{ 
    E = C;
}

void CPU::opcode5A() // LD E,D 
{ 
    E = D;
}

void CPU::opcode5B() // LD E,E 
{ 
    
}

void CPU::opcode5C() // LD E,H 
{ 
    E = H;
}

void CPU::opcode5D() // LD E,L
{ 
    E = L;
}

void CPU::opcode5E() // LD E,(HL)
{ 
    E = mmu[HL];
}
void CPU::opcode5F() // LD E,A 
{ 
    E = A;
}

void CPU::opcode60() // LD H,B
{ 
    H = B;
}

void CPU::opcode61() // LD H,C 
{ 
    H = C;
}

void CPU::opcode62() // LD H,D 
{ 
    H = D;
}

void CPU::opcode63() // LD H,E 
{ 
    H = E;
}
void CPU::opcode64() // LD H,H 
{ 
    
}

void CPU::opcode65() // LD H,L 
{ 
    H = L;
}
void CPU::opcode66() // LD H,(HL) 
{ 
    H = mmu[HL];
}
void CPU::opcode67() // LD L,A
{ 
    H = A;
}
void CPU::opcode68() // LD L,B 
{ 
    L = B;
}
void CPU::opcode69() // LD L,B 
{ 
    L = C;
}
void CPU::opcode6A() // LD L,D 
{ 
    L = D;
}
void CPU::opcode6B() // LD L,E 
{ 
    L = E;
}
void CPU::opcode6C() // LD L,H 
{ 
    L = H;
}
void CPU::opcode6D() // LD L,L 
{ 
    
}
void CPU::opcode6E() // LD L,(HL) 
{ 
    L = mmu[HL];
}
void CPU::opcode6F() // LD L,A 
{ 
    L = A;
}
void CPU::opcode70() // LD (HL),B 
{ 
    mmu[HL] = B;
}
void CPU::opcode71() // LD (HL),C 
{ 
    mmu[HL] = C;
}
void CPU::opcode72() // LD (HL),D 
{ 
    mmu[HL] = D;
}
void CPU::opcode73() // LD (HL),E 
{ 
    mmu[HL] = E;
}
void CPU::opcode74() // LD (HL),H 
{ 
    mmu[HL] = H;
}
void CPU::opcode75() // LD (HL),L 
{ 
    mmu[HL] = L;
}
void CPU::opcode76() { std::cout << "Not implemented\n"; exit(0); } //HALT
void CPU::opcode77() // LD (HL),A 
{ 
    mmu[HL] = A;
}
void CPU::opcode78() // LD A,B 
{ 
    A = B;
}
void CPU::opcode79() // LD A,C 
{ 
    A = C;
}
void CPU::opcode7A() // LD A,D 
{ 
    A = D;
}
void CPU::opcode7B() // LD A,E 
{ 
    A = E;
}
void CPU::opcode7C() // LD A,H 
{ 
    A = H;
}
void CPU::opcode7D() // LD A,L 
{ 
    A = L;
}
void CPU::opcode7E() // LD A,(HL) 
{ 
    A = mmu[HL];
}
void CPU::opcode7F() // LD A,A
{
    
}
void CPU::opcode80() // ADD A,B 
{
    ResetFlag(F_N);
    if ((A & 0x00F) + (B & 0x00F) > u16max) {
        SetFlag(F_C);
    }
    else if ((A & 0x0F) + (B & 0x0F) > u8max) {
        SetFlag(F_H);
    }
    A += B;
    if (A == Zero) {
        SetFlag(F_Z);
    }
}
void CPU::opcode81() // ADD A,C 
{
    ResetFlag(F_N);
    if ((A & 0x00F) + (C & 0x00F) > u16max) {
        SetFlag(F_C);
    }
    else if ((A & 0x0F) + (C & 0x0F) > u8max) {
        SetFlag(F_H);
    }
    A += C;
    if (A == Zero) {
        SetFlag(F_Z);
    }
}
void CPU::opcode82() // ADD A,D 
{
    ResetFlag(F_N);
    if ((A & 0x00F) + (D & 0x00F) > u16max) {
        SetFlag(F_C);
    }
    else if ((A & 0x0F) + (D & 0x0F) > u8max) {
        SetFlag(F_H);
    }
    A += D;
    if (A == Zero) {
        SetFlag(F_Z);
    }
}
void CPU::opcode83() // ADD A,E 
{
    ResetFlag(F_N);
    if ((A & 0x00F) + (E & 0x00F) > u16max) {
        SetFlag(F_C);
    }
    else if ((A & 0x0F) + (E & 0x0F) > u8max) {
        SetFlag(F_H);
    }
    A += E;
    if (A == Zero) {
        SetFlag(F_Z);
    }
}
void CPU::opcode84() // ADD A,H 
{
    ResetFlag(F_N);
    if ((A & 0x00F) + (H & 0x00F) > u16max) {
        SetFlag(F_C);
    }
    else if ((A & 0x0F) + (H & 0x0F) > u8max) {
        SetFlag(F_H);
    }
    A += H;
    if (A == Zero) {
        SetFlag(F_Z);
    }
}
void CPU::opcode85() // ADD A,L 
{
    ResetFlag(F_N);
    if ((A & 0x00F) + (L & 0x00F) > u16max) {
        SetFlag(F_C);
    }
    else if ((A & 0x0F) + (L & 0x0F) > u8max) {
        SetFlag(F_H);
    }
    A += L;
    if (A == Zero) {
        SetFlag(F_Z);
    }
}
void CPU::opcode86() // ADD A,(HL) 
{
    ResetFlag(F_N);
    u8 data = mmu[HL];
    if ((A & 0x00F) + (data & 0x00F) > u16max) {
        SetFlag(F_C);
    }
    else if ((A & 0x0F) + (data & 0x0F) > u8max) {
        SetFlag(F_H);
    }
    A += data;
    if (A == Zero) {
        SetFlag(F_Z);
    }
}
void CPU::opcode87() // ADD A,A 
{
    ResetFlag(F_N);
    if ((A & 0x00F) + (A & 0x00F) > u16max) {
        SetFlag(F_C);
    }
    else if ((A & 0x0F) + (A & 0x0F) > u8max) {
        SetFlag(F_H);
    }
    A += A;
    if (A == Zero) {
        SetFlag(F_Z);
    }
}
void CPU::opcode88() // ADC A,B
{
    u8 tmp = B + (F & F_C);
    ResetFlag(F_N);
    if ((A & 0x00F) + (tmp & 0x00F) > u16max) {
        SetFlag(F_C);
    }
    else if ((A & 0x0F) + (tmp & 0x0F) > u8max) {
        SetFlag(F_H);
    }
    A += tmp;
    if (A == Zero) {
        SetFlag(F_Z);
    }
}
void CPU::opcode89() // ADC A,C
{
    u8 tmp = C + (F & F_C);
    ResetFlag(F_N);
    if ((A & 0x00F) + (tmp & 0x00F) > u16max) {
        SetFlag(F_C);
    }
    else if ((A & 0x0F) + (tmp & 0x0F) > u8max) {
        SetFlag(F_H);
    }
    A += tmp;
    if (A == Zero) {
        SetFlag(F_Z);
    }    
}
void CPU::opcode8A() // ADC A,D
{
    u8 tmp = D + (F & F_C);
    ResetFlag(F_N);
    if ((A & 0x00F) + (tmp & 0x00F) > u16max) {
        SetFlag(F_C);
    }
    else if ((A & 0x0F) + (tmp & 0x0F) > u8max) {
        SetFlag(F_H);
    }
    A += tmp;
    if (A == Zero) {
        SetFlag(F_Z);
    }    
}
void CPU::opcode8B() // ADC A,E
{
    u8 tmp = E + (F & F_C);
    ResetFlag(F_N);
    if ((A & 0x00F) + (tmp & 0x00F) > u16max) {
        SetFlag(F_C);
    }
    else if ((A & 0x0F) + (tmp & 0x0F) > u8max) {
        SetFlag(F_H);
    }
    A += tmp;
    if (A == Zero) {
        SetFlag(F_Z);
    }    
}
void CPU::opcode8C() // ADC A,H
{
    u8 tmp = H + (F & F_C);
    ResetFlag(F_N);
    if ((A & 0x00F) + (tmp & 0x00F) > u16max) {
        SetFlag(F_C);
    }
    else if ((A & 0x0F) + (tmp & 0x0F) > u8max) {
        SetFlag(F_H);
    }
    A += tmp;
    if (A == Zero) {
        SetFlag(F_Z);
    }    
}
void CPU::opcode8D() // ADC A,L
{
    u8 tmp = L + (F & F_C);
    ResetFlag(F_N);
    if ((A & 0x00F) + (tmp & 0x00F) > u16max) {
        SetFlag(F_C);
    }
    else if ((A & 0x0F) + (tmp & 0x0F) > u8max) {
        SetFlag(F_H);
    }
    A += tmp;
    if (A == Zero) {
        SetFlag(F_Z);
    }    
}
void CPU::opcode8E() // ADC A,(HL)
{
    u8 tmp = mmu[HL] + (F & F_C);
    ResetFlag(F_N);
    if ((A & 0x00F) + (tmp & 0x00F) > u16max) {
        SetFlag(F_C);
    }
    else if ((A & 0x0F) + (tmp & 0x0F) > u8max) {
        SetFlag(F_H);
    }
    A += tmp;
    if (A == Zero) {
        SetFlag(F_Z);
    }    
}
void CPU::opcode8F() // ADC A,A
{
    u8 tmp = A + (F & F_C);
    ResetFlag(F_N);
    if ((A & 0x00F) + (tmp & 0x00F) > u16max) {
        SetFlag(F_C);
    }
    else if ((A & 0x0F) + (tmp & 0x0F) > u8max) {
        SetFlag(F_H);
    }
    A += tmp;
    if (A == Zero) {
        SetFlag(F_Z);
    }    
}
void CPU::opcode90() // SUB B
{
    SetFlag(F_N);
    if ((A & 0x00F) - (B & 0x00F) > u16max) {
        SetFlag(F_C);
    }
    else if ((A & 0x0F) - (B & 0x0F) > u8max) {
        SetFlag(F_H);
    }
    A -= B;
    if (A == Zero) {
        SetFlag(F_Z);
    }
}
void CPU::opcode91() // SUB C
{    
    SetFlag(F_N);
    if ((A & 0x00F) - (C & 0x00F) > u16max) {
        SetFlag(F_C);
    }
    else if ((A & 0x0F) - (C & 0x0F) > u8max) {
        SetFlag(F_H);
    }
    A -= C;
    if (A == Zero) {
        SetFlag(F_Z);
    }    
}
void CPU::opcode92() // SUB D
{
    SetFlag(F_N);
    if ((A & 0x00F) - (D & 0x00F) > u16max) {
        SetFlag(F_C);
    }
    else if ((A & 0x0F) - (D & 0x0F) > u8max) {
        SetFlag(F_H);
    }
    A -= D;
    if (A == Zero) {
        SetFlag(F_Z);
    }    
}
void CPU::opcode93() // SUB E
{
    SetFlag(F_N);
    if ((A & 0x00F) - (E & 0x00F) > u16max) {
        SetFlag(F_C);
    }
    else if ((A & 0x0F) - (E & 0x0F) > u8max) {
        SetFlag(F_H);
    }
    A -= E;
    if (A == Zero) {
        SetFlag(F_Z);
    }    
}
void CPU::opcode94() // SUB H
{
    SetFlag(F_N);
    if ((A & 0x00F) - (H & 0x00F) > u16max) {
        SetFlag(F_C);
    }
    else if ((A & 0x0F) - (H & 0x0F) > u8max) {
        SetFlag(F_H);
    }
    A -= H;
    if (A == Zero) {
        SetFlag(F_Z);
    }    
}
void CPU::opcode95() // SUB L
{
    SetFlag(F_N);
    if ((A & 0x00F) - (L & 0x00F) > u16max) {
        SetFlag(F_C);
    }
    else if ((A & 0x0F) - (L & 0x0F) > u8max) {
        SetFlag(F_H);
    }
    A -= L;
    if (A == Zero) {
        SetFlag(F_Z);
    }    
}
void CPU::opcode96() // SUB (HL)
{
    SetFlag(F_N);
    if ((A & 0x00F) - (mmu[HL] & 0x00F) > u16max) {
        SetFlag(F_C);
    }
    else if ((A & 0x0F) - (mmu[HL] & 0x0F) > u8max) {
        SetFlag(F_H);
    }
    A -= mmu[HL];
    if (A == Zero) {
        SetFlag(F_Z);
    }    
}
void CPU::opcode97() // SUB A
{
    SetFlag(F_N);
    if ((A & 0x00F) - (A & 0x00F) > u16max) {
        SetFlag(F_C);
    }
    else if ((A & 0x0F) - (A & 0x0F) > u8max) {
        SetFlag(F_H);
    }
    A -= A;
    if (A == Zero) {
        SetFlag(F_Z);
    }    
}
void CPU::opcode98() // SBC A,B
{
    u8 tmp = B + (F & F_C);
    SetFlag(F_N);
    if ((A & 0x00F) - (tmp & 0x00F) > u16max) {
        SetFlag(F_C);
    }
    else if ((A & 0x0F) - (tmp & 0x0F) > u8max) {
        SetFlag(F_H);
    }
    A -= tmp;
    if (A == Zero) {
        SetFlag(F_Z);
    }
}
void CPU::opcode99() // SBC A,C
{
    u8 tmp = C + (F & F_C);
    SetFlag(F_N);
    if ((A & 0x00F) - (tmp & 0x00F) > u16max) {
        SetFlag(F_C);
    }
    else if ((A & 0x0F) - (tmp & 0x0F) > u8max) {
        SetFlag(F_H);
    }
    A -= tmp;
    if (A == Zero) {
        SetFlag(F_Z);
    }    
}
void CPU::opcode9A() // SBC A,D
{
    u8 tmp = D + (F & F_C);
    SetFlag(F_N);
    if ((A & 0x00F) - (tmp & 0x00F) > u16max) {
        SetFlag(F_C);
    }
    else if ((A & 0x0F) - (tmp & 0x0F) > u8max) {
        SetFlag(F_H);
    }
    A -= tmp;
    if (A == Zero) {
        SetFlag(F_Z);
    }    
}
void CPU::opcode9B() // SBC A,E
{
    u8 tmp = E + (F & F_C);
    SetFlag(F_N);
    if ((A & 0x00F) - (tmp & 0x00F) > u16max) {
        SetFlag(F_C);
    }
    else if ((A & 0x0F) - (tmp & 0x0F) > u8max) {
        SetFlag(F_H);
    }
    A -= tmp;
    if (A == Zero) {
        SetFlag(F_Z);
    }    
}
void CPU::opcode9C() // SBC A,H
{
    u8 tmp = H + (F & F_C);
    SetFlag(F_N);
    if ((A & 0x00F) - (tmp & 0x00F) > u16max) {
        SetFlag(F_C);
    }
    else if ((A & 0x0F) - (tmp & 0x0F) > u8max) {
        SetFlag(F_H);
    }
    A -= tmp;
    if (A == Zero) {
        SetFlag(F_Z);
    }    
}
void CPU::opcode9D() // SBC A,L
{
    u8 tmp = L + (F & F_C);
    SetFlag(F_N);
    if ((A & 0x00F) - (tmp & 0x00F) > u16max) {
        SetFlag(F_C);
    }
    else if ((A & 0x0F) - (tmp & 0x0F) > u8max) {
        SetFlag(F_H);
    }
    A -= tmp;
    if (A == Zero) {
        SetFlag(F_Z);
    }    
}
void CPU::opcode9E() // SBC A,(HL)
{
    u8 tmp = mmu[HL] + (F & F_C);
    SetFlag(F_N);
    if ((A & 0x00F) - (tmp & 0x00F) > u16max) {
        SetFlag(F_C);
    }
    else if ((A & 0x0F) - (tmp & 0x0F) > u8max) {
        SetFlag(F_H);
    }
    A -= tmp;
    if (A == Zero) {
        SetFlag(F_Z);
    }    
}
void CPU::opcode9F() // SBC A,n
{
    u8 tmp = B + (F & F_C);
    SetFlag(F_N);
    if ((A & 0x00F) - (tmp & 0x00F) > u16max) {
        SetFlag(F_C);
    }
    else if ((A & 0x0F) - (tmp & 0x0F) > u8max) {
        SetFlag(F_H);
    }
    A -= tmp;
    if (A == Zero) {
        SetFlag(F_Z);
    }    
}
void CPU::opcodeA0() // AND B 
{    
    ResetFlag(F_C);
    ResetFlag(F_N);
    SetFlag(F_H);
    A &= B;
    if (A == Zero) {
        SetFlag(F_Z);
    }
}
void CPU::opcodeA1() // AND C
{
    ResetFlag(F_C);
    ResetFlag(F_N);
    SetFlag(F_H);
    A &= C;
    if (A == Zero) {
        SetFlag(F_Z);
    }
}
void CPU::opcodeA2() // AND D
{
    ResetFlag(F_C);
    ResetFlag(F_N);
    SetFlag(F_H);
    A &= D;
    if (A == Zero) {
        SetFlag(F_Z);
    }
}
void CPU::opcodeA3() // AND E
{
    ResetFlag(F_C);
    ResetFlag(F_N);
    SetFlag(F_H);
    A &= E;
    if (A == Zero) {
        SetFlag(F_Z);
    }
}
void CPU::opcodeA4() // AND H
{
    ResetFlag(F_C);
    ResetFlag(F_N);
    SetFlag(F_H);
    A &= H;
    if (A == Zero) {
        SetFlag(F_Z);
    }
}
void CPU::opcodeA5() // AND L
{
    ResetFlag(F_C);
    ResetFlag(F_N);
    SetFlag(F_H);
    A &= L;
    if (A == Zero) {
        SetFlag(F_Z);
    }
}
void CPU::opcodeA6() // AND (HL)
{
    ResetFlag(F_C);
    ResetFlag(F_N);
    SetFlag(F_H);
    A &= mmu[HL];
    if (A == Zero) {
        SetFlag(F_Z);
    }
}
void CPU::opcodeA7() // AND A
{
    ResetFlag(F_C);
    ResetFlag(F_N);
    SetFlag(F_H);
    A &= A;
    if (A == Zero) {
        SetFlag(F_Z);
    }
}
void CPU::opcodeA8() // XOR B
{
    ResetFlag(F_N);
    ResetFlag(F_H);
    ResetFlag(F_C);
    A ^= B;
    if (A == Zero) {
        SetFlag(F_Z);
    }       
}
void CPU::opcodeA9() // XOR C 
{
    ResetFlag(F_N);
    ResetFlag(F_H);
    ResetFlag(F_C);
    A ^= C;
    if (A == Zero) {
        SetFlag(F_Z);
    }       
}
void CPU::opcodeAA() // XOR D 
{
    ResetFlag(F_N);
    ResetFlag(F_H);
    ResetFlag(F_C);
    A ^= D;
    if (A == Zero) {
        SetFlag(F_Z);
    }       
}
void CPU::opcodeAB() // XOR E 
{
    ResetFlag(F_N);
    ResetFlag(F_H);
    ResetFlag(F_C);
    A ^= E;
    if (A == Zero) {
        SetFlag(F_Z);
    }       
}
void CPU::opcodeAC() // XOR H 
{
    ResetFlag(F_N);
    ResetFlag(F_H);
    ResetFlag(F_C);
    A ^= H;
    if (A == Zero) {
        SetFlag(F_Z);
    }       
}
void CPU::opcodeAD() // XOR L 
{
    ResetFlag(F_N);
    ResetFlag(F_H);
    ResetFlag(F_C);
    A ^= L;
    if (A == Zero) {
        SetFlag(F_Z);
    }       
}
void CPU::opcodeAE() // XOR (HL)
{
    ResetFlag(F_N);
    ResetFlag(F_H);
    ResetFlag(F_C);
    A ^= mmu[HL];
    if (A == Zero) {
        SetFlag(F_Z);
    }       
}
void CPU::opcodeAF() // XOR A 
{
    ResetFlag(F_N);
    ResetFlag(F_H);
    ResetFlag(F_C);
    A ^= A;
    if (A == Zero) {
        SetFlag(F_Z);
    }       
}
void CPU::opcodeB0() // OR B 
{
    ResetFlag(F_N);
    ResetFlag(F_H);
    ResetFlag(F_C);
    A |= B;
    if(A == Zero) {
        SetFlag(F_Z);
    }
}
void CPU::opcodeB1() // OR C 
{
    ResetFlag(F_N);
    ResetFlag(F_H);
    ResetFlag(F_C);
    A |= C;
    if(A == Zero) {
        SetFlag(F_Z);
    }
}
void CPU::opcodeB2() // OR D 
{
    ResetFlag(F_N);
    ResetFlag(F_H);
    ResetFlag(F_C);
    A |= D;
    if(A == Zero) {
        SetFlag(F_Z);
    }
}
void CPU::opcodeB3() // OR E 
{
    ResetFlag(F_N);
    ResetFlag(F_H);
    ResetFlag(F_C);
    A |= E;
    if(A == Zero) {
        SetFlag(F_Z);
    }
}
void CPU::opcodeB4() // OR H 
{
    ResetFlag(F_N);
    ResetFlag(F_H);
    ResetFlag(F_C);
    A |= H;
    if(A == Zero) {
        SetFlag(F_Z);
    }
}
void CPU::opcodeB5() // OR L 
{
    ResetFlag(F_N);
    ResetFlag(F_H);
    ResetFlag(F_C);
    A |= L;
    if(A == Zero) {
        SetFlag(F_Z);
    }
}
void CPU::opcodeB6() // OR (HL) 
{
    ResetFlag(F_N);
    ResetFlag(F_H);
    ResetFlag(F_C);
    A |= mmu[HL];
    if(A == Zero) {
        SetFlag(F_Z);
    }
}
void CPU::opcodeB7() // OR A 
{
    ResetFlag(F_N);
    ResetFlag(F_H);
    ResetFlag(F_C);
    A |= A;
    if(A == Zero) {
        SetFlag(F_Z);
    }
}
void CPU::opcodeB8() // CP B
{
    SetFlag(F_N);
    if(B == Zero){
        SetFlag(F_Z);
    }
    if ((B & 0x00F)  > u16max) {
        SetFlag(F_C);
    }
    else if ((B & 0x0F)  > u8max) {
        SetFlag(F_H);
    }
}
void CPU::opcodeB9() // CP C
{
    SetFlag(F_N);
    if(C == Zero){
        SetFlag(F_Z);
    }
    if ((C & 0x00F)  > u16max) {
        SetFlag(F_C);
    }
    else if ((C & 0x0F)  > u8max) {
        SetFlag(F_H);
    }
}
void CPU::opcodeBA() // CP D 
{
    SetFlag(F_N);
    if(D == Zero){
        SetFlag(F_Z);
    }
    if ((D & 0x00F)  > u16max) {
        SetFlag(F_C);
    }
    else if ((D & 0x0F)  > u8max) {
        SetFlag(F_H);
    }
}
void CPU::opcodeBB() // CP E
{
    SetFlag(F_N);
    if(E == Zero){
        SetFlag(F_Z);
    }
    if ((E & 0x00F)  > u16max) {
        SetFlag(F_C);
    }
    else if ((E & 0x0F)  > u8max) {
        SetFlag(F_H);
    }    
}
void CPU::opcodeBC() // CP H 
{
    SetFlag(F_N);
    if(H == Zero){
        SetFlag(F_Z);
    }
    if ((H & 0x00F)  > u16max) {
        SetFlag(F_C);
    }
    else if ((H & 0x0F)  > u8max) {
        SetFlag(F_H);
    }    
}
void CPU::opcodeBD() // CP L
{
    SetFlag(F_N);
    if(L == Zero){
        SetFlag(F_Z);
    }
    if ((L & 0x00F)  > u16max) {
        SetFlag(F_C);
    }
    else if ((L & 0x0F)  > u8max) {
        SetFlag(F_H);
    }
}
void CPU::opcodeBE() // CP (HL)
{
    u8 tmp = mmu[HL];
    SetFlag(F_N);
    if(tmp == Zero){
        SetFlag(F_Z);
    }
    if ((tmp & 0x00F)  > u16max) {
        SetFlag(F_C);
    }
    else if ((tmp & 0x0F)  > u8max) {
        SetFlag(F_H);
    }
}
void CPU::opcodeBF() // CP A
{
    
}
void CPU::opcodeC0() // RET cc if Z flag is reset
{
    if (!GetFlag(F_Z)) {
        opcodeC9();
    }    
}
void CPU::opcodeC1() // POP BC 
{
    BC = PopMem16();
}
void CPU::opcodeC2() // JP cc,nn if z flag is reset
{
    if (!GetFlag(F_Z)) {
        PC = ReadMem16(PC);
    }
}
void CPU::opcodeC3() // JP nn 
{
    PC = ReadMem16(PC);
}
void CPU::opcodeC4() // CALL cc,nn if z flag is reset
{
    if (!GetFlag(F_Z)) {
        opcodeCD();
    }
}
void CPU::opcodeC5() // PUSH BC 
{ 
    PushMem16(BC);
}
void CPU::opcodeC6() // ADD A,# 
{
    ResetFlag(F_N);
    u8 data = mmu[PC++];
    if ((A & 0x00F) + (data & 0x00F) > u16max) {
        SetFlag(F_C);
    }
    else if ((A & 0x0F) + (data & 0x0F) > u8max) {
        SetFlag(F_H);
    }
    A += data;
    if (A == Zero) {
        SetFlag(F_Z);
    }
}
void CPU::opcodeC7() { std::cout << "Not implemented\n"; exit(0); } // RST n
void CPU::opcodeC8() // RET cc if Z flag is set 
{
    if (GetFlag(F_Z)) {
        opcodeC9();
    }  
}
void CPU::opcodeC9() // RET 
{
    PC = ReadMem16(SP);
    SP += 2;
}
void CPU::opcodeCA() // JP cc,nn if z flag is set 
{
    if (GetFlag(F_Z)) {
        PC = ReadMem16(PC);
    }
}
void CPU::opcodeCB() { std::cout << "Not implemented\n"; exit(0); } //
void CPU::opcodeCC() // CALL cc,nn if z flag is set 
{
    if (GetFlag(F_Z)) {
        opcodeCD();
    }
}
void CPU::opcodeCD() // CALL nn 
{
    u16 nn = ReadMem16(PC); 
    PC += 2;
    PushMem16(PC);
    PC = nn;
}
void CPU::opcodeCE() // ADC A,#
{
    u8 tmp = mmu[PC++] + (F & F_C);
    ResetFlag(F_N);
    if ((A & 0x00F) + (tmp & 0x00F) > u16max) {
        SetFlag(F_C);
    }
    else if ((A & 0x0F) + (tmp & 0x0F) > u8max) {
        SetFlag(F_H);
    }
    A += tmp;
    if (A == Zero) {
        SetFlag(F_Z);
    }    
}
void CPU::opcodeCF() { std::cout << "Not implemented\n"; exit(0); } // RST n
void CPU::opcodeD0() // RET cc if C flag is reset 
{
    if (!GetFlag(F_C)) {
        opcodeC9();
    }  
}
void CPU::opcodeD1() // POP DE
{
    DE = PopMem16();
}
void CPU::opcodeD2() // JP cc,nn if c flag is reset 
{
    if (!GetFlag(F_C)) {
        PC = ReadMem16(PC);
    }
}
void CPU::opcodeD3() { std::cout << "Not implemented\n"; exit(0); } //
void CPU::opcodeD4() // CALL cc,nn if C flag is reset 
{
    if (!GetFlag(F_C)) {
        opcodeCD();
    }
}
void CPU::opcodeD5() // PUSH DE 
{
    PushMem16(DE);
}
void CPU::opcodeD6() // SUB #
{
    SetFlag(F_N);
    if ((A & 0x00F) - (mmu[PC] & 0x00F) > u16max) {
        SetFlag(F_C);
    }
    else if ((A & 0x0F) - (mmu[PC] & 0x0F) > u8max) {
        SetFlag(F_H);
    }
    A -= mmu[PC++];
    if (A == Zero) {
        SetFlag(F_Z);
    }    
}
void CPU::opcodeD7() { std::cout << "Not implemented\n"; exit(0); } // RST n
void CPU::opcodeD8() // RET cc if C flag is set 
{
    if (GetFlag(F_C)) {
        opcodeC9();
    }  
}
void CPU::opcodeD9() { std::cout << "Not implemented\n"; exit(0); } // RETI
void CPU::opcodeDA() // JP cc,nn if c flag is set
{
    if (GetFlag(F_C)) {
        PC = ReadMem16(PC);
    }
}
void CPU::opcodeDB() { std::cout << "Not implemented\n"; exit(0); } //
void CPU::opcodeDC() // CALL cc,nn if C flag is set 
{
    if (GetFlag(F_C)) {
        opcodeCD();
    }
}
void CPU::opcodeDD() { std::cout << "Not implemented\n"; exit(0); } //
void CPU::opcodeDE() { std::cout << "Not implemented\n"; exit(0); } //
void CPU::opcodeDF() { std::cout << "Not implemented\n"; exit(0); } // RST n
void CPU::opcodeE0() { std::cout << "Not implemented\n"; exit(0); } // LDH (n),A
void CPU::opcodeE1() // POP HL 
{
    HL = PopMem16();
}
void CPU::opcodeE2() { std::cout << "Not implemented\n"; exit(0); } // LD (C),A
void CPU::opcodeE3() { std::cout << "Not implemented\n"; exit(0); } //
void CPU::opcodeE4() { std::cout << "Not implemented\n"; exit(0); } //
void CPU::opcodeE5() // PUSH HL 
{
    PushMem16(HL);
}
void CPU::opcodeE6() // AND #
{
    ResetFlag(F_C);
    ResetFlag(F_N);
    SetFlag(F_H);
    A &= mmu[PC++];
    if (A == Zero) {
        SetFlag(F_Z);
    }
}
void CPU::opcodeE7() { std::cout << "Not implemented\n"; exit(0); } // RST n
void CPU::opcodeE8() { std::cout << "Not implemented\n"; exit(0); } // ADD SP,n
void CPU::opcodeE9() // JP (HL) 
{
    PC = HL;
}
void CPU::opcodeEA() // LD nn,A 
{ 
    mmu[ReadMem16(PC)] = A;
    PC += 2;
}
void CPU::opcodeEB() { std::cout << "Not implemented\n"; exit(0); } //

void CPU::opcodeEC() { std::cout << "Not implemented\n"; exit(0); } //

void CPU::opcodeED() { std::cout << "Not implemented\n"; exit(0); } //

void CPU::opcodeEE() // XOR #
{
    ResetFlag(F_N);
    ResetFlag(F_H);
    ResetFlag(F_C);
    A ^= mmu[PC++];
    if (A == Zero) {
        SetFlag(F_Z);
    } 
}

void CPU::opcodeEF() { std::cout << "Not implemented\n"; exit(0); } // RST n

void CPU::opcodeF0() { std::cout << "Not implemented\n"; exit(0); } // LDH A,(n)

void CPU::opcodeF1() // POP AF 
{
    AF = PopMem16();
}

void CPU::opcodeF2() { std::cout << "Not implemented\n"; exit(0); } // LD A,(C)

void CPU::opcodeF3() // DI 
{
    IME = 0;
}

void CPU::opcodeF4() { std::cout << "Not implemented\n"; exit(0); } //

void CPU::opcodeF5() // PUSH AF 
{
    PushMem16(AF);
}

void CPU::opcodeF6() // OR #
{
    ResetFlag(F_N);
    ResetFlag(F_H);
    ResetFlag(F_C);
    A |= mmu[PC++];
    if(A == Zero) {
        SetFlag(F_Z);
    }
}

void CPU::opcodeF7() { std::cout << "Not implemented\n"; exit(0); } // RST n

void CPU::opcodeF8() { std::cout << "Not implemented\n"; exit(0); } // LDHL SP,n

void CPU::opcodeF9() // LD SP,HL 
{
     SP = HL;
}

void CPU::opcodeFA() // LD A,(nn) 
{ 
    A = mmu[ReadMem16(PC)];
    PC += 2;
}

void CPU::opcodeFB() { std::cout << "Not implemented\n"; exit(0); } // EI

void CPU::opcodeFC() { std::cout << "Not implemented\n"; exit(0); } //

void CPU::opcodeFD() { std::cout << "Not implemented\n"; exit(0); } //

void CPU::opcodeFE() // CP  
{
    
}

void CPU::opcodeFF() { std::cout << "Not implemented\n"; exit(0); } // RST n
