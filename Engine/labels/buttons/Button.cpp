#include "Button.h"

void Button::Draw()
{
    ISCREATED;
    rectangle.Draw();
}

void Button::Init()
{
    aimed = false;
    pressed = false;
    released = false;
}

void Button::Create(sf::Vector2f position, sf::Vector2f size, sf::Color color, CMode mode = CMode(Mode::right, Mode::center))
{
    turnOn();
    setSize(size);
    setPosition(position);
    setColor(color);
    setMode(mode);
}

void Button::Create(sf::Vector2f position, sf::Vector2f size, sf::Color color, Mode modeX, Mode modeY)
{
    turnOn();
    setSize(size);
    setPosition(position);
    setColor(color);
    setMode(CMode(modeX, modeY));
}

bool Button::Find()
{
    ISCREATED

    sf::Vector2i mouse = sf::Mouse::getPosition(*window);

    return (position.x < mouse.x&& position.y < mouse.y&& position.x + size.x > mouse.x&& position.y + size.y > mouse.y) ? true : false;
}

void Button::countPosition()
{
    switch (mode.modeX)
    {
    case Mode::right:
        rectangle.setPosition(sf::Vector2f(
            position.x,
            rectangle.getPosition().y
        ));
        break;
    case Mode::center:
        rectangle.setPosition(sf::Vector2f(
            position.x - size.x / 2,
            rectangle.getPosition().y
        ));
        break;
    case Mode::left:
        rectangle.setPosition(sf::Vector2f(
            position.x - size.x,
            rectangle.getPosition().y
        ));
        break;
    }

    switch (mode.modeY)
    {
    case Mode::right:
        rectangle.setPosition(sf::Vector2f(
            rectangle.getPosition().x,
            position.y
        ));
        break;
    case Mode::center:
        rectangle.setPosition(sf::Vector2f(
            rectangle.getPosition().x,
            position.y - size.y / 2
        ));
        break;
    case Mode::left:
        rectangle.setPosition(sf::Vector2f(
            rectangle.getPosition().x,
            position.y - size.y
        ));
        break;
    }
}