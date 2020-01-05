#include "Position.hpp"

// -----------------------------------------------------------------------------

bool isPositionValid(const SPosition &position) {
    return MIN_ROW_COL <= position.row && position.row <= MAX_ROW_COL
        && MIN_ROW_COL <= position.col && position.col <= MAX_ROW_COL;
}