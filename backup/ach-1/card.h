#ifndef CARD_H
#define CARD_H


struct card_t
{
    char* name;
    int idCard;
    int cost;
};

typedef struct card_t *cardPointer;
typedef struct card_t card;

#endif // CARD_H
