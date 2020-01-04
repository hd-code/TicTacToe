#include "Board.hpp"

// -----------------------------------------------------------------------------

int getFieldIndex(const SPosition &position) {
    return position.row * NUM_OF_COLS + position.col;
}

void getPlayersAlongLine(const SBoard &board, SPlayer* result[], int numOfResults, const SPosition &startPos, int rowOffset, int colOffset) {
    SPosition pos = startPos;
    for (int i = 0; i < numOfResults; i++) {
        result[i] = getPlayerOnField(board, pos);
        pos.row += rowOffset;
        pos.col += colOffset;
    }
}

bool areAllPlayersTheSame(SPlayer* players[], int numOfPlayers) {
    for (int i = 1; i < numOfPlayers; i++) {
        if (players[i-1] != players[i]) {
            return false;
        }
    }
    return true;
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

SPlayer* getPlayerWithThreeInARow(const SBoard &board) {
    SPlayer* tmp[3];
    
    for (int row = 0; row < NUM_OF_ROWS; row++) {
        getPlayersAlongLine(board, tmp, 3, {row,0}, 0, 1);
        if (areAllPlayersTheSame(tmp, 3) && tmp[0] != nullptr) {
            return tmp[0];
        }
    }

    for (int col = 0; col < NUM_OF_COLS; col++) {
        getPlayersAlongLine(board, tmp, 3, {0,col}, 1, 0);
        if (areAllPlayersTheSame(tmp, 3) && tmp[0] != nullptr) {
            return tmp[0];
        }
    }
    
    getPlayersAlongLine(board, tmp, 3, {0,0}, 1, 1);
    if (areAllPlayersTheSame(tmp, 3) && tmp[0] != nullptr) {
        return tmp[0];
    }

    getPlayersAlongLine(board, tmp, 3, {0,2}, 1, -1);
    if (areAllPlayersTheSame(tmp, 3) && tmp[0] != nullptr) {
        return tmp[0];
    }

    return nullptr;
}