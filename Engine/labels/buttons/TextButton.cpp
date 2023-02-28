#include "TextButton.h"

TextButton::TextButton() : Button(), text()
{

}

void TextButton::Create(sf::Vector2f position, sf::Vector2f size, sf::Vector2f scale, sf::Color color, sf::Color textColor, float radius, sf::String message, unsigned int fontSize, PositionMode mode, PositionMode textPositionMode)
{
    Button::Create(position, size, scale, color, radius, mode);
    setTextColor(textColor);
    setMessage(message);
    setFontSize(fontSize);
}

void TextButton::Draw()
{
    Button::Draw();
    text.Draw();
}

void TextButton::countTextPosition()
{
    switch (text.getPositionMode().modeX)
    {
    case Mode::left:
        text.setPosition(sf::Vector2f(position.x + padding.x, text.getPosition().y));
        break;
    case Mode::center:
        text.setPosition(sf::Vector2f(position.x + size.x / 2, text.getPosition().y));
        break;
    case Mode::right:
        text.setPosition(sf::Vector2f(position.x + size.x - padding.x, text.getPosition().y));
        break;
    default:
        throw PositionModeException("Trying to compare modeX with top/bottom/other");
    }

    switch (text.getPositionMode().modeY)
    {
    case Mode::top:
        text.setPosition(sf::Vector2f(text.getPosition().x, position.y + padding.y));
        break;
    case Mode::center:
        text.setPosition(sf::Vector2f(text.getPosition().x, position.y + size.y / 2));
        break;
    case Mode::bottom:
        text.setPosition(sf::Vector2f(text.getPosition().x, position.y + size.y - padding.y));
        break;
    default:
        throw PositionModeException("Trying to compare modeY with left/right/other");
    }
}

void TextButton::countSize()
{
    float textLength = text.getTextSize().x;
    float textHeight = text.getTextSize().y;

    setPadding(sf::Vector2f(-textLength / text.getString().getSize(), -textHeight / 2));
    setSize(sf::Vector2f(textLength - 2 * padding.x, textHeight - 2 * padding.y));
}
