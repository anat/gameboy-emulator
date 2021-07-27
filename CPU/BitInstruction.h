#ifndef BITINSTRUCTION_H
#define BITINSTRUCTION_H

#include "Register.h"
#include "CPU.h"
#include <iostream>

class BitInstruction : virtual public Register
{
public:
    uint8_t* memory;
    BitInstruction() : memory(Memory::GetInstance()->memory) {}
    template <typename T> void fetch();
    template <typename T> T & getOperand();
};

#endif // BITINSTRUCTION_H
