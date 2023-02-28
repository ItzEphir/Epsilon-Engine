#include "ImageButton.h"
#include "ImageButton.h"

ImageButton::ImageButton(std::shared_ptr<sf::RenderWindow> rw, std::shared_ptr<sf::Font> font) : UsualButton(rw, font), image(rw)
{

}

void ImageButton::Create(sf::Vector2f position, sf::Vector2f size, sf::Color color, Mode imageModeX, Mode imageModeY, Mode textModeX, Mode textModeY)
{

}

void ImageButton::Create(sf::Vector2f position, sf::Vector2f size, sf::Color color, CMode imageMode, CMode textMode)
{

}

void ImageButton::Create(sf::Vector2f position, sf::Vector2f size, sf::Color color, sf::Color textColor, Mode imageModeX, Mode imageModeY, Mode textModeX, Mode textModeY)
{

}

void ImageButton::Create(sf::Vector2f position, sf::Vector2f size, sf::Color color, sf::Color textColor, CMode imageMode, CMode textMode)
{

}

void ImageButton::Update()
{
	ISCREATED;
}
