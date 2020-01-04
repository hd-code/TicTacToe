#pragma once

#include "Board.hpp"

// -----------------------------------------------------------------------------

enum EPlayer { ONE, TWO, NUM_OF_PLAYERS };

struct SGame {
    SBoard board;
    SPlayer players[NUM_OF_PLAYERS];
    EPlayer playerOnTurn;
};

// -----------------------------------------------------------------------------

void initGame(SGame &game);

void setNextPlayerOnTurn(SGame &game);

SPlayer* getWinner(const SGame &game);

bool isGameOver(const SGame &game);