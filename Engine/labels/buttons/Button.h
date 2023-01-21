#pragma once
#include "../Drawable.h"
#include "SFML/System.hpp"
#include "../Rectangle.h"
#include <string>
#include <functional>

#define ISCREATED { if(!isCreated()) { throw "Button wasn`t initialized, please, use Button::Create() to initialize the button."; } }

enum class Mode
{
    right,
    center,
    left
};

struct CMode
{

    Mode modeX;
    Mode modeY;

    CMode(Mode modex, Mode modey)
    {
        modeX = modex;
        modeY = modey;
    }

    CMode()
    {
        modeX = Mode::right;
        modeY = Mode::center;
    }

};

class Button : public Drawable
{

public:

    virtual void Create(sf::Vector2f position, sf::Vector2f size, sf::Color color, CMode mode);
    virtual void Create(sf::Vector2f position, sf::Vector2f size, sf::Color color, Mode modeX, Mode modeY);

    virtual void Give(std::function<void()> aimed, std::function<void()> pressed, std::function<void()> released)
    {
        ISCREATED;
        whenAimed = aimed;
        whenPressed = pressed;
        whenReleased = released;
    }

    virtual void Draw() override;
    virtual void Update() override = 0;

    sf::Vector2f getSize()
    {
        ISCREATED;
        return size;
    }

    sf::Color getColor()
    {
        ISCREATED;
        return color;
    }

    CMode getMode()
    {
        ISCREATED;
        return mode;
    }

    bool getAimed()
    {
        ISCREATED;
        return aimed;
    }

    bool getPressed()
    {
        ISCREATED;
        return pressed;
    }

    bool getReleased()
    {
        ISCREATED;
        return released;
    }

    virtual void setPosition(sf::Vector2f newPosition) override
    {
        position = newPosition;
        rectangle.setPosition(position);
    }

    virtual void setSize(sf::Vector2f newSize)
    {
        size = newSize;
        rectangle.setSize(size);
    }

    virtual void setColor(sf::Color newColor)
    {
        color = newColor;
        rectangle.setColor(color);
    }

    virtual void setMode(CMode newMode)
    {
        mode = newMode;
        countPosition();
    }

    virtual void setMode(Mode newModeX, Mode newModeY)
    {
        setMode(CMode(newModeX, newModeY));
    }

protected:

    Button(std::shared_ptr<Window> window) : Drawable(window), rectangle(window)
    {
        Init();
        whenAimed = []() {};
        whenPressed = []() {};
        whenReleased = []() {};
    }

    bool Find();

    virtual void setAimed(bool isAimed)
    {
        aimed = isAimed;
    }

    virtual void setPressed(bool isPressed)
    {
        pressed = isPressed;
    }

    virtual void setReleased(bool isReleased)
    {
        released = isReleased;
    }

    virtual Rectangle& takeRectangle()
    {
        return rectangle;
    }

    void turnOn()
    {
        created = true;
    }

    bool isCreated()
    {
        return created;
    }

    virtual void countPosition();

    std::function<void()> whenAimed;
    std::function<void()> whenPressed;
    std::function<void()> whenReleased;

private:

    void Init();

    bool aimed;
    bool pressed;
    bool released;

    sf::Vector2f size;

    sf::Color color;

    Rectangle rectangle;

    CMode mode;

    bool created = false;

};

