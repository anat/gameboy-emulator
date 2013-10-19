#ifndef __ROMLOADER_H__
#define __ROMLOADER_H__

# include <string>
# include "Buffer.h"
# include "ROMHeader.h"

class ROMLoader
{
 public:
  Buffer* loadROM();
 ROMLoader(std::string const & path) : fileName(path) {}
  ~ROMLoader() {}


 private:
  ROMHeader* header;
  Buffer* buffer;
  std::string fileName;
};

#endif
