#ifndef __ROMHEADER_H__
#define __ROMHEADER_H__

# include <stdint.h>

enum CartRidgeType
{
  ROMOnly = 0x00,
  ROMMBC1 = 0x01,
  ROMRAM = 0x08,
  ROMMBC5 = 0x19
};

struct ROMHeader
{
  uint8_t dummy[64];
  uint8_t verticalBlankISA[8];
  uint8_t lcdcBlankISA[8];
  uint8_t timeOverflowISA[8];
  uint8_t serialTransferISA[8];
  uint8_t h2lISA[160];
  uint8_t entryPoint[4];
  uint8_t NINTENDO[48];
  char title[16];
  uint8_t colorInfo;
  uint8_t license[2];
  uint8_t gbType;
  uint8_t cartType;
  uint8_t romSize;
  uint8_t ramSize;
  uint8_t jpzone;
  uint8_t oldLicense;
  uint8_t maskRomVersion;
  uint8_t specialCheck;
  uint8_t checksum[2];

  void showInfo()
  {
    std::cout << "ROM Infos:" << std::endl;
    std::cout << "Game name: " << this->title << std::endl;
    std::cout << (this->colorInfo == 0x80 ? "Game has color" : "B&White Game") << std::endl;
    std::cout << "ROM Type: " << (this->gbType == 0x00 ? "Old GameBoy" : "SuperGameBoy") << std::endl;
    std::cout << "Cartridge type: " << (int)this->cartType << std::endl;
    std::cout << "ROM Size: " << (int)this->romSize << std::endl;
    std::cout << "RAM Size: " << (int)this->ramSize << std::endl;
  }
} __attribute__ ((packed));

#endif
