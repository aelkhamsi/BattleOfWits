#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "game.h"

card id2card(int id, board B){
    return (B.cards)[id-1];
}

player id2player(int id, board B){
    return (B.players)[id-1];
}

void increase_ideas(playerPointer p){
    p->ideas = p->ideas + p->gain;
}

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
        srand(time(NULL));
        i = rand()%j;
        return id2card(carte_jouable[i], B);
    } else {
        card null;
        null.idCard = 0;
        return null;
    }
}

player select_player(board B){
    int i;
    int j=0;
    int joueur_attaquable[4] = {0,0,0,0};
    for (i=1; i<NB_PLAYERS; i++){
        if ( id2player(i, B).isAlive == 1 & id2player(i, B).isPlaying == 0 ){
            joueur_attaquable[j] = i;
            j += 1;
        }
    }
    srand(time(NULL));
    i = rand()%j;
    return id2player(joueur_attaquable[i], B);
}

void apply_card(card C, playerPointer p, playerPointer pAdv){
    switch (C.idCard)
    {
        case 1 :
            Kitty_Think(p);
            p->ideas -= 5;
            (p->hand)[0] = 0;
            break;
        case 2 :
            Kitty_Steal(p, pAdv);
            p->ideas -= 10;
            (p->hand)[1] = 0;
            break;
        case 3 :
            Kitty_Panacea(p);
            p->ideas -= 2;
            (p->hand)[2] = 0;
            break;
        case 4 :
            Kitty_Razor(pAdv);
            p->ideas -= 2;
            (p->hand)[3] = 0;
            break;
        case 5 :
            Kitty_Hell_is_Others(pAdv);
            p->ideas -= 100;
            (p->hand)[4] = 0;
            break;
    }
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
            srand(time(NULL));
            c = rand()%131;
            if (c<20) (p->hand)[i] = 1;
            else if (c>=20 & c<30) (p->hand)[i] = 2;
            else if (c>=30 & c<80) (p->hand)[i] = 3;
            else if (c>=80 & c<130) (p->hand)[i] = 4;
            else (p->hand)[i] = 5;
        }
    } else {
        srand(time(NULL));
        c = rand()%131;
        if (c<20) (p->hand)[indZero] = 1;
        else if (c>=20 & c<30) (p->hand)[indZero] = 2;
        else if (c>=30 & c<80) (p->hand)[indZero] = 3;
        else if (c>=80 & c<130) (p->hand)[indZero] = 4;
        else (p->hand)[indZero] = 5;
    }
}




