CFLAGS=-std=c99 -Wall -Wextra

all: code

code: code-Achievement1

code-Achievement1: main.o fifo.o player.o card.o board.o game.o arena.o
	gcc $(CFLAGS) main.o fifo.o player.o card.o board.o game.o arena.o -o project

main.o: main.c game.h
	gcc $(CFLAGS) -c $^

game.o: game.c game.h arena.h
	gcc $(CFLAGS) -c $^

board.o: board.c board.h player.h card.h
	gcc $(CFLAGS) -c $^

card.o: card.c card.h
	gcc $(CFLAGS) -c $^

player.o: player.c player.h fifo.h
	gcc $(CFLAGS) -c $^

fifo.o: fifo.c fifo.h
	gcc $(CFLAGS) -c $^

arena.o: arena.c arena.h board.h
	gcc $(CFLAGS) -c $^

test: test-achievement2

test-achievement2: test-achievement2.o fifo.o player.o card.o board.o game.o arena.o
	gcc $(CFLAGS) test-achievement2.o fifo.o player.o card.o board.o game.o arena.o -o test-0 && ./test-0

test-achievement2.o: test-achievement2.c arena.h
	gcc $(CFLAGS) -c $^

clean:
	rm -f project *.o *.gch *~ *# test-0
