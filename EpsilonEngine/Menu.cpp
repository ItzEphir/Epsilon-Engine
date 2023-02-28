#include "Menu.h"

void Menu::Draw()
{
    for (auto drawable : drawables)
    {
        drawable->Draw();
    }
}

void Menu::Update()
{
    for (auto drawable : drawables)
    {
        drawable->Update();
    }
}

void Menu::Load()
{
	sf::VideoMode vm = sf::VideoMode(1280, 720);
	window->create(vm, "Epsilon Engine", sf::Style::Default);

    Background bg = Background(window, sf::Color::White);
    drawables.push_back(std::make_shared<Background>(bg));

    RenderText text = RenderText(window, font, "aboba", 30, sf::Color::Black);
    text.setPosition(sf::Vector2f(200, 200));
    text.Centralize();
    drawables.push_back(std::make_shared<RenderText>(text));
}
