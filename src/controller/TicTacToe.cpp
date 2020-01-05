#include "TicTacToe.hpp"
#include "../models/Game.hpp"
#include "../views/Console.hpp"

// -----------------------------------------------------------------------------

void beginGame(SGame &game) {
    initGame(game);
    renderWelcome();
}

void makeTurn(SGame &game) {
    renderTurnBegin(game.players[game.playerOnTurn], game.board);
    renderBoard(game.board);

    SPosition pos = askUserForPosition("Bitte Feld eingeben (Reihe und Spalte z.B a2)");
    while (!isPositionValid(pos) || !isFieldFree(game.board, pos)) {
        pos = askUserForPosition("Ungültig! Bitte erneut eingeben");
    }

    setPlayerOnField(game.board, &game.players[game.playerOnTurn], pos);
    setNextPlayerOnTurn(game);
}

void endGame(const SGame &game) {
    SPlayer* winner = getWinner(game);

    renderGameOverMsg();
    renderBoard(game.board);
    renderWinner(winner);
}

// -----------------------------------------------------------------------------

void playTicTacToe() {
    SGame game;
    
    beginGame(game);

    while (!isGameOver(game)) {
        makeTurn(game);
    }

    endGame(game);
}