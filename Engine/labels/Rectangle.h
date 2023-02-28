#pragma once
#include "Drawable.h"
#include "../system/Constrait.h"
#include "Image.h"
#define _USE_MATH_DEFINES
#include <math.h>

class Rectangle : public Drawable
{
public:

    Rectangle();

    virtual void Create(sf::Vector2f position, sf::Vector2f size, sf::Vector2f scale, sf::Color color, float radius = 0.0f, PositionMode positionMode = PositionMode::ORIGINAL_POSITION);

    virtual void Update() override;

    virtual void Draw() override;

    virtual void countSize() override;

    sf::Color getColor()
    {
        return color;
    }

    float getRadius()
    {
        return shape.getRadius();
    }

    virtual void setSize(sf::Vector2f newSize) override
    {
        Drawable::setSize(newSize);
        shape = RoundedRectangle(sf::FloatRect(position, size), shape.getRadius());
    }

    virtual void setPosition(sf::Vector2f newPosition) override
    {
        Drawable::setPosition(newPosition);
        shape.setPosition(position);
    }

    virtual void setColor(sf::Color newColor)
    {
        color = newColor;
        shape.setFillColor(color);
    }

    virtual void setRadius(float newRadius)
    {
        shape.setRadius(newRadius);
    }

    virtual void setScale(sf::Vector2f newScale) override
    {
        Drawable::setScale(newScale);
        shape.setScale(scale);
    }

    virtual void setPositionMode(PositionMode newPositionMode) override
    {
        Drawable::setPositionMode(newPositionMode);
        shape.setPosition(position);
    }

protected:
    
    static class RoundedRectangle : public sf::ConvexShape
    {
    public:
        RoundedRectangle(const sf::Rect<float> rt, const float rs)
            : rect(rt), radius(rs)
        {
            init();
            setPosition(rt.left, rt.top);
            sf::Shape::update();
        }

        virtual size_t getPointCount() const { return m.size(); }
        virtual sf::Vector2f getPoint(size_t i) const { return m[i]; }

        float getRadius() const
        {
            return radius;
        }

        virtual void setRadius(float newRadius)
        {
            radius = newRadius;
            init();
            setPosition(rect.left, rect.top);
            sf::Shape::update();
        }

    private:
        sf::FloatRect rect;
        float radius;
        sf::Vector2f position{ 0.f, 0.f };

        std::vector<sf::Vector2f> m;
        unsigned PointCount;

        void init()
        {
            std::vector<sf::Vector2f> sin_4;
            {
                const float PREC = M_PI_2 / 15;
                for (float f = 0.0; f < M_PI_2; f += PREC)
                {
                    sin_4.push_back({ sinf(f) * radius, cosf(f) * radius });
                }
            }

            std::vector<sf::Vector2f> sin_4_reverse(sin_4.rbegin(), sin_4.rend());

            const float WIDE2 = rect.width - radius;
            const float HEIGHT2 = rect.height - radius;

            for (const auto& e : sin_4_reverse)
            {
                m.push_back({ WIDE2 + e.x, HEIGHT2 + e.y });
            }

            for (const auto& e : sin_4)
            {
                m.push_back({ radius - e.x, HEIGHT2 + e.y });
            }

            for (const auto& e : sin_4_reverse)
            {
                m.push_back({ radius - e.x, radius - e.y });
            }

            for (const auto& e : sin_4)
            {
                m.push_back({ WIDE2 + e.x, radius - e.y });
            }
        }
    };

    void setShape(RoundedRectangle newShape)
    {
        shape = newShape;
    }

    RoundedRectangle& takeShape()
    {
        return shape;
    }

private:

    RoundedRectangle shape;

    sf::Color color;

};

