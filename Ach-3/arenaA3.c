#include <stdio.h>
#include "arena.h"


int is_empty(int x, int y, boardPointer B){
    return (B->arena)[x][y] == '0';
}

int up_empty(player p, board B){
	if (p.x != 0) return B.arena[((p.x)-1)%50][p.y] == '0';
	else return B.arena[49][p.y] == '0';
}

int down_empty(player p, board B){
    return B.arena[((p.x)+1)%50][p.y] == '0';
}

int right_empty(player p, board B){
    return B.arena[p.x][((p.y)+1)%50] == '0';
}

int left_empty(player p, board B){
    if (p.y != 0) return B.arena[p.x][((p.y)-1)%50] == '0';
	else return B.arena[p.x][49] == '0';
}

/*
void up(playerPointer p, boardPointer B){
    B->arena[p->x][p->y] = '0';
    p->x = ((p->x)-1)%50;
    B->arena[p->x][p->y] = (char)p->idPlayer;
}

void down(playerPointer p, boardPointer B){
    B->arena[p->x][p->y] = '0';
    p->x = ((p->x)+1)%50;
    B->arena[p->x][p->y] = (char)p->idPlayer;
}

void right(playerPointer p, boardPointer B){
    B->arena[p->x][p->y] = '0';
    p->y = ((p->y)+1)%50;
    B->arena[p->x][p->y] = (char)p->idPlayer;
}

void left(playerPointer p, boardPointer B){
    B->arena[p->x][p->y] = '0';
    p->y = ((p->y)-1)%50;
    B->arena[p->x][p->y] = (char)p->idPlayer;
}

*/
void choose_directions(boardPointer B){
    int ran;
    int flag;
    for (int i=0; i<NB_PLAYERS; i++){
      flag = 1;
      if (B->players[i].isAlive != 0){
	while(flag){
	  ran = rand()%4;
	  switch (ran)
	    {
	    case 0:
	      if (up_empty(B->players[i], *B)){
		B->directions[i].y = B->players[i].y;
		if (B->players[i].x != 0){
		  B->directions[i].x = B->players[i].x -1;
		} else {
		  B->directions[i].x = 49;
		}
		flag = 0;
	      }
	      break;
	    case 1:
	      if (down_empty(B->players[i], *B)){
		B->directions[i].x = (B->players[i].x +1)%50;
		B->directions[i].y = B->players[i].y;
		flag = 0;
	      }
	      break;
	    case 2:
	      if (right_empty(B->players[i], *B)){
		B->directions[i].x = B->players[i].x;
		B->directions[i].y = (B->players[i].y +1)%50;
		flag = 0;
	      }
	      break;
	    case 3:
	      if (left_empty(B->players[i], *B)){
		B->directions[i].x = B->players[i].x;
		if (B->players[i].y != 0){
		  B->directions[i].y = B->players[i].y -1;
		} else {
		  B->directions[i].y = 49;
		}
		flag = 0;
	      }
	      break;
	    }
	} 
      } else {
	B->directions[i].x = -1;
	B->directions[i].y = -1;
	flag = 0;
      }
    }
}

void del_duplicates(boardPointer B){
  for (int i=0; i<NB_PLAYERS-1; i++){
    for (int j=i+1; j<NB_PLAYERS; j++){
      if (B->directions[i].x == B->directions[j].x && B->directions[i].y == B->directions[j].y){
	B->directions[i].x = -1;
	B->directions[i].y = -1;
	B->directions[j].x = -1;
	B->directions[j].y = -1;
      }	
    }
  }
}

void move(playerPointer p, boardPointer B, int x, int y){
  if(x != -1 && y != -1){
    B->arena[p->x][p->y] = '0';
    p->x = x;
    p->y = y;
    B->arena[p->x][p->y] = p->idPlayer;
  }
}

void move_all(boardPointer B){
       
    choose_directions(B);
    del_duplicates(B);
     
    for (int i=0; i<NB_PLAYERS; i++){
      move(&(B->players[i]), B, B->directions[i].x, B->directions[i].y);
    }
}
	
int is_traped(player p, board B){
  int flag = 0;
  if (p.x == 0 && p.y == 0){
    if (B.arena[49][0] != '0' && B.arena[1][0] != '0' && B.arena[0][1] != '0' && B.arena[0][49] != '0') flag = 1;
  
  } else if (p.x == 0) {
    if (B.arena[49][p.y] != '0' && B.arena[1][p.y] != '0' && B.arena[0][p.y+1] != '0' && B.arena[0][p.y-1] != '0') flag = 1;
  
  } else if (p.y == 0) {
    if (B.arena[p.x][49] != '0' && B.arena[p.x][1] != '0' && B.arena[p.x+1][0] != '0' && B.arena[p.x-1][0] != '0') flag = 1;
 
  } else {
    if (B.arena[((p.x)+1)%50][p.y] != '0' && B.arena[p.x][((p.y)+1)%50] != '0' && B.arena[p.x-1][p.y] != '0' && B.arena[p.x][p.y-1] != '0') flag = 1;
  }
  
  return flag;
}

int is_traped_fr(friend_t p, board B){
  
  int flag = 0;
  if (p.x == 0 && p.y == 0){
    if (B.arena[49][0] != '0' && B.arena[1][0] != '0' && B.arena[0][1] != '0' && B.arena[0][49] != '0') flag = 1;
  
  } else if (p.x == 0) {
    if (B.arena[49][p.y] != '0' && B.arena[1][p.y] != '0' && B.arena[0][p.y+1] != '0' && B.arena[0][p.y-1] != '0') flag = 1;
  
  } else if (p.y == 0) {
    if (B.arena[p.x][49] != '0' && B.arena[p.x][1] != '0' && B.arena[p.x+1][0] != '0' && B.arena[p.x-1][0] != '0') flag = 1;
 
  } else {
    if (B.arena[((p.x)+1)%50][p.y] != '0' && B.arena[p.x][((p.y)+1)%50] != '0' && B.arena[p.x-1][p.y] != '0' && B.arena[p.x][p.y-1] != '0') flag = 1;
  }
  
  return flag;
}


void initialize_arena(boardPointer B){
  int x, y;
  int flag;
  for (int i=0; i<NB_PLAYERS; i++){
    flag = 1;
    do {
      x = rand()%50;
      y = rand()%50;
      if (is_empty(x, y, B)) {
	B->arena[x][y] = (B->players[i]).idPlayer; 
	B->players[i].x = x;
	B->players[i].y = y;
	flag = 0;
      }
    } while (flag);
  }
}

void display_arena(board B){
  printf("\n");
  couleur("33");
  printf("************************\n");
  printf("***                  ***\n");
  printf("***    THE ARENA     ***\n");
  printf("***                  ***\n");             
  printf("************************\n\n");
  couleur("0");
  int i, j;
  for (i=0; i<50; i++){
    for (j=0; j<50; j++){
      if( B.arena[i][j] == '#'){
	couleur("31");
        printf("%c ", B.arena[i][j]);
	couleur("0");
      } else if (B.arena[i][j] == '0') {
	printf("%c ", B.arena[i][j]);
      } else {
	if (id2player(B.arena[i][j], B).isAlive == 0){
	  
	  if (B.arena[i][j] >=10){
	    couleur("31");
	    printf("%d", B.arena[i][j]);
	    couleur("0");
	  } else {
	    couleur("31");
	    printf("%d ", B.arena[i][j]);
	    couleur("0");
	  }   
	} else {
	  if (B.arena[i][j] >=10){
	    couleur("32");
	    printf("%d", B.arena[i][j]);
	    couleur("0");
	  } else {
	    couleur("32");
	    printf("%d ", B.arena[i][j]);
	    couleur("0");
	  } 
	}
      }
      
    }
    printf("\n");
  }
}

void Kitty_Stone(playerPointer pAdv, boardPointer B){
    int d;
    int flag = 1;
    while (flag){
      d = rand()%4;
      switch (d)
        {
        case 0:
	  if (up_empty(*pAdv, *B)){
	    if (pAdv->x == 0) {
	      B->arena[49][pAdv->y] = '#';
	      flag = 0;

	    } else { 
	      B->arena[(pAdv->x)-1][pAdv->y] = '#';
	      flag = 0;
	    }
	  }
	  break;
        case 1:
	  if (down_empty(*pAdv, *B)){
	    B->arena[((pAdv->x)+1)%50][pAdv->y] = '#';
	    flag = 0;
	  }
	  break;
        case 2:
	  if (right_empty(*pAdv, *B)){
	    B->arena[pAdv->x][((pAdv->y)+1)%50] = '#';
	    flag = 0;
	  }
	  break;
        case 3:
	  if (left_empty(*pAdv, *B)){
	    if (pAdv-> y == 0) {
	      B->arena[pAdv->x][49] = '#';
	      flag = 0;
	    } else {	
	      B->arena[pAdv->x][(pAdv->y)-1] = '#';
	      flag = 0;
	    }
	  }
	  break;
        }
    }
}






