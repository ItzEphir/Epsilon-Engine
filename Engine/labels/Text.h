#pragma once
#include "Drawable.h"

class Text : public Drawable
{
public:

    Text();

    void Create(std::shared_ptr<sf::Font> font, sf::String message, sf::Vector2f position, sf::Vector2f size, unsigned int characterSize = 14, sf::Color color = sf::Color::White, PositionMode positionMode = PositionMode::DEFAULT);

    virtual void Update() override;

    virtual void Draw() override;

    virtual void countSize() override;

    std::shared_ptr<sf::Font> getFont()
    {
        return font;
    }

    sf::String getString()
    {
        return message;
    }

    sf::Text getText()
    {
        return text;
    }

    sf::Color getColor()
    {
        return color;
    }

    unsigned int getCharacterSize()
    {
        return characterSize;
    }

    sf::Vector2f getTextSize()
    {
        return sf::Vector2f(text.getLocalBounds().width, text.getLocalBounds().height);
    }

    virtual void setFont(std::shared_ptr<sf::Font> newFont)
    {
        font = newFont;
        text.setFont(*font);
    }

    virtual void setPosition(sf::Vector2f newPosition) override
    {
        Drawable::setPosition(newPosition);
        text.setPosition(position);
    }

    virtual void setString(sf::String newMessage)
    {
        message = newMessage;
        text.setString(message);
    }

    virtual void setColor(sf::Color newColor)
    {
        color = newColor;
        text.setFillColor(color);
    }

    virtual void setCharacterSize(unsigned int newCharacterSize)
    {
        characterSize = newCharacterSize;
        text.setCharacterSize(characterSize);
    }

    virtual void setPositionMode(PositionMode newPositionMode) override
    {
        Drawable::setPositionMode(newPositionMode);
        setPosition(position);
    }

protected:

private:

    std::shared_ptr<sf::Font> font;
    sf::String message;
    sf::Text text;
    sf::Color color;

    unsigned int characterSize = 14;

};

