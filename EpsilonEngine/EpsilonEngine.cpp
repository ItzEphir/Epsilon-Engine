#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"
#include "SFML/System.hpp"
#include "Application.h"
#include <Windows.h>

int main()
{
    sf::Uint32* style = new sf::Uint32(sf::Style::None);
    std::setlocale(LC_ALL, "Russian");
    sf::VideoMode vm = sf::VideoMode(640, 360);
    std::shared_ptr<sf::RenderWindow> rw = std::make_shared<sf::RenderWindow>(vm, "", *style);

    Application application = Application(rw);

    rw->setFramerateLimit(60);

    application.Load();

    while (rw->isOpen())
    {
        sf::Event wevent;
        while (rw->pollEvent(wevent))
        {
            if (wevent.type == sf::Event::Closed)
            {
                rw->close();
            }

            if (wevent.type == sf::Event::KeyPressed)
            {
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::F11))
                {
                    style = new sf::Uint32( sf::Style::Resize);
                    rw->create(vm, "", *style);
                    rw->setFramerateLimit(60);
                }
            }
        }
        rw->clear();

        application.Update();
        application.Draw();

        rw->display();
    }
}
