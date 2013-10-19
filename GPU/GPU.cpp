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
    this->window = new sf::RenderWindow(sf::VideoMode(256, 256, 8), "GameBoy");
    this->window->Clear(sf::Color(0, 0, 0));
    uint8_t vsync = 0;

    while (this->window->IsOpened())
    {
        sf::Event Event;
        while (this->window->GetEvent(Event))
        {
            if (Event.Type == sf::Event::Closed)
            {
                 //   this->window->Close();
                          }
        }
        this->window->Clear(sf::Color(0, 0, 0));
        //this->window->UseVerticalSync(true);
        int x = 0;
        int y = 0;
        for (int i = 0x8000; i <= 0x97FF; i+= 16)
        {
            Sprite* s = new Sprite(memory + i, 1);
            if (x == 17)
            {
                y++;
                x = 0;
            }
            sf::Sprite sprite(*(s->getImage()), sf::Vector2f(x * 8, y * 8));
            this->window->Draw(sprite);
            //delete s->getImage();
            //delete s;
            x++;
        }
        this->window->Display();
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

