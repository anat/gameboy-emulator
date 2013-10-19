#include "gameboy.h"

GameBoy::GameBoy() : memory(Memory::GetInstance())
{
}

void GameBoy::start(Buffer * romBuffer)
{
    this->gpu.start();
    this->memory->copyToMemory(romBuffer);
    this->cpu.run();
}
