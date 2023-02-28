#include "PositionMode.h"

const PositionMode PositionMode::DEFAULT = PositionMode();
const PositionMode PositionMode::CENTER = PositionMode(Mode::center, Mode::center);
const PositionMode PositionMode::LEFT = PositionMode(Mode::left, Mode::center);
const PositionMode PositionMode::ORIGINAL_POSITION = PositionMode(Mode::left, Mode::top);
