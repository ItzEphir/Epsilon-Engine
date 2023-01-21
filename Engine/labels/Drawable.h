#pragma once
#include "../window/Window.h"

class Drawable
{
public:

	Drawable(std::shared_ptr<Window> window) : window(window) {}

	virtual void Draw() = 0;
	virtual void Update() = 0;

    virtual sf::Vector2f getPosition()
    {
        return position;
    }

    virtual void setPosition(sf::Vector2f newPosition)
    {
        position = newPosition;
    }

protected:
	
    std::shared_ptr<Window> window;

    sf::Vector2f position;

private:

};

