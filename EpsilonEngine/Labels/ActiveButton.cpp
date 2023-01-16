#include "ActiveButton.h"

ActiveButton::ActiveButton(std::shared_ptr<sf::RenderWindow> rw, std::shared_ptr<sf::Font> font) 
	: UsualButton(rw, font) { }

void ActiveButton::Create(sf::Vector2f position, sf::Vector2f size, sf::Color color, sf::Color activeColor, sf::Color textColor, sf::Color activeTextColor, sf::String message, unsigned int fontSize, CMode mode)
{
	turnOn();
	UsualButton::Create(position, size, color, textColor, message, fontSize, mode);
	setActiveColor(activeColor);
	setActiveTextColor(activeTextColor);
}

void ActiveButton::Create(sf::Vector2f position, sf::Vector2f size, sf::Color color, sf::Color textColor, sf::String message, unsigned int fontSize, CMode mode)
{
	turnOn();
	UsualButton::Create(position, size, color, textColor, message, fontSize, mode);
	setActiveColor(color);
	setActiveTextColor(textColor);
}

void ActiveButton::Create(sf::Vector2f position, sf::Vector2f size, sf::Color color, sf::Color activeColor, sf::Color textColor, sf::Color activeTextColor, sf::String message, unsigned int fontSize, Mode modeX, Mode modeY)
{
	turnOn();
	UsualButton::Create(position, size, color, textColor, message, fontSize, modeX, modeY);
	setActiveColor(activeColor);
	setActiveTextColor(activeTextColor);
}

void ActiveButton::Create(sf::Vector2f position, sf::Vector2f size, sf::Color color, sf::Color textColor, sf::String message, unsigned int fontSize, Mode modeX, Mode modeY)
{
	turnOn();
	UsualButton::Create(position, size, color, textColor, message, fontSize, modeX, modeY);
	setActiveColor(color);
	setActiveTextColor(textColor);
}

void ActiveButton::Draw()
{
	ISCREATED
	if (Find())
	{
		takeRect()->setFillColor(getActiveColor());
		takeText()->setFillColor(getActiveTextColor());
	}
	else
	{
		if (getColor() == getActiveColor())
			takeRect()->setFillColor(getColor());

		if (getTextColor() == getActiveTextColor())
			takeText()->setFillColor(getTextColor());
	}

	UsualButton::Draw();
}

