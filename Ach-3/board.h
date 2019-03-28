#ifndef BOARD_H
#define BOARD_H
#include "player.h"
#include "card.h"

struct case_t
{
  int x;
  int y;
};

typedef struct case_t case_t;
typedef struct case_t *casePointer;


struct board_t
{
  struct player_t players[NB_PLAYERS];
  struct card_t cards[NB_CARDS];
  char arena[50][50];
  struct case_t directions[NB_PLAYERS];
  struct friend_t *friends[NB_PLAYERS];  //Tableau de liste chainée (une liste chainée est un pointeur vers le premier élèment de la liste)
										// Chaque case du tableau friends[i] représente la liste chainée des amis du joueur d'indice i

};

typedef struct board_t *boardPointer;
typedef struct board_t board;

card id2card(int id, board B);
player id2player(int id, board B);
int select_player(board B);
void display_players(int c, board B);
void announce_results(int c, board B);
int count_alive(board B);
void init_board( boardPointer B );
#endif // BOARD_H
