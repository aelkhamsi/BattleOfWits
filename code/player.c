#include <stdio.h>
#include "player.h"
#include "board.h"

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
    pAdv->pv *= INT_MAX;
}
