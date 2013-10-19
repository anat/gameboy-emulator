#ifndef __MEMORY_H__
# define __MEMORY_H__

# include <stdint.h>
# include "Buffer.h"


class Memory
{
private:
    Memory()
    {
        std::cout << "Create memory" << std::endl;
        memory = new uint8_t[65536];
    }

public:
    static Memory* instance;
    uint8_t * memory;

    static Memory * GetInstance()
    {
        if (Memory::instance == NULL)
        {
            Memory::instance = new Memory();
            Memory::instance->init();
        }
        return Memory::instance;
    }

    void init()
    {
        memory[0xFF05] = 0x00;
        memory[0xFF06] = 0x00;
        memory[0xFF07] = 0x00;
        memory[0xFF10] = 0x80;
        memory[0xFF11] = 0xBF;
        memory[0xFF12] = 0xF3;
        memory[0xFF14] = 0xBF;
        memory[0xFF16] = 0x3F;
        memory[0xFF17] = 0x00;
        memory[0xFF19] = 0xBF;
        memory[0xFF1A] = 0x7F;
        memory[0xFF1B] = 0xFF;
        memory[0xFF1C] = 0x9F;
        memory[0xFF1E] = 0xBF;
        memory[0xFF20] = 0xFF;
        memory[0xFF21] = 0x00;
        memory[0xFF22] = 0x00;
        memory[0xFF23] = 0xBF;
        memory[0xFF24] = 0x77;
        memory[0xFF25] = 0xF3;
        memory[0xFF26] = 0xF1;
        memory[0xFF40] = 0x91;
        memory[0xFF42] = 0x00;
        memory[0xFF43] = 0x00;
        memory[0xFF45] = 0x00;
        memory[0xFF47] = 0xFC;
        memory[0xFF48] = 0xFF;
        memory[0xFF49] = 0xFF;
        memory[0xFF4A] = 0x00;
        memory[0xFF4B] = 0x00;
        memory[0xFFFF] = 0x00;

        memory[0xFF44] = 0x94;
    }

    template<typename T>
    inline void write(T* data, int offset, int size)
    {
        memcpy(((char *)this->memory) + offset, data, size);
    }

    void copyToMemory(Buffer* buffer)
    {
        this->write(buffer->getBuffer(), 0, buffer->getSize());
    }

};

#endif
