#include "Rectangle.h"

Rectangle::Rectangle(std::shared_ptr<Window> window) : Drawable(window)
{
    shape = sf::RectangleShape(size);
    shape.setPosition(position);
    color = sf::Color::Black;
    shape.setFillColor(color);
}

Rectangle::Rectangle(std::shared_ptr<Window> window, sf::Vector2f position, sf::Vector2f size) : Drawable(window)
{
    shape = sf::RectangleShape(this->size);
    shape.setPosition(this->position);
    color = sf::Color::Black;
    shape.setFillColor(color);
}

void Rectangle::Centralize(bool turn)
{
     if (turn && !centralized)
    {
        position = sf::Vector2f(
            position.x - size.x / 2,
            position.y - size.y / 2
        );
        shape.setPosition(position);
        centralized = true;
    }
    else if (!turn && centralized)
    {
        position = sf::Vector2f(
            position.x + size.x / 2,
            position.y + size.y / 2
        );
        shape.setPosition(position);
        centralized = true;
    }
}
