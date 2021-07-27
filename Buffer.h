#ifndef __BUFFER_H__
#define __BUFFER_H__

#include <stdlib.h>
#include <iostream>
#include <stdint.h>
#include <string.h>

class Buffer
{
private:
  uint32_t Size;
  void *buffer;

public:
  Buffer() : Size(0), buffer(NULL) {}

  ~Buffer()
  {
    if (this->buffer)
      free(this->buffer);
  }

  template <typename T>
  inline int append(T *data, int size)
  {
    this->buffer = realloc(this->buffer, this->Size + size);
    memcpy(((char *)this->buffer) + this->Size, data, size);
    this->Size += size;
    return this->Size;
  }

  void *getBuffer() { return this->buffer; }
  uint32_t getSize() { return this->Size; }
};

#endif
