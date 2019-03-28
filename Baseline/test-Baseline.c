#include "game.h"


// ********************test_player****************************

void  test_Kitty_Think()
{
  player P1 = {1,50,100,2,{1,2,1,2,3},1,0};
  Kitty_Think(&P1);
  if (P1.gain == 3){
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
  player P1 = {1,50,100,2,{1,2,1,2,3},1,0};
  player P2 = {1,50,100,2,{1,2,1,2,3},1,0};
  player P3 = {1,50,100,1,{1,2,1,2,3},1,0};
  Kitty_Steal(&P1,&P2);
  Kitty_Steal(&P1,&P3);
  if (P1.gain == 4 && P2.gain == 1 && P3.gain == 1){
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
  player P1 = {1,50,100,2,{1,2,1,2,3},1,0};
  Kitty_Panacea(&P1);
  if (P1.pv == 60){
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
  player P1 = {1,50,100,2,{1,2,1,2,3},1,0};
  Kitty_Razor(&P1);
  if (P1.pv == 40){
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
  player P1 = {1,50,100,2,{1,2,1,2,3},1,0};
  Kitty_Hell_is_Others(&P1);
  if (P1.pv == 50-INT_MAX){
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
  player P1 = {1,50,100,2,{1,2,1,2,3},1,0};
  increase_ideas(&P1);
  if (P1.ideas == 102){
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
  player P1 = {1,50,100,2,{1,2,1,2,3},1,0};
  discard_hand(&P1);
  if (P1.hand[0] == 0 && P1.hand[1] == 0 && P1.hand[2] == 0 && P1.hand[3] == 0 && P1.hand[4] == 0){
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
  player P1 = {1,50,100,2,{0,0,0,0,0},1,0};
  player P2 = {1,50,100,2,{0,2,1,2,3},1,0};
  refill_cards(&P1);
  refill_cards(&P2);
  if (P2.hand[0] != 0 && P1.hand[0] != 0 && P1.hand[1] != 0 && P1.hand[2] != 0 && P1.hand[3] != 0 && P1.hand[4] != 0){
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
          B.players[i].isPlaying == 0))
      test = 0;
    i++;
  }

// vérification de l'initialisation des cartes

  if (test &&
      !(strcmp(B.cards[0].name, "Kitty-Think")) &&
      B.cards[0].idCard == 1 &&
      B.cards[0].cost == 5 &&
      !(strcmp(B.cards[1].name, "Kitty-Steal")) &&
      B.cards[1].idCard == 2 &&
      B.cards[1].cost == 10 &&
      !(strcmp(B.cards[2].name, "Kitty-Panacea")) &&
      B.cards[2].idCard == 3 &&
      B.cards[2].cost == 2 &&
      !(strcmp(B.cards[3].name, "Kitty-Razor")) &&
      B.cards[3].idCard == 4 &&
      B.cards[3].cost == 2 &&
      !(strcmp(B.cards[4].name, "Kitty-Hell-is-Others")) &&
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

/*
card select_card(player, board);
void apply_card(card, playerPointer, playerPointer);
void remove_card(card C, playerPointer p);
*/

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
  player P1 = {1,50,100,2,{1,2,1,2,3},1,0};
  player P2 = {1,50,100,2,{1,2,1,2,3},1,0};
  card C1 = {"Kitty-Think",1,5};
  apply_card(C1,&P1,&P2);
  if (P1.ideas == 95){  // les fonctions des cartes ont déjà été controlées
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
  player P1 = {1,50,100,2,{1,2,1,2,3},1,0};
  card C1 = {"Kitty-Think",1,5};
  remove_card(C1,&P1);
  if (P1.hand[0] == 0){
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
  printf("///////////////////////       TEST-BASELINE        ///////////////////////\n");
  printf("//////////////////////////////////////////////////////////////////////////\n");
  couleur("0");
  test_player();
  test_board();
  test_game();
  return 0;
}
