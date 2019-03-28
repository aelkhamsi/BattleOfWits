#ifndef BOARD_H
#define BOARD_H

#define NB_PLAYERS 4
#define NB_CARDS 5
#define INT_MAX 50

#include "player.h"
#include "card.h"

struct board_t
{
    struct player_t players[NB_PLAYERS];
    struct card_t cards[NB_CARDS];
};

typedef struct board_t *boardPointer;
typedef struct board_t board;

#endif // BOARD_H
