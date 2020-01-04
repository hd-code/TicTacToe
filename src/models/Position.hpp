#pragma once

// -----------------------------------------------------------------------------

const int MIN_ROW = 0;
const int MAX_ROW = 2;

const int MIN_COL = 0;
const int MAX_COL = 2;

const int NUM_OF_ROWS = MAX_ROW - MIN_ROW + 1;
const int NUM_OF_COLS = MAX_COL - MIN_COL + 1;

struct SPosition {
    int row;
    int col;
};

// -----------------------------------------------------------------------------

bool isPositionValid(const SPosition &position);