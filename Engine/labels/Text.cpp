#include "Text.h"

Text::Text(std::shared_ptr<Window> window) : Drawable(window)
{
    
}

Text::Text(std::shared_ptr<Window> window, std::shared_ptr<sf::Font> font) : Drawable(window), font(font)
{
    
}

Text::Text(std::shared_ptr<Window> window, std::shared_ptr<sf::Font> font, sf::String str, unsigned int characterSize, sf::Color color) : Drawable(window), font(font), str(str), characterSize(characterSize), color(color)
{
    text = sf::Text(str, *font, characterSize);
}

Text::Text(std::shared_ptr<Window> window, std::shared_ptr<sf::Font> font, sf::String str, sf::Vector2f position, unsigned int characterSize, sf::Color color) : Drawable(window), font(font), str(str), characterSize(characterSize), color(color)
{
    text = sf::Text(str, *font, characterSize);
    setPosition(position);
}

void Text::Update()
{

}

void Text::Draw()
{
    window->draw(text);
}

void Text::Centralize(bool turn)
{
    if (turn && !centralized)
    {
        position = sf::Vector2f(
            position.x - size.x / 2,
            position.y - size.y / 2
        );
        text.setPosition(position);
        centralized = true;
    }
    else if (!turn && centralized)
    {
        position = sf::Vector2f(
            position.x + size.x / 2,
            position.y + size.y / 2
        );
        text.setPosition(position);
        centralized = true;
    }
}
