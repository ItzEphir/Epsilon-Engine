#include "TextButton.h"


void TextButton::Create(sf::Vector2f position, sf::Vector2f size, sf::Color color, sf::Color textColor, sf::String message, unsigned int fontSize, CMode mode)
{
    Button::Create(position, size, color, mode);
    setTextColor(textColor);
    setMessage(message);
    setFontSize(fontSize);
}

void TextButton::Create(sf::Vector2f position, sf::Vector2f size, sf::Color color, sf::Color textColor, sf::String message, unsigned int fontSize, Mode modeX, Mode modeY)
{
    Button::Create(position, size, color, modeX, modeY);
    setTextColor(textColor);
    setMessage(message);
    setFontSize(fontSize);
}

void TextButton::Update()
{
    ISCREATED;

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

void TextButton::Draw()
{
    ISCREATED;
    takeRectangle().Draw();
    text.Draw();
}

void TextButton::countTextPosition()
{
    switch (getMode().modeX)
    {
    case Mode::right:
        text.setPosition(sf::Vector2f(
            textPosition.x,
            text.getPosition().y
        ));
        break;
    case Mode::center:
        text.setPosition(sf::Vector2f(
            textPosition.x - text.getSize().x / 2,
            text.getPosition().y
        ));
        break;
    case Mode::left:
        text.setPosition(sf::Vector2f(
            textPosition.x - text.getSize().x,
            text.getPosition().y
        ));
        break;
    }

    switch (getMode().modeY)
    {
    case Mode::right:
        text.setPosition(sf::Vector2f(
            text.getPosition().x,
            textPosition.y
        ));
        break;
    case Mode::center:
        text.setPosition(sf::Vector2f(
            text.getPosition().x,
            textPosition.y - text.getSize().y / 2
        ));
        break;
    case Mode::left:
        text.setPosition(sf::Vector2f(
            text.getPosition().x,
            textPosition.y - text.getSize().y
        ));
        break;
    }
}

void TextButton::countSize()
{
    float textLength = text.getSize().x;
    float textHeight = text.getSize().y;

    diplacement = sf::Vector2f(-textLength / text.getString().getSize(), -textHeight / 2);
    setSize(sf::Vector2f(textLength - 2 * diplacement.x, textHeight - 2 * diplacement.y));
}



