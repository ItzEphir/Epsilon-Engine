#pragma once
#include "IDrawable.h"
#include "SFML/System.hpp"
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

class Button :
    public IDrawable
{
public:
    virtual void Create(sf::Vector2f position, sf::Vector2f size, sf::Color color, CMode mode);
    virtual void Create(sf::Vector2f position, sf::Vector2f size, sf::Color color, Mode modeX, Mode modeY);

    virtual void Give(void (*aimed)(), void (*pressed)(), void (*released)())
    {
        ISCREATED;
        whenAimed = aimed;
        whenPressed = pressed;
        whenReleased = released;
    }

    virtual void Draw() override;
    virtual void Update() override = 0;

    virtual sf::Vector2f getPosition()
    {
        ISCREATED;
        return position;
    }

    virtual sf::Vector2f getSize()
    {
        ISCREATED;
        return size;
    }

    virtual sf::Color getColor()
    {
        ISCREATED;
        return color;
    }

    virtual CMode getMode()
    {
        ISCREATED;
        return mode;
    }

    virtual bool getAimed()
    {
        ISCREATED;
        return aimed;
    }

    virtual bool getPressed()
    {
        ISCREATED;
        return pressed;
    }

    virtual bool getReleased()
    {
        ISCREATED;
        return released;
    }

protected:
    Button(std::shared_ptr<sf::RenderWindow> rw) : IDrawable(rw)
    {
        rect = sf::RectangleShape();
        setWindow(rw);
        Init();
        whenAimed = []() {};
        whenPressed = []() {};
        whenReleased = []() {};
    }

    bool Find();

    virtual void setPosition(sf::Vector2f newPosition)
    {
        position = newPosition;
        rect.setPosition(position);
    }

    virtual void setSize(sf::Vector2f newSize)
    {
        size = newSize;
        rect.setSize(size);
    }

    virtual void setColor(sf::Color newColor)
    {
        color = newColor;
        rect.setFillColor(color);
    }

    virtual void setMode(CMode newMode)
    {
        mode = newMode;
    }

    virtual void setMode(Mode newModeX, Mode newModeY)
    {
        mode = CMode(newModeX, newModeY);
    }

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

    virtual std::shared_ptr<sf::RectangleShape> takeRect()
    {
        return std::make_shared<sf::RectangleShape>(rect);
    }

    void turnOn()
    {
        created = true;
    }

    bool isCreated()
    {
        return created;
    }

    std::function<void()> whenAimed;
    std::function<void()> whenPressed;
    std::function<void()> whenReleased;

private:
    void Init();

    bool aimed;
    bool pressed;
    bool released;

    sf::Vector2f position;
    sf::Vector2f size;

    sf::Color color;

    sf::RectangleShape rect;

    CMode mode;

    bool created = false;
};

