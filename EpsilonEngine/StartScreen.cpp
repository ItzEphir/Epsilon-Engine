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
	// window->draw(logo);

	// sf::Image img = sf::Image();
	// img.loadFromFile("src/pngs/start/Dark.png");
	// sf::Texture imgt = sf::Texture();
	// imgt.loadFromImage(img);
	// sf::Sprite imgs = sf::Sprite();
	// imgs.setTexture(imgt);
	// imgs.setPosition(sf::Vector2f(100, 100));

	// window->draw(imgs);
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
	// Sleep(9000);
	std::shared_ptr<Rect> sl = std::dynamic_pointer_cast<Rect>(drawables[3]);
	sl->setSize(sf::Vector2f(200, 10));
}

void StartScreen::secondLoading()
{
	nextScreen = std::make_shared<Menu>(Menu(window, font));
	Sleep(1000);
	std::shared_ptr<Rect> sl = std::dynamic_pointer_cast<Rect>(drawables[3]);
	sl->setSize(sf::Vector2f(400, 10));
}

void StartScreen::thirdLoading()
{
	// Sleep(1000);
	
}
