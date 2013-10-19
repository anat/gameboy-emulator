#ifndef INTERRUPTION_H
#define INTERRUPTION_H

#include "CPU.h"
#include "Register.h"
#include "Memory.h"

class Interruption : virtual public Register
{
public:
    uint8_t* memory;
    bool activated;
    Interruption() : memory(Memory::GetInstance()->memory), activated(true) {}
    void DI() {INST activated = false; PC++; }
    void EI() {INST activated = true; PC++; }
};

#endif // INTERRUPTION_H
