#include "Position.hpp"

// -----------------------------------------------------------------------------

bool isPositionValid(const SPosition &position) {
    return MIN_ROW <= position.row && position.row <= MAX_ROW
        && MIN_COL <= position.col && position.col <= MAX_COL;
}