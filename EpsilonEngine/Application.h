#pragma once
#include "SFML/Graphics.hpp"

#ifdef _DEBUG
#include <iostream>
#endif

class Application final
{
public:
	Application(std::shared_ptr<sf::RenderWindow> _window)
	{
		window = _window;
	}

	void Load();

	void Update();
	
	void Draw();

	void Close();

protected:
	std::shared_ptr<sf::RenderWindow> window;
	sf::Image icon;
};

