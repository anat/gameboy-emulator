#ifndef GAMEBOY_H
#define GAMEBOY_H

# include "Memory.h"
# include "CPU.h"
# include "GPU.h"
# include "Buffer.h"

class GameBoy
{
private:
    Memory* memory;
    CPU cpu;
    GPU gpu;
public:
    GameBoy();
    void start(Buffer* romBuffer);
};

#endif // GAMEBOY_H
