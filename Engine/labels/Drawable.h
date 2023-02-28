#pragma once
#include "../window/Window.h"
#include "PositionMode.h"

class Drawable
{
public:

	Drawable()
    {
        window = Window::getInstance();
    }

	virtual void Draw() = 0;
	virtual void Update() = 0;
    
    sf::Vector2f getOriginalPosition()
    {
        return originalPosition;
    }

    virtual sf::Vector2f getPosition()
    {
        return position;
    }

    sf::Vector2f getOriginalSize()
    {
        return originalSize;
    }

    virtual sf::Vector2f getSize()
    {
        return size;
    }

    virtual sf::Vector2f getScale()
    {
        return scale;
    }

    virtual PositionMode getPositionMode()
    {
        return positionMode;
    }

    virtual void setPosition(sf::Vector2f newPosition)
    {
        position = newPosition;
        originalPosition = newPosition;
        countPosition();
    }

    virtual void setSize(sf::Vector2f newSize)
    {
        originalSize = newSize;
        size = newSize;
        size.x *= scale.x;
        size.y *= scale.y;
    }

    virtual void setScale(sf::Vector2f newScale)
    {
        scale = newScale;
        size.x *= scale.x;
        size.y *= scale.y;
    }

    virtual void setPositionMode(PositionMode newPositionMode)
    {
        positionMode = newPositionMode;
        countPosition();
    }

    void setWindow(std::shared_ptr<Window> newWindow)
    {
        window = newWindow;
    }

    protected:

    virtual void countSize() = 0;

    void Create(sf::Vector2f position, sf::Vector2f size, sf::Vector2f scale, PositionMode positionMode);

    virtual void countPosition();

    std::shared_ptr<Window> window;

    sf::Vector2f originalPosition;

    sf::Vector2f position;

    sf::Vector2f originalSize;

    sf::Vector2f size;

    sf::Vector2f scale;

    PositionMode positionMode;

private:

};

