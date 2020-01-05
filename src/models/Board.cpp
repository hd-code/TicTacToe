#include "Board.hpp"

// -----------------------------------------------------------------------------

int getFieldIndex(const SPosition &position) {
    return position.row * NUM_OF_ROWS_COLS + position.col;
}

bool areAllPlayersTheSame(SPlayer* players[], int numOfPlayers) {
    for (int i = 1; i < numOfPlayers; i++) {
        if (players[i-1] != players[i]) {
            return false;
        }
    }
    return true;
}

SPlayer* getPlayerWithAFullRow(const SBoard &board) {
    SPlayer* tmp[NUM_OF_ROWS_COLS];

    for (int i = MIN_ROW_COL; i <= MAX_ROW_COL; i++) {
        for (int j = MIN_ROW_COL; j <= MAX_ROW_COL; j++) {
            tmp[j] = getPlayerOnField(board, {i,j});
        }
        if (areAllPlayersTheSame(tmp, NUM_OF_ROWS_COLS)) {
            return tmp[0];
        }
    }

    return nullptr;
}

SPlayer* getPlayerWithAFullCol(const SBoard &board) {
    SPlayer* tmp[NUM_OF_ROWS_COLS];

    for (int i = MIN_ROW_COL; i <= MAX_ROW_COL; i++) {
        for (int j = MIN_ROW_COL; j <= MAX_ROW_COL; j++) {
            tmp[j] = getPlayerOnField(board, {j,i});
        }
        if (areAllPlayersTheSame(tmp, NUM_OF_ROWS_COLS)) {
            return tmp[0];
        }
    }

    return nullptr;
}

SPlayer* getPlayerWithAFullDiagonal(const SBoard &board) {
    SPlayer* tmp[NUM_OF_ROWS_COLS];

    for (int i = MIN_ROW_COL; i < MAX_ROW_COL; i++) {
        tmp[i] = getPlayerOnField(board, {i,i});
    }
    if (areAllPlayersTheSame(tmp, NUM_OF_ROWS_COLS)) {
        return tmp[0];
    }

    for (int i = MIN_ROW_COL; i < MAX_ROW_COL; i++) {
        tmp[i] = getPlayerOnField(board, {i, MAX_ROW_COL - i});
    }
    if (areAllPlayersTheSame(tmp, NUM_OF_ROWS_COLS)) {
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

SPlayer* getPlayerWithAFullLine(const SBoard &board) {
    SPlayer* result = nullptr;

    result = getPlayerWithAFullRow(board);
    if (result != nullptr)
        return result;

    result = getPlayerWithAFullCol(board);
    if (result != nullptr)
        return result;

    result = getPlayerWithAFullDiagonal(board);

    return result;
}