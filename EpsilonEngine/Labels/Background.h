#pragma once
#include "Rect.h"

class Background : public Rect
{
public:

	Background(std::shared_ptr<sf::RenderWindow> window, sf::Color color) 
		: Rect(window, sf::Vector2f(0, 0), sf::Vector2f(window->getSize().x, window->getSize().y))
	{
		setColor(color);
	}

protected:

private:

};

