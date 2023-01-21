#pragma once
#include "Drawable.h"

class Text : public Drawable
{
public:

    Text(std::shared_ptr<Window> window);

    Text(std::shared_ptr<Window> window, std::shared_ptr<sf::Font> font);

    Text(std::shared_ptr<Window> window, std::shared_ptr<sf::Font> font, sf::String str, unsigned int characterSize = 14, sf::Color color = sf::Color::White);

    Text(std::shared_ptr<Window> window, std::shared_ptr<sf::Font> font, sf::String str, sf::Vector2f position, unsigned int characterSize = 14, sf::Color color = sf::Color::White);

    virtual void Update() override;

    virtual void Draw() override;

    void Centralize(bool turn = true);

    std::shared_ptr<sf::Font> getFont()
    {
        return font;
    }

    sf::Vector2f getSize()
    {
        return size;
    }

    sf::String getString()
    {
        return str;
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

    virtual void setFont(std::shared_ptr<sf::Font> newFont)
    {
        font = newFont;
        text.setFont(*font);
    }

    virtual void setPosition(sf::Vector2f newPosition) override
    {
        position = newPosition;
        text.setPosition(position);
    }

    virtual void setString(sf::String str)
    {
        this->str = str;
        text.setString(this->str);
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

protected:

private:

    std::shared_ptr<sf::Font> font;

    sf::Vector2f size;
    sf::String str;
    sf::Text text;
    sf::Color color;

    unsigned int characterSize = 14;

    bool centralized = false;

};

