#include "StartScreen.h"

void StartScreen::Update()
{
	switch (loading)
	{
	case 0:
		
		break;
	case 1:
		firstLoading();
		break;
	case 2:
		secondLoading();
		break;
	case 3:
		thirdLoading();
		break;
	default:
		break;
	}

	if (loading == lastloading)
	{
		setEnded(true);
	}

	for (int i = 0; i < drawables.size(); i++)
	{
		drawables[i]->Update();
	}

	loading++;
}

void StartScreen::Draw()
{
	for (int i = 0; i < drawables.size(); i++)
	{
		drawables[i]->Draw();
	}

    RenderImage img = RenderImage(window, "src/pngs/start/Light.png");
    img.setPosition({ 100, 100 });
    img.setScale({ 1, 1 });
    img.Centralize();
    img.Draw();
}

void StartScreen::Load()
{
	Background background = { window, {44, 52, 56, 255} };
	drawables.push_back(std::make_shared<Background>(background));

	RenderImage image = { window, "src/pngs/start/Light.png" };
	image.setPosition(sf::Vector2f(window->getSize().x / 2, window->getSize().y / 2));
	image.setScale(sf::Vector2f(1, 1));
	image.Centralize();
	drawables.push_back(std::make_shared<RenderImage>(image));

	RenderText text = RenderText(window, font, "Epsilon Engine", sf::Vector2f(window->getSize().x / 2, window->getSize().y / 2 + 100), 30);
	text.Centralize();
	drawables.push_back(std::make_shared<RenderText>(text));

	Rect slider = Rect(window, sf::Vector2f(window->getSize().x / 2 - 200, window->getSize().y / 2 + 150), sf::Vector2f(2, 10));
	slider.setColor(sf::Color::White);
	drawables.push_back(std::make_shared<Rect>(slider));
}

void StartScreen::firstLoading()
{
	std::shared_ptr<Rect> sl = std::dynamic_pointer_cast<Rect>(drawables[3]);
	sl->setSize(sf::Vector2f(rand() % 151, 10));
	Sleep(rand() % 4001);
}


void StartScreen::secondLoading()
{
	nextScreen = std::make_shared<Menu>(Menu(window, font));
	std::shared_ptr<Rect> sl = std::dynamic_pointer_cast<Rect>(drawables[3]);
	sl->setSize(sf::Vector2f(150 + rand() % 151, 10));
    Sleep(rand() % 4001);
}

void StartScreen::thirdLoading()
{
    std::shared_ptr<Rect> sl = std::dynamic_pointer_cast<Rect>(drawables[3]);
    sl->setSize(sf::Vector2f(400, 10));
	Sleep(rand() % 3001);
}
