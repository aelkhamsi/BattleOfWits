#ifndef FRIEND_H
#define FRIEND_H

#include "arena.h"


void choose_coord(int id, board B, int* x, int* y);
int select_target(board B, int id);
void reselect_target(board B);
void init_friend( friendPointer fr, boardPointer B, int id, int x, int y);

void Kitty_Puppy(int id, boardPointer B);
void Kitty_Steal_p2fr(playerPointer p, int idAdv, boardPointer B);

void kill_friends(boardPointer B);
void decrease_friends_lifes(boardPointer B);
void increase_friends_ideas(board B, int id);
void attack( boardPointer B, friendPointer fr);
int comparer(int a, int b);
void move2target( friendPointer fr, boardPointer B);




#endif // FRIEND_H
