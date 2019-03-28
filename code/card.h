#ifndef CARD_H
#define CARD_H


struct card_t
{
    char name[20];
    int idCard;
    int cost;
    //int proba;
};

typedef struct card_t *cardPointer;
typedef struct card_t card;


#endif // CARD_H
