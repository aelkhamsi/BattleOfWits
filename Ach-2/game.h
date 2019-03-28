#ifndef GAME_H
#define GAME_H

#include "arena.h"

card select_card(player, board);
void apply_card(card, boardPointer, playerPointer, playerPointer);
void remove_card(card C, playerPointer p);
void kill_players(boardPointer B);

#endif // GAME_H
