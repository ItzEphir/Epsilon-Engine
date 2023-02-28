#include "Text.h"

Text::Text() : Drawable()
{
    
}

void Text::Create(std::shared_ptr<sf::Font> font, sf::String message, sf::Vector2f position, sf::Vector2f size, unsigned int characterSize, sf::Color color, PositionMode positionMode)
{
    setFont(font);
    setString(message);
    setPosition(position);
    setSize(size);
    setCharacterSize(characterSize);
    setColor(color);
}

void Text::Update()
{

}

void Text::Draw()
{
    window->draw(text);
}

void Text::countSize()
{
    setSize(sf::Vector2f(text.getLocalBounds().width, text.getLocalBounds().height));
}
