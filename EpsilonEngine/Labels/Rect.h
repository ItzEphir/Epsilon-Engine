#pragma once
#include "IDrawable.h"

class Rect :
    public IDrawable
{
public:

    Rect(std::shared_ptr<sf::RenderWindow> window, sf::Vector2f position, sf::Vector2f size) : IDrawable(window), position(position), size(size)
    {
        shape = sf::RectangleShape(size);
        shape.setPosition(position);
        color = sf::Color::Black;
        shape.setFillColor(color);
    }

    virtual void Draw() override;

    virtual void Update() override;

    virtual sf::RectangleShape getShape()
    {
        return shape;
    }

    virtual sf::Vector2f getSize()
    {
        return size;
    }

    virtual sf::Vector2f getPosition()
    {
        return position;
    }

    virtual sf::Color getColor()
    {
        return color;
    }

    virtual void setSize(sf::Vector2f newSize)
    {
        size = newSize;
        shape.setSize(size);
    }

    virtual void setPosition(sf::Vector2f newPosition)
    {
        position = newPosition;
        shape.setPosition(position);
    }

    virtual void setColor(sf::Color newColor)
    {
        color = newColor;
        shape.setFillColor(color);
    }

protected:

    virtual sf::RectangleShape& takeShape()
    {
        return shape;
    }

private:

    sf::RectangleShape shape;
    sf::Vector2f size;
    sf::Vector2f position;
    sf::Color color;

};

