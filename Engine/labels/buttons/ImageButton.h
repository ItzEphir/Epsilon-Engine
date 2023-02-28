#pragma once
#include "Button.h"
#include "../Image.h"

class ImageButton : public Button
{
public:

    ImageButton();

    virtual void Create(sf::Vector2f position, sf::Vector2f size, sf::Vector2f scale, sf::Color color, float radius, sf::String filename, PositionMode mode = PositionMode::DEFAULT, PositionMode imageMode = PositionMode::DEFAULT);

    virtual void Draw() override;

    Image getImage() { return image; }

    PositionMode getImagePositionMode() { return image.getPositionMode(); }

    void setImage(Image newImage)
    {
        image = newImage;
    }

    void setImagePositionMode(PositionMode newImagePositionMode)
    {
        image.setPositionMode(newImagePositionMode);
    }

protected:

    Image& takeImage() { return image; }

    void countImagePosition();

    virtual void countSize();

private:

    Image image;

    bool alreadyPressed = false;
};

