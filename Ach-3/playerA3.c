#include "player.h"

///////////////////////////////////////////////// Cards ///////////////////////////////////////////////////////

//Cards for Individuals Players
void Kitty_Think_p(playerPointer p){
    p->gain += 1;
}

void Kitty_Panacea_p(playerPointer p){
    p->pv += 10;
}

//Cards for Individuals Friends

void Kitty_Think_fr( friendPointer fr){
    fr->gain += 1;
}

void Kitty_Panacea_fr( friendPointer fr){
    fr->pv += 10;
}

//Cards from Friends towards Players

void Kitty_Steal_fr2p( friendPointer fr, playerPointer pAdv){
    fr->gain += 1;
    if (pAdv->gain > 1) pAdv->gain -= 1;
}

//Cards from Players towards Players

void Kitty_Steal_p2p(playerPointer p, playerPointer pAdv){
    p->gain += 1;
    if (pAdv->gain > 1) pAdv->gain -= 1;
}

//Cards from Players towards Friends


           //void Kitty_Steal_p2fr(playerPointer p, int idAdv, boardPointer B) in GAME.C because needs the BOARD structure


//Cards towards Players

void Kitty_Razor_2p(playerPointer pAdv){
    pAdv->pv -= 10;

}

void Kitty_Hell_is_Others(playerPointer pAdv){
  if (pAdv->pv <= 0) 
    pAdv->pv = -INT_MAX;
  else
    pAdv->pv -= INT_MAX;
}

//Cards towards Friends

void Kitty_Razor_2fr(friendPointer frAdv){
    frAdv->pv -= 10;
}


//Other functions
void increase_player_ideas(playerPointer p){
    p->ideas = p->ideas + p->gain;
}

void discard_hand(playerPointer p){
    int i;
    for (i=0; i<NB_CARDS; i++)(p->hand)[i] = 0;
}

void refill_cards(playerPointer p){
  int c = 0;
  int indZero;
  int i;
  for (i=0; i<NB_CARDS; i++){
    if ((p->hand)[i] == 0 ){
      c += 1;
      indZero = i;
    }
  }
  if (c>1){
    for (int i=0; i<5; i++){
      int c = defile(&(p->deck));
    (p->hand)[i] = c;
    (p->deck_counter)++;
    } 
  } else if ( c == 1) {
    int c = defile(&(p->deck));
    (p->hand)[indZero] = c;
    (p->deck_counter)++;
  }
}


void fill_deck (playerPointer p)
{
  for (int i=0; i<LEN_DECK; i++){
    int c = rand()%161;
    if (c<20) enfile(&(p->deck),1);
    else if (c>=20 && c<30) enfile(&(p->deck),2);
    else if (c>=30 && c<80) enfile(&(p->deck),3);
    else if (c>=80 && c<130) enfile(&(p->deck),4);
    else if (c>=130 && c<140) enfile(&(p->deck),6);
    else if (c>=140 && c<160) enfile(&(p->deck),7);
    else  enfile(&(p->deck),5);
  }
}
