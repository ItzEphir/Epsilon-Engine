#pragma once
#include "IDrawable.h"
#include "SFML/System.hpp"
#include <string>

#define ISCREATED { if(!created) { throw "Button wasn`t initialized, please, use Button::Create() to initialize the button."; } }

enum class Mode
{
    right,
    center,
    left
};

struct TextMode
{
    Mode modeX;
    Mode modeY;
    TextMode(Mode modex, Mode modey)
    {
        modeX = modex;
        modeY = modey;
    }
    TextMode()
    {
        modeX = Mode::right;
        modeY = Mode::center;
    }
};

class Button :
    public IDrawable
{
public:
    void Create(sf::Vector2f position, sf::Vector2f size, sf::Color color, sf::Color textColor, sf::String message, unsigned int fontSize, TextMode mode);
    void Create(sf::Vector2f position, sf::Vector2f size, sf::Color color, sf::Color textColor, sf::String message, unsigned int fontSize, Mode modeX, Mode modeY);

    void Give(void (*aimed)(), void (*pressed)(), void (*released)())
    {
        ISCREATED
            whenAimed = aimed;
        whenPressed = pressed;
        whenReleased = released;
    }

    virtual void Draw() override;
    virtual void Update() override;

    sf::String getMessage()
    {
        return message;
    }

    sf::Text getText()
    {
        return text;
    }

    sf::Vector2f getPosition()
    {
        return position;
    }

    sf::Vector2f getSize()
    {
        return size;
    }

    sf::Vector2f getTextPosition()
    {
        return textPosition;
    }

    sf::Color getColor()
    {
        return color;
    }

    sf::Color getTextColor()
    {
        return textColor;
    }

    std::shared_ptr<sf::Font> getFont()
    {
        return font;
    }

    unsigned int getFontSize()
    {
        return fontSize;
    }

    TextMode getMode()
    {
        return mode;
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

    virtual std::string get—ondition()
    {
        std::string result = "";

        if (aimed)
        {
            result += "aimed ";
        }
        if (pressed)
        {
            result += "pressed";
        }
        if (released)
        {
            result += "released";
        }

        return result;
    }

protected:
    Button(std::shared_ptr<sf::RenderWindow> rw, std::shared_ptr<sf::Font> font)
    : font(font)
    {
        setWindow(rw);
        Init();
    }

    bool Find();

    void setPosition(sf::Vector2f newPosition)
    {
        position = newPosition;
    }

    void setSize(sf::Vector2f newSize)
    {
        size = newSize;
    }

    void setTextPosition(sf::Vector2f newTextPosition)
    {
        textPosition = newTextPosition;
    }

    void setColor(sf::Color newColor)
    {
        color = newColor;
    }

    void setTextColor(sf::Color newTextColor)
    {
        textColor = newTextColor;
    }

    void setFont(std::shared_ptr<sf::Font> newFont)
    {
        font = newFont;
    }

    void setFontSize(unsigned int newFontSize)
    {
        fontSize = newFontSize;
    }

    void setMode(TextMode newMode)
    {
        mode = newMode;
    }

    void setMode(Mode newModeX, Mode newModeY)
    {
        mode = TextMode(newModeX, newModeY);
    }

    void setAimed(bool isAimed)
    {
        aimed = isAimed;
    }

    void setPressed(bool isPressed)
    {
        pressed = isPressed;
    }

    void setReleased(bool isReleased)
    {
        released = isReleased;
    }

private:
    void Init();

    void countSize();

    void countTextPosition();

    bool aimed;
    bool pressed;
    bool released;

    void (*whenAimed)();
    void (*whenPressed)();
    void (*whenReleased)();

    sf::Vector2f position;
    sf::Vector2f textPosition;
    sf::Vector2f size;
    sf::Vector2f diplacement;

    sf::Color color;
    sf::Color textColor;

    std::shared_ptr<sf::Font> font;

    sf::String message;
    sf::Text text;

    unsigned int fontSize;
    TextMode mode;

    bool created = false;
};

