#include "game.h"

card select_card(player P, board B){
    int i;
    int j = 0;
    int carte_jouable[5] = {0,0,0,0,0};
    for (i=0; i<5; i++){
        if( id2card(P.hand[i], B).cost <= P.ideas ) {
            carte_jouable[j] = P.hand[i];
            j += 1;
        }
    }
    if(j){
        i = rand()%j;
        return id2card(carte_jouable[i], B);
    } else {
        card null;
        null.idCard = 0;
        return null;
    }
}

void apply_card(card C, boardPointer B, playerPointer p, playerPointer pAdv){
    switch (C.idCard)
    {
    case 1 :
      Kitty_Think(p);
      p->ideas -= C.cost;
      break;
    case 2 :
      Kitty_Steal(p, pAdv);
      p->ideas -= C.cost;
      break;
    case 3 :
      Kitty_Panacea(p);
      p->ideas -= C.cost;
      break;
    case 4 :
      Kitty_Razor(pAdv);
      p->ideas -= C.cost;
      break;
    case 5 :
      Kitty_Hell_is_Others(pAdv);
      p->ideas -= C.cost;
      break;
    case 6 :
      Kitty_Stone(pAdv, B);
      p->ideas -= C.cost;
      break;
    }
}

void remove_card(card C, playerPointer p){
    int i;
    int c=0;
    for (i=0; i<NB_CARDS; i++){
        if (p->hand[i] == C.idCard && c == 0) {
                p->hand[i] = 0;
                c += 1;
        }
    }
    enfile(&(p->deck),C.idCard);
}

void kill_players(boardPointer B){
    int i;
    playerPointer p;
    for (i=0; i<NB_PLAYERS; i++){
        p = &(B->players[i]);
        if(p->pv<=0 || is_traped(*p, *B)) p->isAlive = 0;
    }
}
