#pragma once
#include "IScreen.h"
#include "Labels.hpp"

class Menu :
    public IScreen
{
public:

    Menu(std::shared_ptr<sf::RenderWindow> window, std::shared_ptr<sf::Font> font) : IScreen(window), font(font)
    {
        drawables = std::vector<std::shared_ptr<IDrawable>>();
    }

    virtual void Draw() override;
    virtual void Update() override;
    virtual void Load() override;

protected:

    std::vector<std::shared_ptr<IDrawable>> drawables;

    std::shared_ptr<sf::Font> font;

private:

};

