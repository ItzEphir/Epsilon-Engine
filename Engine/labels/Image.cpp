#include "Image.h"

Image::Image() : Drawable(), image(), texture(), sprite()
{

}

void Image::Create(sf::Vector2f position, sf::Vector2f scale, std::string filename, PositionMode positionMode)
{
    LoadFromFile(filename);
    setPosition(position);
    setScale(scale);
    setPositionMode(positionMode);
}

void Image::Update()
{
    if (takenImage)
    {
        texture.loadFromImage(image);
        sprite.setTexture(texture);
        takenImage = false;
    }

    if (takenTexture)
    {
        image = texture.copyToImage();
        sprite.setTexture(texture);
    }

    if (takenSprite)
    {
        image = sprite.getTexture()->copyToImage();
        texture.loadFromImage(image);
    }
}

void Image::Draw()
{
    window->draw(sprite);
}

void Image::countSize()
{
    setSize(sf::Vector2f(image.getSize().x, image.getSize().y));
}
