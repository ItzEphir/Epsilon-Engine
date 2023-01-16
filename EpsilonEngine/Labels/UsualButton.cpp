#include "UsualButton.h"
#include <iostream>

UsualButton::UsualButton(std::shared_ptr<sf::RenderWindow> rw, std::shared_ptr<sf::Font> font)
	:Button(rw), font(font), alreadyPressed(false) 
{ 
	text = sf::Text();
}

void UsualButton::Create(sf::Vector2f position, sf::Vector2f size, sf::Color color, CMode mode)
{
	Button::Create(position, size, color, mode);
}

void UsualButton::Create(sf::Vector2f position, sf::Vector2f size, sf::Color color, Mode modeX, Mode modeY)
{
	Button::Create(position, size, color, modeX, modeY);
}

void UsualButton::Create(sf::Vector2f position, sf::Vector2f size, sf::Color color, sf::Color textColor, sf::String message, unsigned int fontSize, CMode mode)
{
	Button::Create(position, size, color, mode);
	setTextColor(textColor);
	setMessage(message);
	setFontSize(fontSize);
}

void UsualButton::Create(sf::Vector2f position, sf::Vector2f size, sf::Color color, sf::Color textColor, sf::String message, unsigned int fontSize, Mode modeX, Mode modeY)
{
	Button::Create(position, size, color, modeX, modeY);
	setTextColor(textColor);
	setMessage(message);
	setFontSize(fontSize);
}

void UsualButton::Update()
{
	if (Find())
	{
		setAimed(true);
		if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
		{
			setPressed(true);
			alreadyPressed = true;
		}
		else
		{
			setPressed(false);
			if (alreadyPressed)
			{
				alreadyPressed = false;
				setReleased(true);
			}
			else
			{
				setReleased(false);
			}
		}
	}
	else
	{
		setAimed(false);
	}

	if (getAimed())
	{
		whenAimed();
	}
	if (getPressed())
	{
		whenPressed();
	}
	if (getReleased())
	{
		whenReleased();
	}
}

// ToDo: сделать реализацию
void UsualButton::countTextPosition()
{
	switch (getMode().modeX)
	{
	case Mode::right:
		break;
	case Mode::center:
		break;
	case Mode::left:
		break;
	}

	switch (getMode().modeY)
	{
	case Mode::right:
		break;
	case Mode::center:
		break;
	case Mode::left:
		break;
	}
}

void UsualButton::countSize()
{
	float textLength = text.getLocalBounds().width;
	float textHeight = text.getLocalBounds().height;

	diplacement = sf::Vector2f(-textLength / message.getSize(), -textHeight / 2);
	setSize(sf::Vector2f(textLength - 2 * diplacement.x, textHeight - 2 * diplacement.y));
}
