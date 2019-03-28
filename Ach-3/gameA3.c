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
    
    int choice = rand()%2;
    
    switch (C.idCard)
    {
    case 1 :
		Kitty_Think_p(p);
		p->ideas -= C.cost;	
		break;
    case 2 :
		if (choice == 0 && B->friends[pAdv->idPlayer-1] != NULL) Kitty_Steal_p2fr(p, pAdv->idPlayer - 1, B);    
		else Kitty_Steal_p2p(p, pAdv);
		p->ideas -= C.cost;
		break;
    case 3 :
		Kitty_Panacea_p(p);
		p->ideas -= C.cost;
		break;
    case 4 :
		if (choice == 0 && B->friends[pAdv->idPlayer-1] != NULL) Kitty_Razor_2fr( B->friends[pAdv->idPlayer -1]);    
		else Kitty_Razor_2p(pAdv);
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
	case 7 :
		Kitty_Puppy(p->idPlayer, B);
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
