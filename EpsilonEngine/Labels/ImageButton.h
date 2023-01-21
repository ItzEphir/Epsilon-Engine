#pragma once
#include "UsualButton.h"
#include "RenderImage.h"
#include "RenderText.h"

class ImageButton :
    public UsualButton
{
public:
    ImageButton(std::shared_ptr<sf::RenderWindow> rw, std::shared_ptr<sf::Font> font);

    virtual void Create(sf::Vector2f position, sf::Vector2f size, sf::Color color, Mode imageModeX, Mode imageModeY, Mode textModeX, Mode textModeY);

    virtual void Create(sf::Vector2f position, sf::Vector2f size, sf::Color color, CMode imageMode, CMode textMode);

    virtual void Create(sf::Vector2f position, sf::Vector2f size, sf::Color color, sf::Color textColor, Mode imageModeX, Mode imageModeY, Mode textModeX, Mode textModeY);

    virtual void Create(sf::Vector2f position, sf::Vector2f size, sf::Color color, sf::Color textColor, CMode imageMode, CMode textMode);

    virtual void Update() override;

    virtual void Draw()
    {
        ISCREATED;
        image.Draw();
        getWindow()->draw(getText());
    }

    RenderImage getimage()
    {
        ISCREATED;
        return image;
    }

    virtual void setImage(RenderImage newImage)
    {
        ISCREATED;
        image = newImage;
    }

    sf::Vector2f getImagePosition()
    {
        return imagePosition;
    }

    virtual void setImagePosition(sf::Vector2f newImagePosition)
    {
        imagePosition = newImagePosition;
        image.setPosition(imagePosition);
    }

    sf::Vector2f getImageScale()
    {
        return imageScale;
    }

    virtual void setImageScale(sf::Vector2f newImageScale)
    {
        imageScale = newImageScale;
        image.setScale(imageScale);
    }

protected:

    

private:

    RenderImage image;

    sf::Vector2f imagePosition;
    sf::Vector2f imageScale = sf::Vector2f(1, 1);

};

