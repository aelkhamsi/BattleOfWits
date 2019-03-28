#ifndef GAME_H
#define GAME_H

#include "player.h"
#include "card.h"
#include "board.h"

card id2card(int, board);

player id2player(int, board);

void increase_ideas(playerPointer p);

card select_card(player, board);

player select_player(board);

void apply_card(card, playerPointer, playerPointer);

#endif // GAME_H
