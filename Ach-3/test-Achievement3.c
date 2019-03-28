#include "game.h"

//******************************************************************test friend*******************************************************************


void test_choose_coord(){
	board B;
	init_board(&B);
	initialize_arena(&B);
	
	int xP = B.players[0].x;
	int yP = B.players[0].y;
	
	
	int xFr;
	int yFr;
	
	choose_coord(1, B, &xFr, &yFr);

	if ( ( xFr == (xP+1)%50 && yFr == yP ) || ( xFr == (xP+49)%50  && yFr == yP ) || ( xFr == xP && yFr == (yP+1)%50 ) || ( xFr == xP && yFr == (yP+49)%50 ) ){
		couleur("32");
	    printf("choose_coord passed\n");
	    couleur("0");
	} else {
		couleur("31");
		printf("choose_coord failed\n");
		couleur("0");
	}
	
}
	

void test_select_target(){
	board B;
	init_board(&B);
	initialize_arena(&B);
	
	int idTarget = select_target(B, 2);
	
	int flag = ( idTarget >= 1 && idTarget <= NB_PLAYERS && idTarget != 2 );
	
	if (flag){
		couleur("32");
	    printf("select_target passed\n");
	    couleur("0");
	} else {
		couleur("31");
		printf("select_target failed\n");
		couleur("0");
	}
}

void test_reselect_target(){
	board B;
	init_board(&B);
	initialize_arena(&B);
	
	Kitty_Puppy(1, &B); //Creer un friend du joueur 1
	int idTarget1 = B.friends[0]->idTarget; // ID de la cible
	B.players[ idTarget1 -1 ].isAlive = 0; //Tuer la cible du friend
	
	reselect_target(B);
	int idTarget2 = B.friends[0]->idTarget; // ID de la nouvelle cible
	
	int flag = (idTarget2 >=1 && idTarget2 <=NB_PLAYERS && idTarget1 != idTarget2);
	
	if (flag){
		couleur("32");
	    printf("reselect_target passed\n");
	    couleur("0");
	} else {
		couleur("31");
		printf("reselect_target failed\n");
		couleur("0");
	}
	
}


void test_Kitty_Puppy(){
	board B;
	init_board(&B);
	initialize_arena(&B);
	
	int xP = B.players[0].x;
	int yP = B.players[0].y;

	Kitty_Puppy(1, &B);
	Kitty_Puppy(1, &B);
	
	int flag1 = (B.arena[(xP+1)%50][yP] == 1 || B.arena[(xP+49)%50][yP] == 1 || B.arena[xP][(yP+1)%50] == 1 || B.arena[xP][(yP+49)%50] == 1 );
	int flag2 = (B.friends[0]->nextFriend != NULL && B.friends[0]->nextFriend->nextFriend == NULL );
	
	
	if (flag2 && flag1){
		couleur("32");
	    printf("Kitty_Puppy passed\n");
	    couleur("0");
	} else {
		couleur("31");
		printf("Kitty_Puppy failed\n");
		couleur("0");
	}	
}

void test_kill_friends(){
	board B;
	init_board(&B);
	initialize_arena(&B);
	//Creation des friends (2 pour le joueur 1 & 3 pour le joueur 2)
	Kitty_Puppy(1, &B);
	Kitty_Puppy(1, &B);
	Kitty_Puppy(2, &B);
	Kitty_Puppy(2, &B);
	Kitty_Puppy(2, &B);
	//Tuer Le joueur 1 et un friend du joueur 2
	B.players[0].isAlive = 0;
	B.friends[1]->nextFriend->pv = 0;
	
	kill_friends(&B);
	
	int flag1 = (B.friends[0] == NULL);  // 0 Friend pour le joueur 1
	int flag2 = (B.friends[1] != NULL && B.friends[1]->nextFriend != NULL && B.friends[1]->nextFriend->nextFriend == NULL); //2 Friend pour le joueur 2
	
	if (flag1 && flag2){
		couleur("32");
	    printf("kill_friends passed\n");
	    couleur("0");
	} else {
		couleur("31");
		printf("kill_friends failed\n");
		couleur("0");
	}
}

void test_decrease_friends_lifes(){
	board B;
	init_board(&B);
	initialize_arena(&B);
	//Creation des friends
	Kitty_Puppy(1, &B);
	Kitty_Puppy(1, &B);
	Kitty_Puppy(2, &B);
	
	//Decrementer leur life
	decrease_friends_lifes(&B);
	
	int flag = (B.friends[0]->life == 19 && B.friends[0]->nextFriend->life == 19 && B.friends[1]->life == 19 );

	if (flag){
		couleur("32");
	    printf("decrease_friends_lifes passed\n");
	    couleur("0");
	} else {
		couleur("31");
		printf("decrease_friends_lifes failed\n");
		couleur("0");
	}
}


void test_move2target(){
	board B;
	init_board(&B);
	initialize_arena(&B);
	Kitty_Puppy(1, &B); // Creer un ami du player 1
	
	friendPointer fr = B.friends[0]; // pointeur vers l'ami
	int xFr = fr->x; // coord x du friend
	int yFr = fr->y; // coord y du friend
	int xTarg = B.players[ fr->idTarget -1].x; // coord x de la cible
	int yTarg = B.players[ fr->idTarget -1].y; // coord y de la cible
	
	int xEvo = 0, yEvo = 0; // Le sens d'évolution de xFr et yFr
	
	if ( abs(xFr - xTarg) != 1 || abs(yFr - yTarg) != 1 ){
		int diffx = comparer( 48-abs(xFr - xTarg), abs(xFr - xTarg) -1);

		switch (diffx)
		{
			case 1:
			if ( xFr < xTarg && is_empty((fr->x+1)%50, fr->y,&B)) {xEvo = 1; printf("br");} 
			else if (xFr > xTarg && is_empty((fr->x+49)%50, fr->y,&B)) xEvo = -1;
			break;
		
			case -1:
			if ( xFr < xTarg && is_empty((fr->x+49)%50, fr->y,&B)) xEvo = -1;
			else if ( xFr > xTarg && is_empty((fr->x+1)%50, fr->y,&B)) xEvo = 1;
			break;
			
			case 0:
			xEvo = 1;
			break;
		}
	
		int diffy = comparer( 48-abs(yFr - yTarg), abs(yFr - yTarg) -1);
		switch (diffy)
		{
			case 1:
			if (yFr < yTarg && is_empty(fr->x, (fr->y+1)%50,&B)) yEvo = 1;
			else if (yFr > yTarg && is_empty(fr->x, (fr->y+49)%50,&B)) yEvo = -1;
			break;
		
			case -1:
			if (yFr < yTarg && is_empty(fr->x, (fr->y+49)%50,&B)) yEvo = -1;
			else if (yFr > yTarg && is_empty(fr->x, (fr->y+1)%50,&B)) yEvo = 1;
			break;
			
			case 0:
			xEvo = 1;
			break;
		}
	}
	
	move2target(B.friends[0], &B);
	
	int flag = ( fr->x == xFr + xEvo && fr->y == yFr + yEvo);
	 
	 
	if (flag){
		couleur("32");
	    printf("move2target passed\n");
	    couleur("0");
	} else {
		couleur("31");
		printf("move2target failed\n");
		couleur("0");
	}
}



void test_friend(){
  couleur("34");
  printf("*************************************************************************\n");
  printf("Test_Board\n");
  couleur("0");
	
  test_choose_coord();
  test_select_target();
  test_reselect_target();
  test_Kitty_Puppy();
  test_kill_friends();
  test_decrease_friends_lifes();
  test_move2target();
  
  couleur("34");
  printf("*************************************************************************\n");
  couleur("0");
}


int main(){
  couleur("33");
  printf("//////////////////////////////////////////////////////////////////////////\n");
  printf("///////////////////////     TEST-ACHIEVEMENT-3     ///////////////////////\n");
  printf("//////////////////////////////////////////////////////////////////////////\n");
  couleur("0");
  test_friend();
  return 0;
}


