#ifndef PLAYER_H
#define PLAYER_H

struct player_t
{
    int idPlayer;
    int pv;
    int ideas;
    int gain;
    int hand[5];
    int isAlive;
    int isPlaying;
};

typedef struct player_t *playerPointer;
typedef struct player_t player;

void Kitty_Think(playerPointer);
void Kitty_Steal(playerPointer, playerPointer);
void Kitty_Panacea(playerPointer);
void Kitty_Razor(playerPointer);
void Kitty_Hell_is_Others(playerPointer);

#endif // PLAYER_H
