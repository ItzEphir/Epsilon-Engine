#include "Application.h"

void Application::Load()
{
	
	// icon = sf::Image();
	// icon.loadFromFile("ico/Epsilon.png");
	// window->setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());
	screen.reset(new StartScreen(window, font));

	font = std::make_shared<sf::Font>();
	font->loadFromFile("src/fonts/Nexa-Trial-Bold.ttf");

	sf::Image icon;
	icon.loadFromFile("src/icons/LightIcon.png");
	
	window->setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());

	screen->Load();
}

void Application::Update()
{
	if (screen->isEnded())
	{
		screen = screen->Next();
		screen->Load();
	}

	screen->Update();
}

void Application::Draw()
{
	screen->Draw();
}

void Application::Close()
{
	window->close();
}
