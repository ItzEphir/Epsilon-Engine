#pragma once
#include "IScreen.h"

class Menu :
    public IScreen
{
public:

    Menu(std::shared_ptr<sf::RenderWindow> window) : IScreen(window) 
    {
        drawables = std::vector<IDrawable>();
    }

    virtual void Draw() override;
    virtual void Update() override;
    virtual void Load() override;

protected:

    std::vector<IDrawable> drawables;

private:

};

