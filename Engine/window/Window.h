#pragma once
#include "SFML/Graphics.hpp"

class Window : public sf::RenderWindow
{
public:

	Window();

	Window(sf::VideoMode mode, sf::VideoMode countedMode, const sf::String &title, sf::Uint32 style, const sf::ContextSettings &contextSettings = sf::ContextSettings());

	Window(sf::WindowHandle handle, const sf::ContextSettings &contextSettings = sf::ContextSettings());

	void create(sf::VideoMode mode, sf::VideoMode countedMode, const sf::String &title, sf::Uint32 style = sf::Style::Default, const sf::ContextSettings &contextSettings = sf::ContextSettings());

	void create(sf::WindowHandle handle, const sf::ContextSettings& contextSettings = sf::ContextSettings());

#pragma region GETTERS

	sf::VideoMode getMode()
	{
		return mode;
	}

	sf::VideoMode getCountedMode()
	{
		return countedMode;
	}
	
	sf::VideoMode getDesktopMode()
	{
		return fullScreen;
	}

	sf::String getTitle()
	{
		return title;
	}

	sf::Uint32 getStyle()
	{
		return style;
	}

	sf::Vector2f getSizef()
	{
		return size;
	}

	sf::Vector2f getPositionf()
	{
		return position;
	}

	sf::Image getIcon()
	{
		return icon;
	}

#pragma endregion

#pragma region SETTERS

	void setTitle(sf::String newTitle)
	{
		title = newTitle;
		Window::setTitle(title);
	}

	void setSize(sf::Vector2f newSize)
	{
		size = newSize;
		Window::setSize(size);
	}

	void setStyle(sf::Uint32 newStyle)
	{
		style = newStyle;
		create(mode, countedMode, title, style, contextSettings);
	}

	void setPosition(sf::Vector2f newPosition)
	{
		position = newPosition;
		Window::setPosition(position);
	}

	void setIcon(sf::Image image)
	{
		icon = image;
		Window::setIcon(image);
	}

#pragma endregion

protected:

	void Initialize();

private:

	sf::VideoMode mode;
	sf::VideoMode countedMode;
	sf::VideoMode fullScreen;
	sf::String title;
	sf::Uint32 style = sf::Style::Default;
	sf::ContextSettings contextSettings;

	sf::Vector2f size;
	sf::Vector2f position;

	sf::Image icon;
};

