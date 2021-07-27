#include "gameboy.h"

GameBoy::GameBoy() : memory(Memory::GetInstance())
{
}

void GameBoy::start(Buffer *romBuffer)
{
    this->memory->copyToMemory(romBuffer);
    this->gpu.start();
    this->cpu.run();
}
