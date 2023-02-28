#include "Drawable.h"

void Drawable::Create(sf::Vector2f position, sf::Vector2f size, sf::Vector2f scale, PositionMode positionMode)
{
    setPosition(position);
    setSize(size);
    setScale(scale);
    setPositionMode(positionMode);
}

void Drawable::countPosition()
{
    switch (positionMode.modeX)
    {
    case Mode::left:
        position.x = originalPosition.x;
        break;
    case Mode::center:
        position.x = originalPosition.x + size.x / 2;
        break;
    case Mode::right:
        position.x = originalPosition.x + size.x;
        break;
    default:
        throw PositionModeException("Trying to compare modeX with top/bottom/other");
    }

    switch (positionMode.modeY)
    {
    case Mode::top:
        position.y = originalPosition.y;
        break;
    case Mode::center:
        position.y = originalPosition.y + size.y / 2;
        break;
    case Mode::bottom:
        position.y = originalPosition.y + size.y;
        break;
    default:
        throw PositionModeException("Trying to compare modeY with left/right/other");
    }
}
