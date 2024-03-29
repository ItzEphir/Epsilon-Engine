#pragma once
#include "Button.h"

class UsualButton :
    public Button
{
public:

    UsualButton(std::shared_ptr<sf::RenderWindow> rw, std::shared_ptr<sf::Font> font);

    virtual void Create(sf::Vector2f position, sf::Vector2f size, sf::Color color, CMode mode) override;

    virtual void Create(sf::Vector2f position, sf::Vector2f size, sf::Color color, Mode modeX, Mode modeY) override;

    virtual void Create(sf::Vector2f position, sf::Vector2f size, sf::Color color, sf::Color textColor, sf::String message, unsigned int fontSize, CMode mode);

    virtual void Create(sf::Vector2f position, sf::Vector2f size, sf::Color color, sf::Color textColor, sf::String message, unsigned int fontSize, Mode modeX, Mode modeY);

    virtual void Update() override;

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

    sf::Vector2f getTextPosition()
    {
        ISCREATED;
        return textPosition;
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

    virtual void setMessage(sf::String newMessage)
    {
        ISCREATED;
        message = newMessage;
        text.setString(newMessage);
    }

    virtual void setText(sf::Text newText)
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
        text.setFillColor(textColor);
    }

    virtual void setFont(std::shared_ptr<sf::Font> newFont)
    {
        ISCREATED;
        font = newFont;
        text.setFont(*font);
    }

    virtual void setFontSize(unsigned int newFontSize)
    {
        ISCREATED;
        fontSize = newFontSize;
        text.setCharacterSize(fontSize);
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

    std::shared_ptr<sf::Text> takeText()
    {
        ISCREATED;
        return std::make_shared<sf::Text>(text);
    }

    void countTextPosition();

    void countSize();

private:

    sf::Vector2f textPosition;
    sf::Vector2f diplacement;

    sf::Color textColor;

    sf::String message;

    std::shared_ptr<sf::Font> font;
    unsigned int fontSize;

    sf::Text text;

    bool alreadyPressed;

};

