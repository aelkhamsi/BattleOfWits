#ifndef BOARD_H
#define BOARD_H
#include "player.h"
#include "card.h"

struct board_t
{
    struct player_t players[NB_PLAYERS];
    struct card_t cards[NB_CARDS];
};

typedef struct board_t *boardPointer;
typedef struct board_t board;

card id2card(int id, board B);
player id2player(int id, board B);
int select_player(board B);
void display_players(int, board);
void announce_results(int, board);
int count_alive(board B);
void kill_players(boardPointer B);
void init_board( boardPointer B );
#endif // BOARD_H
