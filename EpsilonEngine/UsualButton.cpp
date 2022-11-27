#include "UsualButton.h"

UsualButton::UsualButton(std::shared_ptr<sf::RenderWindow> rw, std::shared_ptr<sf::Font> font)
	:Button(rw, font), alreadyPressed(false) { }

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
