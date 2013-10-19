#ifndef JUMPS_H
#define JUMPS_H

#include "CPU.h"
#include "Register.h"
#include "Memory.h"

class Jumps : virtual public Register
{
public:
    uint8_t* memory;
    Jumps()
    {
        memory = Memory::GetInstance()->memory;
    }

    void JP() {INST
        PC = *(uint16_t*)(this->memory + (PC + 1));
        cpum("Jump to " << std::hex << PC)
        //db();
    }


    void JPNZ() {INST cpum("Jump if NZero to " << (uint16_t)*(this->memory + (PC + 1)))
        if (!Z)
            PC = *(uint16_t*)(this->memory + (PC + 1));
        else
            PC += 3;
    }

    void JPZ() {INST cpum("Jump if Zero to " << (uint16_t)*(this->memory + (PC + 1)))
        if (Z)
            PC = *(uint16_t*)(this->memory + (PC + 1));
        else
            PC += 3;
    }

    void JPC() {INST cpum("Jump if Not Carry to " << (uint16_t)*(this->memory + (PC + 1)))
        if (!CA)
            PC = *(uint16_t*)(this->memory + (PC + 1));
        else
            PC += 3;
    }

    void JPNC() {INST cpum("Jump if Carry to " << (uint16_t)*(this->memory + (PC + 1)))
        if (CA)
            PC = *(uint16_t*)(this->memory + (PC + 1));
        else
            PC += 3;
    }

    void JR20() {INST cpum("Jump to " << (int)(PC + (int8_t)memory[PC - 1]) << " if Z==0  Z=" << (int)Z)
                  PC += 2;
                            if (!Z)
                            {
                                PC += (int8_t)memory[PC - 1];
                            }
                            else
                            {
                                cpum("Continue")
                                cpum("HL = " << (H << 8) + L)
                            }
                }

    void call1() {INST
        SP -= 2;
        *(uint16_t*)(memory + SP) = PC + 3; // push EIP
        PC = *(uint16_t*)(memory + (PC + 1)); // Jump
        cpum("Call " << std::hex << this->PC)
    }

    void RET()
    {INST
        PC = *(uint16_t*)(memory + SP);
        SP += 2;
        //db();
    }

    void db()
    {
        cpum(endl << "----------------------------------------------------------")
        cpum("PC = " << PC)
        cpum("----------------------------------------------------------")
        for (int i = 0; i < 10; i++)
        {
            for (int j = i * 10; j < (10 * i) + 10; j++)
            {
                //cpum("J=" << j << " ")
                cpum(setfill('0') << setw(2)<< hex << (short)memory[PC + j] << " ");
            } cpum(endl)
        }
        cpum("----------------------------------------------------------")
    }
};

#endif // JUMPS_H
