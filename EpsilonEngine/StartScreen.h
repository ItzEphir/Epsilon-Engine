#pragma once
#include <iostream>
#include "IScreen.h"
#include "Menu.h"
#include "Labels.hpp"
#include "windows.h"

class StartScreen : public IScreen
{
public:

    StartScreen(std::shared_ptr<sf::RenderWindow> window, std::shared_ptr<sf::Font> font) : IScreen(window), font(font)
    {
        setMode(sf::Style::None);
        drawables = std::vector<std::shared_ptr<IDrawable>>();
    }

    virtual void Update() override;

    virtual void Draw() override;

    virtual void Load() override;

protected:

    std::vector<std::shared_ptr<IDrawable>> drawables;

private:

    void firstLoading();

    void secondLoading();

    void thirdLoading();

    std::shared_ptr<sf::Font> font;

    sf::Texture logoTex;
    sf::Sprite logo;
    
    int loading = 0;
    const int lastloading = 3;

    bool loaded = false;

};

