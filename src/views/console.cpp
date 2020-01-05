#include "Console.hpp"
#include "../lib/HDio.hpp"

// -----------------------------------------------------------------------------

SPosition inputToPosition(char input[3]) {
    SPosition result;
    result.row = input[0] - "a"[0];
    result.col = input[1] - "1"[0];
    return result;
}

// -----------------------------------------------------------------------------

void renderWelcome() {
    clearScreen();
    askForEnter("Herzlich Willkommen zu TIC TAC TOE (ENTER drücken)");
}

void renderTurnBegin(const SPlayer &player, const SBoard &board) {
    clearScreen();
    renderBoard(board);
    print("Spieler ", player.sign);
    askForEnter(" ist am Zug (ENTER drücken)");

    clearScreen();
    print("Spieler ", player.sign);
    println(" ist am Zug");
    println();
}

void renderBoard(const SBoard &board) {
    print(" ");
    for (int i = MIN_ROW_COL; i <= MAX_ROW_COL; i++) {
        print(" ", i+1);
    }
    println();

    char rowName = "a"[0];
    for (int i = MIN_ROW_COL; i <= MAX_ROW_COL; i++) {
        print(rowName);
        for (int j = MIN_ROW_COL; j <= MAX_ROW_COL; j++) {
            SPlayer* field = getPlayerOnField(board, {i,j});
            char sign = field == nullptr ? "_"[0] : field->sign;
            print(" ", sign);
        }
        println();
        rowName++;
    }
    
    println();
}

SPosition askUserForPosition(const char msg[]) {
    int inputLen = 3;
    char input[inputLen];
    askForInput(msg, input, inputLen);

    return inputToPosition(input);
}

void renderGameOverMsg() {
    clearScreen();
    println("DAS SPIEL IST VORBEI!");
    println();
}

void renderWinner(const SPlayer* winner) {
    if (winner == nullptr) {
        println("Es ist unentschieden.");
    } else {
        print("Spieler ", winner->sign);
        println(" hat gewonnen. Herzlichen Glückwunsch!");
    }

    println();
    askForEnter("Ende (ENTER drücken)");
}