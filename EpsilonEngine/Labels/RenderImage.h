#pragma once
#include "IDrawable.h"
#include <iostream>

class RenderImage : public IDrawable
{
public:

    RenderImage(std::shared_ptr<sf::RenderWindow> window) : IDrawable(window)
    {
        image = sf::Image();
        texture = sf::Texture();
        sprite = sf::Sprite();

        position = sf::Vector2f();
        scale = sf::Vector2f();
    }

    RenderImage(std::shared_ptr<sf::RenderWindow> window, std::string filename);

    RenderImage(std::shared_ptr<sf::RenderWindow> window, sf::Image image);

    RenderImage(std::shared_ptr<sf::RenderWindow> window, sf::Texture texture);

    RenderImage(std::shared_ptr<sf::RenderWindow> window, sf::Sprite sprite);

    virtual void LoadFromFile(std::string filename)
    {
        image.loadFromFile(filename);
        texture.loadFromImage(image);
        sprite.setTexture(texture);
    }

    virtual void LoadFromImage(sf::Image image)
    {
        this->image = image;
        texture.loadFromImage(image);
        sprite.setTexture(texture);
    }

    virtual void LoadFromTexture(sf::Texture texture)
    {
        this->texture = texture;
        image = texture.copyToImage();
        sprite.setTexture(texture);
    }

    virtual void LoadFromSprite(sf::Sprite sprite)
    {
        this->sprite = sprite;
        image = sprite.getTexture()->copyToImage();
        texture.loadFromImage(image);
    }

    virtual void Update() override;

    virtual void Draw() override
    {
        sprite.setTexture(texture);
        getWindow()->draw(sprite);
    }

    virtual sf::Vector2f getPosition()
    {
        return position;
    }

    virtual void setPosition(sf::Vector2f newPosition)
    {
        if (newPosition.x > 0 && newPosition.x < getWindow()->getSize().x &&
            newPosition.y > 0 && newPosition.y < getWindow()->getSize().y)
        {
            position = newPosition;
            sprite.setPosition(position);
        }
    }

    virtual sf::Vector2f getScale()
    {
        return scale;
    }

    virtual void setScale(sf::Vector2f newScale)
    {
        scale = newScale;
        sprite.setScale(scale);
    }

    virtual sf::Image& takeImage()
    {
        takenImage = true;
        return image;
    }

    virtual sf::Texture& takeTexture()
    {
        takenTexture = true;
        return texture;
    }

    virtual sf::Sprite& takeSprite()
    {
        takenSprite = true;
        return sprite;
    }

    virtual void Centralize(bool turn = true);

protected:

    std::shared_ptr<sf::RenderWindow> window;

private:

    bool takenImage = false;
    bool takenTexture = false;
    bool takenSprite = false;
    bool centralized = false;

    sf::Vector2f position;
    sf::Vector2f scale;

    sf::Image image;
    sf::Texture texture;
    sf::Sprite sprite;

};

