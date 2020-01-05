#pragma once

// -----------------------------------------------------------------------------

const int MIN_ROW_COL = 0;
const int MAX_ROW_COL = 2;

const int NUM_OF_ROWS_COLS = MAX_ROW_COL - MIN_ROW_COL + 1;

struct SPosition {
    int row;
    int col;
};

// -----------------------------------------------------------------------------

bool isPositionValid(const SPosition &position);