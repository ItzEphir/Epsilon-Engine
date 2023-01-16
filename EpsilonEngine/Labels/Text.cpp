#include "Text.h"

RenderText::RenderText(std::shared_ptr<sf::RenderWindow> window, std::shared_ptr<sf::Font> font, sf::String str, unsigned int characterSize, sf::Color color) 
	: IDrawable(window), font(font), str(str), characterSize(characterSize), color(color)
{
	text = sf::Text(str, *font, characterSize);
	size = sf::Vector2f(text.getLocalBounds().width, text.getLocalBounds().height);
	text.setFillColor(color);
}

RenderText::RenderText(std::shared_ptr<sf::RenderWindow> window, std::shared_ptr<sf::Font> font, sf::String str, sf::Vector2f position, unsigned int characterSize, sf::Color color) 
	: IDrawable(window), font(font), str(str), position(position), characterSize(characterSize), color(color)
{
	text = sf::Text(str, *font, characterSize);
	size = sf::Vector2f(text.getLocalBounds().width, text.getLocalBounds().height);
	text.setFillColor(color);
	text.setPosition(position);
}

void RenderText::Centralize(bool turn)
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
    else if(!turn && centralized)
    {
        position = sf::Vector2f(
            position.x + size.x / 2,
            position.y + size.y / 2
        );
        text.setPosition(position);
        centralized = false;
    }
}
