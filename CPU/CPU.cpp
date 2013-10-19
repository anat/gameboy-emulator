#include "CPU.h"
#include <SFML/System.hpp>
#include "Attribute.h"
void CPU::run()
{
    this->init();
        int i = 0;
        char c = 'a';
        cpum("RUN at " << this->PC);
        while (1)
        {
            if ((this->memory[this->PC] != 0xcb && this->instructions[this->memory[this->PC]] == NULL))
            {
                std::cout << "------------" << std::endl << "Not exists" << std::endl << "0x";
                if (this->memory[this->PC] == 0xcb)
                    std::cout << "cb" << std::hex << (int)this->memory[this->PC + 1];
                else
                    std::cout << std::hex << (int)this->memory[this->PC];
                std::cout << std::endl << "------------" << std::endl;
                exit(1);
            }


           // sf::Sleep(0.0001);
            cpum(std::hex << this->PC << setfill('0') << setw(2) << (int)this->memory[this->PC]);

            if (this->memory[this->PC] != 0xcb)
                (this->*instructions[this->memory[this->PC]])();
            else
            {
                this->fetch();
            }

            //if (c != 'c')
             //   read(0, &c, 1);

            for (int nAttr = 0; nAttr < 40; nAttr++)
            {
                Attribute* attr = (Attribute*)(memory + 0xFE00 + (4 * nAttr));
                if (attr->X != 0 || attr->Y != 0)
                {
                    gpum("Sprite FOUND !!!")
                    gpum("X= " << (int)attr->X);
                    gpum("Y= " << (int)attr->Y);
                    exit(0);
                }
            }
/*
            int tiles = 0;
            for (int j = 0x9800; j < 0x9C00; j++)
            {
                if (memory[j] != 0)
                    tiles++;
            }
            std::cout << "Tiles1 = " << tiles << std::endl;

            tiles = 0;
            for (int k = 0x9C00; k <= 0x9FFF; k++)
            {
                if (memory[k] != 0)
                    tiles++;
            }
            std::cout << "Tiles2 = " << tiles << std::endl;

*/
            /*
            if (i == 1000000)
            {
                std::cout << "THIS IS THE END" << std::endl;
                break;
            }
            */
            i++;
        }
        std::cout << this->PC << "/" << std::hex << this->PC << " Not implemented : "  << std::endl;
}
