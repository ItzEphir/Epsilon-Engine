#include "Window.h"

Window::Window() 
	: RenderWindow()
{
	Initialize();
}

Window::Window(sf::VideoMode mode, sf::VideoMode countedMode, const sf::String &title, sf::Uint32 style, const sf::ContextSettings &contextSettings)
	: RenderWindow(mode, title, style, contextSettings), mode(mode), title(title), style(style), contextSettings(contextSettings), countedMode(countedMode)
{
	size = sf::Vector2f(getSize().x, getSize().y);
	position = sf::Vector2f(getPosition().x, getPosition().y);
	Initialize();
}

Window::Window(sf::WindowHandle handle, const sf::ContextSettings &contextSettings) 
	: RenderWindow(handle, contextSettings)
{
	size = sf::Vector2f(getSize().x, getSize().y);
	position = sf::Vector2f(getPosition().x, getPosition().y);
	Initialize();
}

void Window::create(sf::VideoMode mode, sf::VideoMode countedMode, const sf::String& title, sf::Uint32 style, const sf::ContextSettings& contextSettings)
{
	RenderWindow::create(mode, title, style, contextSettings);
	this->mode = mode;
	this->title = title;
	this->style = style;
	this->contextSettings = contextSettings;
	this->countedMode = countedMode;
	size = sf::Vector2f(getSize().x, getSize().y);
	position = sf::Vector2f(getPosition().x, getPosition().y);
}

void Window::create(sf::WindowHandle handle, const sf::ContextSettings& contextSettings)
{
	RenderWindow::create(handle, contextSettings);
	size = sf::Vector2f(getSize().x, getSize().y);
	position = sf::Vector2f(getPosition().x, getPosition().y);
}

void Window::Initialize()
{
	fullScreen = sf::VideoMode::getDesktopMode();
}
