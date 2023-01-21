#pragma once
#include "SFML/Graphics.hpp"
#include "IScreen.h"
#include "StartScreen.h"

#ifdef _DEBUG
#include <iostream>
#endif

class Application
{
public:

	Application(std::shared_ptr<sf::RenderWindow> window) : window(window)
	{
		font = std::make_shared<sf::Font>();
		font->loadFromFile("src/fonts/Nexa-Trial-Bold.ttf");
	}

	virtual void Load();

	virtual void Update();
	
	virtual void Draw();

	virtual void Close();

protected:

	std::shared_ptr<sf::RenderWindow> window;
	std::shared_ptr<sf::Font> font;
	sf::Image icon;

	std::shared_ptr<IScreen> screen;

};

