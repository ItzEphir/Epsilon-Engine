#include "Button.h"

Button::Button() : Drawable(), rectangle()
{

}

void Button::Draw()
{
    rectangle.Draw();
}

void Button::Update()
{
    if (Find())
    {
        setAimed(true);
        if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
        {
            setPressed(true);
            alreadyPressed = true;
        }
        else
        {
            setPressed(false);
            if (alreadyPressed)
            {
                alreadyPressed = false;
                setReleased(true);
            }
            else 
                setReleased(false);
        }
    }
    else 
        setAimed(false);
}

void Button::Create(sf::Vector2f position, sf::Vector2f size, sf::Vector2f scale, sf::Color color, float radius, PositionMode positionMode)
{
    setPosition(position);
    setSize(size);
    setScale(scale);
    setColor(color);
    setRadius(radius);
    setPositionMode(positionMode);
}

bool Button::Find()
{
    sf::Vector2i mouse = sf::Mouse::getPosition(*window);

    return position.x < mouse.x && position.y < mouse.y && position.x + size.x > mouse.x && position.y + size.y > mouse.y;
}