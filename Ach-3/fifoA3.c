#include <stdio.h>
#include <stdlib.h>
#include "fifo.h"

int length_file ( file f )
{
  if (f.isEmpty)
    return 0;
  else
    if (f.head <= f.queue)
      return f.queue-f.head+1;
    else
      return f.queue+LEN_DECK-f.head+1;
}

void enfile ( filePointer f, int e )
{
  if ((f->queue +1)%LEN_DECK != f->head){
    if (f->isEmpty){
      (f->tab)[f->queue] = e;
      f->isEmpty = 0;
    }
    else{
      f->queue = (f->queue +1)%LEN_DECK;
      (f->tab)[f->queue] = e;
    }
  }		
}

int defile ( filePointer f )
{
  if(!(f->isEmpty)){
      if (f->head == f->queue){
	f->isEmpty = 1;
	return (f->tab)[f->head];
      }
      else{
	int aux = f->head;
	f->head = (f->head +1)%LEN_DECK;
	return (f->tab)[aux];
      }
  }
  else
    return 0;
}

void mix_file ( filePointer f )
{
  if (!f->isEmpty && f->head != f->queue ){
      int n = length_file(*f);
      while (n>1){
	int m = rand()%(n-1);
	int j = (f->head + m)%LEN_DECK;
	int i = (f->head + n-1)%LEN_DECK;
	int aux = (f->tab)[j];
	(f->tab)[j] = (f->tab)[i];
	(f->tab)[i] = aux;
	n--;
      }
    }
}
