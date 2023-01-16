#include "RenderImage.h"

RenderImage::RenderImage(std::shared_ptr<sf::RenderWindow> window, std::string filename) : IDrawable(window)
{
    image = sf::Image();
    texture = sf::Texture();

    position = sf::Vector2f();
    scale = sf::Vector2f();

    if (!image.loadFromFile(filename))
    {
        std::cout << "image wasn`t loaded" << std::endl;
    }
    if (!texture.loadFromImage(image))
    {
        std::cout << "texture wasn`t loaded" << std::endl;
    }
}

RenderImage::RenderImage(std::shared_ptr<sf::RenderWindow> window, sf::Image image) : IDrawable(window), image(image)
{
    texture = sf::Texture();
    sprite = sf::Sprite();

    position = sf::Vector2f();
    scale = sf::Vector2f();

    texture.loadFromImage(image);
    sprite.setTexture(texture);
}

RenderImage::RenderImage(std::shared_ptr<sf::RenderWindow> window, sf::Texture texture) : IDrawable(window), texture(texture)
{
    image = sf::Image();
    sprite = sf::Sprite();

    position = sf::Vector2f();
    scale = sf::Vector2f();

    image = texture.copyToImage();
    sprite.setTexture(this->texture);
}

RenderImage::RenderImage(std::shared_ptr<sf::RenderWindow> window, sf::Sprite sprite) : IDrawable(window), sprite(sprite)
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
    else if(!turn && centralized)
    {
        position = sf::Vector2f(
            position.x + texture.getSize().x * scale.x / 2,
            position.y + texture.getSize().y * scale.y / 2
        );
        sprite.setPosition(position);
        centralized = false;
    }
}
