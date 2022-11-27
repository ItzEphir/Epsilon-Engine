#pragma once
#include "IDrawable.h"
#include "SFML/System.hpp"
#include <string>

#define ISCREATED { if(!isCreated()) { throw "Button wasn`t initialized, please, use Button::Create() to initialize the button."; } }

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
    virtual void Create(sf::Vector2f position, sf::Vector2f size, sf::Color color, sf::Color textColor, sf::String message, unsigned int fontSize, TextMode mode);
    virtual void Create(sf::Vector2f position, sf::Vector2f size, sf::Color color, sf::Color textColor, sf::String message, unsigned int fontSize, Mode modeX, Mode modeY);

    virtual void Give(void (*aimed)(), void (*pressed)(), void (*released)())
    {
        ISCREATED;
        whenAimed = aimed;
        whenPressed = pressed;
        whenReleased = released;
    }

    virtual void Draw() override;
    virtual void Update() override = 0;

    sf::String getMessage()
    {
        ISCREATED;
        return message;
    }

    sf::Text getText()
    {
        ISCREATED;
        return text;
    }

    sf::Vector2f getPosition()
    {
        ISCREATED;
        return position;
    }

    sf::Vector2f getSize()
    {
        ISCREATED;
        return size;
    }

    sf::Vector2f getTextPosition()
    {
        ISCREATED;
        return textPosition;
    }

    sf::Color getColor()
    {
        ISCREATED;
        return color;
    }

    sf::Color getTextColor()
    {
        ISCREATED;
        return textColor;
    }

    std::shared_ptr<sf::Font> getFont()
    {
        ISCREATED;
        return font;
    }

    unsigned int getFontSize()
    {
        ISCREATED;
        return fontSize;
    }

    TextMode getMode()
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

protected:
    Button(std::shared_ptr<sf::RenderWindow> rw, std::shared_ptr<sf::Font> font)
        : font(font)
    {
        rect = sf::RectangleShape();
        text = sf::Text();
        setWindow(rw);
        Init();
    }

    bool Find();

    void setPosition(sf::Vector2f newPosition)
    {
        position = newPosition;
        rect.setPosition(position);
    }

    void setSize(sf::Vector2f newSize)
    {
        size = newSize;
    }

    void setTextPosition(sf::Vector2f newTextPosition)
    {
        textPosition = newTextPosition;
        text.setPosition(textPosition);
    }

    void setColor(sf::Color newColor)
    {
        color = newColor;
        rect.setFillColor(color);
    }

    void setTextColor(sf::Color newTextColor)
    {
        textColor = newTextColor;
        text.setFillColor(textColor);
    }

    void setFont(std::shared_ptr<sf::Font> newFont)
    {
        font = newFont;
        text.setFont(*font);
    }

    void setFontSize(unsigned int newFontSize)
    {
        fontSize = newFontSize;
        text.setCharacterSize(fontSize);
    }

    void setMode(TextMode newMode)
    {
        mode = newMode;
        countTextPosition();
    }

    void setMode(Mode newModeX, Mode newModeY)
    {
        mode = TextMode(newModeX, newModeY);
        countTextPosition();
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

    std::shared_ptr<sf::Text> takeText()
    {
        return std::make_shared<sf::Text>(text);
    }

    std::shared_ptr<sf::RectangleShape> takeRect()
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

    void (*whenAimed)();
    void (*whenPressed)();
    void (*whenReleased)();

private:
    void Init();

    void countSize();

    void countTextPosition();

    bool aimed;
    bool pressed;
    bool released;

    sf::Vector2f position;
    sf::Vector2f textPosition;
    sf::Vector2f size;
    sf::Vector2f diplacement;

    sf::Color color;
    sf::Color textColor;

    std::shared_ptr<sf::Font> font;

    sf::String message;
    sf::Text text;
    sf::RectangleShape rect;

    unsigned int fontSize;
    TextMode mode;

    bool created = false;
};

