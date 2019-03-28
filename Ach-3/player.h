#ifndef PLAYER_H
#define PLAYER_H
#include "fifo.h"

struct friend_t   // Cette structure est équivalente à un noeud qui sera introduit dans une liste chainée par la suite
{
	//Les valeurs
	int idFriend;
	int pv;
	int ideas;
	int gain;
	int hand; // l'ID de l'unique carte du friend

	int isAlive;
	int isPlaying;
	int life;	//Initialisé à 20 et décrémenté à chaque tour ( si ==0 le friend meurt)

	int x;
	int y;

	int idTarget;

	//Le noeud suivant
	struct friend_t *nextFriend;

};

typedef struct friend_t friend_t;
typedef struct friend_t* friendPointer;

struct player_t
{
  int idPlayer;
  int pv;
  int ideas;
  int gain;
  int hand[5];

  int isAlive;
  int isPlaying;

  int x;
  int y;

  file deck;
  int deck_counter;
};

typedef struct player_t *playerPointer;
typedef struct player_t player;

void Kitty_Think_p(playerPointer p);
void Kitty_Panacea_p(playerPointer p);

void Kitty_Think_fr( friendPointer fr);
void Kitty_Panacea_fr( friendPointer fr);

void Kitty_Steal_fr2p( friendPointer fr, playerPointer pAdv);
void Kitty_Steal_p2p(playerPointer p, playerPointer pAdv);
//void Kitty_Steal_p2fr(playerPointer p, int idAdv, boardPointer B);     DANS GAME.H

void Kitty_Razor_2p(playerPointer pAdv);
void Kitty_Razor_2fr(friendPointer frAdv);

void Kitty_Hell_is_Others(playerPointer pAdv);


//void Kitty_Razor_fr(playerPointer);
//void Kitty_Hell_is_Others_fr(playerPointer);

void increase_player_ideas(playerPointer p);
void discard_hand(playerPointer p);
void refill_cards(playerPointer p);
void fill_deck(playerPointer);

#endif // PLAYER_H
