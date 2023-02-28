#pragma once
#include "Drawable.h"

class Image : public Drawable
{
public:

    Image();

    void Create(sf::Vector2f position, sf::Vector2f scale, std::string filename, PositionMode positionMode = PositionMode::DEFAULT);

    virtual void LoadFromFile(std::string filename)
    {
        image.loadFromFile(filename);
        texture.loadFromImage(image);
        sprite.setTexture(texture);
        setSize(sf::Vector2f(texture.getSize()));
    }

    virtual void LoadFromImage(sf::Image image)
    {
        this->image = image;
        texture.loadFromImage(image);
        sprite.setTexture(texture);
        setSize(sf::Vector2f(texture.getSize()));
    }

    virtual void LoadFromTexture(sf::Texture texture)
    {
        this->texture = texture;
        image = texture.copyToImage();
        sprite.setTexture(this->texture);
        setSize(sf::Vector2f(texture.getSize()));
    }

    virtual void LoadFromSprite(sf::Sprite sprite)
    {
        this->sprite = sprite;
        image = sprite.getTexture()->copyToImage();
        texture.loadFromImage(image);
        setSize(sf::Vector2f(texture.getSize()));
    }

    virtual void Update() override;

    virtual void Draw() override;

    virtual void setPosition(sf::Vector2f newPosition) override
    {
        Drawable::setPosition(newPosition);
        sprite.setPosition(position);
    }

    virtual void setSize(sf::Vector2f newSize) override
    {
        Drawable::setSize(newSize);
        setScale(sf::Vector2f(texture.getSize().x / size.x, texture.getSize().y / size.y));
    }

    virtual void setScale(sf::Vector2f newScale) override
    {
        Drawable::setScale(newScale);
        sprite.setScale(scale);
    }

    virtual void setPositionMode(PositionMode newPositionMode) override
    {
        Drawable::setPositionMode(newPositionMode);
        setPosition(position);
    }

    virtual void countSize() override;

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

protected:

private:

    bool takenImage = false;
    bool takenTexture = false;
    bool takenSprite = false;

    sf::Image image;
    sf::Texture texture;
    sf::Sprite sprite;
};

