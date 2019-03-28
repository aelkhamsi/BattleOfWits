#include "player.h"

void Kitty_Think(playerPointer p){
    p->gain += 1;
}

void Kitty_Steal(playerPointer p, playerPointer pAdv){
    p->gain += 1;
    if (pAdv->gain > 1) pAdv->gain -= 1;
}

void Kitty_Panacea(playerPointer p){
    p->pv += 10;
}

void Kitty_Razor(playerPointer pAdv){
    pAdv->pv -= 10;

}

void Kitty_Hell_is_Others(playerPointer pAdv){
  if (pAdv->pv <= 0) 
    pAdv->pv = -INT_MAX;
  else
    pAdv->pv -= INT_MAX;
}


void increase_ideas(playerPointer p){
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
    int c = rand()%141;
    if (c<20) enfile(&(p->deck),1);
    else if (c>=20 && c<30) enfile(&(p->deck),2);
    else if (c>=30 && c<80) enfile(&(p->deck),3);
    else if (c>=80 && c<130) enfile(&(p->deck),4);
    else if (c>=130 && c<140) enfile(&(p->deck),6);
    else  enfile(&(p->deck),5);
  }
}
