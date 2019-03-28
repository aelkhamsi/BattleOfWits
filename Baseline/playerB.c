#include "player.h"

void Kitty_Think(playerPointer p){
  if (p->gain != INT_MAX)
    p->gain += 1;
}

void Kitty_Steal(playerPointer p, playerPointer pAdv){
    if (p->gain != INT_MAX) p->gain += 1;
    if (pAdv->gain > 1) pAdv->gain -= 1;
}

void Kitty_Panacea(playerPointer p){
  if (p->pv <=  INT_MAX-10) p->pv += 10;
}

void Kitty_Razor(playerPointer pAdv){
  if (pAdv->pv >= -INT_MAX+10) pAdv->pv -= 10;

}

void Kitty_Hell_is_Others(playerPointer pAdv){
  if (pAdv->pv <= 0) 
    pAdv->pv = -INT_MAX;
  else
    pAdv->pv -= INT_MAX;
}


void increase_ideas(playerPointer p){
  if (p->ideas <= INT_MAX - p->gain) p->ideas = p->ideas + p->gain;
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
        for (i=0; i<NB_CARDS; i++){
            c = rand()%131;
            if (c<20) (p->hand)[i] = 1;
            else if (c>=20 && c<30) (p->hand)[i] = 2;
            else if (c>=30 && c<80) (p->hand)[i] = 3;
            else if (c>=80 && c<130) (p->hand)[i] = 4;
            else (p->hand)[i] = 5;
        }
    } else if ( c == 1) {
        c = rand()%131;
        if (c<20) (p->hand)[indZero] = 1;
        else if (c>=20 && c<30) (p->hand)[indZero] = 2;
        else if (c>=30 && c<80) (p->hand)[indZero] = 3;
        else if (c>=80 && c<130) (p->hand)[indZero] = 4;
        else (p->hand)[indZero] = 5;
    }
}
