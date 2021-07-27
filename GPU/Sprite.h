#ifndef SPRITE_H
#define SPRITE_H

#include <stdint.h>
#include <SFML/Graphics.hpp>
#include <string.h>

class Sprite
{
    sf::Image *img;
    public:
    Sprite(uint8_t* startAddr, int size)
    {
        //startAddr = new uint8_t[16];
        //memcpy(startAddr, (uint8_t*)"\x3c\x3c\x42\x7e\x85\xfb\x81\xff\xa1\xdf\xb1\xcf\x42\x7e\x3c\x3c", 16);
        img = new sf::Image();
        img->create(8, 8);
        //img->SetSmooth(false);
        int x = 0, y = 0;
        for (int i = 0; i < 16; i += 2)
        {
            for (int pixShift = 7; pixShift >= 0; pixShift--)
            {
                int color = (((startAddr[i] >> pixShift) & 1) * 2) + ((startAddr[i + 1] >> pixShift) & 1);
                color = (3 - color) * 85;
                //std::cout << color << std::endl;
                img->setPixel(x, y, sf::Color(color, color, color));
                x++;
            }
            y++;
            x = 0;
        }
    }

    sf::Image * getImage()
    {
        return img;
    }
} __attribute__ ((packed));

#endif // SPRITE_H
