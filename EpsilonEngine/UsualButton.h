#pragma once
#include "Button.h"

class UsualButton :
    public Button
{
public:
    UsualButton(std::shared_ptr<sf::RenderWindow> rw, std::shared_ptr<sf::Font> font);

    virtual void Update() override;

private:
    bool alreadyPressed;
};

