#include "GPU.h"
#include <sstream>
#include "Attribute.h"
#include "macro.h"
#include "Sprite.h"

GPU::GPU() : memory(Memory::GetInstance()->memory)
{
}

void GPU::run()
{
    std::cout << "GPU run" << std::endl;
    this->window = new sf::RenderWindow(sf::VideoMode(256, 256, 8), "GameBoy");
    this->window->clear(sf::Color(0, 0, 0));
    uint8_t vsync = 0;

    while (this->window->isOpen())
    {
        sf::Event Event;
        while (this->window->pollEvent(Event))
        {
            if (Event.type == sf::Event::Closed)
            {
                this->window->close();
            }
        }
        this->window->clear(sf::Color(0, 0, 0));
        //this->window->UseVerticalSync(true);

        /*
        sf::Texture texture;
        texture.create(256, 256);

        // on déclare un tableau de pixels bruts de 2x2
        sf::Uint8 pixels[256 * 256 * 4];

        // on bidouille autant qu'on veut dans le tableau de pixels...
        // là par exemple on remplit tout de pixels verts semi-transparents
        for (int x = 0; x < 256; ++x)
            for (int y = 0; y < 256; ++y)
            {
                pixels[(x + y * 256) * 4 + 0] = 0;   // composante rouge
                pixels[(x + y * 256) * 4 + 1] = 255; // composante verte
                pixels[(x + y * 256) * 4 + 2] = 0;   // composante rouge
                pixels[(x + y * 256) * 4 + 3] = 128; // composante alpha
            }

        for (int i = 0x8000; i <= 0x97FF; i += 16)
        {

        }

        // le tableau de pixels est prêt : on met à jour la texture
        texture.update(pixels);

        // plus tard, on affiche par exemple cette texture via un sprite
        this->window->draw(sf::Sprite(texture));
*/

        int x = 0;
        int y = 0;

        //texture.create(256, 256);
        // 4*16 = 32 > 1 octet par pixel
        // 6142 = 32*32 tiles 8*8 per tile
        //for (int i = 0x8000; i <= 0x87FF; i += 16)
        /*
        for (int i = 0x8000; i <= 0x87FF; i += 16)
        {
            Sprite *s = new Sprite(memory + i, 1);
            if (x == 33)
            {
                y++;
                x = 0;
            }
            //sf::Sprite sprite(*(s->getImage()), sf::Vector2f(x * 8, y * 8));

//            std::cout << "x:" << x << " y:" << y << std::endl;
            sf::Texture texture;
            texture.loadFromImage(*(s->getImage()));

            sf::Sprite sprite(texture);
            //sprite.setTexture(texture);
            sprite.setPosition(x * 8, y * 8);
            this->window->draw(sprite);

            //delete s->getImage();
            //delete s;
            x++;
        }
        */


        //for (char i = )
        std::cout << "Index Tile Map :" << std::endl;
        for (int i = 0; i <= 0x9bff - 0x9800; i += 1) {
            //std::cout << (int)memory[0x9800 + i] << std::endl;
            int tileIndex = (int)memory[0x9800 + i];
            Sprite *s = new Sprite(memory + 0x8000 + (tileIndex * 16), 1);
            if (x == 33)
            {
                y++;
                x = 0;
            }
              sf::Texture texture;
            texture.loadFromImage(*(s->getImage()));
            sf::Sprite sprite(texture);
            //sprite.setTexture(texture);
            sprite.setPosition(x * 8, y * 8);
            this->window->draw(sprite);

            x++;
        }

        this->window->display();
        /*
        memory[0xFF44] = vsync;
        vsync++;
        if (vsync == 154)
            vsync = 0;
        sf::String Text;
        std::stringstream st;
        st << vsync;
        std::string out = st.str();
        Text.SetText(st.str().c_str());
        Text.SetSize(50);
        Text.SetFont(sf::Font::GetDefaultFont());
        Text.SetPosition(0, 0);
        this->window->Draw(Text);

        */
    }
}
