#ifndef GAME_H
#define GAME_H

#include "board.h"

card select_card(player, board);
void apply_card(card, playerPointer, playerPointer);
void remove_card(card C, playerPointer p);

#endif // GAME_H
