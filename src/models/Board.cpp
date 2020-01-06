#include "Board.hpp"

// -----------------------------------------------------------------------------

int getFieldIndex(const SPosition &position) {
    return position.row * NUM_OF_ROWS_COLS + position.col;
}

// returns also false, when all entries in players[] are nullptr
bool areAllPlayersTheSame(SPlayer* players[], int numOfPlayers) {
    if (players[0] == nullptr)
        return false;

    for (int i = 1; i < numOfPlayers; i++) {
        if (players[i-1] != players[i]) {
            return false;
        }
    }

    return true;
}

SPlayer* getPlayerWithAFullRow(const SBoard &board) {
    SPlayer* row[NUM_OF_ROWS_COLS];

    for (int i = MIN_ROW_COL; i <= MAX_ROW_COL; i++) {
        for (int j = MIN_ROW_COL; j <= MAX_ROW_COL; j++) {
            row[j] = getPlayerOnField(board, {i,j});
        }
        
        if (areAllPlayersTheSame(row, NUM_OF_ROWS_COLS)) {
            return row[0];
        }
    }

    return nullptr;
}

SPlayer* getPlayerWithAFullCol(const SBoard &board) {
    SPlayer* col[NUM_OF_ROWS_COLS];

    for (int i = MIN_ROW_COL; i <= MAX_ROW_COL; i++) {
        for (int j = MIN_ROW_COL; j <= MAX_ROW_COL; j++) {
            col[j] = getPlayerOnField(board, {j,i});
        }
        if (areAllPlayersTheSame(col, NUM_OF_ROWS_COLS)) {
            return col[0];
        }
    }

    return nullptr;
}

SPlayer* getPlayerWithAFullDiagonal(const SBoard &board) {
    SPlayer*  leftDiagonal[NUM_OF_ROWS_COLS];
    SPlayer* rightDiagonal[NUM_OF_ROWS_COLS];

    for (int i = MIN_ROW_COL; i <= MAX_ROW_COL; i++) {
         leftDiagonal[i] = getPlayerOnField(board, { i, i });
        rightDiagonal[i] = getPlayerOnField(board, { i, MAX_ROW_COL - i });
    }

    if (areAllPlayersTheSame( leftDiagonal, NUM_OF_ROWS_COLS)) return  leftDiagonal[0];
    if (areAllPlayersTheSame(rightDiagonal, NUM_OF_ROWS_COLS)) return rightDiagonal[0];

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