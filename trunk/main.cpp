
#include <iostream>

#include "Buffer.h"



#include "ROMLoader.h"


#include "ROMHeader.h"

#include "gameboy.h"

#include <unistd.h>



//JOKER

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
