#include "RenderImage.h"

RenderImage::RenderImage(std::shared_ptr<Window> window, std::string filename) : Drawable(window)
{
    image = sf::Image();
    texture = sf::Texture();

    position = sf::Vector2f();
    scale = sf::Vector2f();
}

RenderImage::RenderImage(std::shared_ptr<Window> window, sf::Image image) : Drawable(window), image(image)
{
    texture = sf::Texture();
    sprite = sf::Sprite();

    position = sf::Vector2f();
    scale = sf::Vector2f();

    texture.loadFromImage(image);
    sprite.setTexture(texture);
}

RenderImage::RenderImage(std::shared_ptr<Window> window, sf::Texture texture) : Drawable(window), texture(texture)
{
    image = sf::Image();
    sprite = sf::Sprite();

    position = sf::Vector2f();
    scale = sf::Vector2f();

    image = texture.copyToImage();
    sprite.setTexture(this->texture);
}

RenderImage::RenderImage(std::shared_ptr<Window> window, sf::Sprite sprite) : Drawable(window), sprite(sprite)
{
    image = sf::Image();
    texture = sf::Texture();

    position = sf::Vector2f();
    scale = sf::Vector2f();

    image = sprite.getTexture()->copyToImage();
    texture.loadFromImage(image);
}

void RenderImage::Update()
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

void RenderImage::Centralize(bool turn)
{
    if (turn && !centralized)
    {
        position = sf::Vector2f(
            position.x - texture.getSize().x * scale.x / 2,
            position.y - texture.getSize().y * scale.y / 2
        );
        sprite.setPosition(position);
        centralized = true;
    }
    else if (!turn && centralized)
    {
        position = sf::Vector2f(
            position.x + texture.getSize().x * scale.x / 2,
            position.y + texture.getSize().y * scale.y / 2
        );
        sprite.setPosition(position);
        centralized = false;
    }
}