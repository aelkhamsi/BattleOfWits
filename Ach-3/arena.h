#ifndef ARENA_H
#define ARENA_H

#include "board.h"


int is_empty(int x, int y, boardPointer B);
int up_empty(player p, board B);
int down_empty(player p, board B);
int right_empty(player p, board B);
int left_empty(player p, board B);
/*
void up(playerPointer p, boardPointer B);
void down(playerPointer p, boardPointer B);
void right(playerPointer p, boardPointer B);
void left(playerPointer p, boardPointer B);
*/
void choose_directions(boardPointer B);
void del_duplicates(boardPointer B);
void move(playerPointer p, boardPointer B, int x, int y);
void move_all(boardPointer B);
int is_traped(player p, board B);
int is_traped_fr(friend_t p, board B);
void initialize_arena(boardPointer);
void display_arena(board);

void Kitty_Stone(playerPointer, boardPointer);



#endif // ARENA_H
