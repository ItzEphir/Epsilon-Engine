#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"
#include "SFML/System.hpp"
#include "Application.h"
#include <Windows.h>
#include "window/Window.h"

static sf::Uint16 STYLE = sf::Style::Default;

int main()
{
    std::setlocale(LC_ALL, "Russian");

    sf::VideoMode screen = sf::VideoMode::getDesktopMode();
    sf::VideoMode countedScreen = sf::VideoMode(1920, 1080);

    sf::VideoMode vm = sf::VideoMode(640 * screen.width / countedScreen.width, 360 * screen.height / countedScreen.height);
    std::shared_ptr<sf::RenderWindow> rw = std::make_shared<sf::RenderWindow>(vm, "", sf::Style::None);

    STYLE = sf::Style::None;

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
                    rw->create(vm, "", sf::Style::Resize);
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
