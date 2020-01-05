#include "Board.hpp"

// -----------------------------------------------------------------------------

int getFieldIndex(const SPosition &position) {
    return position.row * NUM_OF_COLS + position.col;
}

bool areAllPlayersTheSame(SPlayer* players[], int numOfPlayers) {
    for (int i = 1; i < numOfPlayers; i++) {
        if (players[i-1] != players[i]) {
            return false;
        }
    }
    return true;
}

const int WINNING_NUM_OF_PLAYERS = NUM_OF_ROWS < NUM_OF_COLS ? NUM_OF_ROWS : NUM_OF_COLS;

SPlayer* getPlayerWithThreeInARow(const SBoard &board) {
    SPlayer* tmp[WINNING_NUM_OF_PLAYERS];

    for (int i = MIN_ROW; i <= MAX_ROW; i++) {
        for (int j = MIN_COL; j <= MAX_COL; j++) {
            tmp[j] = getPlayerOnField(board, {i,j});
        }
        if (areAllPlayersTheSame(tmp, WINNING_NUM_OF_PLAYERS)) {
            return tmp[0];
        }
    }

    return nullptr;
}

SPlayer* getPlayerWithThreeInACol(const SBoard &board) {
    SPlayer* tmp[WINNING_NUM_OF_PLAYERS];

    for (int i = MIN_COL; i <= MAX_COL; i++) {
        for (int j = MIN_ROW; j <= MAX_ROW; j++) {
            tmp[j] = getPlayerOnField(board, {j,i});
        }
        if (areAllPlayersTheSame(tmp, WINNING_NUM_OF_PLAYERS)) {
            return tmp[0];
        }
    }

    return nullptr;
}

SPlayer* getPlayerWithThreeInADiagonal(const SBoard &board) {
    SPlayer* tmp[WINNING_NUM_OF_PLAYERS];

    for (int i = MIN_ROW; i < WINNING_NUM_OF_PLAYERS; i++) {
        tmp[i] = getPlayerOnField(board, {i,i});
    }
    if (areAllPlayersTheSame(tmp, WINNING_NUM_OF_PLAYERS)) {
        return tmp[0];
    }

    for (int i = MIN_ROW; i < WINNING_NUM_OF_PLAYERS; i++) {
        tmp[i] = getPlayerOnField(board, {i, MAX_COL - i});
    }
    if (areAllPlayersTheSame(tmp, WINNING_NUM_OF_PLAYERS)) {
        return tmp[0];
    }

    return nullptr;
}

// -----------------------------------------------------------------------------

void resetBoard(SBoard &board) {
    for (int i = 0; i < BOARD_ARRAY_SIZE; i++) {
        board.fields[i] = nullptr;
    }
}

void setPlayerOnField(SBoard &board, SPlayer* player, const SPosition &position) {
    int index = getFieldIndex(position);
    board.fields[index] = player;
}

SPlayer* getPlayerOnField(const SBoard &board, const SPosition &position) {
    int index = getFieldIndex(position);
    return board.fields[index];
}

bool isFieldFree(const SBoard &board, const SPosition &position) {
    return getPlayerOnField(board, position) == nullptr;
}

bool areThereStillEmptyFields(const SBoard &board) {
    for (int i = 0; i < BOARD_ARRAY_SIZE; i++) {
        if (board.fields[i] == nullptr) {
            return true;
        }
    }
    return false;
}

SPlayer* getPlayerWithThreeInALine(const SBoard &board) {
    SPlayer* result = nullptr;

    result = getPlayerWithThreeInARow(board);
    if (result != nullptr)
        return result;

    result = getPlayerWithThreeInACol(board);
    if (result != nullptr)
        return result;

    result = getPlayerWithThreeInADiagonal(board);

    return result;
}