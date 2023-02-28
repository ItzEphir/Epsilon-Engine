#pragma once
#include "../labels/Drawable.h"

class Constrait
{
public:
    static void CenterToCenterOf(std::shared_ptr<Drawable> from, std::shared_ptr<Drawable> to);

    static void CenterToTopOf(std::shared_ptr<Drawable> from, std::shared_ptr<Drawable> to);

    static void CenterToBottomOf(std::shared_ptr<Drawable> from, std::shared_ptr<Drawable> to);

    static void CenterToLeftOf(std::shared_ptr<Drawable> from, std::shared_ptr<Drawable> to);

    static void CenterToRightOf(std::shared_ptr<Drawable> from, std::shared_ptr<Drawable> to);

    static void TopToCenterOf(std::shared_ptr<Drawable> from, std::shared_ptr<Drawable> to);
 
    static void TopToTopOf(std::shared_ptr<Drawable> from, std::shared_ptr<Drawable> to);

    static void TopToBottomOf(std::shared_ptr<Drawable> from, std::shared_ptr<Drawable> to);

    static void BottomToCenterOf(std::shared_ptr<Drawable> from, std::shared_ptr<Drawable> to);

    static void BottomToTopOf(std::shared_ptr<Drawable> from, std::shared_ptr<Drawable> to);

    static void BottomToBottomOf(std::shared_ptr<Drawable> from, std::shared_ptr<Drawable> to);

    static void LeftToCenterOf(std::shared_ptr<Drawable> from, std::shared_ptr<Drawable> to);

    static void LeftToLeftOf(std::shared_ptr<Drawable> from, std::shared_ptr<Drawable> to);

    static void LeftToRightOf(std::shared_ptr<Drawable> from, std::shared_ptr<Drawable> to);
 
    static void RightToCenterOf(std::shared_ptr<Drawable> from, std::shared_ptr<Drawable> to);

    static void RightToLeftOf(std::shared_ptr<Drawable> from, std::shared_ptr<Drawable> to);

    static void RightToRightOf(std::shared_ptr<Drawable> from, std::shared_ptr<Drawable> to);
};
