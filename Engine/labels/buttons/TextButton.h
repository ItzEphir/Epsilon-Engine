#pragma once
#include "Button.h"
#include "../Text.h"

class TextButton : public Button
{
public:

    TextButton();

    virtual void Create(sf::Vector2f position, sf::Vector2f size, sf::Vector2f scale, sf::Color color, sf::Color textColor, float radius, sf::String message, unsigned int fontSize, PositionMode positionMode = PositionMode::ORIGINAL_POSITION, PositionMode textPositionMode = PositionMode::DEFAULT);

    virtual void Draw() override;

    sf::String getMessage()
    {
        return text.getString();
    }

    Text getText()
    {
        return text;
    }

    sf::Vector2f getTextPosition()
    {
        return text.getPosition();
    }

    sf::Color getTextColor()
    {
        return text.getColor();
    }

    std::shared_ptr<sf::Font> getFont()
    {
        return font;
    }

    unsigned int getFontSize()
    {
        return text.getCharacterSize();
    }

    virtual void setPosition(sf::Vector2f newPosition) override
    {
        Drawable::setPosition(newPosition);
    }

    virtual void setMessage(sf::String newMessage)
    {
        text.setString(newMessage);
    }

    virtual void setText(Text newText)
    {
        text = newText;
    }

    virtual void setTextPosition(sf::Vector2f newTextPosition)
    {
        text.setPosition(newTextPosition);
        countTextPosition();
    }

    virtual void setTextColor(sf::Color newTextColor)
    {
        text.setColor(newTextColor);
    }

    virtual void setFont(std::shared_ptr<sf::Font> newFont)
    {
        text.setFont(newFont);
    }

    virtual void setFontSize(unsigned int newFontSize)
    {
        text.setCharacterSize(newFontSize);
    }

    virtual void setTextPositionMode(PositionMode newTextPositionMode)
    {
        text.setPositionMode(newTextPositionMode);
        countTextPosition();
    }

    virtual void setPadding(sf::Vector2f newPadding)
    {
        padding = newPadding;
        countTextPosition();
    }

protected:

    Text& takeText()
    {
        return text;
    }

    void countTextPosition();

    virtual void countSize() override;

private:

    Text text;

    bool alreadyPressed = false;

    sf::Vector2f padding = { 0, 0 };
};

