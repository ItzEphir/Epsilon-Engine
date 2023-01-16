#pragma once
#include <memory>
#include "SFML/Graphics.hpp"
#include <vector>
#include "Labels/IDrawable.h"

class IScreen
{
public:

	IScreen(std::shared_ptr<sf::RenderWindow> window) : window(window), mode(sf::Style::Default) { }

	virtual void Update() = 0;

	virtual void Draw() = 0;

	virtual std::shared_ptr<IScreen> Next()
	{
		return nextScreen;
	}

	virtual bool isEnded()
	{
		return ended;
	}

	virtual void Load() = 0;

	virtual unsigned int getMode()
	{
		return mode;
	}

protected:

	virtual void setEnded(bool newEnded = true)
	{
		this->ended = newEnded;
	}

	std::shared_ptr<sf::RenderWindow> window;

	std::shared_ptr<IScreen> nextScreen;
	
	virtual void setMode(unsigned int newMode)
	{
		mode = newMode;
		window->create(sf::VideoMode(window->getSize().x, window->getSize().y), "Epsilon Engine", mode);
	}

private:

	bool ended = false;
	
	unsigned int mode;

};

