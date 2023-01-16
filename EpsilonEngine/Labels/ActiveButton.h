#pragma once
#include "UsualButton.h"

class ActiveButton :
    public UsualButton
{
public:
    ActiveButton(std::shared_ptr<sf::RenderWindow> rw, std::shared_ptr<sf::Font> font);

    virtual void Create(sf::Vector2f position, sf::Vector2f size, sf::Color color, sf::Color activeColor, sf::Color textColor, sf::Color activeTextColor, sf::String message, unsigned int fontSize, CMode mode);
    virtual void Create(sf::Vector2f position, sf::Vector2f size, sf::Color color, sf::Color textColor, sf::String message, unsigned int fontSize, CMode mode) override;
    virtual void Create(sf::Vector2f position, sf::Vector2f size, sf::Color color, sf::Color activeColor, sf::Color textColor, sf::Color activeTextColor, sf::String message, unsigned int fontSize, Mode modeX, Mode modeY);
    virtual void Create(sf::Vector2f position, sf::Vector2f size, sf::Color color, sf::Color textColor, sf::String message, unsigned int fontSize, Mode modeX, Mode modeY) override;

    virtual void Draw() override;

    sf::Color getActiveColor()
    {
        ISCREATED;
        return activeColor;
    }
    
    sf::Color getActiveTextColor()
    {
        ISCREATED;
        return activeTextColor;
    }

protected:
    void setActiveColor(sf::Color newActiveColor)
    {
        ISCREATED
        activeColor = newActiveColor;
    }

    void setActiveTextColor(sf::Color newActiveTextColor)
    {
        ISCREATED
        activeTextColor = newActiveTextColor;
    }

private:
    sf::Color activeColor;
    sf::Color activeTextColor;
};

