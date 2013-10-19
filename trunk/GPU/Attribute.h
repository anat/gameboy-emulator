#ifndef ATTRIBUTE_H
#define ATTRIBUTE_H

#include <stdint.h>

class Attribute
{
public:
    Attribute();
    uint8_t Y;
    uint8_t X;
    uint8_t pattern;
    uint8_t dummy: 4;
    uint8_t palette: 1;
    uint8_t xflip: 1;
    uint8_t yflip: 1;
    uint8_t priority: 1;
} __attribute__ ((packed));

#endif // ATTRIBUTE_H
