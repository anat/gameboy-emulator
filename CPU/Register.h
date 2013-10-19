#ifndef REGISTER_H
#define REGISTER_H

#include "macro.h"
#include <iostream>

class Register
{
public:
    uint8_t A;

    uint8_t B;
    uint8_t C;

    uint8_t D;
    uint8_t E;

    uint8_t H;
    uint8_t L;

    uint16_t SP;
    uint16_t PC;

    uint8_t Z:1; // Zero flag
    uint8_t N:1; // Substract Flag
    uint8_t HCA:1; // Half Carry Flag
    uint8_t CA:1; // Carry Flag
    uint8_t Dummy:4;

    Register(){
    }

    void init()
    {
        cpum("Register Construct")
        this->A = 0x01;
        this->B = 0x00;
        this->C = 0x13;
        this->D = 0x00;
        this->E = 0xD8;
        this->H = 0x01;
        this->L = 0x4D;


        this->Z = 1;
        this->N = 0;
        this->HCA = 1;
        this->CA = 1;

        this->SP = 0xFFFE;
        this->PC = 0x100;
    }

    template <typename T>
    inline void setZ(T result)
    {
        Z = (!result);
    }

    inline void setN() { N = 0; }
    inline void resetN() { N = 0; }

    inline void setH() { HCA = 1; }
    inline void resetH() { HCA = 0; }

    template <typename T1, typename T2>
    inline void setH(T1 operand, T2 result)
    {
        int oldcarry = HCA;
        if (sizeof(operand) == 1)
            this->HCA = result > 0x0f;
        else if (sizeof(operand) == 2)
            this->HCA = result > 0xff;
        else { cpum("ERROR"); exit(0); }
        if (oldcarry != (int)HCA)
            cpum("Half carry changed = " << (int)HCA)
    }

    template <typename T1, typename T2>
    inline void setC(T1 operand, T2 result)
    {
        int oldcarry = CA;
        if (sizeof(operand) == 1)
            this->CA = result > 0xff;
        else if (sizeof(operand) == 2)
            this->CA = result > 0xffff;
        else { cpum("ERROR"); exit(0); }
        if (oldcarry != (int)CA)
            cpum("Carry changed = " << (int)CA)
    }

    inline void resetC() { CA = 0; }
};

#endif // REGISTER_H
