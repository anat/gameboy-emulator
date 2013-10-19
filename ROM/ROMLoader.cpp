# include <iostream>
# include <fstream>
# include "ROMLoader.h"
# include "Buffer.h"

Buffer * ROMLoader::loadROM()
{
  std::ifstream is;
  char * buffer;
  is.open (this->fileName.c_str(), std::ios::binary);

  is.seekg (0, std::ios::end);
  uint32_t length = is.tellg();
  is.seekg (0, std::ios::beg);
  std::cout << "Size of ROM : " << length << std::endl;
  buffer = new char[length];

  is.read (buffer, length);
  this->buffer = new Buffer();
  this->buffer->append(buffer, 32768);
  is.close();
  return this->buffer;
}
