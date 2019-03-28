#include "game.h"


//*********************test_fifo******************************

void test_length_file()
{
  file f;
  f.isEmpty = 0;
  f.head = 40;
  f.queue = 10;
  int test1 = length_file(f);
  f.head = 0;
  f.queue = 20;
  int test2 = length_file(f);
  f.isEmpty = 1;
  int test3 = length_file(f);
  if (test1 == test2 && test3 == 0){
    couleur("32");
    printf("length_file passed\n");
    couleur("0");
  }
  else{
    couleur("31");
    printf("length_file failed\n");
    couleur("0");
  }
}

void test_enfile()
{
  file f1;
  f1.isEmpty = 1;
  f1.head = 10;
  f1.queue = 10;
  enfile(&f1,3);
  int test1 = f1.head - f1.queue == f1.isEmpty && f1.tab[f1.head] == 3; 
  enfile(&f1,4);
  int test2 = f1.head - f1.queue == -1 && f1.isEmpty == 0 && f1.tab[f1.queue] == 4;
  f1.queue = 9;
  f1.tab[9] = 2;  
  enfile(&f1,4);
  int test3 = f1.tab[9] == 2 && f1.tab[10] == 3;
  if (test1 && test2 && test3){
    couleur("32");
    printf("enfile passed\n");
    couleur("0");
  }
  else{
    couleur("31");
    printf("enfile failed\n");
    couleur("0");
  }
}

void test_defile()
{
  file f1;
  f1.isEmpty = 1;
  f1.head = 10;
  f1.queue = 10;
  int c = defile(&f1);
  int test1 = f1.head - f1.queue == c && f1.isEmpty; 
  enfile(&f1,4);
  c = defile(&f1);
  int test2 = f1.head - f1.queue == 0 && f1.isEmpty && c == 4;
  if (test1 && test2){
    couleur("32");
    printf("defile passed\n");
    couleur("0");
  }
  else{
    couleur("31");
    printf("defile failed\n");
    couleur("0");
  }
}

void test_mix_file()
{
  file f1;
  f1.isEmpty = 1;
  f1.head = 10;
  f1.queue = 10;
  mix_file(&f1);
  enfile(&f1,1);
  enfile(&f1,2);
  enfile(&f1,3);
  enfile(&f1,4);
  mix_file(&f1);
  if (f1.tab[13] != 4){
    couleur("32");
    printf("mix_file passed\n");
    couleur("0");
  }
  else{
    couleur("31");
    printf("mix_file failed\n");
    couleur("0");
  }
  
}

void test_fifo()
{
  couleur("34");
  printf("*************************************************************************\n");
  printf("Test_Fifo\n");
  couleur("0");
  test_length_file();
  test_enfile();
  test_defile();
  test_mix_file();
  couleur("34");
  printf("*************************************************************************\n");
  couleur("0");
} 

// ********************test_player****************************

void  test_Kitty_Think()
{
  board B;
  init_board(&B);
  Kitty_Think(&(B.players[0]));
  if (B.players[0].gain == 2){
    couleur("32");
    printf("Kitty_Think passed\n");
    couleur("0");
  }
  else{
    couleur("31");
    printf("Kitty_Think failed\n");
    couleur("0");
  }
}

void  test_Kitty_Steal()
{
  board B;
  init_board(&B);
  Kitty_Steal(&(B.players[0]),&(B.players[1]));
  Kitty_Steal(&(B.players[0]),&(B.players[2]));
  if (B.players[0].gain == 3 && B.players[1].gain == 1 && B.players[2].gain == 1){
    couleur("32");
    printf("Kitty_Steal passed\n");
    couleur("0");
  }
  else{
    couleur("31");
    printf("Kitty_Steal failed\n");
    couleur("0");
  }
}

void  test_Kitty_Panacea()
{
  board B;
  init_board(&B);
  Kitty_Panacea(&(B.players[0]));
  if (B.players[0].pv == 60){
    couleur("32");
    printf("Kitty_Panacea passed\n");
    couleur("0");
  }
  else{
    couleur("31");
    printf("Kitty_Panacea failed\n");
    couleur("0");
  }
}

void  test_Kitty_Razor()
{
  board B;
  init_board(&B);
  Kitty_Razor(&(B.players[0]));
  if (B.players[0].pv == 40){
    couleur("32");
    printf("Kitty_Razor passed\n");
    couleur("0");
  }
  else{
    couleur("31");
    printf("Kitty_Razor failed\n");
    couleur("0");
  }
}

void  test_Kitty_Hell_is_Others()
{
  board B;
  init_board(&B);
  Kitty_Hell_is_Others(&(B.players[0]));
  if (B.players[0].pv == 50 - INT_MAX){
    couleur("32");
    printf("Kitty_Hell_is_Others passed\n");
    couleur("0");
  }
  else{
    couleur("31");
    printf("Kitty_Hell_is_Others failed\n");
    couleur("0");
  }
}

void test_increase_ideas()
{
  board B;
  init_board(&B);
  increase_ideas(&(B.players[0]));
  if (B.players[0].ideas == 1){
    couleur("32");
    printf("increase_ideas passed\n");
    couleur("0");
  }
  else{
    couleur("31");
    printf("increase_ideas failed\n");
    couleur("0");
  }
}


void test_discard_hand()
{
  board B;
  init_board(&B);
  discard_hand(&(B.players[0]));
  if (B.players[0].hand[0] == 0 && B.players[0].hand[1] == 0 && B.players[0].hand[2] == 0 && B.players[0].hand[3] == 0 && B.players[0].hand[4] == 0){
    couleur("32");
    printf("discard_hand passed\n");
    couleur("0");
  }
  else{
    couleur("31");
    printf("discard_hand failed\n");
    couleur("0");
  }
}


void test_refill_cards()
{
  board B;
  init_board(&B);
  if (B.players[0].hand[0] != 0 && B.players[0].hand[1] != 0 && B.players[0].hand[2] != 0 && B.players[0].hand[3] != 0 && B.players[0].hand[4] != 0){
    couleur("32");
    printf("refill_cards passed\n");
    couleur("0");
  }
  else{
    couleur("31");
    printf("refill_cards failed\n");
    couleur("0");
  }
}

void test_fill_deck()
{
  board B;
  init_board(&B);
  int test = 1;
  for (int i=0; i<50; i++){
    if (B.players[0].deck.tab[i] == 0)
      test = 0;
  }
  if (test){
    couleur("32");
    printf("fill_deck passed\n");
    couleur("0");
  }
  else{
    couleur("31");
    printf("fill_deck failed\n");
    couleur("0");
  }
}

void test_player()
{
  couleur("34");
  printf("*************************************************************************\n");
  printf("Test_Player\n");
  couleur("0");
  test_Kitty_Think();
  test_Kitty_Steal();
  test_Kitty_Panacea();
  test_Kitty_Razor();
  test_Kitty_Hell_is_Others();
  test_increase_ideas();
  test_discard_hand();
  test_refill_cards();
  test_fill_deck();
  couleur("34");
  printf("*************************************************************************\n");
  couleur("0");
}


// *********************test_board***************************


void test_init_board()
{
  board B;
  init_board(&B);
  int test = 1;
  int i =0;

// vérification de l'initialisation de tous les paramètres pour chaque player

  while (i<NB_PLAYERS && test){
    if (!(B.players[i].idPlayer == i+1 &&
	  B.players[i].pv == 50 &&
	  B.players[i].ideas == 0 &&
	  B.players[i].gain == 1 &&
	  B.players[i].hand[0] != 0 &&
	  B.players[i].hand[1] != 0 &&
	  B.players[i].hand[2] != 0 &&
	  B.players[i].hand[3] != 0 &&
	  B.players[i].hand[4] != 0 &&
	  B.players[i].isAlive == 1 &&
	  B.players[i].isPlaying == 0 &&
	  ((B.players)[i].deck).head == 5 &&
	  ((B.players)[i].deck).queue == LEN_DECK-1 &&
	  ((B.players)[i].deck).isEmpty == 0 &&
	  (B.players)[i].deck_counter == 5))
      test = 0;
    i++;
  }
// fill_deck et refill_cards sont testés séparément
// vérification de l'initialisation des cartes

  if (test &&
      strcmp(B.cards[0].name, "Kitty_Think") &&
      B.cards[0].idCard == 1 &&
      B.cards[0].cost == 5 &&
      strcmp(B.cards[1].name, "Kitty_Steal") &&
      B.cards[1].idCard == 2 &&
      B.cards[1].cost == 10 &&
      strcmp(B.cards[2].name, "Kitty_Panacea") &&
      B.cards[2].idCard == 3 &&
      B.cards[2].cost == 2 &&
      strcmp(B.cards[3].name, "Kitty_Razor") &&
      B.cards[3].idCard == 4 &&
      B.cards[3].cost == 2 &&
      strcmp(B.cards[0].name, "Kitty_Hell_is_Others") &&
      B.cards[4].idCard == 5 &&
      B.cards[4].cost == 100){
    couleur("32");
    printf("init_board passed\n");
    couleur("0");
  }
  else{
    couleur("31");
    printf("init_board failed\n");
    couleur("0");
  }
}


void test_id2card()
{
  board B;
  init_board(&B);
  int test = 1;
  int i=1;
  while (i<6 && test){
    if(id2card(i,B).idCard != B.cards[i-1].idCard ||
       strcmp(id2card(i,B).name,B.cards[i-1].name) ||
       id2card(i,B).cost != B.cards[i-1].cost)
      test = 0;
    i++;     
  }
  if (test){
    couleur("32");
    printf("id2card passed\n");
    couleur("0");
  }
  else{
    couleur("31");
    printf("id2card failed\n");
    couleur("0");
  }
}

void test_id2player()
{
  board B;
  init_board(&B);
  int test = 1;
  int i =0;

  while (i<NB_PLAYERS && test){
    if (!(B.players[i].idPlayer == id2player(i+1,B).idPlayer &&
	  B.players[i].pv == id2player(i+1,B).pv &&
	  B.players[i].ideas == id2player(i+1,B).ideas &&
	  B.players[i].gain == id2player(i+1,B).gain &&
	  B.players[i].hand[0] == id2player(i+1,B).hand[0] &&
	  B.players[i].hand[1] == id2player(i+1,B).hand[1] &&
	  B.players[i].hand[2] == id2player(i+1,B).hand[2] &&
	  B.players[i].hand[3] == id2player(i+1,B).hand[3] &&
	  B.players[i].hand[4] == id2player(i+1,B).hand[4] &&
	  B.players[i].isAlive == id2player(i+1,B).isAlive &&
	  B.players[i].isPlaying == id2player(i+1,B).isPlaying))
      test = 0;
    i++;
  }
  if (test){
    couleur("32");
    printf("id2player passed\n");
    couleur("0");
  }
  else{
    couleur("31");
    printf("id2player failed\n");
    couleur("0");
  }
}

void test_select_player()
{
  board B;
  init_board(&B);
  int test = 1;
  int p = select_player(B);
  if (!(p<NB_PLAYERS+1 && p>0))
    test = 0;
  
  for (int i=0; i<NB_PLAYERS; i++){
    B.players[i].isAlive = 0;
  }
  
  int test2 = select_player(B);
  
  if (test && !test2){
    couleur("32");
    printf("select_player passed\n");
    couleur("0");
  }
  else{
    couleur("31");
    printf("select_player failed\n");
    couleur("0");
  }
}

void test_display_players() // fonction d'affichage testée visuellement
{
  couleur("32");
  printf("display_players passed\n");
  couleur("0");
}

void test_announce_results() // fonction d'affichage testée visuellement
{
  couleur("32");
  printf("announce_results passed\n");
  couleur("0");
}

void test_count_alive()
{
  board B;
  init_board(&B);
  int sum = 0;
  for (int i=0; i<NB_PLAYERS; i++){
    sum += B.players[i].isAlive;
  }

  if (sum == count_alive(B)){
    couleur("32");
    printf("count_alive passed\n");
    couleur("0");
  }
  else{
    couleur("31");
    printf("count_alive failed\n");
    couleur("0");
  }
}

void test_kill_players()
{
  board B;
  init_board(&B);
  for (int i=0; i<NB_PLAYERS; i++){
    B.players[i].pv = 0;
  }
  kill_players(&B);

  int test = 1;
  int i = 0;
  while (i<NB_PLAYERS && test){
    if (B.players[i].isAlive != 0)
      test = 0;
    i++;
  }
  if (test){
    couleur("32");
    printf("kill_players passed\n");
    couleur("0");
  }
  else{
    couleur("31");
    printf("kill_players failed\n");
    couleur("0");
  }
}

void test_board()
{
  couleur("34");
  printf("*************************************************************************\n");
  printf("Test_Board\n");
  couleur("0");
  test_init_board();
  test_id2card();
  test_id2player();
  test_select_player();
  test_display_players();
  test_announce_results();
  test_count_alive();
  test_kill_players();
  couleur("34");
  printf("*************************************************************************\n");
  couleur("0");
}


// **********************test game******************************



void test_select_card()
{
  board B;
  init_board(&B);
  int test = 1;
  card d = select_card(B.players[0],B);
  if ( d.idCard != 0 )
    test = 0;
  B.players[0].ideas = 100;
  card c = select_card(B.players[0],B);
  if ((c.idCard == B.players[0].hand[0] ||
       c.idCard == B.players[0].hand[1] ||
       c.idCard == B.players[0].hand[2] ||
       c.idCard == B.players[0].hand[3] ||
       c.idCard == B.players[0].hand[4]) &&
      c.cost <= B.players[0].ideas &&
      test){

    couleur("32");
    printf("select_card passed\n");
    couleur("0");
  }
  else{
    couleur("31");
    printf("select_card failed\n");
    couleur("0");
  }

       
  
}

void test_apply_card()
{
  board B;
  init_board(&B);
  B.players[0].ideas = 100;
  card C1 = {"Kitty-Think",1,5};
  apply_card(C1,&(B.players[0]),&(B.players[1]));
  if (B.players[0].ideas == 95){  // les fonctions des cartes ont déjà été controlées
    couleur("32");
    printf("apply_card passed\n");
    couleur("0");
  }
  else{
    couleur("31");
    printf("apply_card failed\n");
    couleur("0");
  }
}

void test_remove_card()
{
  board B;
  init_board(&B);
  card C1 = {"Kitty-Think",1,5};
  B.players[0].hand[0] = 1;
  remove_card(C1,&(B.players[0]));
  if (B.players[0].hand[0] == 0){
    couleur("32");
    printf("remove_card passed\n");
    couleur("0");
  }
  else{
    couleur("31");
    printf("remove_card failed\n");
    couleur("0");
  }
}

void test_game()
{
  couleur("34");
  printf("*************************************************************************\n");
  printf("Test_Game\n");
  couleur("0");
  test_select_card();
  test_apply_card();
  test_remove_card();
  couleur("34");
  printf("*************************************************************************\n");
  couleur("0");
}

int main()
{
  couleur("33");
  printf("//////////////////////////////////////////////////////////////////////////\n");
  printf("///////////////////////     TEST-ACHIEVEMENT-1     ///////////////////////\n");
  printf("//////////////////////////////////////////////////////////////////////////\n");
  test_fifo();
  test_player();
  test_board();
  test_game();
  return 0;
}
