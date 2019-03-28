#ifndef FIFO_H
#define FIFO_H
#include "cst.h"


struct file
{
	int head;
	int queue;
	int tab[LEN_DECK];
	int isEmpty;
};

typedef struct file *filePointer;
typedef struct file file;

int length_file ( file f );
int defile ( filePointer f );
void enfile ( filePointer f, int e );
void mix_file ( filePointer f );

#endif // FIFO_H
