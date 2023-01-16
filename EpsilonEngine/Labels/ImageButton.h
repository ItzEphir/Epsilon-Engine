#pragma once
#include "Button.h"

class ImageButton :
    public Button
{
public:
    ImageButton(std::shared_ptr<sf::RenderWindow> rw);

    virtual void Create(sf::Vector2f position, sf::Vector2f size, sf::Color color, sf::Texture& texture, CMode imageMode);
    virtual void Create(sf::Vector2f position, sf::Vector2f size, sf::Color color, sf::Texture& texture, Mode imageModeX, Mode imageModeY);

    virtual void Update() override;

    virtual sf::Text getText()
    {
        return sf::Text();
    }

    virtual sf::String getMessage()
    {
        return "";
    }
};

