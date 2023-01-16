#include "Menu.h"

void Menu::Draw()
{
}

void Menu::Update()
{
}

void Menu::Load()
{
	sf::VideoMode vm = sf::VideoMode(1280, 720);
	window->create(vm, "Epsilon Engine", sf::Style::Default);

	// nextScreen.reset(this);
}
