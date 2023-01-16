#pragma once
#include "SFML/Graphics.hpp"

class IDrawable
{
public:

	IDrawable(std::shared_ptr<sf::RenderWindow> window) : rw(window) {}

	virtual void Draw() = 0;
	virtual void Update() = 0;

protected:
	std::shared_ptr<sf::RenderWindow> getWindow()
	{
		return rw;
	}

	void setWindow(std::shared_ptr<sf::RenderWindow> rw)
	{
		this->rw = rw;
	}

private:
	std::shared_ptr<sf::RenderWindow> rw;
};

