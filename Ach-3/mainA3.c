#include <getopt.h>

#include "game.h"

// Global seed for the random number generator
int seed = 0;

// Function for parsing the options of the program
// Currently available options are :
// -s <seed> : sets the seed
void parse_opts(int argc, char* argv[]) {
  int opt;
  while ((opt = getopt(argc, argv, "s:")) != -1) {
    switch (opt) {
    case 's':
      seed = atoi(optarg);
      break;
    default: /* '?' */
      fprintf(stderr, "Usage: %s [-s seed] \n",
	      argv[0]);
      exit(EXIT_FAILURE);
    }
  }
}

int main(int argc, char* argv[]){
  parse_opts(argc, argv);
  printf("Seed : %d\n", seed);
  srand(seed);

  board B;
  init_board(&B);
  initialize_arena(&B);

  
  char mode[20];
  char chaine[20];
  printf("Choose player mode [ (1) round by round & display arena (other) all game ]: ");
  fgets(mode, sizeof(mode), stdin);
  printf("%s\n", mode);

  int count_round = 0;
  display_players(count_round, B);
  count_round++;
  
  if ( atoi(mode)==1 ){
    printf("press Enter to continue\n");
    fgets(chaine, sizeof(chaine), stdin);
  }
///////////////////////////////////////////////////////////Phase de JEU///////////////////////////////////////////////////////////////
  while(count_alive(B)>=2){
		//////INCREMENTATION D'IDEES/////
    for (int i=0; i<NB_PLAYERS; i++){
		
		if((B.players[i]).isAlive) increase_player_ideas( &(B.players[i]) );
		increase_friends_ideas(B, i);
    }
    
    for (int i=0; i<NB_PLAYERS; i++){
		
		////////////JOUEURS//////////////
		if((B.players[i]).isAlive){
	
		(B.players[i]).isPlaying = 1;
	
		int c = select_card(B.players[i], B).idCard;
		int idAdv = select_player(B);
	
		if(c) {
			apply_card(id2card(c, B), &B, &(B.players[i]), &(B.players[idAdv-1]));
			remove_card(id2card(c, B), &(B.players[i]));
		}
	
		refill_cards(&(B.players[i]));
		if (B.players[i].deck_counter == 50){
			mix_file(&(B.players[i].deck));
			B.players[i].deck_counter = 0;
		}
	
	(B.players[i]).isPlaying = 0;
		}
		////////////FRIENDS//////////////
		friendPointer fr = B.friends[i];
		
		while (fr != NULL){
			if ( fr->ideas >= id2card(fr->hand, B).cost ){
				attack(&B, fr); 
			} else {
				move2target(fr, &B); 
			}
			fr = fr->nextFriend;
		}
    }
    ////////ELIMINATION DES MORTS////////
   
    decrease_friends_lifes(&B);
    
    kill_players(&B);
   
    kill_friends(&B);
    
    reselect_target(B);

///////////////////////////////////////////////////////////Phase d'AFFICHAGE////////////////////////////////////////////////////////////
    display_players(count_round,B);
    count_round++;
    
    if ( atoi(mode)==1 ){
      display_arena(B);
      printf("press Enter to continue\n");
      fgets(chaine, sizeof(chaine), stdin);
    }
///////////////////////////////////////////////////////////Phase de MOUVEMENT///////////////////////////////////////////////////////////
    for (int i=0; i<5; i++){
		move_all(&B);
	}
  }
  
  
  
  announce_results(count_round,B);
  
  return 0;
}

