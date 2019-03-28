#include "board.h"


card id2card(int id, board B){
    return (B.cards)[id-1];
}

player id2player(int id, board B){
    return (B.players)[id-1];
}

int select_player(board B){  // retourne l'id du joueur sélectionné
    int i;
    int j=0;
    int joueur_attaquable[NB_PLAYERS-1];

    for (i=1; i<=NB_PLAYERS; i++){
        if ( id2player(i, B).isAlive == 1 && id2player(i, B).isPlaying == 0 ){
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

void display_players(int c, board B){
    int i;
    if (c == 0){
      couleur("36");
      printf("**********************************************************************\n");
      printf("**********************************************************************\n");
      printf("***                                                                ***\n");
      printf("***                WELCOME TO KITTY WONDERLAND                     ***\n");
      printf("***                                                                ***\n");
      printf("***               The battle of wits will begin                    ***\n");
      printf("***                                                                ***\n");
      printf("**********************************************************************\n");
      printf("**********************************************************************\n\n");
      
      printf("The number of philosophers : %d \n\n", NB_PLAYERS);
      couleur("0");
    } else {
      
      couleur("33");
      printf("*********************************************************************\n");
      printf("*************************** Round %d *********************************\n", c);
      printf("*********************************************************************\n\n");
      
      printf("************************\n");
      printf("***                  ***\n");
      printf("***    THE ALIVE     ***\n");
      printf("***     PLAYERS      ***\n");             
      printf("***                  ***\n");
      printf("************************\n\n");
      couleur("0");
      
      for (i=0; i<NB_PLAYERS; i++){
        if((B.players[i]).isAlive){
	  printf("Player number %d :\n", B.players[i].idPlayer );
	  printf("PV : %d  Ideas : %d  Gain : %d \n", B.players[i].pv, B.players[i].ideas, B.players[i].gain);
	  printf("Cards : %s   ",id2card((B.players[i].hand)[0], B).name);
	  printf("%s   ",id2card((B.players[i].hand)[1], B).name);
	  printf("%s   ",id2card((B.players[i].hand)[2], B).name);
	  printf("%s   ",id2card((B.players[i].hand)[3], B).name);
	  printf("%s\n",id2card((B.players[i].hand)[4], B).name);
      
	  couleur("35");
	  printf("-------------------------------------------------------------\n");
	  couleur("0");
	  
        }
      }
    }
}

void announce_results(int c, board B){
    int i;
    printf("\n\n THE GAME LASTED %d ROUNDS \n\n",c);
    int gagnant = 0;
    for (i=0; i<NB_PLAYERS; i++){
        if((B.players[i]).isAlive){
            printf("\n\n");
	    couleur("34");
            printf("****************************************************************\n");
            printf("****************************************************************\n");
	    printf("***************                               ******************\n");
            printf("***************");
	    couleur("33");
	    printf("   CONGRATULATIONS PLAYER %d   ", (B.players[i]).idPlayer);
	    couleur("34");
	    printf("******************\n");
	    printf("***************                               ******************\n");
            printf("****************************************************************\n");
	    printf("****************************************************************\n");
	    couleur("0");
            gagnant = 1;

        }
    }
    if (gagnant == 0){
        printf("\n\n");
	couleur("34");
	printf("****************************************************************\n");
	printf("****************************************************************\n");
	printf("***************                               ******************\n");
	printf("***************");
	couleur("33");
	printf("            DRAW                ");                                           
	couleur("34");
	printf("******************\n");
	printf("***************                               ******************\n");
	printf("****************************************************************\n");
	printf("****************************************************************\n");
	couleur("0");
    }

}

int count_alive(board B){
    int i;
    int s=0;
    for(i=0; i<NB_PLAYERS; i++) s += (B.players[i]).isAlive;
    return s;
}

void kill_players(boardPointer B){
    int i;
    playerPointer p;
    for (i=0; i<NB_PLAYERS; i++){
        p = &(B->players[i]);
        if(p->pv<=0) p->isAlive = 0;
    }
}

void init_board( boardPointer B )
{
  for(int i=0; i<NB_PLAYERS; i++){
    (B->players)[i].idPlayer = i+1;
    (B->players)[i].pv = 50;
    (B->players)[i].ideas = 0;
    (B->players)[i].gain = 1;
    for (int j=0; j<5; j++){
      ((B->players)[i].hand)[j] = 0;
    };
    (B->players)[i].isAlive = 1;
    (B->players)[i].isPlaying = 0;
    refill_cards(&((B->players)[i]));
  }

  card C1 = {"Kitty-Think",1,5};
  card C2 = {"Kitty-Steal",2,10};
  card C3 = {"Kitty-Panacea",3,2};
  card C4 = {"Kitty-Razor",4,2};
  card C5 = {"Kitty-Hell-is-Others",5,100};

  (B->cards)[0] = C1;
  (B->cards)[1] = C2;
  (B->cards)[2] = C3;
  (B->cards)[3] = C4;
  (B->cards)[4] = C5;
}

 
