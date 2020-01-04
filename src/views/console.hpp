#pragma once

#include "../models/Game.hpp"

// -----------------------------------------------------------------------------

void renderWelcome();

void renderTurnBegin(const SPlayer &player, const SBoard &board);

void renderBoard(const SBoard &board);

SPosition askUserForPosition(const char msg[]);

void renderEnd();

void renderWinner(const SPlayer* winner);