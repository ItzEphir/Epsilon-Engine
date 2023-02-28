#include "Constrait.h"

void Constrait::CenterToCenterOf(std::shared_ptr<Drawable> from, std::shared_ptr<Drawable> to)
{
    sf::Vector2f position_dr = to->getOriginalPosition();
    sf::Vector2f size_dr = to->getSize();
    from->setPosition({ position_dr.x + size_dr.x / 2 - from->getSize().x / 2, position_dr.y + size_dr.y / 2 - from->getSize().y / 2 });
}

void Constrait::CenterToTopOf(std::shared_ptr<Drawable> from, std::shared_ptr<Drawable> to)
{
    sf::Vector2f position_dr = to->getOriginalPosition();
    sf::Vector2f size_dr = to->getSize();
    from->setPosition({ position_dr.x + size_dr.x / 2 - from->getSize().x / 2, position_dr.y - from->getSize().y / 2 });
}

void Constrait::CenterToBottomOf(std::shared_ptr<Drawable> from, std::shared_ptr<Drawable> to)
{
    sf::Vector2f position_dr = to->getOriginalPosition();
    sf::Vector2f size_dr = to->getSize();
    from->setPosition({ position_dr.x + size_dr.x / 2 - from->getSize().x / 2, position_dr.y + size_dr.y - from->getSize().y / 2 });
}

void Constrait::CenterToLeftOf(std::shared_ptr<Drawable> from, std::shared_ptr<Drawable> to)
{
    sf::Vector2f position_dr = to->getOriginalPosition();
    sf::Vector2f size_dr = to->getSize();
    from->setPosition({ position_dr.x - from->getSize().x / 2, position_dr.y + size_dr.y / 2 - from->getSize().y / 2 });
}

void Constrait::CenterToRightOf(std::shared_ptr<Drawable> from, std::shared_ptr<Drawable> to)
{
    sf::Vector2f position_dr = to->getOriginalPosition();
    sf::Vector2f size_dr = to->getSize();
    from->setPosition({ position_dr.x + size_dr.x - from->getSize().x / 2, position_dr.y + size_dr.y / 2 - from->getSize().y / 2});
}

void Constrait::TopToCenterOf(std::shared_ptr<Drawable> from, std::shared_ptr<Drawable> to)
{
    sf::Vector2f position_dr = to->getOriginalPosition();
    sf::Vector2f size_dr = to->getSize();
    from->setPosition({ from->getOriginalPosition().x, position_dr.y + size_dr.y / 2 });
}

void Constrait::TopToTopOf(std::shared_ptr<Drawable> from, std::shared_ptr<Drawable> to)
{
    sf::Vector2f position_dr = to->getOriginalPosition();
    sf::Vector2f size_dr = to->getSize();
    from->setPosition({ from->getOriginalPosition().x, position_dr.y });
}

void Constrait::TopToBottomOf(std::shared_ptr<Drawable> from, std::shared_ptr<Drawable> to)
{
    sf::Vector2f position_dr = to->getOriginalPosition();
    sf::Vector2f size_dr = to->getSize();;
    from->setPosition({ from->getOriginalPosition().x, position_dr.y + size_dr.y });
}

void Constrait::BottomToCenterOf(std::shared_ptr<Drawable> from, std::shared_ptr<Drawable> to)
{
    sf::Vector2f position_dr = to->getOriginalPosition();
    sf::Vector2f size_dr = to->getSize();
    from->setPosition({ from->getOriginalPosition().x, position_dr.y + size_dr.y - from->getSize().y });
}

void Constrait::BottomToTopOf(std::shared_ptr<Drawable> from, std::shared_ptr<Drawable> to)
{
    sf::Vector2f position_dr = to->getOriginalPosition();
    sf::Vector2f size_dr = to->getSize();
    from->setPosition({ from->getOriginalPosition().x, position_dr.y - from->getSize().y });
}

void Constrait::BottomToBottomOf(std::shared_ptr<Drawable> from, std::shared_ptr<Drawable> to)
{
    sf::Vector2f position_dr = to->getOriginalPosition();
    sf::Vector2f size_dr = to->getSize();
    from->setPosition({ from->getOriginalPosition().x, position_dr.y + size_dr.y - from->getSize().y });
}

void Constrait::LeftToCenterOf(std::shared_ptr<Drawable> from, std::shared_ptr<Drawable> to)
{
    sf::Vector2f position_dr = to->getOriginalPosition();
    sf::Vector2f size_dr = to->getSize();
    from->setPosition({ position_dr.x + size_dr.x / 2, from->getOriginalPosition().y });
}

void Constrait::LeftToLeftOf(std::shared_ptr<Drawable> from, std::shared_ptr<Drawable> to)
{
    sf::Vector2f position_dr = to->getOriginalPosition();
    sf::Vector2f size_dr = to->getSize();
    from->setPosition({ position_dr.x, from->getOriginalPosition().y });
}

void Constrait::LeftToRightOf(std::shared_ptr<Drawable> from, std::shared_ptr<Drawable> to)
{
    sf::Vector2f position_dr = to->getOriginalPosition();
    sf::Vector2f size_dr = to->getSize();
    from->setPosition({ position_dr.x + size_dr.x, from->getOriginalPosition().y });
}

void Constrait::RightToCenterOf(std::shared_ptr<Drawable> from, std::shared_ptr<Drawable> to)
{
    sf::Vector2f position_dr = to->getOriginalPosition();
    sf::Vector2f size_dr = to->getSize();
    from->setPosition({ position_dr.x + size_dr.x / 2 - from->getSize().x, from->getOriginalPosition().y });
}

void Constrait::RightToLeftOf(std::shared_ptr<Drawable> from, std::shared_ptr<Drawable> to)
{
    sf::Vector2f position_dr = to->getOriginalPosition();
    sf::Vector2f size_dr = to->getSize();
    from->setPosition({ position_dr.x - from->getSize().x, from->getOriginalPosition().y });
}

void Constrait::RightToRightOf(std::shared_ptr<Drawable> from, std::shared_ptr<Drawable> to)
{
    sf::Vector2f position_dr = to->getOriginalPosition();
    sf::Vector2f size_dr = to->getSize();
    from->setPosition({ position_dr.x + size_dr.x - from->getSize().x, from->getOriginalPosition().y });
}
