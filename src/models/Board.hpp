#pragma once

#include "Position.hpp"
#include "Player.hpp"

// -----------------------------------------------------------------------------

const int BOARD_ARRAY_SIZE = NUM_OF_ROWS_COLS * NUM_OF_ROWS_COLS;

struct SBoard {
    SPlayer* fields[BOARD_ARRAY_SIZE]; // nullptr means field is empty
};

// -----------------------------------------------------------------------------

void resetBoard(SBoard &board);

void setPlayerOnField(SBoard &board, SPlayer* player, const SPosition &position);

// returns nullptr if no player is on this field
SPlayer* getPlayerOnField(const SBoard &board, const SPosition &position);

bool isFieldFree(const SBoard &board, const SPosition &position);

bool areThereStillEmptyFields(const SBoard &board);

// returns nullptr if no player has a full line
SPlayer* getPlayerWithAFullLine(const SBoard &board);