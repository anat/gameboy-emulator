#ifndef GBGPU_H
#define GBGPU_H

#include <iostream>
#include <QThread>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "Memory.h"

class GPU : public QThread
{
private:
    uint8_t* memory;
    sf::RenderWindow* window;
    void run();
public:
    GPU();
};

#endif // GPU_H
