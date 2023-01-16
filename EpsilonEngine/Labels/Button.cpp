#include "Button.h"

void Button::Draw()
{
	ISCREATED;
	getWindow()->draw(rect);
}

void Button::Init()
{
	aimed = false;
	pressed = false;
	released = false;
}

void Button::Create(sf::Vector2f position, sf::Vector2f size, sf::Color color, CMode mode = CMode(Mode::right, Mode::center))
{
	created = true;
	setSize(size);
	setPosition(position);
	setColor(color);
	setMode(mode);

	setPosition(getPosition());
}

void Button::Create(sf::Vector2f position, sf::Vector2f size, sf::Color color, Mode modeX, Mode modeY)
{
	created = true;
	setSize(size);
	setPosition(position);
	setColor(color);
	setMode(CMode(modeX, modeY));

	setPosition(getPosition());
}

bool Button::Find()
{
	ISCREATED

	sf::Vector2i mouse = sf::Mouse::getPosition(*getWindow());

	return (position.x < mouse.x && position.y < mouse.y && position.x + size.x > mouse.x && position.y + size.y > mouse.y) ? true : false;
}