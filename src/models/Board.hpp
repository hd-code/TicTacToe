#pragma once

#include "Position.hpp"
#include "Player.hpp"

// -----------------------------------------------------------------------------

const int BOARD_ARRAY_SIZE = NUM_OF_ROWS * NUM_OF_COLS;

struct SBoard {
    SPlayer* fields[BOARD_ARRAY_SIZE];
};

// -----------------------------------------------------------------------------

void resetBoard(SBoard &board);

void setPlayerOnField(SBoard &board, SPlayer* player, const SPosition &position);

SPlayer* getPlayerOnField(const SBoard &board, const SPosition &position);

bool isFieldFree(const SBoard &board, const SPosition &position);

bool areThereStillEmptyFields(const SBoard &board);

SPlayer* getPlayerWithThreeInARow(const SBoard &board);