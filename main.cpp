
#include <iostream>
#include <unistd.h>

#include "Buffer.h"
#include "ROMLoader.h"
#include "ROMHeader.h"
#include "gameboy.h"

int main(int ac, char **av)
{
  ac = ac;
  GameBoy gb;
  Buffer *buffer;
  ROMLoader rom(av[1]);
  buffer = rom.loadROM();
  //ROMHeader* header = static_cast<ROMHeader*>(buffer->getBuffer());
  //header->showInfo();
  gb.start(buffer);
  return 0;
}
