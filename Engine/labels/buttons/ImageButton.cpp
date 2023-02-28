#include "ImageButton.h"

ImageButton::ImageButton() : Button(), image()
{

}

void ImageButton::Create(sf::Vector2f position, sf::Vector2f size, sf::Vector2f scale, sf::Color color, float radius, sf::String filename, PositionMode mode, PositionMode imageMode)
{
    Button::Create(position, size, scale, color, radius, mode);
    image.LoadFromFile(filename);
    setImagePositionMode(imageMode);
}

void ImageButton::Draw()
{
    Button::Draw();
    image.Draw();
}

void ImageButton::countImagePosition()
{
    switch (image.getPositionMode().modeX)
    {
    case Mode::left:
        image.setPosition(sf::Vector2f(position.x, image.getPosition().y));
        break;
    case Mode::center:
        image.setPosition(sf::Vector2f(position.x + size.x / 2 - image.getSize().x / 2, image.getPosition().y));
        break;
    case Mode::right:
        image.setPosition(sf::Vector2f(position.x + size.x - image.getSize().x, image.getPosition().y));
        break;
    default:
        throw PositionModeException("Trying to compare modeX with top/bottom/other");
    }

    switch (image.getPositionMode().modeY)
    {
    case Mode::top:
        image.setPosition(sf::Vector2f(image.getPosition().x, position.y));
        break;
    case Mode::center:
        image.setPosition(sf::Vector2f(image.getPosition().x, position.y + size.y / 2 - image.getSize().y / 2));
        break;
    case Mode::bottom:
        image.setPosition(sf::Vector2f(image.getPosition().x, position.y + size.y - image.getSize().y));
        break;
    default:
        throw PositionModeException("Trying to compare modeY with left/right/other");
    }
}

void ImageButton::countSize()
{
    float imageLength = image.takeTexture().getSize().x * image.getScale().x;
    float imageHeight = image.takeTexture().getSize().y * image.getScale().y;

    setSize(sf::Vector2f(imageLength, imageHeight));
}
