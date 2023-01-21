#pragma once
#include "Button.h"
#include "../Text.h"

class TextButton : public Button
{
public:
    
    TextButton(std::shared_ptr<Window> window) : Button(window), text(window)
    {
        
    }

    TextButton(std::shared_ptr<Window> window, std::shared_ptr<sf::Font> font) : Button(window), font(font), text(window)
    {

    }

    virtual void Create(sf::Vector2f position, sf::Vector2f size, sf::Color color, sf::Color textColor, sf::String message, unsigned int fontSize, CMode mode);

    virtual void Create(sf::Vector2f position, sf::Vector2f size, sf::Color color, sf::Color textColor, sf::String message, unsigned int fontSize, Mode modeX, Mode modeY);


    virtual void Update() override;

    virtual void Draw() override;

    sf::String getMessage()
    {
        ISCREATED;
        return text.getString();
    }

    Text getText()
    {
        ISCREATED;
        return text;
    }

    sf::Vector2f getTextPosition()
    {
        ISCREATED;
        return textPosition;
    }

    sf::Vector2f getModedTextPosition()
    {
        ISCREATED;
        return text.getPosition();
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
        return text.getCharacterSize();
    }

    virtual void setMessage(sf::String newMessage)
    {
        ISCREATED;
        text.setString(newMessage);
    }

    virtual void setText(Text newText)
    {
        ISCREATED;
        text = newText;
    }

    virtual void setTextPosition(sf::Vector2f newTextPosition)
    {
        ISCREATED;
        textPosition = newTextPosition;
        text.setPosition(textPosition);
    }

    virtual void setTextColor(sf::Color newTextColor)
    {
        ISCREATED;
        textColor = newTextColor;
        text.setColor(textColor);
    }

    virtual void setFont(std::shared_ptr<sf::Font> newFont)
    {
        ISCREATED;
        font = newFont;
        text.setFont(font);
    }

    virtual void setFontSize(unsigned int newFontSize)
    {
        ISCREATED;
        text.setCharacterSize(newFontSize);
    }

    virtual void setMode(CMode newMode) override
    {
        Button::setMode(newMode);
        countTextPosition();
    }

    virtual void setMode(Mode newModeX, Mode newModeY) override
    {
        Button::setMode(newModeX, newModeY);
        countTextPosition();
    }

protected:

    Text& takeText()
    {
        ISCREATED;
        return text;
    }

    void countTextPosition();

    void countSize();

private:

    std::shared_ptr<sf::Font> font;

    Text text;

    sf::Vector2f textPosition;
    sf::Vector2f diplacement;

    sf::Color textColor;

    bool alreadyPressed = false;
};

