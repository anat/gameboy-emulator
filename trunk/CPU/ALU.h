#ifndef ALU_H
#define ALU_H

#include "Register.h"
#include "CPU.h"
#include <iostream>

using namespace std;

class ALU : virtual public Register
{
public:
    uint8_t* memory;

    ALU() : memory(Memory::GetInstance()->memory)
    {}
    /*
    void initALU(instruction instructions)
    {

    }
*/

    /**********************************************************
                            ***********************************
      8-bit ALU             ***********************************
                            ***********************************
      ********************************************************/

    /**********************************************************
      Add
      ********************************************************/
    inline void ADD(uint8_t reg)
    {
        int result = A + reg;
        setZ(result);
        resetN();
        setH(reg, result);
        setC(reg, result);
        A = result;
        cpum("Add " << (int)reg << " to A = " << (int)A);
        PC++;
        //cycle += 4;
    }

    void ADDAA() {INST  ADD(A); }
    void ADDAB() {INST  ADD(B); }
    void ADDAC() {INST  ADD(C); }
    void ADDAD() {INST  ADD(D); }
    void ADDAE() {INST  ADD(E); }
    void ADDAH() {INST  ADD(H); }
    void ADDAL() {INST  ADD(L); }

    void ADDAHL()
    {INST;
        int result = A + (H << 8) + L;
        setZ(result);
        resetN();
        setH(A, result);
        setC(A, result);
        A = result;
        PC++;
        cpum("Add HL (" << (H << 8) + L << ") to A = " << (int)A);
    }

    void ADDAN()
    {INST;
        int result = A + memory[PC + 1];
        setZ(result);
        resetN();
        setH(A, result);
        setC(A, result);
        A = result;
        PC += 2;
        cpum("Add N - " << (int)L);
    }

    /**********************************************************
      Add with Carry
      ********************************************************/

    inline void ADDCA(uint8_t reg)
    {
        int result = A + reg + CA;
        setZ(result);
        resetN();
        setH(A, result);
        setC(A, result);
        A = result;
        cpum("Add " << (int)reg << " + CA to A = " << (int)A);
        PC++;
        //cycle += 4;
    }

    void ADDCAA() {INST  ADDCA(A); }
    void ADDCAB() {INST  ADDCA(B); }
    void ADDCAC() {INST  ADDCA(C); }
    void ADDCAD() {INST  ADDCA(D); }
    void ADDCAE() {INST  ADDCA(E); }
    void ADDCAH() {INST  ADDCA(H); }
    void ADDCAL() {INST  ADDCA(L); }
    //this->instructions[0x8e] = &CPU::ADDCAHL;
    //this->instructions[0xce] = &CPU::ADDCAN;


    /**********************************************************
      Sub
      ********************************************************/

    inline void SUB(uint8_t reg)
    {
        int result = A - reg;
        setZ(result);
        setN();
        setH(A, result);
        setC(A, result);
        A = result;
        cpum("Sub " << (int)reg << " to A = " << (int)A);
        PC++;
        //cycle += 4;
    }

    void SUBAA() {INST  SUB(A); }
    void SUBAB() {INST  SUB(B); }
    void SUBAC() {INST  SUB(C); }
    void SUBAD() {INST  SUB(D); }
    void SUBAE() {INST  SUB(E); }
    void SUBAH() {INST  SUB(H); }
    void SUBAL() {INST  SUB(L); }
    //this->instructions[0x96] = &CPU::SUBAHL;
    //this->instructions[0xd6] = &CPU::SUBAN;


    /**********************************************************
      Sub with Carry
      ********************************************************/

    inline void SUBCA(uint8_t reg)
    {
        int result = A - (reg + CA);
        setZ(result);
        setN();
        setH(A, result);
        setC(A, result);
        A = result;
        cpum("Add " << (int)reg << " + CA to A = " << (int)A);
        PC++;
        //cycle += 4;
    }

    void SUBACAA() {INST  SUBCA(A); }
    void SUBACAB() {INST  SUBCA(B); }
    void SUBACAC() {INST  SUBCA(C); }
    void SUBACAD() {INST  SUBCA(D); }
    void SUBACAE() {INST  SUBCA(E); }
    void SUBACAH() {INST  SUBCA(H); }
    void SUBACAL() {INST  SUBCA(L); }

    //this->instructions[0x9e] = &CPU::SUBACAHL;
    //this->instructions[0x??] = &CPU::SUBACAN;


    /**********************************************************
      And
      ********************************************************/

    inline void AND(uint8_t reg)
    {
        A = reg && A;
        setZ(A);
        resetN();
        setH();
        resetC();
        cpum("And A && " << (int)reg);
        PC++;
        //cycle += 4;
    }

    void ANDAA() {INST  AND(A); }
    void ANDAB() {INST  AND(B); }
    void ANDAC() {INST  AND(C); }
    void ANDAD() {INST  AND(D); }
    void ANDAE() {INST  AND(E); }
    void ANDAH() {INST  AND(H); }
    void ANDAL() {INST  AND(L); }

    void ANDAN() {
        INST;
        A = memory[PC] && A;
        setZ(A);
        resetN();
        setH();
        resetC();
        PC += 2;
        cpum("And A - " << (int)A);
    }


    /**********************************************************
      Or
      ********************************************************/

    inline void OR(uint8_t reg)
    {
        A = reg || A;
        setZ(A);
        resetN();
        resetH();
        resetC();
        cpum("Or A || " << (int)reg);
        PC++;
        //cycle += 4;
    }


    void ORAA() {INST  OR(A); }
    void ORAB() {INST  OR(B); }
    void ORAC() {INST  OR(C); }
    void ORAD() {INST  OR(D); }
    void ORAE() {INST  OR(E); }
    void ORAH() {INST  OR(H); }
    void ORAL() {INST  OR(L); }

    //this->instructions[0xb6] = &CPU::ORAHL;
    //this->instructions[0xf6] = &CPU::ORAN;


    /**********************************************************
      Xor
      ********************************************************/

    inline void XOR(uint8_t reg)
    {
        A = reg ^ A;
        setZ(A);
        resetN();
        resetH();
        resetC();
        cpum("Xor A ^ " << (int)reg);
        PC++;
        //cycle += 4;
    }

    void XORAA() {INST  XOR(A); }
    void XORAB() {INST  XOR(B); }
    void XORAC() {INST  XOR(C); }
    void XORAD() {INST  XOR(D); }
    void XORAE() {INST  XOR(E); }
    void XORAH() {INST  XOR(H); }
    void XORAL() {INST  XOR(L); }
    //this->instructions[0xae] = &CPU::XORAHL;
    //this->instructions[0xee] = &CPU::XORAN;


    /**********************************************************
      CP
      ********************************************************/

    inline void CP(uint8_t reg)
    {
        if (A == reg)
            Z = 1;
        else
            Z = 0;
        resetN();
        setH(reg, A - reg); // JOKER
        setC(reg, A - reg);
        cpum("Cp A," << (int)reg);
        PC++;
    }

    void CPAA() {INST CP(A); }
    void CPAB() {INST CP(B); }
    void CPAC() {INST CP(C); }
    void CPAD() {INST CP(D); }
    void CPAE() {INST CP(E); }
    void CPAH() {INST CP(H); }
    void CPAL() {INST CP(L); }
    //CPHL
    void CPAN() {INST CP(memory[PC + 1]); PC++; }
    // H =  ! (((A & 0x0f) + ((~memory[PC + 1]+1) & 0x0f)) & 0x10) ;


    /**********************************************************
      Inc
      ********************************************************/

    inline void INC(uint8_t& reg)
    {
        reg++;
        setZ(reg);
        resetN();
        setH(reg, reg);
        cpum("Inc " << (int)reg);
        PC++;
    }

    void INCA() {INST  INC(A); }
    void INCB() {INST  INC(B); }
    void INCC() {INST  INC(C); }
    void INCD() {INST  INC(D); }
    void INCE() {INST  INC(E); }
    void INCH() {INST  INC(H); }
    void INCL() {INST  INC(L); }

    //void INCHL() {INST  INC(L); }


    /**********************************************************
      Dec
      ********************************************************/

    inline void DEC(uint8_t& reg)
    {
        reg--;
        setZ(reg);
        resetN();
        setH(reg, reg);
        cpum("Dec " << (int)reg);
        PC++;
    }

    void DECA() {INST  DEC(A); }
    void DECB() {INST  DEC(B); }
    void DECC() {INST  DEC(C); }
    void DECD() {INST  DEC(D); }
    void DECE() {INST  DEC(E); }
    void DECH() {INST  DEC(H); }
    void DECL() {INST  DEC(L); }

    //void DECHL() {INST
    //DEC(L); }

    /**********************************************************
                            ***********************************
      16-bit ALU            ***********************************
                            ***********************************
      ********************************************************/

    void INCBC() {INST  C++; if (!C) B++; PC++; cpum("Inc BC " << (int)((B << 8) + C)); }
    void INCDE() {INST  E++; if (!E) D++; PC++; cpum("Inc DE " << (int)((D << 8) + E)); }
    void INCHL() {INST  L++; if (!L) H++; PC++; cpum("Inc HL " << (int)((H << 8) + L)); }
    void INCSP() {INST  SP++; PC++; cpum("Inc SP " << SP); }

    void DECBC() {INST  C--; if (C == 0xff) B--; PC++; cpum("Dec BC : " << (int)((B << 8) + C)); }
    void DECDE() {INST  E--; if (E == 0xff) D--; PC++; cpum("Dec DE : " << (int)((D << 8) + E)); }
    void DECHL() {INST  L--; if (L == 0xff) H--; PC++; cpum("Dec HL : " << (int)((H << 8) + L)); }
    void DECSP() {INST  SP--; PC++; cpum("Dec SP : " << SP); }
};

#endif // ALU_H
