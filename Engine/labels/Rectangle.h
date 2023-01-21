#pragma once
#include "Drawable.h"

class Rectangle : public Drawable
{
public:

    Rectangle(std::shared_ptr<Window> window);

    Rectangle(std::shared_ptr<Window> window, sf::Vector2f position, sf::Vector2f size);

    virtual void Update() override;

    virtual void Draw() override;

    sf::RectangleShape getShape()
    {
        return shape;
    }

    sf::Vector2f getSize()
    {
        return size;
    }

    sf::Color getColor()
    {
        return color;
    }

    virtual void setSize(sf::Vector2f newSize)
    {
        size = newSize;
        shape.setSize(size);
    }

    virtual void setPosition(sf::Vector2f newPosition) override
    {
        Drawable::setPosition(newPosition);
        shape.setPosition(position);
    }

    virtual void setColor(sf::Color newColor)
    {
        color = newColor;
    }

    virtual void Centralize(bool turn = true);

protected:
    
    void setShape(sf::RectangleShape newShape)
    {
        shape = newShape;
    }

    sf::RectangleShape& takeShape()
    {
        return shape;
    }

private:

    sf::RectangleShape shape;

    sf::Vector2f size;
    sf::Color color;

    bool centralized = false;

};

