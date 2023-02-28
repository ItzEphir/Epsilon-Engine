#pragma once
#include <exception>

enum Mode
{
    center,
    right,
    left,
    top,
    bottom
};

class PositionMode
{
public:
    static const PositionMode DEFAULT;
    static const PositionMode CENTER;
    static const PositionMode LEFT;
    static const PositionMode ORIGINAL_POSITION;

    Mode modeX = Mode::left, modeY = Mode::center;

    PositionMode(Mode modeX = Mode::left, Mode modeY = Mode::center)
    {
        if (modeX == Mode::bottom || modeX == Mode::top) throw PositionModeException("ModeX cannot be top or bottom, use right, left or center.");
        this->modeX = modeX;
        if (modeY == Mode::right || modeY == Mode::left) throw PositionModeException("ModeY cannot be left or right, use top, bottom or center.");
        this->modeY = modeY;
    }
};

class PositionModeException : std::exception
{
public:
    PositionModeException() noexcept
    {
        exception::exception();
    }

    explicit PositionModeException(char const* const _Message) noexcept
    {
        exception::exception(_Message);
    }

    PositionModeException(char const* const _Message, int iexc) noexcept
    {
        exception::exception(_Message, iexc);
    }

    PositionModeException(exception const& _Other) noexcept
    {
        exception::exception(_Other);
    }
};
