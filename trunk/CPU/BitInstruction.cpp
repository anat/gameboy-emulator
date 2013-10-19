#include "BitInstruction.h"

template <typename T>
void BitInstruction::fetch()
{
    T operand = getOperand();





    if ((this->memory[this->PC + 1] >> 4) == 0)
    {

    }
    else if ((this->memory[this->PC + 1] >> 4) >= 4 && (this->memory[this->PC + 1] >> 4) <= 7)
    {

    }
    else if ((this->memory[this->PC + 1] >> 4) >= 8 && (this->memory[this->PC + 1] >> 4) <= 0xB)
    {

    }
    else if ((this->memory[this->PC + 1] >> 4) >= 0xC)
    {

    }
}


template <typename T>
T & BitInstruction::getOperand()
{
    if ((this->memory[this->PC + 1] & 0x0f) == 0x07 || (this->memory[this->PC + 1] & 0x0f) == 0x0f)
        return A;
    if ((this->memory[this->PC + 1] & 0x0f) == 0x00 || (this->memory[this->PC + 1] & 0x0f) == 0x08)
        return B;
    if ((this->memory[this->PC + 1] & 0x0f) == 0x01 || (this->memory[this->PC + 1] & 0x0f) == 0x09)
        return C;
    if ((this->memory[this->PC + 1] & 0x0f) == 0x02 || (this->memory[this->PC + 1] & 0x0f) == 0x0a)
        return D;
    if ((this->memory[this->PC + 1] & 0x0f) == 0x03 || (this->memory[this->PC + 1] & 0x0f) == 0x0b)
        return E;
    if ((this->memory[this->PC + 1] & 0x0f) == 0x04 || (this->memory[this->PC + 1] & 0x0f) == 0x0c)
        return H;
    if ((this->memory[this->PC + 1] & 0x0f) == 0x05 || (this->memory[this->PC + 1] & 0x0f) == 0x0d)
        return L;


}
