#pragma once
#include "../Drawable.h"
#include "SFML/System.hpp"
#include "../Rectangle.h"
#include <string>
#include <functional>

class Button : public Drawable
{

public:

    Button();
    
    virtual void Create(sf::Vector2f position, sf::Vector2f size, sf::Vector2f scale, sf::Color color, float radius, PositionMode mode = PositionMode::DEFAULT);

    virtual void Give(std::function<void()> aimed, std::function<void()> pressed, std::function<void()> released)
    {
        whenAimed = aimed;
        whenPressed = pressed;
        whenReleased = released;
    }

    virtual void Draw() override;
    virtual void Update() override;

    sf::Color getColor()
    {
        return color;
    }

    bool getAimed()
    {
        return aimed;
    }

    bool getPressed()
    {
        return pressed;
    }

    bool getReleased()
    {
        return released;
    }

    virtual void setRadius(float pixels)
    {
        rectangle.setRadius(pixels);
    }

    virtual void setPosition(sf::Vector2f newPosition) override
    {
        Drawable::setPosition(newPosition);
        rectangle.setPosition(position);
    }

    virtual void setSize(sf::Vector2f newSize) override
    {
        Drawable::setSize(newSize);
        rectangle.setSize(size);
    }

    virtual void setScale(sf::Vector2f newScale) override
    {
        Drawable::setScale(newScale);
        rectangle.setScale(scale);
    }

    virtual void setColor(sf::Color newColor)
    {
        color = newColor;
        rectangle.setColor(color);
    }

    virtual void countSize() override
    {

    }

protected:
    
    bool Find();

    virtual void setAimed(bool isAimed)
    {
        aimed = isAimed;
        if(aimed) whenAimed();
    }

    virtual void setPressed(bool isPressed)
    {
        pressed = isPressed;
        if(pressed) whenPressed();
    }

    virtual void setReleased(bool isReleased)
    {
        released = isReleased;
        if(released) whenReleased();
    }

    virtual Rectangle& takeRectangle()
    {
        return rectangle;
    }

    std::function<void()> whenAimed = []() {};
    std::function<void()> whenPressed = []() {};
    std::function<void()> whenReleased = []() {};

private:

    bool aimed = false;
    bool pressed = false;
    bool released = false;

    sf::Color color;

    Rectangle rectangle;

    bool alreadyPressed = false;
};

