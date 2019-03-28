#include "friend.h"


//FRIEND Functions

//Le joueur, ses amis et les amis de ses amis ont le meme ID (idPlayer pour le joueur, idFriend pour l'ami)
//l'ID est donc utilisé pour reconnaitre toute " l'arbre généalogique "
//l'ID est l'équivalent du nom de famille


void choose_coord(int id, board B, int* x, int* y){        //Choisir l'une des quatre case autour du joueur père pour apparaitre et met les coord dans x et y
	
	int flag = 1;
	int ran;
	player p = B.players[id - 1];
	
	if ( B.arena[(p.x+1)%50][p.y] != '0' && B.arena[(p.x+49)%50][p.y] != '0' && B.arena[p.x][(p.y+1)%50] != '0' && B.arena[p.x][(p.y+49)%50] != '0' ) {
		*x = -1;
		*y = -1;
	} else {
		while (flag) {
			ran = rand()%4;
			switch (ran)
			{
				case 0:
				if (up_empty(id2player(id, B), B)){    
					*x = (id2player(id, B).x + 49)%50;
					*y = id2player(id, B).y;
					flag = 0;
				}
				break;

				case 1:
				if (down_empty(id2player(id, B), B)){
					*x = (id2player(id, B).x+1)%50;
					*y = id2player(id, B).y;
					flag = 0;
				}	
				break;

				case 2:
				if (right_empty(id2player(id, B), B)){
					*x = id2player(id, B).x;
					*y = (id2player(id, B).y+1)%50;
					flag = 0;
				}
				break;
	
				case 3:
				if (left_empty(id2player(id, B), B)){
					*x = id2player(id, B).x;
					*y = (id2player(id, B).y + 49)%50;
					flag = 0;
				}
				break;
			}
		}
	}
}

int select_target(board B, int id){			//Choisir une cible
											//l'ID est utilisé pour éviter de choisir un "membre de la famille" comme cible
	int j=0;
    int joueur_attaquable[NB_PLAYERS-1];
	int i;
    for (i=1; i<=NB_PLAYERS; i++){
        if ( id2player(i, B).isAlive == 1 && i != id){
            joueur_attaquable[j] = i;
            j += 1;
        }
    }
    if (j!=0){
      i = rand()%j;
      return joueur_attaquable[i];
    }
    else
      return 0;
}

void reselect_target(board B){
	friendPointer fr;
	for (int i=0; i<NB_PLAYERS; i++){
		fr = B.friends[i];
		while (fr != NULL){
			if (B.players[fr->idTarget -1].isAlive == 0) fr->idTarget = select_target(B, i);
			fr = fr->nextFriend;
		}
	}
}

void init_friend( friendPointer fr, boardPointer B, int id, int x, int y){
	fr->idFriend = id;
	fr->pv = 1;
	fr->ideas = 1;
	fr->gain = 1;
	fr->hand = rand()%NB_CARDS +1;
	
	fr->isAlive = 1;
	fr->isPlaying = 0;
	fr->life = 20;
	
	fr->x = x;
	fr->y = y;
	
	fr->idTarget = select_target(*B, id);
}
	

void Kitty_Puppy(int id, boardPointer B){ 			// Prend l'ID du joueur (ou de l'ami) qui l'a joué
																		// Fonction équivalente à un ajout d'un élément dans une liste chainée
	
	int x,y;
	choose_coord(id, *B, &x, &y);
	
	if (x != -1 && y != -1){
		if (B->friends[id-1] == NULL) {
			friend_t* fr = malloc(sizeof(*fr)); 
			init_friend(fr, B, id, x, y);
			fr->nextFriend = NULL;
			//struct friend_t f = {id, 1,1, 1, rand()%NB_CARDS, 1, 0, 20, x, y, choose_target(*B, id), NULL};
			B->friends[id-1] = fr;
			B->arena[x][y] = fr->idFriend;
		} else {
			friend_t* fr = malloc(sizeof(*fr)); 
			init_friend(fr, B, id, x, y);
			fr->nextFriend = B->friends[id-1];
			//struct friend_t f = {id, 1, 1,1, rand()%NB_CARDS, 1, 0, 20, x, y, choose_target(*B, id), B->friends[id-1]};
			B->friends[id-1] = fr;
			B->arena[x][y] = fr->idFriend;
		}
	}
}


void Kitty_Steal_p2fr(playerPointer p, int idAdv, boardPointer B){
    
    p->gain += 1;
    if ( B->friends[idAdv]->gain > 1) B->friends[idAdv]->gain -= 1;
}


void kill_friends(boardPointer B){		// Fonction équivalente à une suppression d'un élèment d'une liste chainée (si il est mort ou a dépassé 20 tours)
	for (int i=0; i<NB_PLAYERS; i++){
		if (B->players[i].isAlive == 1 ){
		
			friendPointer previousFr = NULL;
			friendPointer fr = B->friends[i];

			while (fr != NULL){
				if (fr->pv > 0 && fr->life > 0 && !(is_traped_fr(*fr, *B))){
					previousFr = fr;
					fr = fr->nextFriend;
				} else {
					if (previousFr == NULL){
						B->arena[fr->x][fr->y] = '0';
						B->friends[i] = fr->nextFriend;
						fr = fr->nextFriend;
					} else {
						B->arena[fr->x][fr->y] = '0';
						previousFr->nextFriend = fr->nextFriend;
						fr = fr->nextFriend;
					}
				}
			}
		} else if (B->players[i].isAlive == 0) {
			friendPointer fr = B->friends[i];
			while (fr != NULL){
				B->arena[fr->x][fr->y] = '0';
				fr = fr->nextFriend;
			}
			B->friends[i] = NULL;	
		}
	}
}

void decrease_friends_lifes(boardPointer B){    // life décrémente de 1 à chaque tour
	for (int i=0; i<NB_PLAYERS; i++){
		
		friendPointer fr = B->friends[i];

		while (	fr != NULL) {
			fr->life -= 1;
			fr = fr->nextFriend;
		}
	}
}

void increase_friends_ideas( board B, int id){
	friendPointer fr = B.friends[id];
	while (fr != NULL){
		fr->ideas += 1;
		fr = fr->nextFriend;
	}
}

void attack( boardPointer B, friendPointer fr){		// le friend attaque la cible
	printf("flagOn\n");
	playerPointer pAdv = &(B->players[fr->idTarget-1]);
	
	switch ( fr->hand )
    {
    case 1 :
      Kitty_Think_fr(fr);
      fr->ideas -= id2card(fr->hand, *B).cost;
      break;
    case 2 :
      Kitty_Steal_fr2p(fr, pAdv); 
      fr->ideas -= id2card(fr->hand, *B).cost;
      break;
    case 3 :
      Kitty_Panacea_fr(fr);
      fr->ideas -= id2card(fr->hand, *B).cost;
      break;
    case 4 :
      Kitty_Razor_2p(pAdv); 
      fr->ideas -= id2card(fr->hand, *B).cost;
      break;
    case 5 :
      Kitty_Hell_is_Others(pAdv);
      fr->ideas -= id2card(fr->hand, *B).cost;
      break;
    case 6 :
      Kitty_Stone( pAdv, B);
      fr->ideas -= id2card(fr->hand, *B).cost;
      break;
    case 7 : 
	  Kitty_Puppy(fr->idFriend, B);
	  fr->ideas -= id2card(fr->hand, *B).cost;
	  break;
    }
}


int comparer(int a, int b){
	if (a>b) return 1;
	else if (a<b) return -1;
	else return 0;
}


//id2player(fr->idTarget, *B).x
void move2target( friendPointer fr, boardPointer B){
	
	int xFr = fr->x;
	int yFr = fr->y;
	int xTarg = id2player(fr->idTarget, *B).x;
	int yTarg = id2player(fr->idTarget, *B).y;  
	if ( abs(xFr - xTarg) != 1 || abs(yFr - yTarg) != 1 ){
		int diffx = comparer( 48-abs(xFr - xTarg), abs(xFr - xTarg) -1);
		
		switch (diffx)
		{
			case 1:
			if (xFr < xTarg && is_empty((fr->x+1)%50, fr->y,B)){
				B->arena[fr->x][fr->y] = '0';
				fr->x = (fr->x+1)%50;
				B->arena[fr->x][fr->y] = fr->idFriend;  
				
			} else if (xFr > xTarg && is_empty((fr->x+49)%50, fr->y,B)) {
				B->arena[fr->x][fr->y] = '0';
				fr->x = (fr->x+49)%50;
				B->arena[fr->x][fr->y] = fr->idFriend;
			}
			break;
		
			case -1:
			if (xFr < xTarg && is_empty((fr->x+49)%50, fr->y,B)) {
				B->arena[fr->x][fr->y] = '0';
				fr->x = (fr->x+49)%50;
				B->arena[fr->x][fr->y] = fr->idFriend;
			} else if (xFr > xTarg && is_empty((fr->x+1)%50, fr->y,B)){
				B->arena[fr->x][fr->y] = '0';
				fr->x = (fr->x+1)%50;
				B->arena[fr->x][fr->y] = fr->idFriend;
			}
			break;
			
			case 0:
			B->arena[fr->x][fr->y] = '0';
			fr->x = (fr->x+1)%50;
			B->arena[fr->x][fr->y] = fr->idFriend;
			break;
			
		}
	
		int diffy = comparer( 48-abs(yFr - yTarg), abs(yFr - yTarg) -1);
		switch (diffy)
		{
			case 1:
			if (yFr < yTarg && is_empty(fr->x, (fr->y+1)%50,B)) {
				B->arena[fr->x][fr->y] = '0';
				fr->y = (fr->y+1)%50;
				B->arena[fr->x][fr->y] = fr->idFriend;
			} else if (yFr > yTarg && is_empty(fr->x, (fr->y+49)%50,B)) { 
				B->arena[fr->x][fr->y] = '0';
				fr->y = (fr->y+49)%50;
				B->arena[fr->x][fr->y] = fr->idFriend;
			}
			break;
		
			case -1:
			if (yFr < yTarg && is_empty(fr->x, (fr->y+49)%50,B)) {
				B->arena[fr->x][fr->y] = '0';
				fr->y = (fr->y+49)%50;
				B->arena[fr->x][fr->y] = fr->idFriend;
			} else if (yFr > yTarg && is_empty(fr->x, (fr->y+1)%50,B)) { 
				B->arena[fr->x][fr->y] = '0';
				fr->y = (fr->y+1)%50;
				B->arena[fr->x][fr->y] = fr->idFriend;
			}
			break;
			
			case 0:
			B->arena[fr->x][fr->y] = '0';
			fr->y = (fr->y+1)%50;
			B->arena[fr->x][fr->y] = fr->idFriend;
			break;
		}
	}
}

