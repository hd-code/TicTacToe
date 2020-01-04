#include "Game.hpp"

// -----------------------------------------------------------------------------

const char PLAYER_SIGNS[NUM_OF_PLAYERS] = { "X"[0], "O"[0] };

void initPlayers(SGame &game) {
    for (int i = 0; i < NUM_OF_PLAYERS; i++) {
        game.players[i].sign = PLAYER_SIGNS[i];
    }
}

EPlayer getNextPlayer(const SGame &game) {
    return game.playerOnTurn == ONE ? TWO : ONE;
}

// -----------------------------------------------------------------------------

void initGame(SGame &game) {
    resetBoard(game.board);
    initPlayers(game);
    game.playerOnTurn = ONE;
}

void setNextPlayerOnTurn(SGame &game) {
    game.playerOnTurn = getNextPlayer(game);
}

SPlayer* getWinner(const SGame &game) {
    return getPlayerWithThreeInARow(game.board);
}

bool isGameOver(const SGame &game) {
    return !areThereStillEmptyFields(game.board) || getWinner(game) != nullptr;
}