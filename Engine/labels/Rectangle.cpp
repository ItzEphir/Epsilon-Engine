#include "Rectangle.h"

Rectangle::Rectangle() : Drawable(), shape(sf::FloatRect(position, size), 0.0f)
{

}

void Rectangle::Create(sf::Vector2f position, sf::Vector2f size, sf::Vector2f scale, sf::Color color, float radius, PositionMode positionMode)
{
    setPosition(position);
    setSize(size);
    setScale(scale);
    setColor(color);
    setRadius(radius);
    setPositionMode(positionMode);
}

void Rectangle::Update()
{
    
}

void Rectangle::Draw()
{
    window->draw(shape);
}

void Rectangle::countSize()
{
    
}
