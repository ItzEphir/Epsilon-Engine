#pragma once
#include "IDrawable.h"

class RenderText : public IDrawable
{
public:

	RenderText(std::shared_ptr<sf::RenderWindow> window) : IDrawable(window)
	{
		text = sf::Text();
		str = sf::String();
		size = sf::Vector2f();
		position = sf::Vector2f();
		color = sf::Color::White;
		text.setFillColor(color);
	}

	RenderText(std::shared_ptr<sf::RenderWindow> window, std::shared_ptr<sf::Font> font, sf::String str, unsigned int characterSize = 14, sf::Color color = sf::Color::White);

	RenderText(std::shared_ptr<sf::RenderWindow> window, std::shared_ptr<sf::Font> font, sf::String str, sf::Vector2f position, unsigned int characterSize = 14, sf::Color color = sf::Color::White);

	virtual void setPosition(sf::Vector2f newPosition)
	{
		position = newPosition;
	}

	virtual sf::Vector2f getPosition()
	{
		return position;
	}

	virtual void setString(sf::String newStr)
	{
		str = newStr;
		text.setString(str);
		size = sf::Vector2f(text.getLocalBounds().width, text.getLocalBounds().height);
	}

	virtual sf::Vector2f getSize()
	{
		return size;
	}

	virtual int getLength()
	{
		return str.getSize();
	}

	virtual void Update() override
	{
		
	}

	virtual void Draw() override
	{
		getWindow()->draw(text);
	}

	virtual void Centralize(bool turn = true);

protected:

private:

	unsigned int characterSize = 14;
	
	bool centralized = false;

	sf::Text text;
	sf::String str;
	sf::Vector2f size;
	sf::Vector2f position;
	sf::Color color;

	std::shared_ptr<sf::Font> font;
};

