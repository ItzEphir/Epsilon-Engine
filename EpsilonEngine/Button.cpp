#include "Button.h"

void Button::Draw()
{
	ISCREATED
}

void Button::Update()
{
	ISCREATED
}


void Button::Init()
{
	aimed = false;
	pressed = false;
	released = false;
}

void Button::Create(sf::Vector2f position, sf::Vector2f size, sf::Color color, sf::Color textColor, sf::String message, unsigned int fontSize, TextMode mode)
{
	this->position = position;
	this->size = size;
	this->color = color;
	this->textColor = textColor;
	this->message = message;
	this->fontSize = fontSize;
	this->mode = mode;

	created = true;
}

void Button::Create(sf::Vector2f position, sf::Vector2f size, sf::Color color, sf::Color textColor, sf::String message, unsigned int fontSize, Mode modeX, Mode modeY)
{
	setPosition(position);
	setSize(size);
	setColor(color);
	setTextColor(textColor);
	this->message = message;
	this->fontSize = fontSize;
	this->mode = TextMode(modeX, modeY);

	text = sf::Text(message, *font, fontSize);

	if (this->size.x == 0 && this->size.y == 0)
	{
		countSize();
	}
	else
	{
		diplacement = sf::Vector2f(0, 0);
	}

	setPosition(getPosition() + diplacement);

	created = true;
}

bool Button::Find()
{
	ISCREATED

	sf::Vector2i mouse = sf::Mouse::getPosition();

	return (position.x < mouse.x&& position.y < mouse.y&& position.x + size.x > mouse.x&& position.y + size.y > mouse.y) ? true : false;
}

void Button::countSize()
{
	float textLength = text.getLocalBounds().width;
	float textHeight = text.getLocalBounds().height;

	diplacement = sf::Vector2f(-textLength / message.getSize(), -textHeight / 2);
	size = sf::Vector2f(textLength - 2 * diplacement.x, textHeight - 2 * diplacement.y);
}

void Button::countTextPosition()
{
	switch (mode.modeX)
	{
	case Mode::right:
		break;
	case Mode::center:
		break;
	case Mode::left:
		break;
	}

	switch (mode.modeY)
	{
	case Mode::right:
		break;
	case Mode::center:
		break;
	case Mode::left:
		break;
	}
}