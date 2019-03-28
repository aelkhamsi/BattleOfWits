#include <stdio.h>

#include "player.h"
#include "card.h"
#include "board.h"
#include "game.h"

int main(int argc, char *argv[]){
    /*struct player_t p1;
    player p = &p1;
    p->ideas = 1;
    p->gain = 10;
    increase_ideas(p);
    printf("%d\n", p1.ideas);
    return 0;*/

    // Creation des variables PLAYERS, CARDS ET TABLE DE JEU
    player P1 = {1,99,20,5,{2,4,3,1,1},1,0};
    player P2 = {2,100,0,2,{4,2,1,3,1},1,1};
    player P3 = {3,10,0,10,{4,3,1,3,1},1,0};
    player P4 = {3,10,0,10,{4,3,1,3,1},1,1};

    void (*pf1)(playerPointer) = &Kitty_Think;
    void (*pf2)(playerPointer, playerPointer) = &Kitty_Steal;
    void (*pf3)(playerPointer) = &Kitty_Panacea;
    void (*pf4)(playerPointer) = &Kitty_Razor;
    void (*pf5)(playerPointer) = &Kitty_Hell_is_Others;

    card C1 = {"Kitty-Think",1,10,20};
    card C2 = {"Kitty-Steal",2,100,10};
    card C3 = {"Kitty-Panacea",3,5,50};
    card C4 = {"Kitty-Razor",4,7,50};
    card C5 = {"Kitty-Hell-is-Others",5,100,1};

    board B;

    //Remplir le tableau de jeu
    B.players[0] = P1;
    B.players[1] = P2;
    B.players[2] = P3;
    B.players[3] = P4;

    B.cards[0] = C1;
    B.cards[1] = C2;
    B.cards[2] = C3;
    B.cards[3] = C4;
    B.cards[4] = C5;

    card c = select_card(P1,B);
    player P = select_player(B);

    playerPointer p = &P1;
    playerPointer pAdv = &P2;
    apply_card(C2, p, pAdv);

    increase_ideas(p);

    printf("player number %d has %d pv  ", (B.players)[0].idPlayer, (B.players)[0].pv);
    printf("%d\n", P1.ideas);
    printf("the pv of player 1 is %d\n", id2player(1,B).pv);

    printf("%s\n", c.name);
    printf("%d\n", P.idPlayer);

    printf("%d %d  %d\n", P1.gain, P2.gain, P1.ideas);

    return 0;
}

